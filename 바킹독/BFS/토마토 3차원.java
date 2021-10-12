import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  static int m;
  static int n;
  static int h;

  static int[] dx = {0,0,1,-1,0,0};
  static int[] dy = {1,-1,0,0,0,0};
  static int[] dz = {0,0,0,0,1,-1};

  static int[][][] f;
  static boolean[][][] check;

  static class Pair{
    public int x;
    public int y;
    public int z;

    Pair(int x, int y, int z) {
      this.x = x;
      this.y = y;
      this.z = z;
    }

    @Override
    public String toString() {
      return "Pair{" +
              "x=" + x +
              ", y=" + y +
              ", z=" + z +
              '}';
    }
  }

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());

    m = Integer.parseInt(st.nextToken());
    n = Integer.parseInt(st.nextToken());
    h = Integer.parseInt(st.nextToken());

    f = new int[n][m][h];
    check = new boolean[n][m][h];

    Queue<Pair> q = new LinkedList<>();

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < n; j++) {
        st = new StringTokenizer(br.readLine());
        for (int k = 0; k < m; k++) {
          f[j][k][i] = Integer.parseInt(st.nextToken());
          if (f[j][k][i] == 1) {
            q.add(new Pair(j,k,i));
          }
        }
      }
    }

    while (!q.isEmpty()) {
      Pair p = q.poll();
      for (int i = 0; i < 6; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        int nz = p.z + dz[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h) {
          if (f[nx][ny][nz] == 0 && !check[nx][ny][nz]) {
            f[nx][ny][nz] = f[p.x][p.y][p.z] + 1;
            check[nx][ny][nz] = true;
            q.add(new Pair(nx,ny,nz));
          }
        }
      }
    }

    int max = Integer.MIN_VALUE;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
          if (f[j][k][i] == 0) {
            System.out.println("-1");
            return;
          }
          max = Math.max(max, f[j][k][i]);
        }
      }
    }

    System.out.println(max-1);

  }
}
