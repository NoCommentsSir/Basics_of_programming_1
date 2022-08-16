#include <iostream>
#include <cmath>
using namespace std;
void QuickSort(int A[], int st, int fn){
    int left = st; int right = fn;
    if(st>=fn) return;
    int x, y;
    x = A[(right + left)/2];
    while(left<=right){
        while(A[left] < x) left++;
        while(A[right] > x) right--;
        if (left<=right){
            y = A[right]; A[right] = A[left]; A[left] = y;
            left++; right--;
        }
    }
    QuickSort(A, st, right);
    QuickSort(A, left, fn);
}
int mass(int a, int b, int c, int d, int e){
    int A[5];
    A[0] = a;
    A[1] = b;
    A[2] = c;
    A[3] = d;
    A[4] = e;
    QuickSort(A, 0, 4);
    if(A[0]<=A[1] && A[1]<=A[2] && A[2]<=A[3] && A[3]<=A[4]){
        return true;
    }
    else{
        return false;
    }
}