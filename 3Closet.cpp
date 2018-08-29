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

int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int sum1, lowest = -1 ;
		int Index1, ans=nums[0]+nums[1]+nums[2], nsize = nums.size();

		for(int i=0; i<nsize-2; i++){
            int j = i+1;
            Index1 = nsize-1;
            while(Index1>j){
                sum1 = nums[i]+nums[j]+nums[Index1];
                if(abs(target-ans) > abs(target - sum1)){
                    ans = sum1;
                    if (ans == target) return ans;
                    }
                (sum1 > target) ? Index1-- : j++;
            }
        }

		return ans;

	}



int main(){
	vector<int> nums = {1,1,1,0};
	int target = -100, ans;
	ans = threeSumClosest(nums, target);
	cout<<"ans = "<<ans<<endl;
	return EXIT_SUCCESS;
}
