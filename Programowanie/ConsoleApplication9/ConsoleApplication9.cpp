#include <iostream>

class GameObject
{
protected:
	void interaction()
	{
	}
};

class SnakePart : public GameObject
{
public:
	SnakePart(int X, int Y)
	{
		this->X = X;
		this->Y = Y;
	}
	SnakePart()
	{
		this->X = 0;
		this->Y = 0;
	}
protected:
	int X;
	int Y;
	void interaction()
	{
		die();
	}
};
class Snake :public GameObject
{
private:
	SnakePart head(5, 5);
	SnakePart snakeParts[99];
	snakeParts[0] = head;
};
void die()
{

}
int main()
{


}