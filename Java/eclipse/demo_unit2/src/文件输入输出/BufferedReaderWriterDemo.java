package 文件输入输出;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;
class BufferedReaderWriterDemo extends JFrame implements ActionListener{
	JMenuBar menubar;
	JMenu menu;
	JMenuItem item1,item2,item3;
	JScrollPane scrollPane;
	JTextArea textarea;
	
	public BufferedReaderWriterDemo() {
		menubar=new JMenuBar( ); 
		menu=new JMenu("文件");  
		this.setJMenuBar(menubar);  
		menubar.add(menu);
		textarea=new JTextArea( );
		scrollPane = new JScrollPane(textarea);
		this.add(textarea);    
		item1=new JMenuItem("打开"); 
		item2=new JMenuItem("保存");
		item3=new JMenuItem("退出");   
		menu.add(item1);
		menu.addSeparator( );
		menu.add(item2);
		menu.addSeparator( );
		menu.add(item3);    
		item1.addActionListener(this);
		item2.addActionListener(this);
		item3.addActionListener(this);
		setSize(300,260);
		setVisible(true);  
	}
	public void actionPerformed(ActionEvent e){ 
		if(e.getSource( )==item1){
			textarea.setText("");
			JFileChooser fc=new JFileChooser( );
			fc.setCurrentDirectory(new File("."));
			try{
				if(fc.showOpenDialog(this)==JFileChooser.APPROVE_OPTION)
				{
					String filename = fc.getSelectedFile( ).getPath( );
					setTitle(filename);
					FileReader fr = new FileReader(filename); //创建字符输入流对象
					BufferedReader br=new BufferedReader(fr); //创建过滤器输入流对象
					String s="";
					while((s=br.readLine())!=null){
						textarea.append(s+"\n");        
					}
					br.close( );      
					fr.close( );
				}
			}catch(Exception ex){
				System.out.print(ex.toString());
			}
		}
		
		if(e.getSource( )==item2){
			JFileChooser fc=new JFileChooser( );
			fc.setCurrentDirectory(new File("."));
			try{
				if(fc.showSaveDialog(this)==JFileChooser.APPROVE_OPTION)
			{
					String filename = fc.getSelectedFile( ).getAbsolutePath( );
					FileWriter fw=new FileWriter(filename); //创建字符输出流对象
					BufferedWriter bw=new BufferedWriter(fw); //创建过滤器输出流对象
					String s =textarea.getText( );
					bw.write(s);
					bw.close( );
					fw.close( );
			}
			}catch(Exception ex){
				System.out.print(ex.toString( ));
			}
		}
		
		if(e.getSource( )==item3)
			System.exit(0); 
		}
		public static void main(String args[ ])
		{
		new BufferedReaderWriterDemo( );
		}
}
	
	
