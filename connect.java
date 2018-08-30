//33.87
public class Solution {
    public void connect(TreeLinkNode root) {
        if(root == null)
            return;
        Queue<TreeLinkNode> q = new LinkedList<TreeLinkNode>();
        q.add(root);
        
        int n;
        TreeLinkNode node;
        while(!q.isEmpty()){
            n = q.size();
            while(n-- > 0){
                
                node = q.peek();
                q.poll();
                if(n>0)
                    node.next = q.peek();
                if(node.left != null)
                    q.add(node.left);
                if(node.right != null)
                    q.add(node.right);
            }
        }
    }
}
