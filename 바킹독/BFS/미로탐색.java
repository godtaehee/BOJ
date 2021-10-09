import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  static int[] dx = {0,0,1,-1};
  static int[] dy = {1,-1,0,0};
  static int n;
  static int m;
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

  public static void bfs() {
    Queue<Pair> q = new LinkedList<>();
    q.add(new Pair(0,0));
    check[0][0] = true;

    while(!q.isEmpty()) {
      Pair p = q.poll();
      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          if (f[nx][ny] == 1 && !check[nx][ny]) {
            check[nx][ny] = true;
            f[nx][ny] = f[p.x][p.y] + 1;
            q.add(new Pair(nx, ny));
          }
        }
      }
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    f = new int[n][m];
    check = new boolean[n][m];

    for (int i = 0; i < n; i++) {
      String line = br.readLine();
      for (int j = 0; j < m; j++) {
        f[i][j] = line.charAt(j) - '0';
        check[i][j] = false;
      }
    }

    bfs();

    System.out.println(f[n-1][m-1]);

  }
}
