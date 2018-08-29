#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define leng 4
using namespace std;


//22

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size() == 0 || p.size() > s.size())
            return ans;
        
        //multiset<char> mset1;
        map<char, int> mset1;
        for(int i = 0; i<p.size(); ++i){
            mset1[p[i]]++;
        }
        
        //multiset<char> mset2;
        map<char, int> mset2;
        int start = 0, end = 0;

        int count = 0;
        while(end < s.size()){
            //cout<<mset2.size()<<endl;
            mset2[s[end]]++;
            count++;

            if(count == p.size()){
                if(mset2 == mset1)
                    ans.push_back(start);
                mset2[s[start]]--;
                if(mset2[s[start]] == 0)
                    mset2.erase(mset2.find(s[start]));
                start++;
                count--;
            }
            end++;
        }
        
        return ans;
    }
};     
