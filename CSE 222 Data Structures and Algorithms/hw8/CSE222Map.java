import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.Color;

import java.util.Map;
import java.util.List;



public class CSE222Map {
    

    //CSE222Map Map = new CSE222Map (this.FileName, this.X_SIZE, this.Y_SIZE)
    private String start_point_y; //column
    private String start_point_x; //row

    private String end_point_y;
    private String end_point_x;

    private String[][] map = null;




    public CSE222Map(String fileName,int X_SIZE, int Y_SIZE){

        map = new String[X_SIZE][Y_SIZE];

        fileName = fileName.toLowerCase();

        //Reading file and append data to nxn map.

        String directoryPath = "TextFiles";
       //String fileName = "example.txt";

        // Construct the file path
        Path filePath = Paths.get(directoryPath, fileName);

        try {
            Scanner scanner = new Scanner(filePath);

            if(scanner.hasNextLine()){
                String line = scanner.nextLine();
                String[] values = line.split(",");
                start_point_y = values[0];
                start_point_x = values[1];

            }

            if(scanner.hasNextLine()){
                String line = scanner.nextLine();
                String[] values = line.split(",");
                end_point_y = values[0];
                end_point_x = values[1];

            }

            // Read the file line by line
            int i = 0;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                //System.out.println(line);
                String[] values = line.split(",");
                for(int j=0; j<values.length ; j++){
                    String num = values[j];
                    map[i][j] = num;
                }
                i++;
            }

            // Close the scanner
            scanner.close();

        } catch (Exception e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }

        //map = rotateClockwise(map);
        map = getSymmetric(map);
    }


    public CSE222Map(List<String> path,CSE222Map map){

        // for(String str : path){
        //     System.out.printf("\n%s",str);
        // }
        this.start_point_x = map.getStart_point_x();
        this.start_point_y = map.getStart_point_y();
        this.end_point_x = map.getEnd_point_x();
        this.end_point_y = map.getEnd_point_y();
        
        String[][] original = map.getMap();
        if (original == null){
            return;
        }

        int rows = original.length;
        int columns = original[0].length;

        this.map = new String[rows][columns];

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++) {
                
                String str = j + "," + i;

                //System.out.printf("\nKontrol edilen: i: %d, j: %d",i,j);
                
                if(path.contains(str)){
                    //System.out.printf("\nBu path'te bulunuyor");
                    this.map[i][j] = "k";
                }
                
                
                // if(j%10 == 0){
                //     this.map[i][j] = "k";
                // }
                
                else this.map[i][j] = original[i][j];
            }
        }

    }


    public String getStart_point_y(){
        return start_point_y;
    }

    public String getStart_point_x(){
        return start_point_x;
    }

    public String getEnd_point_y(){
        return end_point_y;
    }

    public String getEnd_point_x(){
        return end_point_x;
    }

    public String[][] getMap(){
        return map;
    }
    
    public void convertPNG(String pngName){
        int width = map[0].length;
        int height = map.length;
        
        System.out.printf("\n\n\nPng Dönüştürme işlemi başladı");
        System.out.printf("\nWidth: %d",width);
        System.out.printf("\nheight: %d",height);

        //BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_BYTE_BINARY);
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                
                // int rgb = map[y][x].equals("0") ? 0xFFFFFF : 0x000000;
                // image.setRGB(x, y, rgb);

                String value = map[y][x];
                Color color;

                if (value.equals("0")) {
                    color = Color.WHITE;
                } else if (value.equals("k")) {
                    color = Color.RED;
                } else {
                    color = Color.BLACK;
                }

                image.setRGB(x, y, color.getRGB());
            }
        }

        try {
            File outputFile = new File(pngName);
            ImageIO.write(image, "png", outputFile);
            System.out.println("PNG image created successfully.");
        } catch (IOException e) {
            System.out.println("Error creating PNG image: " + e.getMessage());
        }
    }


    public String[][] rotateClockwise(String[][] matrix){
        if (matrix == null || matrix.length == 0) {
            return matrix;
        }

        int rows = matrix.length;
        int columns = matrix[0].length;

        String[][] rotatedMatrix = new String[columns][rows];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                rotatedMatrix[j][rows - i - 1] = matrix[i][j];
            }
        }

        return rotatedMatrix;
    }


    public String[][] getSymmetric(String[][] matrix){
        if (matrix == null || matrix.length == 0) {
            return matrix;
        }

        int rows = matrix.length;
        int columns = matrix[0].length;

        String[][] symmetricMatrix = new String[columns][rows];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                symmetricMatrix[j][i] = matrix[i][j];
            }
        }

        return symmetricMatrix;
    }


    // public void arrangeMap(List<String> path ){
    //     System.out.printf("\n\nPath:\n");
    //     for(String str : dijkstraPath){
    //         System.out.printf("\n%s",str);
    //     }
    // }


    // public void deneme(int[][] matrix){

    //     for(int i = 0; i<map.length ; i++){

    //         for(int j = 0 ; j<map[i].length ; j++){
    //             map[i][j] = matrix[i][j];
    //         }
    //     }

    //     convertPNG("output2.png");
    // }

    public void deneme2(Map<String, List<String>> list){

        convertPNG("giris.png"); 
        for(int i = 0 ; i<map.length ; i++){

            for(int j=0 ; j<map[i].length ; j++){

                String obj = j + "," + i;
                if(list.get(obj) != null){
                    map[i][j] = "1";
                }
                else{
                    //System.out.printf("\ni: %d , j: %d  için null değeri bulundu",i,j);
                }
                
            }
        }

        convertPNG("cikis.png");        
    }

}
