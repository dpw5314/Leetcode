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
const int size =9;

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

   struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

    void searching(vector<vector<char>>& board, string& word, int stringindex, int indexi, int indexj, bool& ans){
        if(stringindex == word.size() - 1) {
            ans = 1;
            return;
        }
        char temp = board[indexi][indexj];
        board[indexi][indexj] = '.';
        
        if(indexi-1 >=0 && board[indexi-1][indexj] == word[stringindex+1]) 
            searching(board, word, stringindex+1, indexi-1, indexj, ans);
        if(indexi+1 < board.size() && board[indexi+1][indexj] == word[stringindex+1]) 
            searching(board, word, stringindex+1, indexi+1, indexj, ans);
        if(indexj-1 >=0 && board[indexi][indexj-1] == word[stringindex+1]) 
            searching(board, word, stringindex+1, indexi, indexj-1, ans);
        if(indexj+1 < board[0].size() && board[indexi][indexj+1] == word[stringindex+1]) 
            searching(board, word, stringindex+1, indexi, indexj+1, ans);
        
        if(!ans) board[indexi][indexj] = temp;
        return;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ans = 0;
        int size = board.size(), size1 = board[0].size();
            for(int i = 0; i<size ;++i){
                for(int j = 0; j<size1; ++j){
                    if(ans) return ans;
                    if(word[0] == board[i][j]) searching(board, word, 0, i, j, ans);
                }
            }
        return ans;
    }

int main(){
	vector<vector<char>> a = {{'A','B','C','E'},
							  {'S','F','C','S'},
							  {'A','D','E','E'}};
	string target = "SEED";
							
	bool ans;
	
	ans = exist(a, target);
	cout<<ans<<endl;
	PrintItvector(a);

	return EXIT_SUCCESS;
}