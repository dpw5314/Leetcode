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


//68
class WordDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<string>> map;
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        map[word.size()].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(map.find(word.size()) == map.end())
            return false;
        
        vector<string> temp = map[word.size()];
        if(find(temp.begin(), temp.end(), word) != temp.end())
            return true;
        else{
            int index = 0;
            while(index < word.size()){
                vector<string> c;                
                if(word[index] != '.'){
                    for(string ele : temp){
                        if(ele[index] == word[index]){
                            if(index == word.size()-1)
                                return true;
                            c.push_back(ele); 
                        }
                    }
                    index++;
                }
                
                else if (word[index] == '.'){
                    if(index == word.size() - 1)
                        return true;
                    word = word.erase(index,1);
                    
                    for(auto ele : temp){
                        c.push_back(ele.erase(index, 1));
                }
            }
                if(c.size() == 0)
                    return false;
                std::swap(c, temp);
            }
        }
        return false;
    }
};


int main(){
	vector<int> vec = {2,1,1,2};
	//{3,5,7,0,1,2};
	//{3,1};
	Solution* a = new Solution();
	int ans = a->rob(vec);
    cout<<ans;
    delete a;
	return EXIT_SUCCESS;
}