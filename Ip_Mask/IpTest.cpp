#include<iostream>
#include"Adress.cpp"

#include<gtest/gtest.h>

/*TEST(FlagTest, PositeveNos){
    ASSERT_TRUE(posled(5,6));
    ASSERT_TRUE(posled(-1, 1));
    ASSERT_TRUE(posled(0,0));
}
TEST(FlagTest, NegativeNos){
    ASSERT_FALSE(posled(6,5));
    ASSERT_FALSE(posled(1, -1));
    ASSERT_FALSE(posled(0,0));
}*/

TEST(IPTest, PositeveNos){
    ASSERT_TRUE(IP("10.10.10.10","10.10.9.5","255.255.248.0"));
    ASSERT_FALSE(IP("10.10.10.10","9.9.9.5","255.255.248.0"));
}
TEST(IPTest, NegativeNos){
    ASSERT_FALSE(IP("10.10.10.10","10.10.9.5","255.255.248.254"));
    ASSERT_FALSE(IP("10.10.10.10","10.10.9.5","255.256.248.0"));
}

int main(int argc, char ** argv){
    std::cout<<"Hello, gtest"<<std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}