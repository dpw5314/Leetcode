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

//94
class Solution {
public:
        
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr)
            return false;
        if(isSame(s, t))
            return true;
        
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isSame(TreeNode*s ,TreeNode* t){
        if(s == nullptr && t == nullptr)
            return true;
        if(s == nullptr || t==nullptr)
            return false;
        if((s && t) && s->val != t->val)
            return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int len = nums.size();
        MonotonicQueue q;
        for(int i = 0; i<len; ++i){
            q.insert(nums[i]);
            if(i-k+1 >= 0){
                ans.push_back(q.max());
                if(nums[i-k+1] == q.max())
                    q.pop();
            }
        }
        
        return ans;
    }
};

int main(){
	string s = "xyyxabcba", ans;
	ans = longestPalindrome(s);
	cout<<ans;
	return EXIT_SUCCESS;
}
