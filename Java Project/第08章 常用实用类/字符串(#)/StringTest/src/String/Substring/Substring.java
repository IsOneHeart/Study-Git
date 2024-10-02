package String.Substring;

public class Substring {
    public static void main(String[] args) {
        String str1 = "I am a substring in this string.";
        String str2 = "I am studying Java.";
        if (str1.substring(0, 3) == str2.substring(0, 3)) {
            System.out.println("两个子串地址相同");
        }
        else{
            System.out.println("两个子串地址不相同");
        }
        if (str1.substring(0, 3).equals(str2.substring(0, 3))) {
            System.out.println("两个子串内容相同");
        }
        else{
            System.out.println("两个子串内容不相同");
        }
    }
}
