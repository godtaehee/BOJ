import java.io.*;
import java.util.*;
class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        int size = s.length();
        int ans = 0;
        Stack<Integer> stk = new Stack<>();
        for(int i = 0; i < size; i++){
            if(s.charAt(i) == '(')
                stk.push(i);
            else if(!stk.isEmpty()){
                if(stk.peek() == i-1){
                    stk.pop();
                    ans+=stk.size();
                }else{
                    stk.pop();
                    ans+=1;
                }
            }
        }
        bw.write(String.valueOf(ans));
        bw.flush();
    }
}
