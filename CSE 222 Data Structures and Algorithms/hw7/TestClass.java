import java.util.LinkedHashMap;

public class TestClass {
    


    public static void main(String[] args){

        
        //Following processes is done because we  are  expected to  analyze which  algorithms  keep  the  input ordering and which don’t.
        
        String input = "'Hush, hush!' whispered the rushing wind.";

        myMap map_obj = new myMap(input);

        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj.printMap();


        System.out.printf("\n\n\nThe sorted map with mergesort: \n");

        mergeSort merge_obj = new mergeSort(map_obj);
        merge_obj.sort();


        System.out.printf("\n\n\nThe sorted map with selection sort: \n");
        selectionSort selection_obj = new selectionSort(map_obj);
        selection_obj.selection_sort();


        System.out.printf("\n\n\nThe sorted map with insertion sort: \n");
        insertionSort insertion_obj = new insertionSort(map_obj);
        insertion_obj.insertion_sort();


        System.out.printf("\n\n\nThe sorted map with bubble sort: \n");
        bubbleSort buble_obj = new bubbleSort(map_obj);
        buble_obj.bubble_sort();


        System.out.printf("\n\n\nThe sorted map with quick sort: \n");
        quickSort quicksort_obj = new quickSort(map_obj);
        quicksort_obj.quick_sort();


        ////////
        
        //Following processes is done because we are expected to calculate running  time  of  each  sorting  algorithm  for  each input.


        //worst case senario for merge sort
        System.out.printf("\n\n\n\n\n\n\nThe worst-case scenario of merge sort:");
        String input1 = "jjjjjjjjjj iiiiiiiii hhhhhhhh ggggggg ffffff eeeee dddd ccc bb a";
        myMap map_obj1 = new myMap(input1);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        mergeSort sort_obj = new mergeSort(map_obj1);
        long startTime = System.nanoTime();
        sort_obj.sort();    
        long endTime = System.nanoTime();
        double runningTime = (endTime - startTime);
        System.out.println("Running time: " + runningTime + " nanoseconds");




        //average case senario for merge sort
        System.out.printf("\n\n\nThe average-case scenario of merge sort:");
        String input2 = "eeeee bb iiiiiiiii a ggggggg dddd ffffff ccc hhhhhhhh jjjjjjjjjj";
        map_obj1 = new myMap(input2);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        sort_obj = new mergeSort(map_obj1);
        startTime = System.nanoTime();
        sort_obj.sort();    
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");
        
        

        //best case senario for merge sort
        System.out.printf("\n\n\nThe best-case scenario of merge sort:");
        String input3 = "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj";
        map_obj1 = new myMap(input3);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        sort_obj = new mergeSort(map_obj1);
        startTime = System.nanoTime();
        sort_obj.sort();    
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");    
        

//////////        


        //worst case senario for selection sort
        System.out.printf("\n\n\n\n\n\n\nThe worst-case scenario of selection sort:");
        map_obj1 = new myMap(input1);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        selectionSort sel_obj1 = new selectionSort(map_obj1);
        startTime = System.nanoTime();
        sel_obj1.selection_sort();   
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");         



        //average case senario for selection sort
        System.out.printf("\n\n\nThe average-case scenario of selection sort:");
        map_obj1 = new myMap(input2);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        sel_obj1 = new selectionSort(map_obj1);
        startTime = System.nanoTime();
        sel_obj1.selection_sort();  
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");  


 
        //best case senario for selection sort
        System.out.printf("\n\n\nThe best-case scenario of selection sort:");
        map_obj1 = new myMap(input3);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        sel_obj1 = new selectionSort(map_obj1);
        startTime = System.nanoTime();
        sel_obj1.selection_sort();
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");         



////////


        //worst case senario for insertion sort
        System.out.printf("\n\n\n\n\n\n\nThe worst-case scenario of insertion sort:");
        
        map_obj1 = new myMap(input1);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        insertionSort ins_obj1 = new insertionSort(map_obj1);
        startTime = System.nanoTime();
        ins_obj1.insertion_sort();    
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");         



        //average case senario for insertion sort
        System.out.printf("\n\n\nThe average-case scenario of insertion sort:");
        
        map_obj1 = new myMap(input2);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        ins_obj1 = new insertionSort(map_obj1);
        startTime = System.nanoTime();
        ins_obj1.insertion_sort();    
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");  


 
        //best case senario for insertion sort
        System.out.printf("\n\n\nThe best-case scenario of insertion sort:");
        
        map_obj1 = new myMap(input3);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        ins_obj1 = new insertionSort(map_obj1);
        startTime = System.nanoTime();
        ins_obj1.insertion_sort();    
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");   



///////

        //worst case senario for bubble sort
        System.out.printf("\n\n\n\n\n\n\nThe worst-case scenario of bubble sort:");
        
        map_obj1 = new myMap(input1);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        bubbleSort bub_obj1 = new bubbleSort(map_obj1);
        startTime = System.nanoTime();
        bub_obj1.bubble_sort();    
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");         



        //average case senario for bubble sort
        System.out.printf("\n\n\nThe average-case scenario of bubble sort:");
        
        map_obj1 = new myMap(input2);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        bub_obj1 = new bubbleSort(map_obj1);
        startTime = System.nanoTime();
        bub_obj1.bubble_sort();   
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");  


 
        //best case senario for bubble sort
        System.out.printf("\n\n\nThe best-case scenario of bubble sort:");
        
        map_obj1 = new myMap(input3);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        bub_obj1 = new bubbleSort(map_obj1);
        startTime = System.nanoTime();
        bub_obj1.bubble_sort();    
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");   



///////


        //worst case senario for quick sort
        System.out.printf("\n\n\n\n\n\n\nThe worst-case scenario of quick sort:");
        
        map_obj1 = new myMap(input3);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        quickSort quick_obj1 = new quickSort(map_obj1);
        startTime = System.nanoTime();
        quick_obj1.quick_sort();    
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");         



        //average case senario for quick sort
        System.out.printf("\n\n\nThe average-case scenario of quick sort:");
        
        map_obj1 = new myMap(input2);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        quick_obj1 = new quickSort(map_obj1);
        startTime = System.nanoTime();
        quick_obj1.quick_sort();  
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds");  


 
        //best case senario for quick sort
        System.out.printf("\n\n\nThe best-case scenario of quick sort:");
        //5 2 1 3 4 8 6 7 9 10
        String input4 = "eeeee bb a ccc dddd hhhhhhhh ffffff ggggggg iiiiiiiii jjjjjjjjjj";
        map_obj1 = new myMap(input4);
        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();

        System.out.printf("\n\n\nThe sorted map: \n");
        quick_obj1 = new quickSort(map_obj1);
        startTime = System.nanoTime();
        quick_obj1.quick_sort();    
        endTime = System.nanoTime();
        runningTime = (endTime - startTime);
        System.out.printf("\nRunning time: " + runningTime + " nanoseconds\n\n");   


    }
}
