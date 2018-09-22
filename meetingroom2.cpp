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




//33
class Solution{
public:
	struct{
		bool operator()(pair<int,int> &a, pair<int,int> &b){
			return a.first < b.first;
		}
	}comp;

    int meetingroom(vector<pair<int,int>> & vec){

    	if(vec.size() == 0)
    		return 0;

    	multiset<int> start, end;

    	for(int i = 0; i<vec.size(); ++i){
    		start.insert(vec[i].first); end.insert(vec[i].second);
    	}
    	int max = 0;

    	int cur = 0;

    	auto it = start.begin();
    	auto it1 = end.begin();
    	while(it != start.end() && it1 != end.end()){
    		cout<<*it<<" "<<*it1<<endl;
    		if(*it < *it1){
    			it++;
    			++cur;
    		}
    		else if(*it1 < *it){
    			it1++;
    			--cur;
    		}
    		else{
    			it++; it1++;
    		}

    		cout<<cur<<"...."<<endl;
    		if(cur > max)
    			max = cur;
    	}

    	return max;
    }
};



int main(){
	Solution a;
	vector<pair<int, int>> vec = {{0, 5}, {15,20}, {5,10}};

	int ans = a.meetingroom(vec);

	cout<<ans<<endl; 

	return EXIT_SUCCESS;
}