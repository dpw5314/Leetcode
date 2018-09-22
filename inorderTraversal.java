//57

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if(root == null)
            return res;
        
        Stack<TreeNode> st = new Stack<TreeNode>();
        
        TreeNode temp = root;
        while(!st.isEmpty() || temp != null){
            if(temp != null){
                st.add(temp);
                temp = temp.left;
            }
            else{
                if(!st.isEmpty()){
                    temp = st.peek();
                    //System.out.println(temp.val);
                    res.add(temp.val);
                    st.pop();
                    temp = temp.right;
                }
            }
        }
        
        return res;
    }
}

//57 recursive
class Solution {
    List<Integer> res = new ArrayList<Integer>();
    public void helper(TreeNode root){
        if(root == null)
            return;
        helper(root.left);
        res.add(root.val);
        helper(root.right );
    }
    public List<Integer> inorderTraversal(TreeNode root) {        
        helper(root);
        return res;
    }
}