//1
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> res = new ArrayList<Integer>();
        if(root == null)
            return res;
        Stack<Node> st = new Stack<Node>();
        st.add(root);
        while(!st.isEmpty()){
            Stack<Node> st1 = new Stack<Node>();
            Node top = st.peek();
            st.pop();
            res.add(top.val);
            for(Node ch : top.children)
                st1.add(ch);
            while(!st1.isEmpty()){
                st.add(st1.peek());
                st1.pop();
            }
        }
        return res;
    }
}

//99
class Solution {
    public List<Integer> res = new ArrayList<Integer>();
    
    public void traverse(Node root){
        res.add(root.val);
        for(Node ch : root.children)
            traverse(ch);
    }
    
    public List<Integer> preorder(Node root) {
        if(root != null)
            traverse(root);
        return res;
    }
}