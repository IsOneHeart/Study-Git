public class WarpClass {
    public static void main(String[] args){
        Integer integer_ = 1;
        //Integer integer_ = new Integer(1); //不必要的装箱
        System.out.println(integer_.compareTo(2));
        int _integer = integer_;
        System.out.println(_integer);

        Character char1='A',char2='A';
        char1=Character.toUpperCase(char2);
        System.out.println(char1.equals(char2));
        char1=Character.toLowerCase(char1);
        System.out.println(char1.equals(char2));

        Boolean bool=true;
        System.out.println(bool.toString());
    }
}
