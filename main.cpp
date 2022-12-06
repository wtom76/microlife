#include "pch.h"
#include "render.h"
#include "field.h"
#include "environment/obstacle_cont.h"
#include "fauna/population.h"

using namespace std::chrono_literals;

int main()
{
	std::future<void> fut{
		std::async(std::launch::async,
		[]()
		{
			microlife::render rend;
			microlife::field field;
			microlife::environment::obstacle_cont obst;
			obst.populate();
			obst.update(field);
			microlife::fauna::population population;
			population.populate(field);
			population.update(field);
			field.update(rend);
			while (rend.is_open())
			{
				rend.draw();
				std::this_thread::sleep_for(1s);	// temp
			}
		}
	)};
	if (fut.valid())
	{
		fut.wait();
	}
    return 0;
}