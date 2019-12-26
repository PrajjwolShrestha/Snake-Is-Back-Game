#include "Tail_node.h" //include header file
#include "Utils.h"
const double Snake::Tail_node::MAX_DIST = 4;

void Snake::Tail_node::addTo(GameObject* parent) {
	GameObject::load("snake_body", parent->x, parent->y);
	parent->addChild(this);
	x = parent->x;
	y = parent->y;
}

void Snake::Tail_node::addPath(PathPoint* path_point) {
	if (path.empty()) {
		if (distanceTo(path_point->x, path_point->y) > Tail_node::MAX_DIST) {
			path.push(path_point);
		}
	}
}

bool Snake::Tail_node::collidesWith(GameObject* other, int node_number) {
	if (!in_motion) {
		return false;
	}
	if (node_number > 10 && distanceTo(other) < 16) {
		return true;
	}
	if (next_node != nullptr) {
		return next_node->collidesWith(other, node_number + 1);
	}
	return false;
}

//update our tail_node
void Snake::Tail_node::update() {
	GameObject::update();
	if (next_node != nullptr) {
		next_node->speed_delta = speed_delta;
		if (!next_node->path.empty()) {
			PathPoint* last_path = next_node->path.back();
			if (distanceTo(last_path->x, last_path->y) > Tail_node::MAX_DIST) {
				next_node->addPath(new PathPoint(x, y));
			}
		}
		else {
			if (distanceTo(next_node->x, next_node->y) > Tail_node::MAX_DIST) {
				next_node->addPath(new PathPoint(x, y));
			}
		}
	}
	if (path.empty()) {
		return;
	}
	PathPoint* target = path.front();
	double distance = moveTowards(target);
	if (distance > MAX_DIST) {
		distance = moveTowards(target);
	}
	if (distance < MAX_DIST) {
		path.pop();
		if (next_node != nullptr) {
			next_node->addPath(target);
		}
		else {
			delete target;
		}
	}
}


double Snake::Tail_node::moveTowards(PathPoint* target) {
	if (speed_delta > MAX_DIST) {
		speed_delta = MAX_DIST;
	}
	if (distanceTo(target->x, target->y) > speed_delta) {
		if (x < target->x) {
			x += speed_delta;
		}
		if (x > target->x) {
			x -= speed_delta;
		}
		if (y < target->y) {
			y += speed_delta;
		}
		if (y > target->y) {
			y -= speed_delta;
		}
	}
	in_motion = true;
	return distanceTo(target->x, target->y);
}
