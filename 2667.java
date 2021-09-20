import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    static List homeCount;

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



    static void bfs(int[][] f, int[][] check, Pair pair, int cnt) {

        Queue<Pair> q = new LinkedList<>();

        q.add(pair);
        check[pair.x][pair.y] = cnt;
        int answer = 1;

        while(!q.isEmpty()) {
            Pair p = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (f[nx][ny] == 1 && check[nx][ny] == -1) {
                        q.add(new Pair(nx, ny));
                        check[nx][ny] = cnt;
                        answer++;
                    }
                }
            }
        }

        homeCount.add(answer);


    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sf = new StringBuffer();
        n = Integer.parseInt(br.readLine());

        int[][] f = new int[n+1][n+1];
        int[][] check = new int[n+1][n+1];
        homeCount = new ArrayList();


        for (int i = 0; i < n; i++) {
            String input = br.readLine();
            for (int j = 0; j < n; j++) {
                f[i][j] = input.charAt(j) - '0';
                check[i][j] = -1;
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (f[i][j] == 1 && check[i][j] == -1) {
                    bfs(f, check, new Pair(i, j), cnt++);
                }
            }
        }

        Collections.sort(homeCount);


        sf.append(cnt + "\n");
        for (int i = 0; i < homeCount.size(); i++) {
                sf.append(homeCount.get(i) + "\n");
        }

        System.out.println(sf.toString().trim());
    }
}
