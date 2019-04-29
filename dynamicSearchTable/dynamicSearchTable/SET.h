#pragma once
#include <iostream>
using namespace std;
template<class KEY, class OTHER>
class SET
{
	friend bool operator<=(const SET<KEY, OTHER>& lf, const SET<KEY, OTHER>& rh) { return lf.key <= rh.key; }
	friend bool operator>=(const SET<KEY, OTHER>& lf, const SET<KEY, OTHER>& rh) { return lf.key >= rh.key; }
public:
	SET();
	KEY key;
	OTHER other;
	SET<KEY, OTHER>& operator=(const SET<KEY, OTHER>& rh);
};