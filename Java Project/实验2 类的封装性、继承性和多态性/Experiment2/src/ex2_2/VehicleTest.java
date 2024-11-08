//VehicleTest.java
package ex2_2;

public class VehicleTest {
    public static void main(String[] args){
        Vehicle vehicle = new Vehicle();
        vehicle.setDoorNumber(0);
        vehicle.setWheelNumber(2);
        vehicle.setPassengerNumber(2);
        vehicle.setWeightLimit(300);
        vehicle.drive();
        vehicle=new Car(4,4, 5, 2000, 100);
        vehicle.drive();
        vehicle=new Truck(2, 6, 2, 5000, 1000);
        vehicle.drive();
    }
}
