import java.util.LinkedHashMap;

public class TestClass {
    


    public static void main(String[] args){

        String input = "'Hush, hush!' whispered the rushing wind.";

        myMap map_obj1 = new myMap(input);

        System.out.printf("\nThe original (unsorted) map: \n");
        map_obj1.printMap();


        System.out.printf("\n\n\nThe sorted map: \n");

        mergeSort sort_obj = new mergeSort(map_obj1);
        sort_obj.sort();

    }
}
