![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2509b790-ac07-4fff-9467-1aa7bc8f0e09/.jpeg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2509b790-ac07-4fff-9467-1aa7bc8f0e09/.jpeg)

static 변수는 인스턴스의 생성과 상관없이 존재하는 변수를 말한다.

static 변수는 변수가 선언된 클래스의 모든 인스턴스가 공유하는 변수이다.

클래스 변수는 인스턴스 내에 존재하는 변수가 아니라 "어떠한 인스턴스에도 속하지 않는 상태로 메모리 공간에 딱 하나만 존재하는 변수" 이다. 다만 이 변수가 선언된 클래스의 인스턴스들은 이 변수에 바로 접근할 수 있는 권한이 있을 뿐이다.

클래스 변수의 접근 방법은

2가지가 있다 클래스 내부에서 외부에서

내부에서는 만약 아래와 같이 코드가 있다하면

```jsx
class test {
    static int num = 0;
    test() {
        num++;
    }
}
```

이건 클래스 내부에서 클래스 변수를 사용하는 방법이며

```jsx
public class Main {
    public static void main(String[] args) {
        test t = new test();
        System.out.println(t.num);
        t.num++;
        System.out.println(t.num);
        test.num++;
        System.out.println(t.num);

    }
}
```

이렇게는 클래스 외부에서 접근하는 방법이다.

클래스변수는 객체 생성 이전에 메모리 공간에 존재한다.

**해당클래스 정보가 가상머신에 의해 읽히는순간 메모리 공간에 할당되고 초기화 된다**

클래스정보를 가상머신이 읽는다 → 클래스 로딩

특정 클래스의 인스턴스 생성을 위해서는 해당 클래스가 반드시 가상머신에 의해 로딩되어야 한다. 즉 인스턴스 생성보다 클래스 로딩이 먼저이다.

한 클래스 내에 동일한 이름의 메소드를 정의하는 것은 허용되지 않는다 그러나 매개변수 선언이 다르면 가능하다 이것을 메소드 **오버로딩**이라고한다.

메소드를 찾을때 메소드의 이름, 메소드의 매개변수 정보

이 두가지의 정보를 가지고 메소드를 호출한다.
