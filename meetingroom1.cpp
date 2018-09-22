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




//33
class Solution{
public:
	struct{
		bool operator()(pair<int,int> &a, pair<int,int> &b){
			return a.first < b.first;
		}
	}comp;

    bool meetingroom(vector<pair<int,int>> & vec){
    	sort(vec.begin(), vec.end(), comp);

    	if(vec.size() == 0)
    		return true;
    	

    	for(int i = 0; i<vec.size()-1; ++i){
    		if(vec[i].second > vec[i+1].first)
    			return false;
    	}

    	return true;
    }
};



int main(){
	Solution a;
	vector<pair<int, int>> vec = {{0, 30}, {15,20}, {5,10}};

	bool ans = a.meetingroom(vec);

	cout<<ans<<endl; 

	return EXIT_SUCCESS;
}