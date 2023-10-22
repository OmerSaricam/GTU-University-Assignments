import java.util.LinkedHashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.Map;


/**
 *The myMap class is used to create and manipulate a LinkedHashMap that stores info objects for each letter in a given string. The LinkedHashMap is created by splitting the given input string into words and storing each letter in the map as a key with an associated info object that contains a count and a list of the words in which the letter appears.
*/
public class myMap {
    
    private LinkedHashMap<String,info> map;  //The LinkedHashMap object that stores the letters and associated info objects
    private int mapSize;  //The size of the LinkedHashMap.
    private String str;  //The string used to create the LinkedHashMap.


    /**
     * Constructs a myMap object by creating a LinkedHashMap and populating it with 
     * the letters from the given input string. Each letter is stored as a key with an
     * associated info object that contains a count of occurrences and a list of the 
     * words in which the letter appears.
     * 
     * @param input The input string used to create the LinkedHashMap.
     */    
    public myMap(String input){

        //error handling
        if(!input.matches(".*[a-zA-Z].*")){
            System.out.printf("\n\nThe entered string is not valid. The string must have at least one letter!\n\n");
            throw new IllegalArgumentException("Invalid string");
        }
        
        System.out.printf("\nOriginal String: %s",input);
        input = input.replaceAll("[^a-zA-Z\\s]", "");
        input = input.toLowerCase();

        System.out.printf("\nPreprocessed String: %s\n\n",input);

        str = new String(input);
        this.mapSize = 0;
        String[] arr = str.split(" ");
        int word_number = 0;

        map = new java.util.LinkedHashMap<>();
        
        for(int i=0 ; i<str.length(); i++){
            
            char ch = str.charAt(i);
            String letter  = Character.toString(ch);

            if( letter.equals(" ")){
                word_number++;
                continue;
            }
            else{

            
                //If the key is not in map
                if(map.get(letter) == null){
                    map.put(letter, new info(1,arr[word_number]));
                    mapSize++;
                }

                //If the key is in map.
                else{
                    info temp_info = map.get(letter);
                    
                    temp_info.push(arr[word_number]);
                    map.put(letter,temp_info);
                }
            }
            
        }
    }

    /**
     * Constructs a myMap object by creating a LinkedHashMap and populating it with 
     * the letters from the given input string. Each letter is stored as a key with an
     * associated info object that contains a count of occurrences and a list of the 
     * words in which the letter appears. The LinkedHashMap is populated using an 
     * existing ArrayList of info objects.
     * 
     * @param input The input string used to create the LinkedHashMap.
     * @param valuesList The ArrayList of info objects used to populate the LinkedHashMap.
     */
    public myMap(String input, ArrayList<info> valuesList){

        str = new String(input);
        mapSize = 0;
        String[] arr = str.split(" ");
        int word_number = 0;

        map = new java.util.LinkedHashMap<>(); 
        for(int i=0 ; i<str.length(); i++){

            char ch = str.charAt(i);
            String letter  = Character.toString(ch);

            //If it is a space character, no action is taken.
            if( letter.equals(" ")){
                word_number++;
                continue;
            }
            else{

                //If the key is not in map
                if(map.get(letter) == null){
                    map.put(letter, valuesList.get(i));
                    mapSize++;
                }

                //If the key is in map.
                else{
                    info temp_info = map.get(letter);
                    
                    temp_info.push(arr[word_number]);
                    map.put(letter,temp_info);
                }
            }
            
        }

    }

    /**
     * Returns the LinkedHashMap object created by the myMap constructor.
     * 
     * @return The LinkedHashMap object created by the myMap constructor.
     */
    public LinkedHashMap<String,info> getMap(){
        return map;
    }


    /**
     * Prints the contents of the LinkedHashMap in the format "Letter: key - Count: count - Words: words"
     */
    public void printMap(){

        for (Map.Entry<String, info> entry : map.entrySet()) {
            String key = entry.getKey();
            info value = entry.getValue();
            System.out.println("\nLetter: " + key + " - Count: " + value.getCount() + " - Words: " + value.getWords() );
        }
    }
}
