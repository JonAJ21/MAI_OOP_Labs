#include "npc.h"
#include "robber.h"
#include "orc.h"
#include "werewolf.h"

Robber::Robber(int x, int y) : NPC(RobberType, x, y) {}
Robber::Robber(std::istream &is) : NPC(RobberType, is) {}

void Robber::print()
{
    std::cout << *this;
}

void Robber::save(std::ostream &os)
{
    os << RobberType << std::endl;
    NPC::save(os);
}
bool Robber::is_robber() const
{
    return true;
}

bool Robber::fight(std::shared_ptr<Robber> other)
{
    fight_notify(other, true);
    return true;
}

bool Robber::fight(std::shared_ptr<Orc> other)
{
    fight_notify(other, false);
    return false;
}

bool Robber::fight(std::shared_ptr<Werewolf> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Robber &robber)
{
    os << "Robber: " << *static_cast<NPC *>(&robber) << std::endl;
    return os;
}