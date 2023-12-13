import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] start = new int[n];
        int[] end = new int[n];
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            start[i] = Integer.parseInt(st.nextToken());
            end[i] = Integer.parseInt(st.nextToken());
        }
        boolean isIntersecting = false;
        for (int i=0;i<n;i++){
            int maxStart = 0;
            int minEnd = Integer.MAX_VALUE;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                maxStart=Math.max(maxStart,start[j]);
                minEnd=Math.min(minEnd,end[j]);
            }
            if(minEnd>=maxStart){
                isIntersecting = true;
                break;
            }
        }
        if(isIntersecting)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}