#ifndef GARBAGE_COLLECTOR_H
#define GARBAGE_COLLECTOR_H

#include "object.h"

// GarbageCollector 구조체 정의
typedef struct _GarbageCollector {
    TObject* head;  // 연결 리스트의 첫 번째 TObject
    TObject* tail;  // 연결 리스트의 마지막 TObject
} GarbageCollector;

// 함수 선언
void gc_append_object(GarbageCollector* gc, TObject* obj);   // 객체를 가비지 컬렉터에 추가
void gc_delete_object(GarbageCollector* gc, TObject* obj);   // 객체를 가비지 컬렉터에서 삭제
void gc_free_memory(GarbageCollector* gc, void* data_ptr);   // 메모리 해제 (참조 카운트에 따른 해제)
void gc_increase_reference(GarbageCollector* gc, void* data_ptr); // 참조 카운트 증가
void gc_decrease_reference(GarbageCollector* gc, void* data_ptr); // 참조 카운트 감소
void gc_traverse(GarbageCollector* gc);  // 가비지 컬렉터를 순회하여 객체 상태 출력
void gc_refresh_heap(GarbageCollector* gc); // 힙 메모리 강제 초기화

#endif // GARBAGE_COLLECTOR_H
