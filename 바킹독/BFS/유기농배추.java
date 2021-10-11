import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
  static int[] dx = {1,-1,0,0};
  static int[] dy = {0,0,1,-1};

  static int[][] f;
  static boolean[][] check;
  static int m;
  static int n;

  static class Pair {
    public int x;
    public int y;
    Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  public static void bfs(Pair pair) {

    Queue<Pair> q = new LinkedList<>();
    check[pair.x][pair.y] = true;
    q.add(pair);

    while(!q.isEmpty()) {
      Pair p = q.poll();

      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          if (f[nx][ny] == 1 && !check[nx][ny]) {
            check[nx][ny] = true;
            q.add(new Pair(nx, ny));
          }
        }
      }
    }

  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int testCase = Integer.parseInt(br.readLine());
    for (int i = 0; i < testCase; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int answer = 0;

      n = Integer.parseInt(st.nextToken());
      m = Integer.parseInt(st.nextToken());
      int k = Integer.parseInt(st.nextToken());

      f = new int[m][n];
      check = new boolean[m][n];

      for (int u = 0; u < k; u++) {
        st = new StringTokenizer(br.readLine());
        int p = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        f[q][p] = 1;
      }

      for (int u = 0; u < m; u++) {
        for (int v = 0; v <n; v++) {
          if (f[u][v] == 1 && !check[u][v]) {
            answer++;
            bfs(new Pair(u,v));
          }
        }
      }
      System.out.println(answer);
    }
  }
}
