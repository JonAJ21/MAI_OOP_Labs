#ifndef ROBBER_H
#define ROBBER_H

#include "npc.h"

struct Robber : public NPC {
    Robber(int x, int y);
    Robber(std::istream &is);

    void print() override;

    bool is_robber() const override;

    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Orc> other) override;
    bool fight(std::shared_ptr<Werewolf> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Robber &robber);
};

#endif // ROBBER_H