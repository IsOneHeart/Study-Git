package append;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Append {
    public static void main(String[] args) throws IOException {
        File file = new File("file.txt");
        String name = "";
        String password = "";
        Scanner scanner = new Scanner(System.in);
        try {
            FileWriter fileWriter = new FileWriter(file, true); //追加
            while (true) {
                System.out.print("姓名：");
                name = scanner.nextLine();
                if (name.equals("done"))
                    break;
                System.out.print("密码：");
                password = scanner.nextLine();
                fileWriter.write(name + " " + password + "\n");
            }
            fileWriter.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
