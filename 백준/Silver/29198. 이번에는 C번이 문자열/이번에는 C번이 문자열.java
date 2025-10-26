import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        String[] words = new String[N];
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < N; i++) {
            sb = new StringBuilder();
            String input = br.readLine();
            char[] ch = input.toCharArray();
            Arrays.sort(ch);
            for (char c : ch) {
                sb.append(c);
            }
            words[i] = sb.toString();
        }
        Arrays.sort(words);

        sb = new StringBuilder();
        for (int i = 0; i < K; i++) {
            sb.append(words[i]);
        }

        List<Character> list = new ArrayList<>();
        for (char ch : sb.toString().toCharArray()) {
            list.add(ch);
        }
        list.sort(Character::compareTo);
        list.forEach(System.out::print);
    }
}
