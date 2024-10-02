public class Main {
    public static void main(String[] args) {
        // 输出大写希腊字母
        System.out.println("大写希腊字母：");
        for (char ch = '\u0391'; ch <= '\u03A9'; ch++) {
            System.out.print(ch + " ");
        }
        System.out.println(); // 换行

        // 输出小写希腊字母
        System.out.println("小写希腊字母：");
        for (char ch = '\u03B1'; ch <= '\u03C9'; ch++) {
            System.out.print(ch + " ");
        }
    }
}