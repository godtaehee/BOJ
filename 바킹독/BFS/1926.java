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
  static int[][] check;
  static int[] wide;

  static class Pair {
    public int x;
    public int y;

    Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  public static void bfs(int x, int y, int count) {
    Queue<Pair> q = new LinkedList<>();
    q.add(new Pair(x, y));
    check[x][y] = count;
    int wideCount = 1;

    while(!q.isEmpty()) {
      Pair p = q.poll();
      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          if (f[nx][ny] == 1 && check[nx][ny] == -1) {
            q.add(new Pair(nx, ny));
            check[nx][ny] = count;
            wideCount++;
          }
        }
      }
    }
    wide[count] = wideCount;
  }


  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    f = new int[n][m];
    check = new int[n][m];
    wide = new int[n*m];

    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < m; j++) {
        f[i][j] = Integer.parseInt(st.nextToken());
        check[i][j] = -1;
      }
    }

    int pictureCount = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (f[i][j] == 1 && check[i][j] == -1) {
          bfs(i,j,pictureCount++);
        }
      }
    }

    int max = Integer.MIN_VALUE;
    for (int i = 0; i < pictureCount; i++) {
      if (max < wide[i])
        max = wide[i];
    }

    if (pictureCount == 0){
      System.out.println(0);
      System.out.println(0);
    }else {
      System.out.println(pictureCount);
      System.out.println(max);
    }
  }
}
