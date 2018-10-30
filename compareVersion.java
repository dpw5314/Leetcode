//35
class Solution {
    public int compareVersion(String version1, String version2) {
        int index = 0;
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        //System.out.println(v1.length+" "+v2.length);
        
        
        while(index < v1.length && index <v2.length){
            int num1 = Integer.parseInt(v1[index]);
            int num2 = Integer.parseInt(v2[index]);
            //System.out.println(num1 + " "+ num2);
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
            index++;
        }
        
        while(index < v1.length){
            int num = Integer.parseInt(v1[index]);
            if(num > 0)
                return 1;
            index++;
        }
            
        while(index < v2.length){
            int num = Integer.parseInt(v2[index]);
            if(num > 0)
                return -1;
            index++;            
        }
        
        
        return 0;
    }
}