import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    static int N, E;
    static List<HashSet<Integer>> songs;

    public static void shareSong(List<Integer> nums) {
        HashSet<Integer> shareSongs = new HashSet<>();

        for (int num : nums) {
            shareSongs.addAll(songs.get(num));
        }

        for (int num : nums) {
            songs.get(num).addAll(shareSongs);
        }
    }

    public static void createSong(int song, List<Integer> nums) {
        for(int n : nums) {
            songs.get(n).add(song);
        }
    }

    public static void findAllSongsKnow() {
        int size = songs.get(1).size(), ans = 0;

        for(int i = 1; i <= N; i++) {
            if(songs.get(i).size() != size) continue;
            System.out.println(i);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        E = Integer.parseInt(br.readLine());

        //songs = new ArrayList<>(N + 1);
        songs = IntStream
                .rangeClosed(1, N + 1)
                .mapToObj(i -> new HashSet<Integer>())
                .collect(Collectors.toList());

        for(int i = 0; i < E; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            List<Integer> nums = new ArrayList<>();

            for(int j = 0; j < k; j++) {
                nums.add(Integer.parseInt(st.nextToken()));
            }
            nums.sort(Integer::compare);

            if (nums.get(0) == 1) createSong(i, nums);
            else shareSong(nums);
        }

        findAllSongsKnow();
    }
}
