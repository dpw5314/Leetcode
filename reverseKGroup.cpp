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


//57
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = head;
        dummy->next = head;
        int count = 1;
        while(count <= k){
            if(temp == nullptr)
                return head;
            temp = temp->next;
            count++;
        }
        
        count = 1;
        while(count < k ){
            ListNode* l1 = head->next;
            ListNode *l2 = head->next->next;
            l1->next = dummy->next;
            head->next = l2;
            dummy->next = l1;
            count++;
        }
        head->next = reverseKGroup(head->next, k);
        return dummy->next;
    }
};


int main(){
	Solution a;
	string s = "the sky is blue";

	a.reverseWords(s);

	cout<<s<<endl; 

	return EXIT_SUCCESS;
}