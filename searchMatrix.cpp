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

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return 0;
        else if(matrix[0].size() == 0) return 0;
        int size1 = matrix.size(), size2 = matrix[0].size();
		
		if(target< matrix[0][0] or target > matrix[size1-1][size2-1]) return 0;
        //locate row
        int size = size1/2;
        int lowerbound = 0;
        while(lowerbound + size>lowerbound and size + lowerbound <size1){
            if(target < matrix[lowerbound+size][0]) size /= 2;
            else if(target == matrix[lowerbound + size][0]) return 1;
            else {
                lowerbound += size;
                size = size/2 == 0 ? 1 : size/2;
            }
        }
        size = lowerbound;
        int size3 = size2/2;
        lowerbound = 0;
        while(size3 + lowerbound>lowerbound and size3 + lowerbound<size2){
            if(target<matrix[size][lowerbound + size3]) size3 /= 2;
            else if (target == matrix[size][lowerbound+size3]) return 1;
            else {
            	lowerbound += size3;
            	size3 = size3/2 == 0? 1 : size3/2;
            }
        }
        size3 = lowerbound;
        //cout<<size<<" "<<size3<<endl;
        return matrix[size][size3] == target;
    }


int main(){
	vector<vector<int>> input = {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
	//{{1,3,5}};
	//{{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
	//{{1}};
	//{{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};

	int target;
	cin>>target;
	bool ans = searchMatrix(input, target);
	cout<<ans;
	return EXIT_SUCCESS;
}