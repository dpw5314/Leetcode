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

vector<vector<int> > fourSum(vector<int>& nums, int target) {
		vector<int> ans1 = {0,0,0,0};
		vector<vector<int> > ans;

		int sum1, sum2, sum3;
		int Index1, Index2, Index3, Index4;
		bool find_or_not;
		//Index1 = nums.size()-1; Index2 = 0;
   
		sort(nums.begin(), nums.end());
		if(nums.size()<4) return ans;
        for(int i =0; i<nums.size()-2; i++){        	
            for(int j = i+1; j < nums.size()-1; j++) {
                sum1 =  nums[i] + nums[j];
                Index1 = j+1;
                Index2 = nums.size()-1;
                while(Index2 > Index1) {
                	cout<<"temp:"<<nums[i]<<" "<<nums[j]<<" "<<nums[Index1]<<" "<<nums[Index2]<<" ";
                	cout<<"index:"<<i<<" "<<j<<" "<<Index1<<" "<<Index2<<" "<<endl; 
                	sum2 = nums[Index1]+nums[Index2]+sum1;
                    if (sum2 == target) {
						ans1[0] = nums[i];
	                    ans1[1] = nums[j];
	                    ans1[2] = nums[Index1]; 
	                    ans1[3] = nums[Index2]; 
	                    ans.push_back(ans1);
                        if(Index1 + 1 <= Index2 and Index2 - 1 >= Index1)Index1++; Index2--;
                        }
                    else if(sum2 > target ) Index2--;
                    else if (sum2 < target ) Index1++;
                    while(Index1 - 1 >= j+1 and nums[Index1-1] == nums[Index1] ) {cout<<"Happen Index1:"<<nums[Index1]<<endl; Index1++;}
                	while(Index2 + 1 < nums.size() and nums[Index2+1] == nums[Index2]) {cout<<"Happen Index2:"<<nums[Index2]<<endl; Index2--;}

                }
                while(j+1<nums.size()  and nums[j+1] == nums[j]) j++;
            }
            while(i+1<nums.size() and nums[i+1] == nums[i]) i++;
        }

		return ans;

	}        



int main(){
	vector<vector<int> > ans;
	vector<int> nums = {-9,4,0,-3,6,3,-3,-9,-7,1,0,-7,-8,7,1};
	int target = -9;
	ans = fourSum(nums, target);
	PrintItvector(nums);
	cout<<endl<<endl;
	PrintItvector(ans);
	return EXIT_SUCCESS;
} 
