import java.util.ArrayList;
import java.util.Set;

/**
 * The insertionSort class represents an insertion sort algorithm for sorting a map.
 * It takes an original map and performs insertion sort to obtain a sorted map.
 */
public class insertionSort {

    private myMap originalMap;  //The original map to be sorted.
    private myMap sortedMap;  //The resulting sorted map after the insertion sort.
    private String[] aux; //auxiliary array

    /**
     * Constructs an InsertionSort object with the given map.
     * The constructor initializes the original map and extracts the keys into an auxiliary array.
     *
     * @param map The original map to be sorted.
     */
    public insertionSort(myMap map){
        originalMap = map;

        Set<String> keys = originalMap.getMap().keySet();
        this.aux = keys.toArray(new String[0]);        
    }

    /**
     * Performs the insertion sort algorithm on the original map.
     * The method sorts the keys in ascending order based on the count value in the map's values.
     * It initializes the sortedMap with the sorted keys and corresponding values.
     * Finally, it prints the sorted map.
     */
    public void insertion_sort(){

        
        for(int i=1 ; i<aux.length ; i++){

                String key = aux[i];
                int j = i - 1;

                while (j >= 0 && originalMap.getMap().get(aux[j]).getCount() > originalMap.getMap().get(key).getCount()) {
                    aux[j + 1] = aux[j];
                    j--;
                }
                
                aux[j + 1] = key;
            }
        

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
}
