#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<sstream>
#include<math.h>
#include<climits>
#include<stack>
#include <sstream>
#include <unordered_map>


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

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
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

//23.84
class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        queue<pair<int, int>> q;
        unordered_map<int, int> map;
        int longest = 0;
        map[K] = 0;
        for(int i = 0; i<times.size();i++){
            if(times[i][0] == K){
                q.push(make_pair(times[i][1], times[i][2]));
                map[times[i][1]] = times[i][2];
            }
        }
        
        while(!q.empty()){
            queue<pair<int, int>> temp;
            for(; !q.empty(); q.pop()){
                int Num = q.front().first;
                //cout<<Num<<endl;
                for(int i = 0; i<times.size();i++){
                    if(times[i][0] == Num){
                        //cout<<times[i][1]<<endl;
                        if((map.find(times[i][1]) != map.end() && times[i][2]+q.front().second < map[times[i][1]] )
                          || map.find(times[i][1]) == map.end() ){
                            temp.push(make_pair(times[i][1], times[i][2]+q.front().second));
                            map[times[i][1]] =  times[i][2]+q.front().second;
                        }  

                    }
                }
            }
            std::swap(temp, q);  
            //cout<<longest<<endl;
        }
        if(map.size() != N)
            return -1;
        else{
            for(auto it : map){
                //cout<<it.first<<"->"<<it.second<<endl;
                if(it.second> longest)
                    longest = it.second;
            }
            return longest;
        }

    }
};

//25
class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        queue<pair<int, int>> q;
        unordered_map<int, int> map;
        int longest = 0;
        map[K] = 0;
        for(int i = 0; i<times.size();i++){
            if(times[i][0] == K){
                q.push(make_pair(times[i][1], times[i][2]));
                map[times[i][1]] = times[i][2];
            }
        }
        
        while(!q.empty()){
            queue<pair<int, int>> temp;
            for(; !q.empty(); q.pop()){
                int Num = q.front().first;
                //cout<<Num<<endl;
                for(int i = 0; i<times.size();i++){
                    if(times[i][0] == Num){
                        //cout<<times[i][1]<<endl;
                        if((map.find(times[i][1]) != map.end() && times[i][2]+q.front().second < map[times[i][1]] )
                          || map.find(times[i][1]) == map.end() ){
                            temp.push(make_pair(times[i][1], times[i][2]+q.front().second));
                            map[times[i][1]] =  times[i][2]+q.front().second;
                        }  

                    }
                }
            }
            std::swap(temp, q);  
            //cout<<longest<<endl;
        }
        if(map.size() != N)
            return -1;
        else{
            set<int> se1;
            for(auto it : map){
                se1.insert(it.second);
            }
            return *se1.rbegin();
        }

    }
};
//bellman 97
class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int max_value = 101*100;
        vector<int> dp(N, max_value);
        dp[K-1] = 0;
        for(int i =0; i<N; ++i){
            for(const auto & time : times){
                int u = time[0]-1, v = time[1]-1, w = time[2];
                dp[v] = min(dp[v], dp[u] + w);
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        return ans == 101*100 ? -1 : ans;
    }
};

int main(){
	vector<string> string = {"3","-4","+"};
	//{"15", "7", "1", "1", "+", "−", "÷", "3", "×", "2", "1", "1", "+", "+" ,"−"};
	//{"2", "1", "+", "3", "*"};
	Solution *b = new Solution();
	int ans = b->evalRPN(string);

	cout<<ans;
	cout<<endl;

	return EXIT_SUCCESS;
}