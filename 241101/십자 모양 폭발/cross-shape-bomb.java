import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int[][] grid;

    // 이동방향
    public static int[] dx = {0,1,0,-1};
    public static int[] dy = {1,0,-1,0};

    // 특정 블럭을 터뜨리면 십자 모양으로 폭발한 후 가라앉는 함수
    public static void gridBomb(int r, int c) {
        // 폭발
        for(int i=1;i<grid[r][c];i++) {
            for(int j=0;j<4;j++) {
                int nx = r+dx[j]*i;
                int ny = c+dy[j]*i;
                if(nx<0||nx>=n||ny<0||ny>=n)
                    continue;
                grid[nx][ny]=0;
            }
        }
        grid[r][c]=0;

        // 가라앉음
        int[][] temp = new int[n][n];
        for(int i=0;i<n;i++) {
            int idx = n-1;
            for(int j=n-1;j>=0;j--) {
                if(grid[j][i]==0)
                    continue;
                temp[idx--][i]=grid[j][i];
            }
        }
        grid=temp;
    }

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        grid = new int[n][n];

        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++) {
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        // 로직

        gridBomb(r-1,c-1);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++)
                System.out.print(grid[i][j]+" ");
            System.out.println();
        }

    }
}