package ExceptionDemo.StudentException;

class MyException extends Exception{
    public MyException(String ErrorMessage){
        //构造方法
        super(ErrorMessage);
    }
}

class Student {
    private int m;
    public void setM(int m){
        this.m=m;
    }
    public void speak() throws MyException {
        if(this.m>1000){
            throw(new MyException("参数不得大于1000"));
        }
        else{
            System.out.println("Set M successfully.");
        }
    }
}

public class StudentException {
    public static void main(String[] args) {
        Student student=new Student();
        student.setM(100);
        try {
            student.speak();
        } catch (MyException e) {
            System.out.println(e.getMessage());
        }
        student.setM(1001);
        try {
            student.speak();
        } catch (MyException e) {
            System.out.println(e.getMessage());
        }
    }
}
