import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import java.util.LinkedList;
import java.util.Queue;



public class MainFile {
    


    public static void main(String[] main){
        
        String[][] array = new String[10][10];

        System.out.printf("uzunluk: %d \n",array[0].length);


        try {
            File myFile = new File("tree.txt");
            Scanner myReader = new Scanner(myFile);
            int i = 0;
            while (myReader.hasNextLine()) {
                if(i == array.length -1){
                    array = resize(array, true, false);
                }
                String data = myReader.nextLine();
                System.out.println(data);
                String[] array2 = data.split(";");

                if(array[0].length <= array2.length -1){
                    array = resize(array, false, true);
                }

                for(int j = 0 ; j<array2.length ; j++){
                    array[i][j] = array2[j];
                }
                i++;
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found.");
            e.printStackTrace();
        }



        DefaultMutableTreeNode root = new DefaultMutableTreeNode("Root");
        JTree tree = new JTree(root);


        int i=0, j=0;
        while(array[i][0] != null){

            DefaultMutableTreeNode node = root;
            j=0;
            while(array[i][j] != null){
                //System.out.printf("\nKontrol2 .array[i][j]: %s",array[i][j]);
                boolean nodeExists = false;
                //Checking if there are same node
                int index = 0;  //index of same node.
                for(int k = 0; k<node.getChildCount() ; k++){
                    DefaultMutableTreeNode child = (DefaultMutableTreeNode) node.getChildAt(k);

                    if(array[i][j].equals(child.getUserObject())){
                        index = k;
                        nodeExists = true;
                        break;
                    }
                }

                if(nodeExists == true){
                    node = (DefaultMutableTreeNode)node.getChildAt(index);
                }
               
                
                else{
                    DefaultMutableTreeNode node2 =  new DefaultMutableTreeNode(array[i][j]);
                    node.add(node2);
                
                    int our_place_in_child_order = node.getChildCount() - 1;
                    node = (DefaultMutableTreeNode)node.getChildAt(our_place_in_child_order);
                }

                j++;
            }
            i++;
        }
        
         
        JFrame first = new JFrame();
        first.add(tree);
        first.setSize(200,200);
        first.setVisible(true);

        
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.printf("\nFirst JFrame is open. Press a key to close:" );
            String userInput = scanner.nextLine();
            first.dispose();
        } catch (Exception e) {
            System.out.println("Invalid input. Please try again.");
        }
        //scanner1.close();
        
    
        

    

/////
        //Scanner scanner = new Scanner(System.in);
        String choice;
        String input;
        boolean quit = false;
        
        while (!quit) {
            System.out.println("\nPlease select which part you want to test. Part A runs automatically : ");
            System.out.println("b - Process B");
            System.out.println("c - Process C");
            System.out.println("d - Process D");
            System.out.println("e - Process E");
            System.out.println(":q - Quit");
            
            if (scanner.hasNextLine()) {
                choice = scanner.nextLine().toLowerCase();
            }
            else{
                System.out.printf("\nGirmedi:");
                choice = ":q";
            }
            
            switch (choice) {

                case "b":
                    System.out.printf("\nEnter input to find with BFS (enter :q to go back to menu):");
                    input = scanner.nextLine();
                    while (!input.equals(":q")) {
                        BFSsearchJTree(root,input);
                        
                        System.out.printf("\nPlease enter a string (enter :q to go back to menu):");
                        input = scanner.nextLine();
                    }
                    break;
                case "c":
                    System.out.printf("\nEnter input to find with DFS (enter :q to go back to menu):");
                    input = scanner.nextLine();
                    while (!input.equals(":q")) {
                        DFSsearchJTree(root,input);
                        
                        System.out.printf("\nPlease enter a string (enter :q to go back to menu):");
                        input = scanner.nextLine();
                    }
                    break;                    
                case "d":
                    System.out.printf("\nEnter input to find with POST-ORDER TRAVERSAL (enter :q to go back to menu):");
                    input = scanner.nextLine();
                    while (!input.equals(":q")) {
                        postOrderTraversal(root, input);;
                        
                        System.out.printf("\nPlease enter a string (enter :q to go back to menu):");
                        input = scanner.nextLine();
                    }
                    break;                
                case "e":
                    moving_process(tree);
                    JFrame f = new JFrame();
                    f.add(tree);
                    f.setSize(200,200);
                    f.setVisible(true);
                    
                case ":q":
                    quit = true;
                    break;
                default:
                    System.out.printf("\nInvalid choice. Please try again.\n");
                    break;
            }
        }
        scanner.close();
        System.out.printf("\nProgram finished.\n");

        
    }

    /**
     * Resizes a two-dimensional String array.
     *
     * @param array             the original array to resize
     * @param row_will_resize   if true, the number of rows will be doubled
     * @param column_will_resize if true, the number of columns will be doubled
     * @return                  a new two-dimensional String array with the specified size
     */
    public static String[][] resize(String[][] array, boolean row_will_resize,boolean column_will_resize){
        
        int new_row_size;
        int new_column_size;
        
        if(row_will_resize == true){
            new_row_size = array.length*2;
        }
        else new_row_size = array.length;

        if(column_will_resize == true){
            new_column_size = array[0].length*2;
        }
        else new_column_size = array[0].length;
        
        
        String[][] new_array = new String[new_row_size][new_column_size];

        for(int i = 0; i<array.length ; i++){

            for(int j = 0 ; j<array[0].length ; j++){
                new_array[i][j] = array[i][j];
            }
        }

        return new_array;

    }

    /**
     * Traverses a tree using depth-first search and prints the user object associated with each node.
     * The children of each node are traversed recursively.
     *
     * @param node  the root node of the tree to traverse
     */
    public static void traverseTree(DefaultMutableTreeNode node) {
        // Get the user object associated with the node
        Object obj = node.getUserObject();
        System.out.println(obj.toString()); 
        
    
        // Traverse the children of the node recursively
        int childCount = node.getChildCount();
        for (int i = 0; i < childCount; i++) {
            DefaultMutableTreeNode childNode = (DefaultMutableTreeNode) node.getChildAt(i);
            traverseTree(childNode);
        }
    }

    /**
     * Performs a breadth-first search on a tree to find a specific node.
     * Each node is added to a queue and processed in order.
     *
     * @param root  the root node of the tree to search
     * @param str   the user object associated with the node to find
     */
    public static void BFSsearchJTree(DefaultMutableTreeNode root, String str) {
        Queue<DefaultMutableTreeNode> queue = new LinkedList<>();
        queue.add(root);
        int count = 1;
        while (!queue.isEmpty()) {
            DefaultMutableTreeNode node = queue.poll();
            System.out.printf("\nStep %d -> %s",count++,node.toString());

            if (node.toString().equals(str)) {
                System.out.printf("\nFound the node: %s",node.toString());
                System.out.printf(" (FOUND!)");
                return;
            }
            for (int i = 0; i < node.getChildCount(); i++) {
                queue.add((DefaultMutableTreeNode) node.getChildAt(i));
            }
        }
        System.out.printf("\nNot found: %s ",str);
    }


/**
 * Performs a depth-first search on a tree to find a specific node.
 * Each node is visited in a pre-order traversal, and the children are processed recursively.
 *
 * @param root  the root node of the tree to search
 * @param str   the user object associated with the node to find
 */
    public static void DFSsearchJTree(DefaultMutableTreeNode root, String str){

        
        int arr[] = {0,1}; //0. indis aranan str var mı, 1. indis ise count'u tutar

        arr = DFSsearchJTree(str, root, arr);

        if(arr[0] == 0){
            System.out.printf("\nNot found: ",root.toString());
        }
    }

    public static int[] DFSsearchJTree( String str, DefaultMutableTreeNode node,int[] arr ){
        
        System.out.printf("\nPart %d -> %s",arr[1],node.toString());
        
        if(node.toString().equals(str)){
            System.out.printf(" (FOUND!)");
            arr[0] = 1;
            return arr;
        }

        else if(node.getChildCount() == 0){
            arr[0] = 0;
            return arr;
        } 

        for(int i = node.getChildCount()-1 ; i>=0 ; i--){
            arr[1]++;
            arr = DFSsearchJTree(str, (DefaultMutableTreeNode)node.getChildAt(i), arr);
            if(arr[0] == 1){
                return arr;
            }
        }
        return arr;
    }



    /////////



    /**
     * Performs a post-order traversal of a tree to find a specific node.
     * The children of each node are processed recursively before the parent node is visited.
     *
     * @param root  the root node of the tree to traverse
     * @param str   the user object associated with the node to find
     */
    public static void postOrderTraversal(DefaultMutableTreeNode root, String str){

        
        int arr[] = {0,0}; //0. indis aranan str var mı, 1. indis ise count'u tutar

        arr = postOrderTraversal(str, root, arr);

        if(arr[0] == 0){
            System.out.printf("\nNot found: ",root.toString());
        }
    }

    public static int[] postOrderTraversal( String str, DefaultMutableTreeNode node,int[] arr ){        


        for(int i = 0 ; i<node.getChildCount() ; i++){
            
            arr = postOrderTraversal(str, (DefaultMutableTreeNode)node.getChildAt(i), arr);
        }
        
        if(arr[0] == 0){
            arr[1]++;
            System.out.printf("\nPart %d -> %s",arr[1],node.toString());

            if(node.toString().equals(str)){
                System.out.printf(" (FOUND!)");
                arr[0] = 1;
                return arr;
            }

            else if(node.getChildCount() == 0){
                arr[0] = 0;
                return arr;
            }
        }
 
        return arr;
    }

////////
    /**
     * Moves a node in a JTree to a specified location.
     * The path to the node to be moved and the destination are entered by the user.
     *
     * @param tree  the JTree containing the node to be moved
     */
    public static void moving_process(JTree tree){

       
        String[] path = new String[10];
        
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.printf("\nEnter a path to be moved like this:  2023;CSE222;LECTURE1;PROBLEM1  :    ");
            String str = scanner.nextLine().trim();

            path = str.split(";");
        } catch (Exception e) {
            System.err.println("Error reading input 1: " + e.getMessage());
        }

        String destination = "";
        try {
            System.out.print("Enter the destination: ");
            destination = scanner.nextLine();
        } catch (Exception e) {
            System.err.println("Error reading input 2: " + e.getMessage());
        }

        scanner.close();


        DefaultMutableTreeNode root = (DefaultMutableTreeNode) tree.getModel().getRoot();

        //System.out.printf("\nRoot before: %s",root.toString());

        boolean b = search_for_moving(root, path);

        

        if(b == true){

        JTree tree_to_move = TreeGeneratorWithPath(root, path,destination);

        DefaultMutableTreeNode root2 = (DefaultMutableTreeNode) tree_to_move.getModel().getRoot();

        

        deleting_the_moved_part(root, path, 0);

        //System.out.printf("\nSildikten sonra root\n");

        //traverseTree(root);

        //System.out.printf("\nŞimdi ekleme vakti\n");

       
        transportation(root, destination, (DefaultMutableTreeNode)root2);

        }

        else{
            System.out.printf("\nCannot move because it doesn't exist in the tree");
        }

    }


    /**
     * Searches for a specific path in the tree rooted at the given node.
     * @param root the root node of the tree to search
     * @param str the array of strings representing the path to be found
     * @return true if the path is found, false otherwise
     */    
    public static boolean search_for_moving(DefaultMutableTreeNode root, String[] str) {
        
        
        int count = 0; //str elemanları bulununca artırılır. 
        
        for(int i = 0 ; i<root.getChildCount(); i++){

           
            if(root.getChildAt(i).toString().equals(str[count])){
                count++;
                if(count == str.length){
                    return true;
                }    
                root = (DefaultMutableTreeNode)root.getChildAt(i);
                
                i = -1;
            }
            
        }
        return false;
    }

/**
 * Generates a new JTree containing the nodes in the specified path.
 * @param root the root node of the original tree
 * @param str the array of strings representing the path to be extracted
 * @param destination the name of the new root node for the generated tree
 * @return a new JTree containing the nodes in the specified path
 */    
    public static JTree TreeGeneratorWithPath(DefaultMutableTreeNode root, String[] str,String destination) {
        
        
        int count = 0; //str elemanları bulununca artırılır. 
        

        DefaultMutableTreeNode new_root = new DefaultMutableTreeNode(destination);
       
        JTree new_tree = new JTree(new_root);

        DefaultMutableTreeNode node = new DefaultMutableTreeNode();
        node = root;

        for(int i = 0 ; i<node.getChildCount(); i++){

            
            if(node.getChildAt(i).toString().equals(str[count])){
                count++;
                if(count != 1){ //Baştaki yıl node'unu eklemesin tree'ye.
                    DefaultMutableTreeNode temp_node = new DefaultMutableTreeNode(node.getChildAt(i).toString());
                    if(count >= str.length){
                        temp_node = (DefaultMutableTreeNode)node.getChildAt(i);
                    }
                    new_root.add(temp_node);
                    new_root = (DefaultMutableTreeNode)new_root.getChildAt(0);
                }
                if(!(count >= str.length)){  
                    node = (DefaultMutableTreeNode)node.getChildAt(i);
                }
                
                i = -1;
                if(count == str.length){
                    return new_tree;
                }

               
            }
            
        }
        return new_tree;
    }

/**
 * Deletes the specified node and its descendants from the tree rooted at the given node.
 * @param node the root node of the tree to modify
 * @param str the array of strings representing the path to be deleted
 * @param count the index of the current node in the path
 */
    public static void deleting_the_moved_part(DefaultMutableTreeNode node, String[] str,int count){

     
        for(int i=0 ; i<node.getChildCount(); i++){
           
            if(node.getChildAt(i).toString().equals(str[count])){
                
                if(count == str.length-1){  //eğer silinecek path'in sonuna gelmişsek onu kaldırırz.
                    System.out.printf("\nSona geldik");
                    node.remove(i);
                    return;
                }
                else{
                    count++;
                    deleting_the_moved_part((DefaultMutableTreeNode)node.getChildAt(i), str, count);
                }
              
                if((node.getChildCount() != 0) && node.getChildAt(i).getChildCount() == 0){
                    node.remove(i);
                    return;
                }
            }
        }
    }


    /**
     * Moves the specified node and its descendants to the new location in the tree rooted at the given node.
     * @param node the root node of the tree to modify
     * @param destination the name of the node where the moved nodes will be placed
     * @param will_be_put the root node of the subtree to be moved
     */
    public static void transportation(DefaultMutableTreeNode node, String destination, DefaultMutableTreeNode will_be_put ){

       
        for(int i = 0 ; i<node.getChildCount() ; i++){
            
            if(node.getChildAt(i).toString().equals(destination)){
                if(will_be_put.getChildCount() != 0 && node.getChildCount() != 0){
                    destination = will_be_put.getChildAt(0).toString();
                    
                    transportation((DefaultMutableTreeNode)node.getChildAt(i), destination, (DefaultMutableTreeNode)will_be_put.getChildAt(0));
                    return;
                }
                else{
                    System.out.printf("\nIt has been overwritten");  //BU KALACAK!!
                    return;
                }
            }
            
        }
       
        node.add(will_be_put);
        
        return;
    }
}
