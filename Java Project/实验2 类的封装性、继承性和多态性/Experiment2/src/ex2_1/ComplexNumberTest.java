//ComplexNumberTest.java
package ex2_1;

public class ComplexNumberTest {
    public static void main(String[] args) {
        ComplexNumber c1 = new ComplexNumber(1, 2);
        ComplexNumber c2 = new ComplexNumber();
        c2.setReal(3);
        c2.setImag(4);
        ComplexNumber c3 = c1.add(c2);
        ComplexNumber c4 = c1.sub(c2);
        ComplexNumber c5 = c1.mul(c2);
        ComplexNumber c6 = c1.div(c2);
        System.out.println(c1+"的实数部分是"+c1.getReal()+"，虚数部分是"+c1.getImag());
        System.out.println("("+c1+") + ("+c2+") = "+c3);
        System.out.println("("+c1+") - ("+c2+") = "+c4);
        System.out.println("("+c1+") × ("+c2+") = "+c5);
        System.out.println("("+c1+") ÷ ("+c2+") = "+c6);
    }
}
