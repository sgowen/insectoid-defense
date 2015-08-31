//
//  Direct3DInterop.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "pch.h"
#include "Direct3DInterop.h"
#include "Direct3DContentProvider.h"
#include "Direct3DGameScreen.h"
#include "Vector2D.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "Assets.h"
#include "OverlapTester.h"
#include "GameListener.h"
#include "Renderer.h"
#include "LineBatcher.h"
#include "RectangleBatcher.h"
#include "Triangle.h"
#include "Font.h"
#include "Direct3DRenderer.h"
#include "SpriteBatcher.h"
#include "LineBatcher.h"
#include "CircleBatcher.h"
#include "GameListener.h"
#include "BackgroundElements.h"
#include "TimeButton.h"
#include "Dialog.h"
#include "TouchCursor.h"
#include "Text.h"
#include "Asteroid.h"
#include "ShipModule.h"
#include "CoreShipModule.h"
#include "TowerCursor.h"
#include "Rectangle.h"
#include "TowerOptionButton.h"
#include "Circle.h"
#include "GameSound.h"
#include "DifficultyLevel.h"
#include "ScreenState.h"
#include "AchievementMapper.h"

#include <string.h>
#include <sstream>

// For Randomness
#include <stdlib.h>
#include <time.h>

using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Microsoft::WRL;
using namespace Windows::Phone::Graphics::Interop;
using namespace Windows::Phone::Input::Interop;

namespace InsectoidDefenseComp
{
	Direct3DInterop::Direct3DInterop() : m_timer(ref new BasicTimer())
	{
		// Empty
	}

	IDrawingSurfaceContentProvider^ Direct3DInterop::CreateContentProvider(int levelIndex, int difficulty, bool isMinimumWaveRequirementMet)
	{
		m_isMinimumWaveRequirementMet = isMinimumWaveRequirementMet;

		m_gameScreen = std::unique_ptr<Direct3DGameScreen>(new Direct3DGameScreen(levelIndex, difficulty));

		ComPtr<Direct3DContentProvider> provider = Make<Direct3DContentProvider>(this);
		return reinterpret_cast<IDrawingSurfaceContentProvider^>(provider.Get());
	}

	// IDrawingSurfaceManipulationHandler
	void Direct3DInterop::SetManipulationHost(DrawingSurfaceManipulationHost^ manipulationHost)
	{
		manipulationHost->PointerPressed += ref new TypedEventHandler<DrawingSurfaceManipulationHost^, PointerEventArgs^>(this, &Direct3DInterop::OnPointerPressed);
		manipulationHost->PointerMoved += ref new TypedEventHandler<DrawingSurfaceManipulationHost^, PointerEventArgs^>(this, &Direct3DInterop::OnPointerMoved);
		manipulationHost->PointerReleased += ref new TypedEventHandler<DrawingSurfaceManipulationHost^, PointerEventArgs^>(this, &Direct3DInterop::OnPointerReleased);
	}

	bool Direct3DInterop::onBackPressed()
	{
		return m_gameScreen->handleOnBackPressed();
	}

	int Direct3DInterop::getWave()
	{
		return m_gameScreen->getWave();
	}

	int Direct3DInterop::getScore()
	{
		return m_gameScreen->getScore();
	}

	void Direct3DInterop::setWinRtCallback(WinRtCallback^ callback)
	{
		m_winRtCallback = callback;
	}

	void Direct3DInterop::RenderResolution::set(Windows::Foundation::Size renderResolution)
	{
		if (renderResolution.Width != m_renderResolution.Width || renderResolution.Height != m_renderResolution.Height)
		{
			m_renderResolution = renderResolution;

			if (m_gameScreen)
			{
				m_gameScreen->updateForRenderResolutionChange(m_renderResolution.Width, m_renderResolution.Height);
				RecreateSynchronizedTexture();
			}
		}
	}

	// Event Handlers
	void Direct3DInterop::OnPointerPressed(DrawingSurfaceManipulationHost^ sender, PointerEventArgs^ args)
	{
		m_gameScreen->onTouch(DOWN, args->CurrentPoint->RawPosition.X, args->CurrentPoint->RawPosition.Y);
	}

	void Direct3DInterop::OnPointerMoved(DrawingSurfaceManipulationHost^ sender, PointerEventArgs^ args)
	{
		m_gameScreen->onTouch(DRAGGED, args->CurrentPoint->RawPosition.X, args->CurrentPoint->RawPosition.Y);
	}

	void Direct3DInterop::OnPointerReleased(DrawingSurfaceManipulationHost^ sender, PointerEventArgs^ args)
	{
		m_gameScreen->onTouch(UP, args->CurrentPoint->RawPosition.X, args->CurrentPoint->RawPosition.Y);
	}

	// Interface With Direct3DContentProvider
	HRESULT Direct3DInterop::Connect(_In_ IDrawingSurfaceRuntimeHostNative* host)
	{
		m_gameScreen->load(m_renderResolution.Width, m_renderResolution.Height, (int)WindowBounds.Width, (int)WindowBounds.Height);
		m_gameScreen->onResume();

		// Restart timer after renderer has finished initializing.
		m_timer->Reset();

		return S_OK;
	}

	void Direct3DInterop::Disconnect()
	{
		m_gameScreen->unload();
	}

	HRESULT Direct3DInterop::PrepareResources(_In_ const LARGE_INTEGER* presentTargetTime, _Out_ BOOL* contentDirty)
	{
		*contentDirty = true;

		return S_OK;
	}

	HRESULT Direct3DInterop::GetTexture(_In_ const DrawingSurfaceSizeF* size, _Out_ IDrawingSurfaceSynchronizedTextureNative** synchronizedTexture, _Out_ DrawingSurfaceRectF* textureSubRectangle)
	{
		int screenState = m_gameScreen->getState();
		switch (screenState)
		{
		case SCREEN_STATE_WAVE_COMPLETED:
			onWaveCompleted();
			m_gameScreen->clearState();
		case SCREEN_STATE_NORMAL:
			m_timer->Update();
			m_gameScreen->update(m_timer->Delta);
			break;
		case SCREEN_STATE_GAME_OVER:
			m_winRtCallback->Invoke("GAME_OVER", "NULL");
			m_gameScreen->clearState();
			break;
		case SCREEN_STATE_EXIT:
			m_winRtCallback->Invoke("EXIT", "NULL");
			break;
		default:
			break;
		}

		m_gameScreen->render();
		m_gameScreen->handleSound();
		m_gameScreen->handleMusic();

		RequestAdditionalFrame();

		return S_OK;
	}

	ID3D11Texture2D* Direct3DInterop::GetTexture()
	{
		return m_gameScreen->getTexture();
	}

	void Direct3DInterop::onWaveCompleted()
	{
		int wave = m_gameScreen->getWave();
		bool isAtMaxHealth = m_gameScreen->isAtMaxHealth();
		int difficulty = m_gameScreen->getDifficulty();
		int levelIndex = m_gameScreen->getLevelIndex();

		if (!m_isMinimumWaveRequirementMet && wave >= AchievementMapper::getWaveRequirementForLevelIndex(levelIndex))
		{
			m_isMinimumWaveRequirementMet = true;

			std::wstring levelUnlockedMessage = AchievementMapper::getUnLockedMessageForLevelIndex(levelIndex);

			m_winRtCallback->Invoke("DISPLAY_TOAST", ref new Platform::String(levelUnlockedMessage.c_str()));
		}
	}
}