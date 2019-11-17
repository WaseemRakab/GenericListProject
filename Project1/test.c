#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("number of files are invaild\n");
	}
	FILE *orig = fopen(argv[1], "r");
	int max = 0, let[128] = { 0 };
	char ch;
	while (!feof(orig)) {
		ch = fgetc(orig);
		if (ch != -1 && ch != 255) { // EOF = -1
			let[ch]++;
			if (let[ch] > max) {
				max = let[ch];
			}
		}
	}
	fclose(orig);
	for (int i = 0; i < 128; i++) {
		if (let[i] == max) {
			printf("%c ", i);
		}
	}
	return 0;
}