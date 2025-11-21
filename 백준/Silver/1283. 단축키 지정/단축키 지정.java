import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        boolean[] used = new boolean[26];
        String[] words = new String[N];
        Integer[] indexes = new Integer[N];

        for (int i = 0; i < N; i++) {
            words[i] = br.readLine();
        }

        for (int i = 0; i < N; i++) {
            String[] sub = words[i].split(" ");

            int index = 0;
            for (int j = 0; j < sub.length; j++) {
                String s = sub[j];
                char ch = s.charAt(0);
                char lowerCase = Character.toLowerCase(ch);
                if (!used[lowerCase - 'a']) {
                    used[lowerCase - 'a'] = true;
                    indexes[i]  = index;
                    break;
                }
                index += s.length() + 1;
            }

            if (indexes[i] != null) continue;

            for (int j = 0; j < words[i].length(); j++) {
                char ch = words[i].charAt(j);
                char lowerCase = Character.toLowerCase(ch);
                if (ch == ' ') continue;
                if (!used[lowerCase - 'a']) {
                    used[lowerCase - 'a'] = true;
                    indexes[i]  = j;
                    break;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            String word = words[i];

            if (indexes[i] == null) {
                System.out.println(word);
                continue;
            }

            for (int j = 0; j < word.length(); j++) {
                if (indexes[i] == j) {
                    System.out.print("[" + word.charAt(j) + "]");
                } else {
                    System.out.print(word.charAt(j));
                }
            }
            System.out.println();
        }
    }
}
