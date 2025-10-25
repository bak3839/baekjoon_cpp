import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String first = br.readLine();
        String second = br.readLine();

        int count = 0;
        int firstH = Integer.parseInt(first.split(":")[0]);
        int firstM = Integer.parseInt(first.split(":")[1]);
        int secondH = Integer.parseInt(second.split(":")[0]);
        int secondM = Integer.parseInt(second.split(":")[1]);

        while (firstM != secondM) {
            firstM = firstM + 1;
            if (firstM >= 60) {
                firstH = (firstH + 1) % 24;
                firstM = 0;
            }
            count++;
        }

        while (firstH != secondH) {
            firstH = (firstH + 1) % 24;
            count++;
        }

        System.out.println(count);
    }
}
