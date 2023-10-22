import java.util.*;

public class CSE222Dijkstra {
    private CSE222Graph graph;

    public CSE222Dijkstra(CSE222Graph graph) {
        this.graph = graph;
    }

    public List<String> findPath() {
        // String start = graph.getMap().getStart_point_x() + "," + graph.getMap().getStart_point_y();
        // String end = graph.getMap().getEnd_point_x() + "," + graph.getMap().getEnd_point_y();
        String start = graph.getMap().getStart_point_y() + "," + graph.getMap().getStart_point_x();
        String end = graph.getMap().getEnd_point_y() + "," + graph.getMap().getEnd_point_x();

        // Create a priority queue for nodes to be visited
        PriorityQueue<DijkstraNode> pq = new PriorityQueue<>();
        pq.offer(new DijkstraNode(start, 0));
        
        // Create a map to store the distance of each node from the start node
        Map<String, Integer> distances = new HashMap<>();
        distances.put(start, 0);

        // Create a map to store the previous node in the shortest path
        Map<String, String> previous = new HashMap<>();

        while (!pq.isEmpty()) {
            DijkstraNode current = pq.poll();
            String currentVertex = current.getVertex();

            // Stop the search if the end vertex is reached
            if (currentVertex.equals(end)) {
                break;
            }

            int currentDistance = distances.get(currentVertex);

            // Iterate through the neighbors of the current vertex
            if(graph.getNeighbors(currentVertex) != null){
            for (String neighbor : graph.getNeighbors(currentVertex)) {
                int weight = 1; // Assuming all edge weights are equal to 1

                // Calculate the distance to the neighbor through the current vertex
                int distance = currentDistance + weight;

                if (!distances.containsKey(neighbor) || distance < distances.get(neighbor)) {
                    // Update the distance and previous node of the neighbor
                    distances.put(neighbor, distance);
                    previous.put(neighbor, currentVertex);

                    // Add the neighbor to the priority queue for further exploration
                    pq.offer(new DijkstraNode(neighbor, distance));
                }
            }
            }
        }

        // Reconstruct the path from start to end by backtracking from the end node
        List<String> path = new ArrayList<>();
        String current = end;
        while (current != null) {
            path.add(current);
            current = previous.get(current);
        }
        Collections.reverse(path);

        return path;
    }
}
