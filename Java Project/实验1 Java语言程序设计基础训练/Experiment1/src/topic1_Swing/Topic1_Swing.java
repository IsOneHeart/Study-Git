package topic1_Swing;

import javax.swing.*;
import java.awt.*;
import java.util.Random;

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

class InputPanel extends JPanel {
    //private String labelResult;
    protected JLabel panelResult;

    protected void updateLabelResult(String result) {
        panelResult.setText(result);
        revalidate(); // 重新布局
        repaint(); // 重新绘制组件
    }

    protected class TopPanel extends JPanel {
        void updateResult(String result) {
            InputPanel.this.updateLabelResult(result);
        }

        public TopPanel() {
            setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10)); //使用流布局
            setBounds(0, 0, 200, 30);
            JTextField textField = new JTextField();
            textField.setPreferredSize(new Dimension(120, 30));
            //textField.setBounds(0,0,150,30);
            add(textField);
            JButton button = new JButton("确认");
            button.setPreferredSize((new Dimension(80, 30)));
            //button.setBounds(200,0,50,30);
            button.addActionListener(e -> {
                try {
                    int score = Integer.parseInt(textField.getText());
                    ScoreEvaluator scoreEvaluator = new ScoreEvaluator();
                    String result = scoreEvaluator.evaluateScore(score);
                    updateResult(result);
                } catch (Exception exception) {
                    updateResult("ERROR：不正确的输入。");
                }
                //revalidate();repaint(); //
            });
            add(button);
            setVisible(true);
        }
    }

    public InputPanel() {
        setLayout(new BorderLayout(10, 10));
        setSize(300, 200);
        TopPanel topPanel = new TopPanel();
        add(topPanel, BorderLayout.NORTH);
        panelResult = new JLabel("", SwingConstants.CENTER);
        add(panelResult, BorderLayout.CENTER);
        setVisible(true);
    }
}

class RandomPanel extends JPanel {
    protected JLabel panelResult;

    protected void updateLabelResult(String result) {
        panelResult.setText(result);
        revalidate(); // 重新布局
        repaint(); // 重新绘制组件
    }

    private String getRandomResult() {
        Random random = new Random();
        int randomResult = random.nextInt(101);
        ScoreEvaluator scoreEvaluator = new ScoreEvaluator();
        return scoreEvaluator.evaluateScore(randomResult);
    }

    private class TopPanel extends JPanel {
        void updateResult(String result) {
            RandomPanel.this.updateLabelResult(result);
        }

        public TopPanel() {
            setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10)); //使用流布局
            setBounds(0, 0, 200, 30);
            JButton button1 = new JButton("随机生成1次");
            button1.setPreferredSize(new Dimension(100, 30));
            button1.addActionListener(e -> updateResult(getRandomResult()));
            add(button1);
            JButton button2 = new JButton("随机生成3次");
            button2.setPreferredSize((new Dimension(100, 30)));
            button2.addActionListener(e -> {
                //使用html格式进行换行操作
                updateResult("<html>" + getRandomResult() + "<br>" + getRandomResult() + "<br>" + getRandomResult() + "</html>");
            });
            add(button2);
            setVisible(true);
        }
    }

    public RandomPanel() {
        setLayout(new BorderLayout(10, 10));
        setSize(300, 200);
        TopPanel topPanel = new TopPanel();
        add(topPanel, BorderLayout.NORTH);
        panelResult = new JLabel("", SwingConstants.CENTER);
        add(panelResult, BorderLayout.CENTER);
        setVisible(true);
    }
}

class MainPanel extends JFrame {
    private final SelectPanel selectPanel;
    private final InputPanel textPanel;
    private final RandomPanel buttonPanel;

    public MainPanel() {
        setSize(350, 200);
        setTitle("分数段检测器(实验1-1，张奕鑫）");
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        selectPanel = new SelectPanel();
        textPanel = new InputPanel();
        buttonPanel = new RandomPanel();
        add(textPanel, BorderLayout.CENTER);
        //add(resultLabel, BorderLayout.SOUTH);
        selectPanel.selectComponent.addActionListener(e -> {
            String selectedItem = (String) selectPanel.selectComponent.getSelectedItem();
            if ("输入".equals(selectedItem)) {
                getContentPane().add(textPanel, BorderLayout.CENTER);
                getContentPane().remove(buttonPanel);
            } else if ("随机生成".equals(selectedItem)) {
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
        String mark;
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

public class Topic1_Swing {
    public static void main(String[] args) {
        // 在事件调度线程中创建和显示 GUI
        SwingUtilities.invokeLater(MainPanel::new);
    }

}
