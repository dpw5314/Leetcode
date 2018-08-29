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


void forloop(string& digits, string& letter, int stringindex, vector<string>& ans, string temans){
        int tem = digits[stringindex] - '0' - 2;
        int index = stringindex + 1;
        if(tem == 5 || tem == 7){
            for(int i = 0; i < 4; i++){
            	if(tem == 7) temans += letter[tem*3 + 1 +i];
                else
					temans += letter[tem*3 + i];
                if(stringindex == digits.size()-1) ans.push_back(temans);
                else
                    forloop(digits, letter, index, ans, temans);
                temans.erase(temans.end()-1);
            }
        }
        
        else if (tem == 6){
        	for(int i = 0; i < 3; i++){
                temans += letter[19 + i];
                if(stringindex == digits.size()-1) ans.push_back(temans);
                else
                    forloop(digits, letter, index, ans, temans);
                temans.erase(temans.end()-1);
            }
		}
        
        else{
            for(int i = 0; i < 3; i++){
            	
                temans = temans + letter[tem*3 + i];
                if(stringindex == digits.size()-1) ans.push_back(temans);
                else
                    forloop(digits, letter, index, ans, temans);
                temans.erase(temans.end()-1 );
            }
        }
        return;

    }


vector<string> letterCombinations(string digits) {
        string letter = "abcdefghijklmnopqrstuvwxyz", temans = "";
        vector<string> ans;
        int stringindex = 0;
        if(digits.size() == 0) return ans;
        forloop(digits, letter, stringindex, ans, temans);
        return ans;
    }
    
    



int main(){
	string digits = "343";
	vector<string> ans = letterCombinations(digits);
	PrintItvector(ans);
	return EXIT_SUCCESS;
} 
