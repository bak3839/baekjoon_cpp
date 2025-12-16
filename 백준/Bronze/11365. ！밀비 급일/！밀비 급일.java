import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            String input = br.readLine();
            if ("END".equals(input)) break;

            for (int i = input.length() - 1; i >= 0; i--) {
                System.out.print(input.charAt(i));
            }
            System.out.println();
        }
    }
}
