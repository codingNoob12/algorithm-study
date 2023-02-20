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

# 유클리드 호제법
- 2개의 자연수 또는 정식(整式)의 최대공약수를 구하는 알고리즘의 하나이다.
## 원리
- a와 b의 최대공약수를 (a, b)라 한다, 다음이 성립한다. <br> (단, a, b는 자연수이고 a % b = r이라 가정)
- (a, b) = (b, r)
## 예시
- (1071, 1029) = (1029, 42) = (42, 21) = (21, 0) = 21
## 구현
```python
def gcd(x, y):
    if x < y:
        x, y = y, x
    while y:
        x, y = y, x % y
    return x
```
```python
def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)
```

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
    - [참고](https://nahwasa.com/entry/%EB%88%84%EC%A0%81-%ED%95%A9prefix-sum-2%EC%B0%A8%EC%9B%90-%EB%88%84%EC%A0%81%ED%95%A9prefix-sum-of-matrix-with-java)

---

# union-find 알고리즘
## 정의
- 여러 노드가 존재할 때, 두 노드를 선택해서 현재 두 노드가 같은 그래프에 존재하는지 판별하는 알고리즘
- 상호 배타적 집합(disjoint-set)이라고 하기도 함.
- 주로 합집합을 찾을 때 사용함
## 연산
- find : x가 어떤 집합에 속하는지 찾는 연산
- union : x와 y가 포함된 두 집합을 합치는 연산
## 예제 코드 (백준 1717번)
```python
import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
n, m = map(int, input().rstrip().split())

# 각 원소의 대표 원소를 저장하는 리스트
parent = [i for i in range(n+1)]

def find(x):
    # x의 대표 원소를 찾는 함수
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]

for _ in range(m):
    op, a, b = map(int, input().rstrip().split())
    if op == 0:
        # a와 b의 대표 원소를 찾은 후, 작은 것을 큰 것의 대표 원소로 연결
        a = find(a)
        b = find(b)
        if a < b:
            parent[b] = a
        else:
            parent[a] = b
    else:
        # a와 b의 대표 원소가 같은지 확인
        print('YES' if find(a) == find(b) else 'NO')
```
- [참고](https://brenden.tistory.com/33)

---

# 동적 계획법 (DP)
## 정의
- 어떤 문제를 풀기 위해 그 문제를 더 작은 문제의 연장선으로 생각하고, 과거에 구한 해를 활용하는 방식
- 일반적으로 재귀적으로 정의되는 문제에 사용되고, 기존의 결과를 메모리에 저장하여 최적화한다.
## 종류
### 메모제이션 방식
- 큰 값부터 작은 값으로 진행 (하향식 접근)
#### 예제 코드 (백준 13301)
```python
def radius(n):
    if n in (1, 2):
        RADIUS[n - 1], RADIUS[n - 2] = 1, 1
        return 1
    if RADIUS[n - 2] == 0:
        RADIUS[n - 2] = radius(n - 1)
    if RADIUS[n - 3] == 0:
        RADIUS[n - 3] = radius(n - 2)
    return RADIUS[n - 2] + RADIUS[n - 3]


n = int(input())
RADIUS = [0] * n
RADIUS[n - 1] = radius(n)
a, b = 0, 0
if n == 1:
    a, b = RADIUS[-1], RADIUS[-1]
else:
    a, b = RADIUS[-1], RADIUS[-1] + RADIUS[-2]
print(2 * (a + b))

```
### Bottom-Up 방식
- 작은 값부터 큰 값으로 진행 (상향식 방식)
#### 예제 코드 (백준 1463)
```python
n = int(input())
mem = [0] * (n + 1)
for x in range(2, n + 1):
    candidates = [mem[x - 1]]
    if x % 3 == 0:
        candidates.append(mem[x // 3])
    if x % 2 == 0:
        candidates.append(mem[x // 2])
    mem[x] = min(candidates) + 1
print(mem[n])
```

---

# 에라토스테네스의 체
## 정의
- 범위에서 합성수를 지우는 방식으로 소수를 찾는 방법
## 방법
1. 1은 제거
2. 지워지지 않은 수 중 제일 작은 2를 소수로 채택하고, 나머지 2의 배수를 모두 지운다
3. 지워지지 않은 수 중 제일 작은 3을 소수로 채택하고, 나머지 3의 배수를 모두 지운다
4. 지워지지 않은 수 중 제일 작은 5를 소수로 채택하고, 나머지 5의 배수를 모두 지운다
5. (반복)
- 과정을 보면 알겠지만, Bottom-Up방식으로 코드가 구성됨
- 하지만, 최적화하는 문제가 아니라 소수를 결정하는 문제라 DP라 보기엔 어렵다.
## 코드
```python
n = 1000
a = [False, False] + [True] * (n - 1)
primes = []

for i in range(2, n + 1):
    if a[i]:
        primes.append(i)
        for j in range(2 * i, n + 1, i):
            a[j] = False
print(primes)
```
