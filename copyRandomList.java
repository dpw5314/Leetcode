//72
public class Solution {
    private HashMap<RandomListNode, RandomListNode> map = new HashMap<RandomListNode, RandomListNode>();
    public RandomListNode copyRandomList(RandomListNode head) {
        if(head == null)
            return null;
        
        RandomListNode dummy = new RandomListNode(0);     
        RandomListNode temp = dummy;
        RandomListNode temp1 = head;
        
        while(temp1 != null){
            RandomListNode t1 = new RandomListNode(temp1.label);
            temp.next = t1;
            map.put(temp1, t1);
            temp = temp.next;
            temp1 = temp1.next;
        }
        
        
        temp = dummy.next;
        while(head != null){           
            temp.random = map.get(head.random);            
            head = head.next;
            temp = temp.next;
        }
        
        return dummy.next;
    }
}