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


 //99.91
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        while(!q.empty()){
            queue<TreeNode*> temp;
            for(; !q.empty(); q.pop()){
                TreeNode* tempTree = q.front();
                if(tempTree){
                    ans += to_string(tempTree->val) + " ";
                    temp.push(tempTree->left);
                    temp.push(tempTree->right);
                }
                else
                    ans += "# ";                
            }

            std::swap(temp, q);
        }
        //cout<<ans;
        return ans;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#" || data == "")
            return nullptr;
        else{
            stringstream ss(data);
            string tem;
            getline(ss,tem, ' ');
            TreeNode* root = new TreeNode(stoi(tem)); 
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                queue<TreeNode*> temp;
                for(; !q.empty(); q.pop()){
                    TreeNode* temTree = q.front();
                    if(temTree){
                        string left, right;
                        getline(ss, left,' '), getline(ss,right,' ');
                        temTree->left = (left == "#") ? nullptr : new TreeNode(stoi(left));
                        temTree->right = (right == "#") ? nullptr : new TreeNode(stoi(right));
                        temp.push(temTree->left), temp.push(temTree->right);
                    }
                }
                std::swap(temp, q);
            }
            return root;
        }        
    }
};
int main(){
	TreeNode* tree = new TreeNode(1);
	TreeNode* dummy = tree;
	dummy->left = new TreeNode(2);
	dummy->left->left = new TreeNode(3);
	Solution* a = new Solution();
	a->flatten(tree);
	vector<vector<int>> ans = levelOrder(tree);
	PrintItvector(ans);

	return EXIT_SUCCESS;
}