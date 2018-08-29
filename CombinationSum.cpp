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

void finding (vector<int>& candidates, int target, int sum, vector<int> tem, vector<vector<int>>& ans, int start) {
    int tempsum = target - sum;
    vector<int>::iterator it = find(candidates.begin(), candidates.end(), tempsum);
    if(it != candidates.end() and distance(candidates.begin(), it) >= start) {
        
        tempsum = candidates[distance(candidates.begin(), it)];
        tem.push_back(tempsum); 
        ans.push_back(tem);
        tem.pop_back();
    }
    
    for(int i = start; i< candidates.size(); i++){
        if(sum + candidates[i] < target) {
            tempsum = candidates[i];
            tem.push_back(tempsum);
            finding(candidates, target, sum+ candidates[i], tem, ans, i);
        }
        else if (sum + candidates[i] >= target){
            tem.clear();
            break;
        }
        tem.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tem;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        finding(candidates, target, sum, tem, ans, 0);
        return ans;
        
    }
    

int main(){
	vector<vector<int>> ans;
	vector<int> candidates = {2,3,6,7};
    int target = 7;
	ans = combinationSum(candidates, target);
    PrintItvector(ans);
	return EXIT_SUCCESS;
}
