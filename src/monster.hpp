/*-------------------------------------------------------------------------------

	BARONY
	File: monster.hpp
	Desc: header file for monsters

	Copyright 2013-2016 (c) Turning Wheel LLC, all rights reserved.
	See LICENSE for details.

-------------------------------------------------------------------------------*/

#pragma once

enum Monster : int
{
	NOTHING,
	HUMAN,
	RAT,
	GOBLIN,
	SLIME,
	TROLL,
	OCTOPUS,
	SPIDER,
	GHOUL,
	SKELETON,
	SCORPION,
	CREATURE_IMP, //Because Apple so unkindly is already using the IMP keyword.
	BUGBEAR,
	GNOME,
	DEMON,
	SUCCUBUS,
	MIMIC,
	LICH,
	MINOTAUR,
	DEVIL,
	SHOPKEEPER,
	KOBOLD,
	SCARAB,
	CRYSTALGOLEM,
	INCUBUS,
	VAMPIRE,
	SHADOW,
	COCKATRICE,
	INSECTOID,
	GOATMAN,
	AUTOMATON,
	LICH_ICE,
	LICH_FIRE
};
const int NUMMONSTERS = 33;
extern int kills[NUMMONSTERS];

static char monstertypename[][15] =
{
	"nothing",
	"human",
	"rat",
	"goblin",
	"slime",
	"troll",
	"octopus",
	"spider",
	"ghoul",
	"skeleton",
	"scorpion",
	"imp",
	"bugbear",
	"gnome",
	"demon",
	"succubus",
	"mimic",
	"lich",
	"minotaur",
	"devil",
	"shopkeeper",
	"kobold",
	"scarab",
	"crystalgolem",
	"incubus",
	"vampire",
	"shadow",
	"cockatrice",
	"insectoid",
	"goatman",
	"automaton",
	"lichice",
	"lichfire"
};

static char monstertypenamecapitalized[][15] =
{
	"Nothing",
	"Human",
	"Rat",
	"Goblin",
	"Slime",
	"Troll",
	"Octopus",
	"Spider",
	"Ghoul",
	"Skeleton",
	"Scorpion",
	"Imp",
	"Bugbear",
	"Gnome",
	"Demon",
	"Succubus",
	"Mimic",
	"Lich",
	"Minotaur",
	"Devil",
	"Shopkeeper",
	"Kobold",
	"Scarab",
	"Crystalgolem",
	"Incubus",
	"Vampire",
	"Shadow",
	"Cockatrice",
	"Insectoid",
	"Goatman",
	"Automaton",
	"Lichice",
	"Lichfire"
};

// body part focal points
extern float limbs[NUMMONSTERS][20][3];

// 0: nothing
// 1: red blood
// 2: green blood
// 3: slime
static char gibtype[NUMMONSTERS] =
{
	0,	//NOTHING,
	1,	//HUMAN,
	1,	//RAT,
	1,	//GOBLIN,
	3,	//SLIME,
	1,	//TROLL,
	1,	//OCTOPUS,
	2,	//SPIDER,
	2,	//GHOUL,
	0,	//SKELETON,
	2,	//SCORPION,
	1,	//CREATURE_IMP
	1,	//BUGBEAR,
	1,	//GNOME,
	1,	//DEMON,
	1,	//SUCCUBUS,
	1,	//MIMIC,
	2,	//LICH,
	1,	//MINOTAUR,
	1,	//DEVIL,
	1,	//SHOPKEEPER,
	1,	//KOBOLD,
	2,	//SCARAB,
	0,	//CRYSTALGOLem,
	1,	//INCUBUS,
	1,	//VAMPIRE,
	4,	//SHADOW,
	1,	//COCKATRICE
	2,	//INSECTOID,
	1,	//GOATMAN,
	0,	//AUTOMATON,
	2,	//LICH_ICE,
	2	//LICH_FIRE

};

// columns go like this:
// sword, mace, axe, polearm, ranged, magic, unarmed
// lower number means less effective, higher number means more effective
static double damagetables[NUMMONSTERS][7] =
{
	{ 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f }, // nothing
	{ 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f }, // human
	{ 1.1, 1.1, 0.9, 0.9, 1.2, 1.f, 1.3 }, // rat
	{ 0.9, 1.f, 1.1, 1.1, 1.1, 1.f, 0.8 }, // goblin
	{ 1.4, 0.5, 1.3, 0.7, 0.5, 1.3, 0.5 }, // slime
	{ 1.1, 0.8, 1.1, 0.8, 0.9, 1.f, 0.8 }, // troll
	{ 1.2, 1.f, 1.1, 0.9, 1.1, 1.f, 1.f }, // octopus
	{ 1.f, 1.1, 1.f, 1.2, 1.1, 1.f, 1.1 }, // spider
	{ 1.f, 1.2, 0.8, 1.1, 0.6, 0.8, 1.1 }, // ghoul
	{ 0.5, 1.4, 0.8, 1.3, 0.5, 0.8, 1.1 }, // skeleton
	{ 0.9, 1.1, 1.f, 1.3, 1.f, 1.f, 1.2 }, // scorpion
	{ 1.1, 1.f, 0.8, 1.f, 1.f, 1.2, 1.f }, // imp
	{ 1.1, 1.f, 1.1, 0.9, 1.1, 1.f, 1.f }, // bugbear
	{ 0.9, 1.f, 1.f, 0.9, 1.1, 1.1, 1.f }, // gnome
	{ 0.9, 0.8, 1.f, 0.8, 0.9, 1.1, 0.8 }, // demon
	{ 1.2, 1.f, 1.f, 0.9, 1.f, 0.8, 1.f }, // succubus
	{ 0.8, 1.1, 1.3, 1.f, 0.7, 1.2, 1.f }, // mimic
	{ 2.5, 2.5, 2.5, 2.5, 1.f, 1.f, 1.8 }, // lich
	{ 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f }, // minotaur
	{ 2.f, 2.f, 2.f, 2.f, 1.f, 1.f, 1.f }, // devil
	{ 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.f }, // shopkeeper
	{ 0.9, 1.2, 1.2, 0.9, 1.1, 0.2, 0.8 }, // kobold
	{ 1.5, 1.1, 1.4, 0.7, 1.1, 0.2, 1.4 }, // scarab
	{ 1.f, 1.5, 1.3, 0.8, 0.6, 0.6, 0.6 }, // crystal golem
	{ 1.2, 1.f, 1.f, 0.9, 1.3, 0.8, 1.f }, // incubus
	{ 0.8, 1.2, 0.8, 1.1, 0.5, 0.8, 1.f }, // vampire
	{ 0.5, 0.5, 0.5, 0.5, 0.5, 2.0, 0.5 }, // shadow
	{ 1.6, 1.1, 1.3, 1.8, 0.5, 0.5, 0.8 }, // cockatrice
	{ 0.9, 1.f, 1.1, 1.1, 1.1, 1.f, 0.8 }, // insectoid
	{ 0.9, 1.f, 1.1, 1.1, 1.1, 1.4, 1.f }, // goatman
	{ 0.5, 1.4, 0.8, 1.3, 0.5, 0.8, 0.7 }, // automaton
	{ 1.5, 1.5, 1.5, 1.5, 1.f, 0.7, 1.2 }, // lich ice
	{ 1.8, 1.8, 1.8, 1.8, 1.f, 1.f, 1.4 }  // lich fire

};

static std::vector<std::vector<int>> classStatGrowth =
{
	// stat weightings for classes on level up
	//	STR	DEX	CON	INT	PER	CHR -- sum is approx 24.
	{	6,	5,	2,	2,	4,	5 }, // BARB 0
	{	7,	2,	6,	1,	2,	6 }, // WARRIOR 1
	{	4,	2,	5,	5,	4,	4 }, // CLERIC 2
	{	3,	3,	4,	6,	5,	3 }, // HEALER 3
	{	5,	4,	5,	3,	5,	2 }, // WANDERER 4
	{	2,	7,	1,	2,	7,	5 }, // ROGUE 5
	{	2,	6,	2,	6,	6,	2 }, // ARCANIST 6
	{	1,	3,	2,	7,	6,	5 }, // WIZARD 7
	{	3,	2,	4,	3,	5,	7 }, // MERCHANT 8
	{	4,	4,	4,	4,	4,	4 }, // JOKER 9
	{	4,	4,	2,	4,	2,	2 }, // SEXTON 10
	{	5,	5,	3,	2,	2,	1 }, // NINJA 11
	{	4,	2,	5,	3,	2,	2 }, // MONK 12
	{	3,	2,	4,	6,	4,	4 }, // CONJURER 13
	{	3,	3,	1,	6,	6,	3 }, // ACCURSED 14
	{	3,	3,	1,	6,	4,	7 }, // MESMER 15
	{	4,	4,	3,	5,	3,	5 }, // BREWER 16
	{	4,	4,	4,	4,	4,	4 }, // RESERVED 17
	{	4,	4,	4,	4,	4,	4 }, // RESERVED 18
	{	4,	4,	4,	4,	4,	4 }, // RESERVED 19
	{	4,	4,	4,	4,	4,	4 } // RESERVED 20
};

enum AllyNPCCommand : int
{
	ALLY_CMD_DEFEND,
	ALLY_CMD_CLASS_TOGGLE,
	ALLY_CMD_MOVETO_SELECT,
	ALLY_CMD_PICKUP_TOGGLE,
	ALLY_CMD_MOVEASIDE,
	ALLY_CMD_DROP_EQUIP,
	ALLY_CMD_ATTACK_SELECT,
	ALLY_CMD_SPECIAL,
	ALLY_CMD_FOLLOW,
	ALLY_CMD_MOVETO_CONFIRM,
	ALLY_CMD_CANCEL,
	ALLY_CMD_ATTACK_CONFIRM,
	ALLY_CMD_RETURN_SOUL,
	ALLY_CMD_END
};

static const int AllyNPCSkillRequirements[13] =
{
	SKILL_LEVEL_NOVICE,	// ALLY_CMD_DEFEND,
	SKILL_LEVEL_SKILLED,// ALLY_CMD_CLASS_TOGGLE,
	SKILL_LEVEL_BASIC,// ALLY_CMD_MOVETO_SELECT,
	SKILL_LEVEL_BASIC,	// ALLY_CMD_PICKUP_TOGGLE,
	0,					// ALLY_CMD_MOVEASIDE,
	SKILL_LEVEL_SKILLED,// ALLY_CMD_DROP_EQUIP,
	SKILL_LEVEL_BASIC,	// ALLY_CMD_ATTACK_SELECT,
	SKILL_LEVEL_SKILLED,// ALLY_CMD_SPECIAL,
	SKILL_LEVEL_NOVICE,	// ALLY_CMD_FOLLOW,
	SKILL_LEVEL_BASIC,	// ALLY_CMD_MOVETO_CONFIRM,
	0,					// ALLY_CMD_CANCEL
	SKILL_LEVEL_EXPERT, // ALLY_CMD_ATTACK_CONFIRM
	0					// ALLY_CMD_END
};

enum AllyNPCState : int
{
	ALLY_STATE_DEFAULT,
	ALLY_STATE_MOVETO,
	ALLY_STATE_DEFEND,
	ALLY_STATE_INTERACT
};

enum AllyNPCPickup : int
{
	ALLY_PICKUP_NONPLAYER,
	ALLY_PICKUP_NONE,
	ALLY_PICKUP_ALL
};

enum AllyNPCClass : int
{
	ALLY_CLASS_MIXED,
	ALLY_CLASS_MELEE,
	ALLY_CLASS_RANGED
};

enum AllyNPCChatter : int
{
	ALLY_EVENT_MOVEASIDE,
	ALLY_EVENT_MOVETO_BEGIN,
	ALLY_EVENT_MOVETO_END,
	ALLY_EVENT_MOVETO_FAIL,
	ALLY_EVENT_MOVETO_REPATH,
	ALLY_EVENT_INTERACT_ITEM_UNKNOWN,
	ALLY_EVENT_INTERACT_ITEM_NOUSE,
	ALLY_EVENT_INTERACT_ITEM_FOOD_GOOD,
	ALLY_EVENT_INTERACT_ITEM_FOOD_BAD,
	ALLY_EVENT_INTERACT_ITEM_FOOD_ROTTEN,
	ALLY_EVENT_INTERACT_ITEM_FOOD_FULL,
	ALLY_EVENT_INTERACT_ITEM_CURSED,
	ALLY_EVENT_INTERACT_OTHER,
	ALLY_EVENT_ATTACK,
	ALLY_EVENT_ATTACK_FRIENDLY_FIRE,
	ALLY_EVENT_DROP_WEAPON,
	ALLY_EVENT_DROP_EQUIP,
	ALLY_EVENT_DROP_ALL,
	ALLY_EVENT_DROP_HUMAN_REFUSE,
	ALLY_EVENT_SPOT_ENEMY,
	ALLY_EVENT_WAIT,
	ALLY_EVENT_FOLLOW,
	ALLY_EVENT_REST
};

enum AllyNPCSpecialCmd : int
{
	ALLY_SPECIAL_CMD_NONE,
	ALLY_SPECIAL_CMD_REST
};

enum MonsterDefendType : int
{
	MONSTER_DEFEND_NONE,
	MONSTER_DEFEND_ALLY,
	MONSTER_DEFEND_HOLD
};

#define WAIT_FOLLOWDIST 48
#define HUNT_FOLLOWDIST 64

#define HITRATE 45

#define MONSTER_INIT my->skill[3]
#define MONSTER_NUMBER my->skill[5]
#define MONSTER_HITTIME my->skill[7]
#define MONSTER_ATTACK my->skill[8]
#define MONSTER_ATTACKTIME my->skill[9]
#define MONSTER_ARMBENDED my->skill[10]
#define MONSTER_SPOTSND my->skill[11]
#define MONSTER_SPOTVAR my->skill[12]
#define MONSTER_CLICKED my->skill[13]
#define MONSTER_IDLESND my->skill[19]

#define MONSTER_IDLEVAR myStats->monster_idlevar
#define MONSTER_SOUND myStats->monster_sound
#define MONSTER_VELX my->vel_x
#define MONSTER_VELY my->vel_y
#define MONSTER_VELZ my->vel_z
#define MONSTER_WEAPONYAW my->fskill[5]
#define MONSTER_FLIPPEDANGLE my->fskill[6]
#define MONSTER_SHIELDYAW my->fskill[8]

static const int MONSTER_ALLY_DEXTERITY_SPEED_CAP = 15;

void summonMonsterClient(Monster creature, long x, long y, Uint32 uid);
Entity* summonMonster(Monster creature, long x, long y, bool forceLocation = false);
void summonManyMonster(Monster creature);
bool monsterMoveAside(Entity* my, Entity* entity);

//--init* functions--
void initHuman(Entity* my, Stat* myStats);
void initRat(Entity* my, Stat* myStats);
void initGoblin(Entity* my, Stat* myStats);
void initSlime(Entity* my, Stat* myStats);
void initScorpion(Entity* my, Stat* myStats);
void initSuccubus(Entity* my, Stat* myStats);
void initTroll(Entity* my, Stat* myStats);
void initShopkeeper(Entity* my, Stat* myStats);
void initSkeleton(Entity* my, Stat* myStats);
void initMinotaur(Entity* my, Stat* myStats);
void initGhoul(Entity* my, Stat* myStats);
void initDemon(Entity* my, Stat* myStats);
void initSpider(Entity* my, Stat* myStats);
void initLich(Entity* my, Stat* myStats);
void initImp(Entity* my, Stat* myStats);
void initGnome(Entity* my, Stat* myStats);
void initDevil(Entity* my, Stat* myStats);
void initAutomaton(Entity* my, Stat* myStats);
void initCockatrice(Entity* my, Stat* myStats);
void initCrystalgolem(Entity* my, Stat* myStats);
void initScarab(Entity* my, Stat* myStats);
void initKobold(Entity* my, Stat* myStats);
void initShadow(Entity* my, Stat* myStats);
void initVampire(Entity* my, Stat* myStats);
void initIncubus(Entity* my, Stat* myStats);
void initInsectoid(Entity* my, Stat* myStats);
void initGoatman(Entity* my, Stat* myStats);
void initLichFire(Entity* my, Stat* myStats);
void initLichIce(Entity* my, Stat* myStats);

//--act*Limb functions--
void actHumanLimb(Entity* my);
void actGoblinLimb(Entity* my);
void actScorpionTail(Entity* my);
void actSuccubusLimb(Entity* my);
void actTrollLimb(Entity* my);
void actShopkeeperLimb(Entity* my);
void actSkeletonLimb(Entity* my);
void actMinotaurLimb(Entity* my);
void actGhoulLimb(Entity* my);
void actDemonLimb(Entity* my);
void actSpiderLimb(Entity* my);
void actLichLimb(Entity* my);
void actImpLimb(Entity* my);
void actGnomeLimb(Entity* my);
void actDevilLimb(Entity* my);
void actAutomatonLimb(Entity* my);
void actCockatriceLimb(Entity* my);
void actCrystalgolemLimb(Entity* my);
void actKoboldLimb(Entity* my);
void actShadowLimb(Entity* my);
void actVampireLimb(Entity* my);
void actIncubusLimb(Entity* my);
void actInsectoidLimb(Entity* my);
void actGoatmanLimb(Entity* my);
void actScarabLimb(Entity* my);
void actLichFireLimb(Entity* my);
void actLichIceLimb(Entity* my);

//--*Die functions--
void humanDie(Entity* my);
void ratDie(Entity* my);
void goblinDie(Entity* my);
void slimeDie(Entity* my);
void scorpionDie(Entity* my);
void succubusDie(Entity* my);
void trollDie(Entity* my);
void shopkeeperDie(Entity* my);
void skeletonDie(Entity* my);
void minotaurDie(Entity* my);
void ghoulDie(Entity* my);
void demonDie(Entity* my);
void spiderDie(Entity* my);
void lichDie(Entity* my);
void impDie(Entity* my);
void gnomeDie(Entity* my);
void devilDie(Entity* my);
void automatonDie(Entity* my);
void cockatriceDie(Entity* my);
void crystalgolemDie(Entity* my);
void scarabDie(Entity* my);
void koboldDie(Entity* my);
void shadowDie(Entity* my);
void vampireDie(Entity* my);
void incubusDie(Entity* my);
void insectoidDie(Entity* my);
void goatmanDie(Entity* my);
void lichFireDie(Entity* my);
void lichIceDie(Entity* my);

//--*MoveBodyparts functions--
void humanMoveBodyparts(Entity* my, Stat* myStats, double dist);
void ratAnimate(Entity* my, double dist);
void goblinMoveBodyparts(Entity* my, Stat* myStats, double dist);
void slimeAnimate(Entity* my, double dist);
void scorpionAnimate(Entity* my, double dist);
void succubusMoveBodyparts(Entity* my, Stat* myStats, double dist);
void trollMoveBodyparts(Entity* my, Stat* myStats, double dist);
void shopkeeperMoveBodyparts(Entity* my, Stat* myStats, double dist);
void skeletonMoveBodyparts(Entity* my, Stat* myStats, double dist);
void minotaurMoveBodyparts(Entity* my, Stat* myStats, double dist);
void ghoulMoveBodyparts(Entity* my, Stat* myStats, double dist);
void demonMoveBodyparts(Entity* my, Stat* myStats, double dist);
void spiderMoveBodyparts(Entity* my, Stat* myStats, double dist);
void lichAnimate(Entity* my, double dist);
void impMoveBodyparts(Entity* my, Stat* myStats, double dist);
void gnomeMoveBodyparts(Entity* my, Stat* myStats, double dist);
void devilMoveBodyparts(Entity* my, Stat* myStats, double dist);
void cockatriceMoveBodyparts(Entity* my, Stat* myStats, double dist);
void automatonMoveBodyparts(Entity* my, Stat* myStats, double dist);
void crystalgolemMoveBodyparts(Entity* my, Stat* myStats, double dist);
void scarabAnimate(Entity* my, Stat* myStats, double dist);
void koboldMoveBodyparts(Entity* my, Stat* myStats, double dist);
void shadowMoveBodyparts(Entity* my, Stat* myStats, double dist);
void vampireMoveBodyparts(Entity* my, Stat* myStats, double dist);
void incubusMoveBodyparts(Entity* my, Stat* myStats, double dist);
void insectoidMoveBodyparts(Entity* my, Stat* myStats, double dist);
void goatmanMoveBodyparts(Entity* my, Stat* myStats, double dist);
void lichFireAnimate(Entity* my, Stat* myStats, double dist);
void lichIceAnimate(Entity* my, Stat* myStats, double dist);

//--misc functions--
void actMinotaurTrap(Entity* my);
void actMinotaurTimer(Entity* my);
void actMinotaurCeilingBuster(Entity* my);
void actDemonCeilingBuster(Entity* my);

void actDevilTeleport(Entity* my);

void createMinotaurTimer(Entity* entity, map_t* map);

void actSummonTrap(Entity* my);
int monsterCurve(int level);

bool forceFollower(Entity& leader, Entity& follower);

//--monsterState constants
static const Sint32 MONSTER_STATE_WAIT = 0;
static const Sint32 MONSTER_STATE_ATTACK = 1;
static const Sint32 MONSTER_STATE_PATH = 2;
static const Sint32 MONSTER_STATE_HUNT = 3;
static const Sint32 MONSTER_STATE_TALK = 4;
static const Sint32 MONSTER_STATE_LICH_DODGE = 5;
static const Sint32 MONSTER_STATE_LICH_SUMMON = 6;
static const Sint32 MONSTER_STATE_LICH_DEATH = 7;
static const Sint32 MONSTER_STATE_DEVIL_DEATH = 8;
static const Sint32 MONSTER_STATE_DEVIL_TELEPORT = 9;
static const Sint32 MONSTER_STATE_DEVIL_RISING = 10;
static const Sint32 MONSTER_STATE_DEVIL_SUMMON = 11;
static const Sint32 MONSTER_STATE_DEVIL_BOULDER = 12;
static const Sint32 MONSTER_STATE_LICHFIRE_DODGE = 13;
static const Sint32 MONSTER_STATE_LICH_CASTSPELLS = 14;
static const Sint32 MONSTER_STATE_LICHFIRE_TELEPORT_STATIONARY = 15;
static const Sint32 MONSTER_STATE_LICH_TELEPORT_ROAMING = 16;
static const Sint32 MONSTER_STATE_LICHICE_TELEPORT_STATIONARY = 17;
static const Sint32 MONSTER_STATE_LICHICE_DODGE = 13;
static const Sint32 MONSTER_STATE_LICHFIRE_DIE = 18;
static const Sint32 MONSTER_STATE_LICHICE_DIE = 18;

//--special monster attack constants
static const int MONSTER_POSE_MELEE_WINDUP1 = 4;
static const int MONSTER_POSE_MELEE_WINDUP2 = 5;
static const int MONSTER_POSE_MELEE_WINDUP3 = 6;
static const int MONSTER_POSE_RANGED_WINDUP1 = 7;
static const int MONSTER_POSE_RANGED_WINDUP2 = 8;
static const int MONSTER_POSE_RANGED_WINDUP3 = 9;
//TODO: Need potions and thrown.
static const int MONSTER_POSE_MAGIC_WINDUP1 = 10;
static const int MONSTER_POSE_MAGIC_WINDUP2 = 11;
static const int MONSTER_POSE_MAGIC_WINDUP3 = 12;
static const int MONSTER_POSE_SPECIAL_WINDUP1 = 13;
static const int MONSTER_POSE_SPECIAL_WINDUP2 = 14;
static const int MONSTER_POSE_SPECIAL_WINDUP3 = 15;
static const int MONSTER_POSE_RANGED_SHOOT1 = 16;
static const int MONSTER_POSE_RANGED_SHOOT2 = 17;
static const int MONSTER_POSE_RANGED_SHOOT3 = 18;
static const int MONSTER_POSE_MAGIC_CAST1 = 19;
static const int MONSTER_POSE_MAGIC_CAST2 = 20;
static const int MONSTER_POSE_MAGIC_CAST3 = 21;
static const int MONSTER_POSE_GOLEM_SMASH = 22;
static const int MONSTER_POSE_COCKATRICE_DOUBLEATTACK = 23;
static const int MONSTER_POSE_AUTOMATON_RECYCLE = 24;
//static const int MONSTER_POSE_SHADOW_TELEMIMICINVISI_WINDUP = 25;
static const int MONSTER_POSE_INSECTOID_DOUBLETHROW = 25;
static const int MONSTER_POSE_INCUBUS_CONFUSION = 26;
static const int MONSTER_POSE_INCUBUS_TELEPORT = 27;
static const int MONSTER_POSE_VAMPIRE_AURA_CHARGE = 28;
static const int MONSTER_POSE_VAMPIRE_DRAIN = 29;
static const int MONSTER_POSE_VAMPIRE_AURA_CAST = 30;
static const int MONSTER_POSE_AUTOMATON_MALFUNCTION = 31;
static const int MONSTER_POSE_LICH_FIRE_SWORD = 32;

//--monster special cooldowns
static const int MONSTER_SPECIAL_COOLDOWN_GOLEM = 150;
static const int MONSTER_SPECIAL_COOLDOWN_KOBOLD = 250;
static const int MONSTER_SPECIAL_COOLDOWN_COCKATRICE_ATK = 100;
static const int MONSTER_SPECIAL_COOLDOWN_COCKATRICE_STONE = 250;
static const int MONSTER_SPECIAL_COOLDOWN_AUTOMATON_RECYCLE = 500;
static const int MONSTER_SPECIAL_COOLDOWN_AUTOMATON_MALFUNCTION = 200;
static const int MONSTER_SPECIAL_COOLDOWN_GOATMAN_THROW = 300;
static const int MONSTER_SPECIAL_COOLDOWN_GOATMAN_DRINK = 350;
static const int MONSTER_SPECIAL_COOLDOWN_SHADOW_TELEMIMICINVISI_ATTACK = 500;
static const int MONSTER_SPECIAL_COOLDOWN_SHADOW_PASIVE_TELEPORT = 250;
static const int MONSTER_SPECIAL_COOLDOWN_SHADOW_SPELLCAST = 250;
static const int MONSTER_SPECIAL_COOLDOWN_SHADOW_TELEPORT = 300;
static const int MONSTER_SPECIAL_COOLDOWN_INSECTOID_THROW = 250;
static const int MONSTER_SPECIAL_COOLDOWN_INSECTOID_ACID = 500;
static const int MONSTER_SPECIAL_COOLDOWN_INCUBUS_CONFUSION = 500;
static const int MONSTER_SPECIAL_COOLDOWN_INCUBUS_STEAL = 500;
static const int MONSTER_SPECIAL_COOLDOWN_INCUBUS_CHARM = 300;
static const int MONSTER_SPECIAL_COOLDOWN_INCUBUS_TELEPORT_RANDOM = 400;
static const int MONSTER_SPECIAL_COOLDOWN_INCUBUS_TELEPORT_TARGET = 200;
static const int MONSTER_SPECIAL_COOLDOWN_VAMPIRE_AURA = 500;
static const int MONSTER_SPECIAL_COOLDOWN_VAMPIRE_DRAIN = 300;
static const int MONSTER_SPECIAL_COOLDOWN_SUCCUBUS_CHARM = 400;

//--monster target search types
static const int MONSTER_TARGET_ENEMY = 0;
static const int MONSTER_TARGET_FRIEND = 1;
static const int MONSTER_TARGET_PLAYER = 2;
static const int MONSTER_TARGET_ALL = 3;

//--monster animation handler
static const int ANIMATE_YAW = 1;
static const int ANIMATE_PITCH = 2;
static const int ANIMATE_ROLL = 3;
static const int ANIMATE_WEAPON_YAW = 4;
static const int ANIMATE_Z = 5;

static const int ANIMATE_DIR_POSITIVE = 1;
static const int ANIMATE_DIR_NEGATIVE = -1;
static const int ANIMATE_DIR_NONE = 0;

static const int ANIMATE_OVERSHOOT_TO_SETPOINT = 1;
static const int ANIMATE_OVERSHOOT_TO_ENDPOINT = 2;
static const int ANIMATE_OVERSHOOT_NONE = 0;

//--monster limb bodypart IDs
static const int LIMB_HUMANOID_TORSO = 2;
static const int LIMB_HUMANOID_RIGHTLEG = 3;
static const int LIMB_HUMANOID_LEFTLEG = 4;
static const int LIMB_HUMANOID_RIGHTARM = 5;
static const int LIMB_HUMANOID_LEFTARM = 6;
static const int LIMB_HUMANOID_WEAPON = 7;
static const int LIMB_HUMANOID_SHIELD = 8;
static const int LIMB_HUMANOID_CLOAK = 9;
static const int LIMB_HUMANOID_HELMET = 10;
static const int LIMB_HUMANOID_MASK = 11;

//--monster attack windup duration, in ticks, roughly 180ms
static const int ANIMATE_DURATION_WINDUP = 9;
static const int ANIMATE_DURATION_WINDUP_SHADOW_SPECIAL = 50;

//--monster footstep sounds
static const int MONSTER_FOOTSTEP_NONE = 0;
static const int MONSTER_FOOTSTEP_STOMP = 1;
static const int MONSTER_FOOTSTEP_SKELETON = 2;
static const int MONSTER_FOOTSTEP_LEATHER = 3;
static const int MONSTER_FOOTSTEP_USE_BOOTS = 4; // variable dependent on footwear

//--monster spellcasting animation types
static const int MONSTER_SPELLCAST_NONE = 0;
static const int MONSTER_SPELLCAST_SMALL_HUMANOID = 1;
static const int MONSTER_SPELLCAST_HUMANOID = 2;

//--monster NPC language lines
static const int MONSTER_NPC_DIALOGUE_LINES = 10;

//--animates the selected limb to setpoint along the axis, at the given rate.
int limbAnimateToLimit(Entity* limb, int axis, double rate, double setpoint, bool shake, double shakerate);
//--animates the selected limb to setpoint, then endpoint along the axis, provided MONSTER_LIMB_OVERSHOOT is set
int limbAnimateWithOvershoot(Entity* limb, int axis, double setpointRate, double setpoint, double endpointRate, double endpoint, int dir);
int limbAngleWithinRange(real_t angle, double rate, double setpoint);
real_t normaliseAngle2PI(real_t angle);
void getTargetsAroundEntity(Entity* my, Entity* originalTarget, double distToFind, real_t angleToSearch, int searchType, list_t** list);
int numTargetsAroundEntity(Entity* my, double distToFind, real_t angleToSearch, int searchType);
// change animation speeds for debugging, default value 10.
extern int monsterGlobalAnimationMultiplier;
// change attacktime for debugging, default value 1.
extern int monsterGlobalAttackTimeMultiplier;
// monster custom NPC chatter
bool handleMonsterChatter(int monsterclicked, bool ringconflict, char namesays[32], Entity* my, Stat* myStats);
// check qty of a certain creature race alive on a map
int numMonsterTypeAliveOnMap(Monster creature, Entity*& lastMonster);

//-----RACE SPECIFIC CONSTANTS-----

//--Goatman--
static const int GOATMAN_HEALINGPOTION_MOD = 3;
static const int GOATMAN_HEALING_POTION_SPEED_BOOST_DURATION = 1800;
static const int GOATMAN_POTION = 1;
static const int GOATMAN_THROW = 2;

//--Automaton--
static const int AUTOMATON_RECYCLE_ANIMATION_WAITING = 0;
static const int AUTOMATON_RECYCLE_ANIMATION_COMPLETE = 1;
static const int AUTOMATON_MALFUNCTION_START = 2;
static const int AUTOMATON_MALFUNCTION_RUN = 3;

//--Insectoid--
static const int INSECTOID_ACID = 1;
static const int INSECTOID_DOUBLETHROW_FIRST = 2;
static const int INSECTOID_DOUBLETHROW_SECOND = 3;

//--Incubus--
static const int INCUBUS_CONFUSION = 1;
static const int INCUBUS_STEAL = 2;
static const int INCUBUS_TELEPORT_STEAL = 3;
static const int INCUBUS_TELEPORT = 4;
static const int INCUBUS_CHARM = 5;

//--Vampire--
static const int VAMPIRE_CAST_AURA = 1;
static const int VAMPIRE_CAST_DRAIN = 2;

//--Succubus--
static const int SUCCUBUS_CHARM = 1;

//--Shadow--
static const int SHADOW_SPELLCAST = 1;
static const int SHADOW_TELEPORT_ONLY = 2;

//--Lich Attacks--
static const int LICH_ATK_VERTICAL_SINGLE = 0;
static const int LICH_ATK_HORIZONTAL_SINGLE = 1;
static const int LICH_ATK_RISING_RAIN = 2;
static const int LICH_ATK_BASICSPELL_SINGLE = 3;
static const int LICH_ATK_RISING_SINGLE = 4;
static const int LICH_ATK_VERTICAL_QUICK = 5;
static const int LICH_ATK_HORIZONTAL_RETURN = 6;
static const int LICH_ATK_HORIZONTAL_QUICK = 7;
static const int LICH_ATK_CHARGE_AOE = 8;
static const int LICH_ATK_FALLING_DIAGONAL = 9;
static const int LICH_ATK_SUMMON = 10;

//--Lich Special States--
static const int LICH_ICE_ATTACK_COMBO = 1;
static const int LICH_ALLY_ALIVE = 0;
static const int LICH_ALLY_DEAD = 1;

//--Lich Battle States--
static const int LICH_BATTLE_IMMOBILE = -1;
static const int LICH_BATTLE_READY = 0;