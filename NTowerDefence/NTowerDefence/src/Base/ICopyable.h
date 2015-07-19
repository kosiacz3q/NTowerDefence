#pragma once

#include <memory>

template <class T>
class ICopyable
{
public:

	virtual T* getCopy() = 0;

};