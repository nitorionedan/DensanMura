#ifndef DEF_CHARA_TASK_HPP
#define DEF_CHARA_TASK_HPP


class CharaTask
{
public:
	virtual ~CharaTask() {}
	virtual void Initialize() = 0;	//�����������͕K������
	virtual void Finalize() = 0;   	//�I�������͕K������
	virtual void Update() = 0;		//�X�V�����͕K���p����Ŏ�������
	virtual void Draw() = 0;		//�`�揈���͕K���p����Ŏ�������

private:

};


#endif

// EOF