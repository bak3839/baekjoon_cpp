import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int ans = 0;
    static int[] arr = new int[4];
    static boolean[] checked = new boolean[10000];

    public static int findTimeNum(int[] nums) {
        String target = "9999";

        for(int i = 0; i < 4; i++) {
            StringBuilder sb = new StringBuilder();
            int idx = i, cnt = 0;

            while(cnt < 4) {
                if(idx >= 4) idx = 0;

                cnt++;
                sb.append(nums[idx++]);
            }

            if(target.compareTo(sb.toString()) > 0) {
                target = sb.toString();
            }
        }

        return Integer.parseInt(target);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < 4; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int target = findTimeNum(arr);

        for(int i = 1111; i <= 9999; i++) {
            if(String.valueOf(i).contains("0")) continue;

            int[] nums = new int[4];
            for(int j = 0; j < 4; j++) {
                nums[j] = String.valueOf(i).charAt(j) - '0';
            }

            int res = findTimeNum(nums);
            checked[res] = true;
        }

        for(int i = 1111; i <= target; i++) {
            if(checked[i]) ans++;
        }

        System.out.println(ans);
    }
}
