#include "pch.h"
#include "render.h"
#include "field.h"
#include "environment/obstacle_cont.h"

int main()
{
	microlife::render rend;
	microlife::field field;
	microlife::environment::obstacle_cont obst;
	obst.populate();
	obst.update(field);
	field.update(rend);
	rend.draw();
    return 0;
}