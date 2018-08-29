
//14
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        List<Integer> res = new ArrayList<Integer>();
        if(p.length() == 0 || p.length() > s.length())
            return res;
        char[] p1 = p.toCharArray();
        char[] s1 = s.toCharArray();
        for(int i = 0; i<p1.length; ++i){
            if(!map.containsKey(p1[i])){
                map.put(p1[i], 0);
            }
            int num = map.get(p1[i]);
            num++;
            map.put(p1[i], num);
        }
        
        int start = 0, end = 0;
        HashMap<Character, Integer> map1 = new HashMap<Character, Integer>();
        
        /*
        for(Character ch : map.keySet()){
            System.out.print(ch+"-->" +map.get(ch) + " ");
        }
        System.out.println("");*/
        
        
        while(end < s1.length){    
            if(!map1.containsKey(s1[end]))
                map1.put(s1[end], 0);
            int num = map1.get(s1[end]);
            num++;
            map1.put(s1[end], num); 
            /*
            for(Character ch : map1.keySet()){
                System.out.print(ch+"-->"+map1.get(ch) + " ");
            }
            System.out.println("");*/
            if(map1.size() == map.size() && map1.equals(map))
                res.add(start);
            if(end - start + 1 == p1.length){
               num = map1.get(s1[start]);
               if(num == 1){
                   map1.remove(s1[start]);
               }
               else{
                   map1.put(s1[start], --num);
               }
               start++;
            } 
            end++;
        }
        return res;
    }
}