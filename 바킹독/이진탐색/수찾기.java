import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
  static int n;
  static int[] a;
  static int[] answer;
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    n = Integer.parseInt(br.readLine());

    StringTokenizer st = new StringTokenizer(br.readLine());

     a = new int[n];

    for (int i = 0; i < n; i++) {
      a[i] = Integer.parseInt(st.nextToken());
    }

    int m = Integer.parseInt(br.readLine());

    answer = new int[m];

    st = new StringTokenizer(br.readLine());

    Arrays.sort(a);

    for (int i = 0; i < m; i++) {
      int target = Integer.parseInt(st.nextToken());
      binarySearch(0, n-1, target, i);
    }

    for (int i = 0; i < m; i++) {
      System.out.println(answer[i]);
    }
  }

  static void binarySearch(int start, int end, int target, int idx) {

    if (start > end) return;
    int mid = (start + end)/2;

    if (a[mid] == target) {
      answer[idx] = 1;
      return;
    }else if(a[mid] > target) {
      binarySearch(start, mid-1, target, idx);
    }else
      binarySearch(mid+1, end, target, idx);
  }
}
