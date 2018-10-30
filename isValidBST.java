//100
class Solution {
    public boolean isValidBST(TreeNode root) {
        return ValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    public boolean ValidBST(TreeNode root, long low, long high) {
        
        if(root == null)
            return true;
        
        //System.out.println(low + " " + high);
        
        if(low == high)
            return false;
        
        if(root.val <= low || root.val >= high)
            return false;
        
        return ValidBST(root.left, low, root.val) & ValidBST(root.right, root.val, high);
    }
}