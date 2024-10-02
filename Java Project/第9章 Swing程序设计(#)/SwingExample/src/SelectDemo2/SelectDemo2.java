package SelectDemo2;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

class SelectComponent extends AbstractListModel<String> implements ComboBoxModel<String> {
    private ArrayList<String> items = new ArrayList<>();
    private String selectedItem = null;

    public void addItem(String item) {
        items.add(item);
        fireContentsChanged(this, -1, -1); // 通知监听器内容已更改
    }

    @Override
    public String getElementAt(int index) {
        return items.get(index);
    }

    @Override
    public int getSize() {
        return items.size();
    }

    @Override
    public void setSelectedItem(Object item) {
        selectedItem = (String) item;
    }

    @Override
    public Object getSelectedItem() {
        return selectedItem;
    }
}

class SelectPanel extends JPanel {
    private JComboBox<String> selectComponent;
    private JLabel selectLabel = new JLabel("请选择：");
    private SelectComponent comboModel = new SelectComponent();

    public SelectPanel() {
        setSize(200, 150);
        setLayout(new FlowLayout());
        add(selectLabel);

        selectComponent = new JComboBox<>(comboModel);
        add(selectComponent);

        JButton button = new JButton("添加项");
        button.addActionListener(e -> {
            comboModel.addItem("新建项");
            selectComponent.setSelectedIndex(comboModel.getSize() - 1);
        });
        add(button);
    }
}

public class SelectDemo2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Select Demo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(new SelectPanel());
        frame.pack();
        frame.setLocationRelativeTo(null); // 居中显示
        frame.setVisible(true);
    }
}