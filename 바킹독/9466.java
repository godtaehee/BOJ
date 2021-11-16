import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

  static int n;

  static int[][] f;
  static boolean[] check;

  public static void judge(int x) {

    Stack<Integer> q = new Stack<>();
    q.add(f[x][0]);
    check[f[x][0]] = true;
    while (!q.isEmpty()) {
      int p = q.pop();
      if (!check[f[p][0]]) {
        check[f[p][0]] = true;
        q.add(f[p][0]);
      }
    }
  }


  public static void main(String[] args) throws IOException {

    int testCase;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    testCase = Integer.parseInt(st.nextToken());

    while (testCase --> 0) {
      int answer = 0;
      n = Integer.parseInt(br.readLine());
      f = new int[n+1][1];
      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < n; i++) {
        int tmp = Integer.parseInt(st.nextToken());
        f[i+1][0] = tmp;
      }

      for (int i = 1; i <= n; i++) {
        check = new boolean[n+1];
        judge(i);
        if (!check[i]) {
          answer++;
        }
      }
      System.out.println(answer);
    }
  }
}
