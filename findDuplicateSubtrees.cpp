#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <math.h>
#include <climits>
#include <queue>
#include <sstream>
#include <unordered_map>

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

class Solution {
public:
    unordered_map<string, int> map;
    
    string Inorder(TreeNode* root, vector<TreeNode*>& ans){
        if(!root)
            return "";
        string s =  to_string(root->val)  + "," +Inorder(root->left, ans) + "," + Inorder(root->right, ans);
        //cout<<s<<endl;
        if(map.find(s) == map.end())
            map[s] = 0;
        else{
            if(++map[s] == 1){
                ans.push_back(root);
            }
        }
        return s;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        string s = Inorder(root, ans);
        return ans;
    }
};

int main(){
	Solution a;
	vector<vector<int>> vec = {
							  {1,   4,  7, 11, 15},
							  {2,   5,  8, 12, 19},
							  {3,   6,  9, 16, 22},
							  {10, 13, 14, 17, 24},
							  {18, 21, 23, 26, 30}};
	int target = 11;
	//{{'1','1','1'},{'0','1','0'},{'1','1','1'}};
							/*	{{'1','1','0','0','0'},
								{'1','1','0','0','0'},
								{'0','0','1','0','0'},
								{'0','0','0','1','1'}};*/
							/*	{{'1','1','1','1','0'},
								{'1','1','0','1','0'},
								{'1','1','0','0','0'},
								{'0','0','0','0','0'}};*/
	//{-2, 3, -4};
	//{-1,-2,-9,-6};

  //{412,392,401,75,38,106,223};
  //{58,92,387,421,194,208,231};
  //{186,419,83,408} ;
  //7802;
  //7798;
  //6249;
	bool ans = a.searchMatrix(vec, target);
	cout<<ans;
	return EXIT_SUCCESS;
}