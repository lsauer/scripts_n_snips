

#ifndef PHP_cxpcore_H
#define PHP_cxpcore_H

extern zend_module_entry cxpcore_module_entry;
#define phpext_cxpcore_ptr &cxpcore_module_entry

#ifdef PHP_WIN32
#define PHP_cxpcore_API __declspec(dllexport)
#else
#define PHP_cxpcore_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
PHP_MINIT_FUNCTION(cxpcore);
PHP_MSHUTDOWN_FUNCTION(cxpcore);
PHP_RINIT_FUNCTION(cxpcore);
PHP_RSHUTDOWN_FUNCTION(cxpcore);
*/
PHP_MINFO_FUNCTION(cxpcore);

ZEND_FUNCTION(cxpcore_test);

#ifdef ZTS
#define cxpcore_G(v) TSRMG(cxpcore_globals_id, zend_cxpcore_globals *, v)
#else
#define cxpcore_G(v) (cxpcore_globals.v)
#endif

#endif	/* PHP_cxpcore_H */
