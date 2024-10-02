package JFrameDemo;

import java.awt.*; //awt包
import javax.swing.*; //Swing包

public class JFrameDemo extends JFrame{
    public void CreateJFrame(String title){
        JFrame jf =new JFrame(title);
        Container container =jf.getContentPane(); //获取一个容器
        JLabel jl=new JLabel("这是JFrame窗体");
        jl.setHorizontalAlignment(SwingConstants.CENTER); //标签文字居中
        container.add(jl); //添加标签至容器
        container.setBackground(Color.white);
        jf.setVisible(true); //使窗体可视
        jf.setSize(200,150);
        jf.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE); //窗体关闭方式
    }
    public static void main(String[] args){
        new JFrameDemo().CreateJFrame("我的第一个Swing程序");
    }
}
