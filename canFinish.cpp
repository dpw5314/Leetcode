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
  //16
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        bool ans = 1;
        vector<int> totalNum;
        unordered_map<int, int> map;
        queue<int> temp;
        for(int i=0; i < numCourses; ++i){
          map[i] = 0;
        }
        for(int i=0; i < prerequisites.size(); ++i){
          map[prerequisites[i].first] += 1;
        }
        for(int i=0; i < numCourses; ++i){
          if(map[i] == 0){
            temp.push(i);
          }
        }

        while(!map.empty()){
          if(temp.empty()) return 0;
          queue<int> temp1;
          while(!temp.empty()){
            map.erase(temp.front());
            for(int j = 0; j < prerequisites.size(); ++j){
              if(prerequisites[j].second == temp.front()){
                map[prerequisites[j].first]--;
                if(map[prerequisites[j].first] == 0) temp1.push(prerequisites[j].first);
              }
            }
            temp.pop();
          }
          temp = temp1;
        }
        return 1;
    }
};

//99 DFS
class Solution {
public:
    vector<vector<int>> G;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        G.resize(numCourses);
        Ving.clear(); Ved.clear();
        for(auto ele : prerequisites)
            G[ele.second].push_back(ele.first);
        for(int i=0; i<numCourses; ++i)
            if(!dfs(i))
                return false;
        return true;
    }
    
private:
    unordered_set<int> Ving, Ved;
    bool dfs(int i){
        if(Ved.find(i) != Ved.end())
            return true;
        Ving.insert(i);
        for(auto ele : G[i])
            if(Ving.find(ele) != Ving.end() || !dfs(ele))
                return false;
        Ving.erase(i);
        Ved.insert(i);
        return true;
    }
};
//99 BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        queue<int> q;
        int cnt = 0;
        vector<vector<int>> G(numCourses); vector<int> D(numCourses);
        for(auto ele :  prerequisites){
            G[ele.second].push_back(ele.first);
            ++D[ele.first];
        }
        
        for(int i = 0; i<numCourses; ++i){
            if(D[i] == 0)
                q.push(i);
        }
        
        for(; !q.empty(); cnt++){
            int CurNum = q.front(); q.pop();
            for(auto ele : G[CurNum]){
                if(--D[ele] == 0)
                    q.push(ele);
            }
        }
        
        return cnt==numCourses;
    }
};

int main(){
	Solution a;
	vector<pair<int,int>> pair = {{1,0},{0,2}};
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
	bool ans = a.canFinish(3,pair);
	cout<<ans;
	return EXIT_SUCCESS;
}