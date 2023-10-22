import java.util.ArrayList;
import java.util.Set;

/**
 *A class that implements the merge sort algorithm on a custom map structure.
 *This class merges two subarrays of the original array in a sorted manner.
 */
public class mergeSort {
	
    private myMap originalMap;  //The original map to be sorted.
    private myMap sortedMap;  //The resulting sorted map after the merge sort.
    private String[] arr; //auxiliary array

    /**
     * Constructor that initializes the originalMap and arr variables.
     * @param map The original map to be sorted.
     */
    public mergeSort(myMap map){
        originalMap = map;

        Set<String> keys = originalMap.getMap().keySet();
        this.arr = keys.toArray(new String[0]);
        
    }


    /**
     * Main function that sorts arr[l..r] using merge().
     * @param left_index The starting index of the array.
     * @param right_index The ending index of the array.
     */
    private void sort_helper(int left_index, int right_index)
	{
		if (left_index < right_index) {
			// We find the middle point of array part
			int middle_index = left_index + (right_index - left_index) / 2;

			// We sort first and second halves recursively
			sort_helper(left_index, middle_index);
			sort_helper(middle_index + 1, right_index);

			// Then we merge the sorted halves
			merge(left_index, middle_index, right_index);
		}
	}

    /**
     *The sort method is a public wrapper method to sort the array using merge sort. This method is called in main to sort the LinkedHashMap objects in the desired myMap object
     *The method uses the private sort_helper method to sort the array.
     */
    public void sort(){

        sort_helper(0, arr.length -1);

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


    /**
     * Merges two subarrays of arr[].
     * First subarray is arr[l..m]
     * Second subarray is arr[m+1..r]
     * @param l The starting index of the first subarray.
     * @param m The ending index of the first subarray and the starting index of the second subarray.
     * @param r The ending index of the second subarray.
     */
	private void merge(int l, int m, int r){
		//We find sizes of two subarrays to be merged
		int size1 = m - l + 1;
		int size2 = r - m;

		//We create temp arrays for hold the left and right subarrays.
		String[] left_array = new String[size1];
		String[] right_array = new String[size2];
        

		//Copying the elements in the specified indices to the temp array
		for (int i = 0; i < size1; ++i)
			left_array[i] = arr[l + i];

		for (int j = 0; j < size2; ++j)
			right_array[j] = arr[m + 1 + j];

    
		//Merging process of the temp arrays

		//Initial indexes of first and second subarrays
		int i = 0, j = 0;
		// Initial index of merged subarray array
		int k = l;
		while (i < size1 && j < size2) {
            
            if (originalMap.getMap().get(left_array[i]).getCount() <= originalMap.getMap().get(right_array[j]).getCount()){    
				arr[k] = left_array[i];
				i++;
			}
			else {
				arr[k] = right_array[j];
				j++;
			}
			k++;
		}

		// Copying the remaining elements of L[], if any 
		while (i < size1) {
			arr[k] = left_array[i];
			i++;
			k++;
		}

		//Copying the remaining elements of R[], if any 
		while (j < size2) {
			arr[k] = right_array[j];
			j++;
			k++;
		}
	}



}

