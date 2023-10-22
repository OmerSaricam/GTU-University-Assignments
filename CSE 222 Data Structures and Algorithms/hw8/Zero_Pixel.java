public class Zero_Pixel {
    
    private int y; //column value
    private int x; //row value
    
    public Zero_Pixel(int y,int x){
        this.y = y;
        this.x= x;
    }

    public int getY(){
        return y;
    }

    public int getX(){
        return x;
    }

    @Override
    public boolean equals(Object o){

        if(this.x == ((Zero_Pixel)o).getX() && this.y == ((Zero_Pixel)o).getY()){
            return true;
        }
        else return false;
    }

    @Override
    public String toString() {
        return "(" + getY() + ", " + getX() + ")";
    }
}
