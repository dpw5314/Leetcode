#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>

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

string intToRoman(int num) {
	    if(num<1 || num>3999) {return "Wrong Answer";}
        int count = 0, temnum;
        string ans = "", tem;
        string Roman1 = "IXCM", Roman5 = "VLD", temstring; 
        do {
        	if(count>0) num /= 10;
        	tem = "";
            temnum = num%10;
            if(temnum <= 3){
            	temstring = Roman1[count];
                for(int i=1; i<=temnum; i++) {
                    tem.insert(0, temstring);
                }
            }
            else if (temnum == 4){
            	temstring = Roman1[count];
            	tem = Roman5[count];
            	tem.insert(0, temstring);
			}
			else if (temnum>=5 && temnum<=8){
				temnum = temnum-5;
				temstring = Roman1[count];
                for(int i=1; i<=temnum; i++) {
                    tem.insert(0, temstring);
                }
                temstring = Roman5[count];
                tem.insert(0, temstring);
			}
			if(temnum == 9){
				temstring = Roman1[count];
            	tem = Roman1[count+1];
            	tem.insert(0, temstring);
			}
            count++;
            ans.insert(0, tem);
            cout<<num<<endl;
        } while(num/10>0);
        return ans;
    }



int main(){
	int num = 49;
	string ans;
	ans = intToRoman(num);
	PrintString(ans);
	return EXIT_SUCCESS;
} 
