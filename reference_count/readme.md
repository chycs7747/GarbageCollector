### C Custom Garbage Collector

#### ▶ reference count

1. 소개
   - python, java와 같은 garbage collector을 간단하게 구현
2. 목표
   - garbage collection의 reference count방식을 이해하는데 도움을 주기 위한 프로그램
3. 사용법
   - "make" 명령어로 분할된 파일들에 대해 컴파일 진행
   - "./gc_program" 을 통해 실행파일 실행
   - "make clean" 명령어로 오브젝트 파일들과 실행파일 삭제
4. 한계점
   - Boehm 가비지 컬렉터처럼, 사용자가 기존에 malloc을 사용하듯이 내 custom한 가비지컬렉터를 사용하는 것에 대해 무리가 있다.
   - 오직 프로젝트 목표인 reference count 작동 방식을 간접적으로 이해하는데 도움을 주기 위함으로 제작되어 효율성 측면에 대한 고려는 이루어지지 않음. 