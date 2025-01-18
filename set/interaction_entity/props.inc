
{"auto_unfold"
	{on spawn 
		{call "unfold"}
	}
	{on "unfold"
		{start_sound "push/deployable_cover/plant/"}
		{delay 0.2
			{ani_play "cover_bust" 1.6}
		}
		{delay 1
			{start_sound "push/deployable_cover/unfold"}
			{spawn "spheredust_small" "stake_right_fx"}		
			{spawn "spheredust_small" "stake_centr_fx"}		
			{spawn "spheredust_small" "stake_left_fx"}		
		}
	}
}

{"deployable_cover"
	{on spawn 
		{pillar_up}
	}
	{on "stand"
		{start_sound "push/deployable_cover/unfold"}
		{ani_play "cover_bust" 1.2}
		{delay 1
			{spawn "deployable_cover_unfold" "deployable_centr" x}
			{delete}
		}
	}
	{on "break_blast"
		(define "blast"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 3 dir 7 2 cx 3 2 cy 3 2 rnd_dir 7 no_position}
			}
		)
		("blast" args "cover_right_04"		 )
		("blast" args "cover_right_03"		 )
		("blast" args "cover_right_02"		 )
		("blast" args "cover_right_01"		 )
		("blast" args "cover_left_04"		 )
		("blast" args "cover_left_03"		 )
		("blast" args "cover_left_02"		 )
		("blast" args "cover_left_01"		 )
		("blast" args "deployable_centr"		 )
	}
	{on break_armor_again
		{call "do_armor_break"}
	}
	{on "do_armor_break"
		{if name "blast"
			{if volume "body"
				{call "crush"}
			}
		}
	}
	{on blast
		{if min_energy 10
			(define "blast"
				{if volume "body"
					{tear "piece_medium_steel" bone %0
						{spawn "spheredust_small_short_arm" }
						{impulse up 4 3 dir 7 2 cx 3 2 cy 3 2 rnd_dir 7 no_position}
					}
				}
			)
			("blast" args "cover_right_04"		 )
			("blast" args "cover_right_03"		 )
			("blast" args "cover_right_02"		 )
			("blast" args "cover_right_01"		 )
			("blast" args "cover_left_04"		 )
			("blast" args "cover_left_03"		 )
			("blast" args "cover_left_02"		 )
			("blast" args "cover_left_01"		 )
			("blast" args "deployable_centr"		 )
		else min_energy 5
			{if rand 0.5
				{tear "piece_medium_steel" bone from_volume
					{spawn "spheredust_small_short_arm" }
					{impulse up 3 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 3 no_position}
				}	
			}
		}
	}
	{on "crush"
		(define "blast"
			{spawn "spheredust_small_short_arm" }
			{tear "piece_medium_steel" bone %0
				{impulse up 4 3 dir 7 2 cx 3 2 cy 3 2 rnd_dir 7 no_position}
			}
		)
		("blast" args "cover_right_04"		 )
		("blast" args "cover_right_03"		 )
		("blast" args "cover_right_02"		 )
		("blast" args "cover_right_01"		 )
		("blast" args "cover_left_04"		 )
		("blast" args "cover_left_03"		 )
		("blast" args "cover_left_02"		 )
		("blast" args "cover_left_01"		 )
		("blast" args "deployable_centr"		 )
	}
	{on pierce 
		{if stuff "zenite"
			{burn fx "wound_fx_stone00" time 0.8}		
			{if rand 0.3
				{spawn "spheredust_small_short_arm" }
				{tear "piece_medium_steel" bone from_volume
					{impulse up 5 2 dir 5 2 cx 4 2 cy 4 2 rnd_dir 5 no_position}
				}	
			}
		else stuff "40mm_grenade"
			{if rand 0.4
				{spawn "spheredust_small_short_arm" }
				{tear "piece_medium_steel" bone from_volume
					{impulse up 2 1 dir 7 3 cx 2 1 cy 2 1  no_position}
				}	
			}	
			{burn fx "wound_fx_stone00" time 2}		
		else stuff "rocketlauncher"
			{if rand 0.5
				{call "crush"}	
			}
		else stuff "big"
			{call "crush"}			
		else stuff "bullet"
			{if rand 0.2
				{burn fx "wound_fx_stone00" time 2}		
			}
		}
	}
	{on contact 
		{if effector "tank"
			{call "crush"}
		else effector "vehicle"
			{if contact_velocity 30
				{spawn "spheredust_small_short_arm" }
				{tear "piece_medium_steel" bone from_volume
					{impulse up 5 2 dir 5 2 cx 4 2 cy 4 2 rnd_dir 5 no_position}
				}	
			}			
		}
	}
}

{"nukacola_empty"
	{on spawn 
		{impulse up 0.1 rnd_dir 0.1 no_position}
	}
}
{"nukacola"
	{on "hidden"
		{delay 3
			{delete}
		}
	}
}
{"nukacola"
	{on "hidden"
		{delay 3
			{delete}
		}
	}
}
{"nukacola_quantum"
	{on spawn
		{add_view "fx_blue"	"fx"	"fx"	}
		{view start "fx"}
	}
	{on "hidden"
		{delay 3
			{delete}
		}
	}
}

{"monitor"
	{on blast_hit
		{if volume "monitor"
			{if min_energy 0.5
				{call "blast"}
			}
		}
		{if volume "body"
			{if min_energy 2
				{call "blast"}
			}
		}
	}
	{on bullet_hit 
		{if volume "monitor"
			{call "blast"}
		else volume "body"
			{if stuff "bullet big"
				{if rand 0.5
					{call "blast"}
				}
			else stuff "zenite"			
				{if rand 0.7
					{call "blast"}
				}
			else stuff "bullet"			
				{if rand 0.1
					{call "blast"}
				}
			}
		}
	}
	{on contact
		{if volume "monitor"
			{if effector "fraction" ;дробь
				{call "blast"}
			}
			{if effector "vehicle"
				{call "blast"}
			}
		}
	}
	{on ground_hit
		{if contact_velocity 10
			{if volume "monitor"
				{if rand 0.8
					{call "blast"}
				}
			else volume "body"
				{if rand 0.1
					{call "blast"}
				}
			}
		}
	}
	{on "blast"
		{if bone "monitor" visible
		;{if not tagged "break" 
			;{tags add "break"}
			{spawn "ex_tv" "monitor"}
			{bone show "monitor_break"}			
			{bone hide "monitor"}			
		}
	}
}


{"battery"
	{inflammation_time 5}
	{on spawn 
		{set "blast" 1}
		{link_sound 	"explosion"			"detonation/explosion_medium/fuel/oxygen_Tank"}
		{add_view	 	"smoke_bats"			"smoke" 		"root"}
		{add_view	 	"ex_tv"					"ex_boom" 		"root"}
		{add_view 		"smoke_aero_small"		"smoke_fire" 	"root"}
	}
	{on "burn"
		{if not burned
			{set "burned" 1}
			{burn fx "smoke_barrel_small2" time 2 fake}
			{delay 5 1
				{call "blast"}
			}
		}
	}	
	{on blast_hit
		{if min_energy 3
			{if not tagged "blast"
				{tags add "blast"}
				{tex_mod "dh"}
				{spawn "piece_wheel_fire" "part01"}
				{view start "smoke_fire"}
				{delay 2
					{tex_mod "dh2"}
					{view pause "smoke_fire"}
				}
				{call "blast"}
				;{delete}
			}
		}
	}
	{on bullet_hit 
		{if stuff "bullet big"
			{if rand 0.3
				{call "blast"}
			else rand 0.02
				{call "blast_ph"}
			}
		else stuff "zenite fg"			
			{call "blast"}
		else stuff "zenite"			
			{if rand 0.7
				{call "blast"}
			else rand 0.2
				{call "blast_ph"}
			}
		else stuff "bullet"			
			{if rand 0.05
				{call "blast"}
			else rand 0.02
				{call "blast_ph"}
			}
		}
		{if not tagged "hit"
			{tags add "hit"}
			{tex_mod "d"}
			{view start "smoke"}
			{delay 10
				{view pause "smoke"}
			}
		}
	}
	{on contact
		{if effector "fraction" ;дробь
			{call "blast"}
		}
		{if effector "dummy"
			{call "blast"}
		}
	}
	{on "blast_ph"	
		{play_sound "explosion" 1}
		{burn fx "batt_fire" time 0.3}
		{delay 0.3 {stop_sound "explosion" 1}}
		{impulse up 2 fx 25}
		;{delay 0.2 {impulse up 1 fx 25}}
		;{delay 0.5 {impulse up 1 fx 25}}
		{if rand 0.1
			{stop_sound "explosion" 1}
			{call "blast"}
			{blastwave c4 0.5 r0 2 r1 2 }
		}
	}
	{on "blast"
		{if not tagged "die"
			{tex_mod "dh"}
			{spawn "ex_air_norms" "makeshiftbattery"}
			{view start "ex_boom"}
			{delay 3
				{view pause "ex_boom"}
			}
			{tags add "die"}
			{blastwave c4 0.9 r0 2 r1 2 }
			{blastwave c4 0.7 r0 4 r1 4 }
			(define "cut_part"
				{tear "piece_small_steel" bone %0
						{impulse up 3 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				}
			)
			;("cut_part" args "makeshiftbattery"		"makeshiftbattery" )
			("cut_part" args "part01"		"part01" )
			("cut_part" args "part02"		"part02" )
			("cut_part" args "part03"		"part03" )
			("cut_part" args "part04"		"part04" )
			("cut_part" args "part05"		"part05" )
			("cut_part" args "part06"		"part06" )
			("cut_part" args "part07"		"part07" )
			("cut_part" args "part08"		"part08" )
			("cut_part" args "part09"		"part09" )
		}
	}
}

{"rocket_caps_back"
	{on spawn
		{burn volume "body" fx "fx_fire_engine_gen" time 2 fake even_law}
		{burn volume "body" fx "fire_magazine" time 3 fake even_law}
	}
}

{"rocket_caps_front"
	{on spawn
		{volumes disable bullet contact blast touch}	
		{delay 1
			{volumes enable bullet contact blast touch}	
		}
		{burn volume "body" fx "fx_fire_engine_gen" time 3 fake even_law}
		{burn volume "body" fx "fire_magazine" time 8 fake even_law}
	}
}

{"shell_fg_p"
	{on spawn
		{add_view "rocket_smoke_g" "smoke_shell2" "tail"}
		{view start "smoke_shell2"}
	}
	{on contact
		{blastwave c4 12 r0 3 r1 3 }
		{spawn "ex_air_norm2"}
		{delete}
		
	}
	{on ground_hit
		{delete}
		{blastwave c4 12 r0 3 r1 3 }
		{spawn "ex_ap_medium"}
		{spawn "ex_air_norm2"}
	}
}

{"bomb_nap"
	{on spawn
		{add_view "exhaust_dark_big" "smoke_shell" "basis"}
		{view start "smoke_shell"}
		{delay 4
				{add_view "smoke_dead_tank1" "smoke_shell4" "basis"}
				{view start "smoke_shell4"}
		}
		{delay 5
			{spawn "car_die" }
			{spawn "ex_air_norm5" offset 0 0 2}
			{delete}
		}
	}
	{on contact
		{if effector "vehicle"
			{if effector_velocity 5
				{spawn "car_die" }
				{spawn "bomb_nap" offset 0 0 0}
			}
		}
	}
}
	
{"balloon_nap"
	{on spawn
		{add_view "smoke_aero_big" "smoke_shell1" "tank_can"}
		{view start "smoke_shell1"}
		{delay 4 1
			{stuff_detonate}
			{spawn "ex_air_big" }
		}
	}
	{on contact
		;{stuff_detonate}
	}	
}	

{"remote_tablet"
	{on spawn
		{bone hide "led_power"}	
		{add_view "diod_red3"	"led" "led_power"}
		{view stop "led"}
		{call "power"}
	}
	{on "power"
		{bone show "led_power"}	
		{view start "led"}
		{delay 0.01
			{view pause "led"}
			{bone hide "led_power"}	
		}
		{delay 0.9
			{bone show "led_power"}	
			{view start "led"}
		}
		{delay 1.1
			{view pause "led"}
			{bone hide "led_power"}	
		}
		{delay_effect 2
			"power"
		}
	}
}

{"pulser"
	{on spawn
		{add_view "diod_red3"	"light" "fx_light"}
		{delay 2
			{call "pulse"}
		}
	}
	{on "pulse"
		{view start "light"}
		{tex_morph "sv" 0.2}
		{delay 2
			{view pause "light"}
			{tex_morph "norm" 0.7}
			{delay 2
				{call "pulse"}
			}
		}
	}
}

{"cord_wood"
	{inflammation_time 3}
	(define "burn_start"
		{add_view "smoke_camp_norm" "fire" "fx_light"}
		{set "burning" 1}
		{view start "fire"}
		{burn time %0}
		{fire radius 0.4 time %0 heating 0.3 follow}
		{delay %0
			{view stop "fire"}
			{set "burning" 0}
			{tags remove "burned"}
		}
	)
	{on spawn
		{if "burning"
			{add_view "smoke_camp_norm" "fire" "fx_light"}
			{view start "fire"}
		}
	}
	{on "_burn"
		{if "poured"
			{tags add "burned"}
			("burn_start" args 300)
		}
	}
	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}
	{on contact
		{if effector "vehicle"
			{call "break"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 0.5
				{call "break"}
			}
		}
	}
	{on "break"
		{if "burning"
			{spawn "camp_die" no_position offset 0 0 5}
		else
			{spawn "wood_hit_small" no_position}
		}
		{delete}
	}
	{on "pour_over"
		{if name "fuel"
			{tags add "poured"}
			{set "poured" 1}
		}
	}
}

{"camp_fire"
	{on spawn
		{call "burn"}
	}
	{on "_burn" overload
		("burn_start" args 7200)
	}
}

{"camp_fire_o"
	{on "_burn" overload}
}

{"camp_fire2"
	{on contact overload}
}

{"post_way"
	{on "hide"
		{bone hide "root"}
	}
	{on "show"
		{bone show "root"}
	}
}

{"server_rack"
	{on spawn
		{ani_play "work" 0.5 loop}
	}
	{on bullet_hit
		{if stuff "fx_40"
			{if volume "part"
				{bullet_detonate}
				{spawn "metal_hit_wire2"}
				{burn fx "smoke_aero_small" time 4 fake}				
				{burn fx "smoke_aero_2_small" time 9 fake}				
				{burn fx "smoke_aero_3_small" time 14 fake}				
				{tear "piece_medium_steel" bone from_volume
					{impulse up 4 3 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}	
		else stuff "shell"
			{if volume "part"
				{impulse up 1.4 0.5 dir 2 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
				{bullet_detonate}
				{spawn "metal_hit_wire2"}
				{burn fx "smoke_aero_small" time 4 fake}				
				{burn fx "smoke_aero_2_small" time 9 fake}				
				{burn fx "smoke_aero_3_small" time 14 fake}				
				{tear "piece_medium_steel" bone from_volume
					{impulse up 4 3 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}
		}
	}
	{on blast
		{if volume "part"
			{if min_energy 10
				{tear "piece_medium_steel" bone from_volume
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}	
			{if min_energy 5
				{if rand 0.6		
					{tear "piece_medium_steel" bone from_volume
						{impulse up 5 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				}	
			}
			{if min_energy 1
				{impulse up 0.1}
				{if rand 0.6		
					{tear "piece_medium_steel" bone from_volume
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}
					}
				}					
			}
		}
	}
	{on contact
		{if effector "vehicle" 
			{if min_speed 40
				{if volume "part"
					{if rand 0.4		
						{tear "piece_medium_steel" bone from_volume
							{impulse up 1.6 dir 0.3 0.1}
						}
					}
				}
			}	
		}
	}

	{on pierce
		(define "volume"
			(define "impact"
				{if stuff "%stuff"
					{if volume "%volume"
						{if tagged "broken_%volume"
							{if rand %rand_tear		
								{tear "piece_medium_steel" bone from_volume
									{spawn "metal_hit_wire3" "%volume"}
									%impact	
								}				
							}	
						}	
						{if rand %rand_damage
							{tags add "broken_%volume"}
							{bone hide "%volume_ems"}
							{burn volume "%volume" fx "heat_ten_broken2" time 4 fake even_law}
							{spawn "metal_hit_wire2" "%volume"}
						}
					}
				}	
			)
			("impact" 	stuff(shell_big)  				rand_damage(1)		rand_tear(1)  		impact({impulse up 4 2 		dir 5 2 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))
			("impact" 	stuff(atgm_launcher) 			rand_damage(1)		rand_tear(1) 		impact({impulse up 4 2 		dir 20 10 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))
			("impact" 	stuff(shell_minimum)			rand_damage(1)		rand_tear(1) 		impact({impulse up 3 2 		dir 12 7 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
			("impact" 	stuff(rocketlauncher shell)  	rand_damage(1)		rand_tear(1) 	 	impact({impulse up 4 2 		dir 5 2 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
			("impact" 	stuff(grenade fg)  				rand_damage(1)		rand_tear(1) 		impact({impulse up 3 2 		dir 5 2 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
			("impact" 	stuff(zenite th)  				rand_damage(1)		rand_tear(1) 		impact({impulse up 1 0.5 	dir 2 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
			("impact" 	stuff(zenite fg)  				rand_damage(1)		rand_tear(1) 		impact({impulse up 2 1 		dir 4 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
			("impact" 	stuff(zenite ap)  				rand_damage(1)		rand_tear(1) 		impact({impulse up 1 0.5 	dir 2 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
			("impact" 	stuff(bullet sp big)  			rand_damage(0.3)	rand_tear(0.2) 		impact({impulse up 1 0.5 	dir 2 1 		cx 2 1 cy 2 1 rnd_dir 1 no_position}))  
			("impact" 	stuff(bullet ap big)  			rand_damage(0.5)	rand_tear(0.3) 		impact({impulse up 2 0.5 	dir 3 2 		cx 4 2 cy 4 2 rnd_dir 4 no_position}))  
			("impact" 	stuff(bullet fg big)  			rand_damage(0.6)	rand_tear(0.2) 		impact({impulse up 3 2 		dir 3 2 		cx 4 2 cy 4 2 rnd_dir 4 no_position}))   
			("impact" 	stuff(bullet small)  		 	rand_damage(0.3)	rand_tear(0.1) 		impact({impulse up 1 0.5 	dir 2 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))    
			("impact" 	stuff(bullet normal)  		 	rand_damage(0.5)	rand_tear(0.1) 		impact({impulse up 2 0.5 	dir 3 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))      
		)
		("volume" 	volume(part1))
		("volume" 	volume(part2))
		("volume" 	volume(part3))
		("volume" 	volume(part4))
		("volume" 	volume(part5))
		("volume" 	volume(part6))
		("volume" 	volume(part7))
		("volume" 	volume(part8))
		("volume" 	volume(part9))
		{if rand 0.05
			{tags add "destroy"}
		}

	}	
}

{"m84_burnt"
	{on spawn
		{impulse up 1.4 0.5 dir 2 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
		{add_view "m84_burnt_smoke"	"smoke"	"basis"	}
		{view start "smoke"}
		{delay 5
			{view stop "smoke"}
		}
		{delay 200
			{delete}
		}
	}
	{on ground_hit
		{if terrain_fx "water"
			{view stop "smoke_shell"}
		}
	}
}

{"box_engineer"
	{on "undermine"
		{delay 5
			{spawn "tripod"}
			{spawn "teleport_synth"}
			{delete}
		}
	}
}

{"log_wood"
	{on spawn
		{impulse up 0.1 dir 0.1}
	}
	{on "trunk_fall"
		{start_sound "crush/medium/tree"}
		{spawn "tree_crush"}
		{if rand 0.5
			{spawn "wood_trunk_01"	random_position 2 random_orientation}
		else
			{spawn "wood_trunk_02"	random_position 2 random_orientation}
		}
		{spawn "crushed_bush_04"	random_position 15 random_orientation}
		{delete}
	}
}

{"bomb_homemade_jug"
	{inflammation_time 6}
	{on contact
		{if effector "fraction" ;дробь
			{if not linked
				{impulse up 0.6 dir 0.3 0.1}
			}
		}
	}
	{on "match"
		{delay 3 
			{if not tagged "burn"
				{burn volume "body" fx "smoke_dead_body" time 11 fake even_law}
				{link_sound 	"small"			"fire/small_stuff/fire_small"}
				{play_sound "small" 1}
				{tags add "burn"}
				{delay 10 
					{burn volume "body" fx "smoke_dead_small_cars" time 7 fake even_law}
					{delay 2 1 
						{stop_sound "small" }
						{call "blast"}
					}
				}
			}
		}
	}
	{on "burn_volume"
		{if volume "body"
			{if not tagged "burn"
				{burn volume "body" fx "smoke_dead_body" time 7 fake even_law}
				{link_sound 	"small"			"fire/small_stuff/fire_small"}
				{play_sound "small" 1}
				{fire volume "body" radius 0.2 heating 1  time 7 follow}
				{tags add "burn"}
				{delay 7 
					{stop_sound "small" }
					{call "blast"}
				}
			}
		}
	}
	{on "blast"
		{if not "burned"
			{set "burned" 1}
			{spawn "heavy_revebration" }
			{spawn "ex_fg_small_rpg" }		
			{spawn "ex_therm_fire_big_slicer" "base"}	
			{spawn "open_gas_vl_fx" "base"}	
			{blastwave c4 25 r0 12 r1 12}	
			{fire radius 5 time 4 heating 3}
			{delete}	
		}
	}
	{on bullet_hit
		{if volume "explosive"
			{if rand 0.7
				{call "blast"}
			}
		else volume "body"
			{if rand 0.2
				{call "blast"}
			}
		}
	}
	{on blast_hit
		{call "blast"}
	}
	{on ground_hit
		{if contact_velocity 20
			{if rand 0.1
				{call "blast"}
			}
		}
	}
}

{"lighter_zippo_fire"
	{on spawn
		{impulse up 0.3}
		{delay 2
			{fire radius 0.1 time 20 heating 1 effector}
			{if rand 0.3
				{spawn "zippo_fire_spark"  "fire"}
			}
			{add_view "zippo_fire" "fire" "fire"}
			{view start "fire"}
		}
		{delay 20
			{spawn "zippo_fire_spark"  "fire"}
			{view stop "fire"}
		}
	}
}

{"heater_box"
	{on spawn
;		{burn volume "heat_ten" fx "heat_ten"  }
	}
	{on blast
		{if not "broken"
			{set "broken" 1}
			{bone hide "heat"}
			{burn volume "heat_ten2" fx "heat_ten_broken" time 3 fake even_law}
			{burn volume "heat_ten" fx "heat_ten_broken" time 3 fake even_law}
		}
	}
	{on bullet_hit
		{if volume "body"
			{if rand 0.4
				{if not "broken"
					{set "broken" 1}
					{bone hide "heat"}
					{burn volume "heat_ten2" fx "heat_ten_broken" time 3 fake even_law}
					{burn volume "heat_ten" fx "heat_ten_broken" time 3 fake even_law}
				}
			}
		}
	}
	{on ground_hit
		{if contact_velocity 1
			{if not "broken"
				{set "broken" 1}
				{bone hide "heat"}
				{burn volume "heat_ten2" fx "heat_ten_broken" time 3 fake even_law}
				{burn volume "heat_ten" fx "heat_ten_broken" time 3 fake even_law}
			}
		}
	}
}

{"gas_lantern"
	{on spawn
		{add_view "gas_lantern_light" "lamp" "lamp"}
		{view start "lamp"}
	}
	{on blast
		{if not "broken"
			{set "broken" 1}
			{bone hide "glass"}
			{spawn "glass_hit4" "glass"}
		}
	}
	{on bullet_hit
		{if volume "glass"
			{if rand 0.4
				{if not "broken"
					{set "broken" 1}
					{bone hide "glass"}
					{spawn "glass_hit4" "glass"}
					{view stop "lamp"}	
					{view hide "lamp"}	
				}
			}
		}
	}
	{on ground_hit
		{if contact_velocity 2
			{if rand 0.1
				{if not "broken"
					{set "broken" 1}
					{bone hide "glass"}
					{spawn "glass_hit4" "glass"}
				}
			}
			{view stop "lamp"}	
			{view hide "lamp"}	
		}
	}
}

{"target2"
	{on contact
		{if volume "body"
			{if effector "fraction"
				{with_effector
					{delete}
				}
			}
		}
	}		
	{on bullet_hit
		{if stuff "bullet zenite"
			{if rand 0.1
				{tear "piece_medium_steel" bone from_volume
					{spawn "ex_w_small" }
					{impulse up 3 1 dir 9 3 cx 3 2 cy 3 2 rnd_dir 7 no_position}
				}
			}
			(define "target"
				{if volume %0
					{if rand 0.7
						{ani_play %0 3}	
					else rand 0.5
						{ani_play %0 1.5}	
					else
						{ani_play %0 0.5}
					}						
				}
			)					
			("target" args "target1f"	)
			("target" args "target2f"	)
			("target" args "target3f"	)
			("target" args "target4f"	)
			("target" args "target5f"	)
			("target" args "target6f"	)
			("target" args "target1b"	)
			("target" args "target2b"	)
			("target" args "target3b"	)
			("target" args "target4b"	)
			("target" args "target5b"	)
			("target" args "target6b"	)
		}
		{if stuff "bullet ap"
			(define "target"
				{if volume %0
					{if rand 0.7
						{ani_play %0 2}	
					else rand 0.5
						{ani_play %0 1.2}	
					else
						{ani_play %0 0.7}
					}						
				}
			)					
			("target" args "target1f"	)
			("target" args "target2f"	)
			("target" args "target3f"	)
			("target" args "target4f"	)
			("target" args "target5f"	)
			("target" args "target6f"	)
			("target" args "target1b"	)
			("target" args "target2b"	)
			("target" args "target3b"	)
			("target" args "target4b"	)
			("target" args "target5b"	)
			("target" args "target6b"	)
		}
		{if stuff "bullet sp"
			(define "target"
				{if volume %0
					{if rand 0.7
						{ani_play %0 1.3}	
					else rand 0.5
						{ani_play %0 0.9}	
					else
						{ani_play %0 0.4}
					}						
				}
			)					
			("target" args "target1f"	)
			("target" args "target2f"	)
			("target" args "target3f"	)
			("target" args "target4f"	)
			("target" args "target5f"	)
			("target" args "target6f"	)
			("target" args "target1b"	)
			("target" args "target2b"	)
			("target" args "target3b"	)
			("target" args "target4b"	)
			("target" args "target5b"	)
			("target" args "target6b"	)
		}
	}
}

{"random_crete"
	{on "break_stuff"
		{if not tagged "open" 
			{volumes "break" disable touch}
			{tags add "open"}
			{delay 1
				{if rand 0.01
					{spawn "p320_v1" "spawn00"}
				else rand 0.01
					{spawn "beretta_v1" "spawn01"}
				else rand 0.01
					{spawn "browning_v1" "spawn02"}
				else rand 0.2
					{spawn "medkit_v1" "spawn02"}
				else rand 0.01
					{spawn "grenade_mk2" "spawn02"}
				else rand 0.1
					{spawn "m84s" "spawn02"}
				else rand 0.01
					{spawn "mp5_v2" "spawn01"}
				else rand 0.01
					{spawn "mp5_v1" "spawn01"}
				else rand 0.1
					{spawn "tec9_v1" "spawn01"}
				else rand 0.1
					{spawn "m93r" "spawn01"}
				else rand 0.1
					{spawn "ksj_v1" "spawn01"}
				else rand 0.1
					{spawn "9x19_single" "spawn01"}
					{spawn "ksj_v1" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
				else rand 0.1
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
				else rand 0.1
					{spawn "556x45_single" "spawn01"}
					{spawn "556x45_single" "spawn02"}
					{spawn "556x45_single" "spawn00"}
					{spawn "556x45_single" "spawn01"}
					{spawn "556x45_single" "spawn02"}
					{spawn "556x45_single" "spawn00"}
					{spawn "556x45_single" "spawn01"}
					{spawn "556x45_single" "spawn02"}
				else rand 0.1
					{spawn "556x45_single" "spawn01"}
					{spawn "556x45_single" "spawn02"}
					{spawn "556x45_single" "spawn00"}
					{spawn "556x45_single" "spawn01"}
					{spawn "556x45_single" "spawn02"}
					{spawn "556x45_single" "spawn00"}
					{spawn "556x45_single" "spawn01"}
					{spawn "556x45_single" "spawn02"}
					{spawn "556x45_single" "spawn00"}
					{spawn "556x45_single" "spawn01"}
					{spawn "556x45_single" "spawn02"}
					{spawn "556x45_single" "spawn00"}
					{spawn "556x45_single" "spawn01"}
					{spawn "556x45_single" "spawn02"}
					{spawn "556x45_single" "spawn00"}
					{spawn "556x45_single" "spawn01"}
					{spawn "556x45_single" "spawn02"}
					{spawn "556x45_single" "spawn00"}
				else rand 0.1
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
				else rand 0.1
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
				else rand 0.1
					{spawn "10x22_single" "spawn01"}
					{spawn "10x22_single" "spawn02"}
					{spawn "10x22_single" "spawn00"}
					{spawn "10x22_single" "spawn01"}
					{spawn "10x22_single" "spawn02"}
				else rand 0.1
					{spawn "10x22_single" "spawn01"}
					{spawn "10x22_single" "spawn02"}
					{spawn "10x22_single" "spawn00"}
					{spawn "10x22_single" "spawn01"}
					{spawn "10x22_single" "spawn02"}
					{spawn "10x22_single" "spawn00"}
					{spawn "10x22_single" "spawn01"}
					{spawn "10x22_single" "spawn02"}
					{spawn "10x22_single" "spawn00"}
					{spawn "10x22_single" "spawn01"}
					{spawn "10x22_single" "spawn02"}
					{spawn "10x22_single" "spawn00"}
					{spawn "10x22_single" "spawn01"}
					{spawn "10x22_single" "spawn02"}
					{spawn "10x22_single" "spawn00"}
				else rand 0.1
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
				else rand 0.1
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x18_single" "spawn02"}
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
					{spawn "10x22_single" "spawn01"}
					{spawn "10x22_single" "spawn02"}
					{spawn "10x22_single" "spawn00"}
					{spawn "10x22_single" "spawn02"}
					{spawn "10x22_single" "spawn00"}
					{spawn "10x22_single" "spawn01"}
				else rand 0.1
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x19_single" "spawn01"}
					{spawn "9x19_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "9x18_single" "spawn02"}
					{spawn "9x18_single" "spawn01"}
					{spawn "9x18_single" "spawn00"}
					{spawn "10x22_single" "spawn02"}
					{spawn "10x22_single" "spawn00"}
					{spawn "10x22_single" "spawn01"}
					{spawn "10x22_single" "spawn02"}
					{spawn "10x22_single" "spawn00"}
				}
			}
		}
	}
}

{"spawned_w"
	{on spawn
		{delay 5
			{spawn "fn_p90_v1" "spawned" x}
			{delay 5
				{spawn "fn_p90_v2" "spawned" x}
				{delay 5
					{spawn "fn_p90_v3" "spawned" x}
					{delay 5
						{spawn "fn_p90_v4" "spawned" x}
						{delay 5
							{spawn "g36_v1" "spawned" x}
							{delay 5
								{spawn "g36_v2" "spawned" x}
								{delay 5
									{spawn "g36_v3" "spawned" x}
									{delay 5
										{spawn "g36_v4" "spawned" x}
										{delay 5
											{spawn "g36_v5" "spawned" x}
											{delay 5
												{spawn "mg36_v1" "spawned" x}
												{delay 5
													{spawn "l86_v1" "spawned" x}
													{delay 5
														{spawn "l86_v2" "spawned" x}
														{delay 5
															{spawn "svd_v2" "spawned" x}
															{delay 5
																{spawn "svd_v3" "spawned" x}
																{delay 5
																	{spawn "svd_v4" "spawned" x}
																	{delay 5
																		{spawn "svd_v5" "spawned" x}
																		{delay 5
																			{spawn "vector_ft_v1" "spawned" x}
																			{delay 5
																				{spawn "vector_ft_v2" "spawned" x}
																				{delay 5
																					{spawn "aa12h_v1" "spawned" x}
																					{delay 5
																						{spawn "acr_v1" "spawned" x}
																						{delay 5
																							{spawn "akm74_v1" "spawned" x}
																							{delay 5
																								{spawn "akm74_v2" "spawned" x}
																								{delay 5
																									{spawn "aksu74_v1" "spawned" x}
																									{delay 5
																										{spawn "aksu74_v2" "spawned" x}
																										{delay 5
																											{spawn "aksu74_v3" "spawned" x}
																											{delay 5
																												{spawn "ash127_v1" "spawned" x}
																												{delay 5
																													{spawn "ash127_v2" "spawned" x}
																													{delay 5
																														{spawn "ash127_v3" "spawned" x}
																														{delay 5
																															{spawn "steyraug_a3" "spawned" x}
																															{delay 5
																																{spawn "steyraug_a3_v2" "spawned" x}
																																{delay 5
																																	{spawn "steyraug_a3_v3" "spawned" x}
																																	{delay 5
																																		{spawn "steyraug_a3_v4" "spawned" x}
																																		{delay 5
																																			{spawn "steyraug_a3_xs_v5" "spawned" x}
																																			{delay 5
																																				{spawn "steyraug_a3_lmg" "spawned" x}
																																				{delay 5
																																					{spawn "b725_v1" "spawned" x}
																																					{delay 5
																																						{spawn "b725_v2" "spawned" x}
																																						{delay 5
																																							{spawn "beretta_v1" "spawned" x}
																																							{delay 5
																																								{spawn "beretta_v2" "spawned" x}
																																								{delay 5
																																									{spawn "bizon_v2" "spawned" x}
																																									{delay 5
																																										{spawn "bizon_v3" "spawned" x}
																																										{delay 5
																																											{spawn "bizon_v4" "spawned" x}
																																											{delay 5
																																												{spawn "browning_v1" "spawned" x}
																																												{delay 5
																																													{spawn "cheytac_v1" "spawned" x}
																																													{delay 5
																																														{spawn "famas_v1" "spawned" x}
																																														{delay 5
																																															{spawn "famas_v2" "spawned" x}
																																															{delay 5
																																																{spawn "famas_v3" "spawned" x}
																																																{delay 5
																																																	{spawn "groza_v1" "spawned" x}
																																																	{delay 5
																																																		{spawn "groza_v2" "spawned" x}
																																																		{delay 5
																																																			{spawn "hk433_v1" "spawned" x}
																																																			{delay 5
																																																				{spawn "hk433_v2" "spawned" x}
																																																				{delay 5
																																																					{spawn "hk433_v3" "spawned" x}
																																																					{delay 5
																																																						{spawn "hk433_v4" "spawned" x}
																																																						{delay 5
																																																							{spawn "l96a1" "spawned" x}
																																																							{delay 5
																																																								{spawn "l96a1_scope" "spawned" x}
																																																								{delay 5
																																																									{spawn "m27_mg" "spawned" x}
																																																									{delay 5
																																																										{spawn "m60_hg" "spawned" x}
																																																										{delay 5
																																																											{spawn "m1911_v1" "spawned" x}
																																																											{delay 5
																																																												{spawn "m1911_v2" "spawned" x}
																																																												{delay 5
																																																													{spawn "m1911_v3" "spawned" x}
																																																													{delay 5
																																																														{spawn "m1911_v4" "spawned" x}
																																																														{delay 5
																																																															{spawn "m1911_v5" "spawned" x}
																																																															{delay 5
																																																																{spawn "mc_milan" "spawned" x}
																																																																{delay 5
																																																																	{spawn "mg42_v1" "spawned" x}
																																																																	{delay 5
																																																																		{spawn "mk14_v1" "spawned" x}
																																																																		{delay 5
																																																																			{spawn "mk14_v2" "spawned" x}
																																																																			{delay 5
																																																																				{spawn "mk14_v3" "spawned" x}
																																																																				{delay 5
																																																																					{spawn "mp40_v1" "spawned" x}
																																																																					{delay 5
																																																																						{spawn "mp5_v1" "spawned" x}
																																																																						{delay 5
																																																																							{spawn "mp5_v2" "spawned" x}
																																																																							{delay 5
																																																																								{spawn "mp5_v3" "spawned" x}
																																																																								{delay 5
																																																																									{spawn "mp5_v4" "spawned" x}
																																																																									{delay 5
																																																																										{spawn "origin_v1" "spawned" x}
																																																																										{delay 5
																																																																											{spawn "origin_v2" "spawned" x}
																																																																											{delay 5
																																																																												{spawn "origin_v3" "spawned" x}
																																																																												{delay 5
																																																																													{spawn "origin_v4" "spawned" x}
																																																																													{delay 5
																																																																														{spawn "p320_v1" "spawned" x}
																																																																														{delay 5
																																																																															{spawn "p320_v2" "spawned" x}
																																																																															{delay 5
																																																																																{spawn "pp19_v1" "spawned" x}
																																																																																{delay 5
																																																																																	{spawn "pp19_v2" "spawned" x}
																																																																																	{delay 5
																																																																																		{spawn "pp19_v3" "spawned" x}
																																																																																		{delay 5
																																																																																			{spawn "rem700" "spawned" x}
																																																																																			{delay 5
																																																																																				{spawn "sr556_v1" "spawned" x}
																																																																																				{delay 5
																																																																																					{spawn "sr556_v2" "spawned" x}
																																																																																					{delay 5
																																																																																						{spawn "sr556_v3" "spawned" x}
																																																																																						{delay 5
																																																																																							{spawn "scar_v1" "spawned" x}
																																																																																							{delay 5
																																																																																								{spawn "scar_v2" "spawned" x}
																																																																																								{delay 5
																																																																																									{spawn "scar_v3" "spawned" x}
																																																																																									{delay 5
																																																																																										{spawn "sg552_v1" "spawned" x}
																																																																																										{delay 5
																																																																																											{spawn "sg552_v2" "spawned" x}
																																																																																											{delay 5
																																																																																												{spawn "sg552_v3" "spawned" x}
																																																																																												{delay 5
																																																																																													{spawn "sg552_v4" "spawned" x}
																																																																																													{delay 5
																																																																																														{spawn "sigsauer_v1" "spawned" x}
																																																																																														{delay 5
																																																																																															{spawn "sigsauer_v2" "spawned" x}
																																																																																															{delay 5
																																																																																																{spawn "sigsauer_v3" "spawned" x}
																																																																																																{delay 5
																																																																																																	{spawn "sigsauer_v4" "spawned" x}
																																																																																																	{delay 5
																																																																																																		{spawn "sig_mcx_v1" "spawned" x}
																																																																																																		{delay 5
																																																																																																			{spawn "sig_mcx_v2" "spawned" x}
																																																																																																			{delay 5
																																																																																																				{spawn "sig_mcx_v3" "spawned" x}
																																																																																																				{delay 5
																																																																																																					{spawn "sig_mcx_v4" "spawned" x}
																																																																																																					{delay 5
																																																																																																						{spawn "stg42" "spawned" x}
																																																																																																						{delay 5
																																																																																																							{spawn "stoner_lmg_a1_v1" "spawned" x}
																																																																																																							{delay 5
																																																																																																								{spawn "stoner_lmg_a1_v2" "spawned" x}
																																																																																																								{delay 5
																																																																																																									{spawn "svu_v1" "spawned" x}
																																																																																																									{delay 5
																																																																																																										{spawn "xm109_v1" "spawned" x}
																																																																																																										{delay 5
																																																																																																											{spawn "xm109_v2" "spawned" x}
																																																																																																											{delay 5
																																																																																																												{spawn "aa12_v1" "spawned" x}
																																																																																																												{delay 5
																																																																																																													{spawn "ameli" "spawned" x}
																																																																																																													{delay 5
																																																																																																														{spawn "bos14" "spawned" x}
																																																																																																														{delay 5
																																																																																																															{spawn "bos14_v2" "spawned" x}
																																																																																																															{delay 5
																																																																																																																{spawn "browning_m2_v1" "spawned" x}
																																																																																																																{delay 5
																																																																																																																	{spawn "colt357" "spawned" x}
																																																																																																																	{delay 5
																																																																																																																		{spawn "dwd_v1" "spawned" x}
																																																																																																																		{delay 5
																																																																																																																			{spawn "fg42" "spawned" x}
																																																																																																																			{delay 5
																																																																																																																				{spawn "fn_fal_v1" "spawned" x}
																																																																																																																				{delay 5
																																																																																																																					{spawn "fn_fal_v1s" "spawned" x}
																																																																																																																					{delay 5
																																																																																																																						{spawn "fn_fal_v2" "spawned" x}
																																																																																																																						{delay 5
																																																																																																																							{spawn "fn_fal_v3" "spawned" x}
																																																																																																																							{delay 5
																																																																																																																								{spawn "fn_mk48_v1" "spawned" x}
																																																																																																																								{delay 5
																																																																																																																									{spawn "fn_mk48_v2" "spawned" x}
																																																																																																																									{delay 5
																																																																																																																										{spawn "fnscar_ssr_v1" "spawned" x}
																																																																																																																										{delay 5
																																																																																																																											{spawn "fnscar_ssr_v2" "spawned" x}
																																																																																																																											{delay 5
																																																																																																																												{spawn "gewerh_v1" "spawned" x}
																																																																																																																												{delay 5
																																																																																																																													{spawn "hk416_v1" "spawned" x}
																																																																																																																													{delay 5
																																																																																																																														{spawn "hk416_v2" "spawned" x}
																																																																																																																														{delay 5
																																																																																																																															{spawn "hudson_v1" "spawned" x}
																																																																																																																															{delay 5
																																																																																																																																{spawn "hudson_v2" "spawned" x}
																																																																																																																																{delay 5
																																																																																																																																	{spawn "kel-tec_v1" "spawned" x}
																																																																																																																																	{delay 5
																																																																																																																																		{spawn "ksj_v1" "spawned" x}
																																																																																																																																		{delay 5
																																																																																																																																			{spawn "lynx300" "spawned" x}
																																																																																																																																			{delay 5
																																																																																																																																				{spawn "m107_hr" "spawned" x}
																																																																																																																																				{delay 5
																																																																																																																																					{spawn "m60_hg_v3" "spawned" x}
																																																																																																																																					{delay 5
																																																																																																																																						{spawn "m79" "spawned" x}
																																																																																																																																						{delay 5
																																																																																																																																							{spawn "m93r_v1" "spawned" x}
																																																																																																																																							{delay 5
																																																																																																																																								{spawn "m9beretta_v1" "spawned" x}
																																																																																																																																								{delay 5
																																																																																																																																									{spawn "m9beretta_v2" "spawned" x}
																																																																																																																																									{delay 5
																																																																																																																																										{spawn "mg42_v2" "spawned" x}
																																																																																																																																										{delay 5
																																																																																																																																											{spawn "p226_v1" "spawned" x}
																																																																																																																																											{delay 5
																																																																																																																																												{spawn "pm" "spawned" x}
																																																																																																																																												{delay 5
																																																																																																																																													{spawn "pp19_01_v1" "spawned" x}
																																																																																																																																													{delay 5
																																																																																																																																														{spawn "remington_r11" "spawned" x}
																																																																																																																																														{delay 5
																																																																																																																																															{spawn "remington_r11_v2" "spawned" x}
																																																																																																																																															{delay 5
																																																																																																																																																{spawn "tar21" "spawned" x}
																																																																																																																																																{delay 5
																																																																																																																																																	{spawn "usp_v1" "spawned" x}
																																																																																																																																																	{delay 5
																																																																																																																																																		{spawn "usp_v2" "spawned" x}
																																																																																																																																																		{delay 5
																																																																																																																																																			{spawn "vss_v1s" "spawned" x}
																																																																																																																																																			{delay 5
																																																																																																																																																				{spawn "vss_v2s" "spawned" x}
																																																																																																																																																				{delay 5
																																																																																																																																																					{spawn "xmlar_v1" "spawned" x}
																																																																																																																																																					{delay 5
																																																																																																																																																						{spawn "walter_ppk" "spawned" x}
																																																																																																																																																						{delay 5
																																																																																																																																																							{spawn "walter_ppq5" "spawned" x}
																																																																																																																																																							{delay 5
																																																																																																																																																								{spawn "walther_p99" "spawned" x}
																																																																																																																																																							}
																																																																																																																																																						}
																																																																																																																																																					}
																																																																																																																																																				}
																																																																																																																																																			}
																																																																																																																																																		}
																																																																																																																																																	}
																																																																																																																																																}
																																																																																																																																															}
																																																																																																																																														}
																																																																																																																																													}
																																																																																																																																												}
																																																																																																																																											}
																																																																																																																																										}
																																																																																																																																									}
																																																																																																																																								}
																																																																																																																																							}
																																																																																																																																						}
																																																																																																																																					}
																																																																																																																																				}
																																																																																																																																			}
																																																																																																																																		}
																																																																																																																																	}
																																																																																																																																}
																																																																																																																															}
																																																																																																																														}
																																																																																																																													}
																																																																																																																												}
																																																																																																																											}
																																																																																																																										}
																																																																																																																									}
																																																																																																																								}
																																																																																																																							}
																																																																																																																						}
																																																																																																																					}
																																																																																																																				}
																																																																																																																			}
																																																																																																																		}
																																																																																																																	}
																																																																																																																}
																																																																																																															}
																																																																																																														}
																																																																																																													}
																																																																																																												}
																																																																																																											}
																																																																																																										}
																																																																																																									}
																																																																																																								}
																																																																																																							}
																																																																																																						}
																																																																																																					}
																																																																																																				}
																																																																																																			}
																																																																																																		}
																																																																																																	}
																																																																																																}
																																																																																															}
																																																																																														}
																																																																																													}
																																																																																												}
																																																																																											}
																																																																																										}
																																																																																									}
																																																																																								}
																																																																																							}
																																																																																						}
																																																																																					}
																																																																																				}
																																																																																			}
																																																																																		}
																																																																																	}
																																																																																}
																																																																															}
																																																																														}
																																																																													}
																																																																												}
																																																																											}
																																																																										}
																																																																									}
																																																																								}
																																																																							}
																																																																						}
																																																																					}
																																																																				}
																																																																			}
																																																																		}
																																																																	}
																																																																}
																																																															}
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
