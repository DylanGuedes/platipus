#include "../include/game_object.hpp"

namespace platipus {
        GameObject::GameObject(GameObject *parent) :
                mParent(parent)
        {
        }

        GameObject::~GameObject()
        {
                for (auto &item : mChildren) {
                        delete item;
                }
        }
}
