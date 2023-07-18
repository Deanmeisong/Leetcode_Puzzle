class Solution {
    public boolean validWordSquare(List<String> words) {
        // for(int i = 0; i < words.size(); ++i)
        //     for(int j = 0; j < words.get(i).length(); ++j) {
        //         if(i >= words.get(i).length() || j >= words.size()) return false;
        //         char c1 = words.get(i).charAt(j);
        //         char c2 = words.get(j).charAt(i);
        //         if(c1 != c2) return false;
        //     }
        // return true;
                int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<words.get(i).length(); j++){
                if(j >= n || words.get(j).length() <= i || words.get(j).charAt(i) != words.get(i).charAt(j))
                    return false;
            }
        }
        return true;
    }
}