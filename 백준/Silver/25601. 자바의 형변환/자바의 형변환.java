import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static HashMap<String, String> parentMap = new HashMap<>();

    public static boolean search(String start, String target) {
        while (start != null) {
            if (start.equals(target)) return true;
            start = parentMap.get(start);
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String child = st.nextToken();
            String parent = st.nextToken();
            parentMap.put(child, parent);
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        String class1 = st.nextToken();
        String class2 = st.nextToken();

        if (search(class1, class2) || search(class2, class1)) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }
}
