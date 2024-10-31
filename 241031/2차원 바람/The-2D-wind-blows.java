import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int m;
    public static int q;
    public static int[][] grid;
    public static int[] r1;
    public static int[] c1;
    public static int[] r2;
    public static int[] c2;

    // 동서남북
    public static int[] dx = {0, 1, 0, -1};
    public static int[] dy = {1, 0, -1, 0};

    // 평균 계산 함수
    public static void calAvg(int r1, int c1, int r2, int c2) {
        int[][] avg = new int[n][m];
        for(int i=r1;i<=r2;i++) {
            for(int j=c1;j<=c2;j++) {
                int cnt = 1;
                int sum = grid[i][j];
                for(int k=0;k<4;k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx<0||nx>=n||ny<0||ny>=m)
                        continue;
                    cnt++;
                    sum+=grid[nx][ny];
                }
                avg[i][j]=sum/cnt;
            }
        }
        for(int i=r1;i<=r2;i++) {
            if (c2 + 1 - c1 >= 0) System.arraycopy(avg[i], c1, grid[i], c1, c2 + 1 - c1);
        }
    }

    // 바람으로 인한 이동 함수
    public static void move(int r1, int c1, int r2, int c2) {
        int temp = grid[r1][c1];
        for(int i=r1;i<r2;i++)
            grid[i][c1]=grid[i+1][c1];
        for(int i=c1;i<c2;i++)
            grid[r2][i]=grid[r2][i+1];
        for(int i=r2;i>r1;i--)
            grid[i][c2]=grid[i-1][c2];
        for(int i=c2;i>c1+1;i--)
            grid[r1][i]=grid[r1][i-1];
        grid[r1][c1+1]=temp;
    }

    // 바람 함수
    public static void wind(int r1, int c1, int r2, int c2) {
        // 지정 지점 이동
        move(r1, c1, r2, c2);
        calAvg(r1, c1, r2, c2);
    }

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        grid = new int[n][m];

        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        r1 = new int[q];
        c1 = new int[q];
        r2 = new int[q];
        c2 = new int[q];

        for(int i=0;i<q;i++) {
            st = new StringTokenizer(br.readLine());
            r1[i] = Integer.parseInt(st.nextToken());
            c1[i] = Integer.parseInt(st.nextToken());
            r2[i] = Integer.parseInt(st.nextToken());
            c2[i] = Integer.parseInt(st.nextToken());
        }

        // 로직

        for(int i=0;i<q;i++) {
            wind(r1[i]-1,c1[i]-1,r2[i]-1,c2[i]-1);
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                System.out.print(grid[i][j]+" ");
            }
            System.out.println();
        }
    }
}