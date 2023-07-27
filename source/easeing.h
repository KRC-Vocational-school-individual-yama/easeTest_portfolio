#pragma once
#include<DxLib.h>
#include<cmath>
class EASEING {
public:
	float EInOutSine(int x);
	float EInOutQuad(int x);
	float EInOutCubic(int x);
	float EInOutQuart(int x);
	float EInOutQuint(int x);
	float EInOutExpo(int x);
	float EInOutCirc(int x);
	float EInOutBack(int x);
	float EInOutElastic(int x);
	float EInOutBounce(int x);

private:
	float easeInOutSine(float x)	;
	float easeInOutQuad(float x)	;
	float easeInOutCubic(float x)	;
	float easeInOutQuart(float x)	;
	float easeInOutQuint(float x)	;
	float easeInOutExpo(float x)	;
	float easeInOutCirc(float x)	;
	float easeInOutBack(float x)	;
	float easeInOutElastic(float x)	;
	float easeOutBounce(float x)	;
	float easeInOutBounce(float x)	;
};