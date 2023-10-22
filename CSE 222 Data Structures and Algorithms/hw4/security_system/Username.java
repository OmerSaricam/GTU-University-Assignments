package security_system;

public class Username {

    /**
     * A no parameter constructor
     */
    public Username(){

    }


    /**
     * This method is a wrapper method that check if the username string is empty or not, if not the checkIfValidUsername1 method is called.
     * @param username It is the String to be checked
     * @return False if the username input is empty, otherwise it calls the checkIfValidUsername1 method.
     */
    public boolean checkIfValidUsername(String username){

        if(username.isEmpty() == true){
            System.out.printf("\nThe username is invalid. It should have at least 1 character.");
            return false;
        }


        else{
            boolean rvalue = this.checkIfValidUsername1(username);

            if(rvalue == true){
                return true;
            }
            else{
                System.out.printf("\nThe username is invalid. It should have letters only.");
                return false;
            }
        }
    }

    /**
     * A recursive method that returns false if the given string is contains non-letter element.
     * First, it will be checked if the string is empty. If it is empty, 1 will be returned because it means that there is no error since all elements are letters. Then, it will be checked whether the character received is a letter, if not, 0 will be returned. If it is a letter, the method will be called again with the same string parameter by decrementing the checked element of the string.
     * @param username It is the String to be checked
     * @return True if username is empty, false if non-letter value is encountered
     */
    private boolean checkIfValidUsername1(String username){

        if(username.isEmpty() == true) return true;

        else if(Character.isLetter(username.charAt(0)) == true){
            return checkIfValidUsername1(username.substring(1));
        }

        else return false;
    }


    
}
