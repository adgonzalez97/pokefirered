SixIsland_DottedHole_1F_MapScripts:: @ 8164182
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_DottedHole_1F_OnTransition
	.byte 0

SixIsland_DottedHole_1F_OnTransition:: @ 8164188
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_DOTTED_HOLE_1F
	end

SixIsland_DottedHole_B1F_EventScript_16418C:: @ 816418C
	lockall
	braillemessage gUnknown_81A9288
	waitbuttonpress
	releaseall
	end

SixIsland_DottedHole_B4F_EventScript_164195:: @ 8164195
	lockall
	braillemessage gUnknown_81A928B
	waitbuttonpress
	releaseall
	end

SixIsland_DottedHole_B3F_EventScript_16419E:: @ 816419E
	lockall
	braillemessage gUnknown_81A9290
	waitbuttonpress
	releaseall
	end

SixIsland_DottedHole_B2F_EventScript_1641A7:: @ 81641A7
	lockall
	braillemessage gUnknown_81A9296
	waitbuttonpress
	releaseall
	end
