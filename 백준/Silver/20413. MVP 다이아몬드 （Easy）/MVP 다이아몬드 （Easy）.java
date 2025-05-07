import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[] res;
    static HashMap<Character, Integer> grade = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        Character[] key = {'B', 'S', 'G', 'P'};

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < 4; i++) {
            int n = Integer.parseInt(st.nextToken());
            grade.put(key[i], n - 1);
        }
        grade.put('D', grade.get('P') + 1);

        String s = br.readLine();
        res = new int[s.length() + 1];

        for(int i = 1; i <= s.length(); i++) {
            Character c = s.charAt(i - 1);
            if(c == 'D') res[i] = grade.get(c);
            else res[i] = grade.get(c) - res[i - 1];
        }

        System.out.println(Arrays.stream(res).sum());
    }
}
