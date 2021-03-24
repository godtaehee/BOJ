package test;

public class test {
    public static void main(String[] args) {

        String num = "950424-1533116";
        StringBuilder sb = new StringBuilder(num);

        sb.replace(6,7, " ");
        System.out.println(sb.toString());
    }
}
