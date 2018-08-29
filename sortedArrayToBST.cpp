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

    
    void build(TreeNode* ans, vector<int>& nums, int curIndex, int min){
        if(curIndex >= min and curIndex<nums.size()) {
            if(nums[curIndex] < ans->val) {                
                vector<int> temp(nums.begin()+min, nums.begin()+curIndex+1);
                curIndex = temp.size()/2;
                ans->left = new TreeNode(temp[curIndex]);
                build(ans->left, temp, curIndex-1, 0);
                build(ans->left, temp, temp.size()-1, curIndex + 1);
            }
            else{
                vector<int> temp1(nums.begin()+min, nums.begin()+curIndex+1);
                //cout<<temp1[0];
                curIndex = temp1.size()/2;
                ans->right = new TreeNode(temp1[curIndex]);
                build(ans->right,  temp1, curIndex-1, 0);
                build(ans->right, temp1, temp1.size()-1, curIndex + 1);
            }
        }
        return;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans = NULL;
        int med = nums.size();
        if(med == 0) return ans;
        else if (med ==1){
            ans = new TreeNode(nums[0]);
            return ans;
        }
        else{
            med = med/2;
            ans = new TreeNode(nums[med]);
            build(ans,nums, med-1, 0);
            build(ans, nums, nums.size()-1, med+1);
            return ans;
        }
        
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