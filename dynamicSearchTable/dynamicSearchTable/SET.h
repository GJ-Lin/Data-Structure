#pragma once
#include <iostream>
using namespace std;
template<class KEY, class OTHER>
class SET
{
	friend bool operator<=(const SET<KEY, OTHER>& lf, const SET<KEY, OTHER>& rh) { return lf.key <= rh.key; }
	friend bool operator>=(const SET<KEY, OTHER>& lf, const SET<KEY, OTHER>& rh) { return lf.key >= rh.key; }
public:
	SET() {};
	SET(const KEY& _key_, const OTHER& _other_) : key(_key_), other(_other_) {}
	KEY key;
	OTHER other;
};