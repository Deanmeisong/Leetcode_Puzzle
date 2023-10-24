class Solution {
public:
	string abbreviateProduct(int left, int right) {
        long long suf = 1; double prod = 1; int zero = 0, org = 0;
        for(int i = left; i <= right; ++i) {
            prod *= i;
            while(prod >= 1) {
                prod /= 10;
                ++org;
            }
            
            suf *= i;
            while(suf % 10 == 0) {
                suf /= 10;
                ++zero;
            }
            
            if(suf > pow(10, 14)) suf %= (long long)pow(10, 14);
        }
        
        if(org - zero <= 10) return to_string((long long)(prod * pow(10, org - zero) + 0.5)) + "e" + to_string(zero);
        else {
            string res = to_string(suf);
            return to_string((int)(prod * 100000)) + "..." + res.substr(res.length() - 5) + "e" + to_string(zero);
        }
	}
};

