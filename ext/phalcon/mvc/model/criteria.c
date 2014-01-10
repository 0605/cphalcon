
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


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
 * Phalcon\Mvc\Model\Criteria
 *
 * This class allows to build the array parameter required by Phalcon\Mvc\Model::find
 * and Phalcon\Mvc\Model::findFirst using an object-oriented interface
 *
 *<code>
 *$robots = Robots::query()
 *    ->where("type = :type:")
 *    ->andWhere("year < 2000")
 *    ->bind(array("type" => "mechanical"))
 *    ->order("name")
 *    ->execute();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Criteria) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Criteria, phalcon, mvc_model_criteria, phalcon_mvc_model_criteria_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_bindParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_bindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_criteria_ce, SL("_hiddenParamNumber"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	//missing

}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI) {

	zval *dependencyInjector, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
	if (zephir_array_isset_string_fetch(&dependencyInjector, _0, SS("di"), 1 TSRMLS_CC)) {
		RETURN_CTORW(dependencyInjector);
	}
	RETURN_BOOL(0);

}

/**
 * Set a model on which the query will be executed
 *
 * @param string modelName
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName) {

	zval *modelName_param = NULL;
	zval *modelName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

		if (Z_TYPE_P(modelName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		modelName = modelName_param;



	zephir_update_property_this(this_ptr, SL("_model"), modelName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns an internal model name on which the criteria will be applied
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName) {


	RETURN_MEMBER(this_ptr, "_model");

}

