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

bool canJump(vector<int>& nums) {
        bool ans;
        int index = 0, nextindex, maxJump, nextJump;
        while(nums[index] > 0){
            if(index==nums.size()-1 or nums[index]+index >= nums.size()-1) return true;
            nextJump = 0;
            maxJump = nums[index];
            for(maxJump; maxJump > 0; maxJump--){
                if(maxJump + nums[index+maxJump] > nextJump){
                    nextindex = index  + maxJump;
                    nextJump = maxJump + nums[index+maxJump];
                }
            }
            index = nextindex;
            
        }
        if(nums[index] == 0 and index != nums.size()-1) return false;
        else return true;
    }


int main(){
	vector<int> nums = {2,5,0,0};
	bool ans;
	ans = canJump(nums);
    cout<<ans;
	//PrintItvector(ans);
    return EXIT_SUCCESS;
}
