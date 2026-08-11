typedef union {
	struct {
		long  u;
		short v;
		char  w;
	} t1;
	struct {
		int a[2];
		char  *p;
	} t2;
} u_type;

typedef long typel;
void get_long(u_type *up, typel *dest) {
	*dest =  up->t1.u;
}
typedef short types;
void get_short(u_type *up, types *dest) {
	*dest =  up->t1.v;
}
typedef char *typecp;
void get_charp(u_type *up, typecp *dest) {
	*dest =  &up->t1.w;
}
typedef int *typeip;
void get_intp(u_type *up, typeip *dest) {
	*dest =  up->t2.a;
}
typedef int typei;
void get_int(u_type *up, typei *dest) {
	*dest =  up->t2.a[up->t1.u];
}
typedef char typec;
void get_char(u_type *up, typec *dest) {
	*dest =  *up->t2.p;
}
