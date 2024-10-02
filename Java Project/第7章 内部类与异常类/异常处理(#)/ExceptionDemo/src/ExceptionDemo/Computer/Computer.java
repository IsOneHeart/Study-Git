package ExceptionDemo.Computer;

import ExceptionDemo.Number.NumberException;

public class Computer {
    public int greatestCommonDivisor(int num1, int num2) throws NumberException {
        if (num1 < 0 || num2 < 0) {
            throw (new NumberException("ERROR:参数含负数"));
        }
        // 使用辗转相除法计算最大公约数
        while (num2 != 0) {
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
        return num1;
    }
    public static void main(String[] args) {
        Computer computer = new Computer();

        try {
            int gcd = computer.greatestCommonDivisor(48, 18);
            System.out.println("GCD: " + gcd);

            // 尝试触发异常
            int invalidGcd = computer.greatestCommonDivisor(-12, 24);
        } catch (NumberException e) {
            System.out.println(e.getMessage());
        }
    }
}
