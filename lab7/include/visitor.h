#ifndef VISITOR_H
#define VISITOR_H

#include "npc.h"
#include "orc.h"
#include "werewolf.h"
#include "robber.h"

class Visitor {
public:
    virtual bool visit(const std::shared_ptr<NPC>&) const = 0;
};

class RobberVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::RobberType:
                result = false;
                break;

            case NpcType::WerewolfType:
                result = true;
                break;
            
            case NpcType::OrcType:
                result = false;
                break;
        }
        return result;
    }
};

class WerewolfVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::RobberType:
                result = true;
                break;

            case NpcType::WerewolfType:
                result = false;
                break;
            
            case NpcType::OrcType:
                result = false;
                break;
        }
        return result;
    }
};

class OrcVisitor final : public Visitor {
public:
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::RobberType:
                result = true;
                break;

            case NpcType::WerewolfType:
                result = false;
                break;
            
            case NpcType::OrcType:
                result = false;
                break;
        }
        return result;
    }
};

class VisitorFactory {
public:
    static std::shared_ptr<Visitor> CreateVisitor(const NpcType& type) {
        std::shared_ptr<Visitor> result;
        switch (type) {
            case NpcType::OrcType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<OrcVisitor>());
                break;

            case NpcType::WerewolfType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<WerewolfVisitor>());
                break;

            case NpcType::RobberType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<RobberVisitor>());
                break;
            default:
                break;
        }
        return result;
    }
};

#endif // VISITOR_H