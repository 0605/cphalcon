
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 |          Jason Rice                                                    |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Model\Validator\StringLength
 *
 * Simply validates specified string length constraints
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\StringLength as StringLengthValidator;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *	{
 *		this->validate(new StringLengthValidator(array(
 *			"field" => 'name_last',
 *			'max' => 50,
 *			'min' => 2,
 *			'messageMaximum' => 'We don\'t like really long names',
 *			'messageMinimum' => 'We want more than just their initials'
 *		)));
 *		if (this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, StringLength, phalcon, mvc_model_validator_stringlength, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_stringlength_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_stringlength_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;

}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_StringLength, validate) {

	zend_bool invalidMaximum, invalidMinimum;
	zval *record, *field, *isSetMin, *isSetMax, *value, *length, *maximum, *minimum, *message = NULL, *replacePairs = NULL, *_0, *_1, _2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", 1);
	ZEPHIR_INIT_VAR(field);
	zephir_call_method_p1(field, this_ptr, "getoption", _0);
	if ((Z_TYPE_P(field) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "min", 1);
	ZEPHIR_INIT_VAR(isSetMin);
	zephir_call_method_p1(isSetMin, this_ptr, "issetoption", _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "max", 1);
	ZEPHIR_INIT_VAR(isSetMax);
	zephir_call_method_p1(isSetMax, this_ptr, "issetoption", _0);
	if (!(zephir_is_true(isSetMin))) {
		if (!(zephir_is_true(isSetMax))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A minimum or maximum must be set");
			return;
		}
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "field", 1);
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, record, "readattribute", _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "allowEmpty", 1);
	zephir_call_method_p1(_0, this_ptr, "issetoption", _1);
	if (zephir_is_true(_0) && ZEPHIR_IS_EMPTY(value)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(length);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "mb_strlen", 0);
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p1(_1, "function_exists", &_2);
	if (zephir_is_true(_1)) {
		zephir_call_func_p1(length, "mb_strlen", value);
	} else {
		ZVAL_LONG(length, zephir_fast_strlen_ev(value));
	}
	invalidMaximum = 0;
	invalidMinimum = 0;
	if (zephir_is_true(isSetMax)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "max", 1);
		ZEPHIR_INIT_VAR(maximum);
		zephir_call_method_p1(maximum, this_ptr, "getoption", _3);
		invalidMaximum = ZEPHIR_GT(length, maximum);
		if ((invalidMaximum == 1)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "messageMaximum", 1);
			ZEPHIR_INIT_VAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _3);
			ZEPHIR_INIT_VAR(replacePairs);
			array_init(replacePairs);
			zephir_array_update_string(&replacePairs, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(message);
				ZVAL_STRING(message, "Value of field :field exceeds the maximum :max characters", 1);
			}
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_func_p2(_3, "strtr", message, replacePairs);
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "TooLong", 1);
			zephir_call_method_p3_noret(this_ptr, "appendmessage", _3, field, _4);
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(isSetMin)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "min", 1);
		ZEPHIR_INIT_VAR(minimum);
		zephir_call_method_p1(minimum, this_ptr, "getoption", _3);
		invalidMinimum = ZEPHIR_LT(length, minimum);
		if ((invalidMinimum == 1)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "messageMinimum", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _3);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init(replacePairs);
			zephir_array_update_string(&replacePairs, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(message);
				ZVAL_STRING(message, "Value of field :field is less than the minimum :min characters", 1);
			}
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_func_p2(_3, "strtr", message, replacePairs);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "TooShort", 1);
			zephir_call_method_p3_noret(this_ptr, "appendmessage", _3, field, _4);
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

