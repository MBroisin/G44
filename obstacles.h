#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <ch.h>

typedef struct
{
	//ToF
	float front; //in m
	
	//IRs
	//Only tell if there is something
	bool frontLeft1;
	bool frontLeft2;
	bool frontRight1;
	bool frontRight2;
	bool left;
	bool right;
	bool rearLeft;
	bool rearRight;

} obstacle_t;

const obstacle_t* get_obstacles(void);

void wait_first_obstacle(void);
void wait_obstacle_ready(void);
void obstacle_init(void);

#endif //OBSTACLE_H
