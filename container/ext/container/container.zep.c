
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "Zend/zend_closures.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Container_Container) {

	ZEPHIR_REGISTER_CLASS(Container, Container, container, container, container_container_method_entry, 0);

	zend_declare_property_null(container_container_ce, SL("abstractions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(container_container_ce, SL("bindings"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(container_container_ce, SL("concretions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(container_container_ce, SL("instances"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(container_container_ce, SL("reflectors"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(container_container_ce, SL("singletons"), ZEND_ACC_PROTECTED TSRMLS_CC);

	container_container_ce->create_object = zephir_init_properties_Container_Container;
	return SUCCESS;

}

PHP_METHOD(Container_Container, make) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *class_name, class_name_sub, _1, concrete, instance, _4, _2$$3, _3$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&class_name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&concrete);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_name);



	_0 = Z_TYPE_P(class_name) == IS_STRING;
	if (_0) {
		zephir_read_property(&_1, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_array_isset(&_1, class_name);
	}
	if (_0) {
		zephir_read_property(&_2$$3, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, class_name, PH_NOISY | PH_READONLY, "container/container.zep", 21 TSRMLS_CC);
		RETURN_CTOR(_3$$3);
	}
	ZEPHIR_CALL_METHOD(&concrete, this_ptr, "getconcrete", NULL, 0, class_name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "isabstract", NULL, 0, class_name);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_CALL_METHOD(&instance, this_ptr, "make", NULL, 1, &concrete);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&instance, this_ptr, "build", NULL, 0, &concrete);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("instances"), class_name, &instance TSRMLS_CC);
	RETURN_CCTOR(instance);

}

PHP_METHOD(Container_Container, build) {

	zend_class_entry *_7$$6;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *class_name, class_name_sub, _1, reflector, constructor, dependencies, parameters, _4, _2$$3, _3$$3, _5$$5, _6$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&class_name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&reflector);
	ZVAL_UNDEF(&constructor);
	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_name);



	_0 = Z_TYPE_P(class_name) == IS_STRING;
	if (_0) {
		zephir_read_property(&_1, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_array_isset(&_1, class_name);
	}
	if (_0) {
		zephir_read_property(&_2$$3, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, class_name, PH_NOISY | PH_READONLY, "container/container.zep", 42 TSRMLS_CC);
		RETURN_CTOR(_3$$3);
	}
	if (zephir_instance_of_ev(class_name, zend_ce_closure TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 2, class_name, this_ptr);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&reflector, this_ptr, "getreflector", NULL, 0, class_name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &reflector, "isinstantiable", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$5);
		object_init_ex(&_5$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$5, "container/container.zep", 54 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&constructor, &reflector, "getconstructor", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&constructor) == IS_NULL) {
		zephir_fetch_safe_class(&_6$$6, class_name);
		_7$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6$$6), Z_STRLEN_P(&_6$$6), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(return_value, _7$$6);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&dependencies, &constructor, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&parameters, this_ptr, "resolvedependencies", NULL, 0, &dependencies);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&reflector, "newinstanceargs", NULL, 0, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Container_Container, getConcrete) {

	zval *class_name, class_name_sub, _0, _1$$3, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&class_name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	zephir_fetch_params(0, 1, 0, &class_name);



	zephir_read_property(&_0, this_ptr, SL("bindings"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, class_name)) {
		zephir_read_property(&_1$$3, this_ptr, SL("bindings"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, class_name, PH_NOISY | PH_READONLY, "container/container.zep", 72 TSRMLS_CC);
		RETURN_CTORW(_2$$3);
	}
	RETVAL_ZVAL(class_name, 1, 0);
	return;

}

PHP_METHOD(Container_Container, resolveDependencies) {

	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *dependencies_param = NULL, dependency, results, class_name, *_0, _1$$4, _3$$5;
	zval dependencies;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&dependency);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&class_name);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dependencies_param);

	zephir_get_arrval(&dependencies, dependencies_param);


	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	zephir_is_iterable(&dependencies, 0, "container/container.zep", 93);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&dependencies), _0)
	{
		ZEPHIR_INIT_NVAR(&dependency);
		ZVAL_COPY(&dependency, _0);
		ZEPHIR_CALL_METHOD(&class_name, &dependency, "getclass", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&class_name) == IS_NULL) {
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "resolveprimitive", &_2, 0, &dependency);
			zephir_check_call_status();
			zephir_array_append(&results, &_1$$4, PH_SEPARATE, "container/container.zep", 87);
		} else {
			ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "resolveclass", &_4, 0, &dependency);
			zephir_check_call_status();
			zephir_array_append(&results, &_3$$5, PH_SEPARATE, "container/container.zep", 89);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&dependency);
	RETURN_CCTOR(results);

}

PHP_METHOD(Container_Container, resolvePrimitive) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameter, parameter_sub, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameter_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameter);



	ZEPHIR_CALL_METHOD(&_0, parameter, "isdefaultvalueavailable", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(parameter, "getdefaultvalue", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, spl_ce_InvalidArgumentException);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 3);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "container/container.zep", 102 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Container_Container, resolveClass) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameter, parameter_sub, e, _0$$3, _1$$3, _2$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameter_sub);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameter);




	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_0$$3, parameter, "getclass", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_1$$3, &_0$$3, SL("name"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "make", NULL, 0, &_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZVAL_OBJ(&e, EG(exception));
		Z_ADDREF_P(&e);
		if (zephir_instance_of_ev(&e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(&_2$$4, parameter, "isoptional", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_2$$4)) {
				ZEPHIR_RETURN_CALL_METHOD(parameter, "getdefaultvalue", NULL, 0);
				zephir_check_call_status();
				RETURN_MM();
			}
			zephir_throw_exception_debug(&e, "container/container.zep", 116 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}

}

PHP_METHOD(Container_Container, getReflector) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *class_name, class_name_sub, _0, reflector, _1$$3, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&class_name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&reflector);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_name);



	zephir_read_property(&_0, this_ptr, SL("reflectors"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, class_name)) {
		zephir_read_property(&_1$$3, this_ptr, SL("reflectors"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, class_name, PH_NOISY | PH_READONLY, "container/container.zep", 123 TSRMLS_CC);
		RETURN_CTOR(_2$$3);
	}
	ZEPHIR_INIT_VAR(&reflector);
	object_init_ex(&reflector, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflector, "__construct", NULL, 4, class_name);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("reflectors"), class_name, &reflector TSRMLS_CC);
	RETURN_CCTOR(reflector);

}

PHP_METHOD(Container_Container, isAbstract) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *class_name, class_name_sub, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&class_name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_name);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getreflector", NULL, 0, class_name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "isinstantiable", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_1));

}

PHP_METHOD(Container_Container, bind) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *class_name, class_name_sub, *resolver, resolver_sub, __$false, __$true, _0, _3, _4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&class_name_sub);
	ZVAL_UNDEF(&resolver_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &class_name, &resolver);



	ZEPHIR_CALL_FUNCTION(&_0, "is_a", &_1, 5, resolver, class_name, &__$false);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_update_property_array(this_ptr, SL("instances"), class_name, resolver TSRMLS_CC);
		RETURN_MM_NULL();
	}
	do {
		_2 = 1;
		ZEPHIR_CALL_FUNCTION(&_3, "is_a", &_1, 5, resolver, class_name, &__$true);
		zephir_check_call_status();
		if (_2 == zephir_instance_of_ev(resolver, zend_ce_closure TSRMLS_CC) || ZEPHIR_IS_FALSE(&_3)) {
			zephir_update_property_array(this_ptr, SL("bindings"), class_name, resolver TSRMLS_CC);
			RETURN_MM_NULL();
		}
		break;
	} while(0);

	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, spl_ce_InvalidArgumentException);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 3);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "container/container.zep", 156 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Container_Container, singleton) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *class_name, class_name_sub, *resolver, resolver_sub, __$false, __$true, _0, _3, _4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&class_name_sub);
	ZVAL_UNDEF(&resolver_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &class_name, &resolver);



	ZEPHIR_CALL_FUNCTION(&_0, "is_a", &_1, 5, resolver, class_name, &__$false);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_update_property_array(this_ptr, SL("instances"), class_name, resolver TSRMLS_CC);
		RETURN_MM_NULL();
	}
	do {
		_2 = 1;
		ZEPHIR_CALL_FUNCTION(&_3, "is_a", &_1, 5, resolver, class_name, &__$true);
		zephir_check_call_status();
		if (_2 == zephir_instance_of_ev(resolver, zend_ce_closure TSRMLS_CC) || ZEPHIR_IS_FALSE(&_3)) {
			zephir_update_property_array(this_ptr, SL("bindings"), class_name, resolver TSRMLS_CC);
			RETURN_MM_NULL();
		}
		break;
	} while(0);

	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, spl_ce_InvalidArgumentException);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 3);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "container/container.zep", 177 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

zend_object *zephir_init_properties_Container_Container(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("singletons"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("singletons"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("reflectors"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("reflectors"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("instances"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("concretions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("concretions"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("bindings"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("bindings"), &_9$$7);
		}
		zephir_read_property(&_10, this_ptr, SL("abstractions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval(this_ptr, SL("abstractions"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

