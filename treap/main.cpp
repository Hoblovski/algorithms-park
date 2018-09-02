#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "treap.cpp"

#define ignore_till_eol() do { while (getchar() != '\n') ; } while (0)

int n;
int main() {
	treap_init();

	scanf("%d", &n);
	ignore_till_eol();
	for (int i = 0; i < n; i++) {
		char cmd;
		int v1, v2, v3;
		scanf("%c", &cmd);		
		switch (cmd) {
			case 'i':
				scanf("%d", &v1);
				treap_insert(&root, v1);
				break;
			case 'd':
				scanf("%d", &v1);
				treap_delete(&root, v1);
				break;
			case 'r':
				scanf("%d%d", &v1, &v2);
				v3 = treap_cntless(root, v1);
				if (v3 != v2) {
					printf("BAD! at i=%d.. RANK %d.. treap=%d.. std=%d..\n",
							i, v1, v3, v2);
					return 1;
				}
				break;
			case 's':
				scanf("%d%d", &v1, &v2);
				v3 = treap_select(root, v1)->v;
				if (v3 != v2) {
					printf("BAD! at i=%d.. SELECT %d.. treap=%d.. std=%d..\n",
							i, v1, v3, v2);
					return 1;
				}
				break;
			default:
				printf("BAD CMD!\n");
				return 1;
		}
		ignore_till_eol();
		// Useful for debugging:
		// printf("I=%d\n", i); traverse(root); printf("\n\n");
	}
	printf("ALL RIGHT!\n");
	return 0;
}
