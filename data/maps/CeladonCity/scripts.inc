CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	.byte 0

CeladonCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CELADON_CITY
	end

CeladonCity_EventScript_LittleGirl::
	msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	lock
	msgbox CeladonCity_Text_GymIsGreatFullOfWomen
	release
	end

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_EventScript_SoftboiledTutor::
	goto EventScript_SoftboiledTutor
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_CELADON_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_CELADON_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_EventScript_SilphCoScientist::
	msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
	end

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_ERIKA, 0
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymEntrance::
	lock
	applymovement LOCALID_CELADON_GYMKEEPER, CeladonCity_Mov_GuardHalt
	applymovement LOCALID_PLAYER, CeladonCity_Mov_PlayerStepBack
	msgbox CeladonCity_Text_GymGateKeeper_Halt, MSGBOX_DEFAULT
	delay 20
	checkgympartylimit TRAINER_LEADER_ERIKA
	compare VAR_RESULT, 1
	goto_if_eq CeladonCity_GymGateKeeperAllowEntry
	// else block the player from entering
	msgbox CeladonCity_Text_GymGateKeeper_Deny, MSGBOX_DEFAULT
	applymovement LOCALID_CELADON_GYMKEEPER, CeladonCity_Mov_GuardReset
	waitmovement LOCALID_CELADON_GYMKEEPER
	release
	end

CeladonCity_Mov_GuardFacePlayer::
	faceplayer
	step_end
	
CeladonCity_GymGateKeeperAllowEntry::
	msgbox CeladonCity_Text_GymGateKeeper_Allow, MSGBOX_DEFAULT
	applymovement LOCALID_CELADON_GYMKEEPER, CeladonCity_Mov_GuardReset
	waitmovement LOCALID_CELADON_GYMKEEPER
	applymovement LOCALID_PLAYER, CeladonCity_Mov_PlayerEnterGym
	waitmovement LOCALID_PLAYER
	release
	end

CeladonCity_Mov_GuardHalt:
    face_left
    walk_left
	face_down
    step_end

CeladonCity_Mov_PlayerStepBack:
    walk_down
	face_up
    step_end

CeladonCity_Mov_GuardReset::
	face_right
    walk_right
	face_down
	step_end

CeladonCity_Mov_PlayerEnterGym::
	walk_up
	step_end
