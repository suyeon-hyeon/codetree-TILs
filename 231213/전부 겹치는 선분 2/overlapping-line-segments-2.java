import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int exceptStartIdx = -1;
    static int exceptEndIdx = -1;
    static int startIdx = -1;
    static int endIdx = -1;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] start = new int[n];
        int[] end = new int[n];
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            start[i] = Integer.parseInt(st.nextToken());
            end[i] = Integer.parseInt(st.nextToken());
        }
        if(isIntersecting(n, start, end, -1)){
            if(isIntersecting(n,start,end, exceptStartIdx)||isIntersecting(n,start,end,exceptEndIdx))
                System.out.println("Yes");
            else
                System.out.println("No");
        }
        else
            System.out.println("Yes");
    }
    // 겹치는 여부 확인 함수
    static boolean isIntersecting(int n, int[] start, int[] end, int exceptIdx){
        int maxStart = 0;
        int minEnd = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            if(i==exceptIdx)
                continue;
            if(maxStart<start[i]){
                maxStart=start[i];
                startIdx=i;
            }
            if(minEnd>end[i]){
                minEnd=end[i];
                endIdx=i;
            }
        }
        if(minEnd<maxStart){
            if(exceptIdx==exceptStartIdx)
                exceptStartIdx = startIdx;
            if(exceptIdx==exceptEndIdx)
                exceptEndIdx = endIdx;
            return false;
        } else
            return true;
    }
}