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



//98
class Solution {
public:
    struct ele{
        ele()
         { }
        int degree;
        int first;
        int len;
    };
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, ele> map;
        int degree = 0;
        for(int i = 0; i<nums.size(); ++i){
            if(map.find(nums[i]) == map.end()){
                ele temp;
                temp.degree = 1;
                temp.first = i;
                temp.len = 1;
                map[nums[i]] = temp;
            }
            else{
                map[nums[i]].degree++;
                map[nums[i]].len = i-map[nums[i]].first + 1;
            }
            if(map[nums[i]].degree > degree)
                degree = map[nums[i]].degree;
        }
        
        int ans = INT_MAX;
        for(auto ele : map){
            //cout<<ele.first<<" "<<ele.second.degree<<" "<<ele.second.len<<endl;
            if(ele.second.degree == degree && ele.second.len < ans){
                ans = ele.second.len;
            }
        }

        return ans;
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