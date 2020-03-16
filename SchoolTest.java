package com.imooc.test;
import com.imooc.model.*;


public class SchoolTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Subject sub1=new Subject("计算机科学与应用","J0001",4);
		Student stu1=new Student("501","jack","man",200);
//		System.out.println(stu1.introduction());
		System.out.println(stu1.introduction("computer science", 4));
	}

}
