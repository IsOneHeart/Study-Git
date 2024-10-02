package zip;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

class ZipOutput {
    public void zip(String zipFileName, File inputFile) throws IOException {
        try (ZipOutputStream zipOutputStream = new ZipOutputStream(new FileOutputStream(zipFileName))) {
            zip(zipOutputStream, inputFile, "");
            System.out.println("压缩完成");
        }
    }

    public void zip(ZipOutputStream zipOutputStream, File file, String base) throws IOException {
        if (file.isDirectory()) {
            String dirName = base.isEmpty() ? file.getName() : base + File.separator + file.getName();

            File[] files = file.listFiles();
            if (files != null) {
                for (File childFile : files) {
                    zip(zipOutputStream, childFile, dirName);
                }
            }
        } else {
            String filePath = base.isEmpty() ? file.getName() : base + File.separator + file.getName();
            zipOutputStream.putNextEntry(new ZipEntry(filePath));
            try (FileInputStream in = new FileInputStream(file)) {
                byte[] buffer = new byte[1024];
                int len;
                while ((len = in.read(buffer)) > 0) {
                    zipOutputStream.write(buffer, 0, len);
                }
            }
            zipOutputStream.closeEntry();
        }
    }
}

public class ZIP {
    public static void main(String[] args) {
        ZipOutput book = new ZipOutput();
        try {
            book.zip("file.zip", new File("E:/StudyE/Java/第11章 IO(输入输出)流/file.txt"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}