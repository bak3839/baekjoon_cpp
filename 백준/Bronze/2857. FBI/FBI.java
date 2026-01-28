import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < 5; i++) {
            String name = br.readLine();

            if (name.contains("FBI")) {
                list.add(i + 1);
            }
        }

        if (list.isEmpty()) System.out.println("HE GOT AWAY!");
        else list.forEach(n -> System.out.print(n + " "));
    }
}
