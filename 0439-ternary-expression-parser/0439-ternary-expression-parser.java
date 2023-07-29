class Solution {
    public String parseTernary(String e) {
        if(e.length() == 1) return e;
        int index = 1, count = 0;
        while(index < e.length()) {
            if(e.charAt(index) == '?') count++;
            if(e.charAt(index) == ':') count--;
            if(count == 0) {
                if(e.charAt(0) == 'T')return parseTernary(e.substring(2, index));
                else return parseTernary(e.substring(index + 1)); 
            }
            ++index;
        }
        return "";
    }
}