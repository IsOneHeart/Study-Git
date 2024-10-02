import java.util.Scanner;

// 自定义异常类
class MarkException extends Exception {
    String message;

    public MarkException(String message) {
        this.message = message;
    }

    // 使用标准的 getMessage 方法来获取异常消息
    @Override
    public String getMessage() {
        return message;
    }
}

interface Scanner_Check {

    void input_num(int num) throws MarkException; // 添加 throws 声明
}

class Mark_Scanner implements Scanner_Check {
    Scanner scanner = new Scanner(System.in);
    int mark;

    @Override
    public void input_num(int num) throws MarkException {
        if (num < 0 || num > 100) {
            throw new MarkException("成绩不得小于0或大于100！");
        }
        mark = num;
    }

    public void readAndSetInput() throws MarkException {
        System.out.println("请输入一个成绩（0-100之间）:");
        while (!scanner.hasNextInt()) {
            System.out.println("输入错误，请输入一个整数！");
            scanner.next(); // 清除错误输入
        }
        int input = scanner.nextInt();
        try {
            input_num(input);
        } catch (MarkException e) {
            System.out.println(e.getMessage());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Mark_Scanner mark = new Mark_Scanner();

        try {
            //mark.input_num(100);
            //mark.input_num(50);
            //mark.input_num(-10); // 这将抛出 MarkException
            mark.readAndSetInput();
        } catch (MarkException e) {
            System.out.println("异常抛出：" + e.getMessage());
        } finally {
            System.out.println("END");
        }
        // mark.readAndSetInput();
    }
}