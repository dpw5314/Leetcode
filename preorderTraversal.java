//57
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if(root == null)
            return res;
        
        Stack<TreeNode> st = new Stack<TreeNode>();
        while(!st.isEmpty() || root != null){
            if(root != null){
                res.add(root.val);
                if(root.right != null)
                    st.add(root.right);
                root = root.left;
            }
            else{
                root = st.peek();
                st.pop();
            }
        }
        
        return res;
    }
}