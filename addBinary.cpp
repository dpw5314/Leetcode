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

string addBinary(string a, string b) {
        int add1, add2, carry = 0, sizeA = a.size(), sizeB = b.size(), sizeAns = sizeA+sizeB, startIndex;
        string ans(sizeA+sizeB, '0');
        
        if(sizeA ==0 or sizeB ==0) return (sizeA == 0)?b : a;
        else if(sizeA == 0 and sizeB == 0) return a;
        
        for(int i = 0; i<ans.size(); i++){
            if(sizeA - 1 - i >=0 or sizeB - 1 - i >=0){
                add1 = (sizeA - 1 - i >=0) ? a[sizeA- 1 - i] - '0' : 0;
                add2 = (sizeB - 1 - i >=0) ? b[sizeB-1-i] -'0' : 0;
                add1 = add1 + add2 + carry;
                carry = add1 > 1 ? 1:0;
                ans[sizeAns-1-i] = add1%2 + '0';
            }
            else if ( carry != 0){
                ans[sizeAns-1-i] = carry + '0';
                startIndex = sizeAns-1-i;
                break;
            }
            else{
                startIndex = sizeAns-i;
                break;
            }
        }
        
        return ans.substr(startIndex);
    }



int main(){
	string a = "100", b = "110010", ans;
	ans = addBinary(a,b);
    cout<<ans;
	//PrintItvector(ans);
    return EXIT_SUCCESS;
}
