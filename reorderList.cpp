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
public:
    void reorderList(ListNode* head) {
        ListNode* dummy = head;
        int size = 0;
        while(dummy != nullptr){
            dummy = dummy->next;
            size++;
        }
        if(size<=2) return;
        dummy=head;
        int end = size-1, start = 1;

        while(start < end){
            ListNode* t1 = dummy;
            int diff = end-start;            
            while(diff>0){
                t1 = t1->next;
                diff--;
            }
            ListNode* t2 = t1->next;
            t2->next = dummy->next;
            t1->next = NULL;
            dummy->next = t2;
            start += 2;
            dummy = dummy->next->next;
        }

        return;
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