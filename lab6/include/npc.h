#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <set>
#include <cmath>

class NPC;
class Robber;
class Orc;
class Werewolf;

using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    Unknown = 0,
    RobberType = 1,
    OrcType = 2,
    WerewolfType = 3
};


class IFactory {
public:
    virtual std::shared_ptr<NPC> createNPC(int x, int y) = 0;
    // virtual std::shared_ptr<NPC> createNPC(std::istream & is) = 0;
};

class RobberFactory : public IFactory {
public:
    std::shared_ptr<NPC> createNPC(int x, int y) override;
    // std::shared_ptr<NPC> createNPC(std::istream & is) override;
};

class OrcFactory : public IFactory {
public:
    std::shared_ptr<NPC> createNPC(int x, int y) override;
    // std::shared_ptr<NPC> createNPC(std::istream & is) override;
};

class WerewolfFactory : public IFactory {
public:
    std::shared_ptr<NPC> createNPC(int x, int y) override;
    // std::shared_ptr<NPC> createNPC(std::istream & is) override;
};

class IFightObserver {
public:
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender, bool win) = 0;
};

class LogFightObserver : public IFightObserver {
public:
    void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender, bool win) override;
};

class PrintFightObserver : public IFightObserver {
private: 
    PrintFightObserver(){};
public:
    static std::shared_ptr<IFightObserver> get()
    {
        static PrintFightObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }
    void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender, bool win) override;
};





class IVisitor {
public:
    virtual void visit(std::shared_ptr<Robber> robber, std::shared_ptr<Robber> other) = 0;
    virtual void visit(std::shared_ptr<Robber> robber, std::shared_ptr<Orc> other) = 0;
    virtual void visit(std::shared_ptr<Robber> robber, std::shared_ptr<Werewolf> other) = 0;

    virtual void visit(std::shared_ptr<Orc> orc, std::shared_ptr<Robber> other) = 0;
    virtual void visit(std::shared_ptr<Orc> orc, std::shared_ptr<Orc> other) = 0;
    virtual void visit(std::shared_ptr<Orc> orc, std::shared_ptr<Werewolf> other) = 0;

    virtual void visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Robber> other) = 0;
    virtual void visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Orc> other) = 0;
    virtual void visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Werewolf> other) = 0;   
};

class FightVisitor : public IVisitor {
    void visit(std::shared_ptr<Robber> robber, std::shared_ptr<Robber> other) override;
    void visit(std::shared_ptr<Robber> robber, std::shared_ptr<Orc> other) override;
    void visit(std::shared_ptr<Robber> robber, std::shared_ptr<Werewolf> other) override;

    void visit(std::shared_ptr<Orc> orc, std::shared_ptr<Robber> other) override;
    void visit(std::shared_ptr<Orc> orc, std::shared_ptr<Orc> other) override;
    void visit(std::shared_ptr<Orc> orc, std::shared_ptr<Werewolf> other) override;

    void visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Robber> other) override;
    void visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Orc> other) override;
    void visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Werewolf> other) override;
};


class NPC : public std::enable_shared_from_this<NPC> {
public:
    NpcType type;
    int x = 0;
    int y = 0;
    NPC(NpcType t, int _x, int _y) : type(t), x(_x), y(_y) {
    }
    // NPC(NpcType t, std::istream &is);

    std::vector<std::shared_ptr<IFightObserver>> observers;
    void subscribe(std::shared_ptr<IFightObserver> observer);
    void fight_notify(const std::shared_ptr<NPC> defender, bool win);
    bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    virtual bool accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor = std::make_shared<FightVisitor>()) = 0;

    virtual void fight(std::shared_ptr<Robber> robber) = 0;
    virtual void fight(std::shared_ptr<Orc> orc) = 0;
    virtual void fight(std::shared_ptr<Werewolf> werewolf) = 0;


    virtual void print() = 0;
    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};

class Robber : public NPC {
public:
    Robber(int x, int y);
    void print() override;
    bool accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor = std::make_shared<FightVisitor>()) override;
    void fight(std::shared_ptr<Robber> robber);
    void fight(std::shared_ptr<Orc> orc);
    void fight(std::shared_ptr<Werewolf> werewolf);
    friend std::ostream &operator<<(std::ostream &os, Robber &robber);
};

class Orc : public NPC {
public:
    Orc(int x, int y);
    void print() override;
    bool accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor = std::make_shared<FightVisitor>()) override;
    void fight(std::shared_ptr<Robber> robber);
    void fight(std::shared_ptr<Orc> orc);
    void fight(std::shared_ptr<Werewolf> werewolf);
    friend std::ostream &operator<<(std::ostream &os, Orc &orc);
};

class Werewolf : public NPC {
public:
    Werewolf(int x, int y);
    void print() override;
    bool accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor = std::make_shared<FightVisitor>()) override;
    void fight(std::shared_ptr<Robber> robber);
    void fight(std::shared_ptr<Orc> orc);
    void fight(std::shared_ptr<Werewolf> werewolf);
    friend std::ostream &operator<<(std::ostream &os, Werewolf &werewolf);
};


#endif // NPC_H