
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
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
* Phalcon\Translate\Adapter
*
* Base class for Phalcon\Translate adapters
*/
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate, Adapter, phalcon, translate_adapter, phalcon_translate_adapter_nativearray_ce, phalcon_translate_adapter_method_entry, 0);

	zend_class_implements(phalcon_translate_adapter_ce TSRMLS_CC, 1, phalcon_translate_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Returns the translation string of the given key
 *
 * @param string  translateKey
 * @param array   placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter, t) {

	zval *translateKey_param = NULL, *placeholders = NULL;
	zval *translateKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders);

	if (Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(translateKey_param) == IS_STRING) {
		translateKey = translateKey_param;
	} else {
		ZEPHIR_INIT_VAR(translateKey);
		ZVAL_EMPTY_STRING(translateKey);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	zephir_call_method_p2(return_value, this_ptr, "query", translateKey, placeholders);
	RETURN_MM();

}

/**
 * Sets a translation value
 *
 * @param         string offset
 * @param         string value
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetSet) {

	zval *offset, *value;

	zephir_fetch_params(0, 2, 0, &offset, &value);



	ZEPHIR_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object");
	return;

}

/**
 * Check whether a translation key exists
 *
 * @param string  translateKey
 * @return boolean
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetExists) {

	zval *translateKey_param = NULL;
	zval *translateKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &translateKey_param);

	if (Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(translateKey_param) == IS_STRING) {
		translateKey = translateKey_param;
	} else {
		ZEPHIR_INIT_VAR(translateKey);
		ZVAL_EMPTY_STRING(translateKey);
	}


	zephir_call_method_p1(return_value, this_ptr, "exists", translateKey);
	RETURN_MM();

}

/**
 * Unsets a translation from the dictionary
 *
 * @param string offset
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetUnset) {


	ZEPHIR_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object");
	return;

}

/**
 * Returns the translation related to the given key
 *
 * @param  string translateKey
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetGet) {

	zval *translateKey_param = NULL;
	zval *translateKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &translateKey_param);

	if (Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(translateKey_param) == IS_STRING) {
		translateKey = translateKey_param;
	} else {
		ZEPHIR_INIT_VAR(translateKey);
		ZVAL_EMPTY_STRING(translateKey);
	}


	zephir_call_method_p2(return_value, this_ptr, "query", translateKey, ZEPHIR_GLOBAL(global_null));
	RETURN_MM();

}

