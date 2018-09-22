#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <math.h>
#include <climits>
#include <sstream>
#include <set>


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


//16
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(0);
        
        for(int i = 0; i<lists.size(); ++i){
            dummy->next = merge(dummy->next, lists[i]);
        }
        
        return dummy->next;
    }
    
    ListNode *merge(ListNode* l1, ListNode *l2){
        if(l1 == nullptr)
            return l2;
        
        ListNode *temp = new ListNode(0);
        ListNode *head = temp;
        
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
            }
            else{
                head->next = l2;
                l2 = l2->next;
            }
            
            head = head->next;
        }
        
        if(l1 != nullptr)
            head->next = l1;
        else if(l2 != nullptr)
            head->next = l2;
        
        return temp->next;
    }
};

//99
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;        
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        
        
        for(int i=0; i<lists.size(); ++i){
            if(lists[i] != nullptr)
                pq.push(lists[i]);
        }
        
        if(pq.size() == 0)
            return dummy->next;
        
        while(pq.size()>1){
            ListNode *temp = pq.top();
            //cout<<temp->val<<endl;
            pq.pop();
            head->next = temp;
            head = head->next;
            temp = temp->next;
            if(temp != nullptr)
                pq.push(temp);
        }
        
        head->next = pq.top();
        
        return dummy->next;
    }
    
    struct comp{
        bool operator()(ListNode* a, ListNode *b){
            return a->val > b->val;
        }
    };
};


int main(){
	Solution a;
	vector<pair<int, int>> vec = {{0, 5}, {15,20}, {5,10}};

	int ans = a.meetingroom(vec);

	cout<<ans<<endl; 

	return EXIT_SUCCESS;
}