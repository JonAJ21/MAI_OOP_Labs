#ifndef ORC_H
#define ORC_H

#include "npc.h"

struct Orc : public NPC {
    Orc(int x, int y);
    Orc(std::istream &is);

    void print() override;

    bool is_orc() const override;

    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Orc> other) override;
    bool fight(std::shared_ptr<Werewolf> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Orc &werewolf);
};

#endif // ORC_H