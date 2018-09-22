// 33.7
class Solution {
    public int end;
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int size = inorder.length-1;
        end = size;
        return build(inorder, postorder, 0, size);
    }
        
    private TreeNode build(int[] in, int[] post, int low, int high){
        if(high < low)
            return null;
        int num = -1;
        
        for(int i = low; i<= high; ++i){
            if(in[i] == post[end])
                num = i;
        }
        TreeNode root = new TreeNode(post[end--]);
        if(low == high)
            return root;
        root.right = build(in, post, num+1, high);
        root.left = build(in, post, low, num-1);

        return root;   
    }
}