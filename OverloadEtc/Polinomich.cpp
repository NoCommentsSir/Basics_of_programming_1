#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct Polinom {
    int degree;
    int length;
    int* pol;
    Polinom(int pdeg, int plen) {
        this->degree = pdeg;
        this->length = plen;
        this->pol = new int[plen];
    }
    Polinom(const Polinom& p) {
        degree = p.degree;
        length = p.length;
        pol = new int[p.length];
        pol = p.pol;
    }
    Polinom() {
        this->degree = 1;
        this->length = 2;
        this->pol = new int[2];
        for (int i = 0; i < 2; i++) {
            this->pol[i] = 0;
        }
    }
    ~Polinom() {
        if (!pol) {
            delete[]pol;
        }
    }
    void Reverse(int* A, int n) {
        int* k = new int[n+1];
        for (int j = 0; j <= n; j++) {
            k[j] = A[j];
        }
        for (int i = 0, j = n; i <= n; ++i, --j) {
            A[j] = k[i];
        }
        delete[]k;
    }
};
Polinom getPolinom() {
    int n;
    cout << "Введите степень полинома: " << endl;
    cin >> n;
    int l = n + 1;
    Polinom p(n, l);
    for (int j = 0; j < l; j++) {
        cout << "Введите коэффициенты (в том числе нулевые): ";
        cin >> p.pol[j];
    }
    return p;
}
ostream& operator << (ostream& out, const Polinom& p) {
    for (int i = 0; i < p.length; i++) {
        if (p.pol[i] == 0) continue;
        if (i != p.length - 1)
            out << p.pol[i] << "" << "x^" << p.length -1 - i << "+";
        else
            out << p.pol[i];
    }
    return out;
}
Polinom operator + (const Polinom& A, const Polinom& B) {
    int n = (A.degree > B.degree) ? A.degree : B.degree;
    Polinom Summa(n, n + 1);
    for(int i = 0; i < Summa.length; i++)Summa.pol[i] = 0;
    for (int i = Summa.degree; i >= 0; i--) {
        if (A.length > i) Summa.pol[i] += A.pol[i];
        if (B.length > i) Summa.pol[i] += B.pol[i];
    }
    return Summa;
}
Polinom operator * (const Polinom& A, const Polinom& B) {
    Polinom Proizv;
    for (int i = 0; i < A.length; i++) {
        Polinom helper(B.length + i - 1, B.length + i);
        for (int k = 0; k < i; k++) {
            helper.pol[k] = 0;
        }
        for (int j = 0; j < B.length; j++) {
            helper.pol[j + i] = A.pol[i] * B.pol[j];
        }
        Proizv = Proizv + helper;
    }
    return Proizv;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    char x;
    Polinom Summa;
    Polinom Proizv(0, 1);
    Proizv.pol[0] = 1;
    cout << "Введите количество полиномов: " << endl;
    cin >> n;
    cout << "А теперь операцию + или *: " << endl;
    cin >> x;
    switch (x) {
    case '+':
        if (n != 1) {
            for (int i = 0; i < n; i++) {
                cout << "Инициализация полиномов" << endl;
                Polinom p = getPolinom();
                p.Reverse(p.pol, p.degree);
                Summa = Summa + p;
            }
        }
        else {
            cout << "Пpосто полином..." << endl;
            return 0;
        }
        Summa.Reverse(Summa.pol, Summa.degree);
        cout << Summa;
        break;
    case '*':
        if (n != 1) {
            for (int i = 0; i < n; i++) {
                cout << "Инициализация полиномов" << endl;
                Polinom p = getPolinom();
                p.Reverse(p.pol, p.degree);
                Proizv = p * Proizv;
            }
        }
        else {
            cout << "Пpосто полином..." << endl;
            return 0;
        }
        Proizv.Reverse(Proizv.pol, Proizv.degree);
        cout << Proizv;
        break;
    }
    return 0;
}