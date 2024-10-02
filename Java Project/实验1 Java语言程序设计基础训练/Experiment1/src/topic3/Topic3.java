package topic3;

import java.util.Scanner;

public class Topic3 {
    private static long count = 0;

    private static void palindromeNum(long num) {
        int length = 0;
        long temp = num;
        while (temp > 0) {
            temp = temp / 10;
            length++;
        }
        System.out.print("该数是" + length + "位数。");
        boolean flag = true;
        String stringNum = Long.toString(num);
        for (int i = 0; i < length / 2; i++) {
            if (stringNum.charAt(i) != stringNum.charAt(length - i - 1)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            System.out.println("该数是回文数。");
        } else {
            System.out.println("该数不是回文数。");
        }
        count += num;
    }

    public static void main(String[] args) {
        System.out.println("请输入正整数(输入0终止):");
        long num = -1;
        while (num != 0) {
            System.out.print(">>");
            Scanner scanner = new Scanner(System.in);
            num = scanner.nextLong();
            if (num < 0) {
                System.out.println("输入的数必须是正整数。");
            } else {
                palindromeNum(num);
            }
        }
        System.out.println("和：" + count);
    }
}
