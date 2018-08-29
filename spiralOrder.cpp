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

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) return ans;
        int size1 =matrix.size(), size2 = matrix[0].size();
        int up = 0, right = size2, down = size1, left = 0, total = size1*size2;
        
        while(total>0){
            int i = up, j = left;
            while(j<right and total > 0) {          
                ans.push_back(matrix[i][j]);
                j++;
                total-=1;
            }
            j--;
            up++;  
            
            while(i<down-1 and total > 0){
                i++;
                ans.push_back(matrix[i][j]);
                total-=1;
            }

            right--;
            
            while(j >left and total > 0){
                j--;
                ans.push_back(matrix[i][j]);
                total-=1;
            }            
            left++;
            
            while(i > up and total > 0){
                i--;
                ans.push_back(matrix[i][j]);
                total-=1;
            }
            down--;
            if(total<=0) break;

        }
        return ans;
    }



int main(){
	vector<vector<int>> matrix= {{1,2,3,4}, 
                                 {5,6,7,8},
                                 {9,10,11,12}
                                 };
	vector<int> ans;
	ans = spiralOrder(matrix);
    //cout<<ans;
	PrintItvector(ans);
    return EXIT_SUCCESS;
}
