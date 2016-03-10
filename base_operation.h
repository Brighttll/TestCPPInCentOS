#pragma once
template<typename T>
struct less
{
    bool operator()(const T &t1, const T &t2)
    {
    	return t1 < t2;
    }
};

template<typename T>
struct bigger
{
    bool operator()(const T &t1, const T &t2)
    {
	return t1 > t2;
    }
};
