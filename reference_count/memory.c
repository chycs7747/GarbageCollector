#include "memory.h"

TObject* mm_allocate_memory(GarbageCollector* gc, int type_size) {
    // TObject 구조체와 데이터 메모리 할당
    TObject* obj = (TObject*)malloc(sizeof(TObject));
    if (obj == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // 객체를 GC에 추가
    gc_append_object(gc, obj);

    // 데이터 메모리 할당
    obj->data = malloc(type_size);
    if (obj->data == NULL) {
        fprintf(stderr, "Data allocation failed\n");
        free(obj);
        exit(1);
    }

    obj->ref_count = 1;
    obj->data_size = type_size;
    // obj->is_marked = false;
    return obj->data;
}