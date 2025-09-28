import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int X = Integer.parseInt(br.readLine());
        String input = br.readLine();
        LinkedList<Character> list = new LinkedList<>();

        for (char ch : input.toCharArray()) {
            list.addLast(ch);
        }

        int M = 0, W = 0;

        while (!list.isEmpty()) {
            char first = list.getFirst();
            int diff = Math.abs(M - W);

            if (diff < X) {
                int res = first == 'M' ? M++ : W++;
                list.removeFirst();
            } else if (diff == X) {
                if (M > W && first == 'M') {
                    if (list.size() < 2 || list.get(1) != 'W') break;
                    W++;
                    list.remove(1);
                }
                else if (W > M && first == 'W') {
                    if (list.size() < 2 || list.get(1) != 'M') break;
                    M++;
                    list.remove(1);
                }
                else {
                    int res = first == 'M' ? M++ : W++;
                    list.removeFirst();
                }
            }
        }

        System.out.println(W + M);
    }
}
