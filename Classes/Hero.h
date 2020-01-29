#pragma once
#include "cocos_framework.h"

class Monster;

enum INFO
{
	Waiting = 0,
	Walking,
	Attack,
};

enum Movement
{
	RightWay = 10,
	LeftWay,
};

enum HAMMERINFO
{
	HammerWaiting = 20,
	HammerWalking,
	HammerAttack,
	HammerSkillEffect1,
	HammerSkillEffect2,
	HammerSkillEffect3,
	HammerMissile,
};

enum HAMMERKIND
{
	고무망치 = 1582,
	회복망치,
	식량망치,
};

class Hero
{
private:
	static Hero* Instance;
	Hero();
	~Hero() {}

	SpriteFrameCache* cache;

	vector<Sprite*> HeroInventoryVec; // 히어로 인벤토리

	Animation* _animation1; // 히어로 대기 액션
	Animate* _animate1; // 히어로 대기 액션
	RepeatForever* _heroWaitingAction; // 히어로 대기 액션

	Animation* _animation2; // 히어로 걷기 액션
	Animate* _animate2;	// 히어로 걷기 액션
	RepeatForever* _heroWalkingAction; // 히어로 걷기 액션

	Animation* _animation3; // 히어로 공격 액션
	Animate* _animate3; // 히어로 공격 액션

	Animation* _animation4; // 고무망치 대기 액션
	Animate* _animate4; // 고무망치 대기 액션
	RepeatForever* _hammerWaitingAction1; // 고무망치 대기 액션

	Animation* _animation5; // 고무망치 걷기 액션
	Animate* _animate5; // 고무망치 걷기 액션
	RepeatForever* _hammerWalkingAction1; // 고무망치 걷기 액션

	Animation* _animation6; // 고무망치 공격 액션
	Animate* _animate6; // 고무망치 공격 액션

	Animation* _hammerSkillEffectAnimation_A1; // 고무망치 스킬 이펙트A
	Animate* _hammerSkillEffectAnimate_A1; // 고무망치 스킬 이펙트A

	Animation* _animation7; // 회복망치 대기 액션
	Animate* _animate7; // 회복망치 대기 액션
	RepeatForever* _hammerWaitingAction2; // 회복망치 대기 액션

	Animation* _animation8; // 회복망치 걷기 액션
	Animate* _animate8; // 회복망치 걷기 액션
	RepeatForever* _hammerWalkingAction2; // 회복망치 걷기 액션

	Animation* _animation9; // 회복망치 공격 액션
	Animate* _animate9; // 회복망치 공격 액션

	Animation* _hammerSkillEffectAnimation_A2; // 회복망치 스킬 이펙트A
	Animate* _hammerSkillEffectAnimate_A2; // 회복망치 스킬 이펙트A

	Animation* _hammerSkillEffectAnimation_B2; // 회복망치 스킬 이펙트B
	Animate* _hammerSkillEffectAnimate_B2; // 회복망치 스킬 이펙트B

	Animation* _hammerSkillEffectAnimation_C2; // 회복망치 스킬 이펙트C
	Animate* _hammerSkillEffectAnimate_C2; // 회복망치 스킬 이펙트C

	Animation* _animation10; // 식량망치 대기 액션
	Animate* _animate10; // 식량망치 대기 액션
	RepeatForever* _hammerWaitingAction3; // 식량망치 대기 액션

	Animation* _animation11; // 식량망치 걷기 액션
	Animate* _animate11; // 식량망치 걷기 액션
	RepeatForever* _hammerWalkingAction3; // 식량망치 걷기 액션

	Animation* _animation12; // 식량망치 공격 액션
	Animate* _animate12; // 식량망치 공격 액션

	Animation* _hammerSkillEffectAnimation_A3; // 식량망치 스킬 이펙트A
	Animate* _hammerSkillEffectAnimate_A3; // 식량망치 스킬 이펙트A

	Animation* _animation13; // 식량망치 대기 액션
	Animate* _animate13; // 식량망치 대기 액션
	RepeatForever* _heroBuffOraRepeat; // 식량망치 대기 액션

	Sprite* _hero; // 히어로 스프라이트
	Sprite* _heroWeapon1; // 고무망치
	Sprite* _skillEffectBox1; // 스킬A 이펙트를 보여줄 박스
	Sprite* _skillEffectBox2; // 스킬B 이펙트를 보여줄 박스
	Sprite* _skillEffectBox3; // 스킬C 이펙트를 보여줄 박스
	Sprite* _heroBuffOra;

	ProgressTimer* _manaGauge; // 마나 게이지
	ProgressTimer* _meatGauge; // 고기 게이지
	ProgressTimer* _hpInfoGauge; // 히어로 체력바(중앙상단)
	ProgressTimer* _MonsterBaseHpGauge; // 몬스터 베이스 체력바(중앙상단)
	ProgressTimer* _expGauge; // 몬스터 베이스 체력바(중앙상단)

	Movement _movement; // 현재 플레이어가 보고있는 방향
	HAMMERKIND _HammerKind;

	// 히어로 정보
	float _speed; // 스피드
	float _lv; // 레벨
	float _hp; // 체력
	float _maxhp; // 최대체력
	float _mana; // 현재 마나량
	float _maxmana; // 최대마나
	float _manaRegenSpeed; // 마나 리젠 스피드
	float _meat; // 현재 고기량
	float _maxmeat; // 최대 고기량
	float _meatRegenSpeed; // 고기 리젠 스피드
	float _gold; // 골드
	float _exp; // 경험치
	float _maxExp; // 최대경험치

	float _skillOneManaUse; // 스킬 1 마나 소비량
	float _skillTwoManaUse; // 스킬 2 마나 소비량
	float _skillThreeManaUse; // 스킬 3 마나 소비량

	bool IsHealing;

	bool _skillOneUnlock;
	bool _skillTwoUnlock;
	bool _skillThreeUnlock;

	bool _unitOneUnlock;
	bool _unitTwoUnlock;
	bool _unitThreeUnlock;

	bool _stageStart;


	// 유닛정보
	float _mouseHp; // 체력
	float _mouseMaxHP; // 최대체력
	float _mouseAtk; // 일반공격력
	float _mouseAtk2; // 강공격력
	float _mouseSpeed; // 스피드

	float _bearHp; // 체력
	float _bearMaxHP; // 최대체력
	float _bearAtk; // 일반공격력
	float _bearAtk2; // 강공격력
	float _bearSpeed; // 스피드

	float _kangarooHp; // 체력
	float _kangarooMaxHP; // 최대체력
	float _kangarooAtk; // 일반공격력
	float _kangarooAtk2; // 강공격력
	float _kangarooSpeed; // 스피드


public:
	static Hero* getInstance();
	static void releaseInstance();
	void createHeroInfo(Scene* scene, Layer* layer);

	vector<Sprite*> getHeroInventoryVec() { return HeroInventoryVec; } // 히어로 인벤토리 겟함수

	Movement getMoveWay() { return _movement; }
	void setMoveWay(Movement movement) { _movement = movement; }
	Sprite* getHero() { return _hero; }
	Sprite* getWeapon1() { return _heroWeapon1; }
	Sprite* getSkillEffectBox1() { return _skillEffectBox1; }
	Sprite* getSkillEffectBox2() { return _skillEffectBox2; }
	Sprite* getSkillEffectBox3() { return _skillEffectBox3; }
	Sprite* getHeroBuffOra() { return _heroBuffOra; }
	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }
	float getHp() { return _hp; }
	void setHp(float hp) { _hp = hp; }
	float getMaxHp() { return _maxhp; }
	void setMaxHp(float maxhp) { _maxhp = maxhp; }
	float getMana() { return _mana; }
	void setMana(float mana) { _mana = mana; }
	float getMaxMana() { return _maxmana; }
	void setMaxMana(float maxmana) { _maxmana = maxmana; }
	float getGold() { return _gold; }
	void setGold(float gold) { _gold = gold; }
	float getExp() { return _exp; }
	void setExp(float exp) { _exp = exp; }
	float getMaxExp() { return _maxExp; }
	void setMaxExp(float maxexp) { _maxExp = maxexp; }
	float getManaRegenSpeed() { return _manaRegenSpeed; }
	void setManaRegenSpeed(float manaregenspeed) { _manaRegenSpeed = manaregenspeed; }
	float getMeat() { return _meat; }
	void setMeat(float meat) { _meat = meat; }
	float getMaxMeat() { return _maxmeat; }
	void setMaxMeat(float maxmeat) { _maxmeat = maxmeat; }
	float getMeatRegenSpeed() { return _meatRegenSpeed; }
	void setMeatRegenSpeed(float meatregenspeed) { _meatRegenSpeed = meatregenspeed; }
	float getSkillOneManaUse() { return _skillOneManaUse; }
	void setSkillOneManaUse(float skillonemanause) { _skillOneManaUse = skillonemanause; }
	float getSkillTwoManaUse() { return _skillTwoManaUse; }
	void setSkillTwoManaUse(float skilltwomanause) { _skillTwoManaUse = skilltwomanause; }
	float getSkillThreeManaUse() { return _skillThreeManaUse; }
	void setSkillThreeManaUse(float skillthreemanause) { _skillThreeManaUse = skillthreemanause; }
	float getLv() { return _lv; }
	void setLv(float lv) { _lv = lv; }
	bool getIsHealing() { return IsHealing; }
	void setIsHealing(bool ishealing) { IsHealing = ishealing; }
	bool getSkillOneUnlock() { return _skillOneUnlock; }
	void setSkillOneUnlock(bool skilloneunlock) { _skillOneUnlock = skilloneunlock; }
	bool getSkillTwoUnlock() { return _skillTwoUnlock; }
	void setSkillTwoUnlock(bool skilltwounlock) { _skillTwoUnlock = skilltwounlock; }
	bool getSkillThreeUnlock() { return _skillThreeUnlock; }
	void setSkillThreeUnlock(bool skillthreeunlock) { _skillThreeUnlock = skillthreeunlock; }
	bool getUnitOneUnlock() { return _unitOneUnlock; }
	void setUnitOneUnlock(bool unitoneunlock) { _unitOneUnlock = unitoneunlock; }
	bool getUnitTwoUnlock() { return _unitTwoUnlock; }
	void setUnitTwoUnlock(bool unittwounlock) { _unitTwoUnlock = unittwounlock; }
	bool getUnitThreeUnlock() { return _unitThreeUnlock; }
	void setUnitThreeUnlock(bool unitthreeunlock) { _unitThreeUnlock = unitthreeunlock; }
	bool getStageStart() { return _stageStart; }
	void setStageStart(bool stagestart) { _stageStart = stagestart; }
	ProgressTimer* getManaGauge() { return _manaGauge; }
	ProgressTimer* getMeatGauge() { return _meatGauge; }
	ProgressTimer* getHeroHpInfo() { return _hpInfoGauge; }
	ProgressTimer* getMonsterBaseInfo() { return _MonsterBaseHpGauge; }
	ProgressTimer* getExpGauge() { return _expGauge; }
	RepeatForever* getWaitingAction() { return _heroWaitingAction; }
	RepeatForever* getWalkingAction() { return _heroWalkingAction; }
	Animate* getAttackAction() { return _animate3; }

	HAMMERKIND getHammerKind() { return _HammerKind; }
	void setHammerKind(HAMMERKIND hammerkind) { _HammerKind = hammerkind; }

	RepeatForever* HammerWaitingAction(HAMMERKIND hammerkind);
	RepeatForever* HammerWalkingAction(HAMMERKIND hammerkind);
	Animate* HammerAttackAction(HAMMERKIND hammerkind);
	Animate* HammerAttackEffectA(HAMMERKIND hammerkind);
	Animate* HammerAttackEffectB(HAMMERKIND hammerkind);
	Animate* HammerAttackEffectC(HAMMERKIND hammerkind);

	//유닛 정보 getset 함수
	float getMouseHp() { return _mouseHp; }
	void setMouseHp(float hp) { _mouseHp = hp; }
	float getMouseMaxHp() { return _mouseMaxHP; }
	void setMouseMaxHp(float maxhp) { _mouseMaxHP = maxhp; }
	float getMouseAtk() { return _mouseAtk; }
	void setMouseAtk(float atk) { _mouseAtk = atk; }
	float getMouseAtk2() { return _mouseAtk2; }
	void setMouseAtk2(float atk2) { _mouseAtk2 = atk2; }
	float getMouseSpeed() { return _mouseSpeed; }
	void setMouseSpeed(float speed) { _mouseSpeed = speed; }


	float getBearHp() { return _bearHp; }
	void setBearHp(float hp) { _bearHp = hp; }
	float getBearMaxHp() { return _bearMaxHP; }
	void setBearMaxHp(float maxhp) { _bearMaxHP = maxhp; }
	float getBearAtk() { return _bearAtk; }
	void setBearAtk(float atk) { _bearAtk = atk; }
	float getBearAtk2() { return _bearAtk2; }
	void setBearAtk2(float atk2) { _bearAtk2 = atk2; }
	float getBearSpeed() { return _bearSpeed; }
	void setBearSpeed(float speed) { _bearSpeed = speed; }


	float getKangarooHp() { return _kangarooHp; }
	void setKangarooHp(float hp) { _kangarooHp = hp; }
	float getKangarooMaxHp() { return _kangarooMaxHP; }
	void setKangarooMaxHp(float maxhp) { _kangarooMaxHP = maxhp; }
	float getKangarooAtk() { return _kangarooAtk; }
	void setKangarooAtk(float atk) { _kangarooAtk = atk; }
	float getKangarooAtk2() { return _kangarooAtk2; }
	void setKangarooAtk2(float atk2) { _kangarooAtk2 = atk2; }
	float getKangarooSpeed() { return _kangarooSpeed; }
	void setKangarooSpeed(float speed) { _kangarooSpeed = speed; }
};