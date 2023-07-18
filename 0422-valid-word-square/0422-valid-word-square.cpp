class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for(int i=0;i<words.size();i++)// words.size()  is used  to find vector size 
        {
            if(words[i].size()>words.size())// suppose words[i] string length is greater than the vector size then that string not preent in that . so  we return the false.
            {
                return false;
            }
            for(int j=0;j<words[i].size();j++)
            {
                if(words[i][j]!=words[j][i])// eg: ["abcd","bnrt","crm","dt"]      we compare words[0][3]==words[3][0]
                {
                    return false;
                }
            }
        }
        return true;
    }
};