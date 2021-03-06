SaffronCity_Gym_MapScripts:: @ 816EDD7
	.byte 0

SaffronCity_Gym_EventScript_16EDD8:: @ 816EDD8
	famechecker FAMECHECKER_SABRINA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_SABRINA, Text_19B53C, Text_19B602, EventScript_16EE0A, NO_MUSIC
	goto_if_unset FLAG_GOT_TM04_FROM_SABRINA, EventScript_16EE3D
	msgbox gUnknown_819B7F2
	release
	end

EventScript_16EE0A:: @ 816EE0A
	famechecker FAMECHECKER_SABRINA, 2
	famechecker FAMECHECKER_SABRINA, 3
	clearflag FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setflag FLAG_DEFEATED_SABRINA
	setflag FLAG_BADGE06_GET
	set_gym_trainers 6
	goto EventScript_16EE3D
	end

EventScript_16EE3D:: @ 816EE3D
	msgbox gUnknown_819B6FA
	checkitemspace ITEM_TM04, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_16EE7E
	giveitem_msg gUnknown_819B7D3, ITEM_TM04
	setflag FLAG_GOT_TM04_FROM_SABRINA
	msgbox gUnknown_819B685
	release
	end

EventScript_16EE7E:: @ 816EE7E
	msgbox gUnknown_819B849
	release
	end

SaffronCity_Gym_EventScript_16EE88:: @ 816EE88
	trainerbattle_single TRAINER_PSYCHIC_JOHAN, Text_19B936, Text_19B957
	msgbox gUnknown_819B96D, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_16EE9F:: @ 816EE9F
	trainerbattle_single TRAINER_PSYCHIC_TYRON, Text_19BA45, Text_19BA9E
	famechecker FAMECHECKER_SABRINA, 5
	msgbox gUnknown_819BAB4, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_16EEC3:: @ 816EEC3
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, Text_19BB49, Text_19BBA1
	msgbox gUnknown_819BBB3, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_16EEDA:: @ 816EEDA
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, Text_19BC57, Text_19BCBC
	msgbox gUnknown_819BCC4, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_16EEF1:: @ 816EEF1
	trainerbattle_single TRAINER_CHANNELER_AMANDA, Text_19B86A, Text_19B8A8
	msgbox gUnknown_819B8B9, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_16EF08:: @ 816EF08
	trainerbattle_single TRAINER_CHANNELER_STACY, Text_19B998, Text_19B9EC
	msgbox gUnknown_819B9F7, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_16EF1F:: @ 816EF1F
	trainerbattle_single TRAINER_CHANNELER_TASHA, Text_19BAE8, Text_19BB0D
	msgbox gUnknown_819BB1F, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_16EF36:: @ 816EF36
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SABRINA, EventScript_16EF4B
	msgbox gUnknown_819BCF6
	release
	end

EventScript_16EF4B:: @ 816EF4B
	msgbox gUnknown_819BDBB
	release
	end

SaffronCity_Gym_EventScript_16EF55:: @ 816EF55
	lockall
	goto_if_set FLAG_BADGE06_GET, EventScript_16EF69
	msgbox gUnknown_819BDFE
	releaseall
	end

EventScript_16EF69:: @ 816EF69
	msgbox gUnknown_819BE37
	releaseall
	end
