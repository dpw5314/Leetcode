///98
class Solution {
    public List<Integer> res = new ArrayList<Integer>();
    
    public void traverse(Node root){
        for(Node ch : root.children)
            traverse(ch);
        res.add(root.val);
    }
    public List<Integer> postorder(Node root) {
        if(root != null)
            traverse(root);
        return res;
    }
}