#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int **B = new int*[m];
    for(int i = 0; i<m;i++){
        B[i] = new int[n];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                B[i][j] = 1;
            }
            else{
                B[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < m; i++){
        cout<<"\n";
        for(int j = 0; j < n; j++){
            cout<<B[i][j]<<" ";
        }
    }
    return 0;
}

