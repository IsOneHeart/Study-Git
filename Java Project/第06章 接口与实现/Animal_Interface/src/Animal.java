interface Animal {
    void cry();

    String getAnimalName();
}

class Dog implements Animal {
    public void cry() {
        System.out.println("汪！");
    }

    public String getAnimalName() {
        return "狗🐕";
    }
}

class Cat implements Animal {
    public void cry() {
        System.out.println("喵~");
    }

    public String getAnimalName() {
        return "猫🐱";
    }
}