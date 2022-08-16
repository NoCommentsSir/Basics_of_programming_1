#include<iostream>
#include"Untitled.cpp"

#include<gtest/gtest.h>

TEST(FlagTest, PositeveNos){
    ASSERT_TRUE(posled(5,6));
    ASSERT_TRUE(posled(-1, 1));
    ASSERT_TRUE(posled(0,0));
}
TEST(FlagTest, NegativeNos){
    ASSERT_FALSE(posled(6,5));
    ASSERT_FALSE(posled(1, -1));
    ASSERT_FALSE(posled(0,0));
}
TEST(SravnFlagTest, PositeveNos){
    ASSERT_EQ(sravn(true, 5, 6), 2);
    ASSERT_EQ(sravn(false, 5, 6), 0);
    ASSERT_EQ(sravn(false, 6, 5), 3);
    ASSERT_EQ(sravn(true, 7, 6), 1);
}
TEST(PosledTest, PositeveNos){
    ASSERT_EQ(posl(), 0);
    ASSERT_EQ(posl(), 1);
    ASSERT_EQ(posl(), 2);
    ASSERT_EQ(posl(), 3);
    ASSERT_EQ(posl(), 4);
}
int main(int argc, char ** argv){
    std::cout<<"Hello, gtest"<<std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}