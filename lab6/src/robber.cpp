#include "npc.h"

// =======================================
// Robber

Robber::Robber(int x, int y) : NPC(RobberType, x, y) {}

Robber::Robber(std::istream & is) : NPC(RobberType, is) {}

void Robber::print() {
    std::cout << *this;
}

void Robber::print(std::ofstream& of) {
    of << *this;
} 

bool Robber::accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor) {
    if (npc == shared_from_this()) {
        throw std::logic_error("Decided to kill himself");
    }
    if (npc->type == RobberType) {
        // std::cout << "npc robber";
        visitor->visit(std::dynamic_pointer_cast<Robber>(shared_from_this()), std::dynamic_pointer_cast<Robber>(npc));
        return false;
    }
    if (npc->type == OrcType) {
        visitor->visit(std::dynamic_pointer_cast<Robber>(shared_from_this()), std::dynamic_pointer_cast<Orc>(npc));
        return true;
    } 
    if (npc->type == WerewolfType) {
        visitor->visit(std::dynamic_pointer_cast<Robber>(shared_from_this()), std::dynamic_pointer_cast<Werewolf>(npc));
        return true;
    }
    throw std::logic_error("Incorrect Type");
}
void Robber::fight(std::shared_ptr<Robber> robber) {
    fight_notify(robber, false);
    // std::cout << "Robber vs Robber" << std::endl;
}
void Robber::fight(std::shared_ptr<Orc> orc) {
    fight_notify(orc, false);
    // std::cout << "Robber vs Orc" << std::endl;
}
void Robber::fight(std::shared_ptr<Werewolf> werewolf) {
    fight_notify(werewolf, true);
    // std::cout << "Robber vs Werewolf" << std::endl;
}

// =======================================
// in and out
void Robber::save(std::ostream &os) {
    os << RobberType << ' ' << x << ' ' << y << std::endl;
}

std::ostream &operator<<(std::ostream &os, Robber &robber) {
    os << "Robber: " << *static_cast<NPC *>(&robber) << std::endl;
    return os;
}

