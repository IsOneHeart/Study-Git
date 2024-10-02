package encryptionDecryption;

import javax.swing.*;
import java.awt.*;

public class TextArea extends JPanel {
    JTextArea textArea = new JTextArea("", 6, 30);

    public TextArea() {
        setLayout(new BorderLayout());
        add(new JScrollPane(textArea), BorderLayout.CENTER); // 添加滚动条
    }

    public String getText() {
        return textArea.getText();
    }

    public void setText(String text) {
        textArea.setText(text);
    }
}
