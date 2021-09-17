import java.io.*;
import java.util.*;

public class Main {

    static int[] answer;
    static boolean[] check;
    static int max = Integer.MIN_VALUE;
    
    static void bfs(List<Integer>[] f, boolean[] check, int current) {

        Queue<Integer> q = new LinkedList<>();

        q.add(current);
        check[current] = true;

        while(!q.isEmpty()) {
            int x = q.poll();

            for (int i = 0; i < f[x].size(); i++) {
                if (!check[f[x].get(i)]) {
                    answer[f[x].get(i)]++;
                    if (max < answer[f[x].get(i)])
                        max = answer[f[x].get(i)];
                    q.add(f[x].get(i));
                    check[f[x].get(i)] = true;
                }
            }

        }
    }

    public static void main(String[] args) throws IOException {
        int n, m;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input);
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        List<Integer>[] f = new ArrayList[n+1];
        answer = new int[n+1];

        for (int i = 1; i <= n; i++) {
            f[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {

            String[] inputs = br.readLine().split(" ");

            f[Integer.parseInt(inputs[0])].add(Integer.parseInt(inputs[1]));
        }

        for (int i = 1; i <= n; i++) {
            check = new boolean[n+1];
            bfs(f, check, i);
        }

        StringBuffer sf=  new StringBuffer();

        for (int i = 1; i < answer.length; i++) {
            if (max == answer[i])
                sf.append(i + " ");
        }

        System.out.println(sf.toString().trim());


    }
}
