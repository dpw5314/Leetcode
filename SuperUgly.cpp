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

  /*
    int combination (int a, int b){
      if(b == 1) return a;
      else if (b == 0) return 1;
      int max = b > a-b ? b : a-b;
      long sum1 = 1;
      int sum2 = 1;
      for(int i = max+1; i<a; ++i){
        sum1 *= i;
      }
      for(int i = 1; i< a-max; ++i){
        sum2 *= i;
      }

      return sum1/sum2;
    }
*/

/** Slower but still work
class Solution {
public:
    void run(vector<int>& coins, int amount, int& ans, int layer, int index){
      if(ans != -1 and ans < layer)
        return;
      int size = coins.size();
    if(coins[index] <= amount){
      int nextAmount = amount%coins[index];
      int times = amount/coins[index];
      //cout<<layer<<" "<<coins[index]<<" "<<nextAmount<<" "<<times<<endl;
      if(nextAmount == 0){
        if(ans == -1)
          ans = layer+times-1;
        else
          ans = layer+times-1<ans?layer+times-1:ans;
        //cout<<ans<<endl;
      }
      else{
        if(index<size-1) 
          run(coins, nextAmount, ans, layer + times, index+1);
      }
      //if(ans != -1) return;
      for(int i = 1; i<=times;i++){
        if(index<size-1)
          run(coins, nextAmount+i*coins[index], ans, layer+times-i, index+1);
      }
      
  
    }
    else{
      if(index<size-1)
          run(coins, amount, ans, layer, index+1);
    }
      
  
        
        return;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int ans = -1;
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        //cout<<coins[0];
        run(coins, amount, ans, 1, 0);
        return ans;
    }
};
*/
 


/*
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>> > heap;
        unordered_map<long long, bool> map;
        vector<int> temp = primes;
        for(int i = 0; i<primes.size(); ++i){
            heap.push(make_pair(primes[i],make_pair(i,0)));
            map[primes[i]] = true;
        }
        
        vector<int>dp(1,1);
        
        while(dp.size()<n){
            dp.push_back(heap.top().first);
            long long temNum = heap.top().first;
            //cout<<temNum;
            int index = heap.top().second.second;
            int Indexp = heap.top().second.first;
            //cout<<index<<Indexp<<endl;
            heap.pop();
            index++;
            while(map.find(primes[Indexp]*dp[index]) != map.end())
                index++;
            heap.push(make_pair(primes[Indexp]*dp[index], make_pair(Indexp, index)));
            map[primes[Indexp]*dp[index]] = true;
        }

        return dp[n-1];
    }
};
*/ 

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> p2 = primes;
        vector<int> dp(n, 0);
        vector<int> p3 = dp;
        dp[0] = 1;
        
        for(int i = 1 ;i<dp.size();i++){
            int min = *min_element(p2.begin(), p2.end());
            int dis = distance(p2.begin(), find(p2.begin(), p2.end(), min));
            dp[i] = min;
            p3[dis]++;
            //cout<<dis<<" "<<primes[dis]<<" "<<primes[dis]*dp[p3[dis]]<<endl;
            while(find(p2.begin(), p2.end(), primes[dis]*dp[p3[dis]]) != p2.end()){
                p3[dis]++;
            }
            p2[dis] = primes[dis]*dp[p3[dis]];
            //cout<<dp[i]<<endl;
            //cout<<p2[dis]<<" 1"<<endl;
        }
        
 
        return dp[n-1];
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