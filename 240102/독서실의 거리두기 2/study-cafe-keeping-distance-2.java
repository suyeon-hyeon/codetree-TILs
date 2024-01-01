import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		char[] in = br.readLine().toCharArray();
		int pre = -1, cur = 0;
		int idx = -1, max = 0;
		for(int i=1;i<n;i++) {
			if(in[i]=='1') {
				pre = cur;
				cur = i;
				if(max<cur-pre) {
					max = cur-pre;
					idx = (cur+pre)/2;
				}
			}
		}
		if(cur!=n-1 && max/2<n-1-cur) {
			idx = n-1;
		}
		in[idx] = '1';
		pre = -1;
		cur = 0;
		int min = Integer.MAX_VALUE;
		for(int i=1;i<n;i++) {
			if(in[i]=='1') {
				pre = cur;
				cur = i;
				min = Math.min(min, cur-pre);
			}
		}
		System.out.println(min);
	}
}