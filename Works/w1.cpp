#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string posl(int now){
    setlocale(LC_ALL, "Russian");
    int cont;
    cin>>cont;
    string s = "";
    bool flg;
    while(now != 'x'){
        cin>>now;
        s += now;
        if(cont <= now){
            cont = now;
            flg = true;
        }
        else{
            s += " возрастающая, убывающая";
            return s;
        }
        if(cont >= now){
            cont = now;
            flg = false;
        }
        else{
            s += " убывающая, возрастающая";
            return s;
        }
    }
    if(flg == true){
            return s+=" возрастающая";
        }
    else{
        return s+=" убывающая";
    }
}