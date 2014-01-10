
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Acl\Resource
 *
 * This class defines resource entity and its description
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Resource) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, Resource, phalcon, acl_resource, phalcon_acl_resource_method_entry, 0);

/**
	 * Resource name
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Resource description
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_description"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Resource name
 * @var string
 */
PHP_METHOD(Phalcon_Acl_Resource, getName) {



}

/**
 * Resource name
 * @var string
 */
PHP_METHOD(Phalcon_Acl_Resource, __toString) {



}

/**
 * Resource description
 * @var string
 */
PHP_METHOD(Phalcon_Acl_Resource, getDescription) {



}

/**
 * Phalcon\Acl\Resource constructor
 *
 * @param string name
 * @param string description
 */
PHP_METHOD(Phalcon_Acl_Resource, __construct) {

	zval *name_param = NULL, *description_param = NULL;
	zval *name = NULL, *description = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &description_param);

		zephir_get_strval(name, name_param);
	if (!description_param) {
		ZEPHIR_INIT_VAR(description);
		ZVAL_EMPTY_STRING(description);
	}


	if (ZEPHIR_IS_STRING(name, "*")) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_acl_exception_ce, "Resource name cannot be '*'");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	if (description && Z_STRLEN_P(description)) {
		zephir_update_property_this(this_ptr, SL("_description"), description TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

