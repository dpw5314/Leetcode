#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<sstream>
#include<math.h>

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

void PrintString(string& a){
	cout<<a<<endl;
} 

string multiply(string num1, string num2) {
        int ans_int = 0, c1,c2, v1, v2;
        string ans = "", tem;
        stringstream ss;
        c1 = 1;
        cout<<num1[num1.size()-1]<<endl;
        for(int i = num1.size()-1; i>=0; i--){
            c2 = 1;
            v1 = num1[i] - '0';
            for(int j = num2.size()-1; j>=0; j--){
                v2 = num2[j] - '0';
                ans_int += v1*c1*v2*c2;
                c2 *= 10;
            }
            c1 *= 10;
            cout<<ans_int<<endl;
            if(ans_int >= ((INT_MAX)/10)){
                tem = ans;
                ss<<ans_int;
                ans = ss.str();
                ans += tem;
                c1 = c2 = 1;
            }
            else if (i==0) {
                ss<<ans_int;
                ans = ss.str();
            }
        }
        return ans;
    }



    



int main(){
	string nums1 = "123456789", nums2 = "987654321", ans;
	ans = multiply(nums1, nums2);
	//cout<<ans;
	return EXIT_SUCCESS;
} 
