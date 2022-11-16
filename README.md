# Algorithm Study
Team Note
|Name|Repository|
|--|--|
|서일현|https://github.com/codingNoob12/algorithm-study|
|박창윤|https://github.com/iean3124/coding_test|

---

# 시간 계산 모듈
1. datetime
  - 객체 생성 방식
    ```python
    datetime(year=2022, month=11, day=17, hour=5, minute=15, second=10, microsecond=10)
    ```
  - 날짜의 덧셈 뺄셈을 손쉽게 처리 가능
    - 정확히는 timedelta 객체로 바꾸어 처리하는 것
2. timedelta
  - 객체 생성 방식
    ```python
    timedelta(days=100, hours=12, minutes=13, seconds=167, microseconds=12345)
    ```
  - 주의
    - `seconds`필드는 해당 날짜에서 몇 초가 지났는지 저장하는 멤버필드
    - `total_seconds()`메서드는 실제 시간의 연산값을 초단위로 변경해 리턴해주는 메서드

---

# 문제에서 n이 큰 경우 입출력
## 아래의 코드가 일반적
```python
import sys
n = int(input())
for i in range(n):
  line = sys.stdin.readline()
```
- **n = 10^5**인 경우 까지 `input()`메서드를 사용하는 것이 가능하다.
- 매번 `sys.stdin.readline()`메서드를 사용하지 않아도 된다.
  ```python
  from sys import stdin
  line = stdin.readline()
  ```
  ```python
  import sys
  def myInput():
    return sys.stdin.readline()
  ```
  1. sys모듈에서 stdin객체만 import해오는 방식
    - 별도의 오버헤드 없이 코드 길이를 줄일 수 있다.
  2. `sys.stdin.readline()`같은 메서드를 다른 사용자 정의 메서드로 감싸는 방법
    - 사용자 정의 함수를 호출하면 다시 입력함수를 출력하므로 오버헤드가 발생한다.
    - 일반적으로 입력 횟수가 굉장히 많을 때 `sys.stdin.readline()`과 같은 메서드들을 이용하기 때문에, 프로그램 전체에서 오버헤드가 유의미한 성능 저하를 일으킬 수 있다. 
    **따라서, 1번 방법이 더 나은 선택지다.**

---
