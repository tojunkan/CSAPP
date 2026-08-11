struct prob {
	int *p;			/* offset: 0  */
	struct {
		int x;		/* offset: 8  */
		int y;		/* offset: 12 */
	} s;
	struct prob *next;	/* offset: 16 */
};

void sp_init(struct prob *sp) {
	sp->s.x = sp->s.y;
	sp->p = &sp->s.x;
	sp->next = sp;
}
