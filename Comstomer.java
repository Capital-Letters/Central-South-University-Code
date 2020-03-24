package current;

public class Comstomer implements Runnable {
	Person P=null;
public Comstomer(Person P) {
	this.P=P;
}
	@Override
	public void run() {
		for(int i=0;i<10;i++) {
			if(i%2==0) {
		P.set("Killer", "man");
			}
			else P.set("criminal", "woman");
		}
	}

}
