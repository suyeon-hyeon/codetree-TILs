import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int[][] grid;

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        grid = new int[n][n];
        for(int i=0;i<n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++){
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 로직

        // 변수
        int check_num = 3;
        int coin_sum_first_col = 0;
        int coin_sum_first_row;
        int max_coin_sum = -1;

        // 첫 index 격자 체크
        for(int i=0;i<check_num;i++)
            for(int j=0;j<check_num;j++)
                coin_sum_first_col+=grid[i][j];
        max_coin_sum=coin_sum_first_col;

        // 이후 index 격자 체크
        for(int i=0;i<=n-check_num;i++){

            // col 한칸씩 이동
            if(i>0) {
                for(int j=0;j<check_num;j++) {
                    coin_sum_first_col-=grid[i-1][j];
                    coin_sum_first_col+=grid[i+check_num-1][j];
                }
                max_coin_sum=Math.max(max_coin_sum,coin_sum_first_col);
            }
            coin_sum_first_row = coin_sum_first_col;

            // row 한칸씩 이동
            for(int j=1;j<=n-check_num;j++){
                for(int k=0;k<check_num;k++){
                    coin_sum_first_row-=grid[i+k][j-1];
                    coin_sum_first_row+=grid[i+k][j+check_num-1];
                }
                max_coin_sum=Math.max(max_coin_sum,coin_sum_first_row);
            }
        }

        System.out.println(max_coin_sum);
    }
}