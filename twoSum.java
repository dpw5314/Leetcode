//99
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new  HashMap<Integer, Integer>();
        int[] ans = new int[2];
       
        for(int i = 0; i<nums.length; ++i){
            if(map.get(target - nums[i]) == null)
                map.put(nums[i], i);
            else{
                ans[0] = map.get(target-nums[i]);
                ans[1] = i;
                break;
            }
        }
        
        return ans;
    }
}