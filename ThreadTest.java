package current;

class MyThread extends Thread{
	public MyThread(String name) {
		super(name);
	}
	
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		super.run();
	}
}

class PrintRunnable implements Runnable{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		System.out.println(Thread.currentThread().getName()+"is running");
	}
	
}

public class ThreadTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		MyThread mt=new MyThread("thread1");
//		mt.start();
		PrintRunnable pr1=new PrintRunnable();
		Thread t1=new Thread(pr1);
		t1.start();
		
	}

}
