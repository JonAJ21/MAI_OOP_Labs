#include "werewolf.h"

Werewolf::Werewolf(int x, int y) : NPC(WerewolfType, x, y) {
    move_distance = 40;
    kill_distance = 5;
}

Werewolf::Werewolf(std::istream& is) : NPC(WerewolfType, is) {
    move_distance = 40;
    kill_distance = 5;
}

bool Werewolf::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Werewolf> defender = std::dynamic_pointer_cast<Werewolf>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Werewolf::print() {
    std::cout << *this;
}

void Werewolf::save(std::ostream& os) {
    os << WerewolfType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Werewolf& werewolf) {
    os << "werewolf " << *static_cast<NPC*>(&werewolf) << std::endl;
    return os;
}