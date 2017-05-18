//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//
//void swap(int *a, int *b) { int n = *a; *a = *b; *b = n; }
//
//
//void sort(int *s, int *e) {
//
//	if (s == e) return;
//
//	// Šî€’l
//	int pivot = *s;
//
//	int *p1 = s;
//	int *p2 = e;
//
//	while (1) {
//
//		if (*p1 >= pivot && *p2 < pivot) {
//			swap(p1, p2);
//		}
//
//		if (*p1 < pivot) {
//			p1++;
//			if (p1 == p2) { break; }
//		}
//		if (*p2 >= pivot) {
//			p2--;
//			if (p1 == p2) { break; }
//		}
//
//	}
//
//	if (p1 != s && *p1 >= pivot) p1--;
//	else if (p2 != e) p2++;
//
//	sort(s, p1);
//	sort(p2, e);
//
//}
//
//
//int main() {
//
//	const int MAX = 100;
//
//	srand(time(0));
//
//	int *data = new int[MAX];
//
//	for (int i = 0; i < MAX; ++i) {
//		data[i] = rand() % 1000;
//	}
//
//	sort(&data[0], &data[MAX - 1]);
//
//	for (int i = 0; i < MAX; ++i) {
//		printf("%d\n", data[i]);
//	}
//
//	printf("END");
//	getchar();
//	return 0;
//}
