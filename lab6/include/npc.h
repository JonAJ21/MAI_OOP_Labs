#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <set>

// #include "robber.h"
// #include "orc.h"
// #include "werewolf.h"

class NPC;
class Robber;
class Orc;
class Werewolf;

// class IVisitor {};
// class FightVisitor : public IVisitor {};


using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    Unknown = 0,
    RobberType = 1,
    OrcType = 2,
    WerewolfType = 3
};

// class IFightObserver {
// public:
//     virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender, bool win) = 0;
// };

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
    // NPC() = default;
    NPC(NpcType t, int _x, int _y) : type(t), x(_x), y(_y) {
    }
    // NPC(NpcType t, std::istream &is);
    // virtual ~NPC() = default;

    // std::vector<std::shared_ptr<IFightObserver>> observers;
    // void subscribe(std::shared_ptr<IFightObserver> observer);
    // void fight_notify(const std::shared_ptr<NPC> defender, bool win);
    // virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;
    virtual void accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor = std::make_shared<FightVisitor>()) = 0;

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
    void accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor = std::make_shared<FightVisitor>()) override;
    void fight(std::shared_ptr<Robber> robber);
    void fight(std::shared_ptr<Orc> orc);
    void fight(std::shared_ptr<Werewolf> werewolf);
};

class Orc : public NPC {
public:
    Orc(int x, int y);
    void print() override;
    void accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor = std::make_shared<FightVisitor>()) override;
    void fight(std::shared_ptr<Robber> robber);
    void fight(std::shared_ptr<Orc> orc);
    void fight(std::shared_ptr<Werewolf> werewolf);
};

class Werewolf : public NPC {
public:
    Werewolf(int x, int y);
    void print() override;
    void accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor = std::make_shared<FightVisitor>()) override;
    void fight(std::shared_ptr<Robber> robber);
    void fight(std::shared_ptr<Orc> orc);
    void fight(std::shared_ptr<Werewolf> werewolf);
};




// class IFactory {
// public:
//     virtual std::shared_ptr<NPC> createNPC(int x, int y) = 0;
//     virtual std::shared_ptr<NPC> createNPC(std::istream & is) = 0;
// };

// class LogFightObserver : public IFightObserver {
// public:
//     void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender, bool win) override {
//         if (win) {
//             // Скорее всего лучше подавать имя файла в качестве параметра
//             std::ofstream out;
//             out.open("log.txt");
//             if (out.is_open()) {
//                 out << std::endl
//                     << "Murder --------" << std::endl;
//                 attacker->print();
//                 defender->print();
//             }
//         }
//     }
// };

// class PrintFightObserver : public IFightObserver {
// public:
//     void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender, bool win) override {
//         if (win) {
//             std::cout << std::endl
//                       << "Murder --------" << std::endl;
//             attacker->print();
//             defender->print();
//         }
//     }
// };












// class OrcFactory : public IFactory {
// public:

//     std::shared_ptr<NPC> createNPC(int x, int y) override {
//         return std::make_shared<Orc>(x, y);
//     }
//     std::shared_ptr<NPC> createNPC(std::istream & is) override {
//         return std::make_shared<Orc>(is);
//     }
// };





#endif // NPC_H