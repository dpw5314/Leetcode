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

//75
class Solution {
public:
    string reverseString(string s) {
        int start = 0, end = s.size()-1;
        while(end > start){
            char temp = s[start];
            s[start++] = s[end];
            s[end--] = temp;
        }
        
        return s;
    }
};


int main(){
	Solution a;
	vector<pair<int, int>> vec = {{0, 5}, {15,20}, {5,10}};

	int ans = a.meetingroom(vec);

	cout<<ans<<endl; 

	return EXIT_SUCCESS;
}