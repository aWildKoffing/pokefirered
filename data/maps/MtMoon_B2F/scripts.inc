MtMoon_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	.byte 0

MtMoon_B2F_OnTransition::
	call_if_unset FLAG_GOT_DOME_FOSSIL, MtMoon_B2F_EventScript_ShowDomeFossil
	call_if_unset FLAG_GOT_HELIX_FOSSIL, MtMoon_B2F_EventScript_ShowHelixFossil
	end

MtMoon_B2F_EventScript_ShowDomeFossil::
	clearflag FLAG_HIDE_DOME_FOSSIL
	return

MtMoon_B2F_EventScript_ShowHelixFossil::
	clearflag FLAG_HIDE_HELIX_FOSSIL
	return

MtMoon_B2F_EventScript_Miguel::
	trainerbattle_single TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelIntro, MtMoon_B2F_Text_MiguelDefeat
	msgbox MtMoon_B2F_Text_MiguelDefeat, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_DomeFossil::
	lock
	faceplayer
	removeobject LOCALID_DOME_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedDomeFossil, ITEM_DOME_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
	closemessage
	special QuestLog_CutRecording
	delay 5
	playfanfare MUS_OBTAIN_KEY_ITEM
	waitfanfare
	setflag FLAG_GOT_DOME_FOSSIL
	release
	end

MtMoon_B2F_EventScript_HelixFossil::
	lock
	faceplayer
	removeobject LOCALID_HELIX_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedHelixFossil, ITEM_HELIX_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
	closemessage
	special QuestLog_CutRecording
	delay 5
	playfanfare MUS_OBTAIN_KEY_ITEM
	waitfanfare
	setflag FLAG_GOT_HELIX_FOSSIL
	release
	end

MtMoon_B2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Ben::
	trainerbattle_single TRAINER_MT_MOON_BEN, MtMoon_B2F_Text_BenIntro, MtMoon_B2F_Text_BenDefeat
	waitbuttonpress
	giveitem_msg MtMoon_B2F_Text_BenGiveSunStone, ITEM_SUN_STONE
	msgbox MtMoon_B2F_Text_BenAfterGift, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_MOON_BEN
	fadescreen FADE_FROM_BLACK
	setflag FLAG_BEAT_BEN_MT_MOON
	end
