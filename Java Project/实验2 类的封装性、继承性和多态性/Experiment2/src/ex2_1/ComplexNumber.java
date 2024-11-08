//ComplexNumber.java
package ex2_1;

public class ComplexNumber {
    private double real;
    private double imag;

    public ComplexNumber(double real, double imag) {
        this();
        this.real = real;
        this.imag = imag;
    }

    public ComplexNumber() {
    }

    public double getReal() {
        return real;
    }

    public double getImag() {
        return imag;
    }

    public void setImag(double imag) {
        this.imag = imag;
    }

    public void setReal(double real) {
        this.real = real;
    }

    public ComplexNumber add(ComplexNumber c) {
        return new ComplexNumber(real + c.real, imag + c.imag);
    }

    public ComplexNumber sub(ComplexNumber c) {
        return new ComplexNumber(real - c.real, imag - c.imag);
    }

    public ComplexNumber mul(ComplexNumber c) {
        return new ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    public ComplexNumber div(ComplexNumber c) {
        return new ComplexNumber((real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag),
                (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag));
    }

    @Override
    public String toString() {
        if (imag == 0 && real == 0) {
            return "0";
        }
        else if (imag == 0) {
            return "" + real;
        }
        else if (real == 0) {
            return imag + "i";
        }
        else {
            return real + " + " + imag + "i";
        }
    }
}
