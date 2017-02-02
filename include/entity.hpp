#ifndef PLATIPUS_ENTITY_HPP
#define PLATIPUS_ENTITY_HPP

#include <queue>
namespace platipus {
        namespace entity {
                const unsigned int TRANSITION_BUTTON = 0xFF0;
                extern std::queue<int> *commandQueue;

                enum COMMAND_TYPE {
                        LEVEL_TRANSITION
                };

                enum LEVEL_TYPE {
                        MAIN_MENU = 0x0001,
                        LEVEL_0001 = 0x0002
                };

                static void
                pushCommand(unsigned int comm)
                {
                        if (commandQueue==nullptr) {
                                commandQueue = new std::queue<int>;
                                std::cout << "alocado alguma vez..\n";
                        }

                        platipus::entity::commandQueue->push(comm);
                        std::cout << "SIZE: " << commandQueue->size() << "\n";
                }

                static int
                popCommand()
                {
                        int idx = commandQueue->front();
                        commandQueue->pop();
                        return idx;
                }

                static bool
                pendingCommand()
                {
                        if (commandQueue) {
                                // std::cout << "SIZE THEN: " << commandQueue->size() << "\n";
                                return !(commandQueue->empty());
                        } else {
                                commandQueue = new std::queue<int>;
                                std::cout << "alocado alguma vez..\n";
                                return false;
                        }
                }

                static void
                cleanup()
                {
                        delete commandQueue;
                }
        }
}

#endif
