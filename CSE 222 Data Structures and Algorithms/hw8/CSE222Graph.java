import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Collections;
import java.util.Set;






public class CSE222Graph {
    
    //CSE222Graph Graph = new CSE222Graph (Map)

    private Map<String, List<String>> adjacencyList;

    private CSE222Map map;

    public CSE222Graph(CSE222Map map){
        adjacencyList = new HashMap<>();
        this.map = map;

        String[][] matrix = map.getMap();
        //Creating graph from matrix in given map object.
        for(int i = 0; i<matrix.length ; i++){

            
            for(int j = 0; j<matrix[i].length ; j++){
                
                

                // System.out.printf("\nBakılıyor: %s",matrix[i][j]);
                // boolean d = (matrix[i][j] == "0");
                // System.out.println("\nSonuc5: " + d);

                if(matrix[i][j].equals("0")){
                    
                    //System.out.printf("\n0 bulundu");
                    String vertex = j + "," + i; //bu sayede "column,row" formunda olan vertexler oluşturuyorum.

                    addVertex(vertex);  //kontrolü içeride yapılıyor.
                    //System.out.printf("\ni değeri: %d, j değeri: %d",i,j);
                    //sağında 0 varsa onunla edge oluşturuluyor
                    if(j+1 < matrix[i].length && matrix[i][j+1].equals("0")){
                        //String vertex2 = new String(j+1, i);
                        String vertex2 = (j+1) + "," + i;
                        addEdge(vertex, vertex2);
                    }

                    //Altında 0 varsa onunla edge oluşturuluyor.
                    if(i+1 < matrix.length && matrix[i+1][j].equals("0")){
                        //Zero_Pixel vertex2 = new Zero_Pixel(j, i+1);
                        String vertex2 = j + "," + (i+1);
                        addEdge(vertex, vertex2);
                    }

                    //Sağ alt çarprazında 0 varsa onunla arasında edge oluşturuluyor
                    if(j+1 < matrix[i].length && i+1<matrix.length && matrix[i+1][j+1].equals("0")){
                        //Zero_Pixel vertex2 = new Zero_Pixel(j+1, i+1);
                        String vertex2 = (j+1) + "," + (i+1);
                        addEdge(vertex, vertex2);
                    }

                    //Sol alt çarprazında 0 varsa onunla edge kuruluyor.
                    if(j-1 >= 0 && i+1<matrix.length && matrix[i+1][j-1].equals("0")){
                        //Zero_Pixel vertex2 = new Zero_Pixel(j-1, i+1);
                        String vertex2 = (j-1) + "," + (i+1);
                        addEdge(vertex, vertex2);
                    }

                    // //bunu kaldır!!! Her elemanı gezdik mi diye kontrol ettim. Ancak her eleman doğru şekilde map'e eklendi mi onu kontrol edemedim.
                    // matrix[i][j] = 1;
                    
                }
            }
        }

                           

                        //    map.deneme(matrix);
                        //map.deneme2(adjacencyList);

                        // Set<String> keys = adjacencyList.keySet();
                        // int keySize = keys.size();
                        // System.out.printf("Lan: %d",keySize);
                        // System.out.printf("\nKeyler basılıyor: ");
                        // for(String key: keys){
                        //     // System.out.printf("\ny değeri: %d, x değeri: %d",key.getY(),key.getX());
                        //     System.out.printf("\n%s",key);
                        // }



    }

    public void addVertex(String vertex){
        
        //System.out.printf("\naddVertex metoduna girdik. \nvertex : %s",vertex);
        if(!adjacencyList.containsKey(vertex)){
            //System.out.printf("\nEşit key bulunamadı, ekleme yapılıyor.");
            adjacencyList.put(vertex, new ArrayList<>());
        }
    }

    public void addEdge(String source, String destination){
        if (!adjacencyList.containsKey(source)) {
            addVertex(source);
        }
        if (!adjacencyList.containsKey(destination)) {
            addVertex(destination);
        }
        adjacencyList.get(source).add(destination);
        adjacencyList.get(destination).add(source);
    }

    public List<String> getNeighbors(String vertex) {
        return adjacencyList.get(vertex);
    }

    public void printGraph() {
        for (String vertex : adjacencyList.keySet()) {
            List<String> neighbors = adjacencyList.get(vertex);
            System.out.print(vertex + " -> ");
            for (String neighbor : neighbors) {
                System.out.print(neighbor + " ");
            }
            System.out.println();
        }
    }

    public CSE222Map getMap(){
        return map;
    }


/* 
    public List<Zero_Pixel> findShortestPath(String source, String destination) {
        Map<Zero_Pixel, Integer> distances = new HashMap<>();
        Map<Zero_Pixel, Zero_Pixel> previous = new HashMap<>();
        PriorityQueue<Node<Zero_Pixel>> priorityQueue = new PriorityQueue<>();

        for (Zero_Pixel vertex : adjacencyList.keySet()) {
            distances.put(vertex, Integer.MAX_VALUE);
        }
        distances.put(source, 0);

        priorityQueue.add(new Node<>(source, 0));

        while (!priorityQueue.isEmpty()) {
            Node<Zero_Pixel> currentNode = priorityQueue.poll();
            Zero_Pixel currentVertex = currentNode.vertex;

            if (currentVertex.equals(destination)) {
                break; // Reached the destination vertex
            }

            List<Zero_Pixel> neighbors = adjacencyList.get(currentVertex);

            if (neighbors != null) {
            for (Zero_Pixel neighbor : neighbors) {
                int newDistance = distances.get(currentVertex) + 1; // Assuming all edges have a weight of 1

                if (newDistance < distances.get(neighbor)) {
                    distances.put(neighbor, newDistance);
                    previous.put(neighbor, currentVertex);
                    priorityQueue.add(new Node<>(neighbor, newDistance));
                }
            }
            }
        }

        List<Zero_Pixel> path = new ArrayList<>();
        Zero_Pixel current = destination;

        while (current != null) {
            path.add(current);
            current = previous.get(current);
        }

        Collections.reverse(path);
        return path;
    }

    private static class Node<T> implements Comparable<Node<T>>{  //bu static kalmalı mı????????////Bir de T'yi ayarla
        T vertex;
        int distance;
    
        Node(T vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }

        // @Override
        // public int compareTo(Node<T> other) {
        //     return Integer.compare(this.distance, other.distance);
        // }

        @Override
        public int compareTo(Node<T> other) {
            return Integer.compare(this.distance, other.distance);
        }
        
    }
    */

    
    

    

    

}


















// public class CSE222Graph<T> {
    
//     //CSE222Graph Graph = new CSE222Graph (Map)

//     private Map<T, List<T>> adjacencyList;

//     public CSE222Graph() {
//         adjacencyList = new HashMap<>();
//     }

//     public void addVertex(T vertex) {
//         adjacencyList.put(vertex, new ArrayList<>());
//     }

//     public void addEdge(T source, T destination) {
//         if (!adjacencyList.containsKey(source)) {
//             addVertex(source);
//         }
//         if (!adjacencyList.containsKey(destination)) {
//             addVertex(destination);
//         }
//         adjacencyList.get(source).add(destination);
//         adjacencyList.get(destination).add(source);
//     }

//     public List<T> getNeighbors(T vertex) {
//         return adjacencyList.get(vertex);
//     }

//     public void printGraph() {
//         for (T vertex : adjacencyList.keySet()) {
//             List<T> neighbors = adjacencyList.get(vertex);
//             System.out.print(vertex + " -> ");
//             for (T neighbor : neighbors) {
//                 System.out.print(neighbor + " ");
//             }
//             System.out.println();
//         }
//     }

// }
