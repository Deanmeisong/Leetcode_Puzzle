class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n);
        int ret = 0;
        for(int i = 29; i >= 0; --i) {
            for(int j = 0; j < n; ++j) {
                arr[j] = (arr[j]<<1) + ((nums[j]>>i)&1);
            }
            if(check(arr, k)) ret = ret*2 + 0;
            else {
                ret = ret*2 + 1;
                for(int j = 0; j < n; ++j) arr[j] = arr[j]>>1;
            }      
        }
        return ret;
    }
    
    bool check(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0;
        int count = 0;
        while(i < n) {
            int j = i;
            int cur = arr[i];
            while(cur != 0) {
                count++;
                ++j;
                if(j == n) break;
                cur = cur & arr[j];
            }
            i = j + 1;
        }
        
        return (count != n) && (count <= k);
    }
};