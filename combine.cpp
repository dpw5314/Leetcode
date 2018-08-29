#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;
const int size =9;

template<typename T>
void PrintItvector(vector<vector<T> >& a){
	for(int i = 0; i < a.size(); i++){
		for(int j=0; j<a[0].size(); j++){
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

void PrintString(string& a){
	cout<<a<<endl;
} 


void Combine(vector<int>& temans, vector<vector<int> >& ans, int n, int k, int start, int count) {
	if(start > n || count > k) return;
	int con = start, count1 = count;
	for(int i = con; i<= n; i++){
		temans.push_back(i);
		//PrintItvector(temans);
		if(count1 == k) ans.push_back(temans);
		else {
			con++;
			Combine(temans, ans, n, k, con, count1+1);
		}
		temans.erase(temans.end()-1);	
	}
}

vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > ans;
	vector<int> temans;
	int start = 1, count = 1;
	Combine(temans, ans, n, k, start, count);
	return ans;
}
    
    



int main(){
	int n = 4, k = 2;
	vector<vector<int> > ans = combine(n, k);
	PrintItvector(ans);
	return EXIT_SUCCESS;
} 
