package ex4_1;

public class MathAPI {
    public static void main(String[] args) {
        int[] a = new int[10];
        for (int i = 0; i < a.length; i++) {
            a[i] = (int) (Math.random() * 200 - 100);
            System.out.print(a[i] + (i == 9 ? ".\n" : " , "));
        }
        for (int i = 1; i < a.length; i++) {
            if (Math.abs(a[i]) < Math.abs(a[i - 1])) {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
            }
        }
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + (i == 9 ? ".\n" : " , "));
        }
    }
}
