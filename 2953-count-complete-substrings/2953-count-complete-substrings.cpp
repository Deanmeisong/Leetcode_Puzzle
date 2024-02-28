class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n =  word.length();
        int ret = 0;
        
        for(int i = 0; i < n;) {
            int j = i+1;
            while (j<n && abs(word[j]-word[j-1])<=2) j++;
            ret += helper(word.substr(i, j-i), k);
            i = j;
        }
        
        return ret;
    }
    
    int helper(string s, int k) {
        set<char> Set(s.begin(), s.end());
        int count = 0;
        
        for(int t = 1; t <= Set.size(); ++t) {
            int len = t * k;
            int j = 0;
            vector<int> freq(26, 0);
            for(int i = 0; i + len - 1 < s.length(); ++i) {
                while(j <= i + len - 1) ++freq[s[j++]-'a'];
                if(check(freq, k)) ++count;
                freq[s[i]-'a']--;
            }
        }
        
        return count;

    }
    
    bool check(vector<int>& freq, int k) {
        for(int x : freq)
            if(x != 0 && x != k) return false;
        return true;
    }
};