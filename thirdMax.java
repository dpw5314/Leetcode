//22
class Solution {
    public int thirdMax(int[] nums) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for(int i = 0; i<nums.length; ++i){
            /*
            System.out.println(pq.peek());
            if(pq.size()>0)
                System.out.println("Size:" + pq.size());
            else
                System.out.println("Size:0");*/
            if(!pq.contains(nums[i])){
                if(pq.size()<3)
                    pq.add(nums[i]);
                else if(pq.size() == 3){
                    if((nums[i] > pq.peek())){
                        pq.poll();
                        pq.add(nums[i]);                    
                    }
                }
            }
        }
        if(pq.size() < 3){
            while(pq.size() != 1)
                pq.poll();
            
        }
        return pq.peek();
     }
}