//19
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length == 0)
            return 0;
        int ans = nums[0];
        int size = nums.length, sum = 0;
        
        for(int i = 0; i<size; ++i){
            sum += nums[i];
            ans = (ans > sum) ? ans : sum;
            sum = (sum>0)? sum : 0;
        }
        
        return ans;
            
    }
}