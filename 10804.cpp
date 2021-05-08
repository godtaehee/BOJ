import java.util.Scanner;

public class Main {

    public static int[] f = new int[20];

    public static void swap(int start, int end) {
        int size = end - start + 1;

        int[] tmp = new int[size];
        int idx = 0;

        for(int i = start - 1; i < end; i++) {
            tmp[idx++] = f[i];
        }


        for(int i = start - 1; i < end; i++) {
            f[i] = tmp[--idx];
        }
    }


    public static void main(String[] args) {

        for(int i = 0; i < 20; i++) {
            f[i] = i+1;
        }

        Scanner sc = new Scanner(System.in);

        for(int i = 0; i < 10; i++) {

            int start = sc.nextInt();
            int end = sc.nextInt();

            swap(start, end);

        }

        for(int x : f)
            System.out.print(x + " ");


    }
}
