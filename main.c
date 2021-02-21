#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define STACK_MAX 256

typedef enum {
	OBJ_INT,
	OBJ_PAIR,
} ObjectType_t;

typedef struct Object {
	ObjectType_t type;

	union {
		int value;
		struct {
			Object_t* head;
			Object_t* tail;
		};
	};
} Object_t;

typedef struct {
	Object_t* stack[STACK_MAX];
	int size;
} VM_t;

VM_t* VM_new() {
	VM_t* vm = (VM_t*)malloc(sizeof(VM_t));
	vm -> size = 0;
	return vm;
}

void VM_pushInStack(VM_t* vm, Object_t* item) {
	assert(vm -> size < STACK_MAX);
	vm -> stack[vm -> size++] = item;
}

Object_t* VM_popInStack(VM_t* vm) {
	assert(vm -> size > 0);
	return vm -> stack[--vm -> size];
}

Object_t* Object_new(VM_t* vm, ObjectType_t* type) {
	Object_t* obj = (Object_t*)malloc(sizeof(Object_t));
	obj -> type = type;
	return obj;
}

int main() {
	return 0;
}