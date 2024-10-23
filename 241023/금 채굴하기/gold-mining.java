import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int m;
    public static int[][] grid;

    public static int[] dx = {0, 1, 0, -1};
    public static int[] dy = {1, 0, -1, 0};

    // 특정 칸에서 손해 없이 얻을 수 있는 가장 많은 골드 수
    public static int totalGold(int x, int y) {

        int max = grid[x][y];  // 손해 없이 얻을 수 있는 가장 많은 골드 수
        int cnt = max;  // 마름모 범위 안에 존재하는 골드 수
        for(int size=1; size<=n; size++) {
            int cost = size*size + (size+1)*(size+1);  // 채굴 비용
            // 늘어난 사이즈만큼 골드 수 카운트
            for(int d=0; d<4; d++){ // 동서남북 방향
                // 동서남북 꼭지점 골드 카운트
                int nx = x + size*dx[d];
                int ny = y + size*dy[d];
                if(nx>=0&&nx<n&&ny>=0&&ny<n)
                    cnt+=grid[nx][ny];

                // 꼭지점 사이의 골드 카운트
                int d1 = (d+1)%4;
                int d2 = (d+2)%4;
                for(int i=0;i<size-1;i++) {
                    nx+=dx[d1]+dx[d2];
                    ny+=dy[d1]+dy[d2];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n)
                        cnt+=grid[nx][ny];
                }
            }
            if(cost<=m*cnt)
                max = cnt;
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
                ans = Math.max(ans, totalGold(i,j));
            }
        }

        System.out.println(ans);
    }
}