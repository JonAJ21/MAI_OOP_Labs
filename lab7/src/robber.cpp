#include "robber.h"

Robber::Robber(int x, int y) : NPC(RobberType, x, y) {
    move_distance = 5;
    kill_distance = 5;
}

Robber::Robber(std::istream& is) : NPC(RobberType, is) {
    move_distance = 5;
    kill_distance = 5;
}

bool Robber::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Robber> defender = std::dynamic_pointer_cast<Robber>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Robber::print() {
    std::cout << *this;
}

void Robber::save(std::ostream& os) {
    os << RobberType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Robber& robber) {
    os << "robber " << *static_cast<NPC*>(&robber) << std::endl;
    return os;
}