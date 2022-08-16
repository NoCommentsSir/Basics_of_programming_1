#include <iostream>
#include <string>
using namespace std;
struct Polinom{
	int degree;
    int *pol;
    void Reverse(int *A, int n){
        int k[n];
        for(int j = 0; j <= n; j++){
            k[j] = A[j];
        }
        for(int i=0, j=n; i<=n; ++i, --j){
            A[j] = k[i];
        }
    }
};
void Coeff(int *A, int n){
    for(int j = 0; j <= n; j++){
        cout<<"Введите коэффициенты (в том числе нулевые): ";
        cin>>A[j];
    }
}
Polinom Max(Polinom A, Polinom B){
    if(A.degree > B.degree)return A;
    else return B;
}
Polinom Min(Polinom A, Polinom B){
    if(A.degree < B.degree)return A;
    else return B;
}
Polinom dobav(int *A, int k, int degree){
    Polinom B;
    B.degree = degree+1+k;
    B.pol = new int[B.degree];
    for(int i = 0; i < B.degree; i++){
        B.pol[i] = 0;
    }
    for(int i = 0; i < degree+1; i++){
        B.pol[i] = A[i];
    }
    B.Reverse(B.pol,B.degree);
    return B;
}
Polinom Addition(Polinom A, Polinom B){
    Polinom Summa, fix;
    Polinom max = Max(A, B);
    Polinom min = Min(A, B);
    Summa.degree = max.degree;
    Summa.pol = new int[Summa.degree];
    for(int i = 0; i <= max.degree; i++){
        Summa.pol[i] = 0;
    }
    if(Min(A,B).degree < max.degree){
        int a = Min(A,B).degree;
        fix = Min(A,B);
        int *p = new int[fix.degree];
        for(int k = 0; k <= fix.degree; k++){
            p[k] = Min(A,B).pol[k];
        }
        fix.degree = max.degree;
        fix.pol = new int [fix.degree];
        for(int j = 0; j <= fix.degree; j++){
            fix.pol[j] = 0;
        }
        for(int j = 0; j <= a; j++){
            fix.pol[j] = p[j];
        }
    }
    for(int j = max.degree; j >= 0; j--){
        Summa.pol[j] = fix.pol[j]+Max(A,B).pol[j];
    }
    Summa.Reverse(Summa.pol, Summa.degree);
    return Summa;
}

Polinom Multiplication(Polinom *A, int n){
    Polinom Proizv, max, min;
    int maxdegree = 1;
    Proizv.degree = -1;
    for(int i = 0; i < n; i++){
        Proizv.degree += A[i].degree;
        A[i].Reverse(A[i].pol, A[i].degree);
    }
    Proizv.pol = new int[Proizv.degree];
    for(int i = 0; i < n-1; i++){
        int count = 1;
        max = Max(A[i], A[i+1]);
        min = Min(A[i], A[i+1]);
        for(int j = 0; j <= min.degree; j++){
            int *helper = new int[max.degree];
            for(int k = 0; k <= max.degree; k++){
                helper[k] = max.pol[k]*min.pol[j];
                int *fixic = new int[max.degree];
                fixic = dobav(helper, 0, max.degree).pol;
                for(int h = 1; h <= min.degree; h++){
                    dobav(helper, count, max.degree);
                    count++;
                }
            }
            delete []helper;
        }
    }
    return Proizv;
}

int main(){
    setlocale(LC_ALL, "Russian");
    int quantity;
    char x;
    Polinom Summ;
    Summ.degree = 1;
    Summ.pol = new int[Summ.degree];
    Summ.pol = {0};
    cout<<"Привет. Сколько полиномов? "<<endl;
    cin>>quantity;
    Polinom *A = new Polinom[quantity]; 
    for(int i = 0; i < quantity;i++){
        cout<<"Определим полиномы! \n Введите степень полинома: "<<endl;
        cin>>A[i].degree;
        A[i].pol = new int[A[i].degree];
        cout<<"А теперь коэффициенты! "<<endl;
        Coeff(A[i].pol, A[i].degree);
        A[i].Reverse(A[i].pol, A[i].degree);
    }
    if(quantity == 1){
        cout<<"ПРосто полином..."<<endl;
        return 0;
    }
    cout<<"А теперь операцию + или *: "<<endl;
    cin>>x;
    switch(x){
        case '+':
            for(int n = 0; n < quantity; n++){
                Summ = Addition(Summ,A[n]);
            }
            for(int i = 0; i <= Summ.degree; i++){
                cout<<Summ.pol[i]<<" ";
            }
        case '*':
            cout<<"gtjgijt";
            break;
    }
    delete []A;
	return 0;
}