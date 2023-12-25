#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "npc.h"
#include "visitor.h"

class Werewolf final : public NPC {
public:
    Werewolf(int x, int y);
    Werewolf(std::istream& is);

    virtual bool accept(const std::shared_ptr<NPC>& attacker) const override;

    void print() override;
    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Werewolf& werewolf);
};

#endif // WEREWOLF_H