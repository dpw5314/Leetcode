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

    

    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return -1;
        else if (size==1) return nums[0];

        int index1 = 0, index2 = size-1;
        while(index2 > index1){
        	if(index1+1 < size){
        		if(nums[index1+1] >= nums[index1]) index1++;
        		else return nums[index1+1];
        	}
        	if(index2-1 >= 0){
        		if(nums[index2-1] <= nums[index2]) index2--;
        		else return nums[index2];
        	}
        }
        return nums[0];
    }

int main(){
	vector<int> vec = {1,2,3};
	//{3,5,7,0,1,2};
	//{3,1};
	int ans = findMin(vec);
    cout<<ans;

	return EXIT_SUCCESS;
}