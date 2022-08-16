#include <iostream>
#include<string>
using namespace std;
void StrToInt(string a, int A[4]){
    string s = "";
    int c = 0;
    for(int i = 0;i<a.size();i++){
        if(a[i] == '.'){
           A[c] = stoi(s);
           c++;
           s = "";
        }
        else{
            s += a[i];
        }
    }
    A[c] = stoi(s);
}
bool CheckMask(int D[4]){
    bool warning;
    int c = 0;
    int j;
    for(int i = 0; i < 4; i++){
        if(D[i] >= 0 && D[i] <= 255){
            if(D[i] == 255){
                c++;
            }
            else{
                warning = true;
                for(int j = i+1;i<4;i++){
                    if(D[j]!=0){
                        return false;
                    }
                }
            }
        }
        else{
            return false;
        }
    }
    return warning;
}
bool IP(string a,string b, string d){
    bool flg = true;
    int A[4], B[4], D[4], E[4], F[4];
    StrToInt(a, A);
    StrToInt(b, B);
    StrToInt(d, D);
    if(CheckMask(D) == false){
        return false;
    }
    for(int i = 0; i < 4; i++){
        E[i] = A[i]&D[i];
    }
    for(int i = 0; i < 4; i++){
        F[i] = B[i]&D[i];
    }
    for(int i = 0; i < 4; i++){
        if(E[i]!=F[i]){
            flg = false;
            break;
        }
    }
    cout<<flg<<endl;
    return flg;
}