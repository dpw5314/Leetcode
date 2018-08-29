  #include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <math.h>
#include <climits>
#include <queue>
#include <sstream>
#include <unordered_map>

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

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        if((numerator<0 and denominator > 0) or(numerator > 0 and denominator < 0))
            ans += "-";
        long long numer = numerator, denomin = denominator;
        numer = abs(numer); denomin = abs(denomin);
        long long upper = numer/denomin;
        long long remind = abs(numer%denomin);
        stringstream ss; ss<<upper; 
        
        ans += ss.str();
        
        if(remind == 0) return ans;
        
        ans += ".";
        string tempStr;
        int Cur = -1;
        remind *= 10;
        unordered_map<int, int> map;
        while(remind > 0 ){
            if(map.find(remind) == map.end()){
                Cur++;
                map[remind] = Cur;

                if(remind < denomin){

                    remind *= 10;
                    tempStr += "0";
                }
                else{
                    int Tem = remind/denomin;
                    remind = remind%denomin;
                    //cout<<Tem;
                    stringstream  ss1;
                    ss1<<Tem;
                    tempStr += ss1.str(); 
                    remind *= 10;
                }
            }
            else{
                tempStr.insert(map[remind], "(");
                tempStr += ")";
                break;
            }
        }

        return ans+tempStr;
    }
};


int main(){
	Solution a;
	vector<vector<int>> vec = {
							  {1,   4,  7, 11, 15},
							  {2,   5,  8, 12, 19},
							  {3,   6,  9, 16, 22},
							  {10, 13, 14, 17, 24},
							  {18, 21, 23, 26, 30}};
	int target = 11;
	//{{'1','1','1'},{'0','1','0'},{'1','1','1'}};
							/*	{{'1','1','0','0','0'},
								{'1','1','0','0','0'},
								{'0','0','1','0','0'},
								{'0','0','0','1','1'}};*/
							/*	{{'1','1','1','1','0'},
								{'1','1','0','1','0'},
								{'1','1','0','0','0'},
								{'0','0','0','0','0'}};*/
	//{-2, 3, -4};
	//{-1,-2,-9,-6};

  //{412,392,401,75,38,106,223};
  //{58,92,387,421,194,208,231};
  //{186,419,83,408} ;
  //7802;
  //7798;
  //6249;
	bool ans = a.searchMatrix(vec, target);
	cout<<ans;
	return EXIT_SUCCESS;
}