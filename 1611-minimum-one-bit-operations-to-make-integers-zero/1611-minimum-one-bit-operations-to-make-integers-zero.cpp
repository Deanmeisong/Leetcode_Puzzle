class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0) return 0; 
        string str = bitset<32>(n).to_string();
        int i = 0;
        while(i < str.size() && str[i] == '0') ++i;
        str = str.substr(i);
        int lastDigit = 0;
        int j = 0;
        for(int k = 0; k < str.size(); ++k) {
            int x;
            if(str[k] == '1')
                x = lastDigit == 0 ? 1 : 0;
            else
                x = lastDigit == 0 ? 0 : 1;
            j = j * 2 + x;
            lastDigit = x;
        }
        
        return j;
        
    }
};