#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Error\n");
		return 1;
	}
	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "w");
	char temp[128], line = '\n';
	while (!feof(in)) {
		fgets(temp, sizeof temp, in);
		temp[strcspn(temp, "\n")] = '\0';
		for (int i = strlen(temp) - 1; i >= 0; i--) {
			fputc(temp[i], out);
		}
		fputc(line, out);
		fputs(temp, out);
		fputc(line, out);
	}
	fclose(in);
	fclose(out);
}