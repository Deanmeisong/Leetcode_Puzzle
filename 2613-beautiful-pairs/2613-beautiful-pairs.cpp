class Solution {
    const int N = 100005;
    inline void better (const vector<int> &v, int &x, int y) {
        if(x < 0) x = y;
        if(y >= 0 && (v[x] < v[y] || (v[x] == v[y] && y < x))) x = y;
    }

    int query(const vector<int> &tree, const vector<int> &v, int ind, int left, int right, int x, int y) {
        if(x <= left && right <= y) return tree[ind];
        const int mid = (left + right) >> 1;
        int r = -1;
        if(x <= mid) {
            r = query(tree, v, ind << 1, left, mid, x, y);
        }
        if(y > mid) {
            better(v, r, query(tree, v, (ind << 1) | 1, mid + 1, right, x, y));
        }
        return r;
    }

    void update(vector<int> &tree, const vector<int> &v, int ind, int left, int right, int x, int y) {
        better(v, tree[ind], y);
        if (left >= x && right <= x) {
            return;
        }
        const int mid = (left + right) >> 1;
        if (x <= mid) {
            update(tree, v, ind << 1, left, mid, x, y);
        } else {
            update(tree, v, (ind << 1) | 1, mid + 1, right, x, y);
        } 
    }
public:
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        vector<int> p1(n), p2(n), ind(n);
        for(int i = 0; i < n; ++i) {
            p1[i] = nums2[i] + nums1[i];
            p2[i] = nums2[i] - nums1[i];
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](const int x, const int y) {
            return nums2[x] < nums2[y];
        });

        vector<int> tree1(N << 2, -1); vector<int> tree2(N << 2, -1), ans(2, n);
        int d = INT_MAX;

        for(int i = 0; i < n; ++i) {
            const int i1 = query(tree1, p1, 1, 0, n, 0, nums1[ind[i]]);
            if(i1 >= 0) {
                const int may = p1[ind[i]] - p1[i1];
                if(may < d) {
                    d = may;
                    ans = {min(ind[i], i1), max(ind[i], i1)};
                } else if(may == d){
                    ans = min(ans, {min(ind[i], i1), max(ind[i], i1)});
                }
            }
            const int i2 = query(tree2, p2, 1, 0, n, nums1[ind[i]], n);
            if(i2 >= 0) {
                const int may = p2[ind[i]] - p2[i2];
                if(may < d) {
                    d = may;
                    ans = {min(ind[i], i2), max(ind[i], i2)};
                } else if(may == d){
                    ans = min(ans, {min(ind[i], i2), max(ind[i], i2)});
                }
            }

            update(tree1, p1, 1, 0, n, nums1[ind[i]], ind[i]);
            update(tree2, p2, 1, 0, n, nums1[ind[i]], ind[i]);
        }
        return ans;
    }
};