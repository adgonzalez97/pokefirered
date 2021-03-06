PalletTown_MapScripts:: @ 816545A
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
	.byte 0

PalletTown_OnTransition:: @ 8165465
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
	call_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, EventScript_165488
	compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 0
	call_if_eq EventScript_1654A8
	compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	call_if_eq EventScript_1654A2
	end

EventScript_165488:: @ 8165488
	goto_if_unset FLAG_PALLET_TOWN_LADY_MOVED_FROM_SIGN, EventScript_Return
	compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	goto_if_ge EventScript_Return
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	return

EventScript_1654A2:: @ 81654A2
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
	return

EventScript_1654A8:: @ 81654A8
	goto_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, EventScript_1654BD
	setobjectxyperm 1, 5, 15
	setobjectmovementtype 1, 7
	return

EventScript_1654BD:: @ 81654BD
	setobjectxyperm 1, 12, 2
	setobjectmovementtype 1, 8
	setvar VAR_TEMP_2, 1
	return

PalletTown_OnFrame:: @ 81654CE
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, EventScript_1654D8
	.2byte 0

EventScript_1654D8:: @ 81654D8
	lockall
	textcolor 0
	setobjectxyperm 3, 14, 14
	setobjectmovementtype 3, 9
	addobject 3
	applymovement 3, Movement_1655AF
	waitmovement 0
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, EventScript_1655A1
	msgbox gUnknown_817D8BF
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, Special_GetPokedexCount
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	getnumberstring 0, VAR_0x8008
	getnumberstring 1, VAR_0x8009
	compare VAR_0x8009, 60
	goto_if_lt EventScript_165593
	msgbox gUnknown_817D9AA
	closemessage
	playbgm MUS_ANNAI, 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_1655DD
	applymovement 3, Movement_1655CC
	waitmovement 0
	opendoor 16, 13
	waitdooranim
	applymovement 3, Movement_16572E
	applymovement OBJ_EVENT_ID_PLAYER, Movement_165758
	waitmovement 0
	closedoor 16, 13
	waitdooranim
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 255, 6, 12
	waitstate
	releaseall
	end

EventScript_16557E:: @ 816557E
	closemessage
	applymovement 3, Movement_1655BE
	waitmovement 0
	removeobject 3
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
	releaseall
	end

EventScript_165593:: @ 8165593
	msgbox gUnknown_817D925
	goto EventScript_16557E
	end

EventScript_1655A1:: @ 81655A1
	msgbox gUnknown_817DA16
	goto EventScript_16557E
	end

Movement_1655AF:: @ 81655AF
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

Movement_1655BE:: @ 81655BE
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

Movement_1655CC:: @ 81655CC
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

Movement_1655DD:: @ 81655DD
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PalletTown_EventScript_1655ED:: @ 81655ED
	lockall
	setvar VAR_TEMP_1, 0
	goto EventScript_165605
	end

PalletTown_EventScript_1655F9:: @ 81655F9
	lockall
	setvar VAR_TEMP_1, 1
	goto EventScript_165605
	end

EventScript_165605:: @ 8165605
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	textcolor 0
	delay 30
	playbgm MUS_OHKIDO, 0
	message Text_17D72C
	waitmessage
	delay 85
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ExclamationMark
	waitmovement 0
	delay 30
	addobject 3
	compare VAR_TEMP_1, 0
	call_if_eq EventScript_1656B8
	compare VAR_TEMP_1, 1
	call_if_eq EventScript_1656C3
	delay 30
	msgbox gUnknown_817D74A
	closemessage
	delay 30
	compare VAR_TEMP_1, 0
	call_if_eq EventScript_1656CE
	compare VAR_TEMP_1, 1
	call_if_eq EventScript_1656E0
	opendoor 16, 13
	waitdooranim
	applymovement 3, Movement_16572E
	applymovement OBJ_EVENT_ID_PLAYER, Movement_165758
	waitmovement 0
	closedoor 16, 13
	waitdooranim
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
	setflag FLAG_SPECIAL_FLAG_0x4001
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 255, 6, 12
	waitstate
	releaseall
	end

EventScript_1656B8:: @ 81656B8
	applymovement 3, Movement_1656F2
	waitmovement 0
	return

EventScript_1656C3:: @ 81656C3
	applymovement 3, Movement_1656FB
	waitmovement 0
	return

EventScript_1656CE:: @ 81656CE
	applymovement 3, Movement_165705
	applymovement OBJ_EVENT_ID_PLAYER, Movement_165731
	waitmovement 0
	return

EventScript_1656E0:: @ 81656E0
	applymovement 3, Movement_165719
	applymovement OBJ_EVENT_ID_PLAYER, Movement_165744
	waitmovement 0
	return

Movement_1656F2:: @ 81656F2
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

Movement_1656FB:: @ 81656FB
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

Movement_165705:: @ 8165705
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

Movement_165719:: @ 8165719
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

Movement_16572E:: @ 816572E
	walk_up
	set_invisible
	step_end

Movement_165731:: @ 8165731
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Movement_165744:: @ 8165744
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Movement_165758:: @ 8165758
	walk_right
	walk_up
	set_invisible
	step_end

PalletTown_EventScript_16575C:: @ 816575C
	lock
	compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
	goto_if_eq EventScript_1657ED
	compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	goto_if_eq EventScript_165815
	compare VAR_TEMP_2, 1
	goto_if_eq EventScript_1658C2
	goto_if_set FLAG_TEMP_2, EventScript_165801
	msgbox gUnknown_81B1C8B
	applymovement 1, Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement 1, Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Movement_Delay48
	waitmovement 0
	msgbox gUnknown_81B1C9F
	closemessage
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_1657D7
	compare VAR_FACING, DIR_EAST
	call_if_ne EventScript_1657E2
	moveobjectoffscreen 1
	setflag FLAG_TEMP_2
	release
	end

EventScript_1657D7:: @ 81657D7
	applymovement 1, Movement_165829
	waitmovement 0
	return

EventScript_1657E2:: @ 81657E2
	applymovement 1, Movement_16582C
	waitmovement 0
	return

EventScript_1657ED:: @ 81657ED
	applymovement 1, Movement_FacePlayer
	waitmovement 0
	msgbox gUnknown_817D7C8
	release
	end

EventScript_165801:: @ 8165801
	applymovement 1, Movement_FacePlayer
	waitmovement 0
	msgbox gUnknown_81B1CAF
	release
	end

EventScript_165815:: @ 8165815
	applymovement 1, Movement_FacePlayer
	waitmovement 0
	msgbox gUnknown_81B1CEC
	release
	end

Movement_165829:: @ 8165829
	walk_right
	walk_in_place_fastest_left
	step_end

Movement_16582C:: @ 816582C
	walk_left
	walk_in_place_fastest_right
	step_end

PalletTown_EventScript_16582F:: @ 816582F
	msgbox gUnknown_817D80D, MSGBOX_NPC
	end

PalletTown_EventScript_165838:: @ 8165838
	lockall
	famechecker FAMECHECKER_OAK, 0
	msgbox gUnknown_817D866
	releaseall
	end

PalletTown_EventScript_165850:: @ 8165850
	msgbox gUnknown_817D87F, MSGBOX_SIGN
	end

PalletTown_EventScript_165859:: @ 8165859
	msgbox gUnknown_817D88A, MSGBOX_SIGN
	end

PalletTown_EventScript_165862:: @ 8165862
	msgbox gUnknown_817D895, MSGBOX_SIGN
	end

PalletTown_EventScript_16586B:: @ 816586B
	lockall
	msgbox gUnknown_81B1CC1
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	releaseall
	end

PalletTown_EventScript_16587B:: @ 816587B
	lockall
	applymovement 1, Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	call EventScript_165894
	releaseall
	end

EventScript_165894:: @ 8165894
	textcolor 1
	msgbox gUnknown_81B1D0B
	closemessage
	delay 20
	textcolor 3
	setflag FLAG_PALLET_TOWN_LADY_MOVED_FROM_SIGN
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	setvar VAR_TEMP_2, 0
	special sub_80699E0
	special sub_80699BC
	signmsg
	msgbox gUnknown_81B1D51
	normalmsg
	return

EventScript_1658C2:: @ 81658C2
	applymovement 1, Movement_FacePlayer
	waitmovement 0
	call EventScript_165894
	release
	end
