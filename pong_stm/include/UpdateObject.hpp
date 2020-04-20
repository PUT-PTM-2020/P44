#pragma once

class UpdateObject {
protected:
	float elapsedTime;
	void getElapsedTime();
public:
	UpdateObject();
	virtual void update() = 0;
	virtual void sendUpdateObject();
	virtual void deleteUpdateObject();
	virtual ~UpdateObject();
};

