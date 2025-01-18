;==============================================================================================
;==============================================================================================
{"dust_medium_sound" 		{on spawn {volumes disable contact} {link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust"}  		{delay 2 {play_sound "dust_sound"}} {delay 8 {delete}}}}
{"dust_big_sound" 			{on spawn {volumes disable contact} {link_sound "dust_sound" "world_dust_sound_wcw/ex_big_dust"} 		{delay 2 {play_sound "dust_sound"}} {delay 8 {delete}}}}
{"dust_rifle_sound" 			{on spawn {volumes disable contact} {link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_rifle"} 	{delay 2 {play_sound "dust_sound"}} {delay 6 {delete}}}}
;==============================================================================================
{"dust_dead_big_sound"		{on spawn {link_sound "dust_sound" "world_dust_sound_wcw/ex_dead_tank_dust"} 	{delay 2	{play_sound "dust_sound"}}{delay 8 {delete}}}}
{"dust_dead_medium_sound"		{on spawn {link_sound "dust_sound" "world_dust_sound_wcw/ex_dead_bmp_dust"} 	{delay 2	{play_sound "dust_sound"}}{delay 8 {delete}}}}
{"dust_dead_small_sound"		{on spawn {link_sound "dust_sound" "world_dust_sound_wcw/ex_dead_car_dust"} 	{delay 2	{play_sound "dust_sound"}}{delay 8 {delete}}}}
;==============================================================================================

{"dust_tank1_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_tank1"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 5 	{delete}}
	}
}
{"dust_tank2_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_tank2"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 5 	{delete}}
	}
}
{"dust_tank3_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_tank3"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 5 	{delete}}
	}
}
;==============================================================================================
;==============================================================================================
;==============================================================================================
{"dust_bmp1_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_bmp1"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 5 	{delete}}
	}
}
{"dust_bmp2_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_bmp2"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 5 	{delete}}
	}
}
;==============================================================================================
;==============================================================================================
;==============================================================================================
{"dust_mgun_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_mgun1"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 5 	{delete}}
	}
}
{"dust_mgun2_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_mgun2"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 5 	{delete}}
	}
}
;==============================================================================================
;==============================================================================================
;==============================================================================================
{"dust_hely1_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_heli_gun"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 5 	{delete}}
	}
}
{"dust_hely2_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_heli_gun2"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 5 	{delete}}
	}
}
;==============================================================================================
;==============================================================================================
;==============================================================================================
{"dust_zsu_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_zsu"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 6 	{delete}}
	}
}
{"dust_zsu2_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_zsu2"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 4 	{delete}}
	}
}
;==============================================================================================
;==============================================================================================
;==============================================================================================
{"dust_vulcan_sound"
	{on spawn
		{link_sound "dust_sound" "world_dust_sound_wcw/ex_medium_dust_vulcan"} 
		{delay 2	{play_sound 	"dust_sound"}}
		{delay 5 	{delete}}
	}
}
;==============================================================================================
;==============================================================================================
;==============================================================================================





;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "tank1_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on fire "mgun"
		{if not tagged "dust_mgun1" {call "dust_sound1_mgun"}}
	}
	{on fire "mgun2"
		{if not tagged "dust_mgun2" {call "dust_sound2_mgun"}}
	}
	{on fire "mgun3"
		{if not tagged "dust_mgun3" {call "dust_sound3_mgun"}}
	}

	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_tank1" "basis" x} {delay 4 {tags remove "dust_gun"}}}
	}
	{on "dust_sound1_mgun"
		{tags add "dust_mgun1"}
		{if tagged "dust_mgun1" {spawn "s_box_mgun1" "basis" x} {delay 2 {tags remove "dust_mgun1"}}}
	}
	{on "dust_sound2_mgun"
		{tags add "dust_mgun2"}
		{if tagged "dust_mgun2" {spawn "s_box_mgun2" "basis" x} {delay 2 {tags remove "dust_mgun2"}}}
	}
	{on "dust_sound3_mgun"
		{tags add "dust_mgun3"}
		{if tagged "dust_mgun3" {spawn "s_box_mgun1" "basis" x} {delay 2 {tags remove "dust_mgun3"}}}
	}
)
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "tank2_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on fire "mgun"
		{if not tagged "dust_mgun1" {call "dust_sound1_mgun"}}
	}
	{on fire "mgun2"
		{if not tagged "dust_mgun2" {call "dust_sound2_mgun"}}
	}
	{on fire "mgun3"
		{if not tagged "dust_mgun3" {call "dust_sound3_mgun"}}
	}

	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_tank2" "basis" x} {delay 4 {tags remove "dust_gun"}}}
	}
	{on "dust_sound1_mgun"
		{tags add "dust_mgun1"}
		{if tagged "dust_mgun1" {spawn "s_box_mgun1" "basis" x} {delay 2 {tags remove "dust_mgun1"}}}
	}
	{on "dust_sound2_mgun"
		{tags add "dust_mgun2"}
		{if tagged "dust_mgun2" {spawn "s_box_mgun2" "basis" x} {delay 2 {tags remove "dust_mgun2"}}}
	}
	{on "dust_sound3_mgun"
		{tags add "dust_mgun3"}
		{if tagged "dust_mgun3" {spawn "s_box_mgun1" "basis" x} {delay 2 {tags remove "dust_mgun3"}}}
	}
)
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "tank3_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on fire "mgun"
		{if not tagged "dust_mgun1" {call "dust_sound1_mgun"}}
	}
	{on fire "mgun2"
		{if not tagged "dust_mgun2" {call "dust_sound2_mgun"}}
	}
	{on fire "mgun3"
		{if not tagged "dust_mgun3" {call "dust_sound3_mgun"}}
	}

	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_tank3" "basis" x} {delay 4 {tags remove "dust_gun"}}}
	}
	{on "dust_sound1_mgun"
		{tags add "dust_mgun1"}
		{if tagged "dust_mgun1" {spawn "s_box_mgun1" "basis" x} {delay 2 {tags remove "dust_mgun1"}}}
	}
	{on "dust_sound2_mgun"
		{tags add "dust_mgun2"}
		{if tagged "dust_mgun2" {spawn "s_box_mgun2" "basis" x} {delay 2 {tags remove "dust_mgun2"}}}
	}
	{on "dust_sound3_mgun"
		{tags add "dust_mgun3"}
		{if tagged "dust_mgun3" {spawn "s_box_mgun1" "basis" x} {delay 2 {tags remove "dust_mgun3"}}}
	}
)
{"bmp-1_wcw"	("tank3_dust_wcw")}
{"bmp-1k_wcw"	("tank3_dust_wcw")}
{"bmp-1p_wcw"	("tank3_dust_wcw")}
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "bmp1_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on fire "mgun2"
		{if not tagged "dust_mgun1" {call "dust_sound1_mgun"}}
	}
	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_bmp1" "basis" x} {delay 0.5 {tags remove "dust_gun"}}}
	}
	{on "dust_sound1_mgun"
		{tags add "dust_mgun1"}
		{if tagged "dust_mgun1" {spawn "s_box_mgun2" "basis" x} {delay 2 {tags remove "dust_mgun1"}}}
	}
)
{"m2a2_bredly_wcw"	("bmp1_dust_wcw")}
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "bmp2_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on fire "mgun2"
		{if not tagged "dust_mgun1" {call "dust_sound1_mgun"}}
	}
	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_bmp2" "basis" x} {delay 0.5 {tags remove "dust_gun"}}}
	}
	{on "dust_sound1_mgun"
		{tags add "dust_mgun1"}
		{if tagged "dust_mgun1" {spawn "s_box_mgun2" "basis" x} {delay 2 {tags remove "dust_mgun1"}}}
	}
)
{"lav25_wcw"		("bmp2_dust_wcw")}
{"btr80a_wcw"		("bmp2_dust_wcw")}
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "bmp3_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on fire "mgun2"
		{if not tagged "dust_mgun1" {call "dust_sound1_mgun"}}
	}

	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_hely1" "basis" x} {delay 2 {tags remove "dust_gun"}}}
	}
	{on "dust_sound1_mgun"
		{tags add "dust_mgun1"}
		{if tagged "dust_mgun1" {spawn "s_box_mgun2" "basis" x} {delay 2 {tags remove "dust_mgun1"}}}
	}
)
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "zsu1_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_zsu1" "basis" x} {delay 3 {tags remove "dust_gun"}}}
	}
)
{"2c6_tunguska_wcw"	("zsu1_dust_wcw")}
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "zsu2_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_zsu2" "basis" x} {delay 3 {tags remove "dust_gun"}}}
	}
)
{"zu-23-2_wcw"		("zsu2_dust_wcw")}
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "vulcan_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on fire "gun2"
		{if not tagged "dust_gun2" {call "dust_sound2_gun"}}
	}
	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_vulcan" "basis" x} {delay 3 {tags remove "dust_gun"}}}
	}
	{on "dust_sound2_gun"
		{tags add "dust_gun2"}
		{if tagged "dust_gun2" {spawn "s_box_vulcan" "basis" x} {delay 3 {tags remove "dust_gun2"}}}
	}
)
{"m163_vads_wcw"	("vulcan_dust_wcw")}
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "mgun_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on fire "mgun"
		{if not tagged "dust_mgun1" {call "dust_sound1_mgun"}}
	}
	{on fire "mgun2"
		{if not tagged "dust_mgun2" {call "dust_sound2_mgun"}}
	}
	{on fire "mgun3"
		{if not tagged "dust_mgun3" {call "dust_sound3_mgun"}}
	}

	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_mgun1" "basis" x} {delay 3 {tags remove "dust_gun"}}}
	}
	{on "dust_sound1_mgun"
		{tags add "dust_mgun1"}
		{if tagged "dust_mgun1" {spawn "s_box_mgun1" "basis" x} {delay 3 {tags remove "dust_mgun1"}}}
	}
	{on "dust_sound2_mgun"
		{tags add "dust_mgun2"}
		{if tagged "dust_mgun2" {spawn "s_box_mgun2" "basis" x} {delay 3 {tags remove "dust_mgun2"}}}
	}
	{on "dust_sound3_mgun"
		{tags add "dust_mgun3"}
		{if tagged "dust_mgun3" {spawn "s_box_mgun1" "basis" x} {delay 3 {tags remove "dust_mgun3"}}}
	}
)
{"btr80_wcw"	("mgun_dust_wcw")}
{"btr80s_wcw"	("mgun_dust_wcw")}
{"btr80sa_wcw"	("mgun_dust_wcw")}
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "hely_dust_wcw"
	{on fire "gun"
		{if not tagged "dust_gun" {call "dust_sound_gun"}}
	}
	{on fire "mgun"
		{if not tagged "dust_mgun" {call "dust_sound_mgun"}}
	}

	{on "dust_sound_gun"
		{tags add "dust_gun"}
		{if tagged "dust_gun" {spawn "s_box_hely2" "basis" x} {delay 2 {tags remove "dust_gun"}}}
	}
	{on "dust_sound_mgun"
		{tags add "dust_mgun"}
		{if tagged "dust_mgun" {spawn "s_box_hely1" "basis" x} {delay 2 {tags remove "dust_mgun"}}}
	}
)
{"ah-1z_wcw"	("hely_dust_wcw")}
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================









;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
;=================================================================================================================
(define "dead1_dust_wcw"
	{on "_explosion_xx_wcw"
		{if not tagged "dust_dead_s" {call "dust_dead_sound"}}
	}
	{on "_explosion_ex_t72"
		{if not tagged "dust_dead_s" {call "dust_dead_sound"}}
	}
	{on "_explosion_ex_abrams"
		{if not tagged "dust_dead_s" {call "dust_dead_sound"}}
	}
	{on "dust_dead_sound"
		{tags add "dust_dead_s"}{tags add "dust_dead_sound"}
		{if tagged "dust_dead_sound" {spawn "s_box_dead_big" "basis" x} {delay 1 {tags remove "dust_dead_sound"}}}
	}
)
;=================================================================================================================
;=================================================================================================================
(define "dead2_dust_wcw"
	{on "_explosion_xx_wcw"
		{if not tagged "dust_dead_s" {call "dust_dead_sound"}}
	}
	{on "_explosion_ex_t72"
		{if not tagged "dust_dead_s" {call "dust_dead_sound"}}
	}
	{on "_explosion_ex_abrams"
		{if not tagged "dust_dead_s" {call "dust_dead_sound"}}
	}
	{on "dust_dead_sound"
		{tags add "dust_dead_s"}{tags add "dust_dead_sound"}
		{if tagged "dust_dead_sound" {spawn "s_box_dead_medium" "basis" x} {delay 1 {tags remove "dust_dead_sound"}}}
	}
)
{"btr80_wcw"	("dead2_dust_wcw")}
{"btr80a_wcw"	("dead2_dust_wcw")}
{"btr80s_wcw"	("dead2_dust_wcw")}
{"btr80sa_wcw"	("dead2_dust_wcw")}
{"lav25_wcw"	("dead2_dust_wcw")}

{"ural4320_ammo_wcw"			("dead2_dust_wcw")}
{"ural4320_ammo_tank_wcw"			("dead2_dust_wcw")}
{"ural4320_ammo_canon_wcw"		("dead2_dust_wcw")}
{"ural4320_enginer_wcw"			("dead2_dust_wcw")}
{"ural4320_fuel_wcw"			("dead2_dust_wcw")}
{"ural4320_wcw"				("dead2_dust_wcw")}

{"gmc_ammo_wcw"				("dead2_dust_wcw")}
{"gmc_ammo_tank_wcw"			("dead2_dust_wcw")}
{"gmc_ammo_canon_wcw"			("dead2_dust_wcw")}
{"gmc_enginer_wcw"			("dead2_dust_wcw")}
{"gmc_fuel_wcw"				("dead2_dust_wcw")}
{"gmc_wcw"				("dead2_dust_wcw")}
;==================================================================
;==================================================================
{"bmp2_wcw"					("bmp3_dust_wcw")("dead2_dust_wcw")}
{"bmp2_spv_wcw"					("bmp3_dust_wcw")("dead2_dust_wcw")}
{"bmp2_spv2_wcw"					("bmp3_dust_wcw")("dead2_dust_wcw")}
{"bmp2_spv3_wcw"					("bmp3_dust_wcw")("dead2_dust_wcw")}
;==================================================================
;==================================================================
{"m1a1aim_blok1_wcw"				("tank1_dust_wcw")("dead1_dust_wcw")}
{"m1a1aim_blok1_usmc_wcw"			("tank1_dust_wcw")("dead1_dust_wcw")}
{"m1a1aim_blok1_usmc2_wcw"			("tank1_dust_wcw")("dead1_dust_wcw")}
{"m1a1aim_blok1_usmc3_wcw"			("tank1_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"m1a1aim_blok2_wcw"				("tank1_dust_wcw")("dead1_dust_wcw")}
{"m1a1aim_blok2_usmc_wcw"			("tank1_dust_wcw")("dead1_dust_wcw")}
{"m1a1aim_blok2_usmc2_wcw"			("tank1_dust_wcw")("dead1_dust_wcw")}
{"m1a1aim_blok2_usmc3_wcw"			("tank1_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"m1a1aim_blok2_tusk_wcw"				("tank1_dust_wcw")("dead1_dust_wcw")}
{"m1a1aim_blok2_tusk_usmc_wcw"			("tank1_dust_wcw")("dead1_dust_wcw")}
{"m1a1aim_blok2_tusk_usmc2_wcw"			("tank1_dust_wcw")("dead1_dust_wcw")}
{"m1a1aim_blok2_tusk_usmc3_wcw"			("tank1_dust_wcw")("dead1_dust_wcw")}
;==================================================================
;==================================================================
{"t72b_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b_spv_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b_spv2_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b_spv3_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"t72b2_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b2_spv_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b2_spv2_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b2_spv3_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"t72ab_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72ab_spv_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72ab_spv2_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72ab_spv3_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"t72bc_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72bc_spv_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72bc_spv2_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72bc_spv3_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"t72bm_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72bm_spv_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72bm_spv2_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72bm_spv3_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"t72b3_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b3_spv_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b3_spv2_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b3_spv3_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"t72b3a_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b3a_spv_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b3a_spv2_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
{"t72b3a_spv3_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"t64b_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t64b_spv_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t64b_spv2_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t64b_spv3_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"t64bv_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t64bv_spv_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t64bv_spv2_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
{"t64bv_spv3_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
;==============================================
{"t64bv2_wcw"					("tank2_dust_wcw")("dead1_dust_wcw")}
{"t64bv2_spv_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
{"t64bv2_spv2_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}
{"t64bv2_spv3_wcw"				("tank2_dust_wcw")("dead1_dust_wcw")}