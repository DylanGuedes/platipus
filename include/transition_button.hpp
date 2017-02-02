#ifndef PLATIPUS_TRANSITION_BUTTON_HPP
#define PLATIPUS_TRANSITION_BUTTON_HPP

#include "button.hpp"
#include "entity.hpp"

namespace platipus {
        class TransitionButton : public platipus::Button {
                public:
                        TransitionButton(std::ifstream *mapData);
                        ~TransitionButton();
                        platipus::entity::LEVEL_TYPE desiredLevel() const;

                protected:
                        void handleMouseover(sf::Event e);
                        void handleClick(sf::Event e);
                        void handleClickOut(sf::Event e);

                private:
                        platipus::entity::LEVEL_TYPE mDesiredLevel;
        };
}
#endif
