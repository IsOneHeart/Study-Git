package ExceptionDemo.Number;

class NumberDemo{
    public double count(double num1, double num2) throws NumberException{
        if(num1*num2<Double.MIN_VALUE){
            throw(new NumberException("ERROR:积小于双精度浮点数下限。"));
        }
        if(num1*num2>Double.MAX_VALUE){
            throw(new NumberException("ERROR:积大于双精度浮点数上限。"));
        }
        return num1*num2;
    }
}

public class Number {

    public static void main(String[] args) {
        NumberDemo num=new NumberDemo();
        try{
            System.out.println(num.count(2,2));
            System.out.println(num.count(Double.MAX_VALUE,2));
        }
        catch(NumberException e){
            System.out.println(e.getMessage());
        }
    }
}
