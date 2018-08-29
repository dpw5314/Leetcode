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

void finding(vector<vector<int>>& ans, vector<int>& tem, vector<int> tem1){
    int temint;
    vector<int> tem2;
    
    if(tem1.size() == 0) {
        ans.push_back(tem);
        return;
    }
    else{
        for(int i =0; i < tem1.size(); i++){
            temint = tem1[i];
            tem.push_back(temint);
            tem2 = tem1;
            tem2.erase(tem2.begin()+i, tem2.begin()+i+1);
            finding(ans, tem, tem2);
            tem.pop_back();
        }
    }  
    return;
}

vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tem, tem1 = nums;
        finding (ans, tem, tem1);
        return ans;
    }
    



int main(){
	vector<int> vec = {1,2,3};
	vector<vector<int>> ans;
	ans = permute(vec);
    PrintItvector(ans);
	return EXIT_SUCCESS;
}
