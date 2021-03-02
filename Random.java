import java.util.Arrays;

class Main {
    public static int[] shuffle(int[] arr){
        int length = arr.length;
        boolean[] check = new boolean[length];
        int[] tmp = new int[length];
        for(int i = 0; i < length; i++){
            int count = 0;
            while(true){
                if (count >= length) break;
                int random = (int)(Math.random()*length);
                if(!check[random]){
                    check[random] = true;
                    tmp[i] = random;
                    break;
                }else
                    count++;
            }
        }
        for(int i = 0; i < length; i++){
            tmp[i] = arr[tmp[i]];
        }
        return tmp;
    }
    public static void main(String[] args) {
        int[] original = {1,2,3,4,5,6,7,8,9};
        System.out.println(Arrays.toString(original));
        int[] result = shuffle(original);
        System.out.println(Arrays.toString(result));
    }
}
