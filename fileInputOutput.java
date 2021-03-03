import java.io.*;
import java.util.Scanner;

class Main {
    public static void main(String[] args) throws IOException {

        String path = "data.txt";
        FileInputStream fis = new FileInputStream(path);
        Scanner sc = new Scanner(fis);
        sc.close();
        fis.close();

        int x = (int)(Math.random()*10);
        int y = (int)(Math.random()*10);
        int z = (int)(Math.random()*10);

        FileOutputStream fos = new FileOutputStream(path);
        PrintStream ps = new PrintStream(fos);
        ps.printf("%d %d %d", x,y,z);

        ps.close();
        fos.close();

    }
}
