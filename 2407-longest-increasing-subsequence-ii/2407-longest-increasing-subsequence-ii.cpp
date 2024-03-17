class SegTreeNode {
public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;
    int tag;
    int info;
    
    SegTreeNode(int a, int b, int val) {
        tag = 0;
        start = a, end = b;
        if(a == b) {
            info = val;
            return;
        }
        int mid = (a+b)/2;
        if(left == NULL) {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid+1, b, val);
            info = max(left->info, right->info);
        }
    }
    
    void push() {
        if(tag == 1 && left != NULL) {
            left->info = info;
            right->info = info;
            left->tag = 1;
            right->tag = 1;
            tag = 0;
        }
    }
    
    void update(int a, int b, int val) {
        if(a > end || b < start) return;
        if(a <= start && end <= b) {
            info = val;
            tag = 1;
            return;
        }
        if(left) {
            push();
            left->update(a, b, val);
            right->update(a, b, val);
            info = max(left->info, right->info);
        }
    }
    
    int query(int a, int b) {
        if(a > end || b < start) return INT_MIN;
        if(a <= start && end <= b) return info;
        if(left) {
            push();
            int ret = max(left->query(a, b), right->query(a, b));
            info = max(left->info, right->info);
            return ret;
        }
        return info;
    }
    
    
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int x = *max_element(nums.begin(), nums.end());
        SegTreeNode* root = new SegTreeNode(0, x, 0);
        int ret = 0;
        for(auto x : nums){
            int len = root->query(max(0,x-k), max(0,x-1));
            root->update(x, x, len+1);
            ret = max(ret,len+1);
        }

        return ret;
    }
};