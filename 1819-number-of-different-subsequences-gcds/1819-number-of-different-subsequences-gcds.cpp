class Solution {
    int g[200001];
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        for(int num : nums) {
            for(int i = 1; i <= sqrt(num); ++i) {
                if(num%i == 0) {
                    if(g[i] == 0) 
                        g[i] = num;
                    else 
                        g[i] = gcd(g[i], num);
                    if(num/i != i) {
                    if(g[num/i] == 0) 
                        g[num/i] = num;
                    else 
                        g[num/i] = gcd(g[num/i], num);
                }
                }
                
            }
        }
        
        int count = 0;
        for(int f = 1; f <= 200000; ++f)
            if(g[f] == f)
                ++count;
        return count;
    }
};