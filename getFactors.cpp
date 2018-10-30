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

class Solution {
public:
    void DFS(int n, int factor, vector<int> vec)
    {
        if(factor > sqrt(n)) return;
        DFS(n, factor+1, vec);
        if(n%factor==0)
        {
            vec.push_back(factor);
            DFS(n/factor, factor, vec);
            vec.push_back(n/factor);
            ans.push_back(vec);
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        DFS(n, 2, vector<int>{});
        return ans;
    }
private:
    vector<vector<int>> ans;
};


int main(){
	int num = 12;

	Solution a;
	vector<vector<int>> ans = a.getFactors(num);
	PrintItvector(ans);
	return EXIT_SUCCESS;
}