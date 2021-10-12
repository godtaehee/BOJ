import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

  static int n;
  static int[] dx = {1,-1,0,0};
  static int[] dy = {0,0,1,-1};

  static class Pair {
    public int x;
    public int y;
    Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  static int[][] f;
  static boolean[][] check;
  static int[][] map;

  static List<Integer> list;

  public static void bfs(int x, int y, int count) {
    Queue<Pair> q = new LinkedList<>();

    q.add(new Pair(x, y));
    check[x][y] = true;

    int wide = 1;
    while (!q.isEmpty()) {
      Pair p = q.poll();
      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
          if (f[nx][ny] == 1 && !check[nx][ny]) {
            check[nx][ny] = true;
            map[nx][ny] = count;
            q.add(new Pair(nx, ny));
            wide++;
          }
        }
      }
    }
    list.add(wide);
  }

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    n = Integer.parseInt(br.readLine());

    f = new int[n][n];
    check = new boolean[n][n];
    map = new int[n][n];

    list = new ArrayList<>();

    for (int i = 0; i < n; i++) {
      String line = br.readLine();
      for (int j = 0; j < n; j++) {
        f[i][j] = line.charAt(j) - '0';
      }
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (f[i][j] == 1 && !check[i][j]) {
          bfs(i,j,count);
        }
      }
    }

    System.out.println(list.size());
    Collections.sort(list);
    list.forEach(v -> System.out.print(v + " "));
  }
}
