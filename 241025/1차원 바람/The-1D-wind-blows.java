import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
    public static int n;
    public static int m;
    public static int q;
    public static int[][] grid;
    public static int[] r;
    public static char[] d;

    // 전파 가능 여부 함수
    public static boolean canSpread(int r, char d) {
        boolean isSame = false;
        if(d=='U') {
            for(int i=0;i<m;i++) {
                if(grid[r][i]==grid[r+1][i]) {
                    isSame = true;
                    break;
                }
            }
        } else if(d=='D') {
            for(int i=0;i<m;i++) {
                if(grid[r][i]==grid[r-1][i]) {
                    isSame = true;
                    break;
                }
            }
        }
        return isSame;
    }

    // 바람 혹은 전파로 인한 움직임 함수
    public static void move(int r, char d) {
        if(d=='L') {
            int temp = grid[r][m-1];
            for(int i=0;i<m-1;i++) {
                grid[r][m-1-i] = grid[r][m-2-i];
            }
            grid[r][0] = temp;
        } else if(d=='R') {
            int temp = grid[r][0];
            for(int i=0;i<m-1;i++) {
                grid[r][i] = grid[r][i+1];
            }
            grid[r][m-1] = temp;
        }
    }
    
    // 바람 함수
    public static void wind(int r, char d) {
        // 지정 지점 이동
        move(r,d);
        
        // 위 전파
        char upperPrdDir = d;
        for(int i=r-1;i>=0;i--) {
            if(canSpread(i,'U')) {
                if(upperPrdDir=='L') {
                    upperPrdDir='R';
                    move(i,upperPrdDir);
                } else if(upperPrdDir=='R') {
                    upperPrdDir='L';
                    move(i,upperPrdDir);
                }
            } else 
                break;
        }
        
        // 아래 전파
        char lowerPrdDir = d;
        for(int i=r+1;i<n;i++) {
            if(canSpread(i,'D')) {
                if(lowerPrdDir=='L') {
                    lowerPrdDir='R';
                    move(i,lowerPrdDir);
                } else if(lowerPrdDir=='R') {
                    lowerPrdDir='L';
                    move(i,lowerPrdDir);
                }
            } else
                break;
        }
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

        r = new int[q];
        d = new char[q];

        for(int i=0;i<q;i++) {
            st = new StringTokenizer(br.readLine());
            r[i] = Integer.parseInt(st.nextToken());
            d[i] = st.nextToken().charAt(0);
        }

        // 로직

        for(int i=0;i<q;i++) {
            wind(r[i]-1,d[i]);
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                System.out.print(grid[i][j]+" ");
            }
            System.out.println();
        }
    }
}