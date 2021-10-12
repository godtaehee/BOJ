import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

  static int n;
  static int[] dx = {0,0,1,-1};
  static int[] dy = {1,-1,0,0};
  static char[][] f;
  static boolean[][] check;
  static char[][] map;

  public static class Pair {
    public int x;
    public int y;
    Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }

    @Override
    public String toString() {
      return "Pair{" +
              "x=" + x +
              ", y=" + y +
              '}';
    }
  }

  public static void bfs(int x, int y, char color) {

    Queue<Pair> q = new LinkedList<>();
    q.add(new Pair(x,y));

    while (!q.isEmpty()) {
      Pair p = q.poll();

      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0  && nx < n && ny >= 0 && ny < n) {
          if (f[nx][ny] == color && !check[nx][ny]) {
            check[nx][ny] = true;
            q.add(new Pair(nx, ny));
          }
        }
      }
    }
  }

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    n = Integer.parseInt(br.readLine());

    f = new char[n][n];
    check = new boolean[n][n];

    for (int i = 0; i < n; i++) {
      String line = br.readLine();
      for (int j = 0; j < n; j++) {
        f[i][j] = line.charAt(j);
      }
    }

    int normalAnswer = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!check[i][j]) {
          bfs(i,j,f[i][j]);
          normalAnswer++;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (f[i][j] == 'G') f[i][j] = 'R';
      }
    }

    int colorAnswer = 0;
    check = new boolean[n][n];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!check[i][j]) {
          bfs(i,j,f[i][j]);
          colorAnswer++;
        }
      }
    }

    System.out.println(normalAnswer + " " + colorAnswer);
  }
}
