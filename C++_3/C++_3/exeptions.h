#include <cstring>

class Exception {
private:
	int code;
	char message[80];
public:
	Exception();
	Exception(int error_code, const char* error_message);
	void show() const;
};

class IntException : public Exception {
public:
	IntException(const char* error_message);
};

class BoolException : public Exception {
public:
	BoolException(const char* error_message);
};

class CharArrayException : public Exception {
public:
	CharArrayException(const char* error_message);
};
