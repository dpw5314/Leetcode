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
unordered_map<ListNode*, bool> map;
public:
    bool hasCycle(ListNode *head) {
        if(map.find(head) != map.end()){
            return map[head];
        }
        else if (head == NULL)
            return false;
        else if (!head)
            return false;
        map[head] = true;
        return hasCycle(head->next);
    }
};

int main(){
	//vector<int> a = {1,1};
	UndirectedGraphNode* head = new UndirectedGraphNode(0);
	UndirectedGraphNode* head1 = new UndirectedGraphNode(1);
	UndirectedGraphNode* head2 = new UndirectedGraphNode(2);
	//UndirectedGraphNode* head2 = new UndirectedGraphNode(3);
	UndirectedGraphNode* ans;


	//head->neighbors.push_back(head);
	//head->neighbors.push_back(head);
	
	head->neighbors.push_back(head1);
	head->neighbors.push_back(head2);
	head1->neighbors.push_back(head2);
	head2->neighbors.push_back(head2);
	

	Solution *b = new Solution();
	ans = b->cloneGraph(head);

	PrintUndirectedGraph(ans);
	//PrintUndirectedGraph(head1);
	//PrintUndirectedGraph(head2);
	cout<<endl;

	return EXIT_SUCCESS;
}