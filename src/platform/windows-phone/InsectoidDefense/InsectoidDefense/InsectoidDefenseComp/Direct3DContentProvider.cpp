//
//  Direct3DContentProvider.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "pch.h"
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
#include "Triangle.h"
#include "Font.h"
#include "Direct3DRenderer.h"
#include "SpriteBatcher.h"
#include "RectangleBatcher.h"
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

using namespace InsectoidDefenseComp;

Direct3DContentProvider::Direct3DContentProvider(Direct3DInterop^ controller) : m_controller(controller)
{
	m_controller->RequestAdditionalFrame += ref new RequestAdditionalFrameHandler([=]()
	{
		if (m_host)
		{
			m_host->RequestAdditionalFrame();
		}
	});

	m_controller->RecreateSynchronizedTexture += ref new RecreateSynchronizedTextureHandler([=]()
	{
		if (m_host)
		{
			m_host->CreateSynchronizedTexture(m_controller->GetTexture(), &m_synchronizedTexture);
		}
	});
}

// IDrawingSurfaceContentProviderNative interface
HRESULT Direct3DContentProvider::Connect(_In_ IDrawingSurfaceRuntimeHostNative* host)
{
	m_host = host;

	return m_controller->Connect(host);
}

void Direct3DContentProvider::Disconnect()
{
	m_controller->Disconnect();
	m_host = nullptr;
	m_synchronizedTexture = nullptr;
}

HRESULT Direct3DContentProvider::PrepareResources(_In_ const LARGE_INTEGER* presentTargetTime, _Out_ BOOL* contentDirty)
{
	return m_controller->PrepareResources(presentTargetTime, contentDirty);
}

HRESULT Direct3DContentProvider::GetTexture(_In_ const DrawingSurfaceSizeF* size, _Out_ IDrawingSurfaceSynchronizedTextureNative** synchronizedTexture, _Out_ DrawingSurfaceRectF* textureSubRectangle)
{
	HRESULT hr = S_OK;

	if (!m_synchronizedTexture)
	{
		hr = m_host->CreateSynchronizedTexture(m_controller->GetTexture(), &m_synchronizedTexture);
	}

	// Set output parameters.
	textureSubRectangle->left = 0.0f;
	textureSubRectangle->top = 0.0f;
	textureSubRectangle->right = static_cast<FLOAT>(size->width);
	textureSubRectangle->bottom = static_cast<FLOAT>(size->height);

	m_synchronizedTexture.CopyTo(synchronizedTexture);

	// Draw to the texture.
	if (SUCCEEDED(hr))
	{
		hr = m_synchronizedTexture->BeginDraw();

		if (SUCCEEDED(hr))
		{
			hr = m_controller->GetTexture(size, synchronizedTexture, textureSubRectangle);
		}

		m_synchronizedTexture->EndDraw();
	}

	return hr;
}