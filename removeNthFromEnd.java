class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int copy = n;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode slow = dummy;
        ListNode fast = dummy;
        
        while(copy > 0){
            fast = fast.next;
            copy--;
        }
        while(fast.next != null){
            slow = slow.next;
            fast = fast.next;
        }
        
        slow.next = slow.next.next;
        
        return dummy.next;
    }
}