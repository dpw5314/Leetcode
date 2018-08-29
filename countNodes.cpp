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


//My second solution 18%
class Solution {
public:

    int countNodes(TreeNode* root) {
        if(!root) return 0; 
        if(!root->left && !root->right){
            return 1;
        }
        else if(root->left && !root->right)
            return 2;
    
        TreeNode* rootL = (root->left) ? root->left:nullptr;
        TreeNode* rootR = (root->right) ? root->right:nullptr;
        TreeNode* rootH = (root->right) ? root->right:nullptr;
        int Left = 1, Right = 1, Half = 1;
        while(rootL || rootR || rootH){
            if(rootL) {Left++; rootL = rootL->left;}
            if(rootR) {Right++; rootR = rootR->right;}
            if(rootH) {Half++; rootH = rootH->left;}
        }
        if(Left == Right)
            return pow(2, Left) -1;

        else{
            int Value = (Half == Left)?0:-1;
            int Value2 = Value -1;
            TreeNode* NextRoot = (Left != Half)?root->left:root->right;
            //cout<<root->val<<" "<<pow(2, Left + Value)-pow(2, Left+Value2) -2<<endl;
            return pow(2, Left + Value)-pow(2, Left+Value2) + countNodes(NextRoot);
        } 
        return countNodes(root);
    }
};


// 50% solution
class Solution {
public:

    int countNodes(TreeNode* root) {
        if(!root) return 0; 
        if(!root->left && !root->right){
            return 1;
        }
        else if(root->left && !root->right)
            return 2;
    
        TreeNode* rootL = (root->left) ? root->left:nullptr;
        TreeNode* rootR = (root->right) ? root->right:nullptr;
        //TreeNode* rootH = (root->right) ? root->right:nullptr;
        int Left = 1, Right = 1, Half = 1;
        while(rootL) {Left++; rootL = rootL->left;}
        while(rootR) {Right++; rootR = rootR->right;}

        if(Left == Right)
            return pow(2, Left) -1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// 99 Solution
class Solution {
public:

    int countNodes(TreeNode* root) {
        if(!root) return 0; 
        if(!root->left && !root->right){
            return 1;
        }
        else if(root->left && !root->right)
            return 2;
    
        TreeNode* rootL = (root->left) ? root->left:nullptr;
        TreeNode* rootR = (root->right) ? root->right:nullptr;
        TreeNode* rootH = root->right;
        int Left = 1, Right = 1, Half = 1;
        long long Num = 2;
        while(rootR){
           Num *=2;
           Left++; rootL = rootL->left;
           Right++; rootR = rootR->right;
           Half++; rootH = rootH->left;
        }
        if(rootL){Num *=2; Left++; rootL = rootL->left;}
        if(rootH){Half++; rootH = rootH->left;}
        if(Left == Right)
            return pow(2, Left) -1;

        else{
            TreeNode* NextRoot = (Left != Half)?root->left:root->right;
            //cout<<root->val<<" "<<pow(2, Left + Value)-pow(2, Left+Value2) -2<<endl;
            if(Left == Half)
                return Num-Num/2 + countNodes(NextRoot);
            return Num/2 - Num/4 + countNodes(NextRoot);
        } 
    }
    
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