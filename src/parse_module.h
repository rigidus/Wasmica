#ifndef PARSE_MODULE_H
#define PARSE_MODULE_H
#include <stdint.h>

typedef const char * Result;
struct Environment;
typedef struct Environment * IEnvironment;
struct Module;
typedef struct Module * IModule;

Result parse_module(IEnvironment env, IModule *out, const uint8_t *wasm, uint32_t size);

#endif
