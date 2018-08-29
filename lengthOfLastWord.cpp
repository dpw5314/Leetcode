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

int lengthOfLastWord(string s) {
        int size = s.length(), ans = 0, index;
        if(size == 0) return ans;
        index = size - 1;
        
        while(s[index] == ' ' and index >= 0){
            index--;
        }
        
        while(s[index] != ' ' and index >= 0){
            ans++;
            index--;
        }
        
        return ans;
    }


int main(){
	string s = "Hello cCDJKFLDKFJ;dkajfd";
	int ans;
	ans = lengthOfLastWord(s);
    cout<<ans;
	//PrintItvector(ans);
    return EXIT_SUCCESS;
}
