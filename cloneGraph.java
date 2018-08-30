//64
public class Solution {
    public HashMap<Integer,UndirectedGraphNode > map = new HashMap<>();
    
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node == null)
            return node;
        if(map.get(node.label) != null)
            return map.get(node.label);
        
        UndirectedGraphNode node1 = new UndirectedGraphNode(node.label);
        map.put(node.label, node1);
        
        for(UndirectedGraphNode n : node.neighbors){
            node1.neighbors.add(cloneGraph(n));
            //System.out.println(n.label);
        }
        
        return node1;
    }
}