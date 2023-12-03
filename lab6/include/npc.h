#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <cmath>

struct NPC;
struct Robber;
struct Orc;
struct Werewolf;

using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    Unknown = 0,
    RobberType = 1,
    OrcType = 2,
    WerewolfType = 3
};

struct IFightObserver {
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender, bool win) = 0;
};

struct NPC : public std::enable_shared_from_this<NPC> {
    NpcType type;
    int x {0};
    int y {0};
    std::vector<std::shared_ptr<IFightObserver>> observers;
    
    NPC(NpcType t, int _x, int _y);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightObserver>observer );
    void fight_notify(const std::shared_ptr<NPC> defender,bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    virtual bool is_robber() const;
    virtual bool is_orc() const;
    virtual bool is_werewolf() const;

    virtual bool fight(std::shared_ptr<Robber> other) = 0;
    virtual bool fight(std::shared_ptr<Orc> other) = 0;
    virtual bool fight(std::shared_ptr<Werewolf> other) = 0;
    virtual void print() = 0;

    virtual void save(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};


#endif // NPC_H