import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int m;
    public static int[][] grid;

    public static int[] dx = {0, 1, 0, -1};
    public static int[] dy = {1, 0, -1, 0};

    public static int totalMax(int x, int y) {
        int max = 0;
        for(int i=0;i<4;i++) {
            int nx1 = x+dx[i];
            int ny1 = y+dy[i];
            if(nx1<0||nx1>=n||ny1<0||ny1>=n)
                continue;
            int sum = grid[x][y]+grid[nx1][ny1];
            for(int j=i+1;j<4;j++) {
                int nx2 = x+dx[j];
                int ny2 = y+dy[j];
                if(nx2<0||nx2>=n||ny2<0||ny2>=n)
                    continue;
                sum+=grid[nx2][ny2];
                max = Math.max(max,sum);
                sum-=grid[nx2][ny2];
            }
        }
        return max;
    }

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        grid = new int[n][n];
        int ans = 0;
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++){
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 로직

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ans = Math.max(ans,totalMax(i,j));
            }
        }

        System.out.println(ans);
    }
}