import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while(t --> 0){
            String[] line = sc.nextLine().split(",");
            int x = Integer.parseInt(line[0]);
            int y = Integer.parseInt(line[1]);
            System.out.println(x+y);
        }
    }
}
