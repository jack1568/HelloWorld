#pragma once
#include <string>

class KValue
{
	enum ValueType
	{
		nullValue = 0, ///< 'null' value
		intValue,      ///< signed integer value
		uintValue,     ///< unsigned integer value
		realValue,     ///< double value
		stringValue,   ///< UTF-8 string value
		booleanValue,  ///< bool value
	};

	typedef struct _tagValueHolder
	{
		size_t size;
		union _tagValue
		{
			int iValue;
			unsigned int uiValue;
			double dValue;
			char* szValue;
			bool bValue;
		}value_;
	}ValueHolder;

public:
	KValue();
	KValue(int value);
	KValue(unsigned int value);
	KValue(double value);
	KValue(std::string value);
	KValue(bool value);
	KValue(const KValue& value);
	~KValue();

	KValue& operator = (const KValue& value);
	bool operator == (const KValue& value)const;
	bool operator == (const KValue& value);

	size_t Size() const;

private:
	void* operator new(size_t size);
	void* operator new[](size_t size);
	void operator delete(void* ptr);

	size_t m_size;
	ValueType m_type;
	ValueHolder m_value;

};

