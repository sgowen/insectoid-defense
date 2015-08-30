//
//  TopScreenRenderer.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 8/25/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__TopScreenRenderer__
#define __insectoiddefense__TopScreenRenderer__

#include <memory>

#include <3ds.h>

class Font;
class DSSpriteBatcher;
class LineBatcher;
class Text;
struct TextureWrapper;

class TopScreenRenderer
{
public:
    TopScreenRenderer(gfxScreen_t screen, int screenWidth, int screenHeight);

    void beginFrame();
    
    void render();
    
    void renderDividerLine();
    
    void renderText(TextureWrapper &textureWrapper, Text &text);

    void endFrame();
    
    void cleanUp();
    
private:
    gfxScreen_t m_screen;
    std::unique_ptr<Font> m_font;
    std::unique_ptr<DSSpriteBatcher> m_spriteBatcher;
    std::unique_ptr<LineBatcher> m_lineBatcher;
    
    std::unique_ptr<TextureWrapper> m_topScreenTitleTexture;
};

#endif /* defined(__insectoiddefense__TopScreenRenderer__) */
