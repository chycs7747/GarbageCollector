#include "garbage_collector.h"
#include <stdio.h>
#include <stdlib.h>

// GarbageCollector 배열에 객체 추가
void gc_append_object(GarbageCollector* gc, TObject* obj) {
    if (obj == NULL) {
        fprintf(stderr, "Error: Null pointer passed to gc_append_object\n");
        return;
    }
    if (gc->head == NULL) {
        gc->head = obj;
        gc->tail = obj;
        obj->next = NULL;
        obj->prev = NULL;
    
    } else {
        gc->tail->next = obj;
        obj->prev = gc->tail;
        obj->next = NULL;
        gc->tail = obj;
    } 

}

void gc_delete_object(GarbageCollector* gc, TObject* obj) {
    if (gc->head == NULL || obj == NULL) {
        return;
    }

    if (gc->head == obj) {
        gc->head = obj->next;
        if (gc->head != NULL) {
            gc->head->prev = NULL;
        }
        else {
            gc->tail = NULL;
        }
        printf("Deleted head object\n");
        return;
    }
    else if (gc->tail == obj) {
        gc->tail = obj->prev;
        if (gc->tail != NULL) {
            gc->tail->next = NULL;
        }
        else {
            gc->head = NULL;
        }
        printf("Deleted tail object\n");
        return;
    }
    else {
        if (obj->prev != NULL) {
            obj->prev->next = obj->next;
        }
        if (obj->next != NULL) {
            obj->next->prev = obj->prev;
        }
        printf("Deleted middle object\n");
        return;
    }
    printf("[gc_delete_object] something wrong..\n");
    return;
}

void gc_free_memory(GarbageCollector* gc, void* gc_target_obj) {
    if (gc_target_obj == NULL) {
        TObject* current = gc->head;
        while (current != NULL) {
            if (current->ref_count == 0) {
                gc_delete_object(gc, current);
                free(current->data);
                free(current);
            }
            current = current->next;
        }
    }
    else {
        TObject* current = gc_target_obj;
        gc_delete_object(gc, current);
        free(current->data);
        free(current);
    }   
}

/*
// GarbageCollector에서 메모리 해제 (Mark And Sweep)
void gc_free_memory(GarbageCollector* gc) {
    TObject* current = gc->head;
    while (current != NULL) {
        TObject* next = current->next;

        if (current->is_marked == true) {
            gc_delete_object(gc, current);
            free(current->data);
            free(current);
        }
        current = next;
    }
    return;
}
*/

void gc_increase_reference(GarbageCollector* gc, void* data_ptr) {
    TObject* current = gc->head;
    while (current != NULL) {
        if (current->data == data_ptr) {
            current->ref_count += 1;
            printf("%p: current->ref_count becomes %d..\n", current, current->ref_count);
            break;
        }
        current = current->next;
    }
    return;
}

void gc_decrease_reference(GarbageCollector* gc, void* data_ptr) {
    TObject* current = gc->head;
    
    while (current != NULL) {
        if (current->data == data_ptr) {
            current->ref_count -= 1;
            // 참조 카운트가 0이 되면 객체를 해제
            printf("%p: current->ref_count becomes %d..\n", current, current->ref_count);
            if (current->ref_count == 0) {
                gc_free_memory(gc, current);
            }
            break;
        }
        current = current->next;
    }
}

void gc_traverse(GarbageCollector* gc) {
    int count = 0;
    int data_size = 0;
    int total_heap_usage = 0;

    TObject* current = gc->head;
    while (current != NULL) {
        data_size = sizeof(*current) + current->data_size;
        count += 1;
        total_heap_usage += data_size;
        printf("=====Data Count: %d, TObject Size: %lu, Data Size %d, Total: %d=====\n", count, sizeof(*current), current->data_size, data_size);
        current = current->next;
    }
    printf("\n=====Total Data Count: %d, Heap_Usage: %d=====\n============================================================\n\n", count, total_heap_usage);
}

void gc_refresh_heap(GarbageCollector* gc) {
    TObject* current = gc->head;

    while (current != NULL) {
        TObject* next = current->next;
        gc_delete_object(gc, current);
        free(current->data);
        free(current);
        
        current = next;
    }
}