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
unordered_map<RandomListNode*, RandomListNode*> map;
public:
    RandomListNode* Copy(RandomListNode *head){
    	if(map.find(head)!= map.end()){
    		return map[head];
    	}
    	int a = head->label;
    	RandomListNode* clone = new RandomListNode(a);
    	map[head] = clone;

        if(head->next != nullptr)
        	clone->next = Copy(head->next);
        
        if(head->random != nullptr)
        	clone->random = Copy(head->random);
        return clone;
    }
	
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* dummy;
        if(head != nullptr) {
        	return Copy(head);
        }
        return NULL;
    }
};

int main(){
	vector<int> a = {1,1};
	RandomListNode* head = new RandomListNode(a[0]);
	RandomListNode* tail = head;
	RandomListNode* ans;

	for(int i = 1; i<a.size(); i++){
		RandomListNode* tail1 = new RandomListNode(a[i]);
		tail->next = tail1;
		tail = tail->next;


	}
	Solution *b = new Solution();
	ans = b->copyRandomList(head);

	while(ans){
		cout<<ans->label<<" ";
		ans=ans->next;
	}
	cout<<endl;

	return EXIT_SUCCESS;
}