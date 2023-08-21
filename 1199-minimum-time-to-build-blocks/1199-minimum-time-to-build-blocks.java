class Solution {
    public int minBuildTime(int[] blocks, int split) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int b : blocks) pq.add(b);
        while(pq.size() > 1) {
            int a = pq.poll(), b = pq.poll();
            pq.add(split + b);
        }
        return pq.poll();
    }
}