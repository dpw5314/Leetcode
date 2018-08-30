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
unordered_map<UndirectedGraphNode*, vector<UndirectedGraphNode *>> map;
unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map1;
public:
    vector<UndirectedGraphNode *> copyVector(UndirectedGraphNode *node, UndirectedGraphNode *node1){
        vector<UndirectedGraphNode *> neighbors1;
        for(int i=0; i<node->neighbors.size(); i++){
        	if(node->neighbors[i] == node)
        		neighbors1.push_back(node1);
        	else{
        		if(map1.find(node->neighbors[i]) != map1.end())
        			neighbors1.push_back(map1[node->neighbors[i]]);
        		else{
             		UndirectedGraphNode* node2 = cloneGraph(node->neighbors[i]);
            		neighbors1.push_back(node2);         			
        		}
      		
        	}

        }
        return neighbors1;
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        UndirectedGraphNode* node1 = new UndirectedGraphNode(node->label);
        if(map.find(node) != map.end()){
            node1->neighbors = map[node];
        }
        else {
            node1->neighbors = copyVector(node, node1);
            map[node] = node1->neighbors;
            map1[node] = node1;
        }
        return node1;
    }
};



class Solution {
unordered_map<int, UndirectedGraphNode*> map;
    
public:
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr)
            return node;
        
        if(map.find(node->label) != map.end())
            return map[node->label];
        
        UndirectedGraphNode* node1 = new UndirectedGraphNode(node->label);
        map[node->label] = node1;
        for(int i = 0; i<node->neighbors.size(); ++i){
            node1->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return node1;
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