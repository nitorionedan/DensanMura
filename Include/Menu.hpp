#ifndef DEF_MENU_HPP
#define DEF_MENU_HPP


#include "BaseScene.hpp"


class Menu : public BaseScene
{
public:
	Menu(ISceneChanger* changer);
	~Menu();

private:
	void Initialize();
	void Finalize();
	void Update() override;
	void Draw() override;
};


#endif

// EOF
