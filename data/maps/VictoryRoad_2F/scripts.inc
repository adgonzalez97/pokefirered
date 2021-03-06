VictoryRoad_2F_MapScripts:: @ 8160F92
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
	.byte 0

VictoryRoad_2F_OnLoad:: @ 8160F98
	compare VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
	call_if_ne EventScript_160FAF
	compare VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
	call_if_ne EventScript_160FC2
	end

EventScript_160FAF:: @ 8160FAF
	setmetatile 13, 10, 775, 1
	setmetatile 13, 11, 791, 1
	return

EventScript_160FC2:: @ 8160FC2
	setmetatile 33, 16, 775, 1
	setmetatile 33, 17, 791, 1
	return

VictoryRoad_2F_EventScript_160FD5:: @ 8160FD5
	lockall
	compare VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
	goto_if_eq EventScript_161004
	setmetatile 13, 10, 721, 0
	setmetatile 13, 11, 737, 0
	playse SE_RU_GASYAN
	special DrawWholeMapView
	waitse
	moveobjectoffscreen 11
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
	releaseall
	end

EventScript_161004:: @ 8161004
	releaseall
	end

VictoryRoad_2F_EventScript_161006:: @ 8161006
	lockall
	compare VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
	goto_if_eq EventScript_161035
	setmetatile 33, 16, 721, 0
	setmetatile 33, 17, 737, 0
	playse SE_RU_GASYAN
	special DrawWholeMapView
	waitse
	moveobjectoffscreen 12
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
	releaseall
	end

EventScript_161035:: @ 8161035
	releaseall
	end

VictoryRoad_2F_EventScript_161037:: @ 8161037
	trainerbattle_single TRAINER_POKEMANIAC_DAWSON, Text_1747EF, Text_17482C
	msgbox gUnknown_817483E, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_16104E:: @ 816104E
	trainerbattle_single TRAINER_BLACK_BELT_DAISUKE, Text_174877, Text_1748B4
	msgbox gUnknown_81748BB, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_161065:: @ 8161065
	trainerbattle_single TRAINER_JUGGLER_NELSON, Text_1748EE, Text_17491B
	msgbox gUnknown_8174927, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_16107C:: @ 816107C
	trainerbattle_single TRAINER_JUGGLER_GREGORY, Text_174995, Text_1749B0
	msgbox gUnknown_81749BB, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_161093:: @ 8161093
	trainerbattle_single TRAINER_TAMER_VINCENT, Text_174942, Text_17495A
	msgbox gUnknown_8174969, MSGBOX_AUTOCLOSE
	end
