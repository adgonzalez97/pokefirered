CeladonCity_DepartmentStore_4F_MapScripts:: @ 816BBEE
	.byte 0

CeladonCity_DepartmentStore_4F_EventScript_16BBEF:: @ 816BBEF
	msgbox gUnknown_8195A68, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_16BBF8:: @ 816BBF8
	msgbox gUnknown_8195AC9, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_16BC01:: @ 816BC01
	msgbox gUnknown_8195B5B, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_4F_EventScript_16BC0A:: @ 816BC0A
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart Items_16BC30
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
Items_16BC30:: @ 816BC30
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_NONE
	release
	end
