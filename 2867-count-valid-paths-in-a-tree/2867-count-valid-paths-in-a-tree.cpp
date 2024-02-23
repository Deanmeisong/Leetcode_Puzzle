using LL = long long;
class Solution {
public:
    vector<LL> next[100005];
    int Father[100005];
    LL global = 0;
    unordered_set<int> primes;

    void Union(int x, int y) {
        x = Father[x]; y = Father[y];
        if(x < y) Father[y] = x;
        else Father[x] = y;
    }
    
    int findFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = findFather(Father[x]);
        return Father[x];
    }   
    
    unordered_set<int> getPrimes(int n) {
        vector<int> p(n + 1, 0);
        unordered_set<int> primes;
        for(int i = 2; i <= sqrt(n); ++i) {
            if(p[i] == 1) continue;
            int j = 2 * i;
            while(j <= n) {
                p[j] = 1;
                j += i;
            }
        }
        
        for(int i = 2; i <= n; ++i)
            if(p[i] == 0) primes.insert(i);
      
        return primes;
    }
    
    bool isPrime(int x) {
        return primes.find(x) != primes.end();
    }
    
    long long countPaths(int n, vector<vector<int>>& edges) {
        for(int i = 1; i <= n; ++i) Father[i] = i;
        this->primes = getPrimes(n);
         
        for(auto& e : edges) {
            next[e[1]].push_back(e[0]);
            next[e[0]].push_back(e[1]);
            if(findFather(e[0]) != findFather(e[1]) && !isPrime(e[0]) && !isPrime(e[1])) Union(e[0], e[1]);
        }
        
        unordered_map<int, LL> Map;
        for(int i = 1; i <= n; ++i) Map[findFather(i)] += 1;
        
        for(int p : primes) {
            LL total = 0;
            vector<LL> arr;
            LL local = 0;
            for(int nxt : next[p]) {
                if(isPrime(nxt)) continue;
                LL sum = Map[findFather(nxt)];
                total += sum;
                arr.push_back(sum);
            }
            
            for(LL m : arr) {
                local += (total - m) * m;
            }
            
            local = local / 2 + total;
            this->global += local;
        }
        return this->global;
        
    }
};