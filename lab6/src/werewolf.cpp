#include "npc.h"

// =======================================
// Werewolf

Werewolf::Werewolf(int x, int y) : NPC(WerewolfType, x, y) {}

Werewolf::Werewolf(std::istream & is) : NPC(WerewolfType, is) {}

void Werewolf::print() {
    std::cout << *this;
}

void Werewolf::print(std::ofstream& of) {
    of << *this;
} 

bool Werewolf::accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor){
    if (npc == shared_from_this()) {
        throw std::logic_error("Decided to kill himself");
    }
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
// in and out

void Werewolf::save(std::ostream &os) {
    os << WerewolfType << ' ' << x << ' ' << y << std::endl;
}

std::ostream &operator<<(std::ostream &os, Werewolf const &werewolf) {
    os << "Werewolf: " << *static_cast<NPC *>(&werewolf) << std::endl;
    return os;
}