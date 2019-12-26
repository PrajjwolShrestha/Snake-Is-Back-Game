#pragma once
#include "GameObject.h"
#include <queue>
#include "Path_Point.h"

namespace Snake {
	class Tail_node : public GameObject{
	public:
		static const double MAX_DIST;
		Tail_node() {};
		~Tail_node() {};
		void addTo(GameObject* parent);
		void addPath(PathPoint* path_point);
		bool collidesWith(GameObject* other, int node_number);
		double moveTowards(PathPoint* target);
		void update();
		Tail_node* next_node = nullptr;
		std::queue<PathPoint*> path;
		double speed_delta = 0;
		bool in_motion = false;
	};
}

