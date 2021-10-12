import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

  static int m;
  static int n;
  static int k;

  static int[][] f;
  static boolean[][] check;
  static int[] dx = {0,0,1,-1};
  static int[] dy = {1,-1,0,0};
  static List<Integer> answer = new ArrayList<>();

  static class Pair {
    public int x;
    public int y;
    Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  public static void bfs(int x, int y) {

    Queue<Pair> q = new LinkedList<>();

    q.add(new Pair(x,y));

    int wide = 1;
    check[x][y] = true;

    while (!q.isEmpty()) {
      Pair p = q.poll();
      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          if (f[nx][ny] == 0 && !check[nx][ny]) {
            f[nx][ny] = -1;
            check[nx][ny] = true;
            q.add(new Pair(nx,ny));
            wide++;
          }
        }
      }
    }

    answer.add(wide);

  }

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    m = Integer.parseInt(st.nextToken());
    n = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());

    f = new int[n][m];
    check = new boolean[n][m];


    for (int i = 0; i < k; i++) {
      st = new StringTokenizer(br.readLine());

      int x1 = Integer.parseInt(st.nextToken());
      int y1 = Integer.parseInt(st.nextToken());
      int x2 = Integer.parseInt(st.nextToken());
      int y2 = Integer.parseInt(st.nextToken());

      for (int u = x1; u < x2; u++) {
        for (int v = y1; v < y2; v++) {
          f[u][v] = 1;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (f[i][j] == 0) {
          bfs(i,j);
        }
      }
    }

    Collections.sort(answer);
    System.out.println(answer.size());
    answer.forEach(v -> System.out.print(v + " "));
  }
}
