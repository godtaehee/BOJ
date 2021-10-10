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
  static char[][] f;
  static int[][] check;

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

    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    f = new char[n+2][m+2];
    check = new int[n+2][m+2];

    Queue<Pair> personQueue = new LinkedList<>();
    Queue<Pair> fireQueue = new LinkedList<>();

    for (int i = 0; i < n+2; i++) {
      for (int j = 0; j < m+2; j++) {
        f[i][j] = '.';
      }
    }

    for (int i = 1; i <= n; i++) {
      String line = br.readLine();
      for (int j = 0; j < m; j++) {
        f[i][j+1] = line.charAt(j);
        if (line.charAt(j) == 'J') {
          personQueue.add(new Pair(i, j+1));
        }
        if (line.charAt(j) == 'F') {
          fireQueue.add(new Pair(i, j+1));
        }
      }
    }

    while (!personQueue.isEmpty()) {
      Pair p = personQueue.poll();

      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0 && nx < n + 2 && ny >= 0 && ny < m + 2) {
          if (f[nx][ny] == '.' && check[nx][ny] == 0) {
            f[nx][ny] = 'J';
            check[nx][ny] = check[p.x][p.y] + 1;
            personQueue.add(new Pair(nx, ny));
          }
        }
      }
    }

    while(!fireQueue.isEmpty()) {
      Pair p = fireQueue.poll();
      check[p.x][p.y] = -1;

      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 1 && nx < n + 1 && ny >= 1 && ny < m + 1) {
          if (f[nx][ny] != '#' && check[nx][ny] != -1) {
            fireQueue.add(new Pair(nx, ny));
            f[nx][ny] = 'F';
            check[nx][ny] = -1;
          }
        }
      }
    }

    int min = Integer.MAX_VALUE;

      for (int i = 0; i < m + 2; i++) {
        if (f[0][i] == 'J' && (min > check[0][i])) {
          min = check[0][i];
        }
      }

    for (int i = 0; i < m + 2; i++) {
      if (f[n+1][i] == 'J' && (min > check[n+1][i])) {
        min = check[n+1][i];
      }
    }

    for (int i = 0; i < n + 2; i++) {
      if (f[i][0] == 'J' && (min > check[i][0])) {
        min = check[i][0];
      }
    }

    for (int i = 0; i < n + 2; i++) {
      if (f[i][m+1] == 'J' && (min > check[i][m+1])) {
        min = check[i][m+1];
      }
    }

    System.out.println(min);
  }
}
