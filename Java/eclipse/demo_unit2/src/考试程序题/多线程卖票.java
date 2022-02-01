package ���Գ�����;

class Ticket implements Runnable{		//Runnableʵ����
	private int ticket=20;				//һ��20��Ʊ
	public void run() {
		this.sell();
	}
	public synchronized void sell() {	//�߳�ͬ��
		while(true)
		{
			if(ticket<1) {				//���û��Ʊ��ֹͣ��Ʊ
				System.out.println("Ʊ�����꣡");
				System.exit(0);
			}
			System.out.println(Thread.currentThread().getName()+"������"+(ticket--)+"��Ʊ");
			try {
				Thread.sleep(100);
				notifyAll();	//������������
				wait();
			}catch(InterruptedException ie) {
				ie.printStackTrace();
			}
		}
		
	}
	
}
public class ���߳���Ʊ {
	public static void main(String[] args) {
		Ticket t=new Ticket();
		Thread t1=new Thread(t,"��Ʊ����1��");
		Thread t2=new Thread(t,"��Ʊ����2��");
		Thread t3=new Thread(t,"��Ʊ����3��");
		Thread t4=new Thread(t,"��Ʊ����4��");
		Thread t5=new Thread(t,"��Ʊ����5��");
		t1.start();
		t2.start();
		t3.start();
		t4.start();
		t5.start();
	}
}
