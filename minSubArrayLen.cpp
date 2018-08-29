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

//8.43%
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> dp(nums.size());
        int wSize = 1;
        while(wSize <= nums.size()){
            for(int i = 0; i<nums.size()-wSize+1; ++i){
                dp[i] += nums[i+wSize-1];
                //cout<<dp[i]<<" ";
                if(dp[i] >= s)
                    return wSize;
            }
            //cout<<endl;
            wSize++;
        }
        return 0;
    }
};
//80%
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int p = 0, q = 0, sum = nums[0];
        int ans = nums.size() + 1;
        while (p < nums.size() && q < nums.size()) {
            if (sum < s) {
                p++;
                sum += nums[p];
            } else {
                ans = min(ans, p - q + 1);
                sum -= nums[q];
                q++;
            }
        }
        return ans == nums.size() + 1 ? 0 : ans;
    }
};

int main(){
	Solution a;
	vector<int> vec = {3,2,3,1,2,4,5,5,6};
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
	int ans = a.findKthLargest(vec, 4);
	cout<<ans;
	return EXIT_SUCCESS;
}