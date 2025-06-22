import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N, ans;
    static String[] names;

    public static boolean compare(String name1, String name2) {
        int len = Math.min(name1.length(), name2.length());
        String sub1, sub2;

        for(int i = 1; i <= len; i++) {
            sub1 = name1.substring(name1.length() - i);
            sub2 = name2.substring(0, i);

            if(sub1.equals(sub2)) return true;
        }

        for(int i = 1; i <= len; i++) {
            sub1 = name2.substring(name2.length() - i);
            sub2 = name1.substring(0, i);

            if(sub1.equals(sub2)) return true;
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        names = new String[N];

        for (int i = 0; i < N; i++) {
            names[i] = br.readLine();
        }

        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(compare(names[i], names[j])) { ans++; };
            }
        }

        System.out.println(ans);
    }
}
