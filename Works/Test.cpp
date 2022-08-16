#include<iostream>
#include"Zach.cpp"
#include<string>
#include<gtest/gtest.h>

TEST(Minimum, addtest){
    int n = 4;
    int m = 4;
    List list;
    int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	add(arr, n, m);
    cout<<"Kolichestvo prav"<<endl;
    int kol;
    cin>>kol;
    cout<<"Sami prav"<<endl;
    int** exp = new int*[kol];
    for (int i = 0; i < kol; i++) {
        exp[i] = new int[3];
	}
    for(int i = 0; i < kol; i++){
        cout<<"Answer is:"<<endl;
        for(int j = 0; j < 3; j++){
            cin>>exp[i][j];
        } 
    }
    list = Answer(arr,n,m);
    ans* current = list.pHead;
    int k = 0;
    while(k != kol){
        while (current) {
            ASSERT_EQ(exp[k][0], current->value);
            ASSERT_EQ(exp[k][1],current->x);
            ASSERT_EQ(exp[k][2],current->y);
            k++;
            current = current->pNext;
        }
    }
    for (int i = 0; i < kol; i++) {
		list.delete_Last();
	}
    for (int i = 0; i < kol; i++) {
		delete[] exp[i];
	}
	delete[] exp;
}

int main(int argc, char ** argv){
    std::cout<<"Hello, gtest"<<std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}