public class Solution {
    public int[] CorpFlightBookings(int[][] bookings, int n) {
        int[] diff = new int[n + 2];
        foreach (var book in bookings) {
            diff[book[0]] += book[2];
            diff[book[1] + 1] -= book[2];
        }

        int[] result = new int[n];
        int count = 0;
        for (int i = 1; i <= n; i++) {
            count += diff[i];
            result[i - 1] = count;
        }

        return result;
    }
}