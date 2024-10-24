import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int m;
    public static int[][] grid;

    // 범위 안의 양수일 경우 크기 반환
    public static int getScore(int x, int y, int k, int l) {
        int cnt = 0;
        for(int i=x;i<=k;i++) {
            for(int j=y;j<=l;j++) {
                if(grid[i][j]>0)
                    cnt++;
                else {
                    cnt=-1;
                    break;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        grid = new int[n][m];

        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 로직
        int ans = -1;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                for(int k=i;k<n;k++) {
                    for(int l=j;l<m;l++) {
                        ans = Math.max(ans,getScore(i,j,k,l));
                    }
                }
            }
        }

        System.out.println(ans);
    }
}