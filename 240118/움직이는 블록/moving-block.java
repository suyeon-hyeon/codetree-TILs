import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int block[] = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            block[i] = Integer.parseInt(br.readLine());
            sum += block[i];
        }
        int avg = sum / n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += Math.abs(avg - block[i]);
        }
        System.out.println(ans / 2);
    }
}