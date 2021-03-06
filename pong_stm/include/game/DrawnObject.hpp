#pragma once

//Jako typename można użyć: GE::CircleShape, GE::ConvexShape, GE::RectangleShape, GE::Shape, GE::Sprite, GE::Text, GE::VertexArray, GE::VertexBuffer
template <typename T> class DrawnObject { 
protected:
	T* dObject;
public:
	DrawnObject(T* obj,int which);
	void sendDrawObject();
	void deleteDrawObject();
	void sendDrawOnce();
	void deleteDrawOnce();
	virtual ~DrawnObject();
};