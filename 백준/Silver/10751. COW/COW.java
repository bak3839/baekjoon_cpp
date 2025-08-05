import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long ans = 0, c = 0, co = 0, cow = 0;
        int N = Integer.parseInt(br.readLine());

        String input = br.readLine();
        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);

            if(ch == 'C') {
                c++;
            } else if(ch == 'O') {
                co += c;
            } else {
                cow += co;
            }
        }

        System.out.println(cow);
    }
}
