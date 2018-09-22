//71
    public List<List<Integer>> levelOrder(Node root) {
        Queue<Node> q = new LinkedList<Node>();
        List<List<Integer>> res = new ArrayList<List<Integer>> ();
        if(root == null)
            return res;
        
        q.add(root);
        
        while(!q.isEmpty()){
            List<Integer> temp = new ArrayList<Integer>();
            Queue<Node> tempQ = new LinkedList<Node>();
            for(Node i = q.peek(); !q.isEmpty(); q.poll(), i = q.peek()){
                temp.add(i.val);
                
                for(Node ch : i.children){
                   // System.out.println(ch.val);
                    tempQ.add(ch);
                }
                   
            }
            res.add(temp);
            q = tempQ;
        }
        return res;
    }
}