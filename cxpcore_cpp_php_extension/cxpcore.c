// requires php and zend sources

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "php_cxpcore.h"

#define CXPCORE_MODULE_NAME		"cxpcore"
#define CXPCORE_MODULE_VERSION	"0.01"

/* 
  Look up table with the php function names and the counterparts in 'C'
  extended to zif_funcname
*/
zend_function_entry cxpcore_functions[] = 
{
	ZEND_FE(cxpcore_test,			NULL)
	{NULL,		NULL,		NULL}
};

/* 
   contains module information and module parameters
   Parameter dieses Moduls zu beschreiben
*/
zend_module_entry cxpcore_module_entry = {
	STANDARD_MODULE_HEADER,				  /* keeping to standards	*/
	CXPCORE_MODULE_NAME,				    /* module name				*/
	cxpcore_functions,					    /* points to function LUT		*/
	NULL,								            /* PHP_MINIT(cxpcore)			*/
	NULL,								            /* PHP_MSHUTDOWN(cxpcore)		*/
	NULL,								            /* PHP_RINIT(cxpcore)			*/
	NULL,								            /* PHP_RSHUTDOWN(cxpcore)		*/
	PHP_MINFO(cxpcore),					    /* module info function			*/
	CXPCORE_MODULE_VERSION,				  /* version number				*/
	STANDARD_MODULE_PROPERTIES			/* skip the rest				*/
};

/* 
   the following macro allows dynamic loading of the module via php's dl()
*/
#ifdef COMPILE_DL_cxpcore
	ZEND_GET_MODULE(cxpcore)
#endif

/* 
   definition of module information passed at construction; accessible via php's 'phpinfo()'
*/
PHP_MINFO_FUNCTION(cxpcore) {
	php_info_print_table_start();
	php_info_print_table_row(2, "cxpcore support", "enabled");
	php_info_print_table_row(2, "version", cxpcore_module_entry.version);
	php_info_print_table_end();
}


/* export function definitions

ZEND_FUNCTIONS is expanded during invocation as follows:
  void zif_my_function( int ht,
                        zval *return_value, 
                        zval *this_ptr, 
                        int return_value_used, 
                        zend_executor_globals *executor_globals
                      );  
*/

/* proto string word(string string) */
ZEND_FUNCTION(cxpcore_test) {
	zval **num1, **num2;

	/* check the params and assign to blocks */
	switch (ZEND_NUM_ARGS()) {
		case 1:
			/* reading the paramerts */
			if (zend_get_parameters_ex(2, &num1, &num2) != SUCCESS) {
				ZEND_WRONG_PARAM_COUNT(); /* throw error if wrong number of params are passed */
			}
			break;
		default:
			ZEND_WRONG_PARAM_COUNT();
	}

	/* check the param's types */
	if ( Z_TYPE_PP(num1) != IS_LONG || Z_TYPE_PP(num2) != IS_LONG) {
		zend_error(E_WARNING, "cxpcore_test() - invalid variable type");
		RETURN_NULL();
	}
	/* returning of the parameters via a zend helper macro: RETVAL_XXXXX  */
	RETVAL_LONG( Z_TYPE_PP(num1)+Z_TYPE_PP(num2) );
}