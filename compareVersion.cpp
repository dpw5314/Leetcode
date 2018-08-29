#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<sstream>
#include<math.h>
#include<climits>
#include<stack>
#include <sstream>
#include <unordered_map>


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

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
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
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss(version1), ss1(version2);
        string s1, s2;
        double i1, i2;
        s1 = s2 = "";
        while(1){
        	getline(ss, s1, '.'); getline(ss1, s2, '.');
        	if(s1 == "" and s2 == "") break;
        	s1 = s1=="" ? "0" : s1;
        	s2 = s2=="" ? "0" : s2;
        	//cout<<s1<<" "<<s2<<endl;
            stringstream ss2(s1), ss3(s2);
            ss2>>i1; ss3>>i2;
            if(i1>i2) return 1;
            else if(i2>i1) return -1;
            s1 = s2 = "";            
        }
        return 0;
    }
};*/


class Solution {
public:
    int compareVersion(string version1, string version2) {
    	int size = version1.size() > version2.size()? version1.size():version2.size();
    	for(int i=0; i<size; ++i){
    		if(i<version1.size() and i < version2.size()){
    			if(version1[i] == '.') version1[i] = '';
    			if(version2[i] == '.') version2[i] = '';
    		}
    		else if (i<version1.size())
    			if(version1[i] == '.') version1[i] = '';
    		else if (i<version2.size())
    			if(version2[i] == '.') version2[i] = '';
    	}
    	cout<<version1<<version2;
        stringstream ss(version1), ss1(version2);
        
        return 0;
    }
};

int main(){
	string s = "1", s2 = "1.0";
	//{"15", "7", "1", "1", "+", "−", "÷", "3", "×", "2", "1", "1", "+", "+" ,"−"};
	//{"2", "1", "+", "3", "*"};
	Solution *b = new Solution();
	int ans = b->compareVersion(s,s2);

	cout<<ans;
	cout<<endl;

	return EXIT_SUCCESS;
}