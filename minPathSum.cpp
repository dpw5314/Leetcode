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

 /*
   ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
*/

int minPathSum(vector<vector<int>>& grid){
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dp1(m+1, vector<int>(n+1, 0));
	
	for(int i = 1; i<=m; ++i){
		for(int j = 1; j<=n; ++j){
			if(i == 1) dp1[i][j] = grid[i-1][j-1] + dp1[i][j-1];
			else if (j == 1) dp1[i][j] = grid[i-1][j-1] + dp1[i-1][j];
			else dp1[i][j] = (dp1[i-1][j] < dp1[i][j-1]) ? dp1[i-1][j] + grid[i-1][j-1] : dp1[i][j-1] +grid[i-1][j-1];
			
		}
	}
	
	return dp1[m][n];
}

int main(){
	vector<vector<int>> input = {{1,3,1}, {1,5,1}, {4,2,1}};
	//{{0,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,0}};
	//{{1,1}};
	//{{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
	//{{1}};
	//{{0,0,0}, {0,1,0}, {0,0,0}};
	int ans;
	ans = minPathSum(input);
	cout<<ans;
	return EXIT_SUCCESS;
}