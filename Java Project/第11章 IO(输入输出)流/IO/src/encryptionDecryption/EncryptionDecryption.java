package encryptionDecryption;

import java.awt.*;
import java.io.*;
import javax.swing.*;

class TextAreaPanel extends JPanel {
    public CustomButton button = new CustomButton();
    public Label label = new Label();
    public TextArea textArea = new TextArea();

    private class TopPanel extends JPanel {
        public TopPanel() {
            setLayout(new BorderLayout());
            add(button, BorderLayout.EAST);
            add(label, BorderLayout.WEST);
        }
    }

    public TextAreaPanel() {
        setLayout(new BorderLayout());
        TopPanel topPanel = new TopPanel();
        add(topPanel, BorderLayout.NORTH);
        add(textArea, BorderLayout.CENTER);
        setVisible(true);
    }
}

class PasswordPanel extends JPanel {
    public Label label = new Label();
    public PasswordField passwordField = new PasswordField();
    //public CustomButton button = new CustomButton();

    private class TopPanel extends JPanel {
        public TopPanel() {
            setLayout(new BorderLayout());
            add(label, BorderLayout.WEST);
            //add(button,BorderLayout.EAST);
        }
    }

    public PasswordPanel() {
        setLayout(new BorderLayout());
        TopPanel topPanel = new TopPanel();
        add(topPanel, BorderLayout.NORTH);
        add(passwordField, BorderLayout.SOUTH);
        setVisible(true);
    }
}

class MainPanel extends JFrame {
    TextAreaPanel encryptionPanel;
    PasswordPanel passwordPanel;

    public MainPanel() {
        setTitle("加/解密工具");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        encryptionPanel = new TextAreaPanel();
        encryptionPanel.label.setText("加/解密文本：");
        encryptionPanel.button.setText("加/解密");
        encryptionPanel.button.addActionListener(e -> {
            char[] content = encryptionPanel.textArea.getText().toCharArray();
            String password = new String(passwordPanel.passwordField.getPassword());
            if (password.isEmpty()) {
                throw new IllegalArgumentException("Password cannot be empty");
            }
            for (int i = 0; i < content.length; i++) {
                // 循环使用密码中的字符
                int passwordIndex = i % password.length();
                content[i] = (char) (content[i] ^ password.charAt(passwordIndex));
            }
            String encryptedString = new String(content);
            encryptionPanel.textArea.setText(encryptedString);
            File file = new File("log.txt");
            try {
                FileWriter fileWriter = new FileWriter(file);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write(encryptedString);
                bufferedWriter.newLine();
                bufferedWriter.close();
                fileWriter.close();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
            try {
                FileReader fileReader = new FileReader(file);
                BufferedReader bufferedReader = new BufferedReader(fileReader);
                System.out.println(bufferedReader.readLine());
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }

        });
        passwordPanel = new PasswordPanel();
        passwordPanel.label.setText("密钥：");
        //passwordPanel.button.setText("确认");

        // 添加组件到框架
        add(passwordPanel, BorderLayout.NORTH);
        add(encryptionPanel, BorderLayout.CENTER);

        pack(); // 自动调整窗口大小以适应其内容
        setLocationRelativeTo(null); // 窗口居中显示
        //setSize(400,300);
        setVisible(true);
    }
}

public class EncryptionDecryption {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(MainPanel::new);
    }
}
