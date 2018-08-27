//100
class Solution {
    public int ans;
    public int numberOfArithmeticSlices(int[] A) {
        ans = 0;
        if(A.length < 3)
            return 0;
        for(int i = 0; i<A.length-1; ++i){
            int diff = A[i] - A[i+1];
            helper(A, i+1, 2, diff);
        }
        
        return ans;
    }
    public void helper(int[] A, int curPos, int len, int diff){
        if(curPos+1 < A.length && A[curPos] - A[curPos+1] == diff){
            if(++len >= 3)
                ans++;
            //System.out.println(ans);
            helper(A, curPos+1, len, diff);
        }
    }
}