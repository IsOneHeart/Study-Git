package topic1;

import java.util.Scanner;

class Topic1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入score值：");
        int num = scanner.nextInt();
        if (num > 100 || num < 0) {
            System.out.println("score值必须为0-100的整数。");
        }
        else{
            String mark = "";
            switch (num / 10) {
                case 6:
                    mark = "及格";
                    break;
                case 7:
                    mark = "一般";
                    break;
                case 8:
                    mark = "良好";
                    break;
                case 9:
                case 10:
                    mark = "优秀";
                    break;
                default:
                    mark = "不及格";
            }
            System.out.println("该生的分数为" + num + "分，成绩为" + mark);
        }
    }
}

/*
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Objects;
import java.util.Random;
import java.util.Scanner;
import java.awt.*;
import javax.swing.*;

class SelectComponent extends AbstractListModel<String> implements ComboBoxModel<String> {
    String selectedItem = "输入";
    String[] items = {"输入", "随机生成"};
    @Override
    public String getElementAt(int index) {
        return items[index];
    }
    @Override
    public int getSize() {
        return items.length;
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
    JComboBox<String> selectComponent = new JComboBox<>(new SelectComponent());
    JLabel selectLabel = new JLabel("Score值获取方式：");

    public SelectPanel() {
        setLayout(new FlowLayout());
        add(selectLabel);
        add(selectComponent);
    }
}

class TextPanel extends JPanel{
    public TextPanel(){
        JTextField textField= new JTextField();
        textField.setPreferredSize(new Dimension(200, 30));
        add(textField);
    }
}

class ButtonPanel extends JPanel{
    private int randomResult;
    public ButtonPanel(){
        //Container container=getContentPane();
        setLayout(new FlowLayout(FlowLayout.CENTER,10,10));
        JButton button1=new JButton("随机生成");
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Random random = new Random();
                randomResult = random.nextInt(101);
            }
        });
        add(button1);
    }
    public int getRandomResult(){
        return randomResult;
    }
}

class LabelPanel extends JPanel{
    public LabelPanel(String string){
        JLabel label=new JLabel(string);
        add(label);
    }
}

class MainPanel extends JFrame {
    private final SelectPanel selectPanel;
    private final TextPanel textPanel;
    private final ButtonPanel buttonPanel;
    private final ScoreEvaluator scoreEvaluator = new ScoreEvaluator();

    // 添加一个标签来显示结果
    private JLabel resultLabel = new JLabel();

    public MainPanel() {
        setSize(350, 200);
        setTitle("分数段检测器(实验1-1，张奕鑫）");
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        selectPanel = new SelectPanel();
        textPanel = new TextPanel();
        buttonPanel = new ButtonPanel();
        add(textPanel, BorderLayout.CENTER);
        String result=scoreEvaluator.evaluateScore(buttonPanel.getRandomResult());
        add(new LabelPanel(result), BorderLayout.SOUTH);
        //add(resultLabel, BorderLayout.SOUTH);
        selectPanel.selectComponent.addActionListener(e -> {
            String selectedItem = (String) selectPanel.selectComponent.getSelectedItem();
            if ("输入".equals(selectedItem)) {
                getContentPane().add(textPanel, BorderLayout.CENTER);
                getContentPane().remove(buttonPanel);
            }
            else if ("随机生成".equals(selectedItem)) {
                getContentPane().add(buttonPanel, BorderLayout.CENTER);
                getContentPane().remove(textPanel);
            }
            revalidate();
            repaint();
        });
        add(selectPanel, BorderLayout.NORTH);
        setVisible(true);
    }
}

class ScoreEvaluator {
    public String evaluateScore(int score) {
        if (score > 100 || score < 0) {
            return "score值必须为0-100的整数。";
        }
        String mark = "";
        switch (score / 10) {
            case 6:
                mark = "及格";
                break;
            case 7:
                mark = "一般";
                break;
            case 8:
                mark = "良好";
                break;
            case 9:
            case 10:
                mark = "优秀";
                break;
            default:
                mark = "不及格";
        }
        return "该生的分数为" + score + "分，成绩为" + mark;
    }
}


public class Topic1 {
    public static void main(String[] args) {
        // 在事件调度线程中创建和显示 GUI
        SwingUtilities.invokeLater(MainPanel::new);
    }
}
*/