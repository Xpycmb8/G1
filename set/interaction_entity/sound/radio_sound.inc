;==============================================================================================
;==============================================================================================
;==============================================================================================
{"sound_rus_arty1_0_wcw"
	{on spawn
		{volumes disable contact}
		{link_sound 	"dust_sound" "hit/radio_arty_support/rus_arty1"} 
		{delay 1	{play_sound 	"dust_sound"}}
		{delay 5 	{spawn "sound_box_rad_arty1_1_wcw" "sound_box"} {delete}}
	}
}
{"sound_rus_arty1_1_wcw"
	{on spawn
		{volumes disable contact}
		{link_sound 	"dust_sound" "hit/radio_arty_support/rus_arty2"} 
		{delay 1	{play_sound 	"dust_sound"}}
		{delay 14 	{spawn "sound_box_rad_arty1_2_wcw" "sound_box"} {delete}}
	}
}
{"sound_rus_arty1_2_wcw"
	{on spawn
		{volumes disable contact}
		{link_sound 	"dust_sound" "hit/radio_arty_support/rus_arty3"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 8 	{delete}}
	}
}
{"shell_arty_radio_1"
	{on spawn
		{ani_play "start"}{delay 3 {delete}}
	}
}
{"shell_arty_spawner"
	{on spawn
		{delay 10 {spawn "shell_arty_radio1_wcw" "rgd-5_granade"} {delete}}
	}
}
;==============================================================================================
;==============================================================================================
;==============================================================================================