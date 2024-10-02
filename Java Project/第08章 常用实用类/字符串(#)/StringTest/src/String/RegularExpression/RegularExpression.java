package String.RegularExpression;
import java.util.Scanner;

public class RegularExpression {
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        System.out.print("输入中国大陆11位手机号：");
        String phoneNumber=scanner.nextLine();
        String regularExpression="1[345789]\\d{9}";
        if(phoneNumber.matches(regularExpression)){
            System.out.println("该手机号是中国大陆手机号。");
        }
        else{
            System.out.println("该手机号不是中国大陆手机号。");
        }
    }
}
