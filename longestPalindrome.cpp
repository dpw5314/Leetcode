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

string longestPalindrome(string& s) {
        int length = s.size();
        int Begin = 0, MaxLength = 1;
        bool truth_table[length][length] ={0};

        for(int i =0; i<length; i++) {
            truth_table[i][i] = 1;
        }

        for (int i = 0; i<length - 1; i++){
            if(s[i] == s[i+1]) {
                truth_table[i][i+1] = 1;
                Begin = i;
                MaxLength = 2;
            }
        }

        for(int curLength = 3; curLength <= length; curLength++){
            for(int i =0; i<length - curLength +1; i++){
                int j = i+curLength-1;
                if(s[i] == s[j] and truth_table[i+1][j-1]){
                    truth_table[i][j] = 1;
                    Begin = i;
                    MaxLength = curLength;
                }
            }
        }

        return s.substr(Begin, MaxLength);
    }


int main(){
	string s = "banana", ans;
	ans = longestPalindrome(s);
	cout<<ans;
	return EXIT_SUCCESS;
}
