import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int barn1 = 1000, barn2 = 1000;
    static Set<Integer> set = new HashSet<>();
    static List<Integer> bucket1 = new ArrayList<>();
    static List<Integer> bucket2 = new ArrayList<>();

    public static void search(int count) {
        if(count == 4) {
            set.add(barn1);
            return;
        }

        if(count % 2 == 0) {
            // 1
            for(int i = 0; i < bucket1.size(); i++) {
                int volume = bucket1.get(i);
                barn1 -= volume;
                barn2 += volume;

                bucket1.remove(i);
                bucket2.add(volume);
                search(count + 1);
                bucket1.add(i, volume);
                bucket2.remove(bucket2.size() - 1);

                barn1 += volume;
                barn2 -= volume;
            }
        } else {
            // 2
            for(int i = 0; i < bucket2.size(); i++) {
                int volume = bucket2.get(i);
                barn2 -= volume;
                barn1 += volume;

                bucket2.remove(i);
                bucket1.add(volume);
                search(count + 1);
                bucket2.add(i, volume);
                bucket1.remove(bucket1.size() - 1);

                barn2 += volume;
                barn1 -= volume;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 10; i++) {
            bucket1.add(Integer.parseInt(st.nextToken()));
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 10; i++) {
            bucket2.add(Integer.parseInt(st.nextToken()));
        }

        search(0);
        System.out.println(set.size());
    }
}
