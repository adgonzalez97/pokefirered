CinnabarIsland_PokemonCenter_1F_MapScripts:: @ 816E8D7
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CinnabarIsland_PokemonCenter_1F_OnTransition:: @ 816E8E2
	setrespawn SPAWN_CINNABAR_ISLAND
	end

CinnabarIsland_PokemonCenter_1F_EventScript_16E8E6:: @ 816E8E6
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

CinnabarIsland_PokemonCenter_1F_EventScript_16E8EF:: @ 816E8EF
	msgbox gUnknown_819A5BE, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_16E8F8:: @ 816E8F8
	msgbox gUnknown_819A4F8, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_16E901:: @ 816E901
	msgbox gUnknown_819A6B1, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_16E90A:: @ 816E90A
	lock
	faceplayer
	msgbox gUnknown_819A725, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_16E9A5
	msgbox gUnknown_819A785
	closemessage
	playbgm MUS_ANNAI, 1
	savebgm MUS_ANNAI
	setflag FLAG_SPECIAL_FLAG_0x4001
	setflag FLAG_HIDE_CINNABAR_POKECENTER_BILL
	delay 20
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_16E96F
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_16E981
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_16E993
	removeobject 7
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_2, 1
	clearflag FLAG_HIDE_CINNABAR_BILL
	warp MAP_CINNABAR_ISLAND, 255, 14, 11
	waitstate
	release
	end

EventScript_16E96F:: @ 816E96F
	applymovement 7, Movement_16E9AF
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16E9B9
	waitmovement 0
	return

EventScript_16E981:: @ 816E981
	applymovement 7, Movement_16E9C3
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16E9CF
	waitmovement 0
	return

EventScript_16E993:: @ 816E993
	applymovement 7, Movement_16E9AF
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16E9DE
	waitmovement 0
	return

EventScript_16E9A5:: @ 816E9A5
	msgbox gUnknown_819A766
	release
	end

Movement_16E9AF:: @ 816E9AF
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	delay_8
	set_invisible
	step_end

Movement_16E9B9:: @ 816E9B9
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_16
	walk_down
	step_end

Movement_16E9C3:: @ 816E9C3
	walk_up
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	delay_8
	set_invisible
	step_end

Movement_16E9CF:: @ 816E9CF
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_8
	walk_down
	delay_8
	set_invisible
	step_end

Movement_16E9DE:: @ 816E9DE
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_16
	walk_down
	step_end
