import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		char[] input = br.readLine().toCharArray();
		int pre = -1, cur = 0, len = 0;
		int start = -1, end = n;
		for(int i=1;i<n;i++) {
			if(input[i]=='1') {
				pre=cur;
				cur=i;
				if(len<cur-pre) {
					len = cur-pre;
					end=cur;
					start=pre;
				}
			}
		}
		input[(end-start)/2]='1';
		pre = -1; cur = 0; len = n;
		for(int i=1;i<n;i++) {
			if(input[i]=='1') {
				pre=cur;
				cur=i;
				if(len>cur-pre) {
					len = cur-pre;
				}
			}
		}
		System.out.println(len);
	}
}