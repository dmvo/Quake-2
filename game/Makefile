CFLAGS = -KPIC -m32

GAMELIB=game.so

GAME_OBJS = \
	q_shared.o \
	g_ai.o \
	p_client.o \
	g_cmds.o \
	g_svcmds.o \
	g_chase.o \
	g_combat.o \
	g_func.o \
	g_items.o \
	g_main.o \
	g_misc.o \
	g_monster.o \
	g_phys.o \
	g_save.o \
	g_spawn.o \
	g_target.o \
	g_trigger.o \
	g_turret.o \
	g_utils.o \
	g_weapon.o \
	m_actor.o \
	m_berserk.o \
	m_boss2.o \
	m_boss3.o \
	m_boss31.o \
	m_boss32.o \
	m_brain.o \
	m_chick.o \
	m_flipper.o \
	m_float.o \
	m_flyer.o \
	m_gladiator.o \
	m_gunner.o \
	m_hover.o \
	m_infantry.o \
	m_insane.o \
	m_medic.o \
	m_move.o \
	m_mutant.o \
	m_parasite.o \
	m_soldier.o \
	m_supertank.o \
	m_tank.o \
	p_hud.o \
	p_trail.o \
	p_view.o \
	p_weapon.o \
	m_flash.o \

all: $(GAME_OBJS)
	$(CC) -shared -o $(GAMELIB) $(GAME_OBJS)

clean:
	-rm -rf $(GAME_OBJS) *~ game.so
