#ifndef DEF_CHARA_TASK_HPP
#define DEF_CHARA_TASK_HPP


class CharaTask
{
public:
	virtual ~CharaTask() {}
	virtual void Initialize() = 0;	//初期化処理は必ず実装
	virtual void Finalize() = 0;   	//終了処理は必ず実装
	virtual void Update() = 0;		//更新処理は必ず継承先で実装する
	virtual void Draw() = 0;		//描画処理は必ず継承先で実装する

private:

};


#endif

// EOF