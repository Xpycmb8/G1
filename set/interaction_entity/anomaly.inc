{"crystal_zm_spawner"
	{on spawn
		{burn volume "ems_inside" fx "crystal_mist" time 12 fake even_law}		
		{link_sound "start"	 "anomaly/crystal/spawner/start" }
		{link_sound "loop"	 "anomaly/crystal/spawner/loop" }
		{link_sound "stop"	 "anomaly/crystal/spawner/stop" }
		{play_sound "start" }
		{delay 1
			{play_sound "loop" 1}
		}
		{volumes disable contact}
		{delay 0
			{volumes enable contact}
		}
		{add_view 	"crystal_mist_move" 	"spawner" "basis"}
		;{view start "spawner"}

		{add_view 	"crystal_spark" 			"crystal_spark" "fx"}
		{add_view 	"crystal_mist_move_earth" 	"crystal_mist_move_earth" "fx"}
		{view start "crystal_spark"}
		{delay 3 1 
			{spawn "queit_change" }
			{call "fly"}
			{call "set"}
		}
		{gravity -0.2}
		{impulse up 0.4}
	}
	{on "up_fly"
		{kill_delay "marks"}
		{view start "crystal_mist_move_earth"}
		{delay 1 "marks"
			{view pause "crystal_mist_move_earth"}
		}			
	
	}
	{on "fly"
		{if altitude 15
			{gravity 1}
		else altitude 6
			;{impulse rnd_dir 1 cx 2 1 cy 2 1}
			{gravity 0.1}
		else altitude 1.5
			;{spawn "land_dust_spawner"}
			{impulse rnd_dir 2 cx 2 1 cy 2 1 }
			{call "up_fly"}
			{gravity -0.1}
		else altitude 0.2
			{spawn "queit_change_ground" }
			{gravity -4}
		}
		{delay_effect 0.02 "fly"}
	}	
	{on bullet_hit	
		{if effector "human"
			{tags add "electra_blast"}
			{delay 3 1.5
				{tags remove "electra_blast"}
			}
			{spawn "queit_change" "basis"}
			{with_effector
				{able "burning" 1}
				{delay 2 
					{able "burning" 0}
				}
				{tags add "bleeding_small_e"}
				{delay 10 "tags"
					{tags remove "bleeding_small_e"}
				}
				{call "bleeding_small_e"}
				{burn volume "body" fx "electra_hit" time 10 fake even_law}
				{burn volume "head" fx "electra_hit" time 4 fake even_law}
				{burn volume "foot1r" fx "electra_hit" time 8 fake even_law}
				{burn volume "foot2r" fx "electra_hit" time 3 fake even_law}
				{burn volume "foot1l" fx "electra_hit" time 8 fake even_law}
				{burn volume "foot2l" fx "electra_hit" time 3 fake even_law}
				{burn volume "hand1r" fx "electra_hit" time 8 fake even_law}
				{burn volume "hand2r" fx "electra_hit" time 4 fake even_law}
				{burn volume "hand1l" fx "electra_hit" time 8 fake even_law}
				{burn volume "hand2l" fx "electra_hit" time 4 fake even_law}
			}
		}
		{gravity 1}
		{kill_delay "fly"}
	}
	{on "set"
		{delay 16
			{spawn "queit_change" }
			{gravity 3}
		}
	}
	{on contact
		{with_effector 
			{call "up_fly"}
		}
		{volumes disable contact}
		{delay 0.1
			{volumes enable contact}
		}
		{impulse rnd_dir 2 cx 2 1 cy 2 1 }
		{spawn "electra_blast_centr_mini"}
		{call "up_fly"}
		{gravity -0.1}
		{if rand 0.1
			{call "break"}
		}
	}
	{on ground_hit 	
		{call "break"}
		{spawn "land_dust" }
		{spawn "sur_crystal_medium_02" random_position 600 random_orientation }
	}
	{on "break"
		{if not tagged "break"
			{volumes disable contact}
			{tags add "break"}
			{play_sound "stop" }
			{stop_sound "loop" }
			{stop_sound "start" }
			{spawn "queit_change" }
			{spawn	"glass_hit3"}			
			{delete}
		}	
	}
}
{"land_dust_spawner"
	{on spawn
		{fall_down}
		{pillar_up}
		{spawn "land_dust"}
		{delete}
	}	
}


{"crystal_zm"
	{on spawn
		{link_sound "loop"	 "anomaly/crystal/crystal_loop" }
		{play_sound "loop" 1}
		{if not tagged "grow"
			{tags add "grow"}
			{if rand 0.7
				{scale from 0.2 to 0.9 time 25}
			else rand 0.3
				{scale from 0.2 to 1.6 time 25}
			else
				{scale from 0.2 to 1.2 time 25}
			}
		}
		{burn volume "ems_inside" fx "crystal_mist" time 45 fake even_law}		
		{pillar_up}
		{ani_play "grow" loop}
	}
	{on animation_event "grow"
		{if not tagged "break"
			{if rand 0.3	
				{spawn	"crystal_zm_spawner" }
				{spawn "queit_change" }
			}
			{burn volume "body" fx "smoke_mist_blue" time 45 fake even_law}		
			{burn volume "ems_inside" fx "crystal_mist" time 45 fake even_law}		
		}
	}
	{on "break"
		{if not tagged "break"
			{start_sound "anomaly/break/"}	
			{stop_sound "loop" }
			{if rand 0.1
				{spawn	"crystal_zm_spawner" }
				{spawn "queit_change" }
			}				
			{volumes disable all}
			{ani_stop "grow" }
			{signal shot 500}
			{bone hide "ems"}
			{bone hide "ems_inside"}
			{bone hide "crystal_medium_02"}
			{bone show "crystal_medium_02_dmg"}
			{spawn	"glass_hit2" "1" x}
			{spawn	"glass_hit3" "2" x}
			{spawn	"glass_hit3" "3" x}			
		}
	}
	{on blast_hit
		{spawn "crystal_hit"}	
		{if rand 0.3
			{call "break"}
		}
	}
	{on bullet_hit
		{spawn "crystal_hit"}	
		{if rand 0.3	
			{call "break"}
		}
	}
	{on overlap begin sync
		{if not tagged "electra_blast"
			{if effector "human"
				{volumes disable contact}
				{tags add "electra_blast"}
				{delay 3 1.5
					{tags remove "electra_blast"}
					{volumes enable contact}
				}
				{spawn "electra_blast"}
				{spawn "electra_blast_centr" "basis"}
				{spawn "electra_blast_new" "basis"}
				{spawn "electra_blast" "basis"}
				{with_effector
					{if not tagged "quiet"
						{if not active
							{if rand 0.2
								{player 4}
							else rand 0.2
								{player 5}
							else rand 0.2
								{player 6}
							else rand 0.2
								{player 7}
							else rand 0.2
								{player 8}
							else rand 0.2
								{player 9}
							else rand 0.2
								{player 10}
							else
								{player 11}
							}
						}
						{able "burning" 1}
						{delay 2 
							{able "burning" 0}
						}
						{tags add "bleeding_small_e"}
						{delay 10 "tags"
							{tags remove "bleeding_small_e"}
						}
						{call "bleeding_small_e"}
						{burn volume "body" fx "electra_hit" time 10 fake even_law}
						{burn volume "head" fx "electra_hit" time 4 fake even_law}
						{burn volume "foot1r" fx "electra_hit" time 8 fake even_law}
						{burn volume "foot2r" fx "electra_hit" time 3 fake even_law}
						{burn volume "foot1l" fx "electra_hit" time 8 fake even_law}
						{burn volume "foot2l" fx "electra_hit" time 3 fake even_law}
						{burn volume "hand1r" fx "electra_hit" time 8 fake even_law}
						{burn volume "hand2r" fx "electra_hit" time 4 fake even_law}
						{burn volume "hand1l" fx "electra_hit" time 8 fake even_law}
						{burn volume "hand2l" fx "electra_hit" time 4 fake even_law}
					else
						{spawn "queit_change" "body"}
						(define "burn_volume"
							{burn volume %0 fx "smoke_mist_run" time 2 fake even_law}
							{burn volume %0 fx "electra_hit" time 0.5 fake even_law}
						)
						("burn_volume" args "head" "burn_head")
						("burn_volume" args "body" "burn_body")
						("burn_volume" args "hand1l" "burn_hand1l")
						("burn_volume" args "hand1r" "burn_hand1r")
						("burn_volume" args "hand2l" "burn_hand2l")
						("burn_volume" args "hand2r" "burn_hand2r")
						("burn_volume" args "foot1l" "burn_foot1l")
						("burn_volume" args "foot1r" "burn_foot1r")
						("burn_volume" args "foot2l" "burn_foot2l")
						("burn_volume" args "foot2r" "burn_foot2r")					
					}
				}	
			}	
		}
	}
	
}




{"electra15"
	{on spawn
		{link_sound "delay" "anomaly/electra/idle/electra_idle1"}
		{play_sound "delay" 1}
		{add_view 	"electra_idle" 	"electra_idle" "basis"}
		{view start "electra_idle"}
		{delay 9 3
			{call "blast_delay"}
		}
	}
	{on "blast_delay"
		{spawn "electra_blast" "fx_e10"}
		{if rand 0.2
			{spawn "electra_blast" "fx_e11"}
		}
		{if rand 0.2
			{spawn "electra_blast" "fx_e12"}
		}
		{if rand 0.2
			{spawn "electra_blast" "fx_e13"}
		}
		{if rand 0.2
			{spawn "electra_blast" "fx_e14"}
		}
		{delay 200 90
			{call "blast_delay"}
		}
	}
	{on contact sync
		{if not tagged "electra_blast"
			{volumes disable contact}
			{tags add "electra_blast"}
			{if effector "human"
				{with_effector
					{tags add "bleeding_small_e"}
					{delay 10 "tags"
						{tags remove "bleeding_small_e"}
					}
					{call "bleeding_small_e"}
					{burn volume "body" fx "thermite_hit2" time 10 fake even_law}
				}
			}	
			{spawn "electra_blast"}
			{spawn "electra_blast_centr" "fx_e11"}
			{spawn "electra_blast_new" "fx_e11"}
			{spawn "electra_blast" "fx_e11"}
			{delay 1 0.5
				{tags remove "electra_blast"}
			}	
			{delay 3 1.5
				{volumes enable contact}
			}
		}
	}
	{on "blast"
		{spawn "electra_blast"}
		{spawn "electra_blast_centr"}
		{delay 1
			{volumes disable contact}
		}
		{delay 3 1
			{volumes enable contact}
		}
	}
}

{"electra5"
	{on spawn
		{add_view 	"electra_idle" 	"electra_idle" "basis"}
		{view start "electra_idle"}
		{link_sound "delay" "anomaly/electra/idle/electra_idle1"}
		{play_sound "delay" 1}
		{delay 1
			{call "blast_delay"}
		}
	}
	{on "blast_delay"
		{spawn "electra_blast" "fx_e10"}
		{if rand 0.2
			{spawn "electra_blast" "fx_e11"}
		}
		{if rand 0.2
			{spawn "electra_blast" "fx_e12"}
		}
		{if rand 0.2
			{spawn "electra_blast" "fx_e13"}
		}
		{if rand 0.2
			{spawn "electra_blast" "fx_e14"}
		}
		{delay 200 90
			{call "blast_delay"}
		}
	}
	{on contact sync
		{if not tagged "electra_blast"
			{volumes disable contact}
			{tags add "electra_blast"}
			{if effector "human"
				{with_effector
					{able "burning" 1}
					{delay 3 
						{able "burning" 0}
					}
					{tags add "bleeding_small_e"}
					{delay 10 "tags"
						{tags remove "bleeding_small_e"}
					}
					{call "bleeding_small_e"}
					{burn volume "body" fx "electra_hit" time 10 fake even_law}
					{burn volume "head" fx "electra_hit" time 4 fake even_law}
					{burn volume "foot1r" fx "electra_hit" time 8 fake even_law}
					{burn volume "foot2r" fx "electra_hit" time 3 fake even_law}
					{burn volume "foot1l" fx "electra_hit" time 8 fake even_law}
					{burn volume "foot2l" fx "electra_hit" time 3 fake even_law}
					{burn volume "hand1r" fx "electra_hit" time 8 fake even_law}
					{burn volume "hand2r" fx "electra_hit" time 4 fake even_law}
					{burn volume "hand1l" fx "electra_hit" time 8 fake even_law}
					{burn volume "hand2l" fx "electra_hit" time 4 fake even_law}
				}
			}	
			{spawn "electra_blast"}
			{spawn "electra_blast_centr" "fx_e11"}
			{spawn "electra_blast_new" "fx_e11"}
			{spawn "electra_blast" "fx_e11"}
			{delay 1 0.5
				{tags remove "electra_blast"}
			}	
			{delay 3 1.5
				{volumes enable contact}
			}
		}
	}
	{on "blast"
		{spawn "electra_blast"}
		{spawn "electra_blast_centr"}
		{delay 1
			{volumes disable contact}
		}
		{delay 3 1
			{volumes enable contact}
		}
	}
}

{"swamp"
	{on spawn
		{add_view 	"smoke_swamp" 	"swamp" "basis"}	
		{view start "swamp"}
		{volumes "swamp" enable visible}
		{update_visibility_patch}
	}
}

{"scharka_static_weak"
	{on spawn
		{ani_play "fx_dummy" 0.01 loop}
		{add_view 	"scharka" 	"scharka" "raven_bone_tail"}
		{add_view 	"scharka_big" 	"scharka" "fx_dummy"}
		{view start "scharka"}
		{call "sound_update"}
		{call "fire_update"}
	}
	{on "sound_update"
		{if rand 0.8
			{spawn "scharka_sound" "raven_bone_tail"}
			{spawn "scharka_sound" "fx_dummy"}
		}
		{delay 2
			{call "sound_update"}
		}	
	}
	{on "fire_update"
		{fire volume "fx_dummy" radius 1 time 1}
		{delay 1
			{call "fire_update"}
		}	
	}

}




{"gravi_01"
	{on spawn
		{volumes enable contact}
		{add_view	"af3_tail"			"smoke"			"basis"}		
		{add_view 	"grav1" 			"fx_e10"		"basis"}
		{call "gravi_delay"}
		{call "rand_blow"}
	}
	{on "gravi_delay"
		{view start "fx_e10"}
	}
	{on "rand_blow"
		{if rand 0.2
			{spawn "gravi_blow_s" "basis"}
			{delay 2
				{blastwave c4 2 r0 1 r1 1 offset 0 0 2}
				{blastwave c4 0.2 r0 5 r1 5 offset 0 0 2}
				{spawn "gravi_blow_d" "basis"}
				{if rand 0.8
					{spawn "gravi_tail" "basis"}
				}
			}
		}
		{delay 5
			{call "rand_blow"}
		}	
	}
	{on contact sync
		{volumes disable contact}
		{if effector "human"
			{call "blast"}
		else 
			{call "blast"}
			{with_effector
				{view start "smoke"}
				{delay 4
					{view stop "smoke"}
				}
			}
		}
	}
	{on "blast"
		{blastwave c4 2 r0 1 r1 1 offset 0 0 2}
		{blastwave c4 0.2 r0 5 r1 5 offset 0 0 2}
		{spawn "gravi_hit" "basis"}
		{delay 7 2
			{volumes enable contact}
		}
	}
	{on "small_blast"
		{blastwave c4 0.5 r0 5 r1 5 offset 0 0 2}
		{spawn "gravi_hit" "basis"}
		{delay 1
			{volumes disable contact}
		}
		{delay 7 2
			{volumes enable contact}
		}
	}
}

{"fx_piece_flame2"
	{on spawn
		{volumes "body" enable contact}
		{gravity 2}
		;{if rand 0.1 
			{add_view 	"af2_tail" 	"fraction" "root"}
			{view start "fraction"}
			{delay 2 "t"
				{view pause "fraction"}
			}
		;}
		{delay 1.5 {delete}}
	}
	{on contact sync
		{if effector "vehicle"
			{view pause "fraction"}
			{delete}
		else effector "flesh"
			{view pause "fraction"}
			{delete}
		else effector "concrete"
			{view pause "fraction"}
			{delete}
		else effector "fence"
			{view pause "fraction"}
			{delete}
		else effector "wood"
			{view pause "fraction"}
			{delete}
		else
			{view pause "fraction"}
		}
		;{delete}
	}
	{on ground_hit sync
		{spawn "ex_bul_fr"}
		{delay 4 {delete}}
	}
}


