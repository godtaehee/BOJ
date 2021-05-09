public class Main {


    public static int[] data, prev, after;

    static int unused = 6;

    public static void trace(int idx) {
        System.out.println(data[idx]);
        if(after[idx] == -1) return;
        trace(after[idx]);
    }

    public static void insert(int addr, int num) {

        data[unused] = num;
        prev[unused] = addr;
        after[unused] = after[addr];

        after[addr] = unused;
        if(after[addr] != -1) prev[after[addr]] = unused;
        unused++;

    }

    public static void erase(int addr) {

        after[prev[addr]] = after[addr];
        if(after[addr] != -1) prev[after[addr]] = prev[addr];
        unused--;
    }
    public static void main(String[] args) {


        int maxLen = 100005;

        data = new int[maxLen];
        prev = new int[maxLen];
        after = new int[maxLen];

        for(int i = 0; i < maxLen; i++) {
            data[i] = -1;
            prev[i] = -1;
            after[i] = -1;
        }


        data[0] = -1;
        prev[0] = -1;
        after[0] = 2;

        data[2] = 13;
        prev[2] = 0;
        after[2] = 1;

        data[1] = 65;
        prev[1] = 2;
        after[1] = 4;

        data[4] = 21;
        prev[4] = 1;
        after[4] = 5;

        data[5] = 17;
        prev[5] = 4;


        // 2  1   6  4 5  7
        // 13 65 10 21 17 7

        insert(1, 10);
        insert(5, 7);

        erase(1);
        erase(5);

        trace(after[0]);
    }
}
