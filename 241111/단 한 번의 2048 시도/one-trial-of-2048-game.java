import java.io.*;
import java.util.*;

public class Main {
    // 변수 선언
//    public static int n;
    public static int[][] grid;

    // 이동방향
    public static int[] dx = {0, 1, 0, -1};
    public static int[] dy = {1, 0, -1, 0};

    public static void game2048 (char dir) {
        int[][] temp = new int[4][4];
        switch (dir) {
            case 'L':
                for(int i=0;i<4;i++) {
                    boolean isDouble = false;
                    int idx = 0;
                    int preVal = 0;
                    for(int j=0;j<4;j++) {
                        if(grid[i][j]==0)
                            continue;
                        if(!isDouble && grid[i][j]==preVal) {
                            isDouble=true;
                            temp[i][idx-1]*=2;
                        } else {
                            isDouble=false;
                            preVal=grid[i][j];
                            temp[i][idx++]=preVal;
                        }
                    }
                }
                break;
            case 'U':
                for(int j=0;j<4;j++) {
                    boolean isDouble = false;
                    int idx = 0;
                    int preVal = 0;
                    for(int i=0;i<4;i++) {
                        if(grid[i][j]==0)
                            continue;
                        if(!isDouble && grid[i][j]==preVal) {
                            isDouble=true;
                            temp[idx-1][j]*=2;
                        } else {
                            isDouble=false;
                            preVal=grid[i][j];
                            temp[idx++][j]=preVal;
                        }
                    }
                }
                break;
            case 'R':
                for(int i=0;i<4;i++) {
                    boolean isDouble = false;
                    int idx = 3;
                    int preVal = 0;
                    for(int j=3;j>=0;j--) {
                        if(grid[i][j]==0)
                            continue;
                        if(!isDouble && grid[i][j]==preVal) {
                            isDouble=true;
                            temp[i][idx+1]*=2;
                        } else {
                            isDouble=false;
                            preVal=grid[i][j];
                            temp[i][idx--]=preVal;
                        }
                    }
                }
                break;
            case 'D':
                for(int j=0;j<4;j++) {
                    boolean isDouble = false;
                    int idx = 3;
                    int preVal = 0;
                    for(int i=3;i>=0;i--) {
                        if(grid[i][j]==0)
                            continue;
                        if(!isDouble && grid[i][j]==preVal) {
                            isDouble=true;
                            temp[idx+1][j]*=2;
                        } else {
                            isDouble=false;
                            preVal=grid[i][j];
                            temp[idx--][j]=preVal;
                        }
                    }
                }
                break;
        }
        grid=temp;
    }

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        grid = new int[4][4];

        for(int i=0;i<4;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0;j<4;j++) {
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        char dir = br.readLine().charAt(0);
        game2048(dir);

        // 로직

        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                System.out.print(grid[i][j]+" ");
            }
            System.out.println();
        }

    }
}