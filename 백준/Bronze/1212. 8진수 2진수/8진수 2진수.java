import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        String[] binaries = {
            "000", "001",
            "010", "011",
            "100", "101",
            "110", "111"
        };
        StringBuilder sb = new StringBuilder();

        for (char ch :  input.toCharArray()) {
            int n = ch - '0';
            sb.append(binaries[n]);
        }

        int index = 0;
        String ans = sb.toString();
        for (int i = 0; i < ans.length() - 1; i++) {
            if (ans.charAt(i) == '1') break;
            index++;
        }

        System.out.println(ans.substring(index));
    }
}
