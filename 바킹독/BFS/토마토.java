import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
  static int n;
  static int m;
  static int[] dx = {0,0,1,-1};
  static int[] dy = {1,-1,0,0};
  static int[][] f;
  static boolean[][] check;
  static class Pair {
    public int x;
    public int y;
    Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    f = new int[m][n];
    check = new boolean[m][n];

    Queue<Pair> q = new LinkedList<>();

    for (int i = 0; i < m; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < n; j++) {
        f[i][j] = Integer.parseInt(st.nextToken());
        check[i][j] = false;
        if (f[i][j] == 1) {
          q.add(new Pair(i,j));
          check[i][j] = true;
        }
      }
    }

    while(!q.isEmpty()) {

      Pair p = q.poll();
      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          if (f[nx][ny] == 0 && !check[nx][ny]) {
            f[nx][ny] = f[p.x][p.y] + 1;
            check[nx][ny] = true;
            q.add(new Pair(nx, ny));
          }
        }
      }
    }

    boolean flag = false;
    int max = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (max < f[i][j]) max = f[i][j];
        if (f[i][j] == 0) {
          flag = true;
        }
      }
    }

    if (flag) System.out.println(-1);
    else System.out.println(max - 1);

  }
}
