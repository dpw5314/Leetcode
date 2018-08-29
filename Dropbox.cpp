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
#include <unordered_map>

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

void trevase (string& p1, string& p2, bool& ans, int index1, int index2, unordered_map<char, string> map){
	if(ans)
		return;
	if(map.find(p1[index1]) != map.end()){
		//cout<<index1<<endl;
		int strsize = map[p1[index1]].size();
		string temp = p2.substr(index2, strsize);
		//cout<<temp<<" "<<map[p1[index1]]<<endl;
		if(temp==map[p1[index1]]){
			if(index1<p1.size()-1 and index2+strsize-1<p2.size()-1)
				trevase(p1, p2, ans, index1+1, index2+strsize, map);
			else if(index1 == p1.size()-1 and index2+strsize-1==p2.size()-1)
				ans = 1;
		}
		else
			return;		
			
	}
	else{
		if(index1 == p1.size()-1){

			map[p1[index1]] == p2.substr(index2, p2.size()-index2);
			ans = 1;
			//cout<<p1[index1]<<": "<<p2.substr(index2, p2.size()-index2)<<endl;
			return;
		}
		//cout<<index1<<"Cannot"<<endl;
		for(int i = index2; i<p2.size();i++){
			if(ans)
				return;
			string temp = p2.substr(index2, i-index2+1);
			//cout<<p1[index1]<<": "<<temp<<endl;
			map[p1[index1]] = temp;
			if(index1<p1.size()-1 and i<p2.size()-1)
				trevase(p1, p2, ans, index1+1, i+1, map);
			else if (index1==p1.size()-1 and i==p2.size()-1) {
				ans = 1;
				return;
			}
			else
				return;
		}
		//map[p1[index1]] = "1";
	}
	return;
}

bool Dropbox(string& p1, string& p2) {
	bool ans = 0;
	//vector<char> vec1;
	unordered_map<char, string> map;
	trevase(p1, p2, ans, 0, 0, map);
	return ans;
}


int main(){
	string pattern1 = "aba", pattern2 = "redredred";
	bool ans;
	ans = Dropbox(pattern1, pattern2);
    cout<<ans;
	return EXIT_SUCCESS;
}
