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
			if(a[i][j] > INT_MIN) cout<<a[i][j]<<" ";
			else cout<<"NULL"<<" ";
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

 /*
   ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
*/

  /*
    int combination (int a, int b){
      if(b == 1) return a;
      else if (b == 0) return 1;
      int max = b > a-b ? b : a-b;
      long sum1 = 1;
      int sum2 = 1;
      for(int i = max+1; i<a; ++i){
        sum1 *= i;
      }
      for(int i = 1; i< a-max; ++i){
        sum2 *= i;
      }

      return sum1/sum2;
    }
*/

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void go(vector<vector<char>>& board, int I1, int I2){
        int s1 = board.size(), s2 = board[0].size();
        board[I1][I2] = '#';
        if(I1-1 >= 0 and board[I1-1][I2] == 'O')
            go(board,I1-1, I2);
        if(I1+1 < s1 and board[I1+1][I2] == 'O')
            go(board,I1+1, I2);      
        if(I2-1 >= 0 and board[I1][I2-1] == 'O' )
            go(board, I1, I2-1);
        if(I2+1 < s2 and board[I1][I2+1] == 'O')
            go(board,I1, I2+1);
    
        return;
    
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        else{
            if(board[0].size() == 0)
                return;
            else if(board[0].size() == 2 or board.size()==2)
            	return;
        }
        int s1 = board.size(), s2 = board[0].size();
        for(int i = 0; i<s2;++i){
        	if(board[0][i] == 'O') go(board, 0, i);
        }
        for(int i = 0; i<s2;++i){
        	if(board[s1-1][i] == 'O') go(board, s1-1, i);
        }
        for(int i = 1; i<s1-1; ++i){
        	if(board[i][0] == 'O') go(board, i, 0);
        }
        for(int i = 1; i<s1-1; ++i){
        	if(board[i][s2-1] == 'O') go(board, i, s2-1);
        }
        for(int i = 0; i<s1; ++i){
        	for(int j =0; j<s2; ++j){
        		if(board[i][j] == 'O') board[i][j] = 'X';
        		else if (board[i][j] == '#') board[i][j] = 'O';
        	}
        }
        return;
    }
};

    void Order (vector<vector<int>>& ans, int layer, TreeNode* root){
        if(root == nullptr) return;
        else{
            if(layer == ans.size()){
                vector<int> temp;
                ans.push_back(temp);
                ans[layer].push_back(root->val);
            }
            else ans[layer].push_back(root->val);
            
        }
        
        if(root->left) Order(ans, layer+1, root->left);
        if(!root->left and root->right){
            vector<int> temp;
            ans.push_back(temp);
            ans[layer+1].push_back(INT_MIN);
        }
        if(root->right) Order(ans, layer+1, root->right);
        
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        Order(ans, 0, root);
        return ans;
    }

int main(){
	vector<vector<char>> board ={{'O','O'},{'O','O'}};
	/*
								{{'X','X','X','X'}, 
						  		{'X','O','O','X'}, 
						  		{'X','X','O','X'},
						  		{'X','O','X','X'}};*/
	Solution* a = new Solution();
	a->solve(board);
	PrintItvector(board);

	return EXIT_SUCCESS;
}