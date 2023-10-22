package security_system;

import java.util.Stack;

public class Password1 {

    /**
     * A no parameter constructor
     */
    public Password1(){

    }

    /**
     * First part of the validacition process of password1. 
     * @param password1 the string to be checked
     * @return true if length of the password1 is bigger than 8 and if it contains only letter and brackets and if it contains at least 2 brackets and if it contains at least one letter; returns false otherwise.
     */
    public boolean isPassword1Valid(String password1){

        if(password1.length() <8){
            
            System.out.println("\nThe password1 is invalid. It should have at least 8 characters.");
            return false;
        } 

        else if (!password1.matches(".*[a-zA-Z].*")){
            System.out.printf("\nThe username is invalid. It should have letters too.");
            return false;
        }

        else if (!password1.matches("[a-zA-Z\\{\\}\\[\\]\\(\\)]+")){
            System.out.printf("\nThe username is invalid. It must contains only letter and brackets");
            return false;
        }

        else{

            int count = 0;
            for(int i=0 ; i<password1.length() ; i++){
                
                char ch = password1.charAt(i);
                if( ch == '[' || ch == ']' || ch == '(' || ch == ')' || ch == '{' || ch == '}' ){
                    count++;

                    if(count > 1) return true;
                }
            }
            
        }
        System.out.println("\nThe password1 is invalid. It should have at least 2 brackets.");
        return false;
    }


    /**
     * This method checks if the given username contains any character that is also present in the password (case-insensitive).
     * It converts both username and password to lowercase before comparing the characters.
     * If there is a match, it returns true. Otherwise, it returns false.
     *
     * @param username the string to be checked for any matching character
     * @param password1 the string to be compared for any matching character
     * @return true if the strings contain any matching character, false otherwise
     */    
    public boolean containsUserNameSpirit(String username, String password1){
        
        String lowerUsername = username.toLowerCase();

        String lowerPassword1 = password1.toLowerCase();
        
        Stack<Character> us_stack = new Stack();
        Stack<Character> pas_stack = new Stack();

        for(int i=0 ; i<lowerUsername.length() ; i++ ){
            us_stack.push(lowerUsername.charAt(i));
        }

        for(int i=0 ; i<lowerPassword1.length() ; i++ ){
            pas_stack.push(lowerPassword1.charAt(i));
        }

        while(!us_stack.isEmpty()){

            char ch = us_stack.pop();
            //Character ch = Character.valueOf(us_stack.pop());
            while(!pas_stack.isEmpty()){

                if(pas_stack.pop() == ch){ 
                //if(ch.equals(pas_stack.pop())){     
                  
                    return true;
                }   
            }

            for(int i=0 ; i<lowerPassword1.length() ; i++ ){
                pas_stack.push(lowerPassword1.charAt(i));
            }
        }

        return false;
    }
 

 
    /**
     * This method checks if the given password is balanced in terms of brackets ('[', ']', '(', ')', '{', '}') and that the opening and closing brackets are correctly ordered and nested.
     * It uses a stack to push any bracket characters in the password string.
     * It then pops the brackets from the stack and compares them with their respective closing bracket.
     * If a closing bracket is found without its matching opening bracket, or if the stack is not empty at the end of the process, it returns false. Otherwise, it returns true.
     *
     * @param password1 the password string to be checked for balanced brackets
     * @return true if the password string has balanced brackets, false otherwise
     */    
    public boolean isBalancedPassword(String password1){

        Stack<Character> brackets = new Stack<>();
        for(int i=0 ; i<password1.length() ; i++){
            
            char ch = password1.charAt(i);
            if( ch == '[' || ch == ']' || ch == '(' || ch == ')' || ch == '{' || ch == '}' ){
                brackets.push(ch);
            }
        }

        Stack<Character> temp_brackets = new Stack<>();

        while(!brackets.empty()){

            char ch = brackets.pop();

            if(ch == ')' || ch == '}' || ch == ']') {
                temp_brackets.push(ch);
            }

            else if(ch == '(' || ch == '{' || ch == '['){

                if(temp_brackets.empty()){
                    return false;
                }

                else if( ch == inverse(temp_brackets.pop())){
                    //istenen durum
                }

                else return false;
            }
        }

        if(temp_brackets.empty()){
            return true;
        }
        else return false;

    }    


    /**
     * This method returns the inverse of the input character.
     *If the input character is one of the following brackets: '[', ']', '(', ')', '{', or '}',
    * it returns its inverse bracket. Otherwise, it returns 'e'.
    * @param ch the input character to find its inverse
    * @return the inverse of the input character or 'e' if the input character is not a bracket
    */
    private char inverse(char ch){

        if( ch == '[') return ']';

        else if( ch == ']') return '[';

        else if( ch == '(') return ')';

        else if( ch == ')') return '(';

        else if( ch == '{') return '}';

        else if( ch == '}') return '{';

        else return 'e';
    }


    /**
     * This is a wrapper class for recursive isPalindromePossible1 method.
     * First all elements other than letters is removed from the string 
     * Then all letters is made lower case
     * @param password1 the string that will be controlled if it is possible to obtain a palindrome by rearranging the letters in the string
     * @return true if it is possible to obtain a palindrome by rearranging the letters in the string, false otherwise.
     */
    public boolean isPalindromePossible(String password1){

        String password = password1.replaceAll("[^a-zA-Z]", "");

        password = password.toLowerCase();

        return isPalindromePossible1(password,0);


        //return true;
    }

    /**
     * In the given string sequence, this recursive function considers if it is possible to obtain a palindrome by rearranging the letters in the string
     * Firstly, the letter in the first index of given string is controlled. If there is same letter in the rest of the string, then new string that not contains those letters is created and that new string is given as a parameter to isPalindromePossible1 method recursively. If there is no same letter in the rest of the string, then flag value is incremented. If there are more than one alone number it is not possible to obtain a palindrome from that string therefore the method returns false. If the string became empty, that means it is possible to obtain a palindrome with this string.
     * @param str the string that will be controlled if it is possible to obtain a palindrome by rearranging the letters in the string
     * @param flag alone letter number. If there are more than one alone number it is not possible to obtain a palindrome from that string
     * @return true if it is possible to obtain a palindrome by rearranging the letters in the string, false otherwise.
     */
    private boolean isPalindromePossible1(String str, int flag){

        if (str.length() == 0) {
            return true;
        }

        char ch = str.charAt(0);
        int index = str.indexOf(ch,1);

        if( index != -1){

            str = str.substring(1, index) + str.substring(index+1);

            return isPalindromePossible1(str,flag);
        }

        else{
            flag++;
            if(flag == 2){
                return false;
            }

            else{
                
                str = str.substring(1);
                return isPalindromePossible1(str,flag);
            }     
        }
    
        

    }





}