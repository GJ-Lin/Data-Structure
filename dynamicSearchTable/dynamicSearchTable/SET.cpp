#include "SET.h"

template <class KEY, class OTHER>
SET<KEY, OTHER>::SET()
{

}

template <class KEY, class OTHER>
SET<KEY, OTHER>& SET<KEY, OTHER>::operator=(const SET<KEY, OTHER>& rh)
{
	if (this == &rh) return *this;
	key = rh.key;
	other = rh.other;
	return *this;
}