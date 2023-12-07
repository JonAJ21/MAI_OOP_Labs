#include "npc.h"

// Orc

Orc::Orc(int x, int y) : NPC(OrcType, x, y) {}

void Orc::print() {
}

void Orc::accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor) {
    if (npc->type == RobberType) {
        visitor->visit(std::dynamic_pointer_cast<Orc>(shared_from_this()), std::dynamic_pointer_cast<Robber>(npc));
        return;
    }
    if (npc->type == OrcType) {
        visitor->visit(std::dynamic_pointer_cast<Orc>(shared_from_this()), std::dynamic_pointer_cast<Orc>(npc));
        return;
    } 
    if (npc->type == WerewolfType) {
        visitor->visit(std::dynamic_pointer_cast<Orc>(shared_from_this()), std::dynamic_pointer_cast<Werewolf>(npc));
        return;
    }
    throw std::logic_error("Incorrect Type");
}

void Orc::fight(std::shared_ptr<Robber> robber) {
    std::cout << "Orc vs Robber" << std::endl;
}
void Orc::fight(std::shared_ptr<Orc> orc) {
       std::cout << "Orc vs Orc" << std::endl;
}
void Orc::fight(std::shared_ptr<Werewolf> werewolf) {
    std::cout << "Orc vs Werewolf" << std::endl;
}
