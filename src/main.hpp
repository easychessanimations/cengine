#ifndef MAIN_HPP

#define MAIN_HPP

#ifndef WASM

#define SPRINTF sprintf_s
#define BSPRINTF(X,Y,Z) char X[200];sprintf_s(X,Y,Z);

#else

#define SPRINTF sprintf
#define BSPRINTF(X,Y,Z) char X[200];sprintf(X,Y,Z);

#endif

struct ToIntResult{
	bool ok;
	int value;
};

inline ToIntResult to_int(char const *s){
     if ( s == NULL || *s == '\0' ) return ToIntResult{false, 0};

     bool negate = (s[0] == '-');
     if ( *s == '+' || *s == '-' ) ++s;

     if ( *s == '\0') return ToIntResult{false, 0};

     int result = 0;

     while(*s){
          if ( *s >= '0' && *s <= '9' ){
              result = result * 10  - (*s - '0');
          } else return ToIntResult{false, 0};
          ++s;
     }
     return ToIntResult{true, negate ? result : -result};
}

#endif