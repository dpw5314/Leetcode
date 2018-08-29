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

//14, brute force
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int len = nums.size();
        if(len == 0 || k == 0){
            return ans;
        }
        if(len< k){
            int num = *max_element(nums.begin(), nums.end());
            ans.push_back(num);
        }
        else{
            for(int i = 0; i<nums.size() - k + 1; ++i){
                int max = nums[i];
                //cout<<nums[i]<<" ";
                for(int j = i+1; j<i+k; j++){
                    if(max<nums[j])
                        max = nums[j];
                }
                //cout<<endl;
                ans.push_back(max);
            }
        }
        return ans;
    }
};

//multiset 26.41
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int len = nums.size();
        multiset<int> s1;
        if(len == 0 || k == 0){
            return ans;
        }
        else{
            for(int i = 0; i<k; ++i)
                s1.insert(nums[i]);
            ans.push_back(*s1.rbegin());
            int index = 0;
            for(int i = k; i<len; ++i){
                s1.insert(nums[i]);
                auto it = s1.find(nums[index++]);
                s1.erase(it);
                //ans.push_back(*s1.rbegin());
                ans.push_back(*s1.rbegin());
            }
        }
        return ans;
    }
};


//29.56
class MonotonicQueue{
    public:
        void insert(int num){
            while(!dq.empty() && num > dq.back())  dq.pop_back();            
            dq.push_back(num);
        }
        
        void pop(){
            dq.pop_front();
        }
    
        int max() const{
            return dq.front();
        }
    private:
        deque<int> dq;
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
