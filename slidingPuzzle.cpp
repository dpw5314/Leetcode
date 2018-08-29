#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<sstream>
#include<math.h>
#include<climits>
#include <sstream>


using namespace std;
const int size = 9;


template<typename T>
void PrintItvector(vector<vector<T> >& a){
	for(int i = 0; i < a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

template<typename T>
void PrintItvector(vector<T>& a){
	for(int i = 0; i < a.size(); i++){
			cout<<a[i]<<" ";
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


string IntToString(int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

//52
class Solution {
public:
    unordered_map<string, bool> map;
    
    string goal = "123450";
    
    void insert(string cur, int col, int row, queue<string>&c, string direction){
        if(direction == "left")
            std::swap(cur[row*3+col], cur[row*3+col-1]);
        else if(direction == "right")
            std::swap(cur[row*3+col], cur[row*3+col+1]);
        else if(direction == "up")
            std::swap(cur[row*3+col], cur[(row-1)*3+col]);
        else if(direction == "down")
            std::swap(cur[row*3+col], cur[(row+1)*3+col]);
        
        if(map.find(cur) == map.end())
            c.push(cur);
            
    }
    int slidingPuzzle(vector<vector<int>>& board) {        
        string cur;
        int col, row;
        for(int i = 0; i<board.size(); ++i){
            for(int j = 0; j<board[i].size(); ++j){
                cur+=to_string(board[i][j]);
            }}
        queue<string> q;
        q.push(cur);
        int count = 0;
        while(!q.empty()){
            queue<string> c;
            while(!q.empty()){
                if(q.front() == goal)
                    return count;
                cur = q.front();
                q.pop();
                row = cur.find('0');
                col = row%3;
                row = row/3;                
                map[cur] = true;
                if(col-1 >= 0)
                    insert(cur, col, row, c, "left");
                if(col+1 < 3)
                    insert(cur, col, row, c, "right");
                if(row - 1 >= 0)
                    insert(cur, col, row, c, "up");
                if(row + 1 < 2)
                    insert(cur, col, row, c, "down");
            }
            count++;
            std::swap(q,c);
        }
        return -1;
    }
};

int main(){
	vector<int> vec = {2,1,1,2};
	//{3,5,7,0,1,2};
	//{3,1};
	Solution* a = new Solution();
	int ans = a->rob(vec);
    cout<<ans;
    delete a;
	return EXIT_SUCCESS;
}