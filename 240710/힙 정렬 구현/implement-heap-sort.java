import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] sorted;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // n개의 원소
        n = Integer.parseInt(br.readLine());
        // 정렬될 배열
        sorted = new int[n+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++)
            sorted[i] = Integer.parseInt(st.nextToken());
        // 힙정렬 수행
        heap_sort(sorted,n);
        // 정렬된 결과물 출력
        for(int i=1;i<=n;i++)
            System.out.print(sorted[i]+" ");
    }

    // 힙정렬 함수
    static void heap_sort(int[] arr, int n) {
        // n/2부터 1까지 heapify 수행
        for(int i=n/2;i>=1;i--)
            heapify(arr, n, i);

        // 최댓값을 정렬 후 heapify(1) 수행
        for(int i=n;i>1;i--) {
            swap(arr, 1, i);
            heapify(arr, i-1, 1);
        }
    }

    // heapify 함수
    static void heapify(int[] arr, int n, int i) {
        // 가장 큰 값
        int largest = i;
        // 자식트리
        int l = i*2;
        int r = i*2+1;

        // 가장 큰 값 판별
        if(l<=n && arr[l]>arr[largest])
            largest = l;
        if(r<=n && arr[r]>arr[largest])
            largest = r;

        // 가장 큰 값이 본인이 아닐 경우 swap 후 재귀
        if(largest!=i) {
            swap(arr, i, largest);
            heapify(arr, n, largest);
        }
    }

    // swap 함수
    static void swap (int[] arr, int idx_a, int idx_b) {
        int tmp = arr[idx_a];
        arr[idx_a] = arr[idx_b];
        arr[idx_b] = tmp;
    }
}