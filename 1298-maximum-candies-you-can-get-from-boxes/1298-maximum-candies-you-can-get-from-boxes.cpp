class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        vector<int> myBoxes(status.size());
        vector<int> myKeys(status);
        queue<int> q;
        for(auto b : initialBoxes) {
            myBoxes[b] = 1;
            if(myKeys[b] == 1) q.push(b);
        }
            
        int ans = 0;
        while(!q.empty()) {
            int b = q.front(); q.pop();
            ans += candies[b];
            for(int box : containedBoxes[b]) {
                myBoxes[box] = 1;
                if(myKeys[box] == 1) q.push(box); 
            }
            for(int box : keys[b]) {
                if(!myKeys[box] && myBoxes[box]) {
                    q.push(box);
                }
                myKeys[box] = 1;
            }
        }
        return ans;
    }
};