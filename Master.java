package com.imooc.animal;

public class Master {
	public void feed(Cat cat) {
		cat.eat();
		cat.playBall();
	}
	
	public void feed(Dog dog) {
		dog.eat();
		dog.sleep();
	}
	
	public void feed(Animal obj) {
		if(obj instanceof Cat){
			Cat temp=(Cat) obj;
			temp.eat();
		}
		else if(obj instanceof Dog) {
			Dog temp=(Dog) obj;
			temp.eat();
		}
	}
}
