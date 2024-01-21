/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    let n = nums.length;
    let far = 0;
    for(let i = 0; i < n; ++i) {
        far = Math.max(far, i + nums[i]);
        if(i >= far && i != n - 1) return false;
        if(far >= n - 1) return true;
    }
    return true;
};