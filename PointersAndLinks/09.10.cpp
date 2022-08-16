#define _USE_MATH_DEFINES
#include <iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
int func(int x){
    cout<<"func("<<x<<")"<<endl;
    return x > 0 ? x : -x;
}
void doSmth(int x, int (externalFunc) (int)){
    externalFunc(x);
}
int main(){
    /*int x = -19;
    int (*p) (int)=func;
    cout<<"===========\n";
    cout<<"p:"<<p<<endl;
    cout<<"func(x): "<<func(x)<<endl;
    cout<<"p(x): "<<p(x)<<endl;
    cout<<"doSmth(x)"<<endl;
    doSmth(x,p);*/
    cout<<M_PI<<endl;
    //cout<<fixed<<showpoint;
    cout<<setprecision(200)<<M_PI<<endl;
    string s = "141592653589793115997963468544185161590576171875";
    cout<<s.size()<<endl;

}
/*
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int func(int x)
{
	cout << "func(" << x << ") is called"<<endl;
	return x > 0 ? x : -x;
}

void doSomething (int x, int (*externalFunction) (int)) {
	externalFunction(x);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int x = -19;
	int (*p) (int) = func;
	cout << p << endl;
	cout << p(x);
	cout << func(x);
	doSomething(x, p);
	int* px = &x;
	cout << px << endl;
	cout << &px<<endl;
	return 0;
}*/