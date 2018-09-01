//37
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int size = words.size();
        if(size == 0)
            return res;
        int strSize = words[0].size();
        unordered_map<string, int> map;
        map[words[0]]++;
        for(int i = 1; i<size;++i){
            if(strSize != words[i].size())
                return res;
            map[words[i]]++;
        }
        
        for(int i = 0; i<s.size()-strSize*size+1; ++i){
            string temp = s.substr(i, strSize);
            if(map.find(temp) != map.end()){
                int count = size;
                unordered_map<string, int> map1;
                int j = i;
                for(; count-->0 && j < s.size(); j+=strSize){
                    temp = s.substr(j, strSize);
                    map1[temp]++;                    
                }
                if(map1 == map)
                    res.push_back(i);     
            }
        }
        
        return res;
    }
};