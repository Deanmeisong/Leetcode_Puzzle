class Solution {
public:
    int diff[20005];
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2, 0);
        for(auto book : bookings) {
            diff[book[0]] += book[2];
            diff[book[1]+1] -= book[2];
        }
        vector<int> ret;
        int count = 0;
        for(int i = 1; i <= n; ++i) {
            count += diff[i];
            ret.push_back(count);
        }
        return ret;
    }
};