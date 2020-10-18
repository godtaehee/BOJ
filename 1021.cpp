#include <iostream>
#include <deque>

using namespace std;
int main(){

    int n, m;
    cin >> n >> m;
    deque<int> q;

    // n = 10 이면 1 2 3 4 5 6 7 8 9 10 순으로 들어간다
    for(int i = n; i >= 1; i--){
        q.push_front(i);
    }

    int sum = 0;
    for(int i = 0; i < m; i++){
        int x; // 제거할 숫자
        cin >> x;
        int count = 0; // 제거할 숫자가 몇번째 순서에 있는지 세는 변수
        int size = q.size(); // 2,3번 연산을 계속 수행해주면 큐의 사이즈가 계속 변한다
        for(int t : q){
            count++;
            //큐에서 제거할 숫자를 발견했을때 아래 if문 실행
            if(t == x){
                //왼쪽이동과 오른쪽이동중에 최소값을 결정
                //결국 최솟값은 제거할 숫자를 큐의 첫번째 원소로 보내기위한 최소 횟수가 된다.
                int min_value = (min(count-1,size-count+1));
                sum+=min_value;
                //왼쪽으로 이동시키는것이 최소일때 아래 if문 실행
                if(min_value == count-1){
                    for(int k= 0; k < count-1; k++){
                        int tmp = q.front(); // 앞의숫자를 tmp에 저장 후 삭제
                        q.pop_front();
                        q.push_back(tmp); // 저장된 tmp를 뒤로보냄
                    }
                    // for문을 다 돌고나면 삭제할 숫자가 맨 앞의 원소에 위치에 있는다.
                    // 이것을 삭
                    q.pop_front();
                // 오른쪽으로 이동시키는것이 최소일때 아래 else문 실행  제
                // 오른쪽은 왼쪽과 반대과정으로 해준다.
                }else{
                    for(int k = 0; k < size-count; k++){
                        int tmp = q.back();
                        q.pop_back();
                        q.push_front(tmp);
                    }
                    q.pop_back();
                }
                // 2,3번중 연산을 수행후 break
                // 삭제완료한 상태이므로 다음 원소를 삭제작업을 하러 간다
                break;
            }
        }
    }

    // 최소회수가 모두 더해진 sum 출력
    cout << sum << '\n';

    return 0;
}
