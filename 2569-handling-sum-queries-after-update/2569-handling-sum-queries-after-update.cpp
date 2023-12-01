using LL = long long;
class SegTreeNode{
public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;
    LL info, lazy_val;
    bool lazy_tag;
    
    SegTreeNode(int a, int b, int val) {
        lazy_tag = 0; lazy_val = 0;
        start = a; end = b;
        if(a == b) {
            info = val;
            return;
        }
        // int mid = (b - a) / 2 + a;
        int mid = (a+b)/2;
        if(left == NULL) {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid + 1, b, val);
            info = left->info + right->info;
        }
    }
    
    SegTreeNode(int a, int b, vector<int>& val) {
        lazy_tag = 0; lazy_val = 0;
        start = a; end = b;
        if(a == b) {
            info = val[a];
            return;
        }
        // int mid = (b - a) / 2 + a;
        int mid = (a + b) / 2;
        
        if(left == NULL) {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid + 1, b, val);
            info = left->info + right->info;
        }
    }
    
    void pushDown() {
        if(lazy_tag == 1 && left) {
            if(lazy_val & 1) {
                left->info = (left->end - left->start + 1) - left->info;
                right->info = (right->end - right->start + 1) - right->info;
                left->lazy_tag = 1; left->lazy_val += lazy_val;
                right->lazy_tag = 1; right->lazy_val += lazy_val;
            }
            lazy_tag = 0; lazy_val = 0;
        }
    }
    
    void updateRange(int a, int b) {
        if(a > end || b < start) return;
        if(a <= start && end <= b) {
            info = (end - start) + 1 - info;
            lazy_tag = 1;
            lazy_val += 1;
            return;
        }
        
        if(left) {
            pushDown();
            left->updateRange(a, b);
            right->updateRange(a, b);
            info = left->info + right->info;
        }
    }
    
    LL queryRange(int a, int b) {
        if(a > end || b < start) return 0;
        if(a <= start && end <=b) {
            return info;
        }
        if(left) {
            pushDown();
            LL ret = left->queryRange(a, b) + right->queryRange(a, b);
            info = left->info + right->info;
            return ret;
        }
        return info;
    }
    
};


class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<LL> ret;
        int n = nums1.size();
        SegTreeNode* root = new SegTreeNode(0, n - 1, nums1);
        LL sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        for(auto& query : queries) {
            if(query[0] == 1) {
                root->updateRange(query[1], query[2]);
            } else if(query[0] == 2) {
                sum += query[1] * root->queryRange(0, n - 1);
            } else {
                ret.push_back(sum);
            }
        }
        
        return ret;
    }
};