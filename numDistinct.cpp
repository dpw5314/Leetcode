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

  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

void PrintUndirectedGraph(UndirectedGraphNode* node){
	if(node)
		cout<<node->label<<" ";
	int size = node->neighbors.size();
	for(int i = 0; i<size; i++){
		cout<<node->neighbors[i]->label<<" ";
	}
	if(size>0) cout<<"# ";

	for(int i = 0; i<size; i++){
		if(node->neighbors[i] != node)
			PrintUndirectedGraph(node->neighbors[i]);
	}	
}

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


class Solution {
public:
    int numDistinct(string s, string t) {
    	int size1 = s.size(), size2 = t.size();
        vector<vector<int>>	 dp(size1+1, vector<int>(size2+1, 0));
        for(int i = 0; i<=size1; i++){
        	dp[i][0] = 1;
        }
        for(int i = 1; i<=size1; ++i){
        	for(int j = 1; j<=size2; ++j){
        		if(s[i-1] != t[j-1])
        			dp[i][j] = dp[i-1][j];
        		else
        			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        	}
        }
        return dp[size1][size2];  
    }
};
/*
class Solution {
public:
    void Run(string s, string t, int index, int index1, int& ans){
        for(int j= index1; j<s.size();j++){
            if(t[index] == s[j]){
            	//cout<<t[index]<<" "<<index<<" "<<j<<endl;
                if(index == t.size()-1) 
                	ans++;
                else
                    Run(s,t,index+1,j+1, ans);
            }
        }
        
        return;
    }
    int numDistinct(string s, string t) {
        int ans = 0;
        Run(s, t, 0, 0, ans);
        return ans;  
    }
};
*/
int main(){
	string a = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";

	//"rabbbit";
	string aa = "bddabdcae";
	//"rabbit";++++++++++
	int ans;

	Solution *b = new Solution();
	ans = b->numDistinct(a, aa);

	cout<<ans;
	//PrintUndirectedGraph(head1);
	//PrintUndirectedGraph(head2);
	cout<<endl;

	return EXIT_SUCCESS;
}