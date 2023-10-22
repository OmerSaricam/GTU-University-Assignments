
import java.util.ArrayList;
import java.util.Set;

/**
 * The selectionSort class represents a selection sort algorithm for sorting a map.
 * It takes an original map and performs selection sort to obtain a sorted map.
 */
public class selectionSort {
   
    private myMap originalMap;  //The original map to be sorted.
    private myMap sortedMap;  //The resulting sorted map after the selection sort.
    private String[] arr;

    /**
     * Constructs a SelectionSort object with the given map.
     * The constructor initializes the original map, and extracts the keys into an array.
     *
     * @param map The original map to be sorted.
     */
    public selectionSort(myMap map){
        originalMap = map;
        Set<String> keys = originalMap.getMap().keySet();
        this.arr = keys.toArray(new String[0]);
    }


    /**
     * Performs the selection sort algorithm on the original map.
     * The method sorts the keys in ascending order based on the count value in the map's values.
     * It initializes the sortedMap with the sorted keys and corresponding values.
     * Finally, it prints the sorted map.
     */
    public void selection_sort(){


        for(int i = 0 ; i<arr.length-1 ; i++){
            int index_of_min_count_value = i;
            for(int j = i+1; j<arr.length ; j++){

                if(originalMap.getMap().get(arr[j]).getCount() < originalMap.getMap().get(arr[index_of_min_count_value]).getCount()){
                    index_of_min_count_value = j;
                }

            }
            String temp = arr[i];
            arr[i] = arr[index_of_min_count_value];
            arr[index_of_min_count_value] = temp;
        }


        //To initialize the sortedMap variable, a string is created from the auxiliary array
        String str = String.join("",arr);
        
        //Since the key values are in order, we keep the value values in order in the valuesList list.
        ArrayList<info> valuesList = new ArrayList<>();
        for(int i = 0 ; i<arr.length ; i++){
            valuesList.add(originalMap.getMap().get(arr[i]));
        }
        sortedMap = new myMap(str,valuesList);
        
        
        sortedMap.printMap();        
    }

}
