import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int[][] grid;

    // 이동방향
    public static int[] dx = {-1, -1, 1, 1};
    public static int[] dy = {1, -1, -1, 1};

    // 이동 함수
    public static void move(int r, int c, int m1, int m2, int m3, int m4, int dir) {
        int temp = grid[r][c];
        if(dir==0) {
            for(int i=0;i<m4;i++) {
                grid[r][c]=grid[r-dx[3]][c-dy[3]];
                r-=dx[3];
                c-=dy[3];
            }
            for(int i=0;i<m3;i++) {
                grid[r][c]=grid[r-dx[2]][c-dy[2]];
                r-=dx[2];
                c-=dy[2];
            }
            for(int i=0;i<m2;i++) {
                grid[r][c]=grid[r-dx[1]][c-dy[1]];
                r-=dx[1];
                c-=dy[1];
            }
            for(int i=0;i<m1-1;i++) {
                grid[r][c]=grid[r-dx[0]][c-dy[0]];
                r-=dx[0];
                c-=dy[0];
            }
            grid[r][c]=temp;
        } else if(dir==1) {
            for(int i=0;i<m1;i++) {
                grid[r][c]=grid[r+dx[0]][c+dy[0]];
                r+=dx[0];
                c+=dy[0];
            }
            for(int i=0;i<m2;i++) {
                grid[r][c]=grid[r+dx[1]][c+dy[1]];
                r+=dx[1];
                c+=dy[1];
            }
            for(int i=0;i<m3;i++) {
                grid[r][c]=grid[r+dx[2]][c+dy[2]];
                r+=dx[2];
                c+=dy[2];
            }
            for(int i=0;i<m4-1;i++) {
                grid[r][c]=grid[r+dx[3]][c+dy[3]];
                r+=dx[3];
                c+=dy[3];
            }
            grid[r][c]=temp;
        }
    }

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        grid = new int[n][n];

        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++){
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int m1 = Integer.parseInt(st.nextToken());
        int m2 = Integer.parseInt(st.nextToken());
        int m3 = Integer.parseInt(st.nextToken());
        int m4 = Integer.parseInt(st.nextToken());
        int dir = Integer.parseInt(st.nextToken());

        // 로직

        move(r-1,c-1,m1,m2,m3,m4,dir);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                System.out.print(grid[i][j]+" ");
            }
            System.out.println();
        }
    }
}