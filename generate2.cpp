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

class Solution {
public:
   	vector<int> getRow(int numRows) {
   		numRows += 1;
        vector<vector<int>> ans;
        vector<int> ans1;
        if (numRows == 1) {
          ans = {{1}};
          return ans[0];
        }
        ans = {{1},{1,1}};
        for(int i = 1; i< numRows-1; ++i){
            ans.push_back({1,1});
            for(int j = 0; j<ans[i].size()-1;++j){
                ans[i+1].insert(ans[i+1].begin()+j+1, ans[i][j] + ans[i][j+1]);
            }

        }
        return ans[ans.size()-1];
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
  int Row = 3;
	Solution* a = new Solution();
	vector<int> ans = a->getRow(Row);
	PrintItvector(ans);

	return EXIT_SUCCESS;
}