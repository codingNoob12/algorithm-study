# Algorithm Study

---

# 조건식 축약 방법
- or로 조건식이 길어지는 경우는 아래와 같이 처리하면 좋다
```python
if a in (1, 2, 3):
  print('a is in 1, 2, 3')
```

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

# 정렬 메서드, 함수 이용법
1. 기본적으로 오름차순 정렬
```python
nums = [2, 4, 1, 3]
nums.sort()
# [1, 2, 3, 4]
```
2. reverse 파라미터를 이용한 역순 정렬
```python
nums = [2, 4, 1, 3]
nums.sort(reverse=True)
# [4, 3, 2, 1]
```
3. key 파라미터를 이용한 정렬
```python
lst = [[2, 1], [3, 4], [1, 2], [1, 3], [3, 2]]
lst.sort(key=lambda x:(x[0], -x[1]))
# 행은 오름차순, 열은 내림차순 정렬
# 파라미터 값으론 함수의 이름이 들어가야 함

# [[1, 3], [1, 2], [2, 1], [3, 4], [3, 2]]
```
---

# unpack
- unpack연산자를 잘 사용하면 코드를 더 줄일 수 있다.
```python
lst = [1, 2, 3, 4, 5]
for item in lst:
  print(item)
```
```python
lst = [1, 2, 3, 4, 5]
print(*lst)
```

---

# python에서 몫과 나머지
- 몫을 구할 때 내림을 해서 구하고 나머지는 r = a - bq로 구한다
  - 그렇기 때문에 r이 음수가 나올 수 있어 [백준 16428](https://www.acmicpc.net/problem/16428)같은 문제에서 주의해야한다.

---

# 누적합 알고리즘
## 정의
  - 구간합을 처음부터 모두 계산하는 것이 아니라 누적합의 정의를 이용해 구간합을 구하는 알고리즘
## 종류
  - 1차원 배열
    - 크기가 N인 1차원 배열 A가 존재한다고 가정하자. (A[1] ~ A[N])
    - 이때, S[i]를 A[1] ~ A[i]의 합이라 가정하자.
    - 즉, S[i] = A[1] + A[2] + ... + A[i]가 된다.
    - 이때, A[j] ~ A[k]의 구간합을 누적합을 이용해 구하고 싶다면, 먼저 S[k] = A[1] + ... + A[j-1] + A[j] + ... + A[k]임을 확인 할 수 있다.
    - S[k]에서 A[1] ~ A[j-1]의 누적합을 빼주면 내가 원하는 구간합을 구할 수 있다.
    - 따라서, S[k] - S[j-1]로 구간합을 구하면 된다.
  - 2차원 배열
    - 크기가 N by M인 2차원 배열 A가 있다고 가정하자. (A[1][1] ~ A[N][M])
    - 이때, S[i][j]를 A[1][1] ~ A[i][j]의 합이라 가정하자.
    - 즉, S[i][j] = A[1][1] + ... + A[1][j] + ... + A[N][1] + ... + A[N][j]
    - 이때, A[i][j] ~ A[x][y]의 구간합을 누적합을 이용해 구하고 싶다면, S[x][y] - S[x][j-1] - S[i-1][y] + S[i-1][j-1]로 구할 수 있다.
    - 누적합의 시작 지점이 (1,1)임을 생각하면 구간합을 구하기 위해서는 위와 같은 식이 도출 됨을 알 수 있다.
    ```python
    def prefix_sum_2d(N, M, arr, Q):
        pre_sum = [[0 for j in range(M + 1)] for i in range(N + 1)]
        for i in range(1, N + 1):
            for j in range(1, M + 1):
                pre_sum[i][j] = pre_sum[i][j - 1] + pre_sum[i - 1][j] - pre_sum[i - 1][j - 1] + arr[i - 1][j - 1]

        result = []
        for i, j, x, y in Q:
            result.append(pre_sum[x][y] - pre_sum[x][j - 1] - pre_sum[i - 1][y] + pre_sum[i - 1][j - 1])
        return result
    ```
    - |참고|https://nahwasa.com/entry/%EB%88%84%EC%A0%81-%ED%95%A9prefix-sum-2%EC%B0%A8%EC%9B%90-%EB%88%84%EC%A0%81%ED%95%A9prefix-sum-of-matrix-with-java|
