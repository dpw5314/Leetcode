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


//100%
class Solution {
public:
    void find(int k, int start, vector<int>& temp, int n, vector<vector<int>>& ans){
        //cout<<n<<endl;
        k--;
        for(int i = start; i<=9; ++i){
            int TempNum = n-i;
            temp.push_back(i);
            if(TempNum == 0 && k == 0)
                ans.push_back(temp);
            else if(k > 0)
                find(k, i+1, temp, TempNum, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int max = 9*k - ((k-1) * k)/2;
        if(n == 0 || n>max)
            return ans;
        vector<int> temp;
        find(k, 1, temp, n, ans);
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