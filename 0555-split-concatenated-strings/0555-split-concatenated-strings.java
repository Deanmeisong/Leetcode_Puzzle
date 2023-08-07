class Solution {
    public String splitLoopedString(String[] strs) {
        int len = strs.length;
        for(int i = 0; i < len; ++i) {
            String rev = new StringBuilder(strs[i]).reverse().toString();
            if(rev.compareTo(strs[i]) > 0) {
                strs[i] = rev;
            }
        }
        
        String res = "";
        char c = 'a';
        
        for(int i = 0; i < len; ++i) {
            String rev = new StringBuilder(strs[i]).reverse().toString();
            for(String s : new String[]{rev, strs[i]}) {
                for(int j = 0; j < s.length(); ++j) {
                    StringBuilder sb = new StringBuilder();
                    if(s.charAt(j) < c) continue;
                    else c = s.charAt(j);
                    
                    sb.append(s.substring(j));
                    
                    for(int k = i + 1; k < len; ++k) {
                        sb.append(strs[k]);
                    }
                    
                    for(int k = 0; k < i; ++k) {
                        sb.append(strs[k]);
                    }
                    
                    sb.append(s.substring(0, j));
                    if(sb.toString().compareTo(res) > 0) {
                        res = sb.toString();
                    }
                }
            }
        }
        
        return res;
        
    }
}