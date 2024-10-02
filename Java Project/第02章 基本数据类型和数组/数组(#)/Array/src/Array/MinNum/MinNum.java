package Array.MinNum;
import java.util.Arrays;

public class MinNum {
    public static void main(String[] args) {
        int[] arr=new int[]{3,77,52,2,-9,1};
        int[] arr2=new int[arr.length-1];
        arr2=arr.clone();
        Arrays.sort(arr2);
        System.out.println("sort:"+ Arrays.toString(arr2));
        System.out.println("min:"+ arr2[0]);
    }
}
