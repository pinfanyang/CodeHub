package ����;

class Ticket implements Runnable{	//Runnableʵ����
	private int ticket=1155;	//11*105��Ʊ,�����0��ʼ
	public void run() {	this.sell();}
	
	public synchronized void sell() {	//�߳�ͬ��
		while(true) {
			if(ticket<1) {		//û��Ʊ��ֹͣ��Ʊ
				System.out.println("Ʊ�����꣡");
				System.exit(0);
			}
			System.out.println(Thread.currentThread().getName()+"�����ĳ�ƱΪ:��"+(ticket--)+"��Ʊ��");
			try {
				Thread.sleep(100);
				notifyAll();		//������������
				wait();
			}catch(InterruptedException ie) {
				ie.printStackTrace();
			}
			
		}
	}
}
public class ���߳� {
	public static void main(String[] args) {
		Ticket t=new Ticket();
		Thread t1=new Thread(t,"��Ʊ����1��");
		Thread t2=new Thread(t,"��Ʊ����2��");
		Thread t3=new Thread(t,"��Ʊ����3��");
		t1.start();
		t2.start();
		t3.start();
	}
}
