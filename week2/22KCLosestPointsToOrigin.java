class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[0]*a[0] + a[1]*a[1] - b[0] * b[0] - b[1] * b[1];
        });
        ArrayList<int[]> res = new ArrayList<>();
        for (int[] point : points) {
            pq.add(point);
        }
        for (int i = 0; i < k; i++) {
            res.add(pq.remove());
        }
        return res.toArray(new int[res.size()][2]);
    }
}