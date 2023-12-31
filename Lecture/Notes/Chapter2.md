# Chapter 2. UNIX Programming

## 2.1. UNIX history
- MULTICS(1960) &rarr; UNIX(1969) &rarr; UNIX Families(MINIX, LINUX, BSD, etc...)

#### POSIX
- Portable Operating System Interface(POSIX)
  - Standard API formula of UNIX system
  - define **kernel API**, **command line shell**, utility programs

## 2.2 UNIX Philosophy
1. 각 프로그램이 하나의 일을 잘 할 수 있게 만들 것. 새로운 일을 하려면, 새로운 기능들을 추가하기 위해 오래된 프로그램을 복잡하게 만들지 말고 새로 만들 것.
2. 모든 프로그램 출력이 아직 잘 알려지지 않은 프로그램이라고 할지라도 다른 프로그램에 대한 입력이 될 수 있게 할 것. 무관한 정보로 출력을 채우지 말 것. 까다롭게 세로로 구분되거나 바이너리로 된 입력 형식은 피할 것. 대화식 입력을 고집하지 말 것.
3. 소프트웨어를 설계하고 구축할 때 빠르게 써볼 수 있게 할 것. 심지어 운영체제라도 이상적으로는 수 주 내로. 어설픈 부분을 버리고 다시 만드는 것을 주저하지 말 것.
4. 프로그래밍 작업을 가볍게 하기 위해, 심지어 우회하는 방법으로 도구를 만들고 바로 버릴지라도 어설픈 도움 보다는 도구 사용을 선호할 것.

#### Short summary from Doug McIlroy
    1. 프로그램이 한 가지 일을 잘 하도록 만들어라.
    2. 프로그램이 서로 협력하도록 만들어라.
    3. 프로그램이 텍스트 스트림을 처리하도록 만들어라. 텍스트 스트림은 범용 인터페이스이기 때문이다.

#### Longer version from Rob Pike
    규칙 1. 프로그램이 충분히 빠르다고 말하지 말 것. 병목은 생각지도 못한 곳에서 발생하곤 하기 때문에, 함부로 추측하지 말고 병목의 위치를 찾아내기 전까지 스피드 핵을 할 것.
    규칙 2. 측정할 것. 측정하기 전에는 속도를 조정하지 말 것. 심지어 한 부분의 코드가 나머지 전체의 속도를 좌우한다고 해도 측정 없이 속도를 조정하지 말 것.
    규칙 3. 근사한 알고리즘은 n이 작으면 느린 경우가 많다. 그리고 대부분의 경우, n은 작다. 근사한 알고리즘들은 기본적인 비용이 있기 마련이다. n이 빈번하게 큰 값이 된다는 것을 알기 전까지는 멋을 부리지 말 것(심지어 n이 꽤 커지더라도 규칙 2를 먼저 적용할 것).
    규칙 4. 근사한 알고리즘은 심플한 알고리즘보다 버그가 생기기 쉽고, 구현하기도 어렵다. 심플한 알고리즘과 심플한 자료 구조를 사용할 것.
    거의 모든 실용적인 프로그램들은 다음의 자료구조들만 써도 된다.
        배열
        링크드 리스트
        해시 테이블
        이진 트리
    물론 이런 자료구조를 합친 콜렉션을 쓸 줄도 알아야 한다.
    규칙 5. 데이터가 최고다. 올바른 자료 구조를 선택하고 잘 조직하면, 알고리즘은 자연히 따라올 것이다. 프로그래밍의 핵심은 알고리즘이 아니라 자료구조다.
    규칙 6. 규칙 6은 없다.

#### Critics to Window
- Big and **monolithic**(not modularized)

#### Example codes...
- refer to Codes folder