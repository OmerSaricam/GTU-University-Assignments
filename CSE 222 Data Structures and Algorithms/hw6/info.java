import java.util.ArrayList;

/**
 *The info class represents the information associated with each key in the myMap.
 */
public class info {
    
    private int count;
    private java.util.ArrayList<String> words;

    /**
     *Creates a new instance of info class with given count and first_word.
     *@param count the count of the first_word
     *@param first_word the first word associated with the key
     */
    public info(int count,String first_word){
        this.count = count;

        words = new ArrayList<String>();
        words.add(first_word);
    }

    /**
     *Returns the count of the info object.
     *@return the count of the info object
     */    
    public int getCount(){
        return count;
    }

    /**
     *Returns the ArrayList of words associated with the info object.
     *@return the ArrayList of words associated with the info object
     */
    public ArrayList<String> getWords(){
        return words;
    }

    /**
     *Adds the given string to the words ArrayList and increments the count.
     *@param str the string to be added to the words ArrayList
     */
    public void push(String str){
        words.add(str);
        count = count + 1 ;
    }
}
