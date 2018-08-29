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

void graydfs(vector<int>& ans, int n, int prevnum){
	int now = prevnum, later = n, plus = 1<<(now++-1);
	int size = ans.size() - 1, tem;
	for(int i = size; i>=0; i--){
		tem = plus + ans[i];
		ans.push_back(tem); 
	}
	if(now<=later) graydfs(ans, later, now);
}

 vector<int> grayCode(int n) {
	vector<int> ans;
	ans.push_back(0);
	if(n > 0){
		int count = 1;
		graydfs(ans, n, count);
	}
	return ans;
}



    



int main(){
	int n = 0;
	vector<int> ans = grayCode(n);
	PrintItvector(ans);
	return EXIT_SUCCESS;
} 
