public class DijkstraNode implements Comparable<DijkstraNode> {
    private String vertex;
    private int distance;

    public DijkstraNode(String vertex, int distance) {
        this.vertex = vertex;
        this.distance = distance;
    }

    public String getVertex() {
        return vertex;
    }

    public int getDistance() {
        return distance;
    }

    @Override
    public int compareTo(DijkstraNode other) {
        return Integer.compare(distance, other.distance);
    }
}

