#include "DrawnObject.hpp"
#include "Game.hpp"

template <typename T> DrawnObject<T>::DrawnObject(T* obj,int which) {
	this->dObject = obj;
	if(which==0)sendDrawOnce();
	else sendDrawObject();
}

template <typename T> void DrawnObject<T>::sendDrawObject() {
	Game::getDrawVector()._add(dObject);
}
template <typename T> void DrawnObject<T>::deleteDrawObject() {
	Game::getDrawVector()._delete(dObject);
}

template <typename T> void DrawnObject<T>::sendDrawOnce() {
	Game::getDrawOnce()._add(dObject);
}
template <typename T> void DrawnObject<T>::deleteDrawOnce() {
	Game::getDrawOnce()._delete(dObject);
}

template <typename T> DrawnObject<T>::~DrawnObject() {
	deleteDrawObject();
	delete dObject;
}

template class DrawnObject<GE::Circle>;
template class DrawnObject<GE::Rect>;
template class DrawnObject<GE::Shape>;

