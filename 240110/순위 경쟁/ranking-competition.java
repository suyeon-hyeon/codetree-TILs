import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cur[] = new int[3];
        boolean first[] = new boolean[3];
        boolean next[] = new boolean[3];
        for (int i = 0; i < 3; i++) {
            first[i] = true;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            char who = st.nextToken().charAt(0);
            int score = Integer.parseInt(st.nextToken());
            cur[who - 'A'] += score;
            int max = cur[0];
            for (int j = 1; j < 3; j++) {
                max = Math.max(max, cur[j]);
            }
            boolean isChange = false;
            for (int j = 0; j < 3; j++) {
                if (max == cur[j])
                    next[j] = true;
                else
                    next[j] = false;
                if (first[j] != next[j]) {
                    first[j] = next[j];
                    isChange = true;
                }
            }
            if (isChange)
                cnt++;
        }
        System.out.println(cnt);
    }
}