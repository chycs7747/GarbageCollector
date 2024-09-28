#include "garbage_collector.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    GarbageCollector GC = {0};  // GC 초기화
    
    // Data 1
    Struct* data_ptr = (Struct*)mm_allocate_memory(&GC, sizeof(Struct));
    // Data 2
    int* int_data = (int*)mm_allocate_memory(&GC, sizeof(int));
    // Data 3
    char** name = (char**)mm_allocate_memory(&GC, sizeof(char*));

    // 각 포인터가 가리킬 메모리 공간을 할당 (5바이트 NULL 문자 포함)
    name[0] = (char*)mm_allocate_memory(&GC, 5 * sizeof(char));
    name[1] = (char*)mm_allocate_memory(&GC, 5 * sizeof(char));
    name[2] = (char*)mm_allocate_memory(&GC, 5 * sizeof(char));
    

    int a = 40;
    
    printf("allocate completed..\n");

    // 필드 접근 및 값 할당
    data_ptr->data1 = 10;
    data_ptr->data2 = 'a';

    *int_data = a;
    strcpy(name[0], "yuny");
    strcpy(name[1], "zunz");
    strcpy(name[2], "junj");


    // 출력
    printf("data_ptr->data1 = %d\n", data_ptr->data1);
    printf("data_ptr->data2 = %c\n", data_ptr->data2);

    printf("*int_data = %d\n", *int_data);

    printf("name[0] = %s\n", name[0]);
    printf("name[1] = %s\n", name[1]);
    printf("name[2] = %s\n", name[2]);

    // 가비지컬렉터 출력
    gc_traverse(&GC);

    printf("increase ref_count\n");
    gc_increase_reference(&GC, int_data);
    printf("decrease ref_count\n");
    gc_decrease_reference(&GC, int_data);
    printf("decrease ref_count\n");
    gc_decrease_reference(&GC, int_data);
    printf("%p deleted.. now value became = %d\n", int_data, *int_data);
    
    // 가비지컬렉터 출력
    gc_traverse(&GC);


    gc_refresh_heap(&GC);
    printf("refreshed heap...\n");
    // 가비지컬렉터 출력
    gc_traverse(&GC);

    return 0;
}
