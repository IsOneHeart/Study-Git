//PrinterTest.java
package ex4_2;

public class PrinterTest {
    public static void main(String[] args) throws NoConnectionException {
        LaserPrinter laserPrinter = new LaserPrinter();
        WirelessPrinter wirelessPrinter = new WirelessPrinter();

        String[] laserContents = {"Hello", "World"};
        laserPrinter.load(laserContents);
        laserPrinter.load(laserContents);
        laserPrinter.print();

        String[] wirelessContents = {"Wireless", "Printer"};
        try {
            wirelessPrinter.load(wirelessContents);
            wirelessPrinter.print();
        } catch (NoConnectionException e) {
            System.out.println(e.getMessage());
        }finally {
            wirelessPrinter.wirelessConnect();
            wirelessPrinter.load(wirelessContents);
            wirelessPrinter.print();
        }
    }
}
