class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        vector<int> ones(32);
        
        for(int b : arr2) {
            for(int i = 0; i < 32; ++i)
                ones[i] += ((b >> i) & 1);
        }
        
        int ret = 0;
        
        for(int a : arr1) {
            int ans = 0;
            for(int i = 0; i < 32; ++i) {
                if(((a >> i) & 1) and (ones[i] & 1))
                ans += (1 << i);
            }
            
            ret ^= ans;
        }
        
        return ret;
        
        
        
    }
};