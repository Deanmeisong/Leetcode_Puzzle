public class Solution {
    public int LargestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit) {
        int n = values.Length;
        var pairs = new List<KeyValuePair<int, int>>(n);
        
        for (int i = 0; i < n; ++i) {
            pairs.Add(new KeyValuePair<int, int>(-values[i], labels[i]));
        }

        pairs.Sort((a, b) => a.Key.CompareTo(b.Key));

        var cnt = new Dictionary<int, int>();
        int ans = 0, num = 0;
        
        for (int i = 0; i < n && num < numWanted; ++i) {
            int v = -pairs[i].Key;
            int l = pairs[i].Value;
            
            if (!cnt.ContainsKey(l)) {
                cnt[l] = 0;
            }
            
            if (useLimit > cnt[l]) {
                cnt[l]++;
                num++;
                ans += v;
            }
        }

        return ans;
    }
}
