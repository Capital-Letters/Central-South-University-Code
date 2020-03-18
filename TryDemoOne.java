package com.imooc.test;

import java.util.Scanner;

public class TryDemoOne {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(System.in);
		try {
			int one=input.nextInt();
			int two=input.nextInt();
			System.out.println(one/two);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			
		}
		
	}

}
