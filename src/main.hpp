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

inline int get_int_else(char const *s, int default_value){
	ToIntResult ti = to_int(s);
	if(ti.ok){
		return ti.value;
	}
	return default_value;
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
	return cnt;
}

class Tokenizer{
public:	
	std::string content;
	std::string shift_char(){
		if(content == "") return "";
		std::string c = content.substr(0,1);
		content = content.substr(1);
		return c;
	};
	void flush(){		
		while(true){
			if(content == ""){
				return;
			}else{
				if(content[0] == ' '){
					shift_char();
				}else{
					return;
				}
			}
		}
	};
	std::string get_token(){
		flush();
		if(content == "") return "";		
		std::string buff = "";
		while(true){
			if(content == ""){
				return buff;
			}else{
				std::string c = shift_char();
				if(c == " ") return buff;
				buff += c;
			}
		}
	};
	std::string get_up_to(std::string up_to){
		std::string buff = "";
		while(true){
			if(content == "") return buff;
			std::string token = get_token();
			if(token == up_to) return buff;
			if(buff == ""){
				buff = token;
			}else{
				buff = buff + " " + token;
			}
		}
	};
	Tokenizer(std::string _content){
		content = _content;
	};
};

#endif