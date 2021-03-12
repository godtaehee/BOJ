import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

class fakeMain {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String s = br.readLine();
        Map<Integer, Integer> newMap = new HashMap<>();

        int n = Integer.parseInt(s);
        int[] haveCard = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());

        int idx = 0;


        while (st.hasMoreTokens()) {
            haveCard[idx++] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n; i++) {
            newMap.put(haveCard[i], 0);
        }

        for (int i = 0; i < n; i++) {
            int value = newMap.get(haveCard[i]);
            newMap.put(haveCard[i], value + 1);
        }
        s = br.readLine();
        int m = Integer.parseInt(s);

        idx = 0;
        st = new StringTokenizer(br.readLine());

        int[] card = new int[m];
        int[] ans = new int[m];

        while (st.hasMoreTokens()) {
            card[idx++] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < m; i++) {
            if(newMap.get(card[i]) == null)
                ans[i] = 0;
            else
                ans[i] = newMap.get(card[i]);
        }

        for (int i = 0; i < m; i++) {
            bw.write(Integer.toString(ans[i]));
            bw.write(" ");
        }

        bw.flush();

    }
}
