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

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


void helper(string temans, int n, int left, int right, vector<string>& ans){
	if(right == n) {ans.push_back(temans); return;}

	if(left<n) helper(temans+"(", n, left+1, right, ans);

	if(right<left) helper(temans+")", n, left, right+1, ans);
}

vector<string> generateParenthesis(int n) {  
        vector<string> ans;
        string temans="";
        int left = 0, right = 0;

        helper(temans, n, left, right, ans);
        
        return ans;
    }




int main(){
	int n = 4;
	vector<string> ans;
	ans = generateParenthesis(n);
	PrintItvector(ans);
	return EXIT_SUCCESS;
}
