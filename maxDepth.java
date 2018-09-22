

//39
class Solution {
    
    public int res;
    
    public void traverse(Node root, int level){
        if(level > res)
            res = level;
        for(Node ch : root.children)
            traverse(ch, level+1);
    }
    
    public int maxDepth(Node root) {
        res = 0;
        if(root != null)
            traverse(root, 1);
        return res;
    }
}