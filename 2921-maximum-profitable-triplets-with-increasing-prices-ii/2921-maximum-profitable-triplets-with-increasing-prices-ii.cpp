class BinaryIndexTree {
private:
    int n;
    vector<int> c;
public:
    BinaryIndexTree(int n) {
        this->n = n;
        c.resize(n + 1, 0);
    }
    
    int query(int x) {
        int mx = 0;
        while(x > 0) {
            mx = max(c[x], mx);
            x -= x & (-x);
        }
        return mx;
    }
    
    void update(int x, int v) {
        while(x <= n) {
            c[x] = max(c[x], v);
            x += x & (-x);
        }
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size();
        vector<int> left(n, 0); vector<int> right(n, 0);
        int m = *max_element(prices.begin(), prices.end());
        BinaryIndexTree tree1(m + 1); BinaryIndexTree tree2(m + 1);
        for(int i = 0; i < n; ++i) {
            int x = prices[i];
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for(int i = n - 1; i >= 0; --i) {
            int y = m + 1 - prices[i];
            right[i] = tree2.query(y - 1);
            tree2.update(y, profits[i]);
        }
        
        int ans = -1;
        for(int i = 0; i < n; ++i)
            if(left[i] > 0 && right[i] > 0) ans = max(ans, profits[i] + left[i] + right[i]);
        
        return ans;
    }
};