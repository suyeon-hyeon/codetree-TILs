import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int in[] = new int[n];
        int first = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            in[i] = Integer.parseInt(st.nextToken());
            first = Math.min(first, in[i]);
        }
        int idx = -1, second = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (first == in[i])
                continue;
            if(second>in[i]){
                second = in[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if(second==in[i]){
                if(idx!=-1){
                    idx=-1;
                    break;
                }
                idx = i+1;
            }
        }
        System.out.println(idx);
    }
}