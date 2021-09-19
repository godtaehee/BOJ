import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    static class Pair {
        public int x;
        public int y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};

    static void print(char[][] f) {
        for (int i = 0; i < f.length; i++) {
            for (int j = 0; j < f[i].length; j++) {
                System.out.print(f[i][j]);
            }
            System.out.println();
        }
    }

    static void printFullBoard(int r, int c) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print('O');
            }
            System.out.println();
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int r, c, n;


        r = Integer.parseInt(input[0]);
        c = Integer.parseInt(input[1]);
        n = Integer.parseInt(input[2]);

        char[][] f = new char[r][c];
        char[][] boomBoard = new char[r][c];
        char[][] secondBoomBoard = new char[r][c];


        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                boomBoard[i][j] = 'O';
                secondBoomBoard[i][j] = 'O';
            }
        }

        for (int i = 0; i < r; i++) {
            String line = br.readLine();
            for (int j = 0; j < c; j++) {
                f[i][j] = line.charAt(j);
                if (f[i][j] == 'O') {
                    boomBoard[i][j] = '.';
                    for (int z = 0; z < 4; z++) {
                        int nx = i + dx[z];
                        int ny = j + dy[z];
                        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                            boomBoard[nx][ny] = '.';
                        }
                    }
                }
            }
        }


        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (boomBoard[i][j] == 'O') {
                    secondBoomBoard[i][j] = '.';
                    for (int z = 0; z < 4; z++) {
                        int nx = i + dx[z];
                        int ny = j + dy[z];
                        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                            secondBoomBoard[nx][ny] = '.';
                        }
                    }
                }
            }
        }

        if (n == 1) {
            print(f);
        }else if (n % 2 == 0) {
            printFullBoard(r, c);
        }else if (n%4 == 1){
            print(secondBoomBoard);
        }else if (n%4 == 3) {
            print(boomBoard);
        }
    }
}


