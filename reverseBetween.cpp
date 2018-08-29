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

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* dummy1 = new ListNode(0);
        dummy->next = head;
        head = dummy;
        int tem = m;
        while(tem>1){
            head = head->next;
            tem--;
        }
        while(n>m){
            tem = n-m;
            ListNode* n1 = head->next;
            ListNode* temp = n1->next;
            
            ListNode* n2 = n1;
            if(tem > 1){
                while(tem>1){
                    n2 = n2->next;
                    tem--;
                }
                
                ListNode* temp1 = n2->next;
                head->next = temp1;
                n1->next = temp1->next;
                n2->next = n1;
                temp1->next = temp;
            }
            else {
                n2 = n2->next;
                head->next = n2;
                n1->next = n2->next;
                n2->next = n1;
            }
            head = head->next;
            m++; n--;
        }

        return dummy->next;
    }


int main(){
	vector<int> a = {1,2,3,4,5,6};
	ListNode* head = new ListNode(a[0]);
	ListNode* tail = head;
	ListNode* ans;
    int m = 2, n =6;

	for(int i = 1; i<a.size(); i++){
		ListNode* tail1 = new ListNode(a[i]);
		tail->next = tail1;
		tail = tail->next;


	}

	ans = reverseBetween(head, m, n);
	while(ans){
		cout<<ans->val<<" ";
		ans=ans->next;
	}
	cout<<endl;

	return EXIT_SUCCESS;
}