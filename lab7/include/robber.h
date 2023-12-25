#ifndef ROBBER_H
#define ROBBER_H

#include "npc.h"
#include "visitor.h"

class Robber final : public NPC {
public:
    Robber(int x, int y);
    Robber(std::istream& is);

    virtual bool accept(const std::shared_ptr<NPC>& attacker) const override;

    void print() override;
    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Robber& robber);
};

#endif // ROBBER_H