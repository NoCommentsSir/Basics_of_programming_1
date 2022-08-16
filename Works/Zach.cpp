#include <iostream>
#include <string>
using namespace std;
struct ans {
    int value;
    int x;
    int y;
    ans *pNext;
    ans(int value, int x, int y) {
        this->value = value;
        this->x = x;
        this->y = y;
        this->pNext = nullptr;
    }
};
struct List {
    ans* pHead = nullptr;
    void add(int value, int x, int y) {
        if (!pHead) {
            pHead = new ans(value, x, y);
        }
        else {
            ans* lastone = pHead;
            while (lastone->pNext) {
                lastone = lastone->pNext;
            }
            lastone->pNext = new ans(value, x, y);
        }
    }
    void delete_Last() {
        ans* current = pHead;
        while (current->pNext->pNext) {
            current = current->pNext;
        }
        delete current->pNext;
        current->pNext = nullptr;
    }
};
void add(int** arr, int n, int m) {
	cout << "VVod znachenii" << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int value;
			cin >> value;
			arr[i][j] = value;
		}
	}
}
void deletef(int** arr, int n, int m){
    for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
void print(int** arr, int n, int m) {
    string s = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<<arr[i][j]<<" ";
		}
	}
}
int checkborder(int** arr, int n, int m, int x, int y) {
	if (x == 0) {
		if (y == 0) return 0;
		else if (y == m - 1) return 1;
		else return 4;
	}
	else if (x == n-1) {
		if (y == 0) return 2;
		if (y == m - 1) return 3;
		else return 5;
	}
	else {
		if (y == 0) return 6;
		if (y == m - 1) return 7;
	}
	return -1;
}
bool check(int** arr, int n, int m, int x, int y, int a) {
	if(a == 0){
		if (arr[x + 1][y] > arr[x][y] && arr[x][y + 1] > arr[x][y] && arr[x + 1][y + 1] > arr[x][y]) {
			return true;
		}
	}
	if (a == 1){
		if (arr[x][y - 1] > arr[x][y] && arr[x + 1][y] > arr[x][y] && arr[x + 1][y - 1] > arr[x][y]) {
			return true;
		}
	}
	if(a == 4){
		if (arr[x][y - 1] > arr[x][y] && arr[x + 1][y] > arr[x][y] && arr[x + 1][y - 1] > arr[x][y] && arr[x + 1][y + 1] > arr[x][y] && arr[x][y + 1] > arr[x][y]) {
			return true;
		}
	}
	if (a == 2) {
		if (arr[x - 1][y] > arr[x][y] && arr[x][y + 1] > arr[x][y] && arr[x - 1][y + 1] > arr[x][y]) {
			return true;
		}
	}
	if (a == 3){
		if (arr[x][y - 1] > arr[x][y] && arr[x - 1][y] > arr[x][y] && arr[x - 1][y - 1] > arr[x][y]) {
			return true;
		}
	}
	if(a == 5){
		if (arr[x][y - 1] > arr[x][y] && arr[x - 1][y] > arr[x][y] && arr[x - 1][y - 1] > arr[x][y] && arr[x - 1][y + 1] > arr[x][y] && arr[x][y + 1] > arr[x][y]) {
			return true;
		}
	}
	if (a == 6) {
		if (arr[x - 1][y] > arr[x][y] && arr[x][y + 1] > arr[x][y] && arr[x - 1][y + 1] > arr[x][y] && arr[x + 1][y + 1] > arr[x][y] && arr[x + 1][y] > arr[x][y]) {
			return true;
		}
	}
	if (a == 7) {
		if (arr[x][y - 1] > arr[x][y] && arr[x - 1][y] > arr[x][y] && arr[x - 1][y - 1] > arr[x][y] && arr[x + 1][y - 1] > arr[x][y] && arr[x + 1][y] > arr[x][y]) {
			return true;
		}
	}
	if(a == -1){
		if (arr[x][y - 1] > arr[x][y] && arr[x - 1][y] > arr[x][y] && arr[x - 1][y - 1] > arr[x][y] && arr[x + 1][y - 1] > arr[x][y] && arr[x + 1][y] > arr[x][y] && arr[x - 1][y + 1] > arr[x][y]
		&& arr[x][y + 1] > arr[x][y] && arr[x + 1][y + 1] > arr[x][y]) {
			return true;
		}
	}
	return false;
}
List Answer(int**arr, int n, int m){
    List list;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a = checkborder(arr, n, m, i, j);
			if (check(arr, n, m, i, j, a) == true) {
				cout << arr[i][j] << ": (" << i+1 << "," << j+1 << ");" << endl;
                list.add(arr[i][j], i+1, j+1);
			}
		}
	}
	print(arr, n, m);
	deletef(arr, n, m);
	return list;
}