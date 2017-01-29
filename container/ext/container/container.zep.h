
extern zend_class_entry *container_container_ce;

ZEPHIR_INIT_CLASS(Container_Container);

PHP_METHOD(Container_Container, make);
PHP_METHOD(Container_Container, build);
PHP_METHOD(Container_Container, getConcrete);
PHP_METHOD(Container_Container, resolveDependencies);
PHP_METHOD(Container_Container, resolvePrimitive);
PHP_METHOD(Container_Container, resolveClass);
PHP_METHOD(Container_Container, getReflector);
PHP_METHOD(Container_Container, isAbstract);
PHP_METHOD(Container_Container, bind);
PHP_METHOD(Container_Container, singleton);
zend_object *zephir_init_properties_Container_Container(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_container_container_make, 0, 0, 1)
	ZEND_ARG_INFO(0, class_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_container_container_build, 0, 0, 1)
	ZEND_ARG_INFO(0, class_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_container_container_getconcrete, 0, 0, 1)
	ZEND_ARG_INFO(0, class_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_container_container_resolvedependencies, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, dependencies, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_container_container_resolveprimitive, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, parameter, ReflectionParameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_container_container_resolveclass, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, parameter, ReflectionParameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_container_container_getreflector, 0, 0, 1)
	ZEND_ARG_INFO(0, class_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_container_container_isabstract, 0, 0, 1)
	ZEND_ARG_INFO(0, class_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_container_container_bind, 0, 0, 2)
	ZEND_ARG_INFO(0, class_name)
	ZEND_ARG_INFO(0, resolver)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_container_container_singleton, 0, 0, 2)
	ZEND_ARG_INFO(0, class_name)
	ZEND_ARG_INFO(0, resolver)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(container_container_method_entry) {
	PHP_ME(Container_Container, make, arginfo_container_container_make, ZEND_ACC_PUBLIC)
	PHP_ME(Container_Container, build, arginfo_container_container_build, ZEND_ACC_PUBLIC)
	PHP_ME(Container_Container, getConcrete, arginfo_container_container_getconcrete, ZEND_ACC_PROTECTED)
	PHP_ME(Container_Container, resolveDependencies, arginfo_container_container_resolvedependencies, ZEND_ACC_PROTECTED)
	PHP_ME(Container_Container, resolvePrimitive, arginfo_container_container_resolveprimitive, ZEND_ACC_PROTECTED)
	PHP_ME(Container_Container, resolveClass, arginfo_container_container_resolveclass, ZEND_ACC_PROTECTED)
	PHP_ME(Container_Container, getReflector, arginfo_container_container_getreflector, ZEND_ACC_PROTECTED)
	PHP_ME(Container_Container, isAbstract, arginfo_container_container_isabstract, ZEND_ACC_PROTECTED)
	PHP_ME(Container_Container, bind, arginfo_container_container_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Container_Container, singleton, arginfo_container_container_singleton, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
