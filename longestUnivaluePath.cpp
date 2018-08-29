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


//My second solution 61%
class Solution {
public:
    int Calculation(TreeNode* root, bool isRoot, stack<TreeNode*>& stk){
        int Left = 0, Right = 0;
        if(root->left){
            if(root->left->val == root->val)
                Left = Calculation(root->left, false, stk);
            else
                stk.push(root->left);
        }
        if(root->right)
            if(root->right->val == root->val)
                Right = Calculation(root->right, false, stk);
            else
                stk.push(root->right);
        
        if(isRoot){
            //cout<<root->val<<":"<<Left<<" "<<Right<<endl;
            return Left+Right;
        }
        else if (!isRoot)
            return 1+ max(Left, Right);
    }


    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int Max = 0;  stack<TreeNode*> stk;
        while(root || !stk.empty() ){
            int a = Calculation(root, true, stk);
            if(a > Max)
                Max = a;
            if(!stk.empty()){
                root = stk.top();
                stk.pop();
            }
            else
                root = nullptr;
        }
        return Max;
    }
};

//First 31.18%
class Solution {
public:
    int Calculation(TreeNode* root, bool isRoot){
        int Left = 0, Right = 0;
        if(root->left && root->left->val == root->val)
            Left = Calculation(root->left, false);
        if(root->right && root->right->val == root->val)
            Right = Calculation(root->right, false);
        
        if(isRoot){
            //cout<<root->val<<":"<<Left<<" "<<Right<<endl;
            return Left+Right;
        }
        else if (!isRoot)
            return 1+ max(Left, Right);
    }
    
    void traverse(TreeNode* root, int& Max){
        int Cal = Calculation(root, true);
        
        if(Max<Cal) Max = Cal;
        if(root->left)
            traverse(root->left, Max);
        if(root->right)
            traverse(root->right, Max);
        return;
            
    }

    int longestUnivaluePath(TreeNode* root) {
        int Max = 0;
        if(!root) return 0;
        traverse(root, Max);
        return Max;
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