#include "npc.h"

// =======================================
// Werewolf

Werewolf::Werewolf(int x, int y) : NPC(WerewolfType, x, y){
}

void Werewolf::print() {
    std::cout << *this;
}

bool Werewolf::accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor)  {
    if (npc->type == RobberType) {
        visitor->visit(std::dynamic_pointer_cast<Werewolf>(shared_from_this()), std::dynamic_pointer_cast<Robber>(npc));
        return true;
    }
    if (npc->type == OrcType) {
        visitor->visit(std::dynamic_pointer_cast<Werewolf>(shared_from_this()), std::dynamic_pointer_cast<Orc>(npc));
        return false;
    } 
    if (npc->type == WerewolfType) {
        visitor->visit(std::dynamic_pointer_cast<Werewolf>(shared_from_this()), std::dynamic_pointer_cast<Werewolf>(npc));
        return false;
    }
    throw std::logic_error("Incorrect Type");
}

void Werewolf::fight(std::shared_ptr<Robber> robber) {
    fight_notify(robber, true);
    // std::cout << "Werewolf vs Robber" << std::endl;
}
void Werewolf::fight(std::shared_ptr<Orc> orc) {
    fight_notify(orc, false);
    // std::cout << "Werewolf vs Orc" << std::endl;
}
void Werewolf::fight(std::shared_ptr<Werewolf> werewolf) {
    fight_notify(werewolf, false);
    // std::cout << "Werewolf vs Werewolf" << std::endl;
}

// =======================================
// std::ostream

std::ostream &operator<<(std::ostream &os, Werewolf &werewolf) {
    os << "Werewolf: " << *static_cast<NPC *>(&werewolf) << std::endl;
    return os;
}