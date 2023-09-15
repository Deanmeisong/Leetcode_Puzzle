public class Solution {
    public int[] TwoSum(int[] nums, int target) {
      Dictionary<int, int> m = new Dictionary<int, int>();
      for (int i = 0; i < nums.Length; ++i)
      {
          if (m.ContainsKey(target - nums[i]))
          {
              return new int[] { m[target - nums[i]], i };
          }
          m[nums[i]] = i;
      }
      return new int[] { };
    }
}