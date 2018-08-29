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


    void Valid(TreeNode* root, bool& ans, long long upper, long long lower){
    	cout<<root->val<<" ";
   		cout<<upper<<" "<<lower<<endl;
   		
        if(!root) return;
        else if(!root->left and !root->right) return;
        else if (!root->left){
            ans = (root->right->val <= root->val or root->right->val >= upper)?0:1;
        }
        else if (!root->right){
            ans = (root->left->val >= root->val or root->left->val <= lower)?0:1;
        }
        else if(root->left->val >= root->val or root->left->val <= lower
                or root->right->val <= root->val or root->right->val >= upper){
        
            ans = 0;
            return;
        }


        if(ans and root->left) {
            int temupper = (root->val < upper) ? root->val:upper;
            Valid(root->left,ans, temupper, lower);
        }
        if(ans and root->right) {
            int temlower = (root->val > lower) ? root->val:lower;
            Valid(root->right, ans, upper, temlower );
        }
        
        
        return;
    }

    bool isValidBST(TreeNode* root) {
        bool ans = 1;
        if(!root) return ans;
        else Valid(root, ans, LLONG_MAX,LLONG_MIN);
        return ans;
    }



int main(){
	vector<int> a = {INT_MIN, NULL, INT_MAX};
	//{3,NULL,30,10,NULL,NULL,15,NULL,45};
	//{2,1,3};
	//{3,NULL,30,10,NULL,NULL,15,NULL,45};
	TreeNode* root = new TreeNode(a[0]);
	root->left = NULL;
	root->right = new TreeNode(a[2]);
	/*
	root->right->left = new TreeNode(a[3]);
	root->right->right = NULL;
	root->right->left->left = NULL;
	root->right->left->right = new TreeNode(a[6]);
	root->right->left->right->left = NULL;
	root->right->left->right->right = new TreeNode(a[8]);*/
	
	bool ans = isValidBST(root);
	cout<<ans<<endl;

	return EXIT_SUCCESS;
}