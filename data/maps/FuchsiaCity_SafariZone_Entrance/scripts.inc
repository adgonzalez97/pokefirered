FuchsiaCity_SafariZone_Entrance_MapScripts:: @ 816D2A8
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZone_Entrance_OnFrame
	.byte 0

FuchsiaCity_SafariZone_Entrance_OnFrame:: @ 816D2AE
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1, EventScript_16D2F2
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2, EventScript_16D312
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3, EventScript_16D2C8
	.2byte 0

EventScript_16D2C8:: @ 816D2C8
	lockall
	textcolor 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16D36A
	waitmovement 0
	msgbox gUnknown_8197E85
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16D367
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

EventScript_16D2F2:: @ 816D2F2
	lockall
	textcolor 0
	msgbox gUnknown_8197E85
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16D362
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

EventScript_16D312:: @ 816D312
	lockall
	textcolor 0
	msgbox gUnknown_8197E1A, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_16D345
	msgbox gUnknown_8197E48
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16D362
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

EventScript_16D345:: @ 816D345
	msgbox gUnknown_8197E7A
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16D365
	waitmovement 0
	warp MAP_SAFARI_ZONE_CENTER, 255, 26, 30
	waitstate
	end

Movement_16D362:: @ 816D362
	walk_down
	walk_down
	step_end

Movement_16D365:: @ 816D365
	walk_up
	step_end

Movement_16D367:: @ 816D367
	walk_down
	walk_down
	step_end

Movement_16D36A:: @ 816D36A
	walk_down
	delay_8
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_16D36D:: @ 816D36D
	lockall
	setvar VAR_TEMP_2, 0
	goto EventScript_16D391
	end

FuchsiaCity_SafariZone_Entrance_EventScript_16D379:: @ 816D379
	lockall
	setvar VAR_TEMP_2, 1
	goto EventScript_16D391
	end

FuchsiaCity_SafariZone_Entrance_EventScript_16D385:: @ 816D385
	lockall
	setvar VAR_TEMP_2, 2
	goto EventScript_16D391
	end

EventScript_16D391:: @ 816D391
	textcolor 0
	msgbox gUnknown_8197C6B
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestRight
	waitmovement 0
	showmoneybox 0, 0, 0
	msgbox gUnknown_8197C87, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_16D3CA
	msgbox gUnknown_8197DE9
	goto EventScript_16D49A
	end

EventScript_16D3CA:: @ 816D3CA
	call EventScript_16D462
	checkmoney 500, 0
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_16D48C
	removemoney 500, 0
	updatemoneybox 0, 0, 0
	msgbox gUnknown_8197D07
	textcolor 3
	playfanfare MUS_FANFA1
	message Text_197D50
	waitfanfare
	call EventScript_1A6675
	msgbox gUnknown_8197D80
	closemessage
	hidemoneybox 0, 0
	compare VAR_TEMP_2, 0
	call_if_eq EventScript_16D44C
	compare VAR_TEMP_2, 1
	call_if_eq EventScript_16D441
	compare VAR_TEMP_2, 2
	call_if_eq EventScript_16D457
	special EnterSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2
	warp MAP_SAFARI_ZONE_CENTER, 255, 26, 30
	waitstate
	end

EventScript_16D441:: @ 816D441
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16D4AF
	waitmovement 0
	return

EventScript_16D44C:: @ 816D44C
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16D4AC
	waitmovement 0
	return

EventScript_16D457:: @ 816D457
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16D4B3
	waitmovement 0
	return

EventScript_16D462:: @ 816D462
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EventScript_Return
	specialvar VAR_RESULT, Special_IsThereRoomInAnyBoxForMorePokemon
	compare VAR_RESULT, 1
	goto_if_eq EventScript_Return
	msgbox gUnknown_81BFEAC
	goto EventScript_16D49A
	end

EventScript_16D48C:: @ 816D48C
	msgbox gUnknown_8197E02
	goto EventScript_16D49A
	end

EventScript_16D49A:: @ 816D49A
	closemessage
	hidemoneybox 0, 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_16D4AA
	waitmovement 0
	releaseall
	end

Movement_16D4AA:: @ 816D4AA
	walk_down
	step_end

Movement_16D4AC:: @ 816D4AC
	walk_up
	walk_up
	step_end

Movement_16D4AF:: @ 816D4AF
	walk_up
	walk_left
	walk_up
	step_end

Movement_16D4B3:: @ 816D4B3
	walk_up
	walk_right
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_16D4B7:: @ 816D4B7
	lock
	faceplayer
	msgbox gUnknown_8197EB0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_16D4D6
	msgbox gUnknown_819809E
	release
	end

EventScript_16D4D6:: @ 816D4D6
	msgbox gUnknown_8197EE3
	release
	end
