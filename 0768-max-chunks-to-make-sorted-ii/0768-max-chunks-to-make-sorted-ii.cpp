class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        long sum1=0, sum2=0, cnt=0;
        auto arr2 = arr;
        sort(arr2.begin(), arr2.end());
        
        
        for(int i = 0; i < arr.size(); ++i) {
            sum1 += arr[i];
            sum2 += arr2[i];
            if(sum1 == sum2) {
                ++cnt;
                sum1 = 0; sum2 = 0;
            }
        }
        
        return cnt;
    }
};