#include <stdio.h>
#include <stdlib.h>
#include "parse_module.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <wasm-file>\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        perror("open");
        return 1;
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *buf = malloc(size);
    if (!buf) {
        fprintf(stderr, "malloc failed\n");
        fclose(f);
        return 1;
    }
    if (fread(buf, 1, size, f) != (size_t)size) {
        perror("fread");
        free(buf);
        fclose(f);
        return 1;
    }
    fclose(f);
    struct Module *module = NULL;
    Result r = parse_module(NULL, &module, buf, size);
    if (r) {
        fprintf(stderr, "parse error: %s\n", r);
        free(buf);
        return 1;
    }
    printf("parsed successfully\n");
    free(module);
    free(buf);
    return 0;
}
