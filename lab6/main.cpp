#include <iostream>

#include "npc.h"


set_t fight(const set_t &array, size_t distance) {
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {   
                if (defender->accept(attacker)) dead_list.insert(defender);
            }

    return dead_list;
}


int main() {

    std::vector<std::shared_ptr<IFactory>> factories {std::make_shared<RobberFactory>(),
                                                      std::make_shared<OrcFactory>(),
                                                      std::make_shared<WerewolfFactory>()};

    set_t array;

    for (size_t i = 0; i < 50; ++i) {
        array.insert(factories[std::rand() % 3]->createNPC(std::rand() % 100, std::rand() % 100));
    }
    for (auto el : array) {
        el->print();
    }

    std::cout << "Fighting ..." << std::endl;

    for (size_t distance = 20; (distance <= 100) && !array.empty(); distance += 10)
    {
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list)
            array.erase(d);
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl << std::endl;
    }

    for (auto el : array) {
        el->print();
    }

    return 0;
}  