/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    private HashMap<Node, Node> map = new HashMap<>();
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        Queue<Node> q = new LinkedList<>();
        Node clone = new Node(node.val);
        map.put(node, clone);
        q.offer(node);
        while (!q.isEmpty()) {
            int qLen = q.size();
            for (int i = 0; i < qLen; i++) {
                Node cur = q.poll();
                for (Node next : cur.neighbors) {
                    if (!map.containsKey(next)) {
                        map.put(next, new Node(next.val));
                        q.add(next);
                    }
                    map.get(cur).neighbors.add(map.get(next));
                    
                }
            }
        }
        return clone;
    }
}