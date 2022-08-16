#include <iostream>
#include <stdlib.h>
#include<string.h>
using namespace std;
void success(char **B, int stolb, int strok){
    B[strok-1][stolb-1] = '@';
    char **A = new char* [4];
    A[0] = & B[strok+1][stolb];
    A[1] = & B[strok-1][stolb];
    A[2] = & B[strok][stolb+1];
    A[3] = & B[strok][stolb-1];
    for(int i = 0;i<4;i++){
        cout<<"My turn is ("<<A[rand()%4]<<")"<<endl;
                                            
    }
    delete [] A;
}
int main(){
    int n, m;
    string check, checKill;
    cin>>n>>m;
    char **B = new char*[m];
    for(int i = 0; i<m;i++){
        B[i] = new char[n];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            B[i][j] = '*';
        }
    }
    for(int i = 0;i<m;m++){
        for(int j = 0; j < n; n++){
            cout<<"My turn is ... ("<<rand()%(m)<<","<<rand()%(n)<<")"<<endl;
            cout<<"Is it success?"<<endl;
            cin>>check;
            if(check == "Yes"){

            }
            else if(check == "No"){

            }
            cout<<"Did I kill?"<<endl;
            cin>>checKill;
        }
    }
    
    return 0;
}

