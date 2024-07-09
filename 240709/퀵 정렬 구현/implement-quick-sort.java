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
        sorted = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++)
            sorted[i] = Integer.parseInt(st.nextToken());
        // 퀵정렬 수행
        quick_sort(sorted,0,n-1);
        // 정렬된 결과물 출력
        for(int i=0;i<n;i++)
            System.out.print(sorted[i]+" ");
    }

    // 퀵정렬 함수
    static void quick_sort(int[] arr, int low, int high) {
        // 재귀 조건
        if(low<high){
            // 두 그룹으로 분류
            int pos = partition(arr, low, high);

            // pivot 기준으로 분류된 두 그룹을 다시 퀵정렬
            quick_sort(arr, low, pos-1);
            quick_sort(arr, pos+1, high);
        }
    }

    // pivot 기준으로 분류해주는 함수
    static int partition(int[] arr, int low, int high) {
        int pivot = select_pivot(arr, low, high);
        int i = low-1;
        // pivot보다 작을 경우 swap
        for(int j=low;j<=high-1;j++) {
            if(arr[j]<pivot){
                i++;
                swap(arr,i,j);
            }
        }
        // 한바퀴 다 돈 후에 pivot과 swap
        swap(arr,i+1,high);
        return i+1;
    }

    // pivot 선택 함수
    static int select_pivot(int[] arr, int low, int high) {
        if(arr.length<=3)
            return arr[high];
        // 중간값과 pivot값
        int mid = (low+high)/2;
        int pivot_idx;
        // 만일 맨 오른쪽이 pivot일 경우 swap 없이 바로 return
        if(arr[mid]<=arr[high]&&arr[high]<=arr[low])
            return arr[high];
        // 그 이외의 경우 pivot과 high swap 후 high값 return
        if(arr[low]<=arr[mid]&&arr[mid]<=arr[high])
            pivot_idx = mid;
        else
            pivot_idx = low;
        swap(arr, pivot_idx, high);
        return arr[high];
    }

    // swap 함수
    static void swap (int[] arr, int idx_a, int idx_b) {
        int tmp = arr[idx_a];
        arr[idx_a] = arr[idx_b];
        arr[idx_b] = tmp;
    }
}