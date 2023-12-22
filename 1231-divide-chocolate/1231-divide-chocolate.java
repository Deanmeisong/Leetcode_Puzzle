class Solution {
    public int maximizeSweetness(int[] sweetness, int k) {

        int sum = 0;
        for (int x: sweetness)
            sum+=x;
        
        int left = 0;
        int right = sum;
        
        while (left<right)
        {
            int mid = left+(right-left+1)/2;
            if (ok(sweetness, mid, k))
                left = mid;
            else
                right = mid-1;
        }
        
        return left;
    }
    
    Boolean ok(int[] sweetness, int S, int k) {
        int sum = 0;
        int count = 0;
        for (int i=0; i<sweetness.length; i++)
        {
            sum+=sweetness[i];
            if (sum>=S)
            {
                sum = 0;
                count++;
            }
        }
        return count>=k+1;
    }
}