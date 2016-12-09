#include "../include/button.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>

namespace platipus {
        Button::Button(std::ifstream* mapData) :
                mTexture(new sf::Texture)
        {
                loadTexture(mapData);
                loadPosition(mapData);
        }

        void
        Button::loadPosition(std::ifstream *mapData)
        {
                (*mapData) >> mWidth >> mHeight;
        }

        void
        Button::loadTexture(std::ifstream *mapData)
        {
                std::string textureName;

                if ((*mapData) >> textureName) {
                        mTexture->loadFromFile(textureName);
                        mSprite = new sf::Sprite(*mTexture);
                        mTextureLoaded = true;
                }
        }

        Button::~Button()
        {
                delete mTexture;
        }

        void
        Button::setTexture(std::string textureName)
        {
                std::string texturePath("res/" + textureName);
                mTexture->loadFromFile(texturePath);
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
                GameObject::drawSelf(canvas);
        }
}
