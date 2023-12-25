#ifndef FACTORY_H
#define FACTORY_H

#include "npc.h"
#include "orc.h"
#include "werewolf.h"
#include "robber.h"
#include "observer.h"

class Factory {
public:
    static std::shared_ptr<NPC> CreateNPC(const NpcType& type, int x, int y) {
        std::shared_ptr<NPC> result;
        if (type > NpcType::UnknownType && type < NpcType::Max) {
            switch (type) {
                case NpcType::RobberType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Robber>(x, y));
                    break;

                case NpcType::WerewolfType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Werewolf>(x, y));
                    break;

                case NpcType::OrcType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Orc>(x, y));
                    break;

                default:
                    break;
            }
        } else {
            std::string err = "unexpected NPC type: " + type;
            throw std::runtime_error(err);
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }

    static std::shared_ptr<NPC> CreateNPC(std::istream& is) {
        std::shared_ptr<NPC> result;
        int type{0};
        if (is >> type && type > NpcType::UnknownType && type < NpcType::Max) {
            switch (type) {
                case NpcType::RobberType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Robber>(is));
                    break;

                case NpcType::WerewolfType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Werewolf>(is));
                    break;

                case NpcType::OrcType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Orc>(is));
                    break;

                default:
                    break;
            }
        } else {
            std::string err = "unexpected NPC type: " + type;
            throw std::runtime_error(err);
        }
        
        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }
};

#endif // FACTORY_H