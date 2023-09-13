function twoSum(nums: number[], target: number): number[] {
    let m: { [key: number]: number } = {};

    for (let i = 0; i < nums.length; i++) {
      let complment = target - nums[i];
      if (complment in m) return [m[complment], i];
      m[nums[i]] = i;
    }

    return [];
};