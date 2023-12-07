#include <iostream>

#include "npc.h"
#include "robber.h"
#include "orc.h"
#include "werewolf.h"

int main() {

   std::cout << "Hello lab6.1" << std::endl;
//    foo();
    // Разбойник, Орк, Оборотень
    // Разбойник убивает оборотней
    // Оборотень убивает разбойника
    // Орк убивает разбойника
    auto fight_visitor = std::make_shared<FightVisitor>();
    // auto orc2 = new Orc;
    std::shared_ptr<NPC> orc1 = std::make_shared<Orc>(2, 5);
    auto robber1 = std::make_shared<Robber>(7, 8);
    auto orc2 = std::make_shared<Orc>(10, 6);
    auto werewolf1 = std::make_shared<Werewolf>(1, 0);

    // std::vector<std::shared_ptr<NPC>> s {orc1, orc2};
    set_t array {orc1, orc2, robber1, werewolf1};

    // orc1->accept(orc2, fight_visitor);
    // orc1->accept(robber1, fight_visitor);
    // orc1->accept(werewolf1, fight_visitor);

    // orc2->accept(orc1, fight_visitor);
    // orc2->accept(robber1, fight_visitor);
    // orc2->accept(werewolf1, fight_visitor);

    // robber1->accept(orc1, fight_visitor);
    // robber1->accept(orc2, fight_visitor);
    // robber1->accept(werewolf1, fight_visitor);
    // std::cout << s[0]->x << ' ' << s[0]->y << std::endl;
    // std::cout << s[1]->x << ' ' << s[1]->y << std::endl;
    // orc1->accept(robber1, fight_visitor);
    // s[1]->accept(s[0], fight_visitor);
    // std::cout << orc1->type << std::endl;
    for (const auto &attacker : array)
        for (const auto &defender : array)
            if (attacker != defender)
            {
                defender->accept(attacker, fight_visitor);
            }

    // std::vector<std::shared_ptr<NPC>> v {orc1, orc2};
    // set_t s {orc1, orc2};
    
    return 0;
}  