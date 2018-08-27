//33
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        HashMap<TreeNode, List<TreeNode>> map = new HashMap<TreeNode, List<TreeNode>>();
        TreeNode temp = root;
        Queue<TreeNode> q = new ArrayDeque<TreeNode>();
        List<Integer> ans = new ArrayList<Integer>();
        if(temp != null)
            q.add(temp);
        for(TreeNode cur = q.poll(); cur != null; cur = q.poll()){
            if(map.get(cur) == null)
                map.put(cur, new ArrayList<TreeNode>());
            
            if(cur.left != null){
                if(map.get(cur.left) == null)
                    map.put(cur.left, new ArrayList<TreeNode>());
                q.add(cur.left);
                map.get(cur).add(cur.left);
                map.get(cur.left).add(cur);
            }
            if(cur.right != null){
                if(map.get(cur.right) == null)
                    map.put(cur.right, new ArrayList<TreeNode>());
                q.add(cur.right);
                map.get(cur).add(cur.right);
                map.get(cur.right).add(cur);
             
            }
        }


        
        
        int count = 0;
        HashMap<TreeNode, Integer> map1 = new HashMap<TreeNode, Integer>();
        q.add(target);
        map1.put(target,1);
        while(count++<K){
            Queue<TreeNode> temq = new ArrayDeque<TreeNode>();
            for(TreeNode cur = q.poll(); cur != null; cur = q.poll()){
                for(TreeNode next : map.get(cur)){
                    //System.out.println(next.val + " ");
                    if(map1.get(next) == null){
                        map1.put(next, 1);
                        temq.add(next);
                    }
                    //System.out.println("");
                }
                //System.out.println(cur.val);
                
            }
            q = temq;
        }
        for(TreeNode cur = q.poll(); cur != null; cur = q.poll())
            ans.add(cur.val);
        return ans;
    }
    
}