package topic2;

import java.util.Scanner;

public class Topic2 {
    public static void main(String[] args) {
        char[][] array = new char[7][]; // 使用动态数组
        final char defaultValue = 'A';
        int count = 0;
        for (int i = 0; i < 7; i++) {
            array[i] = new char[1 + i];
            for (int j = 0; j < array[i].length; j++) {
                array[i][j] = (char) (defaultValue + count++);
            }
        }
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入一个字符：");
        char value = scanner.next().charAt(0);
        boolean flag = false;
        int[] position = new int[2];
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < array[i].length; j++) {
                if (array[i][j] == value) {
                    flag = true;
                    position[0] = i;
                    position[1] = j;
                    break;
                }
            }
            if (flag) break;
        }

        if (flag) {
            System.out.println("下标：" + position[0] + "-" + position[1]);
        } else {
            System.out.println("字符在数组中未找到。");
        }

        scanner.close();
    }
}