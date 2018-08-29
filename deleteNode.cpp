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
    void FindandReplace(TreeNode* Curr, TreeNode* prev, TreeNode* root){
        if(root->left){
            prev = root;
            root=root->left;
            while(root->right){
                prev = root;
                root = root->right;
            }
        }
        else if(root->right){
            prev = root;
            root=root->right;
            while(root->left){
                prev = root;
                root = root->left;
            }
        }
        else{
            if(prev->left == root)
                prev->left = nullptr;
            else if(prev->right == root)
                prev->right = nullptr;
            root = nullptr;
            return;
        }        
        Curr->val = root->val;
        Curr = root;
        FindandReplace(Curr, prev, root);
        
    }
    

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* prev = new TreeNode(0);
        //find tie number;
        TreeNode* newPrev = prev;
        prev->left = root;
        bool ifFind = false;
        
        while(root){
            if(key < root->val){
                prev = root;
                root = root->left;
            }
            else if(key > root->val){
                prev = root;
                root = root->right;
            }
            else if(key == root->val){
                //cout<<root->val;
                ifFind =  true;
                break;
            }
        }
        
        if(!ifFind)
            return newPrev->left;
        else if(ifFind and prev == newPrev and !root->left and !root->right){
            return newPrev->right;
        }            
        
        TreeNode* tempRoot = root;
        FindandReplace(tempRoot, prev, root);

        return newPrev->left;
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