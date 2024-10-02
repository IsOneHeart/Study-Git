package JDialogDemo;

import java.awt.*; //awt包
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*; //Swing包

class JDialogDemo extends JDialog {
    public JDialogDemo(MyFrame frame) {
        super(frame, "第一个JDialog窗体", true);
        Container container = getContentPane();
        container.add(new JLabel("这是一个对话框"));
        setBounds(120, 120, 100, 100);
    }
}

public class MyFrame extends JFrame {
    public static void main(String[] args) {
        new MyFrame();
    }

    public MyFrame() {
        Container container = getContentPane();
        container.setLayout(null);
        JLabel jl = new JLabel("这是一个JFrame窗体");
        jl.setHorizontalAlignment(SwingConstants.CENTER);
        container.add(jl);
        JButton bl = new JButton("弹出对话框");
        bl.setBounds(10, 10, 100, 21);
        bl.addActionListener(new ActionListener() {  //为按钮添加鼠标单击事件
            /*
            @Override 是 Java 中的一个注解（Annotation），用于指示一个方法声明打算重写超类中的另一个方法声明。
            当你使用 @Override 注解时，编译器会检查该方法是否确实重写了父类中的方法。
            如果没有找到相应的父类方法（比如方法名、参数列表不匹配），编译器会报错，这有助于你及时发现并修正潜在的错误。
            */
            @Override
            public void actionPerformed(ActionEvent e) {
                //使JDialogDemo窗体可见
                new JDialogDemo(MyFrame.this).setVisible(true);
            }
        });
        container.add(bl);
        setTitle("主窗口"); // 给JFrame设置一个标题
        setSize(300, 200); // 设置JFrame的初始大小
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 设置默认关闭操作
        setVisible(true);
    }
}
