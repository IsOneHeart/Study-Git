//Vehicle.java
package ex2_2;

public class Vehicle {
    private int doorNumber;
    private int wheelNumber;
    private int passengerNumber;
    private int weightLimit;

    void drive() {
        System.out.println("Driving " + this.getClass().getName() + " now...");
        System.out.println("doorNumber: " + doorNumber);
        System.out.println("wheelNumber: " + wheelNumber);
        System.out.println("passengerNumber: " + passengerNumber);
        System.out.println("weightLimit: " + weightLimit);
    }
    public void setDoorNumber(int doorNumber) {
        this.doorNumber = doorNumber;
    }
    public void setWheelNumber(int wheelNumber) {
        this.wheelNumber = wheelNumber;
    }
    public void setPassengerNumber(int passengerNumber) {
        this.passengerNumber = passengerNumber;
    }
    public void setWeightLimit(int weightLimit) {
        this.weightLimit = weightLimit;
    }
    public int getDoorNumber() {
        return doorNumber;
    }
    public int getWheelNumber() {
        return wheelNumber;
    }
    public int getPassengerNumber() {
        return passengerNumber;
    }
    public int getWeightLimit() {
        return weightLimit;
    }
    Vehicle(){}
    Vehicle(int doorNumber, int wheelNumber, int passengerNumber, int weightLimit) {
        this();
        this.doorNumber = doorNumber;
        this.wheelNumber = wheelNumber;
        this.passengerNumber = passengerNumber;
        this.weightLimit = weightLimit;
    }
}

class Car extends Vehicle{
    private double gasolineAmount;
    public double getGasolineAmount(){
        return gasolineAmount;
    }
    public void setGasolineAmount(double gasolineAmount) {
        this.gasolineAmount = gasolineAmount;
    }
    @Override
    public void drive() {
        System.out.println("Driving " + this.getClass().getName() + " now...");
        System.out.println("doorNumber: " + getDoorNumber());
        System.out.println("wheelNumber: " + getWheelNumber());
        System.out.println("passengerNumber: " + getPassengerNumber());
        System.out.println("weightLimit: " + getWeightLimit());
        System.out.println("gasolineAmount: " + gasolineAmount);
    }
    Car(){
        super();
    }
    Car(int doorNumber, int wheelNumber, int passengerNumber, int weightLimit, double gasolineAmount) {
        super(doorNumber, wheelNumber, passengerNumber, weightLimit);
        this.gasolineAmount = gasolineAmount;
    }
}

class Truck extends Vehicle{
    private double dieselAmount;
    public double getDieselAmount(){
        return dieselAmount;
    }
    public void setDieselAmount(double dieselAmount) {
        this.dieselAmount = dieselAmount;
    }
    @Override
    public void drive() {
        System.out.println("Driving " + this.getClass().getName() + " now...");
        System.out.println("doorNumber: " + getDoorNumber());
        System.out.println("wheelNumber: " + getWheelNumber());
        System.out.println("passengerNumber: " + getPassengerNumber());
        System.out.println("weightLimit: " + getWeightLimit());
        System.out.println("dieselAmount: " + dieselAmount);
    }
    Truck(){
        super();
    }
    Truck(int doorNumber, int wheelNumber, int passengerNumber, int weightLimit, double dieselAmount) {
        super(doorNumber, wheelNumber, passengerNumber, weightLimit);
        this.dieselAmount = dieselAmount;
    }
}


