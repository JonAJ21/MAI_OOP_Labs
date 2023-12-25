#ifndef ORC_H
#define ORC_H

#include "npc.h"
#include "visitor.h"

class Orc final : public NPC {
public:
    Orc(int x, int y);
    Orc(std::istream& is);

    virtual bool accept(const std::shared_ptr<NPC>& attacker) const override;

    void print() override;
    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Orc& orc);
};

#endif // ORC_H