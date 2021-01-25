#include <iostream>
using namespace std;

struct GeoObject {
	enum { CIR = 0, REC, TRG} gCode;
	union {
		struct Cir { double x, y, r; } c;
		struct Rec { double x, y, w, h; } r;
		struct Trg { double x, y, b, h; } t;
	};
};

typedef void(*DrawFunc) (struct GeoObject);

void drewCir(struct GeoObject go){
	cout << "Circle: (" << go.c.x << " " << go.c.y << " " << go.c.r << " )\n";
}


void drewRec(struct GeoObject go){
	cout << "Recangle: (" << go.r.x << " " << go.r.y << " " << go.r.w << " " << go.r.h<< " )\n";
}


void drewTrg(struct GeoObject go){
	cout << "Triangle: (" << go.t.x << " " << go.t.y << " " << go.t.b << " " << go.t.h << " )\n";
}

DrawFunc DrawArr[] = {
	drawCir, drawRec, drawTrg
};

int main(){
	struct GeoObject go;

	go.gCode = CIR;
	go.c.x = 2.3; go.c.y = 3.6;
	go.c.r = 1.2;
	DrawArr[go.gCode](go);

	go.gCode = REC;
	go.r.x = 3.1; go.t.y = 1.9;
	go.r.w = 4.2; go.r.h = 3.8;
	DrawArr[go.gCode](go);

	go.gCode = TRG;
	go.t.x = 3.1; go.t.y = 2.8;
	go.t.b = 4.4; go.t.h = 2.7;
	DrawArr[go.gCode](go);

	return 0;
}