//
//  Renderer.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "Renderer.h"
#include "GameConstants.h"
#include "ResourceConstants.h"
#include "SpriteBatcher.h"
#include "RectangleBatcher.h"
#include "Line.h"
#include "LineBatcher.h"
#include "Circle.h"
#include "Color.h"
#include "CircleBatcher.h"
#include "TextureRegion.h"
#include "Assets.h"
#include "Vector2D.h"
#include "Font.h"
#include "TextureWrapper.h"
#include "Rectangle.h"
#include "PhysicalEntity.h"
#include "World.h"
#include "BackgroundElements.h"
#include "TouchCursor.h"
#include "TimeButton.h"
#include "Text.h"
#include "Dialog.h"
#include "Asteroid.h"
#include "ShipModule.h"
#include "CoreShipModule.h"
#include "Spawn.h"
#include "WorldPlatform.h"
#include "Creep.h"
#include "Tower.h"
#include "Missile.h"
#include "IceBlast.h"
#include "FireBolt.h"
#include "AcidDrop.h"
#include "LazerBeam.h"
#include "ElectricBolt.h"
#include "Projectile.h"
#include "Explosion.h"
#include "CreepBodyPartType.h"
#include "ToxicCloud.h"
#include "CreepBodyPart.h"
#include "Creep.h"
#include "GameConstants.h"
#include "ProjectileParticle.h"
#include "TowerCursor.h"
#include "TowerOptionButton.h"

Renderer::Renderer()
{
    m_font = std::unique_ptr<Font>(new Font(FONT_TEXTURE_REGION_X, FONT_TEXTURE_REGION_Y, FONT_GLYPHS_PER_ROW, FONT_GLYPH_WIDTH, FONT_GLYPH_HEIGHT, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512));
}

void Renderer::renderBackground(BackgroundElements &backgroundElements)
{
    m_spriteBatcher->beginBatch();

    renderPhysicalEntity(backgroundElements.getLeftBackground(), Assets::getBackgroundLeftSource());
    renderPhysicalEntity(backgroundElements.getRightBackground(), Assets::getBackgroundRightSource());

    m_spriteBatcher->endBatchWithTexture(*m_backgroundTexture);
}

void Renderer::renderBackgroundOverlay(BackgroundElements &backgroundElements, TimeButton &timeButton)
{
    m_spriteBatcher->beginBatch();
    for (std::list < std::unique_ptr < Asteroid >> ::iterator itr = backgroundElements.getAsteroids().begin(); itr != backgroundElements.getAsteroids().end(); ++itr)
    {
        renderPhysicalEntity((**itr), Assets::getAsteroidSourceForType((*itr)->getAsteroidType()));
    }

    for (std::list < std::unique_ptr < ShipModule >> ::iterator itr = backgroundElements.getShipModules().begin(); itr != backgroundElements.getShipModules().end(); itr++)
    {
        renderPhysicalEntity((**itr), Assets::getShipModuleSource((*itr)->getType()));
    }

    renderPhysicalEntity(backgroundElements.getCoreShipModule(), Assets::getCoreShipModuleSource(backgroundElements.getCoreShipModule()));
    renderPhysicalEntity(timeButton, Assets::getTimeButtonSourceForSpeedScalar(timeButton.getSpeedScalar()));

    m_spriteBatcher->endBatchWithTexture(*m_backgroundTexture);
}

void Renderer::renderWorldAndTouchCursor(World &world, TouchCursor &touchCursor)
{
    m_spriteBatcher->beginBatch();

    for (std::vector < std::unique_ptr < Spawn >> ::iterator itr = world.getSpawns().begin(); itr != world.getSpawns().end(); itr++)
    {
        renderPhysicalEntity((**itr), Assets::getSpawnSource((**itr)));
    }

    for (std::vector < std::unique_ptr < WorldPlatform >> ::iterator itr = world.getPlatforms().begin(); itr != world.getPlatforms().end(); itr++)
    {
        renderPhysicalEntity((**itr), Assets::getPlatformSource((**itr)));
    }

    m_spriteBatcher->endBatchWithTexture(*m_spawnPlatformsProjectilesTowersTexture);

    if (world.getCreeps().size() > 0)
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < Creep >> ::iterator itr = world.getCreeps().begin(); itr != world.getCreeps().end(); itr++)
        {
            Color color = (**itr).getColor();
            m_spriteBatcher->drawSprite((**itr).getPosition().getX(), (**itr).getPosition().getY(), (**itr).getWidth(), (**itr).getHeight(), (**itr).getAngle(), color, Assets::getCreepSource((**itr), false));
        }

        m_spriteBatcher->endBatchWithTexture(*m_creepsTexture);
    }

    if (touchCursor.isVisible())
    {
        Color color = touchCursor.getShadowColor();
        m_circleBatcher->renderCircle(touchCursor.getSelectedTowerShadow(), color);
    }

    if (world.getTowers().size() > 0)
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < Tower >> ::iterator itr = world.getTowers().begin(); itr != world.getTowers().end(); itr++)
        {
            renderPhysicalEntity((**itr), Assets::getTowerSource((**itr)));
        }

        m_spriteBatcher->endBatchWithTexture(*m_spawnPlatformsProjectilesTowersTexture);
    }

    if (world.getMissiles().size() > 0)
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < Missile >> ::iterator itr = world.getMissiles().begin(); itr != world.getMissiles().end(); itr++)
        {
            renderPhysicalEntity((**itr), Assets::getMissileSource((**itr)));
        }

        m_spriteBatcher->endBatchWithTexture(*m_spawnPlatformsProjectilesTowersTexture);
    }

    if (world.getIceBlasts().size() > 0)
    {
        bool renderAtLeastOneIceBlast = false;
        for (std::vector < std::unique_ptr < IceBlast >> ::iterator itr = world.getIceBlasts().begin(); itr != world.getIceBlasts().end(); itr++)
        {
            if ((*itr)->isBlasting())
            {
                renderAtLeastOneIceBlast = true;
                break;
            }
        }

        if (renderAtLeastOneIceBlast)
        {
            m_spriteBatcher->beginBatch();

            for (std::vector < std::unique_ptr < IceBlast >> ::iterator itr = world.getIceBlasts().begin(); itr != world.getIceBlasts().end(); itr++)
            {
                if ((*itr)->isBlasting())
                {
                    renderPhysicalEntity((**itr), Assets::getIceBlastSource((**itr)));
                }
            }

            m_spriteBatcher->endBatchWithTexture(*m_spawnPlatformsProjectilesTowersTexture);
        }
    }

    if (world.getFireBolts().size() > 0)
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < FireBolt >> ::iterator itr = world.getFireBolts().begin(); itr != world.getFireBolts().end(); itr++)
        {
            renderPhysicalEntity((**itr), Assets::getFireBoltSource((**itr)));
        }

        m_spriteBatcher->endBatchWithTexture(*m_spawnPlatformsProjectilesTowersTexture);
    }

    if (world.getAcidDrops().size() > 0)
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < AcidDrop >> ::iterator itr = world.getAcidDrops().begin(); itr != world.getAcidDrops().end(); itr++)
        {
            renderPhysicalEntity((**itr), Assets::getAcidDropSource((**itr)));
        }

        m_spriteBatcher->endBatchWithTexture(*m_spawnPlatformsProjectilesTowersTexture);
    }

    if (world.getLazerBeams().size() > 0)
    {
        m_lineBatcher->beginBatch();
        for (std::vector < std::unique_ptr < LazerBeam >> ::iterator itr = world.getLazerBeams().begin(); itr != world.getLazerBeams().end(); itr++)
        {
            if ((*itr)->isFiring())
            {
                Color color = (*itr)->getColor();
                m_lineBatcher->renderLine((*itr)->getPath(), color);
            }
        }

        m_lineBatcher->endBatch();
    }

    if (world.getElectricBolts().size() > 0)
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < ElectricBolt >> ::iterator itr = world.getElectricBolts().begin(); itr != world.getElectricBolts().end(); itr++)
        {
            Color color = (**itr).getColor();
            m_spriteBatcher->drawSprite((**itr).getPosition().getX(), (**itr).getPosition().getY(), (**itr).getWidth(), (**itr).getHeight(), (**itr).getAngle(), color, Assets::getElectricBoltSource((**itr)));
        }

        m_spriteBatcher->endBatchWithTexture(*m_spawnPlatformsProjectilesTowersTexture);
    }

    if (world.getProjectiles().size() > 0)
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < Projectile >> ::iterator itr = world.getProjectiles().begin(); itr != world.getProjectiles().end(); itr++)
        {
            Color color = (**itr).getColor();
            m_spriteBatcher->drawSprite((**itr).getPosition().getX(), (**itr).getPosition().getY(), (**itr).getWidth(), (**itr).getHeight(), (**itr).getAngle(), color, Assets::getProjectileSource((**itr)));
        }

        m_spriteBatcher->endBatchWithTexture(*m_spawnPlatformsProjectilesTowersTexture);
    }

    if (world.getExplosions().size() > 0)
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < Explosion >> ::iterator itr = world.getExplosions().begin(); itr != world.getExplosions().end(); itr++)
        {
            renderPhysicalEntity((**itr), Assets::getExplosionSource((**itr)));
        }

        m_spriteBatcher->endBatchWithTexture(*m_looseObjectsTexture);
    }

    if (world.getToxicClouds().size() > 0)
    {
        for (std::vector < std::unique_ptr < ToxicCloud >> ::iterator itr = world.getToxicClouds().begin(); itr != world.getToxicClouds().end(); itr++)
        {
            Color color = (*itr)->getColor();
            m_circleBatcher->renderCircle((*itr)->getRadius(), color);
        }
    }

    if (world.getCreepBodyParts().size() > 0)
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < CreepBodyPart >> ::iterator itr = world.getCreepBodyParts().begin(); itr != world.getCreepBodyParts().end(); itr++)
        {
            Color color = (**itr).getColor();
            m_spriteBatcher->drawSprite((**itr).getPosition().getX(), (**itr).getPosition().getY(), (**itr).getWidth(), (**itr).getHeight(), (**itr).getAngle(), color, Assets::getCreepBodyPartSource((**itr)));
        }

        m_spriteBatcher->endBatchWithTexture(*m_looseObjectsTexture);
    }

    if (world.getCreeps().size() > 0)
    {
        bool renderAtLeastOneCreepHealthBar = false;
        for (std::vector < std::unique_ptr < Creep >> ::iterator itr = world.getCreeps().begin(); itr != world.getCreeps().end(); itr++)
        {
            if ((**itr).isHealthBarShowing())
            {
                renderAtLeastOneCreepHealthBar = true;
                break;
            }
        }

        if (renderAtLeastOneCreepHealthBar)
        {
            m_spriteBatcher->beginBatch();

            for (std::vector < std::unique_ptr < Creep >> ::iterator itr = world.getCreeps().begin(); itr != world.getCreeps().end(); itr++)
            {
                if ((**itr).isHealthBarShowing())
                {
                    m_spriteBatcher->drawSprite((**itr).getPosition().getX(), (**itr).getPosition().getY() + (**itr).getHeight() / 2, HEALTH_BAR_WIDTH, HEALTH_BAR_HEIGHT, 0, Assets::getCreepHealthBarSource(**itr));
                }
            }

            m_spriteBatcher->endBatchWithTexture(*m_creepsTexture);
        }
    }

    if (world.getProjectileParticles().size() > 0)
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < ProjectileParticle >> ::iterator itr = world.getProjectileParticles().begin(); itr != world.getProjectileParticles().end(); itr++)
        {
            Color color = (**itr).getColor();
            m_spriteBatcher->drawSprite((**itr).getPosition().getX(), (**itr).getPosition().getY(), (**itr).getWidth(), (**itr).getHeight(), (**itr).getAngle(), color, Assets::getProjectileParticleSource((**itr)));
        }

        m_spriteBatcher->endBatchWithTexture(*m_spawnPlatformsProjectilesTowersTexture);
    }

    if (world.getTowers().size() > 0)
    {
        for (std::vector < std::unique_ptr < Tower >> ::iterator itr = world.getTowers().begin(); itr != world.getTowers().end(); itr++)
        {
            if ((*itr)->getState() == Tower_State::UPGRADING)
            {
                Color color = Tower::getUpgradeCursorColor();
                m_circleBatcher->renderPartialCircle((*itr)->getUpgradeCursor(), (*itr)->getUpgradeCursorArcDegrees(), color);
            }
        }
    }

    if (world.getSpawnPointsState() == World_Spawn_Points_State::COUNTING_DOWN)
    {
        for (std::vector < std::unique_ptr < Spawn >> ::iterator itr = world.getSpawns().begin(); itr != world.getSpawns().end(); itr++)
        {
            Color color = World::getSpawnTimerColor();
            m_circleBatcher->renderPartialCircle((*itr)->getSpawnNextWaveTimer(), world.getSpawnNextWaveTimerArcDegrees(), color);
        }
    }

    if (touchCursor.isVisible())
    {
        Color color = touchCursor.getColor();
        m_circleBatcher->renderCircle(touchCursor.getDisplayCircle(), color);
    }
}

void Renderer::renderTowerMenu(BackgroundElements &backgroundElements)
{
    m_spriteBatcher->beginBatch();
    m_spriteBatcher->drawSprite(15.105f, GAME_HEIGHT / 2, 1.59f, GAME_HEIGHT, 0, Assets::getTowerMenuBackgroundSource());
    m_spriteBatcher->endBatchWithTexture(*m_backgroundTexture);

    if (backgroundElements.isUpgradeSellMenuShowing())
    {
        m_rectangleBatcher->beginBatch();
        Color color = backgroundElements.getUpgradeTowerButton().getBorderColor();
        m_rectangleBatcher->renderRectangle(backgroundElements.getUpgradeTowerButton().getBorder(), color);
        m_rectangleBatcher->endBatch();

        m_rectangleBatcher->beginBatch();
        Color color2 = backgroundElements.getSellTowerButton().getBorderColor();
        m_rectangleBatcher->renderRectangle(backgroundElements.getSellTowerButton().getBorder(), color2);
        m_rectangleBatcher->endBatch();

        renderText(backgroundElements.getUpgradeTowerButton().getButtonText());
        renderText(backgroundElements.getUpgradeTowerButton().getFundsText());
        renderText(backgroundElements.getSellTowerButton().getButtonText());
        renderText(backgroundElements.getSellTowerButton().getFundsText());
    }
    else
    {
        m_spriteBatcher->beginBatch();

        for (std::vector < std::unique_ptr < TowerCursor >> ::iterator itr = backgroundElements.getTowerCursors().begin(); itr != backgroundElements.getTowerCursors().end(); itr++)
        {
            Color color = (**itr).getColor();
            m_spriteBatcher->drawSprite((**itr).getPosition().getX(), (**itr).getPosition().getY(), (**itr).getWidth(), (**itr).getHeight(), (**itr).getAngle(), color, Assets::getTowerSource((*itr)->getTowerType(), 0));
        }

        m_spriteBatcher->endBatchWithTexture(*m_spawnPlatformsProjectilesTowersTexture);

        for (std::vector < std::unique_ptr < TowerCursor >> ::iterator itr = backgroundElements.getTowerCursors().begin(); itr != backgroundElements.getTowerCursors().end(); ++itr)
        {
            if ((*itr)->isEnabled())
            {
                renderText((*itr)->getCostText());
            }
        }
    }
}

void Renderer::renderText(Text &t)
{
    m_spriteBatcher->beginBatch();

    std::string text = t.getText();
    m_font->renderText(*m_spriteBatcher, text, t.getX(), t.getY(), t.getWidth(), t.getHeight(), t.getColor());

    m_spriteBatcher->endBatchWithTexture(*m_topLevelUiTexture);
}

void Renderer::renderDialog(Dialog &dialog)
{
    m_spriteBatcher->beginBatch();

    renderPhysicalEntity(dialog, Assets::getDialogSource());

    m_spriteBatcher->endBatchWithTexture(*m_topLevelUiTexture);

    renderText(dialog.getTitle());
    renderText(dialog.getLeftButton());
    renderText(dialog.getRightButton());
}

TextureWrapper & Renderer::getTopLevelUiTexture()
{
    return *m_topLevelUiTexture;
}

#pragma mark <Private>

void Renderer::renderPhysicalEntity(PhysicalEntity &go, TextureRegion tr)
{
    m_spriteBatcher->drawSprite(go.getPosition().getX(), go.getPosition().getY(), go.getWidth(), go.getHeight(), go.getAngle(), tr);
}