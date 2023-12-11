class SegTreeNode {
public:
    int start, end;
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    bool tag;
    int info;
    
    SegTreeNode(int a, int b, int val) {
        tag = 0;
        start = a, end = b;
        if(a == b) {
            info = val;
            return;
        }
        if(left == NULL) {
            int m = (b - a) / 2 + a;
            left = new SegTreeNode(a, m, val);
            right = new SegTreeNode(m + 1, b, val);
            info = max(left->info, right->info);
        }
    }
    
    void pushDown() {
        if(tag == 1 && left) {
            tag = 0;
            left->info = info;
            right->info = info;
            left->tag = 1;
            right->tag = 1;
        }
    }
    
    
    void update(int a, int b, int val) {
        if(b < start || a > end) return;
        if(a <= start && end <= b) {
            info = val; tag = 1;
            return;
        }
        if(left) {
            pushDown();
            left->update(a, b, val);
            right->update(a, b, val);
            info = max(left->info, right->info);
        }
    }
    
    int query(int a, int b) {
        if(b < start || a > end) return INT_MIN;
        if(a <= start && end <= b) return info;
        if(left) {
            pushDown();
            int ret = max(left->query(a, b), right->query(a, b));
            info = max(left->info, right->info);
            return ret;
        }
        return info;
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> Set;
        for(auto p : positions) {
            Set.insert(p[0]);
            Set.insert(p[0] + p[1]);
        }
        unordered_map<int, int> pos2idx;
        int i = 0;
        for(auto pos : Set) pos2idx[pos] = i++;
        int n = pos2idx.size();
        
        SegTreeNode* root = new SegTreeNode(0, n - 1, 0);
        vector<int> res;
        int maxH = 0;
        
        for(auto rect : positions) {
            int a = pos2idx[rect[0]];
            int b = pos2idx[rect[0]+rect[1]];
            int h = root->query(a, b - 1) + rect[1];
            maxH = max(maxH, h);
            res.push_back(maxH);
            root->update(a, b - 1, h);
        }
        
        return res;
        
    }
};