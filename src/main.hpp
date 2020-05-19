#ifndef MAIN_HPP

#define MAIN_HPP

#ifndef WASM

#define SPRINTF sprintf_s
#define BSPRINTF(X,Y,Z) char X[200];sprintf_s(X,Y,Z);

#else

#define SPRINTF sprintf
#define BSPRINTF(X,Y,Z) char X[200];sprintf(X,Y,Z);

#endif

#include <iostream>

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

inline int split(std::string str, std::string delim, std::string *buff) {
	int index = int(str.find(delim));
	int cnt = 0;
	if (index < 0) {
		buff[cnt] = str;
		return 1;
	}
	while (index >= 0) {
		buff[cnt++] = str.substr(0, index);				
		str = str.substr(index + delim.length());		
		index = int(str.find(delim));
		if(index < 0){
			buff[cnt++] = str;
		}
	}
	return cnt + 1;
}

#endif