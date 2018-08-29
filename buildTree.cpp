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

    
    void Build( TreeNode* ans, int pindex, int iindex, int MinBoundary, int MaxBoundary, vector<int>& preorder, vector<int>& inorder){
        int temp;
        int size = preorder.size();
        
        for(int i = pindex; i<size; i++){
            temp = preorder[i];
            for(int j = MinBoundary; j<iindex;j++){                
                if(inorder[j] == temp) {
                    //cout<<"left:"<<inorder[j]<<" "<<temp<<endl;
                    ans->left = new TreeNode(temp);
                    Build(ans->left, i, j, MinBoundary, iindex, preorder, inorder);
                    pindex = i;
                    i = size;
                    break;
                 }
        }
     }
        for(int i = pindex; i<size; i++){    
            temp = preorder[i];
            for(int j = iindex+1; j<MaxBoundary;j++){  
                //cout<<"right:"<<inorder[j]<<" "<<temp<<endl;
                if(inorder[j] == temp) {          
                    //cout<<"right:"<<inorder[j]<<" "<<temp<<endl;
                    ans->right = new TreeNode(temp);
                    Build(ans->right, i, j, iindex, MaxBoundary, preorder, inorder);
                    i = size;
                    break;
                }
                
            }
        }
        return;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size1 = preorder.size(), size2 = inorder.size();
        TreeNode* ans;
        if(size1 != size2) return nullptr;
        else if(size1 == 0) return nullptr;
        else if(size1 == 1){
            ans = new TreeNode(preorder[0]);
            return ans;
        }
        else{
            int index2 = 0;
            while(index2 < size2){
                if(inorder[index2] == preorder[0]) break;
                index2++;
            }
            ans = new TreeNode(preorder[0]);
            Build(ans, 0, index2, 0, size1, preorder, inorder);
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