#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>


int main() {

	float* tabel = (float*)malloc(3 * sizeof(float));
	if (tabel == NULL) {
		return 1;
	}

	*tabel = 1.5f;
	*(tabel + 1) = 2.5f;
	*(tabel + 2) = 3.5f;

	for (int i = 0; i < 3; i++) {
		printf("Element [%d] Value: %.1f at address: %p\n", i, *(tabel + i), (void*)(tabel + i));
	}
	free(tabel);
	return 0;

}