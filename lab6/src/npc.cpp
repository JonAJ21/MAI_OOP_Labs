#include "npc.h"


// =======================================
// RobberFactory

std::shared_ptr<NPC> RobberFactory::createNPC(int x, int y) {
    auto res = std::make_shared<Robber>(x, y);
    res->subscribe(PrintFightObserver::get());
    return res;
}

// std::shared_ptr<NPC> RobberFactory::createNPC(std::istream & is) {
//     return std::make_shared<Robber>(is);
// }

// =======================================
// OrcFactory

std::shared_ptr<NPC> OrcFactory::createNPC(int x, int y) {
    auto res = std::make_shared<Orc>(x, y);
    res->subscribe(PrintFightObserver::get());
    return res;
}

// std::shared_ptr<NPC> OrcFactory::createNPC(std::istream & is) {
//     return std::make_shared<Orc>(is);
// }

// =======================================
// WerewolfFactory

std::shared_ptr<NPC> WerewolfFactory::createNPC(int x, int y) {
    auto res = std::make_shared<Werewolf>(x, y);
    res->subscribe(PrintFightObserver::get());
    return res;
}

// std::shared_ptr<NPC> WerewolfFactory::createNPC(std::istream & is) {
//     return std::make_shared<Werewolf>(is);
// }


// =======================================
// LogFightObserver

void LogFightObserver::on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender, bool win) {
    if (win) {
        // Скорее всего лучше подавать имя файла в качестве параметра
        std::ofstream out;
        out.open("log.txt");
        if (out.is_open()) {
            out << std::endl
                << "Murder --------" << std::endl;
            attacker->print();
            defender->print();
        }
    }
}

// =======================================
// PrintFightObserver

void PrintFightObserver::on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender, bool win) {
    if (win) {
        std::cout << std::endl
                    << "Murder --------" << std::endl;
        attacker->print();
        defender->print();
    }
}

// =======================================
// FightVisitor

void FightVisitor::visit(std::shared_ptr<Robber> robber, std::shared_ptr<Robber> other) {
        robber->fight(other);
}

void FightVisitor::visit(std::shared_ptr<Robber> robber, std::shared_ptr<Orc> other) {
        robber->fight(other);
}
void FightVisitor::visit(std::shared_ptr<Robber> robber, std::shared_ptr<Werewolf> other) {
    robber->fight(other);
}

void FightVisitor::visit(std::shared_ptr<Orc> orc, std::shared_ptr<Robber> other) {
    orc->fight(other);
}
void FightVisitor::visit(std::shared_ptr<Orc> orc, std::shared_ptr<Orc> other) {
    orc->fight(other);
}
void FightVisitor::visit(std::shared_ptr<Orc> orc, std::shared_ptr<Werewolf> other) {
    orc->fight(other);
}

void FightVisitor::visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Robber> other) {
    werewolf->fight(other);
}
void FightVisitor::visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Orc> other) {
    werewolf->fight(other);
}
void FightVisitor::visit(std::shared_ptr<Werewolf> werewolf, std::shared_ptr<Werewolf> other) {
     werewolf->fight(other);
}


// =======================================
// Subscribe

void NPC::subscribe(std::shared_ptr<IFightObserver> observer) {
    observers.push_back(observer);
}

// =======================================
// Fight_notify

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win) {
    for (auto &o : observers) {
        o->on_fight(shared_from_this(), defender, win);
    }
}

// =======================================
// Is_close

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const {
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}  

// =======================================
// std::ostream

std::ostream &operator<<(std::ostream &os, NPC &npc) {
    os << "{ x:" << npc.x << ", y:" << npc.y << "} ";
    return os;
}
