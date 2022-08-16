#include <iostream>
#include <cmath>
#include <string>
#include<gtest/gtest.h>
using namespace std;
bool posled(int cont, int now){
    if( cont <= now){
        return true;
    }
    else {
        return false;
    }
}
int sravn(bool previous, int container, int now){
    int rez;
    if (previous == posled(container, now)){
        if(posled(container, now) == true){
            rez = 2;
        }
        else{
            rez = 3;
        }
    }
    else if(previous != posled(container, now)){
        if(posled(container, now) == true){
            rez = 0;
        }
        else{
            rez = 1;
        }
    }
    return rez;
}
bool isNumber(string a){
    for(int i = 0; i < a.size();i++){
        if(a[i]-'0'>=0 && a[i]<=9){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int posl(){
    string cont, a;
    int container, now;
    int count = 0;
    int dop = 0;
    bool previous;
    int ans;
    cin>>cont;
    //if(isNumber(cont) == true){
    container = stoi(cont);
    //}
    //else return 1;
    while(count < 9){
        cin>>a;
        if(a == "x"){
            break;
        }
        if(now == stoi(a)){
            dop++;
        }
        //if(isNumber(a) == true){
        now = stoi(a);
        //}
        //else return 1;
        count++;
        if (count == 1){
            previous = posled(container, now);
            continue;
        }
        else if(count != 1){
            ans = sravn(previous, container, now);
            switch(ans){
                case 0:
                    cout<<"убвыающая, возрастающая"<<endl;
                    return 0;
                case 1:
                    cout<<"возрастающая, убывающая"<<endl;
                    return 1;
                case 2:
                    break;
                case 3:
                    break;
            }
        }
        container = now;
    }
    if(dop - count == -1){
        cout<<"Множество из одного элемента!!!"<<endl;
        return 4;
    }
    if(ans == 2){
        cout<<"возрастающая"<<endl;
        return 2;
    }
    else if(ans == 3){
        cout<<"убывающая"<<endl;
        return 3;
    }
    return 0;
}