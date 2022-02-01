package 做题;

class Ticket implements Runnable{	//Runnable实现类
	private int ticket=1155;	//11*105张票,后面从0开始
	public void run() {	this.sell();}
	
	public synchronized void sell() {	//线程同步
		while(true) {
			if(ticket<1) {		//没有票则停止售票
				System.out.println("票已售完！");
				System.exit(0);
			}
			System.out.println(Thread.currentThread().getName()+"卖出的车票为:第"+(ticket--)+"张票。");
			try {
				Thread.sleep(100);
				notifyAll();		//唤醒其他窗口
				wait();
			}catch(InterruptedException ie) {
				ie.printStackTrace();
			}
			
		}
	}
}
public class 多线程 {
	public static void main(String[] args) {
		Ticket t=new Ticket();
		Thread t1=new Thread(t,"卖票窗口1：");
		Thread t2=new Thread(t,"卖票窗口2：");
		Thread t3=new Thread(t,"卖票窗口3：");
		t1.start();
		t2.start();
		t3.start();
	}
}
