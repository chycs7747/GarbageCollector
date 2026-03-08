# 🗑️ Simple Garbage Collector (Reference Counting)

## 1. 소개 (Introduction)
C 언어 환경에서 Python, Java와 같은 자동 메모리 관리(Garbage Collection) 시스템을 모방하여 구현한 **레퍼런스 카운팅(Reference Counting) 기반의 가비지 컬렉터** 프로토타입입니다. 

## 2. 프로젝트 목표 (Objective)
이 프로젝트는 실제 상용 서비스 적용보다는, **가비지 컬렉션의 핵심 알고리즘 중 하나인 '레퍼런스 카운트(Reference Count)'의 동작 방식을 코드 레벨에서 직관적으로 이해하고 학습**하는 데 목적을 두고 있습니다.

## 3. 사용 방법 (Usage)
`Makefile`을 제공하여 손쉽게 빌드하고 테스트할 수 있습니다.

* **프로젝트 빌드:** 분할된 소스 파일들을 컴파일하여 실행 파일을 생성합니다.
    > make

* **프로그램 실행:** 가비지 컬렉터의 동작 흐름(메모리 할당, 참조 증가/감소, 메모리 해제)을 확인합니다.
    > ./gc_program

* **빌드 파일 정리:** 생성된 오브젝트 파일(`.o`)과 실행 파일을 삭제합니다.
    > make clean

## 4. 한계점 및 추후 과제 (Limitations & Future Work)
* **투명성(Transparency) 부족:** Boehm GC와 같은 기존 가비지 컬렉터처럼, 사용자가 일반적인 `malloc`을 쓰듯이 자연스럽고 투명하게 커스텀 GC를 적용하기에는 구조적인 제약이 존재합니다. 메타데이터 관리를 위해 별도의 래퍼(Wrapper) 함수를 명시적으로 호출해야 합니다.
* **성능 최적화 미적용:** 철저히 '레퍼런스 카운트 방식의 간접적 이해'라는 교육적 목표에 초점을 맞추어 제작되었습니다. 따라서 메모리 할당 속도, 파편화(Fragmentation) 방지, 또는 멀티 스레드 환경을 고려한 동기화(Thread-safe) 등 효율성 측면의 최적화는 반영되지 않았습니다.

## 5. 실행

https://github.com/user-attachments/assets/ddec7479-9ff2-4779-bbe5-a4d10075d548


https://github.com/user-attachments/assets/9feda9f9-3077-4105-9ab5-fda518bf9ee2


https://github.com/user-attachments/assets/d44d74db-d8d0-4513-93d4-9f1a12d47c9b

