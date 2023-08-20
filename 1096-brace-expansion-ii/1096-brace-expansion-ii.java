class Solution {
    public List<String> braceExpansionII(String expression) {
         // Updated on 20 June 2021
        int n = expression.length();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (expression.charAt(i) == '{') {
                count++;
            } else if (expression.charAt(i) == '}') {
                count--;
                if (count == 0 && i != n - 1) {
                    expression = "{" + expression + "}";
                    break;
                }
            }
        }

        // the following code is the same in the video
        // new test case: "{a,b},x{c,{d,e}y}"
        Set<String> res = new HashSet<>();
        Deque<String> q = new ArrayDeque<>();
        q.offer(expression);
        
        while (!q.isEmpty()) {
            String cur = q.poll();
            if (cur.indexOf("{") == -1) {
                res.add(cur);
                continue;
            }
            
            int left = cur.indexOf("{");
            int index = left;
            while (index < cur.length() && cur.charAt(index) != '}') {
                if (cur.charAt(index) == '{') {
                    left = index;
                }
                index++;
            }
            int right = index;
            
            // left = { 0, right = 4 }
            // a, b
            String processed = cur.substring(0, left);
            String[] processing = cur.substring(left + 1, right).split(",");
            String unprocessed = cur.substring(right + 1);
            
            for (String part : processing) {
                StringBuilder sb = new StringBuilder(processed);
                sb.append(part).append(unprocessed);
                q.offer(sb.toString());
            }
        }
        
        List<String> resList = new ArrayList<>(res);
        Collections.sort(resList);
        return resList;
    }
}