//100
class Solution {
    public int findMin(int[] nums) {
        int mid;
        int low = 0, high = nums.length-1;
        
        while(high > low){
            mid = (high + low)/2;
            //System.out.println(nums[mid]);
            if(nums[mid] > nums[high]){
                if(mid + 1 < nums.length && nums[mid+1] < nums[mid]){
                    //System.out.println("Here");
                    return nums[mid+1];
                }
                low = mid +1;
            }
            else if(nums[mid] < nums[low]){
                if(mid - 1 >= 0 && nums[mid-1] > nums[mid]){
                    return nums[mid];
                }
                
                else
                    high = mid-1;
            }
            else if(nums[mid] >= nums[low] && nums[mid] <= nums[high]){
                return nums[low];
            }
        }
        
        return nums[0];
    }
}