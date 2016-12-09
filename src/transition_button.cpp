#include "../include/transition_button.hpp"
#include "../include/button.hpp"

namespace platipus {
        TransitionButton::TransitionButton(std::ifstream *mapData) : Button::Button(mapData)
        {
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
                std::cout << "Click in..\n";
        }

        void
        TransitionButton::handleClickOut(sf::Event e)
        {
                std::cout << "Click out..\n";
        }

}
