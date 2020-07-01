#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <alloca.h>
#include <ctype.h>
#include <sys/mman.h>

enum {
	TMOVED = 7,
	TINT,
	TSTRING,
	TCELL,
	TSTMBOL,
	TPRIMITIVE,
	TFUNCTION,
	TMACRO,
	TSPE,

	// Spetypes
	TNIL = 100,
	TDOT,
	TCPAREN,
	TTRUE,
} Type;

struct Obj;

typedef struct Env {
	struct Obj *vars;
	struct Env *next;
} Env;

typedef struct Obj *primitive(Enb * enb, struct Obj **root, struct Obj **args);

typedef struct Obj {
	int type;
	union {
		void *moved;
		//Int
		struct {
			int value;
		};
		//string
		struct {
			char strbody[1];
		};
		// Cell
		struct	{
			struct Obj *car;
			struct Obj *cdr;
		};
		// Symbol
		struct {
			char name[1];
		};
		// Primitive
		struct {
			Primitive *fn;
		};
		// Function and Macro
		struct {
			struct Obj *params;
			struct Obj *body;
		};
		// Spe
		struct {
			int spetype;
		};
	};
} Obj;
