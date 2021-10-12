import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  static int[] dx = {1, -1, 0, 0, 0, 0};
  static int[] dy = {0, 0, 1, -1, 0, 0};
  static int[] dz = {0, 0, 0, 0, 1, -1};

  static int l;
  static int r;
  static int c;

  static char[][][] f;
  static boolean[][][] check;
  static int[][][] map;

  static class Pair {
    public int x;
    public int y;
    public int z;

    Pair(int x, int y, int z) {
      this.x = x;
      this.y = y;
      this.z = z;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    while (true) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      l = Integer.parseInt(st.nextToken());
      r = Integer.parseInt(st.nextToken());
      c = Integer.parseInt(st.nextToken());

      if (l == 0 && r == 0 && c == 0) break;

      f = new char[r][c][l];
      check = new boolean[r][c][l];
      map = new int[r][c][l];

      Queue<Pair> q = new LinkedList<>();
      Pair end = new Pair(0,0,0);

      for (int i = 0; i < l; i++) {
        for (int j = 0; j < r; j++) {
          String line = br.readLine();
          for (int k = 0; k < c; k++) {
            f[j][k][i] = line.charAt(k);
            if (f[j][k][i] == 'S') {
              q.add(new Pair(j,k,i));
              check[j][k][i] = true;
            }
            if (f[j][k][i] == 'E') {
              f[j][k][i] = '.';
              end = new Pair(j,k,i);
            }
          }
        }
        br.readLine();
      }

      while (!q.isEmpty()) {
        Pair p = q.poll();
        for (int i = 0; i < 6; i++) {
          int nx = p.x + dx[i];
          int ny = p.y + dy[i];
          int nz = p.z + dz[i];

          if (nx >= 0 && nx < r && ny >= 0 && ny < c && nz >= 0 && nz < l) {
            if (f[nx][ny][nz] == '.' && !check[nx][ny][nz]) {
              map[nx][ny][nz] = map[p.x][p.y][p.z] + 1;
              check[nx][ny][nz] = true;
              q.add(new Pair(nx,ny,nz));
            }
          }
        }
      }

      if (map[end.x][end.y][end.z] == 0) {
        System.out.println("Trapped!");
      } else {
        System.out.println("Escaped in " + map[end.x][end.y][end.z] +" minute(s).");
      }
    }
  }
}
