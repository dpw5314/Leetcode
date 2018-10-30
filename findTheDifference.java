//10
class Solution {
    private HashMap<Character, Integer> map = new HashMap<Character, Integer>();
    public char findTheDifference(String s, String t) {
        char[] s1 = s.toCharArray();

        for(int i = 0; i<s1.length; ++i){
            if(map.get(s1[i]) == null)
                map.put(s1[i], 1);
            else
                map.put(s1[i], map.get(s1[i]) + 1);
        }
        
        char[] s2 = t.toCharArray();
        
        for(int i = 0; i<s2.length; ++i){
            if(map.get(s2[i]) == null || map.get(s2[i]) == 0)
                return s2[i];
            map.put(s2[i], map.get(s2[i]) - 1);
                 
        }
        return '0';
    }
}

//91
class Solution {
    private HashMap<Character, Integer> map = new HashMap<Character, Integer>();
    public char findTheDifference(String s, String t) {
        char[] s1 = s.toCharArray();
        char[] s2 = t.toCharArray();
        int num = 0;
        
        for(int i = 0; i<s1.length; ++i){
            num ^= s1[i];
        }
        
        for(int i = 0; i<s2.length; ++i){
            num ^= s2[i];
        }
        return (char) num;
    }
}