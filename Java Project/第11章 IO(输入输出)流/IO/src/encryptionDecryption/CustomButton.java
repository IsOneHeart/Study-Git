package encryptionDecryption;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

public class CustomButton extends JPanel {
    private JButton button= new JButton("");

    public CustomButton() {
        add(button);
        setLayout(new FlowLayout(FlowLayout.CENTER));
    }

    public void setText(String label) {
        button.setText(label);
    }

    public CustomButton(String label) {
        this(); // 调用无参构造函数
        setText(label); // 设置按钮文本
    }

    public void addActionListener(ActionListener actionListener) {
        button.addActionListener(actionListener);
    }
}
