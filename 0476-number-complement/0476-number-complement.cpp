class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while(mask & num) mask <<= 1;
        return ~num ^ mask;
    }
};