import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp = br.readLine();
        int n = Integer.parseInt(tmp);
        int[] card = new int[n+1];
        int[] price = new int[n+1];
        for(int i = 1; i <= n; i++){
            card[i] = -1;
        }
        StringTokenizer st = new StringTokenizer(br.readLine());

        int idx = 1;
        while(st.hasMoreTokens()) {
            price[idx++] = Integer.parseInt(st.nextToken());
        }


        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(card[i] == -1 || card[i] > card[i-j] + price[j])
                    card[i] = card[i-j] + price[j];
            }
        }

        System.out.println(card[n]);

    }
}
