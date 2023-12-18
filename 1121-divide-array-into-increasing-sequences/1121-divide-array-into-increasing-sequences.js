/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var canDivideIntoSubsequences = function(nums, k) {
    const n = nums.length; let g = 1; let cur = 1;
    for(let i = 1; i < n; ++i) {
        if(nums[i - 1] < nums[i]) cur = 1;
        else cur = cur + 1;
        g = Math.max(g, cur);
    }
    return n >= g * k;
};