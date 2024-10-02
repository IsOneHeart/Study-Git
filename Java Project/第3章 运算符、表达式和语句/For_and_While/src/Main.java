public class Main {
    public static void main(String[] args) {
        int num = 1, sum = 0;
        float sumF = 0;
        for (byte i = 0; i < 10; i++) {
            int temp = num * (++num);
            sum += (num + temp);
            sumF += (num + 1 / (float) temp);
            num = temp;
        }
        System.out.println("1!+2!+3!+...+10!=" + sum);

        System.out.println("100以内的全部素数：");
        for (int i = 1; i < 100; i++) {
            for (int j = 2; j < Math.sqrt(i); j++) {
                if (i % j == 0) {
                    System.out.print(i + " ");
                    break;
                }
            }
        }
        System.out.println();

        System.out.println("for循环计算的1+1/2!+1/3!+1/4!+...+1/10!=" + sumF);
        sumF = 0;
        num = 1;
        byte count = 0;
        do {
            int temp = num * (++num);
            sum += (num + temp);
            sumF += (num + 1 / (float) temp);
            num = temp;
            count++;
        } while (count < 10);
        System.out.println("do-while循环计算的1+1/2!+1/3!+1/4!+...+1/10!=" + sumF);

        System.out.println("1000以内的全部完数：");
        for (int i = 1; i < 1000; i++) {
            int countW = 0;
            for (int j = 1; j < Math.sqrt(i); j++) {
                if (i % j != 0) {
                    countW += j;
                }
            }
            if (countW == i) {
                System.out.print(i + " ");
            }
        }

        num=8;
        int count8=0;
        for(int i=0;i<10;i++){
            count8+=num*10+num;
        }
        System.out.println("8+88+888+...的前10项和="+count8);

        int i=1;
        count8=0;
        while(count8<8888){
            count8+=i;
            i++;
        }
        System.out.println("满足1+2+3+...+n<8888的最大正整数n="+count8);
    }
}