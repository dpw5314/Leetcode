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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> beginlist;
        unordered_set<string> endlist;
        unordered_set<string> rest;
        for(int i=0;i<wordList.size();i++) rest.insert(wordList[i]);
        if (rest.find(endWord) != rest.end()) {
            rest.erase(endWord);
        }else{
            return 0;
        }
        int depth = 2;
        beginlist.insert(beginWord);
        endlist.insert(endWord);
        while(!beginlist.empty() && !endlist.empty()){
            unordered_set<string> * pb;
            unordered_set<string> * pe;
            if (beginlist.size() < endlist.size()) {
                pb = &beginlist; 
                pe = &endlist; 
            } else {
                pe = &beginlist; 
                pb = &endlist; 
            }
            unordered_set<string> tmp;
            for(unordered_set<string>::iterator it = pb->begin();it!=pb->end();it++){
                string w = *it;
                for(int i=0;i<w.length();i++)
                {
                    char c = w[i];
                    for(int j=0;j<26;j++)
                    {
                        w[i] = 'a'+j;
                        if (w[i] == c) continue;
                        // printf("%s\n", w.c_str());
                        if (pe->find(w) != pe->end()) {
                            // printf("now find %s in pe.\n", w.c_str());
                            return depth;
                        }
                        if (rest.find(w) != rest.end()) {
                            tmp.insert(w);
                            rest.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
            depth++;
            *pb = tmp;
        }
        return 0;
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
	string begin = "hot", end = "dog";
	vector<string> list = {"hot","dog","cog","pot","dot"};
	Solution* a = new Solution();
	int ans = a->ladderLength(begin, end, list);
	cout<<ans;

	return EXIT_SUCCESS;
}