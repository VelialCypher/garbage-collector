#include <stdlib.h>
#include <stdio.h>

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

int main() {
	return 0;
}