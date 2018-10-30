//38
class Solution {
    public int search(int[] nums, int target) {
        if(nums.length == 0)
            return -1;
        
        if(nums.length == 1){
            if(nums[0] == target)
                return 0;
            return -1;
        }
        
        int pivot = findPivot(nums, 0, nums.length-1);

        if(pivot == 0)
            return findValue(nums, 0, nums.length-1, target);

        return 1 + findValue(nums, 0, pivot-1, target) + findValue(nums, pivot, nums.length-1, target);

    }
    
    public int findValue(int[] nums, int low, int high, int target){
        if(high < low)
            return -1;
        
        if( target < nums[low] || target > nums[high])
            return -1;
        
        while(low <= high){
            int mid = (high + low) / 2;
            if(nums[mid] > target)
                high = mid-1;
            else if(nums[mid] < target)
                low = mid+1;
            else
                return mid;
        }
        
        return -1;
    }
    
    public int findPivot(int[] nums, int low, int high){
        if(high < low)
            return 0;
        
        if(high == low)
            return low;
        
        int mid = (high + low) / 2;
        
        if(high > mid && nums[mid+1] < nums[mid])
            return mid+1;
        
        if(mid > low && nums[mid] < nums[mid-1])
            return mid;
        
        if(nums[high] < nums[mid])
            return findPivot(nums, mid+1, high);
        
        return findPivot(nums, low, mid-1);
    }
}

//98
class Solution {
    public int search(int[] nums, int target) {
        if(nums.length == 0)
            return -1;
        
        if(nums.length == 1){
            if(nums[0] == target)
                return 0;
            return -1;
        }
        
        int pivot = findPivot(nums, 0, nums.length-1);

        if(pivot == 0)
            return findValue(nums, 0, nums.length-1, target);

        return 1 + findValue(nums, 0, pivot-1, target) + findValue(nums, pivot, nums.length-1, target);

    }
    
    public int findValue(int[] nums, int low, int high, int target){
        if(high < low)
            return -1;
        
        if( target < nums[low] || target > nums[high])
            return -1;
        
        while(low <= high){
            int mid = (high + low) / 2;
            if(nums[mid] > target)
                high = mid-1;
            else if(nums[mid] < target)
                low = mid+1;
            else
                return mid;
        }
        
        return -1;
    }
    
    public int findPivot(int[] nums, int low, int high){
        if(nums[high] > nums[low])
            return low;
        while(high >= low){
            int mid = (high + low) / 2;
            if(nums[mid] > nums[high]){
                if(high > mid && nums[mid+1] < nums[mid])
                    return mid+1;
                low = mid + 1;
            }
            
            else if(nums[mid] < nums[low]){
                if(mid > low &&  nums[mid] < nums[mid-1])
                    return mid;
                high = mid - 1;
            }
        }
        
        return -1;
    }
}