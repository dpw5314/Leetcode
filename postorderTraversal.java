//69 two stack
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if(root == null)
            return res;
        
        Stack<TreeNode> st = new Stack<TreeNode>();
        Stack<TreeNode> st1 = new Stack<TreeNode>();
        while(!st.isEmpty() || root != null){
            if(root.left != null)
                st.add(root.left);
            if(root.right != null)
                st.add(root.right);
            st1.add(root);
            if(!st.isEmpty()){
                root = st.peek();
                st.pop();
            }
            else 
                root = null;
        }
        while(!st1.isEmpty()){
            res.add(st1.peek().val);
            st1.pop();
        }
        return res;        
    }
}
