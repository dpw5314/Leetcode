class Solution {
public:
    unordered_map<string, int> map;
    unordered_set<string> se;
/*
    struct{
        bool operator()(string a, string b){
            return a.size() < b.size();
        }
    }comp;*/
    
    int dfs(string word){
        //cout<<word<<endl;
        if(map.find(word) != map.end())
            return map[word];
        
        int nextVal = 0;
        string s = "";
        
        for(int i = 0; i<word.size(); ++i){
            s+=word[i];
            if(se.find(s) != se.end()){
                //cout<<s<<endl;
                if(i+1<word.size()){
                    nextVal = dfs(word.substr(i+1));
                    if(nextVal > 0 && (map.find(word) == map.end() || nextVal + 1 > map[word]))
                        map[word] = nextVal + 1;
                        
                }
                else if(i+1 == word.size()){
                    if(map.find(word) == map.end() || 1 > map[word])
                        map[word] = 1;
                }
            }
           // cout<<endl;
                
        }
        if(map.find(word) == map.end())
            map[word] = 0;
        return map[word];

    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        //sort(words.begin(), words.end(), comp);
        //cout<<words[0].size();
        vector<string> ans;
        unordered_set<string> se1(words.begin(), words.end());
        se = se1;
        //Trie* tr = new Trie();
        
        for(int i = 0; i<words.size(); ++i){
            if(dfs(words[i]) > 1 || map[words[i]] > 1)
                ans.push_back(words[i]);
        }
        
        /*
        for(auto it : map)
            cout<<it.first<<"->"<<it.second<<endl;*/
        
        return ans;
    }
};


//22
class Trie{
public:
    bool isWord;   
    unordered_map<char, Trie*> children; 
    
    Trie(){
        isWord = false;
    }

};


class Solution {
public:
    
    Trie* root = new Trie();
    
    void build(vector<string>& words){
        
        for(auto word : words){
            Trie* temp = root;
            if(word.size()==0)
                continue;
            for(int i = 0; i<word.size(); ++i){
                char ch = word[i];
                if(temp->children.find(ch) == temp->children.end())
                    temp->children[ch] = new Trie();
                temp = temp->children[ch];
            }
            temp->isWord = true;
        }
        return;
    }
    bool searchTrie(Trie* temp, string words, int index, int count){
        int len = words.size();
        for(int i = index; i<len; ++i){
            if(temp->children.find(words[i]) == temp->children.end())
                return false;
            temp = temp->children[words[i]];
            if(temp->isWord && searchTrie(root, words, i+1, count+1))
                return true;
        }
        
        return temp->isWord && count>=1;
    }
    /*
    void print(Trie* root){
        if(!root || root->children.size() == 0)
            return;
        for(auto it : root->children){
            cout<<it.first<<" ";
            print(it.second);
            cout<<endl;
        }
    }
    */
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        build(words);   
        vector<string> ans;
        for(string word : words)
            if(searchTrie(root, word, 0, 0))
                ans.push_back(word);
        //print(root);
        return ans;
    }
};