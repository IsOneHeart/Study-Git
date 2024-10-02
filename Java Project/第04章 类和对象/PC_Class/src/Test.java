class CPU {
    int speed;

    void setSpeed(int speed) {
        this.speed = speed;
        System.out.println("[CPU Speed] Set" + speed);
    }

    int getSpeed() {
        System.out.println("[CPU Speed] Read" + speed);
        return speed;
    }
}

class HardDisk {
    int amount;

    void setAmount(int amount) {
        System.out.println("[HardDisk Amount] Set" + amount);
        this.amount = amount;
    }

    int getAmount() {
        System.out.println("[HardDisk Amount] Read" + amount);
        return amount;
    }
}

class PC {
    private CPU cpu;
    private HardDisk HD;

    void setCPU(CPU cpu) {
        System.out.println("[CPU] ON");
        this.cpu = cpu;
    }

    void setHardDisk(HardDisk HD) {
        System.out.println("[HardDisk Amount] ON");
        this.HD = HD;
    }

    void show() {
        cpu.getSpeed();
        HD.getAmount();
    }
}

public class Test {
    public static void main(String[] args) {
        PC pc=new PC();
        CPU cpu=new CPU();
        HardDisk HD=new HardDisk();
        cpu.setSpeed(50);
        HD.setAmount(2);
        pc.setCPU(cpu);
        pc.setHardDisk(HD);
        pc.show();
    }
}