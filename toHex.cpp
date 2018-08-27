const string HEX = "0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string result;
        int count = 0;
        while (num && count++ < 8) {
            int a = (num & 0xf);
            cout<<num<<" "<<a<<endl;
            result = HEX[(num & 0xf)] + result;
            num >>= 4;
        }
        return result;        
    }
};
