class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
        int n = A.size();
        double l = 0, r = 1.0;
        while(l < r) {
      //          double m = (l + r) / 2;
      // double max_f = 0.0;
      // int total = 0;
      // int p, q = 0;
            
              double m = (r - l) / 2 + l;
            double max_f = 0;
            int p, q;
            int total = 0;
      for (int i = 0, j = 1; i < n - 1; ++i) {
        while (j < n && A[i] > m * A[j]) ++j;
        if (n == j) break;
        total += (n - j);
        const double f = static_cast<double>(A[i]) / A[j];
        if (f > max_f) {
          p = i;
          q = j;
          max_f = f;
        }
      }
      if (total == k)
        return {A[p], A[q]};        
      else if (total > k)
        r = m;
      else
        l = m;
            // int m = (r - l) / 2 + l;
            // double maxF = 0;
            // int p, q;
            // int count = 0;
            // for(int i = 0, j = 1; i < n; ++i) {
            //     while(j < n and A[i] > m * A[j]) ++j;
            //     if(j == n) break;
            //     count += (n - j);
            //     double f = static_cast<double>(A[i] / A[j]);
            //     if(f > maxF) {
            //         p = i; q = j; maxF = f;
            //     }
            // }
            // if(k == count) return {A[p], A[q]};
            // if(k < count) r = m;
            // else l = m;
        }
        return {};
    }
};