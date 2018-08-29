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

  /*
    int combination (int a, int b){
      if(b == 1) return a;
      else if (b == 0) return 1;
      int max = b > a-b ? b : a-b;
      long sum1 = 1;
      int sum2 = 1;
      for(int i = max+1; i<a; ++i){
        sum1 *= i;
      }
      for(int i = 1; i< a-max; ++i){
        sum2 *= i;
      }

      return sum1/sum2;
    }
*/

    void build(TreeNode* ans, ListNode* head, int length){
        if(length == 1) ans->val = head->val;
        else if (length > 1){
            int templength = length/2 + 1;
            ListNode* dummy = new ListNode(0);
            ListNode* dummy1 = new ListNode(0);
            dummy->next = head;
            dummy1->next = head;
            head = dummy;
            
            while(templength > 1){
                head = head->next;
                templength--;
            }
            //cout<<head->next->val;
            if(ans->val) {
                TreeNode* temp =  new TreeNode(head->next->val);
                ans = temp;
            }
            else ans->val = head->next->val;
            templength = length/2 + 1;
            dummy1->next = head->next->next;
            head->next = NULL;
            //cout<<templength - 1<<" "<<length - templength<<endl;
            if(templength - 1 > 0) {
                ans->left = new TreeNode(0);
                build(ans->left, dummy->next, templength - 1);
            }
                
            if(length - templength > 0) 
                ans->right = new TreeNode(0);
                build(ans->right, dummy1->next, length - templength);
        }
        return;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* ans = NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int length = 0;
        while(dummy->next){
            dummy = dummy->next;
            length++;
        }
        if(length == 0) return ans;
        else {
             ans = new TreeNode(NULL);
            build(ans, head, length);
        } 
        return ans;
        
    }
    
int main(){
	vector<int> vec = {3,3,3,3,5,5,5,7,7,7,0,1,1,2,2};
  //{3,1};
	//{3,5,7,0,1,2};
	int a = 6;
	bool ans = search(vec, a);
    cout<<ans;

	return EXIT_SUCCESS;
}