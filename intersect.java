//80
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        List<Integer> li = new ArrayList<Integer>();
        
        for(int i = 0; i<nums1.length; ++i){
            if(map.get(nums1[i]) == null)
                map.put(nums1[i], 1);
            else
                map.put(nums1[i], map.get(nums1[i])+1);
        }
        
        for(int i = 0; i<nums2.length; ++i){
            if(map.get(nums2[i]) != null && map.get(nums2[i]) > 0){
                li.add(nums2[i]);
                map.put(nums2[i], map.get(nums2[i])-1);
            }
        }
        
        int[] ans = new int[li.size()];
        for(int i = 0; i<ans.length; ++i){
            ans[i] = li.get(i);
        }
        return ans;
            
    }
}