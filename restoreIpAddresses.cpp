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

  void BT(string& s, string temp, vector<string>& ans, int size, int curSize, int curIndex, int dotNum){
  	stringstream s1;
  	string temString;
  	int temNum;
  	if(dotNum == 3){
  		if(size - curIndex > 3) return;
  		else {
  			temString = s.substr(curIndex, size-curIndex);
  			if(temString.size()>1 and temString[0] == '0') return;
  			stringstream s1(temString);
  			s1>>temNum;
  			if(temNum > 255) return;
  			else {
  				temp += temString;
  				ans.push_back(temp);
  				return;
  			}
  		}
  	}
  	else{
  		for(int i = curSize; i<=3 ; ++i){
  			if(curIndex + i < size){
  				temString = s.substr(curIndex, i);
  				if(temString.size()>1 and temString[0] == '0') return;
  				stringstream s1(temString);
  				//cout<<dotNum<<" "<<temString<<endl;
  				s1>>temNum;
  				if(temNum <= 255){
  					temp += temString + ".";
  					//cout<<temp;
  					BT(s, temp, ans, size, curSize, curIndex + i, dotNum+1);
  					temp.erase(curIndex+dotNum,i+1);
  				}
  				else return;
  			}
  			else
  				return;
  			
  		}
  	}
  	return;
  }

    vector<string> restoreIpAddresses(string s) {
        int size = s.size();
        int dotNum;
        vector<string> ans;
        string temp;
        BT(s, temp, ans, size, 1, 0 , 0);
        return ans;
    }


int main(){
	string s = "172162541";
	vector<string> ans;
	ans = restoreIpAddresses(s);
	PrintItvector(ans);

	return EXIT_SUCCESS;
}