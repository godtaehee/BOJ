import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class Pair {
        public int x;
        public int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[][] odd = {{-1, 0}, {0, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    static int[][] even = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {0, 1}, {-1 ,0}};
    static int w;
    static int h;
    static int answer = 0;

    static void bfs(int[][] f, boolean[][] isOut) {
        Queue<Pair> q = new LinkedList<>();

        q.add(new Pair(0,0));

        while (!q.isEmpty()) {
            Pair pair = q.poll();

            for (int i = 0; i < 6; i++) {
                int nx;
                int ny;

                if (pair.x % 2 == 0) {
                    nx = pair.x + even[i][0];
                    ny = pair.y + even[i][1];
                }else {
                    nx = pair.x + odd[i][0];
                    ny = pair.y + odd[i][1];
                }

                if (nx >= 0 && nx < h + 2 && ny >= 0 && ny < w + 2) {
                    if (!isOut[nx][ny] && f[nx][ny] == 0) {
                        isOut[nx][ny] = true;
                        q.add(new Pair(nx, ny));
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        int[][] f = new int[h+2][w+2];
        boolean[][] isOut = new boolean[h+2][w+2];

        for (int i = 1; i < h + 1; i++) {
            st = new StringTokenizer(br.readLine());
            int j = 1;
            while(st.hasMoreTokens())
                f[i][j++] = Integer.parseInt(st.nextToken());
        }

        bfs(f, isOut);

        for (int i = 1; i < h + 1; i++) {
            for (int j = 1; j < w + 1; j++) {
                if (f[i][j] == 1) {
                    for (int k = 0; k < 6; k++) {
                        int nx;
                        int ny;
                        if (i % 2 != 0) {
                            nx = i + odd[k][0];
                            ny = j + odd[k][1];
                        }else {
                            nx = i + even[k][0];
                            ny = j + even[k][1];
                        }

                        if (isOut[nx][ny] && f[nx][ny] == 0) {
                            answer++;
                        }
                    }
                }
            }
        }

        System.out.println(answer);
    }
}
