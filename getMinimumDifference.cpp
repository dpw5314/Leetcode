#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<sstream>
#include<math.h>
#include<climits>
#include<stack>
#include <sstream>
#include <unordered_map>


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

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
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


 //97
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findMax(TreeNode* & root){
        if(root->right)
            return findMax(root->right);
        else
            return root->val;
    }
    int findMin(TreeNode* & root){
        if(root->left)
            return findMin(root->left);
        else
            return root->val;
    }
    
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> stk;
        int ans = INT_MAX;
        if(!root)
            return 0;

        while(!stk.empty() || root){
            if(root == nullptr){
                if(!stk.empty()){
                    //cout<<stk.top()->val<<endl;
                    root = stk.top();
                    stk.pop();
                }
            }
            else{
                if(root->left){
                    int temp = findMax(root->left);
                    if(root->val - temp < ans)
                        ans = root->val - temp;
                    //cout<<root->val<<": leftMax -> "<<temp<<endl;
                }
                if(root->right){
                    int temp = findMin(root->right);
                    if(temp - root->val < ans)
                        ans = temp - root->val;  
                    stk.push(root->right);
                    //cout<<root->val<<": rightMin -> "<<temp<<endl;
                }
                root = root->left;
            }
        }
        return ans;
    }
};

int main(){
	vector<string> string = {"3","-4","+"};
	//{"15", "7", "1", "1", "+", "−", "÷", "3", "×", "2", "1", "1", "+", "+" ,"−"};
	//{"2", "1", "+", "3", "*"};
	Solution *b = new Solution();
	int ans = b->evalRPN(string);

	cout<<ans;
	cout<<endl;

	return EXIT_SUCCESS;
}