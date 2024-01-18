import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int odd = 0, even = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            if (num % 2 == 1)
                odd++;
            else
                even++;
        }
        int cnt = 0;
        if (even > odd) {
            cnt = odd * 2 + 1;
        } else if (odd == even) {
            cnt = odd * 2;
        } else {
            cnt = even * 2;
            odd -= even;
            if (odd % 3 == 0)
                cnt += odd / 3 * 2;
            else if (odd % 3 == 2)
                cnt += odd / 3 * 2 + 1;
            else
                cnt += odd / 3 * 2 - 1;
        }
        System.out.println(cnt);
    }
}