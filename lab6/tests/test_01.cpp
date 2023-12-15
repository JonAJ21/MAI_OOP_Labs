#include <gtest/gtest.h>
#include "npc.h"


TEST(robber, All) {
    Robber rob1(2,5);
    Robber rob2(7,2);
    ASSERT_TRUE(rob1.x == 2 && rob1.y == 5);
    ASSERT_TRUE(rob2.x == 7 && rob2.y == 2);
    RobberFactory robber_factory;
    auto prob1 = robber_factory.createNPC(2, 5);
    ASSERT_TRUE(prob1->x == 2 && prob1->y == 5);

}

TEST(Orc, All) {
    Orc orc1(2,5);
    Orc orc2(7,2);
    ASSERT_TRUE(orc1.x == 2 && orc1.y == 5);
    ASSERT_TRUE(orc2.x == 7 && orc2.y == 2);
    OrcFactory orc_factory;
    auto porc1 = orc_factory.createNPC(2, 5);
    ASSERT_TRUE(porc1->x == 2 && porc1->y == 5);
}

TEST(werewolf, All) {
    Werewolf werewolf1(2,5);
    Werewolf werewolf2(7,2);
    ASSERT_TRUE(werewolf1.x == 2 && werewolf1.y == 5);
    ASSERT_TRUE(werewolf2.x == 7 && werewolf2.y == 2);
    WerewolfFactory werewolf_factory;
    auto pwerewolf1 = werewolf_factory.createNPC(2, 5);
    ASSERT_TRUE(pwerewolf1->x == 2 && pwerewolf1->y == 5);
}

TEST(visitor, All) {
    RobberFactory robber_factory;
    OrcFactory orc_factory;
    WerewolfFactory werewolf_factory;
    auto robber1 = robber_factory.createNPC(0, 1);
    auto orc1 = orc_factory.createNPC(1, 0);
    auto werewolf1 = werewolf_factory.createNPC(1, 1);
    auto robber2 = robber_factory.createNPC(0, 1);
    auto orc2 = orc_factory.createNPC(1, 0);
    auto werewolf2 = werewolf_factory.createNPC(1, 1);

    ASSERT_TRUE(!robber1->accept(robber2));
    ASSERT_TRUE(robber1->accept(orc2));
    ASSERT_TRUE(robber1->accept(werewolf2));

    ASSERT_TRUE(!orc1->accept(robber2));
    ASSERT_TRUE(!orc1->accept(orc2));
    ASSERT_TRUE(!orc1->accept(werewolf2));

    ASSERT_TRUE(werewolf1->accept(robber2));
    ASSERT_TRUE(!werewolf1->accept(orc2));
    ASSERT_TRUE(!werewolf1->accept(werewolf2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}