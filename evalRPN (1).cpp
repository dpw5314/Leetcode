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


//15
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	stack<int> test;
    	int temp;
    	int size = tokens.size();
    	for(int i = 0; i<size; i++){
    		stringstream ss(tokens[i]);
    		ss>>temp;
    		if(!ss.fail()){
    			test.push(temp);
    		}
    		else{
    			int temp1, temp2;
    			temp1 = test.top();
    			test.pop();
    			temp2 = test.top();
    			test.pop();
    			if(tokens[i] == "+")
    				temp2 += temp1;
    			else if (tokens[i] == "-")
    				temp2 -= temp1;
    			else if(tokens[i] == "*")
    				temp2 *= temp1;
    			else if(tokens[i] == "/")
    				temp2 /= temp1;
    			test.push(temp2);
    		}
    	}
        return test.top();
    }
};

//100
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> test;
        int temp;
        int size = tokens.size();
        for(int i = 0; i<size; i++){
            if(tokens[i] == "+"){
                temp = test.top();
                test.pop();
                test.top() = test.top()+temp;
                
            }
            else if(tokens[i] == "-"){
                temp = test.top();
                test.pop();
                test.top() = test.top()-temp;
            }
            else if(tokens[i] == "*"){
                temp = test.top();
                test.pop();
                test.top() = test.top()*temp;
            }
            else if(tokens[i] == "/"){
                temp = test.top();
                test.pop();
                test.top() = test.top()/temp;
            }
            else{
                test.push(stoi(tokens[i]));
            }
            //cout<<test.top()<<endl;
        }
        return test.top();
    }
};

int main(){
	vector<string> string = {"3","-4","+"};
	//{"15", "7", "1", "1", "+", "−", "÷", "3", "×", "2", "1", "1", "+", "+" ,"−"};
	//{"2", "1", "+", "3", "*"};
	Solution *b = new Solution();
	int ans = b->evalRPN(string);

	cout<<ans;
	cout<<endl;

	return EXIT_SUCCESS;
}