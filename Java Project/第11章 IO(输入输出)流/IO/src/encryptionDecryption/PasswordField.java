package encryptionDecryption;

import javax.swing.*;

public class PasswordField extends JPanel {
    JPasswordField passwordField = new JPasswordField("", 30);

    public PasswordField() {
        add(passwordField);
    }

    public char[] getPassword(){
        return passwordField.getPassword();
    }
}
