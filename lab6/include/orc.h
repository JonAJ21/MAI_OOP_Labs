#ifndef ORC_H
#define ORC_H

#include "npc.h"
 
// struct Orc : public NPC {
//     Orc(int x, int y);
//     Orc(std::istream &is);

//     void print() override;

//     // void accept(std::shared_ptr<IVisitor> visitor) override {
//     //     visitor->visit(this);
//     // }
//     void accept(std::shared_ptr<Robber> robber, std::shared_ptr<IVisitor> visitor) override {
//         visitor->visit(this, robber);
//     }
//     void accept(std::shared_ptr<Orc> orc, std::shared_ptr<IVisitor> visitor) override {
//         visitor->visit(this, orc);
//     }
//     void accept(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<IVisitor> visitor) override {
//         visitor->visit(this, werewolf);
//     }

//     void fight(std::shared_ptr<Robber> robber) {
//         std::cout << "Orc vs Robber" << std::endl;
//     }
//     void fight(std::shared_ptr<Orc> orc) {
//         std::cout << "Orc vs Orc" << std::endl;
//     }
//     void fight(std::shared_ptr<Werewolf> werewolf) {
//         std::cout << "Orc vs Werewolf" << std::endl;
//     }

//     friend std::ostream &operator<<(std::ostream &os, Orc &werewolf);
// };

// struct OrcFactory : public IFactory {
//     std::shared_ptr<NPC> createNPC(int x, int y) override {
//         return std::make_shared<Orc>(x, y);
//     }
//     std::shared_ptr<NPC> createNPC(std::istream & is) override {
//         return std::make_shared<Orc>(is);
//     }
// };

#endif // ORC_H