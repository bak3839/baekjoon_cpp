import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;


/*
Algorithm	204
DataAnalysis	207
ArtificialIntelligence	302
CyberSecurity	B101
Network	303
Startup	501
TestStrategy	105
 */
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        Map<String, String> map = Map.of(
            "Algorithm", "204",
            "DataAnalysis",	"207",
            "ArtificialIntelligence",	"302",
            "CyberSecurity",	"B101",
            "Network",	"303",
            "Startup",	"501",
            "TestStrategy",	"105"
        );

        for (int i = 0; i < N; i++) {
            String name = br.readLine();
            System.out.println(map.get(name));
        }

    }
}
