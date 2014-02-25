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

namespace Phalcon\Forms;

/**
 * Phalcon\Forms\Manager
 */
class Manager
{

	protected _forms;

	/**
	 * Creates a form registering it in the forms manager
	 *
	 * @param string name
	 * @param object entity
	 * @return Phalcon\Forms\Form
	 */
	public function create(name=null, entity=null) -> <\Phalcon\Forms\Form>
	{
		var form;

		if typeof name != "string" {
			throw new \Phalcon\Forms\Exception("The form name must be string");
		}

		let form = new \Phalcon\Forms\Form(entity),
			this->_forms[name] = form;
		return form;
	}

	/**
	 * Returns a form by its name
	 *
	 * @param string name
	 * @return Phalcon\Forms\Form
	 */
	public function get(string name) -> <\Phalcon\Forms\Form>
	{
		var form, forms;

		let forms = this->_forms;
		if !fetch form, forms[name] {
			throw new \Phalcon\Forms\Exception("There is no form with name='" . name . "'");
		}
		return form;
	}

	/**
	 * Checks if a form is registered in the forms manager
	 *
	 * @param string name
	 * @return boolean
	 */
	public function has(string name) -> boolean
	{
		var forms;
		let forms = this->_forms;
		return isset forms[name];
	}

	/**
	 * Registers a form in the Forms Manager
	 *
	 * @param string name
	 * @param Phalcon\Forms\Form form
	 * @return Phalcon\Forms\FormManager
	 */
	public function set(string name, <\Phalcon\Forms\Form> form) -> <\Phalcon\Forms\FormManager>
	{
		let this->_forms[name] = form;
		return this;
	}

}
