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


//76%
class Solution {
public:
    pair<int,int> helper(TreeNode* root){
        if(!root)
            return make_pair(0,0);
        pair<int,int> left, right;
        left = helper(root->left);
        right = helper(root->right);
        int max1 = max(left.first, left.second), max2 = max(right.first, right.second);
        return make_pair(left.second + right.second + root->val, max1+max2);
    }
    int rob(TreeNode* root) {
        pair<int,int> ans = helper(root);
        return max(ans.first, ans.second);
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