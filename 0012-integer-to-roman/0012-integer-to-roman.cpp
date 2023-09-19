class Solution {
public:
    string intToRoman(int num) {
              vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> ints = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
    
        for(int i = 0; i < romans.size(); ++i) {
            while(num >= ints[i]) {
                num -= ints[i];
                ans += romans[i];
            }
        }

        return ans;
    }
};