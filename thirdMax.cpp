#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define leng 4
using namespace std;


//99.33
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int, int> map;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<nums.size(); ++i){
            if(map[nums[i]]++ == 0){
                if(pq.size() < 3)
                    pq.push(nums[i]);
                else if(pq.size() == 3 && nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        
        while(pq.size() < 3 && pq.size() != 1)
            pq.pop();
        
        return pq.top();
            
    }
};