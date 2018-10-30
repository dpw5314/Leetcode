//39
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0)
            return 0;
        
        int temp = nums[0];
        int ans = 1;
        
        for(int i = 0; i<nums.length; ++i){
            if(nums[i] != temp){
                nums[ans++] = nums[i];
                temp = nums[i];
            }
            else
                temp = nums[i];
        }
        
        return ans;
    }
}