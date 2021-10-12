import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  static int testCase;
  static int h;
  static int w;

  static int[] dx = {0,0,1,-1};
  static int[] dy = {1,-1,0,0};

  static char[][] f;
  static int[][] fireMap;
  static int[][] personMap;

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

    testCase = Integer.parseInt(br.readLine());

    while (testCase --> 0) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      w = Integer.parseInt(st.nextToken());
      h = Integer.parseInt(st.nextToken());

      f = new char[h][w];
      fireMap = new int[h][w];
      personMap = new int[h][w];

      for (int i = 0; i < h; i++) {
        Arrays.fill(fireMap[i], -1);
        Arrays.fill(personMap[i], -1);
      }

      Queue<Pair> fireQueue = new LinkedList<>();
      Queue<Pair> personQueue = new LinkedList<>();

      for (int i = 0; i < h; i++) {
        String line = br.readLine();
        for (int j = 0; j < w; j++) {
          f[i][j] = line.charAt(j);
          if (f[i][j] == '@') {
            personMap[i][j] = 0;
            personQueue.add(new Pair(i, j));
          }
          else if(f[i][j] == '*') {
            fireQueue.add(new Pair(i, j));
            fireMap[i][j] = 0;
          }
        }
      }

      while (!fireQueue.isEmpty()) {
        Pair p = fireQueue.poll();
        for (int i = 0; i < 4; i++) {
          int nx = p.x + dx[i];
          int ny = p.y + dy[i];
          if (nx >= 0  && nx < h && ny >= 0 && ny < w) {
            if (f[nx][ny] != '#' && fireMap[nx][ny] == -1) {
              fireMap[nx][ny] = fireMap[p.x][p.y] + 1;
              fireQueue.add(new Pair(nx, ny));
            }
          }
        }
      }

      boolean flag = false;

      outer: while (!personQueue.isEmpty()) {
        Pair p = personQueue.poll();
        for (int i = 0; i < 4; i++) {
          int nx = p.x + dx[i];
          int ny = p.y + dy[i];
          if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if (f[nx][ny] != '#' && personMap[nx][ny] == -1) {
              if (personMap[p.x][p.y] + 1 < fireMap[nx][ny] || fireMap[nx][ny] == -1) {
                personMap[nx][ny] = personMap[p.x][p.y] + 1;
                personQueue.add(new Pair(nx, ny));
              }
            }
          } else {
            System.out.println(personMap[p.x][p.y] + 1);
            flag = true;
            break outer;
          }
        }
      }
      if (!flag)
        System.out.println("IMPOSSIBLE");
    }
  }
}
