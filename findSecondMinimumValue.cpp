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

//100
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        unordered_map<int, int> map;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        for(;!que.empty(); que.pop()){
            TreeNode* tmpTree = que.front();
            if(map[tmpTree->val]++ == 0)
                pq.push(tmpTree->val);
            if(tmpTree->left != nullptr)
                que.push(tmpTree->left);
            if(tmpTree->right != nullptr)
                que.push(tmpTree->right);
        }
        if(pq.size() < 2)
            return -1;
        
        pq.pop();
        return pq.top();
    }
};

int main(){
	vector<int> nums = {1,1,1,0};
	int target = -100, ans;
	ans = threeSumClosest(nums, target);
	cout<<"ans = "<<ans<<endl;
	return EXIT_SUCCESS;
}
