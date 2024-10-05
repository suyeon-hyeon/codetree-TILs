import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int m;
    public static int[][] grid;

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        grid = new int[n][n];
        int ans = 0;

        // 입력 + 행 로직
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            // 연속인 수 개수
            int cnt = 1;
            boolean isHappy = false;
            for(int j=0;j<n;j++){
                // 입력
                grid[i][j] = Integer.parseInt(st.nextToken());

                // 연속인 경우 count
                if(j>0 && grid[i][j]==grid[i][j-1])
                    cnt++;
                else
                    cnt = 1;

                if(cnt>=m)
                    isHappy = true;
            }

            // count한 수가 m보다 클 경우 ans 증가
            if(isHappy)
              ans++;
        }

        // 열 로직
        for(int i=0;i<n;i++) {
            // 연속인 수 개수
            int cnt = 1;
            boolean isHappy = false;
            for(int j=0;j<n;j++) {
                // 연속인 경우 count
                if(j>0 && grid[j][i]==grid[j-1][i])
                    cnt++;
                else
                    cnt = 1;

                if(cnt>=m)
                    isHappy = true;
            }

            // count한 수가 m보다 클 경우 ans 증가
            if(isHappy)
                ans++;
        }

        System.out.println(ans);
    }
}