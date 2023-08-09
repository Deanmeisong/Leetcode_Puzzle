class Solution {
    public String similarRGB(String color) {
        String[] li = {"00", "11", "22", "33", "44", "55", "66", "77", "88", "99", "aa", "bb", "cc", "dd", "ee", "ff"};
        StringBuilder sb = new StringBuilder();
        sb.append("#");

        for(int i = 1; i < color.length(); i += 2) {
            String hex = color.substring(i, i + 2);
            int num = Integer.MAX_VALUE;
            String rbg = "";

            for(String s : li) {
                int check = Math.abs(Integer.parseInt(s, 16) - Integer.parseInt(hex, 16));
                if(check < num) {
                    num = check;
                    rbg = s;
                }
            }

            sb.append(rbg);
        }

        return sb.toString();
    }
}