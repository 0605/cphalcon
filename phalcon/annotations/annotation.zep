
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

namespace Phalcon\Annotations;

/**
* Phalcon\Annotations\Annotation
*
* Represents a single annotation in an annotations collection
*/
class Annotation
{

	/**
	 * Annotation Name
	 * @var string
	 */
	protected _name;

	/**
	 * Annotation Arguments
	 * @var string
	 */
	protected _arguments;

	/**
	 * Annotation ExprArguments
	 * @var string
	 */
	protected _exprArguments;

	/**
	 * Phalcon\Annotations\Annotation constructor
	 *
	 * @param array reflectionData
	 */
 	public function __construct(reflectionData)
	{
  		var name, exprArguments, argument, resolvedArgument, arguments;

		if typeof reflectionData != "array" {
			throw new \Phalcon\Annotations\Exception("Reflection data must be an array");
		}

		let this->_name = reflectionData["name"];

		/**
		 * Process annotation arguments
		 */
		if fetch exprArguments, reflectionData["arguments"] {
			for argument in exprArguments {
				let resolvedArgument =  this->getExpression(argument["expr"]);
				if fetch name, argument["name"] {
					let arguments = name[resolvedArgument];
	   			} else {
					let arguments = resolvedArgument;
				}
			}
			let this->_arguments = arguments;
			let this->_exprArguments = exprArguments;
		}
 	}

	/**
	 * Returns the annotation's name
	 *
	 * @return string
	 */
	public function getName() -> string
	{
		return this->_name;
	}

	/**
	 * Resolves an annotation expression
	 *
	 * @param array expr
	 * @return mixed
	 */
	public function getExpression(expr)
	{
		var value, item, resolvedItem, arrayValue, name, type;

		if typeof expr != "array" {
			throw new \Phalcon\Annotations\Exception("The expression is not valid");
		}

		let type = expr["type"];
		switch type {
			case 301:
			case 302:
			case 303:
			case 307:
				let value = expr["value"];
				break;
			case 304:
				let value = null;
				break;
			case 305:
				let value = false;
				break;

			case 306:
				let value = true;
				break;

			case 308:
				let arrayValue = null;
				for item in expr["items"] {
					let resolvedItem = this->getExpression(item["expr"]);
					if fetch name, item["name"] {
						let arrayValue = name[resolvedItem];
					} else {
						let arrayValue[] = resolvedItem;
					}
				}
				return arrayValue;

			case 300:
				return new \Phalcon\Annotations\Annotation(expr);

   			default:
				throw new \Phalcon\Annotations\Exception("The expression ". type. " is unknown");
		}

		return value;
	}

 	/**
	 * Returns the expression arguments without resolving
	 *
	 * @return array
	 */
	public function getExprArguments()
	{
		return this->_exprArguments;
	}

	/**
	 * Returns the expression arguments
	 *
	 * @return array
	 */
	public function getArguments()
	{
		return this->_arguments;
	}

	/**
	 * Returns the number of arguments that the annotation has
	 *
	 * @return int
	 */
	public function numberArguments() -> int
	{
		return count(this->_arguments);
	}

	/**
	 * Returns an argument in a specific position
	 *
	 * @param int position
	 * @return mixed
	 */
	public function getArgument(int position)
	{
		var argument;
		if fetch argument, this->_arguments[position] {
			return argument;
		}
	}

	/**
	 * Returns an argument in a specific position
	 *
	 * @param int position
	 * @return boolean
	 */
	public function hasArgument(int position) -> boolean
	{
		return isset this->_arguments[position];
	}

	/**
	 * Returns a named argument
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getNamedArgument(string! name)
	{
		var argument;
		if fetch argument, this->_arguments[name] {
 			return argument;
		}
	}

	/**
	 * Returns a named parameter
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getNamedParameter(string! name)
	{
		return this->getNamedArgument(name);
	}
}
