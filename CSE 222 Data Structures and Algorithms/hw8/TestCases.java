import java.util.List;

public class TestCases implements Runnable {

    private  String FileName;
    private int X_SIZE;
    private int Y_SIZE;

    public TestCases(String FileName, int X_SIZE, int Y_SIZE) {
        this.FileName = FileName;
        this.X_SIZE = X_SIZE;
    	this.Y_SIZE = Y_SIZE;
    }



  
    
    public void test(){
    	
    	System.out.println("\n\n*******************\nMap is " + this.FileName + " with X_SIZE " + this.X_SIZE + " and Y_SIZE " + this.Y_SIZE + "\n********************\n");
	//Put your main class here so I can run your code for each map using my Main.java that I shared with you.
       // Your main class will be here
       /*CSE222Map Map = new CSE222Map (this.FileName, this.X_SIZE, this.Y_SIZE)
	CSE222Graph Graph = new CSE222Graph (Map)
	CSE222Dijkstra Dijkstra = new CSE222Dijkstra (Graph)
	List DijkstraPath = Dijkstra.findPath()
	CSE222BFS BFS= new CSE222BFS (Graph)
	List BFSPath = BFS.findPath()
	Map.convertPNG()
	Map.drawLine(DijkstraPath)
	Map.drawLine(BFSPath)
	Map.writePath(BFSPath)
	Map.writePath(DijkstraPath)
	System.out.println(“Dijkstra Path: “+ Dijkstra.length)
	System.out.println(“BFS Path: “+ BFS.length)*/

    
        CSE222Map Map = new CSE222Map (this.FileName, this.X_SIZE, this.Y_SIZE);
        CSE222Graph Graph = new CSE222Graph (Map);
        //Map.convertPNG("output1.png");
        //Graph.printGraph();

        
        // String source = Map.getStart_point_y() + "," + Map.getStart_point_x();
        // String destination = Map.getEnd_point_y() + "," +  Map.getEnd_point_x();
        
        CSE222Dijkstra dijkstra = new CSE222Dijkstra(Graph);
        List<String> dijkstraPath = dijkstra.findPath();

        // System.out.printf("\n\nPath:\n");
        // for(String str : dijkstraPath){
        //     System.out.printf("\n%s",str);
        // }

        CSE222Map dijkstraMap= new CSE222Map(dijkstraPath, Map);
        String PNG_name = FileName + "dijkstra_output.png";
        dijkstraMap.convertPNG(PNG_name);





    }

    @Override
    public void run() {
        test();
    }
}

