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
			obst.fill(field);
			microlife::fauna::population population;
			population.populate(field);
			while (rend.is_open())
			{
				population.update(field);
				field.update(rend);
				rend.draw();
				population.cycle(field);
				std::this_thread::sleep_for(3s);	// temp
			}
		}
	)};
	if (fut.valid())
	{
		fut.wait();
	}
    return 0;
}