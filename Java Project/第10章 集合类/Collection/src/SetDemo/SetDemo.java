package SetDemo;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class SetDemo {
    public static void main(String[] args) {
        List<Character> list = new ArrayList<Character>();
        Set<Character> set = new HashSet<>();
        list.add('A');
        list.add('a');
        list.add('c');
        list.add('C');
        list.add('a');
        set.add('A');
        set.add('a');
        set.add('c');
        set.add('C');
        set.add('a');
        System.out.println("List：" + list);
        System.out.println("Set：" + set);
    }
}
