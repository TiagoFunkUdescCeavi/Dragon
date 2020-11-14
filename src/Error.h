#ifndef ERROR_H_
#define ERROR_H_

#include <string>
#include <stdexcept>

using std::runtime_error;
using std::string;

class Error: public runtime_error {
public:
	Error( string message );
	virtual ~Error();

private:
};

#endif /* ERROR_H_ */
