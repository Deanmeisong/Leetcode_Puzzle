/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let l = 0; let r = nums.length - 1;
    while(l < r && nums[l] == nums[r]) ++l;
    while(l < r) {
        let m = Math.floor((r - l) / 2) + l;
        if(nums[m] > nums[r]) l = m + 1;
        else r = m;
    } 
    return nums[r];
};