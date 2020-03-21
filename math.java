package sequenceIntputStream;

import java.util.Scanner;

public class math {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in =new Scanner(System.in);
		int n=in.nextInt();
		int D[]=new int[n+1];
		D[2]=1;
		D[1]=0;
		for(int i=3;i<=n;i++) {
			D[i]=(i-1)*(D[i-1]+D[i-2]);
		}
		System.out.println(D[n]);
		
		 float [][]f = new float[6][];
		 
	}

}
