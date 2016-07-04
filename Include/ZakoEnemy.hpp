#ifndef DEF_ZAKO_EMEMY_HPP
#define DEF_ZAKO_ENEMY_HPP


class ZakoEnemy
{
public:
	ZakoEnemy();
	~ZakoEnemy();
	void Update();
	void Draw();

private:
	void Move();
};


#endif