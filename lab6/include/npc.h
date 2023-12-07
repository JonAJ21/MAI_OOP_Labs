#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <set>

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

// class FightVisitor;


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
    virtual void accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor) = 0;
    // virtual void accept(std::shared_ptr<Robber> robber, std::shared_ptr<IVisitor> visitor) = 0;
    // virtual void accept(std::shared_ptr<Orc> orc, std::shared_ptr<IVisitor> visitor) = 0;
    // virtual void accept(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<IVisitor> visitor) = 0;

    virtual void fight(std::shared_ptr<Robber> robber) = 0;
    virtual void fight(std::shared_ptr<Orc> orc) = 0;
    virtual void fight(std::shared_ptr<Werewolf> werewolf) = 0;


    virtual void print() = 0;
    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
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
class Robber : public NPC {
public:
    
    Robber(int x, int y) : NPC(RobberType, x, y){
    }
    // ~Robber() = default;

    void print() override {

    }

    void accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor) override {
        if (npc->type == RobberType) {
            // std::cout << "npc robber";
            visitor->visit(std::dynamic_pointer_cast<Robber>(shared_from_this()), std::dynamic_pointer_cast<Robber>(npc));
            return;
        }
        if (npc->type == OrcType) {
            visitor->visit(std::dynamic_pointer_cast<Robber>(shared_from_this()), std::dynamic_pointer_cast<Orc>(npc));
            return;
        } 
        if (npc->type == WerewolfType) {
            visitor->visit(std::dynamic_pointer_cast<Robber>(shared_from_this()), std::dynamic_pointer_cast<Werewolf>(npc));
            return;
        }
        throw std::logic_error("Incorrect Type");
    }

    void fight(std::shared_ptr<Robber> robber) {
        std::cout << "Robber vs Robber" << std::endl;
    }
    void fight(std::shared_ptr<Orc> orc) {
        std::cout << "Robber vs Orc" << std::endl;
    }
    void fight(std::shared_ptr<Werewolf> werewolf) {
        std::cout << "Robber vs Werewolf" << std::endl;
    }

    // friend std::ostream &operator<<(std::ostream &os, Orc &orc) {
    //     return os;
    // }
};


class Orc : public NPC {
public:
    
    Orc(int x, int y) : NPC(OrcType, x, y){
    }
    // ~Orc() = default;

    void print() override {

    }

    void accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor) override {
        if (npc->type == RobberType) {
            visitor->visit(std::dynamic_pointer_cast<Orc>(shared_from_this()), std::dynamic_pointer_cast<Robber>(npc));
            return;
        }
        if (npc->type == OrcType) {
            visitor->visit(std::dynamic_pointer_cast<Orc>(shared_from_this()), std::dynamic_pointer_cast<Orc>(npc));
            return;
        } 
        if (npc->type == WerewolfType) {
            visitor->visit(std::dynamic_pointer_cast<Orc>(shared_from_this()), std::dynamic_pointer_cast<Werewolf>(npc));
            return;
        }
        throw std::logic_error("Incorrect Type");
    }

    void fight(std::shared_ptr<Robber> robber) {
        std::cout << "Orc vs Robber" << std::endl;
    }
    void fight(std::shared_ptr<Orc> orc) {
        std::cout << "Orc vs Orc" << std::endl;
    }
    void fight(std::shared_ptr<Werewolf> werewolf) {
        std::cout << "Orc vs Werewolf" << std::endl;
    }

    // friend std::ostream &operator<<(std::ostream &os, Orc &orc) {
    //     return os;
    // }
};

class Werewolf : public NPC {
public:
    
    Werewolf(int x, int y) : NPC(WerewolfType, x, y){
    }
    // ~Werewolf() = default;

    void print() override {

    }

    void accept(std::shared_ptr<NPC> npc, std::shared_ptr<IVisitor> visitor) override {
        if (npc->type == RobberType) {
            visitor->visit(std::dynamic_pointer_cast<Werewolf>(shared_from_this()), std::dynamic_pointer_cast<Robber>(npc));
            return;
        }
        if (npc->type == OrcType) {
            visitor->visit(std::dynamic_pointer_cast<Werewolf>(shared_from_this()), std::dynamic_pointer_cast<Orc>(npc));
            return;
        } 
        if (npc->type == WerewolfType) {
            visitor->visit(std::dynamic_pointer_cast<Werewolf>(shared_from_this()), std::dynamic_pointer_cast<Werewolf>(npc));
            return;
        }
        throw std::logic_error("Incorrect Type");
    }

    void fight(std::shared_ptr<Robber> robber) {
        std::cout << "Werewolf vs Robber" << std::endl;
    }
    void fight(std::shared_ptr<Orc> orc) {
        std::cout << "Werewolf vs Orc" << std::endl;
    }
    void fight(std::shared_ptr<Werewolf> werewolf) {
        std::cout << "Werewolf vs Werewolf" << std::endl;
    }

    // friend std::ostream &operator<<(std::ostream &os, Orc &orc) {
    //     return os;
    // }
};

class FightVisitor : public IVisitor {
public:
    void visit(std::shared_ptr<Robber> robber, std::shared_ptr<Robber> other) {
        robber->fight(other);
    }
    void visit(std::shared_ptr<Robber> robber, std::shared_ptr<Orc> other) {
        robber->fight(other);
    }
    void visit(std::shared_ptr<Robber> robber, std::shared_ptr<Werewolf> other) {
        robber->fight(other);
    }

    void visit(std::shared_ptr<Orc> orc, std::shared_ptr<Robber> other) {
        orc->fight(other);
    }
    void visit(std::shared_ptr<Orc> orc, std::shared_ptr<Orc> other) {
        orc->fight(other);
    }
    void visit(std::shared_ptr<Orc> orc, std::shared_ptr<Werewolf> other) {
        orc->fight(other);
    }

    void visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Robber> other) {
        werewolf->fight(other);
    }
    void visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Orc> other) {
        werewolf->fight(other);
    }
    void visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Werewolf> other) {
        werewolf->fight(other);
    }
};

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