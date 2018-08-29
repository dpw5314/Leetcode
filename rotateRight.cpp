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


    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ans = new ListNode(0);
        if(!head or k == 0) return head;
        ListNode* index = new ListNode(0);
        ListNode* index1 = new ListNode(0);
        ListNode* index2 = head;
        index->next = head;
        index1->next = head;
        int length = 1;
        while(index2->next != NULL){
        	index2 = index2->next;
        	length++;
        }
        k = k%length;
        if(k == 0) return head;

        int moving = 0;
        
        for(int i =0; i<k; i++){
        	index = index->next;
        }
        
    
        
        while(index->next != NULL){
            index = index->next;
            index1 = index1->next;
            moving++;
        }
        index1 = index1->next;
        ans->next = index1;
        index2 = index1;
        while(index2->next != NULL){
            index2 = index2->next;
        }
        ListNode* index3 = new ListNode(0);
        index3->next = head;
        index2->next = index3->next;
        for(int i = 0; i<moving; i++){
            index3 = index3->next;
        }
        index3->next = NULL;
        

        return ans->next;
    }


int main(){
	vector<int> a = {1,2,3,4,5};
	ListNode* head = new ListNode(a[0]);
	ListNode* tail = head;
	ListNode* ans;
	int target = 2;

	for(int i = 1; i<a.size(); i++){
		ListNode* tail1 = new ListNode(a[i]);
		tail->next = tail1;
		tail = tail->next;


	}

	ans = rotateRight(head, target);
	while(ans){
		cout<<ans->val<<" ";
		ans=ans->next;
	}
	cout<<endl;

	return EXIT_SUCCESS;
}
