#ifndef DEF_GAME_HPP
#define DEF_GAME_HPP

#include "BaseScene.hpp"
#include "ISceneChanger.hpp"

#include "Game.hpp"
#include "Player.hpp"
#include "Stage.hpp"
#include "BEnemy.hpp"
#include "Image.hpp"
#include "Camera.hpp"
#include "Sound.hpp"
#include <memory>


//�Q�[����ʃN���X
class Game : public BaseScene
{
public:
	Game::Game(ISceneChanger* changer);
	~Game();
	void Update() override;     //�X�V�������I�[�o�[���C�h
	void Draw() override;       //�`�揈�����I�[�o�[���C�h

private:
	void Initialize();
	void Finalize();

	std::shared_ptr<Player> player;
	std::shared_ptr<BEnemy> prcn;
	std::shared_ptr<Stage> stage;
	std::shared_ptr<Camera> mainCamera;
	std::shared_ptr<Sound> sound;
	bool isPause;
};


#endif

// EOF