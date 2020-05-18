#ifndef MAIN_HPP

#define MAIN_HPP

#ifndef WASM

#define SPRINTF sprintf_s
#define BSPRINTF(X,Y,Z) char X[200];sprintf_s(X,Y,Z);

#else

#define SPRINTF sprintf
#define BSPRINTF(X,Y,Z) char X[200];sprintf(X,Y,Z);

#endif

#endif