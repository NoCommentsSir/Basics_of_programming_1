#include <iostream>
using namespace std;
template <typename T>
T findmax (T* Arr, int n){
    T max = Arr[0];
    for(int i = 0; i < n; i++){
        if(Arr[i] > max) max = Arr[i];
    }
    return max;
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    cout<<findmax(a, 5)<<endl;
    float b[5] = {1.1, 2.2, 3.1, 4.0, 5.1};
    cout<<findmax(b, 5)<<endl;;
    return 0;
}