import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] f = new int[201];
        for(int i = 0; i < n; i++) {
            int x = sc.nextInt();
            f[x + 100]++;
        }
        int search = sc.nextInt();
        System.out.println(f[search+100]);
    }
}
