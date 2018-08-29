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


// std sort
  class Solution {
public:
    struct{
        bool operator() ( int& a, int& b) const{
                int lenleft = to_string(a).size();
                int lenright = to_string(b).size();
                if(lenleft == lenright)
                    return a>=b;
                else{
                    int final1 = a* pow(10, lenright) + b;
                    int final2 = b * pow(10, lenleft) + a;
                    if(final1 >= final2)
                        return true;
                    else
                        return false;
                } 
        }       
    } compare;
        
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return "";
        else if(nums.size() == 1)
            return to_string(nums[0]);
        else if(*max_element(nums.begin(), nums.end()) == 0)
            return "0";
        
        vector<int> temp(nums.size());
        std::sort(nums.begin(), nums.end(), compare);
        string ans;
        for(auto ele : nums)
            ans += to_string(ele);
        
        
        return ans;
    }
};

// 55
class Solution {
public:
    void merge(vector<int>& nums, vector<int>& temp, int leftPos, int rightPos, int rightEnd){
        int leftEnd = rightPos - 1;
        int numStart = leftPos, temPos = leftPos;
        while(leftPos<=leftEnd && rightPos <= rightEnd){
            int lenleft = to_string(nums[leftPos]).size();
            int lenright = to_string(nums[rightPos]).size();
            if(lenleft == lenright){
                if(nums[leftPos] >= nums[rightPos])
                    temp[temPos++] = std::move(nums[leftPos++]);
                else
                    temp[temPos++] = std::move(nums[rightPos++]);          
            }
            else{
                int leftNum = nums[leftPos], rightNum = nums[rightPos];
                int final1 = leftNum * pow(10, lenright) + rightNum;
                int final2 = rightNum * pow(10, lenleft) + leftNum;
                if(final1 >= final2)
                    temp[temPos++] = std::move(nums[leftPos++]);
                else
                    temp[temPos++] = std::move(nums[rightPos++]); 
            }
        }
        while(leftPos<=leftEnd)
            temp[temPos++] = std::move(nums[leftPos++]);
        while( rightPos <= rightEnd)
            temp[temPos++] = std::move(nums[rightPos++]);
        
        for(int i = rightEnd; i>= numStart; i--)
            nums[i] = std::move(temp[i]);
    }
    
    void QuickSort(vector<int>& nums, vector<int>& temp, int left, int right){
        int center = (left+right)/2;
        if(left<right){
            QuickSort(nums, temp, left, center);
            QuickSort(nums, temp, center+1, right);
            merge(nums,temp, left, center+1, right);
        }
    }
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return "";
        else if(nums.size() == 1)
            return to_string(nums[0]);
        
        vector<int> temp(nums.size());
        QuickSort(nums, temp, 0, nums.size()-1);
        if(nums[0] == 0)
            return "0";
        string ans;
        for(auto ele : nums)
            ans += to_string(ele);
        
        
        return ans;
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