#include "Error.h"

Error::Error( string message ) : runtime_error( message ) {
}

Error::~Error() {
}
