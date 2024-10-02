package Array.ColumnRowSwap;

class TwoDimensionalArrayInt{
    public static void print(int[][] arr){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }

    public static int[][] swapColumnRow(int[][] arr){
        int[][] arr2=new int[arr.length][arr[0].length];
        try{
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    arr2[j][i]=arr[i][j];
                }
            }
        }
        catch(Exception e){
            System.out.println("ERROR");
        }
        return arr2;
    }
}

public class ColumnRowSwap {
    public static void main(String[] args) {
        int[][] arr = new int[3][3];
        int value=1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                arr[i][j]=value;
                value++;
            }
        }
        System.out.println("arr:");
        TwoDimensionalArrayInt.print(arr);
        System.out.println("arr(new):");
        TwoDimensionalArrayInt.print(TwoDimensionalArrayInt.swapColumnRow(arr));
    }
}
