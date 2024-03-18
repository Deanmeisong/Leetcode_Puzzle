# @param {Integer[]} nums
# @return {Integer}
def minimum_replacement(nums)
    ret = 0
    i = nums.size - 2
    while i >= 0 do
        y = nums[i]
        x = nums[i+1]
        if y <= x
            i -= 1
            next
        end
        if y%x == 0
            ret += y/x - 1
            nums[i] = x
        else
            ret += y/x
            nums[i] = y/(y/x + 1)
        end
        i -= 1
    end
    ret

end