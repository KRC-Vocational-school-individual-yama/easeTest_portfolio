#include"object.h"
#include<DxLib.h>
#include<cmath>
#include"config.h"
#include"easeing.h"
namespace {
	int count;

	VECTOR pos;
	static const int CIRCLENUM = 100;
	float posy[CIRCLENUM] = {};
	
	enum PATERN {
		no=-1,
		one=0,
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,

	};
	PATERN type;
	int typenum;
	bool enterkey= false;
	EASEING* ease;
}

void Init() {
	ease = new EASEING();
	count = 0.0f;
	type = PATERN::no;
	typenum = (int)PATERN::no;
	pos = { 50.0f,400.0f,5 };
	enterkey = false;
	for (int i = 0; i < CIRCLENUM; i++) {
		posy[i] = 500;
	}
}
void Update() {
	count++;


	bool nowkey = CheckHitKey(KEY_INPUT_RETURN);
	if (nowkey && !enterkey) {
		count = 0;
		typenum++;
		type = (PATERN)typenum;
		if (typenum > ten)typenum = -1;
	}
	enterkey = nowkey;


	for (int i = 0; i < CIRCLENUM; i++) {
		if (count == i) {
			switch (type)
			{
			case PATERN::one:	posy[i] = -4 * ease->EInOutSine(i);
				break;
			case PATERN::two:	posy[i] = -4 * ease->EInOutQuad(i);
				break;
			case PATERN::three:	posy[i] = -4 * ease->EInOutCubic(i);
				break;
			case PATERN::four:	posy[i] = -4 * ease->EInOutQuart(i);
				break;
			case PATERN::five:	posy[i] = -4 * ease->EInOutQuint(i);
				break;
			case PATERN::six:	posy[i] = -4 * ease->EInOutExpo(i);
				break;
			case PATERN::seven:	posy[i] = -4 * ease->EInOutCirc(i);
				break;
			case PATERN::eight:	posy[i] = -4 * ease->EInOutBack(i);
				break;
			case PATERN::nine:	posy[i] = -4 * ease->EInOutElastic(i);
				break;
			case PATERN::ten:	posy[i] = -4 * ease->EInOutBounce(i);
				break;
			default:			posy[i] = -4 * (float)i ;
				break;
			}
			posy[i] += 500;

		}
	}

	if (count == CIRCLENUM) {
		count = 0;
		typenum++;
		type = (PATERN)typenum;
		if (typenum > ten)typenum = -1;
	}

}
void Draw() {
	printfDx("type= %d\n", typenum);

	float nums = 0.0f;
	switch (type)
	{
	case PATERN::one:	nums = -4 * ease->EInOutSine(count);
		break;
	case PATERN::two:	nums = -4 * ease->EInOutQuad(count);
		break;
	case PATERN::three:	nums = -4 * ease->EInOutCubic(count);
		break;
	case PATERN::four:	nums = -4 * ease->EInOutQuart(count);
		break;
	case PATERN::five:	nums = -4 * ease->EInOutQuint(count);
		break;
	case PATERN::six:	nums = -4 * ease->EInOutExpo(count);
		break;
	case PATERN::seven:	nums = -4 * ease->EInOutCirc(count);
		break;
	case PATERN::eight:	nums = -4 * ease->EInOutBack(count);
		break;
	case PATERN::nine:	nums = -4 * ease->EInOutElastic(count);
		break;
	case PATERN::ten:	nums = -4 * ease->EInOutBounce(count);
		break;
	default:			nums = -4 * (float)count;
		break;
	}
	{//îwåiêF
		int x=400, 
			y=300;
		int size = 25*(-nums/100)+50;
	DrawBox(x-size,y-size,x+size,y+size,GetColor(224,222,198),true);

	}
	for (int i = 0; i < CIRCLENUM; i++) {

		DrawCircleAA(pos.x+i*pos.z,posy[i],pos.z,20,GetColor(255,255,255));
	}

	printfDx("num=  %f\n", nums);
}
void Delete() {
	delete ease;
}