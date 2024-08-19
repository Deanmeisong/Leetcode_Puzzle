class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n);
        for (int i = 0, x = 0; i < n; ++i) {
            if (seq[i] == '(') {
                cout<<"before x: "<<x<<" || ";
                ans[i] = x++ & 1;
                cout<<"after x: "<<x<<" || ";
                cout<<"ansi: "<<ans[i]<<endl;
            } else {
                cout<<" ====== before x: "<<x<<" || ";
                ans[i] = --x & 1;
                cout<<" ====== after x: "<<x<<" || ";
                cout<<" ====== ansi: "<<ans[i]<<endl;
            }
        }
        return ans;
    }
};