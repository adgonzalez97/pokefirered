SaffronCity_House1_2F_MapScripts:: @ 816EB5C
	.byte 0

SaffronCity_House1_2F_EventScript_16EB5D:: @ 816EB5D
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, 0
	msgbox gUnknown_819B030
	waitmoncry
	release
	end

SaffronCity_House1_2F_EventScript_16EB70:: @ 816EB70
	lock
	msgbox gUnknown_819B071
	release
	end

SaffronCity_House1_2F_EventScript_16EB7B:: @ 816EB7B
	goto_if_questlog EventScript_ReleaseEnd
	special sub_8112364
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_MimicTutor
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq EventScript_16EBB7
	compare VAR_RESULT, FEMALE
	call_if_eq EventScript_16EBC0
	release
	end

EventScript_16EBB7:: @ 816EBB7
	msgbox gUnknown_819AC60
	return

EventScript_16EBC0:: @ 816EBC0
	msgbox gUnknown_819ACF1
	return

SaffronCity_House1_2F_EventScript_16EBC9:: @ 816EBC9
	msgbox gUnknown_819B0D0, MSGBOX_SIGN
	end

SaffronCity_House1_2F_EventScript_16EBD2:: @ 816EBD2
	msgbox gUnknown_819B0A0, MSGBOX_SIGN
	end
