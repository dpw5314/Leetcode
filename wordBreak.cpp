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
#include <unordered_map>

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

class Solution {
public:
    bool Break(vector<string>& wordDict, string s, unordered_map<string, bool>& map, int layer){
    	bool temp = 0, temp1;
    	if(map.find(s) != map.end())
    		return map[s];
    	else if(find(wordDict.begin(), wordDict.end(), s)!= wordDict.end()){
    		map[s] = true;
    		return map[s];
    	}
    	for(int i = s.size()-1; i>=0; --i){
    		string s1 = s.substr(i), s2 = s.substr(0,i);
			if (map.find(s1) == map.end() and find(wordDict.begin(), wordDict.end(), s1)!= wordDict.end()){
				//cout<<"happend";
    			map[s1] = true;
			}
    		else if (map.find(s1) == map.end() and find(wordDict.begin(), wordDict.end(), s1)== wordDict.end())
    			map[s1] = false;
    		//bool tem3 = Break(wordDict, s2, map, layer+1) , tem4= map[s1];
    		temp1 = Break(wordDict, s2, map, layer+1) and map[s1]
    		temp = temp or temp1;
    		//cout<<layer<<" "<<s1<<" "<<s2<<" "<<tem4<<" "<<tem3<<endl;
    	}
    	//cout<<temp<<" "<<s<<" "<<layer<<endl;
    	map[s] = temp;
        return map[s];
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string, bool> map;
        if(find(wordDict.begin(), wordDict.end(), s)!= wordDict.end())
            return true;
        return Break(wordDict, s, map, 0);
    }
};

    
int main(){
	Solution a;
	string s = {"aaaaaaa"};
	//{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
	//{"abcd"};
	//{"aaaaaaa"};;
	vector<string> wordDict = {"aaaa","aaa"};
	//{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	//{"a","abc","b","cd"};
	//{"aaaa","aaa"};
	bool ans = a.wordBreak(s, wordDict);
	cout<<ans;

	return EXIT_SUCCESS;
}