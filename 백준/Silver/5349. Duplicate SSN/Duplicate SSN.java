import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashSet<String> set = new HashSet<>();
        HashSet<String> set2 = new HashSet<>();
        List<String> dup = new ArrayList<>();

        while (true) {
            String num = br.readLine();

            if(num.equals("000-00-0000")) break;

            if (set.contains(num) && !set2.contains(num)) {
                dup.add(num);
                set2.add(num);
            }

            set.add(num);
        }

        dup.sort(Comparator.naturalOrder());
        dup.forEach(System.out::println);
    }
}