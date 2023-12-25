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


void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{   
    std::vector<std::shared_ptr<IFactory>> factories {std::make_shared<RobberFactory>(),
                                                      std::make_shared<OrcFactory>(),
                                                      std::make_shared<WerewolfFactory>()};
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i) {
            int type;
            is >> type;
            std::cout << type << std::endl;
            int x, y;
            is >> x >> y;
            result.insert(factories[type - 1]->createNPC(x, y));
        }  
        is.close();
    } else {
        throw std::logic_error("Error: ifstream");
        // std::cerr << "Error: " << std::perror(errno) << std::endl;
    }
    return result;
}


int main() {

    // std::vector<std::shared_ptr<IFactory>> factories {std::make_shared<RobberFactory>(),
    //                                                   std::make_shared<OrcFactory>(),
    //                                                   std::make_shared<WerewolfFactory>()};
    
    // set_t array;

    // for (size_t i = 0; i < 50; ++i) {
    //     array.insert(factories[std::rand() % 3]->createNPC(std::rand() % 100, std::rand() % 100));
    // }
    // for (auto el : array) {
    //     el->print();
    // }
    // save(array, "npcs.txt");
    set_t array = load("npcs.txt");

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

    save(array, "npcsout.txt");

    return 0;
}  