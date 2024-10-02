package SelectDemo;

import javax.swing.*; //Swing包
import java.awt.*;

class SelectComponent extends AbstractListModel<String> implements ComboBoxModel<String> {
    String selectedItem = null;
    String[] colors = {"红", "蓝", "绿", "黄"};

    public String getElementAt(int index) {
        return colors[index];
    }

    public int getSize() {
        return colors.length;
    }

    public void setSelectedItem(Object item) {
        selectedItem = (String) item;
    }

    public Object getSelectedItem() {
        return selectedItem;
    }
}

class SelectPanel extends JPanel {
    JComboBox<String> selectComponent = new JComboBox<>(new SelectComponent());
    JLabel selectLabel = new JLabel("请选择颜色：");

    public SelectPanel() {
        setLayout(new FlowLayout());
        add(selectLabel);
        add(selectComponent);
        //setVisible(true);
    }
}

class RadioButtonPanel extends JPanel {
    public RadioButtonPanel() {
        JRadioButton radioButton1 = new JRadioButton(), radioButton2 = new JRadioButton();
        ButtonGroup buttonGroup = new ButtonGroup();
        buttonGroup.add(radioButton1);
        buttonGroup.add(radioButton2);
        setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));
        JLabel label1 = new JLabel("男"), label2 = new JLabel("女");
        add(radioButton1);
        add(label1);
        add(radioButton2);
        add(label2);
    }
}

class ButtonPanel extends JPanel {
    public ButtonPanel() {
        setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));
        add(new JButton("确认"));
        add(new JButton("取消"));
    }
}

class MainPanel extends JFrame {
    public MainPanel() {
        setTitle("队伍选择器");
        setSize(300, 200);
        setVisible(true);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        //Container c=getContentPane();
        setLayout(new BorderLayout());
        SelectPanel selectPanel = new SelectPanel();
        add(selectPanel, BorderLayout.NORTH);
        add(new RadioButtonPanel(), BorderLayout.CENTER);
        add(new ButtonPanel(), BorderLayout.SOUTH);
    }
}

public class SelectGUI {
    public static void main(String[] args) {
        // 在事件调度线程中创建和显示 GUI
        SwingUtilities.invokeLater(MainPanel::new);
    }
}
