#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct Polinom {
    int degree;
    int length;
    int* pol;
    void Reverse(int* A, int n) {
        int *k = new int[n];
        for (int j = 0; j <= n; j++) {
            k[j] = A[j];
        }
        for (int i = 0, j = n; i <= n; ++i, --j) {
            A[j] = k[i];
        }
        delete []k;
    }
    void Coeff(int* A, string n) {
        istringstream is(n);
        int num;
        while (is >> num){
            for (int j = 0; j < stoi(n); j++) {
            cout << "Введите коэффициенты (в том числе нулевые): ";
            cin >> A[j];
            }
        }
    }
};
int Max(Polinom A, Polinom B) {
    if (A.degree > B.degree) return A.degree;
    else if (A.degree == B.degree) return A.degree;
    else return B.degree;
}
Polinom Addition(Polinom A, Polinom B) {
    Polinom Summa;
    Summa.degree = Max(A, B);
    Summa.length = Summa.degree + 1;
    Summa.pol = new int[Summa.length];
    for (int i = 0; i < Summa.length; i++) {
        Summa.pol[i] = 0;
    }
    if (A.degree < B.degree) {
        int min = A.length;
        int* fix = new int[min];
        for (int i = 0; i < min; i++) {
            fix[i] = A.pol[i];
        }
        A.degree = Summa.degree;
        A.length = Summa.length;
        delete[]A.pol;
        A.pol = new int[A.length];
        for (int i = 0; i < A.length; i++) {
            A.pol[i] = 0;
        }
        for (int i = 0; i < min; i++) {
            A.pol[i] = fix[i];
        }
        delete []fix;
    }
    if (A.degree > B.degree) {
        int min = B.length;
        int* fix = new int[min];
        for (int i = 0; i < min; i++) {
            fix[i] = B.pol[i];
        }
        B.degree = Summa.degree;
        B.length = Summa.length;
        delete[]B.pol;
        B.pol = new int[B.length];
        for (int i = 0; i < B.length; i++) {
            B.pol[i] = 0;
        }
        for (int i = 0; i < min; i++) {
            B.pol[i] = fix[i];
        }
        delete []fix;
    }
    for (int i = 0; i < Summa.length; i++) {
        Summa.pol[i] = A.pol[i] + B.pol[i];
    }
    return Summa;
}
Polinom Multiplication(Polinom A, Polinom B){
    Polinom Proizv, helper;
    Proizv.degree = 1;
    Proizv.length = 2;
    Proizv.pol = new int[2];
    for (int i = 0; i < 2; i++) {
        Proizv.pol[i] = 0;
    }
    A.Reverse(A.pol, A.degree);
    for(int i = 0; i < A.length; i++){
        helper.degree = B.length+i-1;
        helper.length = B.length+i;
        helper.pol = new int[B.length+i];
        for(int k = 0; k < i; k++){
            helper.pol[k] = 0;
        }
        for(int j = 0; j < B.length; j++){
            helper.pol[j+i] = A.pol[i]*B.pol[j];
        }
        Proizv = Addition(Proizv, helper);
        delete []helper.pol;
    }
    Proizv.Reverse(Proizv.pol, Proizv.degree);
    return Proizv;
}






int main() {





    setlocale(LC_ALL, "Russian");
    int n;
    char x;
    string s;
    Polinom Summa, Proizv;
    Summa.degree = 1;
    Summa.length = 2;
    Summa.pol = new int[2];
    for (int i = 0; i < 2; i++) {
        Summa.pol[i] = 0;
    }
    Proizv.degree = 0;
    Proizv.length = 1;
    Proizv.pol = new int[1];
    Proizv.pol[0] = 1;
    cout << "Введите количество полиномов: " << endl;
    cin >> n;
    Polinom* A = new Polinom[n];
    for (int i = 0; i < n; i++) {
        cout << "Проинициализируем полиномы! " << endl;
        cout << "Введите степень полинома: " << endl;
        cin >> A[i].degree;
        A[i].length = A[i].degree + 1;
        A[i].pol = new int[A[i].length];
        cout << "А теперь коэффициенты!" << endl;
        s = to_string(A[i].length);
        A[i].Coeff(A[i].pol, s);
        A[i].Reverse(A[i].pol, A[i].degree);
    }
    if (n == 1) {
        cout << "Пpосто полином..." << endl;
        return 0;
    }
    cout << "А теперь операцию + или *: " << endl;
    cin >> x;
    switch (x) {
    case '+':
        for (int k = 0; k < n; k++) Summa = Addition(Summa, A[k]);
        Summa.Reverse(Summa.pol, Summa.degree);
        for (int i = 0; i < Summa.length; i++) cout << Summa.pol[i] << " ";
        break;
    case '*':
        for (int k = 0; k < n; k++) Proizv = Multiplication(Proizv, A[k]);
        for (int i = 0; i < Proizv.length; i++) 
            cout << Proizv.pol[i] << " ";
        break;
    }

    delete []Summa.pol;
    delete []Proizv.pol;
    for(int i =0; i < n; i++){
        delete []A[i].pol;
    }
    delete[]A;
    return 0;
}