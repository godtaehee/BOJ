import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
  static int testCase;
  static int n;

  static int[][] f;
  static boolean[][] check;
  static int[][] map;

  static int[] dx = {-2,-2,-1,-1,2,2,1,1};
  static int[] dy = {1,-1,-2,2,1,-1,-2,2};

  static class Pair {

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


  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    testCase = Integer.parseInt(br.readLine());
    
    while (testCase --> 0) {

      n = Integer.parseInt(br.readLine());
      f = new int[n][n];
      map = new int[n][n];
      check = new boolean[n][n];

      Queue<Pair> q = new LinkedList<>();

      StringTokenizer st = new StringTokenizer(br.readLine());

      int currentX = Integer.parseInt(st.nextToken());
      int currentY = Integer.parseInt(st.nextToken());

      q.add(new Pair(currentX, currentY));

      check[currentX][currentY] = true;

      st = new StringTokenizer(br.readLine());

      while (!q.isEmpty()) {
        Pair p = q.poll();
        for (int i = 0; i < 8; i++) {
          int nx = p.x + dx[i];
          int ny = p.y + dy[i];

          if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (!check[nx][ny]) {
              map[nx][ny] = map[p.x][p.y] + 1;
              q.add(new Pair(nx, ny));
              check[nx][ny] = true;
            }
          }
        }
      }
      System.out.println(map[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())]);
    }
  }
}
