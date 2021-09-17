import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

    static int n;
    static int m;

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

    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,-1,1};

    static void bfs(int[][] f, boolean[][] check, Pair pair) {

        Queue<Pair> q = new LinkedList<>();

        q.add(pair);

        check[pair.x][pair.y] = true;

        while (!q.isEmpty()) {
            Pair inQueuedPair = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = inQueuedPair.x + dx[i];
                int ny = inQueuedPair.y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {

                    if (f[nx][ny] == 1 && !check[nx][ny]) {
                        f[nx][ny] = f[inQueuedPair.x][inQueuedPair.y] + 1;

                        check[nx][ny] = true;
                        q.add(new Pair(nx, ny));
                    }
                }
            }
        }



    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        n = Integer.parseInt(input.split(" ")[0]);
        m = Integer.parseInt(input.split(" ")[1]);

        int[][] f = new int[n][m];
        boolean[][] check = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            input = br.readLine();
            for (int j = 0; j < m; j++) {
                f[i][j] = input.charAt(j) - '0';
            }
        }



        Pair pair = new Pair(0,0);

        bfs(f, check, pair);


        System.out.println(f[n-1][m-1]);



    }
}
