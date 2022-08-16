#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int A, B, n, X, N1, N2;
    cin>>A>>B>>n;
    X = (A+B)/2;
    N1 = abs(X - A);
    N2 = abs(X - B);
    if(A == X || B == X || A < X || B > X || n > N1 || n > N2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}