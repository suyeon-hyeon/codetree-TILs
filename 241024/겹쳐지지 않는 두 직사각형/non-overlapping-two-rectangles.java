import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int m;
    public static int[][] grid;

    // 범위 안의 합
    public static int getScore(int x, int y, int k, int l) {
        int sum = 0;
        for(int i=x;i<=k;i++) {
            for(int j=y;j<=l;j++) {
                sum+=grid[i][j];
            }
        }
        return sum;
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
        int ans = Integer.MIN_VALUE;

        // 8중 for문 (...)
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                for(int k=i;k<n;k++) {
                    for(int l=j;l<m;l++) {
                        for(int a=0;a<n;a++) {
                            for(int b=0;b<m;b++) {
                                if(a<=k&&b<=l)
                                    continue;
                                for(int c=a;c<n;c++) {
                                    for(int d=b;d<m;d++) {
                                        ans = Math.max(ans, getScore(i,j,k,l)+getScore(a,b,c,d));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        System.out.println(ans);
    }
}