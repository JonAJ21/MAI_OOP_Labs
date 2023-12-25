#include <gtest/gtest.h>
#include "npc.h"
#include "robber.h"
#include "werewolf.h"
#include "orc.h"
#include "visitor.h"

std::shared_ptr<NPC> orc = std::make_shared<Orc>(21, 17);
std::shared_ptr<NPC> werewolf = std::make_shared<Werewolf>(20, 16);
std::shared_ptr<NPC> robber = std::make_shared<Robber>(100, 17);
std::shared_ptr<Visitor> orc_visitor = std::make_shared<OrcVisitor>();
std::shared_ptr<Visitor> werewolf_visitor = std::make_shared<WerewolfVisitor>();
std::shared_ptr<Visitor> robber_visitor = std::make_shared<RobberVisitor>();

TEST(VisitorTest, Orc) {
    ASSERT_FALSE(orc_visitor->visit(std::static_pointer_cast<Orc>(orc)));
    ASSERT_TRUE(orc_visitor->visit(std::static_pointer_cast<Werewolf>(werewolf)));
    ASSERT_TRUE(orc_visitor->visit(std::static_pointer_cast<Robber>(robber)));
}

TEST(VisitorTest, Werewolf) {
    ASSERT_FALSE(werewolf_visitor->visit(std::static_pointer_cast<Orc>(orc)));
    ASSERT_FALSE(werewolf_visitor->visit(std::static_pointer_cast<Werewolf>(werewolf)));
    ASSERT_TRUE(werewolf_visitor->visit(std::static_pointer_cast<Robber>(robber)));
}

TEST(VisitorTest, Robber) {
    ASSERT_FALSE(robber_visitor->visit(std::static_pointer_cast<Orc>(orc)));
    ASSERT_FALSE(robber_visitor->visit(std::static_pointer_cast<Werewolf>(werewolf)));
    ASSERT_FALSE(robber_visitor->visit(std::static_pointer_cast<Robber>(robber)));
}

TEST(AcceptTest, Orc) {
    ASSERT_FALSE(orc->accept(orc));
    ASSERT_TRUE(werewolf->accept(orc));
    ASSERT_TRUE(robber->accept(orc));    
}

TEST(AcceptTest, Werewolf) {
    ASSERT_FALSE(orc->accept(werewolf));
    ASSERT_FALSE(werewolf->accept(werewolf));
    ASSERT_TRUE(robber->accept(werewolf));
}

TEST(AcceptTest, Robber) {
    ASSERT_FALSE(orc->accept(robber));
    ASSERT_FALSE(werewolf->accept(robber));
    ASSERT_FALSE(robber->accept(robber));
}

TEST(DistanceTest, IsClose) {
    ASSERT_FALSE(orc->is_close(robber));
    ASSERT_FALSE(robber->is_close(werewolf));
    ASSERT_TRUE(werewolf->is_close(orc));
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}