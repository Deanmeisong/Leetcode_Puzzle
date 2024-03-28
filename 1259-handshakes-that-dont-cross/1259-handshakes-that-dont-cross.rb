# @param {Integer} num_people
# @return {Integer}
def number_of_ways(num_people)
    m = 1000000007
    dp = Array.new((num_people/2)+1, 0)
    dp[0] = 1
    (1..(num_people / 2)).each do |i|
      (0...i).each do |j|
        dp[i] += dp[j]*dp[i-j-1]%m
        dp[i] %= m
      end
    end
    return dp[num_people / 2]
end