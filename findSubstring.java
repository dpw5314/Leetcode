//25.24
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        int strSize = -1;
        List<Integer> li = new ArrayList<>();
        if(words.length == 0)
            return li;
        HashMap<String, Integer> map = new HashMap<>();
        
        for(int i = 0; i<words.length; ++i){
            if(map.get(words[i]) == null)
                map.put(words[i], 1);
            else{
                int num = map.get(words[i]);
                map.put(words[i], ++num);
            }
            if(strSize == -1)
                strSize = words[i].length();
            else if(strSize != -1 && strSize != words[i].length())
                return li;
        }
        
        int i = 0, count;
        while(i<s.length()- words.length*strSize+1){
            String temp = s.substring(i,i+strSize);
            if(map.get(temp) != null){
                System.out.println(temp);
                HashMap<String, Integer> map1 = new HashMap<>();
                int j = i;
                count = 0;
                while(j<s.length() && map.get(temp) != null && ++count <= words.length){
                    temp = s.substring(j,j+strSize);
                    if(map1.get(temp) == null)
                        map1.put(temp, 1);
                    else{
                        int num = map1.get(temp);
                        map1.put(temp, ++num);
                    }
                    if(count == words.length && map1.equals(map))
                        li.add(i);
                    j += strSize;
                }
            }
            //System.out.println(temp);
            i++;
        }
        return li;
    }
}