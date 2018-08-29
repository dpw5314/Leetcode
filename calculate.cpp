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


//43
  class Solution {
public:
    int calculate(vector<int>& a1, vector<char>& o2){
        int ans = a1[0];
        for(int i = 0; i<o2.size(); ++i){
            if(o2[i] == '+')
                ans += a1[i+1];
            else if(o2[i] == '-')
                ans -= a1[i+1];
            else if(o2[i] == '*')
                ans *= a1[i+1];
            else if(o2[i] == '/')
                ans /= a1[i+1];
        }
        a1.clear();
        o2.clear();
        return ans;
    }
    int calculate(string s) {
        vector<int> array;
        vector<char> operators;
        vector<int> a1;
        vector<char> o1;
        int ans = -1, index = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' '){
                s.erase(i,1);
                i--;
            }
        }
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '+' || s[i]=='-'){
                int Num = stoi(s.substr(index,i-index));
                if(o1.size() > 0){
                    a1.push_back(Num);
                    Num = calculate(a1, o1);                    
                }
                array.push_back(Num);
                index = i+1;
                operators.push_back(s[i]);
            }
            else if(s[i] == '*' || s[i] == '/'){
                int Num = stoi(s.substr(index,i-index));
                a1.push_back(Num);
                o1.push_back(s[i]);
                index = i+1;
            }
            else if(i == s.size()-1){
                int Num = stoi(s.substr(index,i-index+1));
                if(o1.size()>0){
                    a1.push_back(Num);
                    Num = calculate(a1, o1);
                }
                array.push_back(Num);
            }
        }
        //cout<<array.size();
        if(array.size()>0)
            return calculate(array, operators);
        return ans;
    }
};


int main(){
	vector<int> vec = {2,1,1,2};
	//{3,5,7,0,1,2};
	//{3,1};
	Solution* a = new Solution();
	int ans = a->rob(vec);
    cout<<ans;
    delete a;
	return EXIT_SUCCESS;
}