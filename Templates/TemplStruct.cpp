#include <iostream>
using namespace std;
struct Compl{
    double Re;
    double Im;
    Compl(double Re, double Im){
        this->Re = Re;
        this->Im = Im;
    }
    Compl(): Compl(0,0)
    {}
    
};
ostream& operator << (ostream& out, const Compl& z){
    out << "(" << z.Re << ", " << z.Im << ")";
    return out;
}
template <typename T>
struct Matrix{
    T**data;
    int rows;
    int cols;
    Matrix(int rows, int cols){
        this->rows = rows;
        this->cols = cols;
        data = new T*[rows];
        for(int i = 0; i < rows; i++){
            data[i] = new T[cols];
        }
    }
    void print(){
        cout<<"Matrix"<<endl;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
};
static Matrix<int>* ones(int rows, int cols){
    Matrix<int>*m = new Matrix<int>(rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m->data[i][j] = 1;
        }       
    }
    return m;
}
int main(){
    Matrix<int>*m = ones(5,5);
    m->print();
    Matrix<Compl> z(5,5);
    cout<<endl;
    z.print();
    return 0;
}