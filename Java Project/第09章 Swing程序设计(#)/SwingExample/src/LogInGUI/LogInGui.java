package LogInGUI;

import java.awt.*;
import javax.swing.*;

class IDPanel extends JPanel {
    String text = "";
    JTextField textField = new JTextField(text, 15);

    public IDPanel() {
        setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));
        add(new JLabel("账号"));
        add(textField);
    }

    public String getText() {
        return textField.getText();
    }

    public void setVoid() {
        textField.setText("");
    }
}

class PasswordPanel extends JPanel {
    String password = "";
    JPasswordField passwordFiled = new JPasswordField(password, 15);

    public PasswordPanel() {
        setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));
        add(new JLabel("密码"));
        add(passwordFiled);
    }

    public String getPassword() {
        return String.valueOf(passwordFiled.getPassword());
    }

    public void setVoid() {
        passwordFiled.setText("");
    }
}

class Dialog1 extends JDialog {
    public Dialog1() {
        setSize(100, 50);
        JLabel label = new JLabel("登录成功！");
        add(label);
    }
}

class Dialog2 extends JDialog {
    public Dialog2() {
        setSize(100, 50);
        JLabel label = new JLabel("账号或密码错误！");
        add(label);
    }
}

class Main extends JFrame {
    public Main() {
        setSize(300, 200);
        setName("登录");
        IDPanel idPanel = new IDPanel();
        add(idPanel, BorderLayout.NORTH);
        PasswordPanel passwordPanel = new PasswordPanel();
        add(passwordPanel, BorderLayout.CENTER);
        LogInButton logInButton = new LogInButton();
        logInButton.button1.addActionListener(e -> {
            if (idPanel.getText().equals("mr") && passwordPanel.getPassword().equals("mrsoft")) {
                new Dialog1().setVisible(true);
            } else {
                new Dialog2().setVisible(true);
            }
        });
        logInButton.button2.addActionListener(e -> {
            idPanel.setVoid();
            passwordPanel.setVoid();
        });
        add(logInButton, BorderLayout.SOUTH);
        setVisible(true);
    }
}

class LogInButton extends JPanel {
    public JButton button1 = new JButton("提交");
    public JButton button2 = new JButton("重置");

    public LogInButton() {
        setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));
        add(button1);
        add(button2);
    }
}

public class LogInGui {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(Main::new);
    }
}
