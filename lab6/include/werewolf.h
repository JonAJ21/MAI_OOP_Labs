#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "npc.h"

struct Werewolf : public NPC {
    Werewolf(int x, int y);
    Werewolf(std::istream &is);

    void print() override;

    bool is_werewolf() const override;

    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Orc> other) override;
    bool fight(std::shared_ptr<Werewolf> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Werewolf &werewolf);
};

#endif // WEREWOLF_H