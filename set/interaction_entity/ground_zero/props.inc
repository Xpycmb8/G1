{"opened_fnix"
	{on spawn
		{volumes "touch" disable touch}
	}
	{on "open"
		{if tagged "open" 
			{tags remove "open"}
			{ani_play "open" -0.7}
			{volumes "touch" disable touch}
		else
			{burn volume "fx_l" fx "open_fx" time 4 fake}
			{burn volume "fx_r" fx "open_fx" time 4 fake}
			{tags add "open"}
			{ani_play "open" 0.4}
			{delay 1
				{volumes "touch" enable touch}
			}
		}
	}
}

{"melee_detect"
	{on "close"
		{volumes disable contact }	
	}
	{on "open"
		 {volumes enable contact}	
	}
	{on contact
		{if effector "human"
			{if volume "melee_back"
				{spawn "orientation_melee_back" "spawn" x}
				{volumes disable contact }	
				{delay 5
					 {volumes enable contact}	
				}		
			}		
			{if volume "melee_front"
				{spawn "orientation_melee_front" "spawn" x}
				{volumes disable contact }	
				{delay 5
					 {volumes enable contact}	
				}		
			}		
			{if volume "melee_stab"
				{spawn "orientation_melee_stab" "spawn" x}
				{volumes disable contact }	
				{delay 240
					 {volumes enable contact}	
				}		
			}		
		}		
	}
}


{"melee_detect_front_pest"
	{on "close"
		{volumes disable contact }	
	}
	{on "open"
		 {volumes enable contact}	
	}
	{on contact
		{if effector "human"
			;{if volume "melee"
				{spawn "orientation_melee_front" "spawn" x}
				{volumes disable contact }	
				{delay 5
					 {volumes enable contact}	
				}		
			;}		
		}		
	}
}



{"melee_detect_front_lynx"
	{on spawn
		{delay 0.1
			{spawn "orientation_gun_ik" "spawn" x}
		}
		{volumes enable overlap}
	}
	{on "close"
		{volumes disable overlap}
		{delay 10
			{volumes enable overlap}
		}
	}
	{on "open"
		{volumes enable overlap}
	}
	{on overlap begin	
		{if effector "wood fence"
			{spawn "orientation_melee_front" "spawn" x}
			{volumes disable overlap}
			{delay 2
				{volumes enable overlap}
			}
		}		
		{if effector "human"
			;{if volume "melee"
				{spawn "orientation_melee_front" "spawn" x}
				{volumes disable overlap}
				{delay 10
					{volumes enable overlap}
				}
			;}		
		}		
	}
}

{"attack_melee_l_stamp_place"
	{on spawn
		{volumes enable overlap}
	}
	{on "close"
		{volumes disable overlap}
	}
	{on "open"
		{volumes enable overlap}
	}
	{on overlap begin	
		{if effector "human"
			{spawn "attack_melee_l_stamp" "spawn" x}
			{volumes disable overlap}
		}		
	}
}

{"attack_melee_r_stamp_place"
	{on spawn
		{volumes enable overlap}
	}
	{on "close"
		{volumes disable overlap}
	}
	{on "open"
		{volumes enable overlap}
	}
	{on overlap begin	
		{if effector "human"
			{spawn "attack_melee_r_stamp" "spawn" x}
			{volumes disable overlap}
		}		
	}
}

{"attack_melee_l_stamp_bwd_place"
	{on spawn
		{volumes enable overlap}
	}
	{on "close"
		{volumes disable overlap}
	}
	{on "open"
		{volumes enable overlap}
	}
	{on overlap begin	
		{if effector "human"
			{spawn "attack_melee_l_stamp_bwd" "spawn" x}
			{volumes disable overlap}
		}		
	}
}

{"attack_melee_r_stamp_bwd_place"
	{on spawn
		{volumes enable overlap}
	}
	{on "close"
		{volumes disable overlap}
	}
	{on "open"
		{volumes enable overlap}
	}
	{on overlap begin	
		{if effector "human"
			{spawn "attack_melee_r_stamp_bwd" "spawn" x}
			{volumes disable overlap}
		}		
	}
}

{"check_side"
	{on spawn
		{stuff_detonate}
	}
}


{"police_zero"
	{on spawn
		;{link_sound "rotate"		"vehicle/brakes/brake_small/short"}
		{add_view	"blinker_police"			"blinker_l"			"blinker_l_fx"}
		{add_view	"blinker_police"			"blinker_r"			"blinker_r_fx"}
		{view pause	"blinker_r"}
		{view hide	"blinker_r"}
		{view pause	"blinker_l"}
		{view hide	"blinker_l"}		
		{delay 5
			{call "police_car"}
		}
	}
	{on break
		{if component "blinker_glass_r"
			{bone cut "blinker_glass_r" }
			{view pause	"blinker_r"}
			{view hide	"blinker_r"}
			;{bone hide "blinker_r"}
		}	
		{if component "blinker_glass_l"
			{bone cut "blinker_glass_l" }
			{view pause	"blinker_l"}
			{view hide	"blinker_l"}
			;{bone hide "blinker_l"}
		}	
	}	
	{on pierce
		{if volume "blinker_glass_r"
			{components "blinker_glass_r" break}
		}	
		{if volume "blinker_glass_l"
			{components "blinker_glass_l" break}
		}	
	}
	{on "police_car"
		{if work "engine"
			{ani_play "blinker" loop}
			{if work "blinker_glass_r"
				{view show	"blinker_r"}
				{view start	"blinker_r"}
			}	
			{if work "blinker_glass_l"
				{view show	"blinker_l"}
				{view start	"blinker_l"}
			}	
		else
			{ani_stop "blinker" }
			{view stop	"blinker_r"}
			{view hide	"blinker_r"}
			{view stop	"blinker_l"}
			{view hide	"blinker_l"}		
		}		
	}
}

{"spawner_egg"
	{on spawn
		{impulse up -0.1}
		; {delay 2
			; {if not tagged "load"
				; {call "drop"}
			; }
		; }		
	}
	{on ground_hit
		{if not tagged "load"
			{tags add "load"}
			{delay 3
				{call "drop"}
			}
		}
	}
	{on "unlink"		
		{volumes disable contact}
		{delay 1
			{volumes enable contact}
		}		
	}
	{on "unlink_harvest"		
		{impulse up -5}
	}
	{on "drop"
		(define "spawner_egg"
			{if prop "%prop"
				{if tagged "frends"
					{spawn "%class" "basis" 
						{ani_stop "power_up"  } 
						{ani_play "spawn_egg"  } 
						{tags add "frends"} 
						{tags add "started"} 
						{tags add "spawned"} 
						{burn volume "main_body" fx "smoke_destroy" time 1 fake even_law}
					}
				else
					{spawn "%class" "basis" 
						{ani_stop "power_up"  } 
						{ani_play "spawn_egg"  } 
						{tags add "started"} 
						{tags add "spawned"} 
						{burn volume "main_body" fx "smoke_destroy" time 1 fake even_law}
					}
				}		
			}		
		)		
		("spawner_egg" class(skirmisher_base_smg) 	prop(egg_skirmisher))
		("spawner_egg" class(pest_class_d) 			prop(egg_class_d))
		("spawner_egg" class(pest_01) 				prop(egg_01))
		("spawner_egg" class(pest_bomb) 			prop(egg_bomb))
		("spawner_egg" class(pest_bomb_x3) 			prop(egg_bomb_x3))
		{spawn "spawner_egg_fx" "body"}		
		{tear "piece_small_steel" bone "part"
			{impulse up 0.2}
		}			
		{tear "piece_small_steel" bone "part1"
			{impulse up 0.2}
		}			
		{delay 0
			{delete}
		}
	}
}

;---------------------Stuff

{"open_tritium"
	{inflammation_time 0}
	{on spawn
		{delay 0.5
			{burn volume fx "smoke_gas_trit" time 7 fake even_law}	
		}
		{impulse up 1 0.5 rnd_dir 1 0.5 no_position}
		{if rand 0.4
			{gravity 0.3}
		else rand 0.1
			{gravity 0.8}
		}
		{delay 7 4
			{delete}
		}
	}
	; {on "burn"
		; {if not "burned"
			; {if rand 0.4
				; {spawn "open_gas_s_fx" }	
				; {blastwave c4 0.6 r0 2 r1 2}	
				; {fire radius 0.5 time 3 heating 1}
			; else rand 0.3
				; {spawn "distant_small_expl"}			
				; {blastwave c4 3 r0 5 r1 5}	
				; {fire radius 2 time 3 heating 1}
				; {spawn "open_gas_m_fx" }	
			; }
			; {set "burned" 1}
			; {delete}
		; }
	; }
	; {on blast_hit 
		; {if not "burned"
			; {set "burned" 1}
			; {blastwave c4 0.1 r0 2 r1 2}	
			; {fire radius 0.5 time 2 heating 1}
			; {spawn "open_gas_s_fx" }	
			; {delete}
		; }
	; }	
	{on overlap begin
		{if effector "human"
			{with_effector
				{call "open_trit"}
			}	
		}		
	}
}
{"m43_ammo_gas" ;bullet
	{on spawn
		{link_sound "smoke" "detonation/grenade_smoke/smoke_grenade"}
		{volumes disable contact}	
		{add_view "start_xm109_tail" 		"start_23mm" "tail"}
		{start_sound "weapon/shot/small_arms/m203_close"}				
		{add_view "bullet_tail" "tail_fast" "tail"}
		{view start "start_23mm"}
		{view start "tail_fast"}
		{add_view "gas_smoke_activate"	"smoke_activate" "tail"}
		{add_view "gas_smoke_0"			"smoke1" "tail"}
		{add_view "gas_smoke_1"			"smoke2" "tail"}
		{add_view "gas_smoke_2"			"smoke3" "tail"}
		{add_view "gas_smoke_3"			"smoke4" "tail"}
		{add_view "gas_smoke_4"			"smoke5" "tail"}
		{add_view "gas_smoke_5"			"smoke6" "tail"}
		{delay 0
			{volumes enable contact}	
		}
		{delay 0.8
			{view stop "start_23mm"}
		}
		{update_visibility_patch}
		{delay 2.2
			{view start "smoke_activate"}
			{view start "smoke1"}
			{spawn "ex_gas_grenade"}
			{start_sound "detonation/smoke_start/"}
			{spawn "gas_vol_scale"}
			{delay 2
				{play_sound "smoke" 1}
			}
			{update_visibility_patch}
		}
		{delay 3
			{view stop "smoke1"}
			{view start "smoke2"}
		}
		{delay 5
			{view stop "smoke2"}
			{view start "smoke3"}
		}
		{delay 8
			{view stop "smoke3"}
			{view start "smoke4"}
		}
		{delay 12
			{view stop "smoke4"}
			{view start "smoke5"}
		}
		{delay 33
			{view stop "smoke_activate"}
			{view stop "smoke5"}
			{view start "smoke6"}
		}
		{delay 45
			{view stop "smoke6"}
			{stop_sound "smoke"}
		}		
	}
	{on ground_hit
		{gravity 5}
	}
	{on contact
		{fall_down}
		{delay 0 {impulse up 0.1 cx 2 1}}
		;{gravity 2}
	}
}

{"fnix_ems" 
	{on spawn
		(define "white_ems"
			{burn volume "ems_white_%0" fx "white_burn_ems" }
		)
		("white_ems" args 00 )
		("white_ems" args 01 )
		("white_ems" args 02 )
		("white_ems" args 03 )
		("white_ems" args 04 )
		("white_ems" args 05 )
		("white_ems" args 06 )
		("white_ems" args 07 )
		("white_ems" args 08 )
		("white_ems" args 09 )
		("white_ems" args 10 )
		("white_ems" args 11 )
		("white_ems" args 12 )
		("white_ems" args 13 )
		("white_ems" args 14 )
		("white_ems" args 15 )
		("white_ems" args 16 )
		("white_ems" args 17 )
	}
}

{"mine_cluster_ground"
	{inflammation_time 4}
	{on spawn
		{tags add "mine_cluster"}
		{add_view "red_ems_proj" 		"ems" "ems_bone"}
		{view start "ems"}	
		{delay 60
			{call "blast_stuff"}			
		}
	}
	{on blast_hit 
		{if volume "body"
			{call "blast_stuff"}
		}
	}	
	{on bullet_hit
		{if volume "body"
			{call "blast_stuff"}
		}
	}
	{on "burn"
		{if not "blocked"
			{set "blocked" 1}
			{call "blast_stuff"}			
		}
	}
	{on "blast_stuff"
		{if not "blocked"
			{stuff_detonate}
			{delete}
		}
	}
	{on "activate_stuff"
		{if not "blocked"
			{set "blocked" 1}
			{impulse up 5 1 cx 0 0.5 cy 0 0.5}	
			{spawn "impact_ground2"}
			{delay 0.4
				{stuff_detonate}
				{delete}
			}
		}
	}
	{on overlap begin
		{if effector "human"
			{call "activate_stuff"}
		else effector "vehicle"
			{call "activate_stuff"}
		}		
	}
}

{"mine_cluster"
	{inflammation_time 4}
	{on spawn
		{tags add "mine_cluster"}
		{add_view "red_ems_proj" 		"ems" "ems_bone"}
		{view start "ems"}	
		;{delay 60
		;	{call "blast_stuff"}			
		;}
	}
	{on blast_hit 
		{if volume "body"
			{call "blast_stuff"}
		}
	}	
	{on bullet_hit
		{if volume "body"
			{call "blast_stuff"}
		}
	}
	{on "burn"
		{if not "burned"
			{call "blast_stuff"}			
		}
	}
	{on "blast_stuff"
		{if not "burned"
			{set "burned" 1}
			{spawn "spheredust_big_hit_misc"}
			{impulse up 5 1 cx 0 0.1 cy 0 0.1}
			{delay 0.5
				{stuff_detonate}
				{delete}
			}
		}
	}
	{on overlap begin
		{if effector "human"
			{call "blast_stuff"}
		else effector "vehicle"
			{call "blast_stuff"}
		}		
	}
}
{"composite_blast_rus"
	{on spawn	
		{spawn "fx_piece_fire" 			"basis" x}			
		{spawn "metal_hit_zenite_cs" 	"basis" x}					
		(define "blast"
			{tear "piece_small_steel" bone %0
				{impulse forward 2 1 dir 2 1 cx 4 2 cy 4 2 }
			}
		)
		("blast" args "broken_01" )
		("blast" args "broken_02" )
		("blast" args "broken_03" )
		("blast" args "broken_04" )
		("blast" args "broken_05" )
		("blast" args "broken_06" )
		("blast" args "broken_07" )
		("blast" args "broken_08" )
		("blast" args "broken_09" )
		("blast" args "broken_10" )
		{delay 0.1 {delete}}
	}
}

{"cluster_mine"
	{inflammation_time 0}
	{on spawn
		{impulse forward 45 40}
		{volumes disable all }	
		{delay 0.3
			{volumes enable all}	
		}
		{burn volume fx "tail_grenade" time 1.5 0.5 fake even_law}	
		{burn volume fx "fx_trace_bullet_round" time 4 fake even_law}	
		{delay 5
			{call "explosion"}
		}
	}
	{on "explosion"
		{spawn "ex_air_norm9"}
		{if terrain_fx "shoot_emit_int"
			{start_sound "shoot_emitters_int/rifle"}
		}
		{start_sound "detonation/crack_bullet/med/"}
		
		{stuff_detonate}
	}
	; {on contact
		; {if not prop "cluster_mine"
			; {call "explosion"}
			; {volumes disable contact }			
		; }
	; }
	{on ground_hit
		; {gravity 0}
		; {fall_down}
		{call "explosion"}
		;{spawn "ex_bul_zenit_cs"}
		{start_sound "generation_zero/weapon/cluster_mine/"}	
		; {if rand 0.9
			; {spawn "spheredust_small_short2"}
		; }
		; (define "terrain_fx"
			; {if min_speed %2
				; {if terrain_fx %0 
					; {start_sound "hit/small/grenade/%1/hard/"}	
				; }
			; else min_speed %3
				; {if terrain_fx %0 
					; {start_sound "hit/small/grenade/%1/med/"}	
				; }
			; else min_speed %4
				; {if terrain_fx %0 
					; {start_sound "hit/small/grenade/%1/soft/"}	
				; }
			; }
		; )
		; ("terrain_fx" args "ground" 		grass 			30 14 6 )
		; ("terrain_fx" args "grass" 			grass 			30 14 6 )
		; ("terrain_fx" args "road" 			concrete 		30 14 6 )
		; ("terrain_fx" args "country_road" 	concrete 		30 14 6 )
		; ("terrain_fx" args "sand" 			sand 			30 14 6 )
		; ("terrain_fx" args "snow"  			mud 			30 14 6 )
		; ("terrain_fx" args "water" 			water 			30 14 6 )
		; ("terrain_fx" args "bridge" 		wood			30 14 6 )
		; ("terrain_fx" args "bridge_wood" 	wood			30 14 6 )
		; ("terrain_fx" args "floor" 			carpet 			30 14 6 )
		; ("terrain_fx" args "rock" 			ground 			30 14 6 )
		; ("terrain_fx" args "metal" 			metal 			30 14 6 )
		; ("terrain_fx" args "shoot_emit_mtl" 	 metal 			30 14 6 )
		; ("terrain_fx" args "shoot_emit_mtl_int" 	metal 			30 14 6 )
		; ("terrain_fx" args "shoot_emit_ext" 	 concrete 		30 14 6 )
		; ("terrain_fx" args "shoot_emit_int"  	concrete 		30 14 6 )
		; ("terrain_fx" args "shoot_emit_int_wood"  	wood 		30 14 6 )
	}
}



{"sound_link"
	{on spawn
		{link_sound "sound_link_start" "generation_zero/characters/gas_drop/smoke_hiss_start"}
		{link_sound "sound_link_loop" "generation_zero/characters/gas_drop/smoke_hiss_lp"}
		{link_sound "sound_link_end" "generation_zero/characters/gas_drop/smoke_hiss_end"}
	}
}

{"gas_sound"
	{on "open"
		{play_sound "sound_link_start" }
		{delay 2 "work"
			{play_sound "sound_link_loop" 1}
		}
		{delay 5 "work" ;gas_timer
			{stop_sound "sound_link_loop" }
			{play_sound "sound_link_end" }
		}
	}
	{on "close"
		{kill_delay "work"}
		{stop_sound "sound_link_start" }
		{stop_sound "sound_link_loop" }
		{stop_sound "sound_link_end" }
	}
}

{"turbine_micro_sound"
	{on spawn overload
		{link_sound "sound_link_loop_far" "generation_zero/characters/scout/turbine/far/turbine_distant"}
		{link_sound "sound_link_loop_close" "generation_zero/characters/scout/turbine/close/turbine_whee"}
		{link_sound "sound_link_end" "generation_zero/characters/gas_drop/smoke_hiss_end"}
	}
	{on "open"
		{start_sound "generation_zero/characters/scout/turbine/start/close"}	
		{start_sound "generation_zero/characters/scout/turbine/start/far"}	
		;{play_sound "sound_link_start" }
		{delay 0.5 "work"
			{play_sound "sound_link_loop_far" 1}
			{play_sound "sound_link_loop_close" 1}
		}
	}
	{on "close"
		{kill_delay "work"}
		{stop_sound "sound_link_loop_far" }
		{stop_sound "sound_link_loop_close" }
	}
}


{"gas_view_dread"
	{on spawn
		{ani_play "gas_loop" 1 loop}			
	}
	{on "empty"	     
		{tex_morph "empty" 3}		
	}
	{on "empty_fast"	     
		{tex_morph "empty" 0.5}		
	}
	{on "load"	     
		{tex_morph "full" 3}		
	}
}

{"weapon_warning"
	{on spawn
		{gravity 0}
		{impulse forward 400 com  }		
		{delay 0.5 {delete}}
	}
	{on contact
		{if effector "baze_machinery"
			{if not prop "prototype"
				{if rand 0.3
					{with_effector
						{call "slope_weapon_warning"}
					}
				}
			}
			{delete}
		}		
	}
}
{"rpg_warning"
	{on spawn
		{gravity 0}
		{impulse forward 400 com  }		
		{delay 0.5 {delete}}
	}
	{on contact
		{if effector "baze_machinery"
			{with_effector
				{call "rpg_weapon_warning"}
			}
			{delete}
		}		
	}
}

;		{spawn "ex_air_norm"}

{"scout_horn"
	{on spawn
		{delay 3 {delete}}
	}
}

