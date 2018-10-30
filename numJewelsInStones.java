//90
class Solution {
    private HashMap<Character, Integer> map = new HashMap<Character, Integer>();
    public int numJewelsInStones(String J, String S) {
        char[] Js = J.toCharArray();
        char[] Ss = S.toCharArray();
        
        for(int i = 0; i< Js.length; ++i){
            map.put(Js[i], 1);
        }
        
        int res = 0;
        for(int i = 0; i<Ss.length; ++i){
            if(map.get(Ss[i]) != null)
                res++;
        }
        
        return res;
    }
}