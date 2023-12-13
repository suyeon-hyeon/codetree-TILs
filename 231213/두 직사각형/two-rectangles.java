import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] rect1 = new int[4];
        int[] rect2 = new int[4];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<4;i++)
            rect1[i]=Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<4;i++)
            rect2[i]=Integer.parseInt(st.nextToken());
        if(rect1[2]<rect2[0]||rect1[3]<rect2[1]||
            rect1[0]>rect2[2]||rect1[1]>rect2[3])
            System.out.println("nonoverlapping");
        else
            System.out.println("overlapping");
    }
}