SevenIsland_SevaultCanyon_TanobyKey_MapScripts:: @ 8164DCC
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_SevaultCanyon_TanobyKey_OnTransition
	.byte 0

SevenIsland_SevaultCanyon_TanobyKey_OnTransition:: @ 8164DD2
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND_SEVAULT_CANYON_TANOBY_KEY
	call_if_set FLAG_SYS_UNLOCKED_TANOBY_RUINS, EventScript_164E07
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	end

EventScript_164E07:: @ 8164E07
	setobjectxyperm 1, 7, 2
	setobjectxyperm 2, 4, 4
	setobjectxyperm 3, 10, 4
	setobjectxyperm 4, 5, 6
	setobjectxyperm 5, 9, 6
	setobjectxyperm 6, 5, 8
	setobjectxyperm 7, 9, 8
	return

SevenIsland_SevaultCanyon_TanobyKey_EventScript_164E39:: @ 8164E39
	lockall
	compare VAR_TEMP_1, 100
	goto_if_eq EventScript_164F8A
	call EventScript_164F2E
	setvar VAR_TEMP_1, 100
	compare VAR_TEMP_8, 7
	goto_if_eq EventScript_164F8C
	releaseall
	end

SevenIsland_SevaultCanyon_TanobyKey_EventScript_164E5C:: @ 8164E5C
	lockall
	compare VAR_TEMP_2, 100
	goto_if_eq EventScript_164F8A
	call EventScript_164F2E
	setvar VAR_TEMP_2, 100
	compare VAR_TEMP_8, 7
	goto_if_eq EventScript_164F8C
	releaseall
	end

SevenIsland_SevaultCanyon_TanobyKey_EventScript_164E7F:: @ 8164E7F
	lockall
	compare VAR_TEMP_3, 100
	goto_if_eq EventScript_164F8A
	call EventScript_164F2E
	setvar VAR_TEMP_3, 100
	compare VAR_TEMP_8, 7
	goto_if_eq EventScript_164F8C
	releaseall
	end

SevenIsland_SevaultCanyon_TanobyKey_EventScript_164EA2:: @ 8164EA2
	lockall
	compare VAR_TEMP_4, 100
	goto_if_eq EventScript_164F8A
	call EventScript_164F2E
	setvar VAR_TEMP_4, 100
	compare VAR_TEMP_8, 7
	goto_if_eq EventScript_164F8C
	releaseall
	end

SevenIsland_SevaultCanyon_TanobyKey_EventScript_164EC5:: @ 8164EC5
	lockall
	compare VAR_TEMP_5, 100
	goto_if_eq EventScript_164F8A
	call EventScript_164F2E
	setvar VAR_TEMP_5, 100
	compare VAR_TEMP_8, 7
	goto_if_eq EventScript_164F8C
	releaseall
	end

SevenIsland_SevaultCanyon_TanobyKey_EventScript_164EE8:: @ 8164EE8
	lockall
	compare VAR_TEMP_6, 100
	goto_if_eq EventScript_164F8A
	call EventScript_164F2E
	setvar VAR_TEMP_6, 100
	compare VAR_TEMP_8, 7
	goto_if_eq EventScript_164F8C
	releaseall
	end

SevenIsland_SevaultCanyon_TanobyKey_EventScript_164F0B:: @ 8164F0B
	lockall
	compare VAR_TEMP_7, 100
	goto_if_eq EventScript_164F8A
	call EventScript_164F2E
	setvar VAR_TEMP_7, 100
	compare VAR_TEMP_8, 7
	goto_if_eq EventScript_164F8C
	releaseall
	end

EventScript_164F2E:: @ 8164F2E
	addvar VAR_TEMP_8, 1
	playse SE_TRACK_MOVE
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special Special_ShakeScreen
	delay 60
	return

EventScript_164F51:: @ 8164F51
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 3
	special Special_ShakeScreen
	delay 60
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 12
	setvar VAR_0x8007, 2
	special Special_ShakeScreen
	delay 60
	playse SE_FU_ZUZUZU
	waitse
	return

EventScript_164F8A:: @ 8164F8A
	releaseall
	end

EventScript_164F8C:: @ 8164F8C
	call EventScript_164F51
	msgbox gUnknown_817D31B
	setflag FLAG_SYS_UNLOCKED_TANOBY_RUINS
	releaseall
	end
