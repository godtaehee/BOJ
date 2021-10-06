import java.util.Arrays;

public class Main {

    public static int[] add(int[] go, int value, int idx) {
        int[] newarr = new int[go.length + 1];

        for (int i = 0; i < idx-1; i++) {
            newarr[i] = go[i];
        }

        newarr[idx - 1] = value;

        for (int i = idx; i < go.length; i++) {
            newarr[i] = go[i];
        }
        return newarr;
    }

    public static void main(String[] args) {
        int[] f = {1,2,3,4,5,12,32,9,523,6,363};


        int[] result =  add(f, 100, 2);
        Arrays.stream(result).forEach((v) -> System.out.println(v));


    }
}
