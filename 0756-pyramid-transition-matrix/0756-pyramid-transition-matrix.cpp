class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if (bottom.size() == 1) return true;
        for (string& a : allowed) {
            m_[a.substr(0, 2)].push_back(a[2]);
        }
        return helper(bottom, "", m_);
    }
private:
    unordered_map<string, vector<char>> m_;
    bool helper(string pre, string cur, unordered_map<string, vector<char>>& m_) {
        if (pre.size() == 2 && cur.size() == 1) return true;
        if (pre.size() - cur.size() == 1)
            return helper(cur, "", m_);
        int pos = cur.size();
        string next = pre.substr(pos, 2);
        for (char cs : m_[next]) {
            if (helper(pre, cur + cs, m_)) {
                return true;
            }
        }
        return false;
    }
};
