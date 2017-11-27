#include "stdafx.h"
#include "KValue.h"

KValue::KValue()
	:m_type(nullValue),m_size(0)
{

}
KValue::KValue(int value)
	:m_type(intValue),m_size(sizeof(value))
{
	m_value.value_.iValue = value;
}

KValue::KValue(unsigned int value)
	: m_type(uintValue),m_size(sizeof(value))
{
	m_value.value_.uiValue = value;
}

KValue::KValue(double value)
	: m_type(realValue),m_size(sizeof(value))
{
	m_value.value_.dValue = value;
}

KValue::KValue(bool value)
	: m_type(booleanValue),m_size(sizeof(value))
{
	m_value.value_.bValue = value;
}

KValue::KValue(std::string value)
	: m_type(stringValue),m_size(value.size())
{
	int size = value.size();
	m_value.value_.szValue = new char[size+1];
	std::memcpy(m_value.value_.szValue, value.c_str(), size);
	m_value.value_.szValue[size] = 0;
}

KValue::KValue(const KValue& value)
{
	this->m_type = value.m_type;
	this->m_size = value.m_size;
	switch (value.m_type)
	{
	case intValue:
		this->m_value.value_.iValue = value.m_value.value_.iValue;
		break;
	case uintValue:
		this->m_value.value_.uiValue = value.m_value.value_.uiValue;
		break;
	case realValue:
		this->m_value.value_.dValue = value.m_value.value_.dValue;
		break;
	case booleanValue:
		this->m_value.value_.bValue = value.m_value.value_.bValue;
		break;
	case stringValue:
	{
		if (this->m_value.value_.szValue != nullptr)
		{
			delete[]this->m_value.value_.szValue;
		}
		if (value.m_value.value_.szValue != nullptr)
		{
			this->m_value.value_.szValue = new char[value.m_size + 1];
			std::memcpy(this->m_value.value_.szValue, value.m_value.value_.szValue, value.m_size);
			this->m_value.value_.szValue[value.m_size] = 0;
		}
	}
	break;
	default:
		break;
	}
}

KValue::~KValue()
{
	switch (m_type)
	{
		case intValue:
		case uintValue:
		case realValue:
		case booleanValue:
			break;
		case stringValue:
		{
			if (m_value.value_.szValue != nullptr)
			{
				delete[]m_value.value_.szValue;
			}
		}
		break;
	}
}

KValue& KValue::operator = (const KValue& value)
{
	this->m_type = value.m_type;
	this->m_size = value.m_size;
	switch (value.m_type)
	{
	case intValue:
		this->m_value.value_.iValue = value.m_value.value_.iValue;
		break;
	case uintValue:
		this->m_value.value_.uiValue = value.m_value.value_.uiValue;
		break;
	case realValue:
		this->m_value.value_.dValue = value.m_value.value_.dValue;
		break;
	case booleanValue:
		this->m_value.value_.bValue = value.m_value.value_.bValue;
		break;
	case stringValue:
	{
		if (this->m_value.value_.szValue != nullptr)
		{
			delete[]this->m_value.value_.szValue;
		}
		if (value.m_value.value_.szValue != nullptr)
		{
			this->m_value.value_.szValue = new char[value.m_size + 1];
			std::memcpy(this->m_value.value_.szValue, value.m_value.value_.szValue, value.m_size);
			this->m_value.value_.szValue[value.m_size] = 0;
		}
	}
	break;
	default:
		break;
	}

	return *this;
}

bool KValue::operator == (const KValue& value)
{
	if (this->m_type == value.m_type)
	{
		switch (value.m_type)
		{
		case intValue:
			return (this->m_value.value_.iValue == value.m_value.value_.iValue);
			break;
		case uintValue:
			return (this->m_value.value_.uiValue == value.m_value.value_.uiValue);
			break;
		case realValue:
			return (this->m_value.value_.dValue == value.m_value.value_.dValue);
			break;
		case booleanValue:
			return (this->m_value.value_.bValue == value.m_value.value_.bValue);
			break;
		case stringValue:
			return (std::memcmp(this->m_value.value_.szValue, value.m_value.value_.szValue,value.Size())==0);
		}
	}
}

bool KValue::operator == (const KValue& value) const
{
	if (this->m_type == value.m_type)
	{
		switch (value.m_type)
		{
		case intValue:
			return (this->m_value.value_.iValue == value.m_value.value_.iValue);
			break;
		case uintValue:
			return (this->m_value.value_.uiValue == value.m_value.value_.uiValue);
			break;
		case realValue:
			return (this->m_value.value_.dValue == value.m_value.value_.dValue);
			break;
		case booleanValue:
			return (this->m_value.value_.bValue == value.m_value.value_.bValue);
			break;
		case stringValue:
			return (std::memcmp(this->m_value.value_.szValue, value.m_value.value_.szValue, value.Size()) == 0);
			break;
		default:
			break;
		}
	}
}

size_t KValue::Size() const
{
	return this->m_size;
}