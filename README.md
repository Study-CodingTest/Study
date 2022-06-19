[![Pull Requests][pr-shield]][pr-url]

## 🔥코딩 테스트 스터디🔥
- 방학 기간 동안 진행되는 **코딩 테스트 대비 문제 풀이** 스터디입니다.
- 매 주 금요일 23:59 까지 5문제를 풀고, 코드 리뷰를 진행합니다.
    - 문제는 각자 원하는 문제 1개 + 나머지는 [tony9402 오늘의 문제](https://github.com/tony9402/baekjoon/blob/main/picked.md)에서 보충합니다.
- 매 주 화요일 21:00에 모의 코딩테스트를 진행합니다.
    - Google Meet를 이용하여 실시간으로 각자 문제를 풀이합니다. (마이크 off, 카메라 off)
    - 2시간 동안 3문제를 풀이하며, 주로 기업 코딩테스트 문제나 대회 문제를 풀이합니다.
        - 문제는 미리 풀어보는 것을 방지하기 위해, 당일에 공개합니다.
    - 문제 풀이 이후 간단히 풀이와 느낌을 공유합니다. (마이크 on, 카메라 off, 화면 공유)
    - 모의 코딩테스트에서 풀이한 문제는 여기에 업로드하지 않습니다.

<br>
<br>

## 🔸 참여 방법

### 🔹 다음 주에 풀고 싶은 문제 신청 방법 [(✈ 문제 등록하기)](https://github.com/Study-CodingTest/Study/issues/new?assignees=&labels=&template=add-a-problem.md&title=%5B%ED%94%8C%EB%9E%AB%ED%8F%BC%5D+%EB%AC%B8%EC%A0%9C_%EC%9D%B4%EB%A6%84+%2F+%EB%82%9C%EC%9D%B4%EB%8F%84)
- Issues에 풀고 싶은 문제를 추가해 주세요.

<br>

### 🔹 소스 코드 업로드 및 리뷰 요청 방법
1. Main branch에서 새 branch를 생성한다.
2. 본인이 해결한 문제의 소스 코드를 **본인의 branch**에 push한다.
3. **Pull Request**를 통해 코드 리뷰를 요청한다.
4. 스터디원에게 리뷰를 받은 후, 수정이 완료되면 Label을 수정한다.

<br>

### 🔹 Code Review 규칙
- 자유롭게 의견을 제시한다.
    - 잘했다고 생각하는 부분 칭찬하기
        - 피드백 할 게 없으면 칭찬해 주세요👍
    - 다른 풀이 방법 공유하기
        - 코드 전체를 공유하는 것이 아닌, 키워드나 간단한 소개만 해 주세요.
    - 개선이 필요한 부분 설명하기
        - 단, 개선이 필요한 이유를 충분히 설명해 주세요.
        - 정답 코드를 알려주기 보다는, 스스로 고민하고 개선 방법을 선택할 수 있게 해 주세요.
        - 리뷰 과정이 숙제 검사가 아닌, 학습 과정으로 느낄 수 있게 해 주세요.
    - 궁굼한 부분 물어보기
- 오픈 커뮤니케이션 지향
    > ex) ~ 하는 게 어떨까요? / ~ 하는 것을 제안합니다. / ~ 부분은 ~ 문제가 있는 것 같은데 괜찮을까요?
- 코드 작성자에게 피드백하는 것이 아닌, 코드 자체를 피드백한다는 생각으로 리뷰한다.

#### 📚 References
- [SW 개발을 위한 코드리뷰(우아한 테크 세미나)](https://www.youtube.com/watch?v=ssDMIcPBqUE&ab_channel=%EC%9A%B0%EC%95%84%ED%95%9CTech)
- [효과적인 코드리뷰를 위한 리뷰어의 자세(카카오 테크)](https://tech.kakao.com/2022/03/17/2022-newkrew-onboarding-codereview/)

<br>

### 🔹 Pull Request 규칙
- PR 템플릿에 맞게 작성한다.
    - 문제를 푸는 과정에서 본인이 생각한 내용을 작성한다.
    - 코드 설명을 작성한다. (단, 주석에 작성한 경우 생략한다.)
    - 특히 리뷰를 받고 싶은 부분을 작성한다.
        - Markdown Codeblock을 이용하여 코드 일부를 발췌해서 작성한다.
        - 특히 리뷰를 받고 싶은 부분은, 리뷰어의 시간을 아낄 수 있게 본인 코드를 충분히 설명해 주세요.
- Reviewer는 본인을 제외한 3명을 추가한다.
- Label은 `Review Request`로 추가한다.
- 모든 스터디원에게 리뷰를 받은 후, 코드 수정이 완료되었으면 Label을 `Merge Request`로 변경한다.
- Main branch에 병합되면, 병합된 branch는 삭제시킨다.

<br>

### 🔹 Commit Message 컨벤션
```
type : subject

body
```
#### ✔ Type
- **Add**: 소스 코드 파일(cpp) 추가
- **Refactor**: 소스 코드 수정
- **Style**: 소스 코드 형식(format) 수정, 변수 네이밍 수정, 주석 추가/삭제 등 
    - (코드 동작에 영향이 없는 수정)
- **Chore**: 그 외 기타 작업

#### ✔ Subject
- 50자 이하의 간단한 제목을 사용한다.
    > ex) Add: 홍길동.cpp <br>
    > ex) Refactor: 완전 탐색 -> 이분 탐색 <br>
    > ex) Style: 함수명 변경

#### ✔ Body(optional)
- 부연 설명을 작성한다.
    > ex) input으로 주어진 배열의 원소들이 오름차순으로 정렬되어 있다는 특징을 이용하여, 탐색 알고리즘을 이분 탐색으로 수정하였습니다. <br>
    > 따라서 시간 복잡도가 O(n²) -> O(nlogn) 으로 최적화 되었습니다.
- 한 줄에 72자를 넘기지 않는다.

<br>

### 🔹 Branch Naming 컨벤션
- `본인이름/이슈번호`
    > ex) 홍길동/1
- 각 **문제마다 branch를 새롭게 생성**해서, 소스 코드를 push 후 리뷰 요청하는 방식

<br>

### 🔹 Cpp File Naming 컨벤션
- `본인이름.cpp`
    > ex) 홍길동.cpp

<br>

### 🔹 Directory 구조
```
└── 📂BOJ
       ├── 📂문제_이름
       │      ├── 💾홍길동.cpp
       │      ├── 💾...
       │      └── 💾홍길동.cpp
       ├── 📂...
       └── 📂문제_이름
└── 📂PGS
       ├── 📂문제_이름
       │      ├── 💾홍길동.cpp
       │      ├── 💾...
       │      └── 💾홍길동.cpp
       ├── 📂...
       └── 📂문제_이름
└── 📂CFS
       ├── 📂문제_이름
       │      ├── 💾홍길동.cpp
       │      ├── 💾...
       │      └── 💾홍길동.cpp
       ├── 📂...
       └── 📂문제_이름
└── 📂LCE
       ├── 📂문제_이름
       │      ├── 💾홍길동.cpp
       │      ├── 💾...
       │      └── 💾홍길동.cpp
       ├── 📂...
       └── 📂문제_이름
└── 📂ETC
       ├── 📂문제_이름
       │      ├── 💾홍길동.cpp
       │      ├── 💾...
       │      └── 💾홍길동.cpp
       ├── 📂...
       └── 📂문제_이름
```

<br>
<br>

## 🔸 참여자
<table>
  <tr>
    <td align="center">
      <a href="https://github.com/seonpilKim">
        <img src="https://avatars.githubusercontent.com/u/68049320?v=4" width="110px;" alt=""/><br />
        <sub><b>김선필</b></sub></a><br />
        <a href="https://github.com/seonpilKim" title="Code">💻</a>
    </td>
    <td align="center">
      <a href="https://github.com/elbica">
        <img src="https://avatars.githubusercontent.com/u/74011724?v=4" width="110px;" alt=""/><br />
        <sub><b>김소희</b></sub></a><br />
        <a href="https://github.com/elbica" title="Code">💻</a>
    </td>
    <td align="center">
      <a href="https://github.com/SHDPR">
        <img src="https://avatars.githubusercontent.com/u/35327930?v=4" width="110px;" alt=""/><br />
        <sub><b>박상민</b></sub></a><br />
        <a href="https://github.com/SHDPR" title="Code">💻</a>
    </td>
    <td align="center">
      <a href="https://github.com/raetic">
        <img src="https://avatars.githubusercontent.com/u/83604180?v=4" width="110px;" alt=""/><br />
        <sub><b>박예찬</b></sub></a><br />
        <a href="https://github.com/raetic" title="Code">💻</a>
    </td>
  </tr>
</table>  

[pr-shield]: https://img.shields.io/github/issues-pr/Study-CodingTest/Study?style=for-the-badge
[pr-url]: https://github.com/Study-CodingTest/Study/pulls
