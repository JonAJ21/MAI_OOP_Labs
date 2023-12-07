#include "npc.h"


Werewolf::Werewolf(int x, int y) : NPC(WerewolfType, x, y){
}


void Werewolf::print() {

}

void Werewolf::accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor)  {
    if (npc->type == RobberType) {
        visitor->visit(std::dynamic_pointer_cast<Werewolf>(shared_from_this()), std::dynamic_pointer_cast<Robber>(npc));
        return;
    }
    if (npc->type == OrcType) {
        visitor->visit(std::dynamic_pointer_cast<Werewolf>(shared_from_this()), std::dynamic_pointer_cast<Orc>(npc));
        return;
    } 
    if (npc->type == WerewolfType) {
        visitor->visit(std::dynamic_pointer_cast<Werewolf>(shared_from_this()), std::dynamic_pointer_cast<Werewolf>(npc));
        return;
    }
    throw std::logic_error("Incorrect Type");
}

void Werewolf::fight(std::shared_ptr<Robber> robber) {
    std::cout << "Werewolf vs Robber" << std::endl;
}
void Werewolf::fight(std::shared_ptr<Orc> orc) {
    std::cout << "Werewolf vs Orc" << std::endl;
}
void Werewolf::fight(std::shared_ptr<Werewolf> werewolf) {
    std::cout << "Werewolf vs Werewolf" << std::endl;
}