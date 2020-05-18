#ifndef MAIN_HPP

#define MAIN_HPP

#ifndef WASM

#define SPRINTF sprintf_s

#else

#define SPRINTF sprintf

#endif

#endif