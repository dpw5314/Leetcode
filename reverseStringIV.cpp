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

//97
class Solution {
public:
    string reverseWords(string & s) {
        if(s.size() == 0)
            return s;
        
        int start, end;
        
        reverse(s, 0, s.size() - 1);


        for(int i = 0; i<s.size(); ++i){
            if(s[i] != ' '){
                start = i;
                while(s[i] != ' ' && i != s.size()-1 && s[i+1] != ' ')
                    i++;
                reverse(s, start, i);
            }
        }
        
        return s;
    }
    
    void reverse(string& s, int start, int end){
        while(end > start){
            char temp = s[start];
            s[start++] = s[end];
            s[end--] = temp;
        }
    }
};


int main(){
	Solution a;
	string s = "the sky is blue";

	a.reverseWords(s);

	cout<<s<<endl; 

	return EXIT_SUCCESS;
}