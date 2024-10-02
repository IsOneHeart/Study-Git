public abstract class Animal {
    abstract void cry();

    abstract String getAnimalName();
}

class Dog extends Animal {
    void cry() {
        System.out.println("汪！");
    }

    String getAnimalName() {
        return "狗🐕";
    }
}

class Cat extends Animal {
    void cry() {
        System.out.println("喵~");
    }

    String getAnimalName() {
        return "猫🐱";
    }
}