/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let l = 0; let m = 0; let r = nums.length - 1;
    while(l <= r) {
        m = (r - l) // 2 + l;
        if(nums[m] == target) return m;
        if(nums[m] > target) r = m - 1;
        else l = m + 1;
    }
    return l;
 
};