#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long a, b, S, count, n;
    cin>>a>>b;
    S = a*b;
    count = 0;
    (a<b)? n = a : n = b;
    while(n > 0){
        int P = n*n;
        if(S%P == 0){
            count = count + S/P;
            break;
        }
        else{
            int r = S - P;
                if(r > 0) {
                    count++;
                    S = S - P;
                }
                if(r > 0 && n == 1){
                    count = count + r;
                }
        }       
        n--;
    }
    cout<<count<<endl;
    return 0;
}