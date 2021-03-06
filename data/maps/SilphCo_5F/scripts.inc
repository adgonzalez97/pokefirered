SilphCo_5F_MapScripts:: @ 81617BE
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_5F_OnLoad
	.byte 0

SilphCo_5F_OnLoad:: @ 81617C4
	call_if_unset FLAG_SILPH_5F_DOOR_1, EventScript_Close5FDoor1
	call_if_unset FLAG_SILPH_5F_DOOR_2, EventScript_Close5FDoor2
	call_if_unset FLAG_SILPH_5F_DOOR_3, EventScript_Close5FDoor3
	end

SilphCo_5F_EventScript_1617E0:: @ 81617E0
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_ge EventScript_1617F7
	msgbox gUnknown_8175B70
	release
	end

EventScript_1617F7:: @ 81617F7
	msgbox gUnknown_8175BB3
	release
	end

SilphCo_5F_EventScript_161801:: @ 8161801
	msgbox gUnknown_8175D89, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_16180A:: @ 816180A
	msgbox gUnknown_8175DE0, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_161813:: @ 8161813
	msgbox gUnknown_8175E28, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_16181C:: @ 816181C
	msgbox gUnknown_8175E80, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_161825:: @ 8161825
	trainerbattle_single TRAINER_SCIENTIST_BEAU, Text_175C40, Text_175C6D
	msgbox gUnknown_8175C7D, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_16183C:: @ 816183C
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, Text_175BE5, Text_175C09
	msgbox gUnknown_8175C0F, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_161853:: @ 8161853
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, Text_175D28, Text_175D4B
	msgbox gUnknown_8175D59, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_16186A:: @ 816186A
	trainerbattle_single TRAINER_JUGGLER_DALTON, Text_175CBD, Text_175CEB
	msgbox gUnknown_8175CF9, MSGBOX_AUTOCLOSE
	end
