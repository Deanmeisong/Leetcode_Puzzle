class Solution {
private:
    using point_t = std :: vector<int>;
    static inline uint64_t hash(const point_t &p) {
        return p[0] * 1e6 + p[1];
    }
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<uint64_t> bls;
        for(auto b : blocked) bls.insert(hash(b));
        bool en1 = enclose(source, bls, target);
        bool en2 = enclose(target, bls, source);
        return !en1 && !en2;
    }
    
    bool enclose(vector<int>& s, unordered_set<uint64_t> b, vector<int>& t) {
        unordered_set<uint64_t> visited;
        deque<point_t> dq;
        dq.push_back(s);
        visited.insert(hash(s));
        int maxSize = (b.size() - 1) * b.size()/2;

        while (!dq.empty() && visited.size() <= maxSize) {
        
            int &r = dq.front()[0]; int &c = dq.front()[1];
            static std :: vector<std::pair<int,int>> ds{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
            for (auto &dir: ds) {
                int x = r + dir.first; int y = c + dir.second;
                std::vector<int> p{x, y};
                if(x < 0 || x >= 1e6 || y < 0 || y >= 1e6) continue;
                if(visited.find(hash(p)) != visited.end() || b.find(hash(p)) != b.end()) continue;
                if(p == t) return false;
                dq.push_back(p);
                visited.insert(hash(p));
            }
            dq.pop_front();

        }
        return dq.empty();
    }
};