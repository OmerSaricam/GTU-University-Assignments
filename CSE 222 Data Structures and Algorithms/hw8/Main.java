

public class Main {
    public static void main(String args[]){
        //  public TestCases(String FileName, int X_SIZE, int Y_SIZE) 
        new Thread(new TestCases("Map01.txt", 500, 500)).start();
		//new Thread(new TestCases("deneme_map1.txt", 10,10 )).start();
        new Thread(new TestCases("Map02.txt", 500, 500)).start();
	new Thread(new TestCases("Map03.txt", 500, 500)).start();
	new Thread(new TestCases("Map04.txt", 500, 500)).start();
	new Thread(new TestCases("Map05.txt", 500, 500)).start();
	new Thread(new TestCases("Map06.txt", 500, 500)).start();
	new Thread(new TestCases("Map07.txt", 500, 500)).start();
	new Thread(new TestCases("Map08.txt", 500, 500)).start();
	new Thread(new TestCases("Map09.txt", 500, 500)).start();
	new Thread(new TestCases("Map10.txt", 500, 500)).start();

    }
}

