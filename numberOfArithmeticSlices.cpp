#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define leng 4
using namespace std;
//98

cclass Solution {
public:
    int ans;
    int numberOfArithmeticSlices(vector<int>& A) {
        ans = 0;
        if(A.size() < 3)
            return ans;
        for(int i = 0; i<A.size()-1; ++i)
            helper(A, i+1, 2, A[i]-A[i+1]);
        
        return ans;
    }
    void helper(vector<int>& A, int Pos, int len, int diff ){
        if(Pos + 1<A.size() && A[Pos] - A[Pos+1] == diff){
            if(++len >= 3)
                ans++;
            helper(A, Pos+1, len, diff);
        }
    }
};