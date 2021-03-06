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

//99.13
  class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size());
        
        for(int i = 0; i<graph.size(); ++i){
            if(graph[i].size() != 0 && visited[i] == 0){
                visited[i] = 1;
                queue<int> que;
                que.push(i);
                while(!que.empty()){
                    int current = que.front();
                    int nextColor = visited[current] == 1 ? 2 : 1;
                    
                    for(int next : graph[current]){
                        if(visited[next] == 0){
                            visited[next] = nextColor;
                            que.push(next);
                        }
                        else{
                            if(visited[next] != nextColor)
                                return false;
                        }
                    }
                    que.pop();
                }
            }
        }

        return true;
    }
};

int main(){
	vector<int> input = {{0,1,2,2,0,2,1,0,2,0,1,1,1,2,2,1}};
	//{{1,3,5}};
	//{{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
	//{{1}};
	//{{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};

	sortColors(input);
	PrintItvector(input);
	return EXIT_SUCCESS;
}