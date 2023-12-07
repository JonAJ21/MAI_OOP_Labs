#include "npc.h"

// Robber

Robber::Robber(int x, int y) : NPC(RobberType, x, y) {}

void Robber::print() {

}
void Robber::accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor) {
    if (npc->type == RobberType) {
            // std::cout << "npc robber";
            visitor->visit(std::dynamic_pointer_cast<Robber>(shared_from_this()), std::dynamic_pointer_cast<Robber>(npc));
            return;
    }
    if (npc->type == OrcType) {
        visitor->visit(std::dynamic_pointer_cast<Robber>(shared_from_this()), std::dynamic_pointer_cast<Orc>(npc));
        return;
    } 
    if (npc->type == WerewolfType) {
        visitor->visit(std::dynamic_pointer_cast<Robber>(shared_from_this()), std::dynamic_pointer_cast<Werewolf>(npc));
        return;
    }
    throw std::logic_error("Incorrect Type");
}
void Robber::fight(std::shared_ptr<Robber> robber) {
    std::cout << "Robber vs Robber" << std::endl;
}
void Robber::fight(std::shared_ptr<Orc> orc) {
    std::cout << "Robber vs Orc" << std::endl;
}
void Robber::fight(std::shared_ptr<Werewolf> werewolf) {
    std::cout << "Robber vs Werewolf" << std::endl;
}

