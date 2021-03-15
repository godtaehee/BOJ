import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

public class coronaTwoArray {
    public static void main(String[] args) throws IOException {

        String path = "data.txt";
        FileInputStream fis = new FileInputStream(path);
        Scanner sc = new Scanner(fis);


        String[][] corona = new String[78][];

        for(int i = 0; i < corona.length; i++){
            String tmp = sc.nextLine();
            corona[i] = tmp.split(",");
            for(int j = 0; j < corona[i].length; j++){
                System.out.printf("%s", corona[i][j]);
                if(j!=corona[i].length -1)
                    System.out.print(", ");
            }
            System.out.println();
        }

        int sum = 0;
        for(int i = 1; i < corona.length; i++){
            sum += Integer.parseInt(corona[i][3]);
        }
        System.out.println(sum);

    }
}
