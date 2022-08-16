#include <iostream>
using namespace std;
struct Way {
    int field;           
    struct Way* left_way;  
    struct Way* right_way;
    struct Way* addway(int x, struct Way* tree) {
        if (tree == NULL) { 
            tree =new Way; 
            tree->field = x;   
            tree->left_way =  NULL;
            tree->right_way = NULL; 
        }
        else  if(x%2 == 0)
            tree->left_way = addway(x,tree->left_way);
        else if(x%2 != 0) 
            tree->right_way = addway(x,tree->right_way);
        return(tree);
    }   
};
int main(){
    Way *Chess;
    int n, m;
    cin>>n>>m;
    int** chessboard = new int* [n];
	for (int i = 0; i < n; i++) {
		chessboard[i] = new int[m];
	}
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            chessboard[i][j] = chessboard[i][j-1] + 1;
            if(i != 0){
                if(j == 0){
                    chessboard[i][j] = chessboard[i-1][m-1] + 1;
                }
            }
        }
    }
    Chess->addway(chessboard[2][3], Chess);
    cout<<Chess->field;
    return 0;
}