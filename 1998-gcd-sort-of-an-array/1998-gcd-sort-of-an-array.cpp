class Solution {
public:
    int L = 100005;
    int f[100005];
    
    int find(int x) {
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }
    
    void Union(int x, int y) {
        x = f[x]; y = f[y];
        if(x > y) f[y] = x;
        else f[x] = y;
    }
    
    vector<int> getPrimes(int n) {
                auto q=vector<int>(n+1,0);
        
        for (int i=2; i<=sqrt(n); i++)
        {
            if (q[i]==0)
            {
                int j=i*2;
                while (j<n)
                {
                    q[j]=1;
                    j+=i;
                }
            }
        }
        vector<int>primes;
        for (int i=2; i<=n; i++)
        {
            if (q[i]==0)
                primes.push_back(i);                
        }
        return primes;
//         auto q = vector<int>(n + 1, 0);
        
//         for(int x = 2; x <= sqrt(n); ++x) {
//             if(q[x] == 0) {
//                 int y = 2 * x;
//                 q[y] = 1;
//                 while(y < n) {
//                     y += x;
//                     q[y] = 1;
//                 }
//             }
//         }
        
//         vector<int> primes;
//         for(int x = 2; x <= n; ++x)
//             if(q[x] == 0) primes.push_back(x);
        
//         return primes;
    }
    
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < 100005; ++i) f[i] = i;
        auto primes = getPrimes(sqrt(L));
        
        // for(int x : nums) {
        //     int y = x;
        //     for(int p : primes) {
        //         if(x < p * p) break;
        //         if(x % p == 0) {
        //             if(find(x) != find(p)) Union(x, p);
        //         }
        //         while(x % p == 0) x/= p;
        //     }
        //     if(x > 1) {
        //         if(find(x) != find(y)) Union(x, y);
        //     }
        // }
        
        for (int i=0; i<nums.size(); i++)
        {
            int x = nums[i];
            for (auto p: primes)
            {                
                // if (p > x) break;        // 28.79%, 921ms
                if (p * p > x) break;       // 86.30%, 315ms only iterate primes no greater than sqrt(x)
                if (x%p==0)
                {                    
                    if (find(nums[i])!=find(p))                        
                        Union(nums[i],p);                        
                    while (x%p==0) x/=p;
                }
            }
            if (x > 1)  // x must be a prime factor
            {
                if (find(nums[i])!=find(x))                        
                    Union(nums[i],x);                        
            }            
        }
        
    
        auto nums1 = nums;
        sort(nums1.begin(), nums1.end());
        for(int i = 0; i < nums.size(); ++i)
            if(find(nums[i]) != find(nums1[i])) return false;
        
        return true;
        
    }
};