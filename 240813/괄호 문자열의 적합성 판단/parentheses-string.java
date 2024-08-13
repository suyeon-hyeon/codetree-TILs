import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // n개의 원소
        char[] arr = br.readLine().toCharArray();
        Stack<Character> stack = new Stack<>();
        boolean isCorrect = true;
        for(int i=0;i<arr.length;i++) {
            if(arr[i]=='(') {
                stack.push('(');
            } else if(arr[i]==')' && !stack.isEmpty()) {
                stack.pop();
            } else {
                isCorrect = false;
                break;
            }
        }
        if(isCorrect && stack.isEmpty())
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}