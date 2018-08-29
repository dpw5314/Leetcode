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
  int combination (int a){
  	if (a<3) return a;
  	else{
  		int num;
  		vector<int> tem = {1,2};
  		for(int i = 1; i<a; ++i){
  			num = tem[i] + tem[i-1];
  			tem.push_back(num);
  		}
  		return tem[a-1];
  	}

  }

  void multiply(vector<int>& vec, int size, string& s, long& ans){
  	if(size == 0){
  		ans += numDecodings(s);
  		return;
  	}
  	for(int i = 1; i<=9; ++i){
  		s[vec.size()-size] = i + '0';
  		multiply(vec, size-1, s, ans);
  	}

  	return;
  	
  }
    int numDecodings(string s) {
    	int limit = 1000000007;
    	int size = s.size();
    	int ans = 1, temp, temp1 = 0, length = 1;
        if(size == 0) return 0;
        else if (size == 1) {
        	if (s == "0") return 0;
        	else if (s == "*") return 9;
        	else return 1;
        } 
        else if (s[0] == '0') return 0;

        for(int i = size-1; i>0; --i){
        	stringstream s1(s.substr(i-1, 2));
        	s1>>temp;
        	if(s[i] == '0' and s[i-1] == '0') return 0;
        	else if (s[i]=='0') {
        		temp = s[i-1] - '0';
        		if(temp > 2) return 0;
        		else{
        			i--;
        		}
        	}
        	else if (s[i-1] == '0') {
        		ans *= combination(length);
        		length = 1;
        		}
        	else if(temp > 26) {
        		ans *= combination(length);
        		length = 1;
        	}
        	else length++;
        	if(i == 1) ans *= combination(length);
        }
        return ans;
    }


int main(){
	string a = "1*11";
	int ans = numDecodings(a);
	cout<<ans;
	return EXIT_SUCCESS;
}