#ifndef __CALCULUS_ELEMENT_H__
#define __CALCULUS_ELEMENT_H__

#include <string>

namespace myCalculator
{
	template <typename ValueType>
	class CalculationException
	{
		public:
			std::string errorMessage;
			const bool IsValue;
			char relateOperation;
			ValueType relateValue;
		public:
			CalculationException(ValueType relateValue, const std::string& message) 
				: errorMessage(message), relateValue(relateValue), IsValue(true) {};
			CalculationException(char op, const std::string& message)  
				: errorMessage(message), relateOperation(op), IsValue(false) {};
	};

	template <typename ValueType>
	class CalculusElement 
	{
		private:
			ValueType mValue;
			char mOperation;
		public:
			const bool IsValue;
		public:
			int getPriorityOfOperation() throw (CalculationException<ValueType>);
			ValueType getResultOfBinomialOperation(const ValueType& pNum, const ValueType& Num) throw (CalculationException<ValueType>);
			ValueType getValue() throw (CalculationException<ValueType>)
			{
				if(IsValue)
					return mValue;
				else
					throw CalculationException<ValueType>(mOperation, "is not value. "); 
			}
			char getOperation() throw (CalculationException<ValueType>)
			{
				if(!IsValue)
					return mOperation;
				else
					throw CalculationException<ValueType>(mValue, "is not Operation. "); 
			}
			bool IsBlock();
			CalculusElement(ValueType);
			CalculusElement(char);
			CalculusElement(const CalculusElement& cp) : IsValue(cp.IsValue)
			{
				mValue = cp.mValue;
				mOperation = cp.mOperation;
			}

	};

	template<typename ValueType>
	CalculusElement<ValueType>::CalculusElement(ValueType pValue) : mValue(pValue), mOperation('\0'), IsValue(true) {}

	template<typename ValueType>
	CalculusElement<ValueType>::CalculusElement(char pOperation) : mOperation(pOperation), IsValue(false) {}

	template<typename ValueType>
	int CalculusElement<ValueType>::getPriorityOfOperation() throw(CalculationException<ValueType>) 
	{
		if(IsValue)
			throw CalculationException<ValueType>(mValue, "does not have priority of Operation. ");
		switch(mOperation)
		{
			case '(':
			case ')':
				return 1;
			case '*':
			case '/':
//			case '%':
				return 4;
			case '+':
			case '-':
				return 6;
			default:
				return 0;
		}
	}

	template<typename ValueType>
	ValueType CalculusElement<ValueType>::getResultOfBinomialOperation(const ValueType& Num, const ValueType& pNum) throw(CalculationException<ValueType>)
	{
		if(IsValue)
			throw CalculationException<ValueType>(mValue, "can not binomial calculate because it is Value. ");
		switch(mOperation)
		{
			case '(':
			case ')':
				throw CalculationException<ValueType>(mOperation, "is not binomial operation. ");
			case '*':
				return Num*pNum;
			case '/':
				return Num/pNum;
//			case '%':
//				return Num%pNum;
			case '+':
				return Num+pNum;
			case '-':
				return Num-pNum;
			default:
				throw CalculationException<ValueType>(mOperation, "is not in binomial operation list. ");
		}
	}

	template<typename ValueType>
	bool CalculusElement<ValueType>::IsBlock()
	{
		if(mOperation == '(' || mOperation == ')')
			return true;
		return false;
	}
}
#endif

