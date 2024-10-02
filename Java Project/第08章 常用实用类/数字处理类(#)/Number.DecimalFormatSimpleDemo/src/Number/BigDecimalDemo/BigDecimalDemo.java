package Number.BigDecimalDemo;

import java.math.BigDecimal;
import java.math.RoundingMode;

public class BigDecimalDemo {
    static final int location = 10;

    public BigDecimal add(double value1, double value2) {
        BigDecimal b1 = new BigDecimal(Double.toString(value1));
        BigDecimal b2 = new BigDecimal(Double.toString(value2));
        return b1.add(b2);
    }

    public BigDecimal sub(double value1, double value2) {
        BigDecimal b1 = new BigDecimal(Double.toString(value1));
        BigDecimal b2 = new BigDecimal(Double.toString(value2));
        return b1.subtract(b2);
    }

    public BigDecimal mul(double value1,double value2){
        BigDecimal b1 = new BigDecimal(Double.toString(value1));
        BigDecimal b2 = new BigDecimal(Double.toString(value2));
        return b1.multiply(b2);
    }

    public BigDecimal div(double value1,double value2,RoundingMode model){
        return div(value1,value2,model,location);
    }

    public BigDecimal div(double value1, double value2, RoundingMode model,int b){
        if(b<0){
            System.out.println("b值必须大于等于0。");
        }
        BigDecimal b1 = new BigDecimal(Double.toString(value1));
        BigDecimal b2 = new BigDecimal(Double.toString(value2));
        return b1.divide(b2,b,model);
    }

    public static void main(String[] args){
        BigDecimalDemo b=new BigDecimalDemo();
        System.out.println("-7.5+8.9="+b.add(-7.5,8.9));
        System.out.println("-7.5-8.9="+b.sub(-7.5,8.9));
        System.out.println("-7.5*8.9="+b.mul(-7.5,8.9));
        System.out.println("-7.5/8.9="+b.div(-7.5,8.9, RoundingMode.UP)+"(向前进位，保留10位小数)");
        System.out.println("-7.5/8.9="+b.div(-7.5,8.9,RoundingMode.HALF_DOWN,5)+"(四舍五入，保留5位小数)");
    }
}
