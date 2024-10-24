import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int[][] grid;

    // 동서남북
//    public static int[] dx = {0, 1, 0, -1};
//    public static int[] dy = {1, 0, -1, 0};

    // 이동방향
    public static int[] dx = {1, -1, -1, 1};
    public static int[] dy = {-1, -1, 1, 1};

    // 범위 확인 함수
    public static boolean inRange(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }
    
    // 특정 시작점에서 출발한 기울어진 직사각형 중 가장 큰 합
    public static int getScore(int x, int y, int k, int l) {
        int[] moveNum = new int[]{k,l,k,l};
        int sum = 0;
        
        for(int d=0;d<4;d++)
            for(int q=0;q<moveNum[d];q++) {
                x+=dx[d];
                y+=dy[d];
                if(!inRange(x,y))
                    return 0;
                
                sum+=grid[x][y];
            }
        return sum;
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

        // 로직
        int ans = 0;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=1;k<n;k++)
                    for(int l=1;l<n;l++)
                        ans=Math.max(ans, getScore(i,j,k,l));

        System.out.println(ans);
    }
}