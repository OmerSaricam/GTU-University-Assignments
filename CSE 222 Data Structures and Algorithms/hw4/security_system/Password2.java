package security_system;

public class Password2 {
    
    /**
     * A mo parameter constructor
     */
    public Password2(){

    }


    /**
     * This method checks if the given password2 can be divided exactly by the given denominations.
     * If password2 is less than 11 or greater than 10000, it returns false.
     * It recursively checks if it is possible to form password2 by adding denominations.
     * If the sum of denominations is equal to password2, it returns true.
     * If the sum exceeds password2, it reduces the sum by the last added denomination and continues the recursion.
     * If none of the possible combinations results in an exact division of password2, it returns false.
     * 
     * @param password2 the integer to be divided exactly
     * @param denominations the array of denominations to be used for division
     * @return true if exact division is possible, false otherwise
     */    
    public boolean isExactDivision(int password2, int[] denominations){
        
        if(password2 <11 || password2>10000){
            System.out.printf("\nThe password2 is invalid. It should be between 10 and 10,000.");
            return false;
        }

        else{
            boolean rvalue = isExactDivision(password2, denominations, 0);

            if(rvalue == true) return true;

            else{
                System.out.printf("\nThe password2 is invalid. It is not compatible with the denominations.");
                return false;
            }
        }
    }


    /**
     * This is a helper method for the isExactDivision method.
     * It recursively checks if it is possible to form password2 by adding denominations.
     * If the sum of denominations is equal to password2, it returns true.
     * If the sum exceeds password2, it reduces the sum by the last added denomination and continues the recursion.
     * If none of the possible combinations results in an exact division of password2, it returns false.
     * 
     * @param password2 the integer to be divided exactly
     * @param denominations the array of denominations to be used for division
     * @param sum the current sum of denominations
     * @return true if exact division is possible, false otherwise
     */
    public boolean isExactDivision(int password2, int[] denominations, int sum){

        for(int i = denominations.length-1; i>=0 ; i--){

            sum = sum + denominations[i];

            if(sum == password2){
                return true;
            }

            else if(sum > password2){
                sum -= denominations[i];
            }

            else if(sum < password2){

                boolean rvalue = isExactDivision(password2, denominations, sum);

                if(rvalue == true) return true;
                else{
                    sum -= denominations[i];
                }
            }
        }

        return false;
    }
}
