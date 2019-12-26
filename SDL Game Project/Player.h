#pragma once
#include "GameObject.h"
#include "Tail_node.h"
#include "Direction.h"

namespace Snake{
class Player  : public GameObject
{
public:
	 void load(int x, int y);
      void update();
      void growTail();
      void setDirection(Direction new_direction);
      bool directionPerpendicularTo(Direction new_direction);
      Direction direction = down;
    private:
      int speed = 128;
      Tail_node* last_node = nullptr;
      Tail_node* next_node = nullptr;
  };
}
