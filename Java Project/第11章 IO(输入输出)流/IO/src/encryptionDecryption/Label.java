package encryptionDecryption;

import javax.swing.*;

public class Label extends JPanel {
    JLabel label= new JLabel("");

    public Label() {
        add(label);
    }

    public void setText(String text) {
        label.setText(text);
    }
}
