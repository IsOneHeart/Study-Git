import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Test5 {
    private static String getIndentation(int depth) {
        StringBuilder indentation = new StringBuilder();
        for (int i = 0; i < depth; i++) {
            indentation.append("    ");
        }
        indentation.append("|--");
        return indentation.toString();
    }

    private static void traverse(File dir, int depth, FileWriter writer) throws IOException {
        File[] files = dir.listFiles();
        if (files != null) {
            for (File f : files) {
                if (f.isFile()) {
                    writer.write(getIndentation(depth) + f.getName() + "，文件大小" + f.length() + "bytes\n");
                } else if (f.isDirectory()) {
                    writer.write(getIndentation(depth) + f.getName() + "（目录）\n");
                    traverse(f, depth + 1, writer);  // 递归
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        String path = "../test5";
        File dir = new File(path);
        if (!dir.exists() || !dir.isDirectory()) {
            System.out.println("目录不存在");
            return;
        }
        File log = new File(dir, "../test5/log.info");
        try (FileWriter fw = new FileWriter(log, false)) {
            traverse(dir, 0, fw);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
