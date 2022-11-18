import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(bf.readLine());
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			list.add(Integer.parseInt(bf.readLine()));
		}
		Collections.sort(list);
        StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(list.get(i)+"\n");
		}
        bw.write(sb.toString());
        bw.flush();
		bf.close();
        bw.close();
	}
}