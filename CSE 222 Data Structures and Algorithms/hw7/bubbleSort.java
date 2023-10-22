import java.util.ArrayList;
import java.util.Set;

/**
 * The bubbleSort class represents a bubble sort algorithm for sorting a map.
 * It takes an original map and performs bubble sort to obtain a sorted map.
 */
public class bubbleSort {
   
    private myMap originalMap;  //The original map to be sorted.
    private myMap sortedMap;  //The resulting sorted map after the bubble sort.
    private String[] aux; //auxiliary array

    /**
     * Constructs a BubbleSort object with the given map.
     * The constructor initializes the original map and extracts the keys into an auxiliary array.
     *
     * @param map The original map to be sorted.
     */
    public bubbleSort(myMap map){
        originalMap = map;

        Set<String> keys = originalMap.getMap().keySet();
        this.aux = keys.toArray(new String[0]);        
    }

    /**
     * Performs the bubble sort algorithm on the original map.
     * The method sorts the keys in ascending order based on the count value in the map's values.
     * It initializes the sortedMap with the sorted keys and corresponding values.
     * Finally, it prints the sorted map.
     */
    public void bubble_sort(){

        boolean swapped = true;

        for(int i = 0 ; i<aux.length -1  ; i++){
            swapped = false;
            for(int j=0 ; j<aux.length - i -1 ; j++){

                if(originalMap.getMap().get(aux[j+1]).getCount() < originalMap.getMap().get(aux[j]).getCount()){
                    String temp = aux[j];
                    aux[j] = aux[j+1];
                    aux[j+1] = temp;

                    swapped = true;
                }
            }
            if(swapped == false) break;
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
