#include "Hero.h"
#include "Monster.h"

Hero* Hero::Instance = nullptr;

Hero::Hero()
{
	// plist 파일 추가
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/Unit/u_01_1.plist");
	cache->addSpriteFramesWithFile("Player/weapons/m01_1.plist");
	cache->addSpriteFramesWithFile("Player/weapons/m02.plist");
	cache->addSpriteFramesWithFile("Player/weapons/m09.plist");
	cache->addSpriteFramesWithFile("Player/effect/eff_blend_01.plist");

	_movement = RightWay; // 기본 방향설정

	_lv = 1; // 레벨
	_speed = 1.0f; // 이동스피드

	_maxhp = 200; // 최대체력
	_hp = 200; // 현재체력

	_maxmana = 100; // 최대마나량
	_mana = 0; // 현재마나량
	_manaRegenSpeed = 0.2f; // 마나리젠속도

	_maxmeat = 40; // 최대고기량
	_meat = 0; // 현재고기량
	_meatRegenSpeed = 0.2f; // 고기리젠속도

	_gold = 0; //현재 골드
	_exp = 0; // 현재 경험치
	_maxExp = 100; // 최대 경험치

	_skillOneManaUse = 10; // 스킬 1 마나 사용량
	_skillTwoManaUse = 20; // 스킬 2 마나 사용량
	_skillThreeManaUse = 30; // 스킬 3 마나 사용량

	_HammerKind = 고무망치; // 최초 무기

	IsHealing = false;

	_skillOneUnlock = true;
	_skillTwoUnlock = false;
	_skillThreeUnlock = false;

	_unitOneUnlock = true;
	_unitTwoUnlock = false;
	_unitThreeUnlock = false;

	// 대기 애니메이션 만들기
	_animation1 = Animation::create();
	_animation1->setDelayPerUnit(0.03f);
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0001.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0002.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0003.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0004.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0005.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0006.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0007.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0008.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0009.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0010.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0011.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0012.png"));
	_animate1 = Animate::create(_animation1);
	_heroWaitingAction = RepeatForever::create(_animate1);
	_heroWaitingAction->retain();
	_heroWaitingAction->setTag(Waiting);

	// 걷기 애니메이션 만들기
	_animation2 = Animation::create();
	_animation2->setDelayPerUnit(0.03f);
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0001.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0002.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0003.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0004.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0005.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0006.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0007.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0008.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0009.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0010.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0011.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0012.png"));
	_animate2 = Animate::create(_animation2);
	_heroWalkingAction = RepeatForever::create(_animate2);
	_heroWalkingAction->retain();
	_heroWalkingAction->setTag(Walking);

	// 공격 애니메이션 만들기
	_animation3 = Animation::create();
	_animation3->setDelayPerUnit(0.03f);
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0001.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0002.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0003.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0004.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0005.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0006.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0007.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0008.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0009.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0010.png"));
	_animate3 = Animate::create(_animation3);
	_animate3->retain();
	_animate3->setTag(Attack);

	// 고무망치 대기 애니메이션 만들기
	_animation4 = Animation::create();
	_animation4->setDelayPerUnit(0.03f);
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0001.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0002.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0003.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0004.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0005.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0006.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0007.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0008.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0009.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0010.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0011.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("m01_wait_0012.png"));
	_animate4 = Animate::create(_animation4);
	_hammerWaitingAction1 = RepeatForever::create(_animate4);
	_hammerWaitingAction1->retain();
	_hammerWaitingAction1->setTag(HammerWaiting);

	// 고무망치 걷기 애니메이션 만들기
	_animation5 = Animation::create();
	_animation5->setDelayPerUnit(0.03f);
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0001.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0002.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0003.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0004.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0005.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0006.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0007.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0008.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0009.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0010.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0011.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("m01_walk_0012.png"));
	_animate5 = Animate::create(_animation5);
	_hammerWalkingAction1 = RepeatForever::create(_animate5);
	_hammerWalkingAction1->retain();
	_hammerWalkingAction1->setTag(HammerWalking);

	// 고무망치 공격 애니메이션 만들기
	_animation6 = Animation::create();
	_animation6->setDelayPerUnit(0.03f);
	_animation6->addSpriteFrame(cache->getSpriteFrameByName("m01_attack_0001.png"));
	_animation6->addSpriteFrame(cache->getSpriteFrameByName("m01_attack_0002.png"));
	_animation6->addSpriteFrame(cache->getSpriteFrameByName("m01_attack_0003.png"));
	_animation6->addSpriteFrame(cache->getSpriteFrameByName("m01_attack_0004.png"));
	_animation6->addSpriteFrame(cache->getSpriteFrameByName("m01_attack_0005.png"));
	_animation6->addSpriteFrame(cache->getSpriteFrameByName("m01_attack_0006.png"));
	_animation6->addSpriteFrame(cache->getSpriteFrameByName("m01_attack_0007.png"));
	_animation6->addSpriteFrame(cache->getSpriteFrameByName("m01_attack_0008.png"));
	_animation6->addSpriteFrame(cache->getSpriteFrameByName("m01_attack_0009.png"));
	_animation6->addSpriteFrame(cache->getSpriteFrameByName("m01_attack_0010.png"));
	_animate6 = Animate::create(_animation6);
	_animate6->retain();
	_animate6->setTag(HammerAttack);

	// 고무망치 스킬 이펙트 A 만들기
	_hammerSkillEffectAnimation_A1 = Animation::create();
	_hammerSkillEffectAnimation_A1->setDelayPerUnit(0.03f);
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0001.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0002.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0003.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0004.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0005.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0006.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0007.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0008.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0009.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0010.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0011.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0012.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0013.png"));
	_hammerSkillEffectAnimation_A1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_a_0014.png"));
	_hammerSkillEffectAnimate_A1 = Animate::create(_hammerSkillEffectAnimation_A1);
	_hammerSkillEffectAnimate_A1->retain();
	_hammerSkillEffectAnimate_A1->setTag(HammerSkillEffect1);

	// 회복망치 대기 애니메이션 만들기
	_animation7 = Animation::create();
	_animation7->setDelayPerUnit(0.03f);
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0001.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0002.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0003.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0004.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0005.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0006.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0007.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0008.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0009.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0010.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0011.png"));
	_animation7->addSpriteFrame(cache->getSpriteFrameByName("m02_wait_0012.png"));
	_animate7 = Animate::create(_animation7);
	_hammerWaitingAction2 = RepeatForever::create(_animate7);
	_hammerWaitingAction2->retain();
	_hammerWaitingAction2->setTag(HammerWaiting);

	// 회복망치 걷기 애니메이션 만들기
	_animation8 = Animation::create();
	_animation8->setDelayPerUnit(0.03f);
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0001.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0002.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0003.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0004.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0005.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0006.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0007.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0008.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0009.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0010.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0011.png"));
	_animation8->addSpriteFrame(cache->getSpriteFrameByName("m02_walk_0012.png"));
	_animate8 = Animate::create(_animation8);
	_hammerWalkingAction2 = RepeatForever::create(_animate8);
	_hammerWalkingAction2->retain();
	_hammerWalkingAction2->setTag(HammerWalking);

	// 회복망치 공격 애니메이션 만들기
	_animation9 = Animation::create();
	_animation9->setDelayPerUnit(0.03f);
	_animation9->addSpriteFrame(cache->getSpriteFrameByName("m02_attack_0001.png"));
	_animation9->addSpriteFrame(cache->getSpriteFrameByName("m02_attack_0002.png"));
	_animation9->addSpriteFrame(cache->getSpriteFrameByName("m02_attack_0003.png"));
	_animation9->addSpriteFrame(cache->getSpriteFrameByName("m02_attack_0004.png"));
	_animation9->addSpriteFrame(cache->getSpriteFrameByName("m02_attack_0005.png"));
	_animation9->addSpriteFrame(cache->getSpriteFrameByName("m02_attack_0006.png"));
	_animation9->addSpriteFrame(cache->getSpriteFrameByName("m02_attack_0007.png"));
	_animation9->addSpriteFrame(cache->getSpriteFrameByName("m02_attack_0008.png"));
	_animation9->addSpriteFrame(cache->getSpriteFrameByName("m02_attack_0009.png"));
	_animation9->addSpriteFrame(cache->getSpriteFrameByName("m02_attack_0010.png"));
	_animate9 = Animate::create(_animation9);
	_animate9->retain();
	_animate9->setTag(HammerAttack);

	// 회복망치 스킬 이펙트 A 만들기
	_hammerSkillEffectAnimation_A2 = Animation::create();
	_hammerSkillEffectAnimation_A2->setDelayPerUnit(0.02f);
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0001.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0002.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0003.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0004.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0005.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0006.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0007.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0008.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0009.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0010.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0011.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0012.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0013.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0014.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0015.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0016.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0017.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0018.png"));
	_hammerSkillEffectAnimation_A2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_a_0019.png"));
	_hammerSkillEffectAnimate_A2 = Animate::create(_hammerSkillEffectAnimation_A2);
	_hammerSkillEffectAnimate_A2->retain();
	_hammerSkillEffectAnimate_A2->setTag(HammerSkillEffect1);

	// 회복망치 스킬 이펙트 B 만들기
	_hammerSkillEffectAnimation_B2 = Animation::create();
	_hammerSkillEffectAnimation_B2->setDelayPerUnit(0.02f);
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0001.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0002.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0003.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0004.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0005.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0006.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0007.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0008.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0009.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0010.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0011.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0012.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0013.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0014.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0015.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0016.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0017.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0018.png"));
	_hammerSkillEffectAnimation_B2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_b_0019.png"));
	_hammerSkillEffectAnimate_B2 = Animate::create(_hammerSkillEffectAnimation_B2);
	_hammerSkillEffectAnimate_B2->retain();
	_hammerSkillEffectAnimate_B2->setTag(HammerSkillEffect2);

	// 회복망치 스킬 이펙트 C 만들기
	_hammerSkillEffectAnimation_C2 = Animation::create();
	_hammerSkillEffectAnimation_C2->setDelayPerUnit(0.02f);
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0001.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0002.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0003.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0004.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0005.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0006.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0007.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0008.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0009.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0010.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0011.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0012.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0013.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0014.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0015.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0016.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0017.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0018.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0019.png"));
	_hammerSkillEffectAnimation_C2->addSpriteFrame(cache->getSpriteFrameByName("m02_eff_c_0020.png"));
	_hammerSkillEffectAnimate_C2 = Animate::create(_hammerSkillEffectAnimation_C2);
	_hammerSkillEffectAnimate_C2->retain();
	_hammerSkillEffectAnimate_C2->setTag(HammerSkillEffect3);

	// 식량망치 대기 애니메이션 만들기
	_animation10 = Animation::create();
	_animation10->setDelayPerUnit(0.03f);
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0001.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0002.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0003.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0004.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0005.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0006.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0007.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0008.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0009.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0010.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0011.png"));
	_animation10->addSpriteFrame(cache->getSpriteFrameByName("m09_wait_0012.png"));
	_animate10 = Animate::create(_animation10);
	_hammerWaitingAction3 = RepeatForever::create(_animate10);
	_hammerWaitingAction3->retain();
	_hammerWaitingAction3->setTag(HammerWaiting);

	// 식량망치 걷기 애니메이션 만들기
	_animation11 = Animation::create();
	_animation11->setDelayPerUnit(0.03f);
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0001.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0002.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0003.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0004.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0005.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0006.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0007.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0008.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0009.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0010.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0011.png"));
	_animation11->addSpriteFrame(cache->getSpriteFrameByName("m09_walk_0012.png"));
	_animate11 = Animate::create(_animation11);
	_hammerWalkingAction3 = RepeatForever::create(_animate11);
	_hammerWalkingAction3->retain();
	_hammerWalkingAction3->setTag(HammerWalking);

	// 식량망치 공격 애니메이션 만들기
	_animation12 = Animation::create();
	_animation12->setDelayPerUnit(0.03f);
	_animation12->addSpriteFrame(cache->getSpriteFrameByName("m09_attack_0001.png"));
	_animation12->addSpriteFrame(cache->getSpriteFrameByName("m09_attack_0002.png"));
	_animation12->addSpriteFrame(cache->getSpriteFrameByName("m09_attack_0003.png"));
	_animation12->addSpriteFrame(cache->getSpriteFrameByName("m09_attack_0004.png"));
	_animation12->addSpriteFrame(cache->getSpriteFrameByName("m09_attack_0005.png"));
	_animation12->addSpriteFrame(cache->getSpriteFrameByName("m09_attack_0006.png"));
	_animation12->addSpriteFrame(cache->getSpriteFrameByName("m09_attack_0007.png"));
	_animation12->addSpriteFrame(cache->getSpriteFrameByName("m09_attack_0008.png"));
	_animation12->addSpriteFrame(cache->getSpriteFrameByName("m09_attack_0009.png"));
	_animation12->addSpriteFrame(cache->getSpriteFrameByName("m09_attack_0010.png"));
	_animate12 = Animate::create(_animation12);
	_animate12->retain();
	_animate12->setTag(HammerAttack);

	// 식량망치 스킬 이펙트 A 만들기
	_hammerSkillEffectAnimation_A3 = Animation::create();
	_hammerSkillEffectAnimation_A3->setDelayPerUnit(0.02f);
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0001.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0002.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0003.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0004.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0005.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0006.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0007.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0008.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0009.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0010.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0011.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0012.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0013.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0014.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0015.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0016.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0017.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0018.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0019.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0020.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0021.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0022.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0023.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0024.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0025.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0026.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0027.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0028.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0029.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0030.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0031.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0032.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0033.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0034.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0035.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0036.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0037.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0038.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0039.png"));
	_hammerSkillEffectAnimation_A3->addSpriteFrame(cache->getSpriteFrameByName("m09_eff_a_0040.png"));
	_hammerSkillEffectAnimate_A3 = Animate::create(_hammerSkillEffectAnimation_A3);
	_hammerSkillEffectAnimate_A3->retain();
	_hammerSkillEffectAnimate_A3->setTag(HammerSkillEffect1);

	// 히어로 오라 애니메이션
	_animation13 = Animation::create();
	_animation13->setDelayPerUnit(0.1f);
	_animation13->addSpriteFrame(cache->getSpriteFrameByName("eff_aura_0001.png"));
	_animation13->addSpriteFrame(cache->getSpriteFrameByName("eff_aura_0002.png"));
	_animation13->addSpriteFrame(cache->getSpriteFrameByName("eff_aura_0003.png"));
	_animation13->addSpriteFrame(cache->getSpriteFrameByName("eff_aura_0004.png"));
	_animation13->addSpriteFrame(cache->getSpriteFrameByName("eff_aura_0005.png"));
	_animation13->addSpriteFrame(cache->getSpriteFrameByName("eff_aura_0006.png"));
	_animate13 = Animate::create(_animation13);
	_heroBuffOraRepeat = RepeatForever::create(_animate13);

	
}

Hero * Hero::getInstance()
{
	if (Instance == nullptr)
	{
		Instance = new Hero();
	}

	return Instance;
}

void Hero::releaseInstance()
{
	if (Instance) delete Instance;
}

void Hero::createHeroInfo(Scene* scene, Layer* layer)
{

	// 영웅 만들기
	_hero = Sprite::createWithSpriteFrameName("hero_wait_0001.png");
	_hero->setPosition(100, 440);
	layer->addChild(_hero, (_hero->getPositionY() - _hero->getContentSize().height / 2) * -1);

	// 영웅 무기 만들기
	_heroWeapon1 = Sprite::createWithSpriteFrameName("m01_wait_0001.png");
	_heroWeapon1->setPosition(100, 440);
	layer->addChild(_heroWeapon1, _hero->getZOrder() - 1);

	// 스킬 이펙트를 보여줄 기준 스프라이트
	_skillEffectBox1 = Sprite::createWithSpriteFrameName("m01_eff_a_0001.png");
	layer->addChild(_skillEffectBox1, _hero->getZOrder());
	_skillEffectBox2 = Sprite::createWithSpriteFrameName("m01_eff_a_0001.png");
	layer->addChild(_skillEffectBox2, _hero->getZOrder());
	_skillEffectBox3 = Sprite::createWithSpriteFrameName("m01_eff_a_0001.png");
	layer->addChild(_skillEffectBox3, _hero->getZOrder() - 1);

	// 히어로 버프 오라
	_heroBuffOra = Sprite::createWithSpriteFrameName("eff_aura_0001.png");
	_heroBuffOra->setPosition(_hero->getPosition().x, _hero->getPosition().y);
	//_hero->getContentSize().width / 2, 10
	layer->addChild(_heroBuffOra, _hero->getZOrder() - 2);

	//마나 게이지 만들기
	_manaGauge = ProgressTimer::create(Sprite::create("UI/Mana.png"));
	_manaGauge->setType(ProgressTimer::Type::BAR);
	_manaGauge->setPosition({ 378,113 });
	_manaGauge->setMidpoint({ 1, 0 });
	_manaGauge->setBarChangeRate({ 1,0 });
	scene->addChild(_manaGauge, -1);

	//고기 게이지 만들기
	_meatGauge = ProgressTimer::create(Sprite::create("UI/Meat.png"));
	_meatGauge->setType(ProgressTimer::Type::BAR);
	_meatGauge->setPosition({ 103,113 });
	_meatGauge->setMidpoint({ 0, 0 });
	_meatGauge->setBarChangeRate({ 1,0 });
	scene->addChild(_meatGauge, -1);

	// 체력 게이지(중앙상단)
	_hpInfoGauge = ProgressTimer::create(Sprite::create("UI/HeroHpBar.png"));
	_hpInfoGauge->setType(ProgressTimer::Type::BAR);
	_hpInfoGauge->setPosition(201, 310);
	_hpInfoGauge->setMidpoint({ 1,0 });
	_hpInfoGauge->setBarChangeRate({ 1,0 });
	scene->addChild(_hpInfoGauge, -1);

	// 몬스터 베이스 체력 게이지(중앙상단)
	_MonsterBaseHpGauge = ProgressTimer::create(Sprite::create("UI/MonsterBaseHpBar.png"));
	_MonsterBaseHpGauge->setType(ProgressTimer::Type::BAR);
	_MonsterBaseHpGauge->setPosition(280, 310);
	_MonsterBaseHpGauge->setMidpoint({ 0,0 });
	_MonsterBaseHpGauge->setBarChangeRate({ 1,0 });
	scene->addChild(_MonsterBaseHpGauge, -1);

	// 경험치 게이지
	_expGauge = ProgressTimer::create(Sprite::create("UI/expbar.png"));
	_expGauge->setType(ProgressTimer::Type::BAR);
	_expGauge->setPosition(13, 303);
	_expGauge->setMidpoint({ 0,0 });
	_expGauge->setBarChangeRate({ 0,1 });
	scene->addChild(_expGauge, -11);

	_heroBuffOra->runAction(_heroBuffOraRepeat);
}

RepeatForever* Hero::HammerWaitingAction(HAMMERKIND hammerkind)
{
	switch (hammerkind)
	{
	case 고무망치:
	{
		return _hammerWaitingAction1;
	}
		break;
	case 회복망치:
	{
		return _hammerWaitingAction2;
	}
		break;
	case 식량망치:
	{
		return _hammerWaitingAction3;
	}
		break;
	default:
		break;
	}
}

RepeatForever * Hero::HammerWalkingAction(HAMMERKIND hammerkind)
{
	switch (hammerkind)
	{
	case 고무망치:
	{
		return _hammerWalkingAction1;
	}
	break;
	case 회복망치:
	{
		return _hammerWalkingAction2;
	}
	break;
	case 식량망치:
	{
		return _hammerWalkingAction3;
	}
	break;
	default:
		break;
	}
}

Animate * Hero::HammerAttackAction(HAMMERKIND hammerkind)
{
	switch (hammerkind)
	{
	case 고무망치:
	{
		return _animate6;
	}
	break;
	case 회복망치:
	{
		return _animate9;
	}
	break;
	case 식량망치:
	{
		return _animate12;
	}
	break;
	default:
		break;
	}
}

Animate* Hero::HammerAttackEffectA(HAMMERKIND hammerkind)
{
	switch (hammerkind)
	{
	case 고무망치:
	{
		_skillEffectBox1->setPosition(_hero->getPosition());
		_skillEffectBox1->setVisible(true);

		return _hammerSkillEffectAnimate_A1;
	}
	break;
	case 회복망치:
	{
		_skillEffectBox1->setPosition(_hero->getPosition());
		_skillEffectBox1->setVisible(true);


		IsHealing = true;

		return _hammerSkillEffectAnimate_A2;
	}
	break;
	case 식량망치:
	{
		_skillEffectBox1->setPosition(_hero->getPosition());
		_skillEffectBox1->setVisible(true);

		_meat += 15;

		if (_maxmeat < _meat)
		{
			_meat = _maxmeat;
		}

		return _hammerSkillEffectAnimate_A3;
	}
	break;
	default:
		break;
	}
}

Animate * Hero::HammerAttackEffectB(HAMMERKIND hammerkind)
{
	switch (hammerkind)
	{
	case 고무망치:
	{
		
	}
	break;
	case 회복망치:
	{
		_skillEffectBox2->setPosition(_hero->getPosition());
		_skillEffectBox2->setVisible(true);

		return _hammerSkillEffectAnimate_B2;
	}
	break;
	case 식량망치:
	{
		
	}
	break;
	default:
		break;
	}
}

Animate * Hero::HammerAttackEffectC(HAMMERKIND hammerkind)
{
	switch (hammerkind)
	{
	case 고무망치:
	{

	}
	break;
	case 회복망치:
	{
		_skillEffectBox3->setPosition(_hero->getPosition().x, _hero->getPosition().y - _hero->getContentSize().height / 4);
		_skillEffectBox3->setVisible(true);

		return _hammerSkillEffectAnimate_C2;
	}
	break;
	case 식량망치:
	{

	}
	break;
	default:
		break;
	}
}
