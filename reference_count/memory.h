#ifndef MEMORY_H
#define MEMORY_H

#include "object.h"
#include "garbage_collector.h"
#include <stdio.h>
#include <stdlib.h>

// 메모리 할당 함수
TObject* mm_allocate_memory(GarbageCollector* gc, int type_size); // 객체 메모리 할당 함수

#endif // MEMORY_H