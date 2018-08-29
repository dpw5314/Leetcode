#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int size =9;

template<typename T>
void PrintItvector(vector<vector<T> >& a){
	for(int i = 0; i < a.size(); i++){
		for(int j=0; j<a[0].size(); j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


template<typename T>
void PrintIt(T (&a)[size][size], int size){
	for(int i = 0; i < size; i++){
		for(int j=0; j<size; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
    
bool isValidSudoku(vector<vector<char> >& board, int row, int col) {
    char value = board[row][col];
    int intval = value - '0';
    if(intval>9 || intval < 1) {return false;}
    for(int i = 0; i < 9; i++){
        if(i != row && board[i][col] == value) { return false;}
        if(i != col && board[row][i] == value) { return false;}
    }
        
	int irow0 = row/3*3;
    int icol0 = col/3*3;
    for(int i=irow0; i<irow0+3; i++) {
        for(int j=icol0; j<icol0+3; j++) {
            if(board[i][j]==value && (i!=row || j!=col)) { return false;}
        }
    }
    return true;
}


bool dfs (vector<vector<char> >& board, int row, int col) {
    if(row == 9) return true;
    int row1, col1;
        
    if(col == 8) {row1 = row+1; col1 = 0;}
    else {row1 = row; col1 = col+1;}
        
    if(board[row][col] != '.'){
        if(!(isValidSudoku(board, row, col))) return false;
        return dfs(board, row1, col1);
    }
    
    for(int i = 0; i <= 9; i++){
    	board[row][col] = i+'0';
        if(isValidSudoku(board, row, col) && dfs(board, row1, col1)) {return true;}
    }
        
    board[row][col] = '.';
    return false;
}

void solveSudoku(vector<vector<char> >& board) {
    if(board.size()<9 || board[0].size()<9) return;
    bool ans = dfs(board, 0, 0);
}

int main(){
	char c[][10]= {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
	vector<vector<char> > board;
	vector<char> temp;
	for(int i =0; i<(sizeof(c)/sizeof(c[0])); i++){
		for(int j =0; j<(sizeof(c[0])); j++){
		temp.push_back(c[i][j]);
		}
		board.push_back(temp);
		temp.clear();
	}
	int check[9][9], check1[9][9], check2[9][9];
        memset(check, 0, sizeof(check)); memset(check1, 0, sizeof(check1)); memset(check2, 0, sizeof(check2));
	
	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[0].size(); j++){
			if(board[i][j] != '.'){
				int num = board[i][j] - '0' - 1, k = i/3 * 3 + j/3;
				check[i][num] = check1[j][num] = check2[k][num] = 1;
			}
		}
	}
	
	solveSudoku(board);
	
    //PrintIt(check, size); PrintIt(check1, size); PrintIt(check2, size);
	PrintItvector(board);
	return 0;
} 
