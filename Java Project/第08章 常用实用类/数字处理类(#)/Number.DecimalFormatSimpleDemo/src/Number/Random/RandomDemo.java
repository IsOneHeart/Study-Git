package Number.Random;

import java.util.Random;

public class RandomDemo {
    public static void main(String[] args) {
        int count = 0;
        Random r = new Random();
        for (int i = 0; i < 6; i++) {
            int num = r.nextInt(30) + 2;
            if (num % 2 != 0)
                num--;
            System.out.print(num + " ");
            count += num;
        }
        System.out.println("\ncount=" + count);
    }
}
