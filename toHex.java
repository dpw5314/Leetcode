class Solution {
    public String toHex(int num) {
        if(num == 0)
            return "0";
        String Hex = "0123456789abcdef";
        StringBuilder res = new StringBuilder();
        int count = 0;
        while(num != 0 && count++<8){
            int index = (num&0xf);
            //System.out.println(index);
            res.append(Hex.charAt(index));
           // System.out.println(Hex.charAt(index));
            num >>= 4;
        }
        return res.reverse().toString();
    
