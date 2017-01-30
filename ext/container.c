
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "container.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *container_container_ce;

ZEND_DECLARE_MODULE_GLOBALS(container)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(container)
{
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Container_Container);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(container)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_container_globals *container_globals TSRMLS_DC)
{
	container_globals->initialized = 0;

	/* Memory options */
	container_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	container_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	container_globals->cache_enabled = 1;

	/* Recursive Lock */
	container_globals->recursive_lock = 0;

	/* Static cache */
	memset(container_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_container_globals *container_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(container)
{

	zend_container_globals *container_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	container_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(container_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(container_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(container)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(container)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_CONTAINER_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_CONTAINER_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_CONTAINER_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_CONTAINER_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_CONTAINER_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(container)
{
	php_zephir_init_globals(container_globals TSRMLS_CC);
	php_zephir_init_module_globals(container_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(container)
{

}


zend_function_entry php_container_functions[] = {
ZEND_FE_END

};

zend_module_entry container_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_CONTAINER_EXTNAME,
	php_container_functions,
	PHP_MINIT(container),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(container),
#else
	NULL,
#endif
	PHP_RINIT(container),
	PHP_RSHUTDOWN(container),
	PHP_MINFO(container),
	PHP_CONTAINER_VERSION,
	ZEND_MODULE_GLOBALS(container),
	PHP_GINIT(container),
	PHP_GSHUTDOWN(container),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_CONTAINER
ZEND_GET_MODULE(container)
#endif
