public class Simulator {
    void playSound(Animal animal) {
        System.out.print(animal.getAnimalName() + "：");
        animal.cry();
    }

}
