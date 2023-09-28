class Solution {
    public String convert(String s, int numRows) {
        if(numRows <= 1) return s;
        StringBuilder[] rows = new StringBuilder[numRows];
        
        for(int i = 0; i < numRows; ++i) rows[i] = new StringBuilder();
        
        int dif = 1; int curRow = 0;
        
        for(char c : s.toCharArray()) {
            rows[curRow].append(c);
            if(curRow == 0) dif = 1;
            else if(curRow == numRows - 1) dif = -1;
            curRow += dif;
        }
        
        StringBuilder res = new StringBuilder();
        
        for(StringBuilder r : rows) {
            System.out.println("r: "+r);
            res.append(r);
        }
        
        return res.toString();
    }
}