//77

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        if(!wordList.contains(endWord))
            return 0;
        
        
        Queue<String> begin = new LinkedList<String>();
        Queue<String> end = new LinkedList<String>();
        
        Set<String> words = new HashSet<>(wordList);
        
        begin.add(beginWord);
        end.add(endWord);
        //words.add(beginWord);
        words.remove(endWord);
        //wordList.remove(endWord);
        
        int count = 2;
        Queue<String> be;
        Queue<String> en;      
        
        while(!begin.isEmpty() && !end.isEmpty()){       

            
            if(begin.size() < end.size()){
                be = begin;
                en = end;
            }
            else{
                be = end;
                en = begin;
            }
                
            int size = be.size();
            
            for(int k = 0; k<size; ++k){                
                char[] chArray = be.poll().toCharArray();
                char temp;
                for(int i = 0; i<chArray.length; ++i){
                    temp = chArray[i];
                    for(char word1 = 'a'; word1 <= 'z'; word1++){
                        if( word1 != temp){
                            chArray[i] = word1;
                            String sb = new String(chArray); 
                            if(en.contains(sb))
                                return count;
                            if(words.contains(sb)){  
                                words.remove(sb);
                                //System.out.println("Test + " + sb);
                                be.add(sb);
                            }
                        }
                    }
                    chArray[i] = temp;
                }                
            }
            //System.out.println("\n\n");
            count++;
        }
        
        return 0;
    }
}
