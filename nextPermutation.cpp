#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <math.h>
#include <climits>
#include <sstream>
#include <set>


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

//99
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        int size = nums.size();
        int end = size-1;
        int i = end;
        
        while(nums[i] <= nums[--i]){}
        
        if(i == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        while(nums[end] <= nums[i])
            end--;
        
        swap(nums[end], nums[i]);
        sort(nums.begin() + i+1, nums.end());
    }
};

int main(){
	Solution a;
	string s = "the sky is blue";

	a.reverseWords(s);

	cout<<s<<endl; 

	return EXIT_SUCCESS;
}