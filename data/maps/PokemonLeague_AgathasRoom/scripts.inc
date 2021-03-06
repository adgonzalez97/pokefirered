PokemonLeague_AgathasRoom_MapScripts:: @ 8162810
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_AgathasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_AgathasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_AgathasRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_AgathasRoom_OnFrame
	.byte 0

PokemonLeague_AgathasRoom_OnResume:: @ 8162825
	setvar VAR_0x8004, 2
	call EventScript_1A75D5
	end

PokemonLeague_AgathasRoom_OnLoad:: @ 8162830
	call_if_set FLAG_DEFEATED_AGATHA, EventScript_16284B
	compare VAR_MAP_SCENE_POKEMON_LEAGUE, 3
	call_if_eq EventScript_162845
	end

EventScript_162845:: @ 8162845
	call EventScript_1A759C
	return

EventScript_16284B:: @ 816284B
	call EventScript_1A7538
	return

PokemonLeague_AgathasRoom_OnWarp:: @ 8162851
	map_script_2 VAR_TEMP_1, 0, EventScript_16285B
	.2byte 0

EventScript_16285B:: @ 816285B
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_AgathasRoom_OnFrame:: @ 8162860
	map_script_2 VAR_MAP_SCENE_POKEMON_LEAGUE, 2, EventScript_16286A
	.2byte 0

EventScript_16286A:: @ 816286A
	lockall
	call EventScript_1A751F
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 3
	releaseall
	end

PokemonLeague_AgathasRoom_EventScript_162877:: @ 8162877
	lock
	faceplayer
	famechecker FAMECHECKER_AGATHA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_DEFEATED_AGATHA, EventScript_162911
	famechecker FAMECHECKER_AGATHA, 0
	famechecker FAMECHECKER_AGATHA, 4
	famechecker FAMECHECKER_OAK, 4
	call_if_unset FLAG_SYS_GAME_CLEAR, EventScript_1628E9
	call_if_set FLAG_SYS_GAME_CLEAR, EventScript_1628F2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	call_if_unset FLAG_SYS_CAN_LINK_WITH_RS, EventScript_1628FB
	call_if_set FLAG_SYS_CAN_LINK_WITH_RS, EventScript_162906
	clearflag FLAG_TEMP_5
	goto EventScript_16291B

EventScript_1628E8:: @ 81628E8
	end

EventScript_1628E9:: @ 81628E9
	msgbox gUnknown_817844D
	return

EventScript_1628F2:: @ 81628F2
	msgbox gUnknown_817858D
	return

EventScript_1628FB:: @ 81628FB
	trainerbattle_no_intro TRAINER_ELITE_FOUR_AGATHA, Text_1786D7
	return

EventScript_162906:: @ 8162906
	trainerbattle_no_intro TRAINER_ELITE_FOUR_AGATHA_2, Text_1786D7
	return

EventScript_162911:: @ 8162911
	msgbox gUnknown_8178700
	release
	end

EventScript_16291B:: @ 816291B
	setflag FLAG_DEFEATED_AGATHA
	call EventScript_1A7506
	msgbox gUnknown_8178700
	release
	end
