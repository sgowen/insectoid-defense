//
//  Renderer.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Renderer__
#define __insectoiddefense__Renderer__

#include <memory>

class SpriteBatcher;
class RectangleBatcher;
class LineBatcher;
class CircleBatcher;
class Font;
struct TextureWrapper;
class GameObject;
class TextureRegion;
class World;
class BackgroundElements;
class TouchCursor;
class TimeButton;
class Text;
class Dialog;

class Renderer
{
public:
    Renderer();
    
    virtual void clearScreenWithColor(float r, float g, float b, float a) = 0;
    
    virtual void beginFrame() = 0;
    
    virtual void endFrame() = 0;

	virtual void cleanUp() = 0;
    
    void renderBackground(BackgroundElements &backgroundElements);
    
    void renderBackgroundOverlay(BackgroundElements &backgroundElements, TimeButton &timeButton);
    
    void renderWorldAndTouchCursor(World &world, TouchCursor &touchCursor);
    
    void renderTowerMenu(BackgroundElements &backgroundElements);
    
    void renderText(Text &text);
    
    void renderDialog(Dialog &dialog);
    
protected:
    std::unique_ptr<SpriteBatcher> m_spriteBatcher;
    std::unique_ptr<RectangleBatcher> m_rectangleBatcher;
    std::unique_ptr<LineBatcher> m_lineBatcher;
    std::unique_ptr<CircleBatcher> m_circleBatcher;
    
    std::unique_ptr<TextureWrapper> m_backgroundTexture;
    std::unique_ptr<TextureWrapper> m_creepsTexture;
    std::unique_ptr<TextureWrapper> m_spawnPlatformsProjectilesTowersTexture;
    std::unique_ptr<TextureWrapper> m_looseObjectsTexture;
    std::unique_ptr<TextureWrapper> m_topLevelUiTexture;
    
private:
	std::unique_ptr<Font> m_font;
    
    void renderGameObject(GameObject &go, TextureRegion tr);
};

#endif /* defined(__insectoiddefense__Renderer__) */