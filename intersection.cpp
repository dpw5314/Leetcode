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

//100
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        if(nums1.size() == 0 || nums2.size() == 0)
            return ans;
        unordered_map<int, int> map;
        
        for(int i = 0; i<nums1.size(); ++i){
            map[nums1[i]]++;
        }
        
        for(int i = 0; i<nums2.size(); ++i){
            if(map.find(nums2[i]) != map.end()){
                ans.push_back(nums2[i]);
                map.erase(nums2[i]);
            }
                
        }
        return ans;
    }
};
int main(){
	Solution a;
	string s = "the sky is blue";

	a.reverseWords(s);

	cout<<s<<endl; 

	return EXIT_SUCCESS;
}