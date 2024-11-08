//Printer.java
package ex4_2;

abstract public class Printer {
    protected String[] buffer;

    abstract public void load(String[] contents) throws NoConnectionException;

    abstract public void print();
}

interface Wireless {
    void wirelessConnect();
}

class NoConnectionException extends Exception {
    private String message = "网络未连接！";

    public String getMessage() {
        return message;
    }
}

class LaserPrinter extends Printer {
    public void print() {
        if (buffer != null) { //无需buffer.length>0
            for (String s : buffer) {
                System.out.print(s + " ");
            }
            System.out.println();
            buffer = null;
        }
    }

    public void load(String[] contents) {
        print();
        buffer = contents;
    }
}

class WirelessPrinter extends Printer implements Wireless {
    private boolean status = false;

    public void print() {
        if (buffer != null) {
            for (String s : buffer) {
                System.out.print(s + " ");
            }
            System.out.println();
            buffer = null;
        }
    }

    public void load(String[] contents) throws NoConnectionException {
        print();
        if (status)
            buffer = contents;
        else
            throw new NoConnectionException();
    }

    public void wirelessConnect() {
        status = true;
    }
}