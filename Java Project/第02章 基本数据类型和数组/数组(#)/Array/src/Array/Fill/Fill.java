package Array.Fill;

import java.util.Arrays;

public class Fill {
    public static void main(String[] args) {
        String[] arr = new String[]{"Just", "A", "Java", "Array", "Fill", "Demo"};
        Arrays.fill(arr, 2, 3, "bb");
        System.out.print(Arrays.toString(arr));
    }
}
