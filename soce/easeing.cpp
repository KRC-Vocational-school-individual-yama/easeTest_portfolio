#include "easeing.h"

float EASEING::easeInOutSine(float x){
	return -(cos(DX_PI * x) - 1) / 2;
}
float EASEING::easeInOutQuad(float x){
	return x < 0.5 ? 2 * x * x : 1 - pow(-2 * x + 2, 2) / 2;
}
float EASEING::easeInOutCubic(float x){
	return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}
float EASEING::easeInOutQuart(float x){
	return x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
}
float EASEING::easeInOutQuint(float x){
	return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
}
float EASEING::easeInOutExpo(float x){
	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5 ? pow(2, 20 * x - 10) / 2
		: (2 - pow(2, -20 * x + 10)) / 2;
}
float EASEING::easeInOutCirc(float x){
	return x < 0.5
		? (1 - sqrt(1 - pow(2 * x, 2))) / 2
		: (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
}
float EASEING::easeInOutBack(float x){
	float c1 = 1.70158;
	float c2 = c1 * 1.525;

	return x < 0.5
		? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		: (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;

}
float EASEING::easeInOutElastic(float x){
	float c5 = (2 * DX_PI) / 4.5;

	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5
		? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * c5)) / 2
		: (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * c5)) / 2 + 1;
}
float EASEING::easeOutBounce(float x){
	float n1 = 7.5625;
	float d1 = 2.75;

	if (x < 1 / d1) {
		return n1 * x * x;
	}
	else if (x < 2 / d1) {
		return n1 * (x -= 1.5 / d1) * x + 0.75;
	}
	else if (x < 2.5 / d1) {
		return n1 * (x -= 2.25 / d1) * x + 0.9375;
	}
	else {
		return n1 * (x -= 2.625 / d1) * x + 0.984375;
	}
}
float EASEING::easeInOutBounce(float x){
	return x < 0.5
		? (1 - easeOutBounce(1 - 2 * x)) / 2
		: (1 + easeOutBounce(2 * x - 1)) / 2;
}

float EASEING::EInOutSine(int x){
	return 100*easeInOutSine((float)x/100.0f);
}
float EASEING::EInOutQuad(int x){
	return 100 * easeInOutQuad((float)x / 100.0f);
}
float EASEING::EInOutCubic(int x){
	return 100 * easeInOutCubic((float)x / 100.0f);
}
float EASEING::EInOutQuart(int x){
	return 100 * easeInOutQuart((float)x / 100.0f);
}
float EASEING::EInOutQuint(int x){
	return 100 * easeInOutQuint((float)x / 100.0f);
}
float EASEING::EInOutExpo(int x){
	return 100 * easeInOutExpo((float)x / 100.0f);
}
float EASEING::EInOutCirc(int x){
	return 100 * easeInOutCirc((float)x / 100.0f);
}
float EASEING::EInOutBack(int x){
	return 100 * easeInOutBack((float)x / 100.0f);
}
float EASEING::EInOutElastic(int x){
	return 100 * easeInOutElastic((float)x / 100.0f);
}
float EASEING::EInOutBounce(int x){
	return 100 * easeInOutBounce((float)x / 100.0f);
}
