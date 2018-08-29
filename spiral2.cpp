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

vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        //PrintItvector(ans);
        vector<int>tem;
        if(n == 0) return ans;

        int size1 =n , size2 = n;
        int up = 0, right = size2, down = size1, left = 0, total = 1;
        while(total < n*n+1){
            int i = up, j = left;
            while(j<right and total < n*n+1) {          
                ans[i][j] = total;
                j++;
                total+=1;
            }
            j--;
            up++;  
            
            while(i<down-1 and total < n*n+1){
                i++;
                ans[i][j] = total;
                total+=1;
            }

            right--;
            
            while(j >left and total < n*n+1){
                j--;
                ans[i][j] = total;
                total+=1;
            }            
            left++;
            
            while(i > up and total < n*n+1){
                i--;
                ans[i][j] = total;
                total+=1;
            }
            down--;

        }
        
        return ans;
    }



int main(){
	int n = 1;
	vector<vector<int>> ans;
	ans = generateMatrix(n);
    //cout<<ans;
	PrintItvector(ans);
    return EXIT_SUCCESS;
}
