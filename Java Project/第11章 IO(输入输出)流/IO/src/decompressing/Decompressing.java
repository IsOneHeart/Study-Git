package decompressing;

import java.io.*;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

public class Decompressing {
    public static void main(String[] args) {
        String zipFilePath = "file.zip";
        String destDir = "E:/StudyE/Java/zip";

        File file = new File(zipFilePath);
        ZipInputStream zin = null;

        try {
            zin = new ZipInputStream(new FileInputStream(file));
            ZipEntry entry;
            while ((entry = zin.getNextEntry()) != null) {
                // 跳过目录条目
                if (entry.isDirectory()) {
                    continue;
                }

                // 创建输出文件路径
                File outputFile = new File(destDir + entry.getName());
                if (!outputFile.getParentFile().exists()) {
                    outputFile.getParentFile().mkdirs();
                }

                // 解压文件
                try (BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(outputFile))) {
                    byte[] bytesIn = new byte[4096];
                    int read;
                    while ((read = zin.read(bytesIn)) != -1) {
                        bos.write(bytesIn, 0, read);
                    }
                }
            }
        } catch (IOException e) {
            throw new RuntimeException("Error decompressing file: " + e.getMessage(), e);
        } finally {
            if (zin != null) {
                try {
                    zin.close();
                } catch (IOException e) {
                    // Log or handle exception
                }
            }
        }
    }
}