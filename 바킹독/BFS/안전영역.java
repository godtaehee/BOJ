import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n;

    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    static int[][] f;
    static boolean[][] check;
    static int[][] map;

    static class Pair {
        public int x;
        public int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void bfs(int x, int y, int depth) {

        Queue<Pair> q = new LinkedList<>();

        q.add(new Pair(x, y));
        check[x][y] = true;

        while (!q.isEmpty()) {
            Pair p = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (f[nx][ny] > depth && !check[nx][ny]) {
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

        f = new int[n][n];
        
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        List<Integer> answer = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                f[i][j] = Integer.parseInt(st.nextToken());
                min = Math.min(min, f[i][j]);
                max = Math.max(max, f[i][j]);
            }
        }

        for (int i = min; i < max; i++) {
            map = new int[n][n];
            check = new boolean[n][n];
            int safeZone = 0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (f[j][k] > i && !check[j][k]) {
                        bfs(j, k, i);
                        safeZone++;
                    }
                }
            }
            answer.add(safeZone);
        }

        Collections.sort(answer, Collections.reverseOrder());

        if (answer.size() == 0) {
            System.out.println("1");
        } else
            System.out.println(answer.get(0));

    }
}
