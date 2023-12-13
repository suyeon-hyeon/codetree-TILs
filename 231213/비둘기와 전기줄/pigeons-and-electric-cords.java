import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] doolgi = new int[11];
        for (int i = 1; i <= 10; i++)
            doolgi[i] = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int pos = Integer.parseInt(st.nextToken());
            if (doolgi[num] != -1 && doolgi[num] != pos)
                cnt++;
            doolgi[num] = pos;
        }
        System.out.println(cnt);
    }
}