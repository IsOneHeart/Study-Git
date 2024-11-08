//Flying.java
package ex3_2;

interface Flying {
    public void fly();
}

interface Running {
    public void run();
}

interface Swimming{
    public void swim();
}

abstract class Animal {
    private String type;
    public void setType(String type){
        this.type = type;
    }
    public String getType() {
        return type;
    }
    public abstract void eat();
    public abstract void speak();
    public abstract void attack();
}

abstract class Artificiality {
    private String type;
    public void setType(String type){
        this.type = type;
    }
    public String getType() {
        return type;
    }
    public abstract void consume();
    public abstract void sound();
    public abstract void attack();
}

class Dog extends Animal implements Running {
    public Dog(){
        setType("狗");
    }
    public void eat(){
        System.out.println(getType()+"：吞咽");
    }
    public void speak(){
        System.out.println(getType()+"：狂吠");
    }
    public void attack(){
        System.out.println(getType()+"：撕咬");
    }
    public void run(){
        System.out.println(getType()+"：奔跑");
    }
}

class Bird extends Animal implements Flying {
    public Bird(){
        setType("鸟");
    }
    public void eat(){
        System.out.println(getType()+"：啄食");
    }
    public void speak(){
        System.out.println(getType()+"：鸣叫");
    }
    public void attack(){
        System.out.println(getType()+"：俯冲攻击");
    }
    public void fly(){
        System.out.println(getType()+"：飞翔");
    }
}

class 宇宙超级无敌暴龙战士 extends Animal implements Flying, Running, Swimming{
    public 宇宙超级无敌暴龙战士(){
        setType("宇宙超级无敌暴龙战士");
    }
    public void eat(){
        System.out.println(getType()+"：吞噬");
    }
    public void speak(){
        System.out.println(getType()+"：咆哮");
    }
    public void attack(){
        System.out.println(getType()+"：撕咬");
    }
    public void fly(){
        System.out.println(getType()+"：翱翔");
    }
    public void run(){
        System.out.println(getType()+"：疾跑");
    }
    public void swim(){
        System.out.println(getType()+"：激浪");
    }
}

class Car extends Artificiality implements Running {
    public Car(){
        setType("汽车");
    }
    public void consume(){
        System.out.println(getType()+"：消耗汽油");
    }
    public void sound(){
        System.out.println(getType()+"：轰鸣");
    }
    public void attack(){
        System.out.println(getType()+"：撞击");
    }
    public void run(){
        System.out.println(getType()+"：行驶");
    }
}

class Seaplane extends Artificiality implements Flying, Swimming {
    public Seaplane(){
        setType("水上飞机");
    }
    public void consume(){
        System.out.println(getType()+"：消耗燃油");
    }
    public void sound(){
        System.out.println(getType()+"：轰鸣");
    }
    public void attack(){
        System.out.println(getType()+"：坠机");
    }
    public void fly(){
        System.out.println(getType()+"：飞行");
    }
    public void swim(){
        System.out.println(getType()+"：滑行");
    }
}

class 歼星舰 extends Artificiality implements Flying, Running, Swimming {
    public 歼星舰(){
        setType("歼星舰");
    }
    public void consume(){
        System.out.println(getType()+"：使用曲率引擎");
    }
    public void sound(){
        System.out.println(getType()+"：未知");
    }
    public void attack(){
        System.out.println(getType()+"：摧毁星球");
    }
    public void fly(){
        System.out.println(getType()+"：前进五");
    }
    public void swim(){
        System.out.println(getType()+"：前进四");
    }
    public void run(){
        System.out.println(getType()+"：前进三");
    }
}

public class Main {
    public static void main(String[] args){
        Animal[] animals = new Animal[3];
        animals[0] = new Dog();
        animals[1] = new Bird();
        animals[2] = new 宇宙超级无敌暴龙战士();
        for (Animal animal : animals) {
            animal.eat();
            animal.speak();
            animal.attack();
            if (animal instanceof Running) {
                ((Running) animal).run();
            }
            if (animal instanceof Swimming) {
                ((Swimming) animal).swim();
            }
            if (animal instanceof Flying) {
                ((Flying) animal).fly();
            }
        }
        Artificiality[] artificialities = new Artificiality[3];
        artificialities[0] = new Car();
        artificialities[1] = new Seaplane();
        artificialities[2] = new 歼星舰();
        for (Artificiality artificiality : artificialities) {
            artificiality.consume();
            artificiality.sound();
            artificiality.attack();
            if (artificiality instanceof Running) {
                ((Running) artificiality).run();
            }
            if (artificiality instanceof Swimming) {
                ((Swimming) artificiality).swim();
            }
            if (artificiality instanceof Flying) {
                ((Flying) artificiality).fly();
            }
        }
    }
}