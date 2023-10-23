using LL = long long;
class Solution {
    int temp[100];
public:
    long long kMirror(int k, int n) {
        vector<LL> ret;
        int len = 1;
        while(1) {
            for(LL i = pow(10, len - 1); i < pow(10, len); ++i) {
                LL a = getP(i, 0);
                if(check(a, k)) ret.push_back(a);
                if(ret.size() == n) return accumulate(ret.begin(), ret.end(), 0LL);
            }
            for(LL i = pow(10, len - 1); i < pow(10, len); ++i) {
                LL a = getP(i, 1);
                if(check(a, k)) ret.push_back(a);
                if(ret.size() == n) return accumulate(ret.begin(), ret.end(), 0LL);
            }
            ++len;
         
        }

    }
    
    LL getP(LL x, int flag) {
        LL y = x, z = 0; int count = 0;
        while(y > 0) {
            z = z * 10 + y % 10;
            y /= 10;
            ++count;
        }
        
        if(flag == 0) x /= 10;
        
        for (int i=0; i<count; i++)
            x = x*10;
        
        return x+z; 
    }
    

    bool check(LL x, int k) {
        int t = 0;
        while(x > 0) {
            temp[t++] = x % k;
            x /= k;
        }
        int i = 0, j = t - 1;

        while(i < j) 
            if(temp[i++] != temp[j--]) return false;
        
        return true;
    }
};