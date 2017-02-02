#include "../include/button.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>

namespace platipus {
        Button::Button(std::ifstream* mapData) :
                mTexture(new sf::Texture),
                mTextureHighlight(new sf::Texture)
        {
                loadTexture(mapData);
                loadPosition(mapData);
        }

        void
        Button::loadPosition(std::ifstream *mapData)
        {
                (*mapData) >> mX >> mY;
                mSprite->setPosition(mX, mY);
        }

        void
        Button::loadTexture(std::ifstream *mapData)
        {
                std::string textureName;

                if ((*mapData) >> textureName) {
                        mTexture->loadFromFile(textureName);
                        mSprite = new sf::Sprite(*mTexture);
                }

                if ((*mapData) >> textureName) {
                        mTextureHighlight->loadFromFile(textureName);
                }

                if ((*mapData) >> mWidth >> mHeight) {
                        mTextureLoaded = true;
                }
        }

        Button::~Button()
        {
                delete mTexture;
        }

        sf::Texture *
        Button::texture() const
        {
                return mTexture;
        }

        void
        Button::drawSelf(sf::RenderWindow *canvas)
        {
                if (mTextureLoaded) {
                        canvas->draw(*mSprite);
                }
        }

        void
        Button::onEvent(sf::Event e)
        {
                if (e.type == sf::Event::MouseButtonPressed) {
                        if (e.mouseButton.button == sf::Mouse::Left) {
                                if (e.mouseButton.x<=(mX+mWidth) && e.mouseButton.x>=mX && e.mouseButton.y>=mY && e.mouseButton.y<=(mY+mHeight)) {
                                        handleClick(e);
                                } else {
                                        handleClickOut(e);
                                }
                        }
                } else if (e.type == sf::Event::MouseMoved) {
                        if (e.mouseMove.x<=(mX+mWidth) && e.mouseMove.x>=mX && e.mouseMove.y>=mY && e.mouseMove.y<=(mY+mHeight)) {
                                mSprite->setTexture(*mTextureHighlight);
                                handleMouseover(e);
                        } else {
                                mSprite->setTexture(*mTexture);
                        }
                }
        }
}
