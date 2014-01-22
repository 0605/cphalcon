
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


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
 * Phalcon\Crypt
 *
 * Provides encryption facilities to phalcon applications
 *
 *<code>
 *	$crypt = new Phalcon\Crypt();
 *
 *	$key = 'le password';
 *	$text = 'This is a secret text';
 *
 *	$encrypted = $crypt->encrypt($text, $key);
 *
 *	echo $crypt->decrypt($encrypted, $key);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Crypt) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Crypt, phalcon, crypt, phalcon_crypt_method_entry, 0);

	zend_declare_property_null(phalcon_crypt_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_crypt_ce, SL("_mode"), "cbc", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_crypt_ce, SL("_cipher"), "rijndael-256", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_crypt_ce TSRMLS_CC, 1, phalcon_cryptinterface_ce);

	return SUCCESS;

}

/**
 * Sets the cipher algorithm
 *
 * @param string cipher
 * @return Phalcon\Crypt
 */
PHP_METHOD(Phalcon_Crypt, setCipher) {

	zval *cipher_param = NULL;
	zval *cipher = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);

	if (Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(cipher_param) == IS_STRING) {
		cipher = cipher_param;
	} else {
		ZEPHIR_INIT_VAR(cipher);
		ZVAL_EMPTY_STRING(cipher);
	}


	zephir_update_property_this(this_ptr, SL("_cipher"), cipher TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the current cipher
 *
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, getCipher) {


	RETURN_MEMBER(this_ptr, "_cipher");

}

/**
 * Sets the encrypt/decrypt mode
 *
 * @param string cipher
 * @return Phalcon\Crypt
 */
PHP_METHOD(Phalcon_Crypt, setMode) {

	zval *mode;

	zephir_fetch_params(0, 1, 0, &mode);



	zephir_update_property_this(this_ptr, SL("_mode"), mode TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current encryption mode
 *
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, getMode) {


	RETURN_MEMBER(this_ptr, "_mode");

}

/**
 * Sets the encryption key
 *
 * @param string key
 * @return Phalcon\Crypt
 */
PHP_METHOD(Phalcon_Crypt, setKey) {

	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(key_param) == IS_STRING) {
		key = key_param;
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_this(this_ptr, SL("_key"), key TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the encryption key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, getKey) {


	RETURN_MEMBER(this_ptr, "_key");

}

/**
 * Encrypts a text
 *
 *<code>
 *	$encrypted = $crypt->encrypt("Ultra-secret text", "encrypt password");
 *</code>
 *
 * @param string text
 * @param string key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, encrypt) {

	zval *text_param = NULL, *key = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key);

	if (Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(text_param) == IS_STRING) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
		key = ZEPHIR_GLOBAL(global_null);



}

/**
 * Decrypts an encrypted text
 *
 *<code>
 *	echo $crypt->decrypt($encrypted, "decrypt password");
 *</code>
 *
 * @param string text
 * @param string key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, decrypt) {

	zval *text_param = NULL, *key = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key);

	if (Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(text_param) == IS_STRING) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
		key = ZEPHIR_GLOBAL(global_null);



}

/**
 * Encrypts a text returning the result as a base64 string
 *
 * @param string text
 * @param string key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, encryptBase64) {

	zval *text_param = NULL, *key = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key);

	if (Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(text_param) == IS_STRING) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
		key = ZEPHIR_GLOBAL(global_null);



}

/**
 * Decrypt a text that is coded as a base64 string
 *
 * @param string text
 * @param string key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, decryptBase64) {

	zval *text_param = NULL, *key = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key);

	if (Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(text_param) == IS_STRING) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
		key = ZEPHIR_GLOBAL(global_null);



}

/**
 * Returns a list of available cyphers
 *
 * @return array
 */
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers) {

	ZEPHIR_MM_GROW();

	zephir_call_func(return_value, "mcrypt_list_algorithms");
	RETURN_MM();

}

/**
 * Returns a list of available modes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Crypt, getAvailableModes) {

	ZEPHIR_MM_GROW();

	zephir_call_func(return_value, "mcrypt_list_modes");
	RETURN_MM();

}

