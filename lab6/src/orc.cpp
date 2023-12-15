#include "npc.h"

// =======================================
// Orc

Orc::Orc(int x, int y) : NPC(OrcType, x, y) {}

Orc::Orc(std::istream & is) : NPC(OrcType, is) {}

void Orc::print() {
    std::cout << *this;
}

void Orc::print(std::ofstream& of) {
    of << *this;
} 

bool Orc::accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor) {
    if (npc == shared_from_this()) {
        throw std::logic_error("Decided to kill himself");
    }
    if (npc->type == RobberType) {
        visitor->visit(std::dynamic_pointer_cast<Orc>(shared_from_this()), std::dynamic_pointer_cast<Robber>(npc));
        return false;
    }
    if (npc->type == OrcType) {
        visitor->visit(std::dynamic_pointer_cast<Orc>(shared_from_this()), std::dynamic_pointer_cast<Orc>(npc));
        return false;
    } 
    if (npc->type == WerewolfType) {
        visitor->visit(std::dynamic_pointer_cast<Orc>(shared_from_this()), std::dynamic_pointer_cast<Werewolf>(npc));
        return false;
    }
    throw std::logic_error("Incorrect Type");
}

void Orc::fight(std::shared_ptr<Robber> robber) {
    fight_notify(robber, true);
    // std::cout << "Orc vs Robber" << std::endl;
}
void Orc::fight(std::shared_ptr<Orc> orc) {
    fight_notify(orc, false);
    // std::cout << "Orc vs Orc" << std::endl;
}
void Orc::fight(std::shared_ptr<Werewolf> werewolf) {
    fight_notify(werewolf, false);
    // std::cout << "Orc vs Werewolf" << std::endl;
}

// =======================================
// in and out
void Orc::save(std::ostream &os) {
    os << OrcType << ' ' << x << ' ' << y << std::endl;
}

std::ostream &operator<<(std::ostream &os, Orc &orc) {
    os << "Orc: " << *static_cast<NPC *>(&orc) << std::endl;
    return os;
}