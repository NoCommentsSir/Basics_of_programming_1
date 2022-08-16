#include<iostream>
#include"Safety.cpp"
#include<string>
#include<gtest/gtest.h>

TEST(List, getItemest){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(4);
    list.add(9);
    list.add(0);
    ASSERT_EQ(list.getItem(0), 1);
    ASSERT_EQ(list.getItem(1), 2);
    ASSERT_EQ(list.getItem(2), -1);
    ASSERT_EQ(list.getItem(3), 4);
    ASSERT_EQ(list.getItem(4), 9);
    ASSERT_EQ(list.getItem(5), 0);
}
TEST(List, Count){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(9);
    list.add(0);
    ASSERT_EQ(list.count(), 5);
}
TEST(List, addTest){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(9);
    list.add(0);
    list.add(7);
    ASSERT_EQ("1 2 -1 9 0 7 ", list.print());
}
TEST(List, delLastTest){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(9);
    list.add(0);
    list.add(7);
    list.delete_Last();
    list.delete_Last();
    ASSERT_EQ("1 2 -1 9 ", list.print());
}
TEST(List, delIndexTestPositive){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(9);
    list.add(0);
    list.add(7);
    list.DeleteWthIndex(0, list);
    list.DeleteWthIndex(list.count()-1, list);
    list.DeleteWthIndex(2, list);
    ASSERT_EQ("2 -1 0 ", list.print());
}
TEST(List, delIndexTestNegative){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(9);
    list.add(0);
    list.add(7);
    list.DeleteWthIndex(9, list);
    list.DeleteWthIndex(list.count(), list);
    ASSERT_EQ("1 2 -1 9 0 7 ", list.print());
}
TEST(List, addIndexTestPositive){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(9);
    list.add(0);
    list.add(7);
    list.AddWthIndex(0, 1, list);
    list.AddWthIndex(list.count(), 1, list);
    list.AddWthIndex(3, 1, list);
    ASSERT_EQ("1 1 2 1 -1 9 0 7 1 ", list.print());
}
TEST(List, addIndexTestNegative){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(9);
    list.add(0);
    list.add(7);
    list.AddWthIndex(list.count()+1, 1, list);
    list.AddWthIndex(9, 1, list);
    ASSERT_EQ("1 2 -1 9 0 7 ", list.print());
}
TEST(List, swapTestPositive){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(9);
    list.add(0);
    list.add(7);
    list.swapListItem(0, list.count()-1, list);
    list.swapListItem(0, 3, list);
    list.swapListItem(list.count()-1, 2, list);
    list.swapListItem(4, 3, list);
    ASSERT_EQ("9 2 1 0 7 -1 ", list.print());
}
TEST(List, swapTestNegative){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(9);
    list.add(0);
    list.add(7);
    list.swapListItem(0, 0, list);
    list.swapListItem(9, 3, list);
    list.swapListItem(3, 10, list);
    list.swapListItem(99, 80, list);
    ASSERT_EQ("1 2 -1 9 0 7 ", list.print());
}
TEST(List, sortTest){
    List list;
    list.add(1);
    list.add(2);
    list.add(-1);
    list.add(9);
    list.add(0);
    list.add(7);
    list.sort(list, 0, list.count()-1);
    ASSERT_EQ("-1 0 1 2 7 9 ", list.print());
}
TEST(List, Full_Test){
    List list;
    list.add(231);
    list.add(-192);
    list.add(-1);
    list.add(69);
    list.add(9000);
    list.add(-75);
    list.delete_Last();
    list.DeleteWthIndex(1, list);
    list.AddWthIndex(2, 620, list);
    list.swapListItem(list.count()-1, 0, list);
    list.sort(list, 0, list.count()-1);
    ASSERT_EQ("-1 69 231 620 9000 ", list.print());
}
int main(int argc, char ** argv){
    std::cout<<"Hello, gtest"<<std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}