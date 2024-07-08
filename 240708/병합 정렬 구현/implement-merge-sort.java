import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] sorted;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // n개의 원소
        n = Integer.parseInt(br.readLine());
        sorted = new int[n];
        merged_arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++)
            sorted[i] = Integer.parseInt(st.nextToken());
        merge_sort(sorted, 0, n-1);
        for(int i=0;i<n;i++)
            System.out.print(sorted[i]+" ");
    }

    static void merge_sort(int[] arr, int low, int high) {
        if(low<high){
            int mid = (low+high)/2;
            merge_sort(arr, low, mid);
            merge_sort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }

    static int[] merged_arr;

    static void merge(int[] arr, int low, int mid, int high) {
        int i = low, j = mid+1;

        int k = low;
        while(i<=mid && j<=high) {
            if(arr[i]<arr[j]){
                merged_arr[k]=arr[i];
                k++; i++;
            } else {
                merged_arr[k] = arr[j];
                k++; j++;
            }
        }

        while(i<=mid){
            merged_arr[k]=arr[i];
            k++; i++;
        }

        while(j<=high) {
            merged_arr[k]=arr[j];
            k++; j++;
        }

        for(k=low;k<=high;k++){
            arr[k] = merged_arr[k];
        }
    }
}