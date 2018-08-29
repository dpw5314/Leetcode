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

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    void compare(TreeNode* p, TreeNode* q, bool& ans){
        if(!p and !q) return;
        else if(!p or !q) {ans = 0; return;}
        else if(p->val != q->val){ans = 0; return;}
        
        if(ans) compare(p->left, q->left, ans); // compare left
        
        if(ans)  compare(p->right, q->right, ans); //compare right

        return;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = 1;
        
        
        compare(p,q, ans);
        return ans;
    }
    


int main(){
	vector<vector<int>> input = {{1,3,1}, {1,5,1}, {4,2,1}};
	//{{0,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,0}};
	//{{1,1}};
	//{{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
	//{{1}};
	//{{0,0,0}, {0,1,0}, {0,0,0}};
	int ans;
	ans = minPathSum(input);
	cout<<ans;
	return EXIT_SUCCESS;
}