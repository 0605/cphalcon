
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
 * Phalcon\Text
 *
 * Provides utilities to work with texts
 */
ZEPHIR_INIT_CLASS(Phalcon_Text) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Text, phalcon, text, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALNUM"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALPHA"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_HEXDEC"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NUMERIC"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NOZERO"), 4 TSRMLS_CC);

	return SUCCESS;

}

