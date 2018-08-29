#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <math.h>
#include <climits>
#include <sstream>
#include <stack>


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

string simplifyPath(string path) {

        istringstream input(path);
        string ans, temstring;
        stack<string> temp;

        while(getline(input, temstring, '/')){
        	
        	if(temstring == "." or temstring == "") continue;
        	else if(temstring == ".." and !temp.empty()) temp.pop();
        	else if(temstring == ".." and temp.empty()) continue;
        	else temp.push(temstring);
        }

        if(temp.empty()) {
        	ans = "/";
        	return ans;
        }

        while(!temp.empty()){
        	ans = "/" + temp.top() + ans;
        	temp.pop();
        }

        
        return ans;
    }
/*

string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    istringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(int i = 0; i<stk.size(); i++) res += "/"+stk[i];
    return res.empty() ? "/" : res;
}
*/
int main(){
	string path = "/home/...", ans;
	ans = simplifyPath(path);
	cout<<ans;

	return EXIT_SUCCESS;
}
