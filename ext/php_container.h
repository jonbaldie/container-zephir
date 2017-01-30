
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_CONTAINER_H
#define PHP_CONTAINER_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_CONTAINER_NAME        "container"
#define PHP_CONTAINER_VERSION     "0.0.1"
#define PHP_CONTAINER_EXTNAME     "container"
#define PHP_CONTAINER_AUTHOR      ""
#define PHP_CONTAINER_ZEPVERSION  "0.9.6a-dev-72dbb2063e"
#define PHP_CONTAINER_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(container)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(container)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(container)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(container, v)
#else
	#define ZEPHIR_GLOBAL(v) (container_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_container_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(container_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(container_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def container_globals
#define zend_zephir_globals_def zend_container_globals

extern zend_module_entry container_module_entry;
#define phpext_container_ptr &container_module_entry

#endif
