#ifndef OBJECT_H
#define OBJECT_H

#include <stdbool.h>

// TObject 구조체 정의
typedef struct _TObject {
    int ref_count;
    int data_size;
    void* data;  // 다양한 데이터를 가리킬 void 포인터
    struct _TObject* next;  // 연결 리스트를 위한 다음 객체 포인터
    struct _TObject* prev;  // 연결 리스트를 위한 이전 객체 포인터
    // bool is_marked;  // 가비지 컬렉션 마크용
} TObject;

typedef struct _Struct {
    int data1;
    char data2;
} Struct;


#endif // OBJECT_H

