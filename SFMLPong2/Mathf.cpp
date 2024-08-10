#include "Mathf.h"

bool Mathf::intersect(const vec2& pos1, const vec2& size1, const vec2& pos2, const vec2& size2) {
	//Shape 1
	float left1 = pos1.getX();
	float right1 = pos1.getX() + size1.getX();
	float top1 = pos1.getY();
	float bottom1 = pos1.getY() + size1.getY();

	//Shape 2
	float left2 = pos2.getX();
	float right2 = pos2.getX() + size2.getX();
	float top2 = pos2.getY();
	float bottom2 = pos2.getY() + size2.getY();

	//checks if any of the sides overlap, if so it returns true, if not it returns falls
	return !(right1 <= left2 || right2 <= left1 || bottom1 <= top2 || bottom2 <= top1);
}
