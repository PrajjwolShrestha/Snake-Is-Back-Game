#include "Player.h"
#include "Path_Point.h"
#include "Utils.h"

//void function to load up the snake head
void Snake::Player::load(int x, int y) {
	GameObject::load("snake_head", x, y);
}


//update our player based on delta time
void Snake::Player::update() {
	GameObject::update();
	double speed_delta = speed * time_delta;
	next_node->speed_delta = speed_delta;
	switch (direction) {
	case left:
		x -= speed_delta;
		break;
	case right:
		x += speed_delta;
		break;
	case up:
		y -= speed_delta;
		break;
	case down:
		y += speed_delta;
		break;
	}

	if (next_node->collidesWith(this, 0)) {
		// TODO: implement game over
		speed = 0;
	}

	if (!next_node->path.empty()) {
		PathPoint* last_path = next_node->path.back();
		if (distanceTo(last_path->x, last_path->y) > speed_delta) {
			next_node->addPath(new PathPoint(x, y));
		}
	}
	else {
		if (distanceTo(next_node->x, next_node->y) > speed_delta) {
			next_node->addPath(new PathPoint(x, y));
		}
	}
}

//check if the direction is perpendicular
bool Snake::Player::directionPerpendicularTo(Direction new_direction) {
	switch (direction) {
	case left:
	case right:
		switch (new_direction) {
		case up:
		case down:
			return true;
		default:
			break;
		}
		break;
	case up:
	case down:
		switch (new_direction) {
		case left:
		case right:
			return true;
		default:
			break;
		}
	default:
		break;
	}
	return false;
}

// function to set the direction of our snake
void Snake::Player::setDirection(Direction new_direction) {
	if (directionPerpendicularTo(new_direction)) {
		direction = new_direction;
		next_node->addPath(new PathPoint(x, y));
	}
}

//add tail node or grow the tail of our snake
void Snake::Player::growTail() {
	Tail_node* node = new Tail_node();
	if (next_node == nullptr) {
		node->addTo(this);
		next_node = node;
	}
	else {
		node->addTo(last_node);
		last_node->next_node = node;
	}
	last_node = node;
}
