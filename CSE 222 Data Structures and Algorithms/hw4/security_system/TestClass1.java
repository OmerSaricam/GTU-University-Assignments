package security_system;


import security_system.Password1;

public class TestClass1 {
    

    public static void main(String[] args){
        

        test_driver("sibelgulmez", "[rac()ecar]", 74, 1);

        test_driver("", "[rac()ecar]", 74, 2);

        test_driver("sibel1", "[rac()ecar]", 74, 3);

        test_driver("sibel", "pass[]", 74, 4);

        test_driver("sibel", "abcdabcd", 74, 5);

        test_driver("sibel", "[[[[]]]]", 74, 6);

        test_driver("sibel", "[no](no)", 74, 7);

        test_driver("sibel", "[rac()ecar]]", 74, 8);

        test_driver("sibel", "[rac()ecars]", 74, 9);

        test_driver("sibel", "[rac()ecar]", 5, 10);

        test_driver("sibel", "[rac()ecar]", 35, 11);

        test_driver("Ömer", "[ra5c()ecar]", 35, 12);





        System.out.printf("\n\n\n");

        
    }

    public static void test_driver(String username, String password1, int password2, int test_num){

        Username obj1 = new Username();
        Password1 obj2 = new Password1();  
        Password2 obj3 = new Password2();

        int[] arr = {4,17,29};

        System.out.printf("\n\n\nTest %d... \nInputs: username: '%s'  -  password1: '%s'  -  password2: '%s'",test_num,username,password1,password2);
        if(obj1.checkIfValidUsername(username) == false) return;

        else if(obj2.isPassword1Valid(password1) == false) return;

        else if(obj2.containsUserNameSpirit(username, password1) == false){
            System.out.printf("\nThe password1 is invalid. It should have at least 1 character from the username.");
            return;
        }

        else if(obj2.isBalancedPassword(password1) == false){
            System.out.printf("\nThe password1 is invalid. It should be balanced.");
            return;
        }

        else if(obj2.isPalindromePossible(password1) == false){
            System.out.printf("\nThe password1 is invalid. It should be possible to obtain a palindrome from the password1.");
            return;
        }

        else if(obj3.isExactDivision(password2, arr) == false){
            return;
        }

        else{
            System.out.printf("\nThe username and passwords are valid. The door is opening, please wait..");
            return;
        }
        
    }
}
