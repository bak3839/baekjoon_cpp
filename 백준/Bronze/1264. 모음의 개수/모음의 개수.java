import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while(true) {
			String input = br.readLine().toUpperCase();

			int count = 0;
			
			if(input.equals("#")) break;
			
			for(int i = 0; i < input.length(); i++) {
				if(input.charAt(i) == 'A' || input.charAt(i) == 'E' 
						|| input.charAt(i) == 'I' || input.charAt(i) == 'O' 
						|| input.charAt(i) == 'U') count++;
			}
            
			System.out.println(count);
		}
	}

}