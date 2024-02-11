# @param {Integer[]} weights
# @param {Integer} k
# @return {Integer}
def put_marbles(weights, k)
    n = weights.size
    arr = []
    (0 ... n - 1).each do |i|
        arr.push(weights[i] + weights[i + 1])
    end
    arr.sort!
    ret = 0
    (0 ... k - 1).each do |i|
        ret += arr[arr.size - 1 - i]
    end
    (0 ... k - 1).each do |i|
        ret -= arr[i]
    end
    ret
end