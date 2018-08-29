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

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		dp[0][1] = 1;
		for(int i = 1; i<=m; ++i){
			for(int j = 1; j<=n; ++j){
				if(!obstacleGrid[i-1][j-1]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m][n];
}

int main(){
	vector<vector<int>> input = {{0,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,0}};
	//{{0,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,0}};
	//{{1,1}};
	//{{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
	//{{1}};
	//{{0,0,0}, {0,1,0}, {0,0,0}};
	int ans;
	ans = uniquePathsWithObstacles(input);
	cout<<ans;
	return EXIT_SUCCESS;
}