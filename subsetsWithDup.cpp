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
    void choose (vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int index, int size, bool flag){
        for(int i = index; i < size; ++i){
        	//cout<<i<<" "<<flag<<", length"<<temp.size()<<" ";
            if(flag and i>0 and nums[i-1] == nums[i]){
            	continue;
            }
            else{
            	flag = 0;
                temp.push_back(nums[i]);
                ans.push_back(temp);
                //PrintItvector(temp);
                choose(nums, ans, temp, i+1, size, flag);
                temp.pop_back();    
                
            }
            flag = 1;
            //cout<<endl;
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int size = nums.size();
        ans.push_back(temp);
        if(size == 0) return ans;
        choose(nums, ans, temp, 0, size, 0);
        return ans;
    }



int main(){
	vector<int> input = {4,4,1,4};
	vector<vector<int>> ans;
	//{{1,3,5}};
	//{{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
	//{{1}};
	//{{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};

	ans = subsetsWithDup(input);
	PrintItvector(ans);
	return EXIT_SUCCESS;
}