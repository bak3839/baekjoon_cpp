import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s1 =  st.nextToken();
            String s2 =  st.nextToken();

            char[] arr1 = s1.toCharArray();
            char[] arr2 = s2.toCharArray();

            Arrays.sort(arr1);
            Arrays.sort(arr2);

            boolean flag = true;
            for (int j = 0; j < arr1.length; j++) {
                if (arr1[j] == arr2[j]) continue;

                flag = false;
                break;
            }

            System.out.println(flag ? "Possible" : "Impossible");
        }
    }
}
