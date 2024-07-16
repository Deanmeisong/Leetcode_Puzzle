/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var longestOnes = function(nums, k) {
    let l = 0; let r = 0; let ans = 0; let count = 0;
    while(r < nums.length) {
        if(nums[r] == 0) ++count;
        while(count > k) {
            if(nums[l] == 0) --count;
            ++l;
        }
        ans = Math.max(ans, r-l+1);
        ++r;
    }
    return ans;
};