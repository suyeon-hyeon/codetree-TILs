import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] x = new int[4];
        for(int i=0;i<4;i++) {
            x[i] = Integer.parseInt(st.nextToken());
        }
        boolean isIntersecting = true;
        if(x[2]>x[1] || x[0]>x[3])
            isIntersecting=false;
        if(isIntersecting)
            System.out.println("intersecting");
        else
            System.out.println("nonintersecting");
    }
}