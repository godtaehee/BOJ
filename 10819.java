import java.util.*;


public class Main {

    public static boolean go(int[] a){

        int i = a.length - 1;

        while(i > 0 && a[i-1] >= a[i]){
            i-=1;
        }

        if(i <= 0)
            return false;

        int j = a.length - 1;

        while(a[i - 1] >= a[j]){
            j-=1;
        }

        int tmp = a[i - 1];
        a[i - 1] = a[j];
        a[j] = tmp;

        j = a.length - 1;

        while(i < j){
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i+=1;
            j-=1;
        }

        return true;

    }

    public static int cal(int[] a){
        int sum = 0;

        for(int i = 0; i < a.length - 1; i++){
            sum+= Math.abs(a[i] - a[i+1]);
        }

        return sum;
    }



    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();

        int[] a = new int[n];

        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);

        int max = -9000;

        do{
            int temp = cal(a);
            max = Math.max(temp, max);
        }while(go(a));

        System.out.println(max);

    }
}
