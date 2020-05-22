#pragma once
#include "ge.hpp"
#include <math.h>

#define PHYSICS_DEFAULT_VISCOSITY 1.225f
#define PHYSICS_DEFAULT_GRAV 9.81f
#define PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO 0.008f //Jeden piksel to 0,005 metra
#define PI 3.14159265359f
struct Physics {
	static float viscosity, grav, wind;
	static const float pixelToRealRatio;
	struct Material {
		float friction;
		float elasticity;
	};
	struct Materials {
		static const Material wood;
		static const Material ball;
		static const Material racket;
		static const Material net;
	};	
	static void resetValues();
	static GE::Vector2i floatVectorToIntVector(const GE::Vector2f &floatVector);
	static float calcDirectionFactor(float x1, float y1, float x2, float y2);
	static GE::Vector2f calcRealVector(const GE::Vector2i &pixelVector);
	static GE::Vector2f calcRealVector(const GE::Vector2f &pixelVector);
	static GE::Vector2f calcPixelVector(const GE::Vector2f &realVector);
	static float calcRealValue(const float &pixelValue);
	static int calcPixelValue(const float &realValue);
	static GE::Vector2i swapY(const GE::Vector2i &pos);
	static GE::Vector2i swapYR(const GE::Vector2i &pos);
	static float calcDistanceBetweenTwoPoints(const GE::Vector2i &vector1, const GE::Vector2i &vector2);
};