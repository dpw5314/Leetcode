/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

//19.63
class Solution {
    public int findSecondMinimumValue(TreeNode root) {
        if(root == null)
            return -1;
        Queue<TreeNode> que = new LinkedList<TreeNode>();
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        que.add(root);
        //TreeNode tmp;
        for(TreeNode tmp = que.peek(); !que.isEmpty(); tmp = que.peek()){
            if(!pq.contains(tmp.val))
                pq.add(tmp.val);
            if(tmp.left != null)
                que.add(tmp.left);
            if(tmp.right != null)
                que.add(tmp.right);
            que.poll();
        }
        
        if(pq.size() < 2)
            return -1;
        
        pq.poll();
        return pq.peek();
    }
}

//8.01
class Solution {
    public int findSecondMinimumValue(TreeNode root) {
        if(root == null)
            return -1;
        Queue<TreeNode> que = new LinkedList<TreeNode>();
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        que.add(root);
        //TreeNode tmp;
        for(TreeNode tmp = que.peek(); !que.isEmpty(); tmp = que.peek()){
            if(map.get(tmp.val) == null){
                pq.add(tmp.val);
                map.put(tmp.val, 1);
            }
            if(tmp.left != null)
                que.add(tmp.left);
            if(tmp.right != null)
                que.add(tmp.right);
            que.poll();
        }
        
        if(pq.size() < 2)
            return -1;
        
        pq.poll();
        return pq.peek();
    }
}