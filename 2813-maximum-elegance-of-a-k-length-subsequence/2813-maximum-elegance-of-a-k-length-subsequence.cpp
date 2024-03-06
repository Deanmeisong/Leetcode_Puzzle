using LL = long long;
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.rbegin(), items.rend());
        unordered_map<int, int> Map;
        LL sum = 0;
        
        for(int i = 0; i < k; ++i) {
            sum += items[i][0];
            ++Map[items[i][1]];
        }
        
        LL t = Map.size();
        LL ret = sum + t*t;
        
        priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<>> pq;
        for(int i = 0; i < k; ++i) pq.push({items[i][0], items[i][1]});
        
        for(int i = k; i < items.size(); ++i) {
            if(Map.find(items[i][1]) != Map.end()) continue;
            while(!pq.empty()) {
                auto [profit, category] = pq.top(); pq.pop();
                if(Map[category] > 1) {
                    sum -= profit;
                    sum += items[i][0];
                    ++t;
                    ret = max(ret, sum + t*t);
                    --Map[category];
                    ++Map[items[i][1]];
                    break;
                }
            }

        }
        
        return ret;
    }
};