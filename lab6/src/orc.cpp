#include "npc.h"
#include "robber.h"
#include "orc.h"
#include "werewolf.h"

Orc::Orc(int x, int y) : NPC(OrcType, x, y) {}
Orc::Orc(std::istream &is) : NPC(OrcType, is) {}

void Orc::print()
{
    std::cout << *this;
}

void Orc::save(std::ostream &os)
{
    os << OrcType << std::endl;
    NPC::save(os);
}
bool Orc::is_orc() const
{
    return true;
}

bool Orc::fight(std::shared_ptr<Robber> other)
{
    fight_notify(other, true);
    return true;
}

bool Orc::fight(std::shared_ptr<Orc> other)
{
    fight_notify(other, false);
    return false;
}

bool Orc::fight(std::shared_ptr<Werewolf> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Orc &orc)
{
    os << "Orc: " << *static_cast<NPC *>(&orc) << std::endl;
    return os;
}