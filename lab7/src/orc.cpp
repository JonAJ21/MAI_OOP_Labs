#include "orc.h"

Orc::Orc(int x, int y) : NPC(OrcType, x, y) {
    move_distance = 20;
    kill_distance = 10;
}

Orc::Orc(std::istream& is) : NPC(OrcType, is) {
    move_distance = 20;
    kill_distance = 10;
}

bool Orc::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Orc> defender = std::dynamic_pointer_cast<Orc>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Orc::print() {
    std::cout << *this;
}

void Orc::save(std::ostream& os) {
    os << OrcType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Orc& orc) {
    os << "orc " << *static_cast<NPC*>(&orc) << std::endl;
    return os;
}