package Corona;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {

        String path = "tmp/data.txt";
        FileInputStream fis = new FileInputStream(path);
        Scanner sc = new Scanner(fis);
        ArrayList<Covid> covidList = new ArrayList<Covid>();
        sc.nextLine();

        while(sc.hasNextLine()){
            Covid tmpCovid = new Covid(sc.nextLine().split(","));
            covidList.add(tmpCovid);
        }

        CovidList covid = new CovidList(covidList);

        // 모든 정보 출력

        covid.printCovidInfo();

        // 최대 검사 진행자 수

        System.out.println("최대 검사 진행자 수: " + covid.getMaxTests());

        // 검사 진행자 수

        System.out.println("검사 진행자 수: " + covid.getTotalTests());

        // 최대 검사 진행자 날짜

        System.out.println("최대 검사 진행자 날짜: " + covid.getMaxTestsDate());

    }
}
