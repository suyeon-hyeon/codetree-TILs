import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char in[] = new char[10];
        int start_x = 0, start_y = 0, end_x = 0, end_y = 0;
        for (int i = 0; i < 10; i++) {
            in = br.readLine().toCharArray();
            for (int j = 0; j < 10; j++) {
                if (in[j] == 'L') {
                    start_x = i;
                    start_y = j;
                } else if (in[j] == 'B') {
                    end_x = i;
                    end_y = j;
                }
            }
        }
        System.out.println(Math.abs(end_x - start_x + end_y - start_y) - 1);
    }
}