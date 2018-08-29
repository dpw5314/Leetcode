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

//100
class Solution {
public:
    string reorganizeString(string S) {
        int size = S.size();
        if(size == 0)
            return "";
        unordered_map<char, int> map;
        for(auto ch : S)
            map[ch]++;
        multiset<pair<int, char> > set;
        for(auto ele:map)
            set.insert(make_pair(ele.second, ele.first));
  /*      
        for(auto ele :set)
            cout<<ele.first<<" "<<ele.second<<endl;*/
        
        auto it = set.rbegin();

        if(it->first > size- it->first+1)
            return "";
        else{
            string ans = "";
            auto it1 = ++set.rbegin();
            int Max = it->first, Min = it1->first;
            char ch1 = it->second, ch2 = it1->second;
            while(Max > 0){
                ans.push_back(ch1);
                if(Min-- > 0){                    
                    ans.push_back(ch2);
                }
                else{

                    if(++it1 != set.rend()){
                        Min = it1->first;
                        ch2 = it1->second;
                        Min--;
                        ans.push_back(ch2);                      
                    }
                }
                Max--;
            }
            int i = 0;
            while(it1 != set.rend() || Min >0){
                if(Min>0){
                    if(i > ans.size())
                        i=0;
                    if((i-1 >= 0 && ans[i-1] == ch2 )|| ans[i] == ch2)
                        i++;
                    else{
                        Min--;
                        ans.insert(ans.begin()+i, ch2);
                    }
                }
                else{
                    if(++it1 != set.rend()){
                        Min = it1->first;
                        ch2 = it1->second;                    
                    }
                    else
                        break;
                }
            }
            return ans;
        }
        
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