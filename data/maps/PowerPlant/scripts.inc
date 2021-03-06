PowerPlant_MapScripts:: @ 8163764
	map_script MAP_SCRIPT_ON_RESUME, PowerPlant_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_OnTransition
	.byte 0

PowerPlant_OnResume:: @ 816376F
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, EventScript_163779
	end

EventScript_163779:: @ 8163779
	specialvar VAR_RESULT, Special_GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

PowerPlant_OnTransition:: @ 816378D
	setworldmapflag FLAG_WORLD_MAP_POWER_PLANT
	call_if_unset FLAG_FOUGHT_ZAPDOS, EventScript_1637AC
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1, EventScript_1637B0
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2, EventScript_1637B4
	end

EventScript_1637AC:: @ 81637AC
	clearflag FLAG_HIDE_ZAPDOS
	return

EventScript_1637B0:: @ 81637B0
	clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_1
	return

EventScript_1637B4:: @ 81637B4
	clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_2
	return

PowerPlant_EventScript_1637B8:: @ 81637B8
	goto_if_questlog EventScript_ReleaseEnd
	special sub_8112364
	lock
	faceplayer
	setwildbattle SPECIES_ZAPDOS, 50, ITEM_NONE
	waitse
	playmoncry SPECIES_ZAPDOS, 2
	message Text_1A6448
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_EXEYE, 0
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special Special_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, Special_GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_16381B
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_163824
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_163824
	setflag FLAG_FOUGHT_ZAPDOS
	release
	end

EventScript_16381B:: @ 816381B
	setflag FLAG_FOUGHT_ZAPDOS
	goto EventScript_RemoveStaticMon
	end

EventScript_163824:: @ 8163824
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto EventScript_MonFlewAway
	end

PowerPlant_EventScript_16382F:: @ 816382F
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 34, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special sub_8112364
	specialvar VAR_RESULT, Special_GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_163884
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_163884
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_163884
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
	release
	end

EventScript_163884:: @ 8163884
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_16388D:: @ 816388D
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 34, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special sub_8112364
	specialvar VAR_RESULT, Special_GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_1638E2
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_1638E2
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_1638E2
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
	release
	end

EventScript_1638E2:: @ 81638E2
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
	goto EventScript_RemoveStaticMon
	end
