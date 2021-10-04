import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int[] pocket = new int[n];

        String[] line = br.readLine().split(" ");
        for (int i = 0; i < line.length; i++) {
            pocket[i] = Integer.parseInt(line[i]);
        }

        int x = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());

        Arrays.sort(pocket);

        int start = 0;
        int end = n-1;
        int answer = 0;

        while(start < end) {
            int sum = pocket[start] + pocket[end];

            if (sum == x) answer++;

            if (sum <= x) start++;
            else end--;

        }
        System.out.println(answer);
    }
}
