package current;

import current.Actor.Actor1;

public class Actor extends Thread {
	public class Actor1 {

	}
	public void run() {
		System.out.println(getName()+"线程名称");
		int count=0;
		boolean keeprunning=true;
		while(keeprunning) {
		System.out.println("运行的线程"+(++count));
		if(count==100) {
			keeprunning=false;
		}
		
		if(count%10==0) {
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		}
		System.out.println(getName()+"线程结束");
	}
	public static void main(String []arg) {
		Actor actor=new Actor();
		actor.setName("one");
		actor.start();
		Thread actorone=new Thread(new Actorone(),"Ms.run");
		actorone.start();
	}
}
	
class Actorone implements Runnable{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		System.out.println(Thread.currentThread().getName()+"线程名称");
		int count=0;
		boolean keeprunning=true;
		while(keeprunning) {
		System.out.println(Thread.currentThread().getName()+"运行的线程"+(++count));
		if(count==100) {
			keeprunning=false;
		}
		
		if(count%10==0) {
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		}
		System.out.println(Thread.currentThread().getName()+"线程结束");
		
	}
	
}


