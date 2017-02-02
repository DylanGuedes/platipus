#include "../include/transition_button.hpp"
#include "../include/button.hpp"
#include "../include/entity.hpp"

#include <iostream>
#include <fstream>

namespace platipus {
        TransitionButton::TransitionButton(std::ifstream *mapData) : Button::Button(mapData)
        {
                unsigned int next;
                (*mapData) >> std::hex >> next;
                mDesiredLevel = platipus::entity::LEVEL_TYPE(next);
        }

        TransitionButton::~TransitionButton()
        {
        }

        void
        TransitionButton::handleMouseover(sf::Event e)
        {
        }

        void
        TransitionButton::handleClick(sf::Event e)
        {
                platipus::entity::pushCommand(platipus::entity::COMMAND_TYPE::LEVEL_TRANSITION);
                platipus::entity::pushCommand(desiredLevel());
        }

        void
        TransitionButton::handleClickOut(sf::Event e)
        {
        }

        platipus::entity::LEVEL_TYPE
        TransitionButton::desiredLevel() const
        {
                return mDesiredLevel;
        }

}
