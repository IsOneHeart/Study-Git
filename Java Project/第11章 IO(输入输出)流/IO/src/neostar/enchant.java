package neostar;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.TreeMap;

public class enchant {
    public static void main(String[] args) {
        EnchantedBookRender enchantedBookRender = new EnchantedBookRender();
        HashMap<String, String> renders = new HashMap<>();
        renders.put("01", "锋利");
        renders.put("02", "亡灵杀手");
        renders.put("03","节肢杀手");
        renders.put("04","击退");
        renders.put("05","火焰附加");
        renders.put("06","保护");
        renders.put("07","火焰保护");
        renders.put("08","摔落保护");
        renders.put("09","爆炸保护");
        renders.put("10","弹射物保护");
        renders.put("11","水下呼吸");
        renders.put("12","水下速掘");
        renders.put("13","深海探索者");
        renders.put("14","冰霜行者");
        renders.put("15","灵魂疾行");
        renders.put("16","效率");
        renders.put("17","精准采集");
        renders.put("18","耐久");
        renders.put("19","抢夺");
        renders.put("20","时运");
        renders.put("21","海之眷顾");
        renders.put("22","饵钓");
        renders.put("23","力量");
        renders.put("24","火矢");
        renders.put("25","冲击");
        renders.put("26","无限");
        renders.put("27","荆棘");
        renders.put("28","经验修补");
        renders.put("29","绑定诅咒");
        renders.put("30","消失诅咒");
        renders.put("31","忠诚");
        renders.put("32","穿刺");
        renders.put("33","激流");
        renders.put("34","引雷");
        renders.put("35","多重射击");
        renders.put("36","快速装填");
        renders.put("37","穿透");
        renders.put("38","迅捷潜行");
        renders.put("39","致密");
        renders.put("40","破甲");
        renders.put("41","风爆");
        enchantedBookRender.setParentPath("textures/items/enchanted_book/eb");
        enchantedBookRender.add(renders);
        enchantedBookRender.outPutJson();
    }
}
