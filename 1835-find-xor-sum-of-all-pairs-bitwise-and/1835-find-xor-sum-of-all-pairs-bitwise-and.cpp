class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ora = 0, orb = 0;
        for(int a : arr1) ora ^= a;
        for(int b : arr2) orb ^= b;
        return ora & orb;
    }
};