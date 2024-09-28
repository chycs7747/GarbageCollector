# 컴파일러 설정
CC = gcc
CFLAGS = -Wall -g

# 타겟 파일 이름
TARGET = gc_program

# 소스 파일
SRCS = main.c garbage_collector.c memory.c

# 오브젝트 파일 리스트
OBJS = $(SRCS:.c=.o)

# 디폴트 타겟: 프로그램 빌드
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 각 소스 파일의 오브젝트 파일 생성 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean 명령어로 오브젝트 파일과 타겟 프로그램을 삭제
clean:
	rm -f $(OBJS) $(TARGET)