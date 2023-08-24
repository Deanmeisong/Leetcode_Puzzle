class Solution {
    public int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        List<Integer> count = new ArrayList<>();
        for(int i = 0; i < sideLength; ++i)
            for(int j = 0; j < sideLength; ++j)
                count.add((1 + (width - i - 1) / sideLength) * (1 + (height - j - 1) / sideLength));
        
        count.sort(Comparator.reverseOrder());
        int res = 0;
        for(int i = 0; i < maxOnes; ++i)
            res += count.get(i);
        
        return res;
    }
}