#pragma once
#include <vector>
#include <functional>
template <typename T> class ObjectsVector {
private:
	std::vector<T> vec;
	bool forEachReset;
public:
	ObjectsVector();
	void _add(T object);
	void _delete(T object);
	void clear();
	void forEach(std::function<void(T &object)> _function);
	std::vector<T>& get();
	~ObjectsVector();
};

