package Number.Maths;

class Round {
    private double radius;

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double area() {
        return Math.PI * Math.pow(radius, 2);
    }
}

public class Maths {
    public static void main(String[] args) {
        Round round = new Round();
        round.setRadius(5);
        double area = round.area();
        System.out.printf("圆的面积：%.5f", area);
    }
}
