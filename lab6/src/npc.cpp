#include "npc.h"


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
