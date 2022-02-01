package Swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class MyWin extends JFrame
{
    JButton button;
    int i=0;
    Icon icon1,icon2;
    public  MyWin()
    {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        icon1=new ImageIcon("a.jpg");
        icon2=new ImageIcon("b.jpg");
        setBounds(100,100,300,200);
        setVisible(true);
        button=new JButton("按钮",icon1);
        button.setMnemonic('d') ;
        button.setHorizontalTextPosition(AbstractButton.LEFT);
        button.setVerticalTextPosition(AbstractButton.TOP);
        Container con=getContentPane();
        con.setLayout(new FlowLayout());
        con.add(button);
        con.validate();
        button.addActionListener(new ActionListener()
                                 {
                                     @Override
                                     public void actionPerformed(ActionEvent e)
                                     {
                                         i=(i+1)%2;
                                         if(i==1)
                                             button.setIcon(icon2);
                                         else
                                             button.setIcon(icon1);
                                     }
                                 }
        );
    }
}
public class demo
{
    public static void main(String args[])
    {
        new MyWin();
    }
}
