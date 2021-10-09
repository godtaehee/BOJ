import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
  public static int[] a;
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n;
    n = Integer.parseInt(br.readLine());

    StringTokenizer st = new StringTokenizer(br.readLine());

    a = new int[n];

    for (int i = 0; i < n; i++) {
      a[i] = Integer.parseInt(st.nextToken());
    }
    int m = Integer.parseInt(br.readLine());

    st = new StringTokenizer(br.readLine());

    Arrays.sort(a);

    for (int i = 0; i < m; i++) {
      int target = Integer.parseInt(st.nextToken());
      System.out.println(binarySearch(0,n-1,target));
    }

  }

  public static int binarySearch(int start, int end, int target) {
    while(start <= end) {
      int mid = (start + end) / 2;
      if (a[mid] == target) return 1;
      else if(a[mid] < target) {
        start = mid + 1;
      }else
        end = mid -1;
    }
      return 0;
  }
}
