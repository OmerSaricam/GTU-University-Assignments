import java.util.ArrayList;
import java.util.Set;

/**
 * The quickSort class represents a quicksort algorithm for sorting a map.
 * It takes an original map and performs quicksort to obtain a sorted map.
 */
public class quickSort {
 
    private myMap originalMap;  //The original map to be sorted.
    private myMap sortedMap;  //The resulting sorted map after the quick sort.
    private String[] aux; //auxiliary array

    /**
     * Constructs a QuickSort object with the given map.
     * The constructor initializes the original map and extracts the keys into an auxiliary array.
     *
     * @param map The original map to be sorted.
     */
    public quickSort(myMap map){
        originalMap = map;

        Set<String> keys = originalMap.getMap().keySet();
        this.aux = keys.toArray(new String[0]);        
    }    

    /**
     * Performs the quicksort algorithm on the original map.
     * The method sorts the keys in ascending order based on the count value in the map's values.
     * It initializes the sortedMap with the sorted keys and corresponding values.
     * Finally, it prints the sorted map.
     */
    public void quick_sort() {
        
        quick_Sort(0, aux.length - 1);

       //To initialize the sortedMap variable, a string is created from the auxiliary array
       String str = String.join("",aux);
        
       //Since the key values are in order, we keep the value values in order in the valuesList list.
       ArrayList<info> valuesList = new ArrayList<>();
       for(int i = 0 ; i<aux.length ; i++){
           valuesList.add(originalMap.getMap().get(aux[i]));
       }
       sortedMap = new myMap(str,valuesList);
       
       
       sortedMap.printMap();            
    }

    /**
     * Recursively performs the quicksort algorithm on the auxiliary array.
     *
     * @param first The index of the first element in the subarray.
     * @param last  The index of the last element in the subarray.
     */    
    private void quick_Sort(int first, int last){
        if (first < last) {
            int pivIndex = partition(first, last);
            quick_Sort(first, pivIndex - 1);
            quick_Sort(pivIndex + 1, last);
        }
    }
 

    /**
     * Partitions the subarray by selecting a pivot element and rearranging the elements accordingly.
     *
     * @param first The index of the first element in the subarray.
     * @param last  The index of the last element in the subarray.
     * @return The index of the pivot element after partitioning.
     */    
    private int partition(int first, int last){
        String pivot = aux[first];
        int up = first;
        int down = last;
        //Starting at the beginning of the array, elements smaller than the pivot and large elements starting from the end are found and replaced.
        do{
            while ((up < last) && originalMap.getMap().get(pivot).getCount() >= originalMap.getMap().get(aux[up]).getCount()){
                up++;
            }

            while (originalMap.getMap().get(pivot).getCount() < originalMap.getMap().get(aux[down]).getCount()) {
                down--;
            }

            if (up < down){
                swap(up, down);
            }

        } while (up < down);
        swap(first, down);
        return down;
    }

    /**
     * Swaps two elements in the auxiliary array.
     *
     * @param i The index of the first element.
     * @param j The index of the second element.
     */    
    private void swap(int i, int j){
        String temp = aux[i];
        aux[i] = aux[j];
        aux[j] = temp;
    }
}
