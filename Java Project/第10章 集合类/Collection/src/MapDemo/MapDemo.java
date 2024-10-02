package MapDemo;

import java.util.HashMap;
import java.util.Map;

class Emp {
    String id;

    public void setId(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }
}

public class MapDemo {
    public static void main(String[] args) {
        Map<String, Emp> map = new HashMap<>();
        Emp emp = new Emp();
        emp.setId("015");
        map.put(emp.getId(), emp);
        map.remove("015");
    }
}
