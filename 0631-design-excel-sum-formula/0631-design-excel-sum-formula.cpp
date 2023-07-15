class Excel {
public:
    int val[27][27];
    vector<string> exp[27][27];
    Excel(int height, char width) {
        for(int i = 0; i < 27; ++i)
            for(int j =0; j < 27; ++j)
                val[i][j] = 0;
    }
    
    void set(int row, char column, int v) {
        val[row][column - 'A'] = v;
        exp[row][column - 'A'].clear();
    }
    
    int get(int row, char column) {
        if(exp[row][column - 'A'].empty()) return val[row][column - 'A'];
        else 
        {
            int ret = 0;
            for(auto s : exp[row][column - 'A']) {
                int p = s.find(':');
                if(p == -1) {
                    auto[r, c] = parse(s);
                    ret += get(r, c);
                }
                else
                {
                    auto[x1, y1] = parse(s.substr(0, p));
                    auto[x2, y2] = parse(s.substr(p + 1));
                    for(int i = x1; i <= x2; ++i)
                        for(int j = y1; j <= y2; ++j)
                            ret += get(i, j);
                }
            }
            return ret;
        }
    }
//     int get(int r, char c) 
//     {
//         if (exp[r][c-'A'].empty())
//             return val[r][c-'A'];
//         else
//         {
//             int ret = 0;
//             for (auto s: exp[r][c-'A'])
//             {
//                 int p = s.find(":");
//                 if (p==-1)
//                 {
//                     auto [x, y] = parse(s);
//                     ret += get(x, y);
//                 }
//                 else
//                 {
//                     auto [x0, y0] = parse(s.substr(0, p));
//                     auto [x1, y1] = parse(s.substr(p+1));
//                     for (int i=x0; i<=x1; i++)
//                         for (char j=y0; j<=y1; j++)
//                             ret += get(i, j);
//                 }
//             }
//             return ret;
//         }
            
//     }
    
    int sum(int row, char column, vector<string> numbers) {
        exp[row][column - 'A'] = numbers;
        return get(row, column);
    }
    
    pair<int, char> parse(string s) {
        int row = stoi(s.substr(1));
        char column = s[0];
        return {row, column};
    }

};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */