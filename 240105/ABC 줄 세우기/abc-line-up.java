import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        char in[] = new char[n];
        for (int i = 0; i < n; i++) {
            in[i] = st.nextToken().charAt(0);
        }
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (in[j] > in[j + 1]) {
                    char temp = in[j];
                    in[j] = in[j + 1];
                    in[j + 1] = temp;
                    cnt++;
                }
            }
        }
        System.out.println(cnt);
    }
}