import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    static String key, ciphertext;
    static char[][] cipherArray, plainArray;
    static List<Key> keys = new ArrayList<>();
    static StringBuilder plain = new StringBuilder();

    static class Key {
        char ch;
        int column;

        public Key(char ch, int column) {
            this.ch = ch;
            this.column = column;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        key = br.readLine();
        ciphertext = br.readLine();

        int keyLen = key.length();
        int plainLen = ciphertext.length();
        cipherArray = new char[plainLen / keyLen][keyLen];
        plainArray = new char[plainLen / keyLen][keyLen];

        for (int i = 0; i < key.length(); i++) {
            char c = key.charAt(i);
            keys.add(new Key(c, i));
        }
        keys.sort((k1, k2) -> k1.ch == k2.ch ? k1.column - k2.column : k1.ch - k2.ch);

        int index = 0;

        for (int j = 0; j < keyLen; j++) {
            for (int i = 0; i < plainLen / keyLen; i++) {
                cipherArray[i][j] = ciphertext.charAt(index++);
            }
        }

        for(int i = 0; i < cipherArray.length; i++) {
            for(int j = 0; j < cipherArray[i].length; j++) {
                Key key = keys.get(j);
                plainArray[i][key.column] = cipherArray[i][j];
            }
        }

        for (char[] chars : plainArray) {
            for (char ch : chars) {
                System.out.print(ch);
            }
        }
    }
}
