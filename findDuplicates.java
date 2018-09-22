class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<Integer>();
        if(nums.length == 0)
            return ans;
        Arrays.sort(nums);
        int temp = nums[0];
        for(int i = 1; i<nums.length; ++i){
            if(nums[i]==temp){
                ans.add(temp);
            }
            temp = nums[i];
        }
        
        return ans;
    }
}


int main(){
	Solution a;
	vector<pair<int, int>> vec = {{0, 5}, {15,20}, {5,10}};

	int ans = a.meetingroom(vec);

	cout<<ans<<endl; 

	return EXIT_SUCCESS;
}