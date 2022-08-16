#include <iostream>
#include <string>
using namespace std;

class Desk {
/*

	TOOLS

*/
};
class Figure : public Desk {
private:
	void createArrPoints(int n) {
		points = new int* [n];
		for (int i = 0; i < n; i++) {
			points[i] = new int[2];
		}
		getCoord(points, n);
	}
protected:
    void getColAndPoints() {
		cout << "Vvedite cvet!" << endl;
        cin >> color;
		createArrPoints(n);
	}
private:
    void getCoord(int** arr, int n) {
		cout << "Vvedite coordinati vershin!" << endl;
		for (int i = 0; i < n; i++) {
			cout << "Point: " << endl;
			for (int j = 0; j < 2; j++) {
				cin >> arr[i][j];
			}
		}
	}
protected:
    int** points;
public:
    int n;
    string color;
    virtual void Draw() = 0;
};
class Point: public Figure{
public:
    Point(int n){
        this->n = n;
        getColAndPoints();
    }
    virtual void Draw(){
        cout<<color<<" point is created in: "<<endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                cout<<points[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
class Line: public Figure{
public:
    Line(int n){
        this->n = n;
        getColAndPoints();
    }
    virtual void Draw(){
        cout<<color<<" line is created in: "<<endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                cout<<points[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
class Triangle: public Figure{
public:
    Triangle(int n){
        this->n = n;
        getColAndPoints();
    }
    virtual void Draw(){
        cout<<color<<" triangle is created in: "<<endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                cout<<points[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
class Polygon: public Figure{
public:
    Polygon(int n){
        this->n = n;
        getColAndPoints();
    }
    virtual void Draw(){
        cout<<color<<" polygon is created in: "<<endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                cout<<points[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main() {
	Figure* p;
    int n;
    cout<<"Vvedite colichestvo vershin"<<endl;
    cin>>n;
    if(n == 1){
        p = new Point(n);
        p->Draw();
    }
    else if(n == 2){
        p = new Line(n);
        p->Draw();
    }
    else if(n == 3){
        p = new Triangle(n);
        p->Draw();
    }
    else if(n >= 4){
        p = new Polygon(n);
        p->Draw();
    }
    else{
        cout<<"Error"<<endl;
    }
	return 0;
}