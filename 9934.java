import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static StringBuffer[] sb;
    static int[] f;
    static int k;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         k = Integer.parseInt(br.readLine());

         f = new int[(int) Math.pow(2,k) -1];

         sb = new StringBuffer[k];

        for (int i = 0; i < k; i++) {
            sb[i] = new StringBuffer();
        }

        String[] line = br.readLine().split(" ");
        for (int i = 0; i < f.length; i++) {
            f[i] = Integer.parseInt(line[i]);
        }

        go(0,f.length-1,0);

        for (int i = 0; i < k; i++) {
            System.out.println(sb[i].toString());
        }

    }

    public static void go(int start, int end, int floor) {
        if (k == floor) return;

        int mid = (end + start) / 2;

        sb[floor].append(f[mid] + " ");

        go(start, mid-1, floor+1);
        go(mid+1,end,floor+1);
    }
}
