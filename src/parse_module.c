#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef const char * Result;

struct Environment;
typedef struct Environment * IEnvironment;

struct Module {
    /* placeholder for future members */
};
typedef struct Module * IModule;

static const uint8_t WASM_MAGIC[] = {0x00, 0x61, 0x73, 0x6d};
static const uint8_t WASM_VERSION[] = {0x01, 0x00, 0x00, 0x00};

Result parse_module(IEnvironment env, IModule *out, const uint8_t *wasm, uint32_t size)
{
    if (!wasm || size < 8)
        return "file_too_small";

    if (memcmp(wasm, WASM_MAGIC, 4) != 0)
        return "bad_magic";

    if (memcmp(wasm + 4, WASM_VERSION, 4) != 0)
        return "bad_version";

    *out = malloc(sizeof(**out));
    if (!*out)
        return "malloc_failed";

    /* real parsing is TODO */
    return NULL; /* Err_none */
}
