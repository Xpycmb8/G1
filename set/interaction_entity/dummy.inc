{"physics"
	{on bullet_hit
		{if not linked
			(define "mass"
				(define "blast_physics"
					{if tagged "%mass"
						{if stuff "%stuff"				
							{impulse dir (* %density %imp) }
							;{tags add "%stuff"}
							;{tags add "%density"}
						}
					}
				)		
				("blast_physics" stuff(shell fg) 			imp(13)	)
				("blast_physics" stuff(shell) 				imp(10)	)
				("blast_physics" stuff(rocketlauncher) 		imp(8)	)
				("blast_physics" stuff(zenite cs) 			imp(6)	)
				("blast_physics" stuff(zenite fg) 			imp(7)	)
				("blast_physics" stuff(zenite) 				imp(5)	)
				("blast_physics" stuff(bullet big ap) 		imp(4)	)
				("blast_physics" stuff(bullet big fg) 		imp(5)	)
				("blast_physics" stuff(bullet big) 			imp(3)	)
				("blast_physics" stuff(bullet normal ap) 	imp(2)	)
				("blast_physics" stuff(bullet normal fg) 	imp(1.5))
				("blast_physics" stuff(bullet normal) 		imp(1)	)
				("blast_physics" stuff(bullet small) 		imp(0.5)	)
			)		
			("mass" mass(25000) density(0.000))
			("mass" mass(20000) density(0.000))
			("mass" mass(5000) density(0.0001))
			("mass" mass(4000) density(0.0001))
			("mass" mass(3500) density(0.0001))
			("mass" mass(3000) density(0.0001))
			("mass" mass(2000) density(0.002))
			("mass" mass(1900) density(0.01))
			("mass" mass(1800) density(0.02))
			("mass" mass(1700) density(0.03))
			("mass" mass(1600) density(0.045))
			("mass" mass(1500) density(0.05))
			("mass" mass(1400) density(0.07))
			("mass" mass(1300) density(0.09))
			("mass" mass(1200) density(0.1))
			("mass" mass(1100) density(0.14))
			("mass" mass(1000) density(0.2))
			("mass" mass(900) density(0.28))
			("mass" mass(800) density(0.32))
			("mass" mass(700) density(0.4))
			("mass" mass(600) density(0.45))
			("mass" mass(500) density(0.55))
			("mass" mass(400) density(0.63))
			("mass" mass(300) density(0.71))
			("mass" mass(200) density(0.8))
			("mass" mass(150) density(0.9))
			("mass" mass(100) density(0.93))
			("mass" mass(75) density(1.1))
			("mass" mass(50) density(1.7))
			("mass" mass(35) density(2.2))
			("mass" mass(25) density(2.7))
			("mass" mass(10) density(3.5))
			("mass" mass(5) density(3.7))
			("mass" mass(1)  density(4))
		}
	}
	{on contact
		(define "contact_physics_entity_mass"
			{if effector "vehicle"
				{if tagged "%0"
					{if min_speed 40
						(define "disable_contact_0")
						{impulse up 0.5 dir %1}
;						{tags add "%1"}
;						{tags add "%0"}
					else min_speed 20
						(define "disable_contact_0")
						{impulse up 0.2 dir %2}
;						{tags add "%2"}
;						{tags add "%0"}
					else min_speed 5
						{impulse up 0.1 dir %3}
;						{tags add "%3"}
;						{tags add "%0"}
					}
				}
			}
		)
		("contact_physics_entity_mass" args		1	5 		3		1 	)
		("contact_physics_entity_mass" args		10	4 		1		1 	)
		("contact_physics_entity_mass" args		25 	3.5 	1 		0.5 )
		("contact_physics_entity_mass" args		50 	2 		0.8 	0.3 )	
		("contact_physics_entity_mass" args		100 1.7 	0.4  	0.2 )	
		("contact_physics_entity_mass" args		150 1.5 	0.4  	0.2 )	
		("contact_physics_entity_mass" args		200 1.2 	0.3  	0.1 )	
		("contact_physics_entity_mass" args		300 1 		0.1  	0 	)
		("contact_physics_entity_mass" args		400 0.8 	0.1  	0 	)
		("contact_physics_entity_mass" args		500 0.1 	0.1  	0 	)
		("contact_physics_entity_mass" args		800 0 		0 		0 	)
	}
}

{"auto_grass"
	{on spawn
		(define "disable_contact_1")
		{impulse up 12 rnd_dir 25 no_position}		
		;{add_view "smoke_aero_2_small" "smoke" "root"}
		;{view start "smoke"}
		{delay 20 {delete}}
	}
	{on overlap begin	
		{if effector "bush_tiny"
			{start_sound "human/talk/rus/impossibility_to_execute_an_order/v2/"}
			{delete}
		}
	}
	{on contact
		{impulse up 12 forward 25 no_position}		
		{start_sound "weapon/click/empty_gun_shot"}
		;{delete}
	}
	{on ground_hit
		(define "disable_contact_1")
		{if terrain_fx "grass" 
			{start_sound "hit/generic/metal_small/15/"}	
			{add_view "veterancy_view" "view" "root"}
			{view start "view"}	
			{delete}
		else terrain_fx "ground" 
			{start_sound "hit/generic/metal_small/15/"}	
			{add_view "veterancy_view" "view" "root"}
			{view start "view"}	
			{delete}
		else
			{delete}
		}
	}
}



{"trace_linear"
	{on spawn 
		{if rand 0.2
			{ani_play "trace1" 1.5 callback}
		else rand 0.2
			{ani_play "trace2" 1.8 callback}
		else rand 0.2
			{ani_play "trace3" 2 callback}
		else rand 0.2
			{ani_play "trace4" 1.9 callback}
		else
			{ani_play "trace5" 2.6 callback}
		}
	}
	{on animation_end "trace1"
		{delete}
	}
	{on animation_end "trace2"
		{delete}
	}
	{on animation_end "trace3"
		{delete}
	}
	{on animation_end "trace4"
		{delete}
	}
	{on animation_end "trace5"
		{delete}
	}
}







{"dummy"
	{on "stop"	{view stop ""}}
	{on "pause"	{view pause ""}}
	{on "delete"{delete}}
}
{"stimpack"
	{on "undermine"
		{delete}
	}
}
{"armorplate"
	{on "undermine"
		{delete}
	}
}
{"stim"
	{on "undermine"
		{delete}
	}
}

{"spawn_delete"
	{on spawn	
		{delay 1
			{delete}
		}
	}
}
{"hidden_ui"
	{on spawn	
		{bone hide "ui"}
	}
}
{"sm_upper"
	{on spawn 
		{impulse up 1 dir 1 cx 5 2 cy 5 2 rnd_dir 2 no_position}
	}
}
{"wood_crete_break"
	{on "break_stuff"
		{if not tagged "open" 
			{start_sound "push/ammobox/close/"}
		}
	}
}
{"armor_place"
	{on spawn
		{if linked
			{call "hide"}
		}
	}
	; {on bullet_hit
		; {spawn "metal_hit_zenite_cs"}
	; }
	{on pierce 
		{tear "piece_small_steel" bone "armor"
			{spawn "metal_hit_trace_burn" }
			{impulse up 1 0.5 dir 1 0.5}
		}
		{delete}
	}
	{on "hide"	
		{bone hide "armor"}
	}
}


; {"fxt_veterancy"
	; {on spawn
		; ;{bone hide "ring" }
	; }
	; {on animation_event "start_fx"	
		; {call "start_fx"}	
	; }
; ;	{on animation_event "end"	
; ;	}
	; {on "start_fx"	
		; {if not tagged "start"
			; {start_sound "gui/veterancy/start"}	
			; {burn volume "ems" fx "veterancy_fx" time 5 fake even_law}					
			; {tags add "start"}
			; {delay 1
				; {hide 0.5}
				; {delay 1
					; {delete}
				; }
			; }
		; }
	; }
; }




{"blocked_volume"
	{on spawn
		{delay 110.5
			{delete}
		}
	}
	{on bullet_hit
		{if stuff "bullet"
			{with_effector {delete}}
		}
	}
}





{"ammo_explode"
	{on spawn
		{impulse up 1 dir 4 cx 5 2 cy 5 2 rnd_dir 90 no_position}
		{start_sound "expl_emitters/magazine/ext/"}	
		{blastwave c4 0.4 r0 0.4 r1 0.4}		
		{spawn "burn_magazine" }
		{delay 1 0.7
			{start_sound "expl_emitters/magazine/ext/"}	
			{blastwave c4 0.4 r0 0.4 r1 0.4}		
			{spawn "burn_magazine" }
			{delete}
		}
	}
}




{"knife_armed"
	{on spawn 
		{volumes "knife_armed" disable contact}
	}
	{on contact
		{if volume "knife_armed" 
			{start_sound "hit/generic/metal_small/15/"}	
		}
	}
}

{"rpg7_fraction"
	{on spawn
		{add_view	"rpg7_fraction_burn"			"fraction_burn"		"root"}
		{view start "fraction_burn"}
		{impulse up 0 dir 0.4 forward 5 2 com  fx 0}		
		{delay 0.1
			{tex_morph "burn" 1}
		}
		{delay 4
			{hide 0.3}
		}
	}
}









{"stuff_broken"
	{on ground_hit
		{tags remove "link_weapon"}
		{if "broken"
			{if volume "parts"
				{if contact_velocity 10
					{if rand 0.4
						{call "broken_stuff"}
						{tear "piece_small_steel" bone from_volume
							{impulse up 0.1}
						}
					}
				}
			}
		}
	}
	{on blast sync 
		{if stuff "orientation_melee_front"
			{if volume "parts"
				{if rand 0.3
					{call "broken_stuff"}
					{tear "piece_small_steel" bone from_volume
						{impulse up 4 1 dir 2 1}
					}
				}
			}
		}
		;{if volume "check_move"
			{if stuff "orientation_gun_start" 
				{if not tagged "transform"
					{tags add "transform"}
					{burn volume "select" fx "smoke_mist_run" time 3 fake even_law}
					{ani_play "invisible" 1}
				}
			}
			{if stuff "orientation_gun_end" 
				{if tagged "transform"
					{tags remove "transform"}
					{burn volume "select" fx "smoke_mist_run" time 3 fake even_law}
					{ani_play "invisible" -1}
				}
			}
		;}
		{if not tagged "link_weapon"
			{if volume "parts"
				{if min_energy 6
					{call "broken"}
				else min_energy 2
					{tear "piece_small_steel" bone from_volume
						{impulse up 4 1 dir 2 1}
					}
					{if rand 0.5
						{call "broken"}
					}
				}
			}
		else prop "reactive_stuff"
			{if min_energy 6
				{call "broken_blast"}
			}			
		}
	}
	{on pierce 
		;{if not tagged "link_weapon"
			(define "hit_system"
				{if volume "parts"
					{if stuff %0
						{if rand %1
							{call "broken_stuff"}
							{tear "piece_small_steel" bone from_volume
								%2
							}
						}
					}
				else volume "parts_no_damage"
					{if stuff %0
						{if rand %1
							{tear "piece_small_steel" bone from_volume
								%2
							}
						}
					}
				}
			)	
;								tags (0) 						rand (1)	 impact (2)
			("hit_system" args "bullet stackable small"  		0.1  		{impulse dir 1 0.5 	cx 1 0.5 cy 1 0.5 no_position}   )
			("hit_system" args "bullet big ap"  	  		 	0.7  		{impulse dir 7 1 	cx 2 1 	cy 2 1 no_position}   )
			("hit_system" args "bullet big sp"  	  			0.6  		{impulse dir 4 1 	cx 2 1 	cy 2 1 no_position}    )
			("hit_system" args "zenite fg"  	  			 	0.9  		{impulse dir 12 3 	cx 7 3 	cy 7 3 no_position}   )
			("hit_system" args "zenite ap"  	  			 	0.9  		{impulse dir 7 3 	cx 4 2 	cy 4 2 no_position}   )
			("hit_system" args "zenite"  	  				 	0.7  		{impulse dir 7 3 	cx 4 2 	cy 4 2 no_position}   )
			("hit_system" args "shell"  	  				 	1  			{impulse dir 12 5 	cx 5 3 	cy 5 3 no_position}   )
		;}
	}
	{on "broken_stuff"		
		{volumes disable touch select}
		{set "broken" 1}
	}
	{on "broken_delete"
		{volumes disable touch select}
		{set "broken" 1}
		(define "cut_part"
			{if rand %1
				{spawn "sparks01" "fxshell" x}				
				{tear "piece_small_steel" bone %0
					{impulse up 5 1 dir 2 1}
				}
			}
		)	
		("cut_part" args "muzzle"	 		0.6)
		("cut_part" args "barrel"	 		0.6)
		("cut_part" args "trigger"	 		0.5)
		("cut_part" args "shutter"	 		0.5)
		;("cut_part" args "receiver"	 		0.5)
		("cut_part" args "recoil"	 		0.5)
		("cut_part" args "stock"	 		0.5)
		("cut_part" args "slide"	 		0.5)
		("cut_part" args "part1"	 		0.5)
		("cut_part" args "part2"	 		0.5)
		("cut_part" args "part3"	 		0.5)
		("cut_part" args "part4"	 		0.5)
		("cut_part" args "part8"	 		0.5)
		("cut_part" args "part7"	 		0.5)
		("cut_part" args "part6"	 		0.5)
		("cut_part" args "part5"	 		0.5)
		{delay 1
			;{delete}
		}
	}
	{on "broken_blast"
		{bone hide "ammo_bone"}
		{volumes disable touch select}
		{spawn "distant_small_expl"}			
		;{blastwave c4 8 r0 4 r1 4}	
		{set "broken" 1}
		(define "cut_part"
			;{if rand %1
				{spawn "sparks01" }				
				{tear "piece_small_steel" bone %0
					{impulse up 5 1 dir 2 1 cx 4 2}
				}
			;}
		)	
		("cut_part" args "part1"	 		)
		("cut_part" args "part2"	 		)
		("cut_part" args "part3"	 		)
		("cut_part" args "part4"	 		)
		("cut_part" args "grip"	 			)
		("cut_part" args "sight"	 		)
	}
	{on "broken"
		{volumes disable touch select}
		{set "broken" 1}
		(define "cut_part"
			{if rand %1
				{spawn "sparks01" "fxshell" x}				
				{tear "piece_small_steel" bone %0
					{impulse up 5 1 dir 2 1}
				}
			}
		)	
		("cut_part" args "muzzle"	 		0.6)
		("cut_part" args "barrel"	 		0.6)
		("cut_part" args "trigger"	 		0.5)
		("cut_part" args "shutter"	 		0.5)
		;("cut_part" args "receiver"	 		0.5)
		("cut_part" args "recoil"	 		0.5)
		("cut_part" args "stock"	 		0.5)
		("cut_part" args "slide"	 		0.5)
		("cut_part" args "part1"	 		0.5)
		("cut_part" args "part2"	 		0.5)
		("cut_part" args "part3"	 		0.5)
		("cut_part" args "part4"	 		0.5)
		("cut_part" args "part8"	 		0.5)
		("cut_part" args "part7"	 		0.5)
		("cut_part" args "part6"	 		0.5)
		("cut_part" args "part5"	 		0.5)
	}
	{on "broken_drop"
		{volumes disable touch select}
		{set "broken" 1}
		(define "cut_part"
			{if rand %1
				{tear "piece_small_steel" bone %0
					{impulse up 2 1 dir 2 1}
				}
			}
		)	
		("cut_part" args "barrel"	 		0.6)
		("cut_part" args "trigger"	 		0.5)
		;("cut_part" args "receiver"	 		0.5)
		("cut_part" args "recoil"	 		0.5)
		("cut_part" args "stock"	 		0.5)
		("cut_part" args "slide"	 		0.5)
		("cut_part" args "part1"	 		0.5)
		("cut_part" args "part"	 			0.5)
		{delete}
	}
	{on contact
		{if not tagged "link_weapon"
			{if "broken"
				{if volume "parts"
					{if effector "fraction_small" ;дробь
						{if contact_velocity 2
							{if rand 0.3
								{call "broken_stuff"}
								{tear "piece_small_steel" bone from_volume
									{impulse up 2 1 dir 2 1}
								}
							}
						}
					else effector "vehicle" 
						{if contact_velocity 25
							{if rand 0.4
								{call "broken_stuff"}
								{tear "piece_small_steel" bone from_volume
									{impulse up 2 1 dir 2 1}
								}
							}
						}
					}
				}
			}
		}
	}
}

{"fx_blast_smoke_activate"
	{on spawn
		{add_view "smoke_cover-up_norm"		"trace" "root"}
		{add_view "mk_flare"		"trace" "root"}
		{view start "trace"}
		{delay 0.5 0.2
			{spawn "smoke_screen_blast"}		
			{delete}
		}
	}
}


{"fx_blast_smoke_activate_small"
	{on spawn
		{add_view "smoke_cover-up_norm"		"trace" "root"}
		{add_view "mk_flare_small"			"trace" "root"}
		{view start "trace"}
		{delay 0.3 0.1
			{spawn "smoke_screen_blast"}		
			{delete}
		}
	}
}








{"fx_blast_smoke"
	{on spawn
		{call "activate"}
		{call "add_smoke"}
	}
	{on "add_smoke"
		{add_view "smoke_cover-up_small_fast"	"smoke1" "root"}
		{add_view "smoke_cover-up_norm"			"smoke2" "root"}
		{add_view "smoke_cover-up_big"			"smoke3" "root"}
	}
	{on "activate"
		{view start "smoke1"}
		{delay 3
			{volumes "smoke1" enable visible}
			{update_visibility_patch}
			{view stop "smoke1"}
			{view start "smoke2"}
		}
		{delay 7
			{volumes "smoke1" disable visible}
			{volumes "smoke2" enable visible}
			{update_visibility_patch}
			{view stop "smoke2"}
			{view start "smoke3"}
		}
		{delay 37
			{view stop "smoke3"}
		}
		{delay 40
			{hide 1}
		}
	}
}


{"wood_plate"
	{on spawn 
	}
	{on blast_hit 
		{if not "texmods"
			{set "texmods" 1}
			{if min_energy 1
				{tex_morph "d" 1}
			else 
				{tex_morph "b" 1}
			}
		}
	}	
	{on bullet_hit
		{if not "texmods"
			{set "texmods" 1}
			{tex_morph "d" 1}
		}
	}
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{if volume "fire"
				{call "_burned"}
			}
		}
	}
	{on "_burned"
		{set "texmods" 1}
		{tags add "set"}
		{fire radius 1 time 7 heating 1}
		{tex_morph "b" 12}
		{burn volume fx "smoke_camp_storeable" time 6 fake even_law}
		;{add_view "smoke_dead_small1" "burn_fire"		"basis"}
		;{view start "burn_fire"}
		;{delay 5 2	{view stop "burn_fire"}}
	}
}

{"texmod_sets"
	{on spawn 
		{if not "texmods"
			{set "texmods" 1}
			{if rand 0.3
				{tex_mod "1"}
			else rand 0.3
				{tex_mod "2"}
			else rand 0.3
				{tex_mod "3"}
			else rand 0.3
				{tex_mod "4"}
			else rand 0.3
				{tex_mod "5"}
			else rand 0.3
				{tex_mod "6"}
			else rand 0.3
				{tex_mod "7"}
			else rand 0.3
				{tex_mod "8"}
			else rand 0.3
				{tex_mod "9"}
			else rand 0.3
				{tex_mod "10"}
			else rand 0.3
				{tex_mod "11"}
			else rand 0.3
				{tex_mod "12"}
			}
		}
	}
}




{"radio_bomb"
	{on spawn
		{tags add "radio_bomb"}
		{impulse up 0.4}
		{delay 3
			{call "radio_bomb"}
		}	
	}
	{on "_explosion"
		{spawn "ex_fragment_cl"}
		{stuff_detonate}
	}
}

{"match"
	{on spawn
		{add_view "match_view" "smoke" "fx_flame"}
		{delay 1
			{view start "smoke"}
			{delay 3
				{fire radius 0.1 time 0.5 heating 0.8}
			}
		}
		{delay 15
			{delete}
		}
	}
}

{"source_fire_1m"
	{on spawn
		{add_view "fire_ground_set" "smoke" "root"}
		{delay 0.5
			{view start "smoke"}
			{fire radius 0.5 time 99999 heating 3}
		}
	}
}



{"blind"
	{on spawn
		{stuff_detonate}
	}
}
{"glass"
	{on blast_hit 
		{delete}
	}
	{on bullet_hit 
		{delete}
	}
}



{"old_stuff"
	{on blast_hit 
		{if not tagged "empty"
			{tags add "empty" }
			{spawn "ex_old_dust"}
		}
	}
	{on bullet_hit 
		{if not tagged "empty"
			{tags add "empty" }
			{spawn "ex_old_dust"}
		}
	}
}


{"piece_whell_fire"
	{on spawn
		{volumes disable contact }	
		{delay 0.1
		  {volumes enable contact}	
		}
		{impulse up 0.1}
		{add_view "whells_fire_down"	"fall"	"basis"	}
		{view start "fall"}
		{delay 3
			{hide 3}
		}	
	}
	{on contact
		{fire radius 0.1 time 0.1 heating 0.3 effector}
		{with_effector
			{burn fx "fire_hit_burn" time 10 fake even_law}
		}
		{delete}
	}
	{on ground_hit
		{fire radius 0.1 time 0.1 heating 0.3 effector}
		{spawn "fire_ground_set"}
		{delete}
	}
}

{"fire_whells"
	{on spawn
		{call "rand_fire"}
		{delay 3
			{delete}
		}	
	}
	{on "rand_fire"
		{if rand 0.3 
			{spawn "piece_wheel_fire" "fire_whells"}
		else rand 0.5
			{spawn "piece_wheel_fire" "fire_whells1"}
		else rand 0.8
			{spawn "piece_wheel_fire" "fire_whells2"}
		else
			{spawn "piece_wheel_fire" "fire_whells3"}
		}
		{delay 1 2.1
			{call "rand_fire"}
		}
	}
}

{"pile_land"
	{on spawn
		{if not "texmods"
			{if rand 0.7
				{scale from 0.9 to 0.9 time 0.1}
			else rand 0.3
				{scale from 0.7 to 0.7 time 0.1}
			else
				{scale from 0.5 to 0.5 time 0.1}
			}
		}
	}
}

{"fx_dust"
	{on spawn
		{add_view "smoke_fx_dust"	"tail"	"floatsam1"	}
		{view start "tail"}
		{delay 3
			{view stop "tail"}
		}
	}
	{on contact
		{delete}
	}	
	{on ground_hit
		{delete}
	}
}




{"fx_obstacles"
	{on spawn	
		{impulse up 1 0.5 rnd_dir 2 forward 4 com  }
		{delay 1
			{delete}
		}	
	}
	{on contact
		{delete}
	}	
	{on ground_hit
		{delete}
	}
}

{"fx_shot_obstacles"
	{on spawn	
		{impulse up 0 dir -1 1 forward 400 com  fx -2 4}
		{delay 1
			{delete}
		}	
	}
	{on contact
		{delete}
	}	
	{on ground_hit
		{delete}
	}
}
{"fx_shot_heavy_obstacles"
	{on spawn	
		{impulse up 0 dir -1 1 forward 700 com  fx -2 4}
		{delay 1
			{delete}
		}	
	}
	{on contact
		{delete}
	}	
	{on ground_hit
		{delete}
	}
}

{"fx_obstacles_fast"
	{on spawn	
		{impulse up 1 0.5 rnd_dir 2 forward 4 com  }
		{delay 1
			{delete}
		}	
	}
	{on contact
		{delete}
	}	
	{on ground_hit
		{delete}
	}
}


{"decal_blood_ground"
	{on overlap begin
		{if effector "human"
			{with_effector
				{tags add "blood_step"}
				{call "blood_step"}
			}
		}
	}
}



{"blood_part_fx"
	{on spawn	
		{impulse up 2 0.5 rnd_dir 2 forward -6 -3 com  }
		;{impulse up 0 forward -2 com }
		{delay 3
			{delete}
		}	
	}
	{on contact 
		{if not effector "human"
			{delete}
		}	
	}	
	{on ground_hit
		{spawn "blood_check"}
		{spawn "bloodsplatter"}
		{delete}
	}
}

{"blood_part_fx_ground"
	{on spawn	
		{delay 3
			{delete}
		}	
	}
	{on contact 
		{if not effector "human"
			{delete}
		}	
	}	
	{on ground_hit
		{spawn "blood_check"}
		{spawn "bloodsplatter"}
		{delete}
	}
}


{"blood_part_fx_fast"
	{on spawn	
		{impulse up 2 0.5 rnd_dir 2 forward -12 com  }
		;{impulse up 0 forward -2 com }
	}
	{on contact
		{if not effector "human"
			{delete}
		}	
	}	
	{on ground_hit
		{spawn "blood_check"}
		{spawn "bloodsplatter"}
		{delete}
	}
}
{"blood_part_fx_inv"
	{on spawn	
		{impulse up 0.5 rnd_dir 2 forward 6 2 com  }
		;{impulse up 0 forward -2 com }
	}
	{on contact
		{if not effector "human"
			{delete}
		}	
	}	
	{on ground_hit
		{delete}
	}
}


{"oilsplatter"
	{on spawn
		{if rand 0.5
			{scale from 0.4 to 2 time 20}
		else
			{scale from 0.2 to 2.5 time 25}
		}
		{if rand 0.3
			{tex_mod "1"}
		else
			{tex_mod "2"}
		}
	}
}

{"oil_drop"
	{on spawn	
		{add_view 	"drops_oil_small" 	"oil_drop" "root"}
		{view start	"oil_drop"}
		{impulse up 0.2 0.1 rnd_dir 1 0.5 cx 12}
	}
	{on ground_hit
		{spawn "oilsplatter" random_orientation}
		{delete}
	}
}

{"bush_destroy"
	{on spawn	
		{if rand 0.8
			{scale from 0.8 to 0.8 time 0}
		else rand 0.6
			{scale from 0.5 to 0.5 time 0}
		else rand 0.3
			{scale from 0.2 to 0.2 time 0}
		}
		{impulse up 2 1 dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}	
	}
	{on contact
		{volumes disable contact}
		{delay 0.3
			{volumes enable contact}
		}
		{if effector "vehicle"
			{if min_speed 20
				{if rand 0.5
					{delete}
				}
			}
		}
		{if not effector "human"
			{if min_speed 15
				{spawn "hay_hit_wood" }
			}
		}
	}
	{on ground_hit
		{spawn "hay_hit_wood" }
	}
}


{"glass_prop"
	{on blast 
		{spawn "glass_hit" }
		{delete}
	}
	{on bullet_hit
		{if stuff "zenite"
			{impulse up 2 1}
			{spawn "glass_hit4" }
			{spawn "glass_hit"}
			{delete}
		else stuff "bullet big"
			{spawn "glass_hit"}
			{delete}
		else stuff "bullet"
			{spawn "glass_hit4"}
			{delete}
		}
	}
	{on contact
		{if not effector "human"
			{if min_speed 10
				{spawn "glass_hit4"}
				{delete}
			}
		}
	}
	{on ground_hit
		{if min_speed 10
			{spawn "glass_hit4"}
			{delete}
		}
	}
}




{"glass_bottle"
	{on blast 
		{spawn "bottle_sharp_blast" "basis" x}
		{spawn "glass_hit" "basis"}
		{delete}
	}
	{on bullet_hit
		{if stuff "bullet sm_ic"
			{spawn "bottle_sharp_blast" "basis" x}
			{spawn "glass_hit" "basis"}
			{delete}
		else stuff "hmgun"
			{spawn "bottle_sharp_blast" "basis" x}
			{spawn "glass_hit" "basis"}
			{delete}
		else stuff "zenite"
			{impulse up 2 1}
			{spawn "glass_hit4" }
			{spawn "bottle_sharp_blast" "basis" x}
			{spawn "glass_hit" "basis"}
			{delete}
		else stuff "bullet big"
			{spawn "bottle_sharp_blast" "basis" x}
			{spawn "glass_hit" "basis"}
			{delete}
		else stuff "bullet"
			{spawn "glass_hit4" "basis"}
			{spawn "bottle_sharp" "basis" x}
			{delete}
		}
	}
	{on contact
		{if not effector "human"
			{if min_speed 13
				{spawn "glass_hit4" "basis"}
				{spawn "bottle_sharp" "basis" x}
				{delete}
			}
		}
	}
	{on ground_hit
		{if min_speed 15
			{spawn "glass_hit4" "basis"}
			{spawn "bottle_sharp" "basis" x}
			{delete}
		}
	}
}
{"small_glass"
	{on blast 
		{spawn "glass_hit_sm"}
		{delete}
	}
	{on bullet_hit 
		{spawn "glass_hit_sm"}
		{delete}
	}
	{on contact
		{if not effector "human"
			{if min_speed 25
				{delete}
				{if rand 0.2
					{spawn "glass_hit_sm" }
				}
			}
		}
	}
	{on ground_hit
		{delete}
		{if min_speed 1
			{if rand 0.2
				{spawn "glass_hit_sm" }
			}
		}
	}
}

{"small_glass_no_contact"
	{on blast 
		{spawn "glass_hit_sm"}
		{delete}
	}
	{on bullet_hit 
		{spawn "glass_hit_sm"}
		{delete}
	}
	{on ground_hit
		{if min_speed 4
			{if rand 0.1
				{delete}
				{spawn "glass_hit_sm" }
			}
		}
	}
}

{"small_glass_crushed"
	{on spawn
		(define "blast"
			{tear "piece_small_glass_crushed_small" bone "%bone"
				{impulse up 0.1  dir 0.1 0.1 }
			}
		)
		("blast"  bone(broken_29))
		("blast"  bone(broken_28))
		("blast"  bone(broken_27))
		("blast"  bone(broken_26))
		("blast"  bone(broken_25))
		("blast"  bone(broken_24))
		("blast"  bone(broken_23))
		("blast"  bone(broken_22))
		("blast"  bone(broken_21))
		("blast"  bone(broken_20))
		("blast"  bone(broken_19))
		("blast"  bone(broken_18))
		("blast"  bone(broken_17))
		("blast"  bone(broken_16))
		("blast"  bone(broken_15))
		("blast"  bone(broken_14))
		("blast"  bone(broken_13))
		("blast"  bone(broken_12))
		("blast"  bone(broken_11))
		("blast"  bone(broken_10))
		("blast"  bone(broken_09))
		("blast"  bone(broken_08))
		("blast"  bone(broken_07))
		("blast"  bone(broken_06))
		("blast"  bone(broken_05))
		("blast"  bone(broken_04))
		("blast"  bone(broken_03))
		("blast"  bone(broken_02))
		("blast"  bone(broken_01))
		("blast"  bone(broken_00))
	}
	{on contact overload
		{volumes disable contact }
		{delay 0.1
			{volumes enable contact }
		}
		{if volume "shard" 
			{if rand 0.7
				{spawn "glass_hit4"}
				{tear "piece_small_glass_crushed" bone from_volume
					{impulse dir 0.2}
				}
			}
		}	
		{if volume "body" 
			{delete}
		}
	}
	{on ground_hit
		{volumes disable contact }
		{delay 0.01
			{volumes enable contact }
		}
		{if volume "body" 
			{delete}
		}
		{if contact_velocity 3
			{if volume "shard" 
				{if rand 0.7
					{spawn "glass_hit_small"}
					{tear "piece_small_glass_crushed" bone from_volume
						{impulse dir 0.2}
					}
				}
			}	
		}	
	}
	{on blast 
		{if rand 0.2
			{spawn "glass_hit4"}
			{delete}
		}
	}
	{on bullet_hit 
		{if volume "shard" 
			(define "bullet_hit"
				{if stuff %stuff
					{if rand %rand
						{spawn "glass_hit_small"}
						{tear "piece_small_glass_crushed" bone from_volume
							%impact
						}
					}
				}
			)
			;                  stuff   		   
			("bullet_hit" stuff("shell")			rand(1) 		impact({impulse up 1 0.5  	dir 7 4		cx 4 2 cy 4 2  	no_position}))
			("bullet_hit" stuff("heavy_zenite")		rand(1) 		impact({impulse up 3 1 		dir 5 2 	cx 7 3 cy 7 3  	no_position}))
			("bullet_hit" stuff("zenite")			rand(0.4) 		impact({impulse up 2 1 		dir 4 2 	cx 4 1 cy 4 1 	no_position}))
			("bullet_hit" stuff("bullet big")		rand(0.3) 		impact({impulse up 2 1 		dir 2 1 	cx 2 1 cy 2 1 	no_position}))
			("bullet_hit" stuff("bullet normal")	rand(0.1) 		impact({impulse up 1 0.5    dir 1 0.5 	cx 0.5 cy 0.5  	no_position}))
			("bullet_hit" stuff("bullet small")		rand(0.05) 		impact({impulse up 0.2 0.1 	dir 0.5 	cx 0.5 cy 0.5  	no_position}))
		}
		{if rand 0.1
			{spawn "glass_hit_small"}
			{delete}
		}
	}
}


{"small_glass_crushed2"
	{on spawn
		{volumes disable contact }
		{delay 0.1
			{volumes enable contact }
		}
	}
	{on contact overload
		{if not effector "big_glass_frame" 
			{if not effector "small part" 
				{if volume "shard" 
					{if rand 0.7
						{spawn "glass_hit4"}
						{delete}
					}
				}	
				{if volume "body" 
					{delete}
				}
			}
		}
	}
	{on ground_hit
		{volumes disable contact }
		{delay 0.01
			{volumes enable contact }
		}
		{if volume "body" 
			{delete}
		}
		{if contact_velocity 3
			{if volume "shard" 
				{spawn "glass_hit_small"}
				{delete}
			}	
		}	
	}
	{on blast 
		{if rand 0.5
			{spawn "glass_hit4"}
			{delete}
		}
	}
	{on bullet_hit 
		{if rand 0.5
			{spawn "glass_hit4"}
			{delete}
		}
	}
}


{"gypsum"
	{on contact overload
		{if volume "body" 
			{delete}
		}
	}
	{on ground_hit
		{volumes disable contact }
		{delay 0.01
			{volumes enable contact }
		}
		{if volume "body" 
			{delete}
		}
		{if contact_velocity 5
			{if volume "shard" 
				{if rand 0.7
					{spawn "gypsum_crush_small"}
					{tear "piece_medium_gypsum" bone from_volume
						{impulse dir 0.5}
					}
				}
			}	
		}	
	}
	{on blast 
		{if rand 0.2
			{spawn "gypsum_crush_small"}
			{delete}
		}
	}
	{on bullet_hit 
		{if volume "shard" 
			(define "bullet_hit"
				{if stuff %stuff
					{if rand %rand
						{spawn "gypsum_crush_small"}
						{tear "piece_medium_gypsum" bone from_volume
							%impact
						}
					}
				}
			)
			;                  stuff   		   
			("bullet_hit" stuff("shell")			rand(1) 		impact({impulse up 1 0.5  	dir 7 4		cx 4 2 cy 4 2  	no_position}))
			("bullet_hit" stuff("heavy_zenite")		rand(1) 		impact({impulse up 3 1 		dir 5 2 	cx 7 3 cy 7 3  	no_position}))
			("bullet_hit" stuff("zenite")			rand(0.4) 		impact({impulse up 2 1 		dir 4 2 	cx 4 1 cy 4 1 	no_position}))
			("bullet_hit" stuff("bullet big")		rand(0.3) 		impact({impulse up 2 1 		dir 2 1 	cx 2 1 cy 2 1 	no_position}))
			("bullet_hit" stuff("bullet normal")	rand(0.1) 		impact({impulse up 1 0.5    dir 1 0.5 	cx 0.5 cy 0.5  	no_position}))
			("bullet_hit" stuff("bullet small")		rand(0.05) 		impact({impulse up 0.2 0.1 	dir 0.5 	cx 0.5 cy 0.5  	no_position}))
		}
		{if rand 0.1
			{spawn "gypsum_crush_small"}
			{delete}
		}
	}
}


{"glass_sharp"
	{on spawn
		(define "cut_part"
			{tear "piece_small_glass" bone %0
				{impulse up 0.3 0.1}
			}
		)					
		("cut_part" args "glass_sharp_00"	)
		("cut_part" args "glass_sharp_01"	)
		("cut_part" args "glass_sharp_02"	)
		("cut_part" args "glass_sharp_03"	)
		("cut_part" args "glass_sharp_04"	)
		("cut_part" args "glass_sharp_05"	)
		("cut_part" args "glass_sharp_06"	)
		("cut_part" args "glass_sharp_07"	)
	}
}

{"glass_sharp_blast"
	{on spawn
		(define "cut_part"
			{tear "piece_small_glass" bone %0
				{impulse up 2 1 dir 6 3 cx 3 2 cy 3 2 rnd_dir 3 no_position}	
			}
		)					
		("cut_part" args "glass_sharp_00"	)
		("cut_part" args "glass_sharp_01"	)
		("cut_part" args "glass_sharp_02"	)
		("cut_part" args "glass_sharp_03"	)
		("cut_part" args "glass_sharp_04"	)
		("cut_part" args "glass_sharp_05"	)
		("cut_part" args "glass_sharp_06"	)
		("cut_part" args "glass_sharp_07"	)
	}
}



{"broken"
	{on blast 
		{set_skeleton "-x"}
		{set "broken" 1}
	}
	{on bullet_hit 
		{set_skeleton "-x"}
		{set "broken" 1}
		{if stuff "bullet big"
			{if rand 0.1
				{spawn "metal_crush"}
			}
		else stuff "bullet"			
			{if rand 0.05
				{spawn "metal_crush"}
			}
		}
	}
	{on contact
		{if effector "dummy"
			{spawn "metal_crush"}
			{delete}
		}
	}
	{on ground_hit
		{set_skeleton "-x"}
		{set "broken" 1}
	}
}

{"head_blam"
	{on spawn	
		(define "cut_part"
			{tear "fx_piece_blood" bone %0
				{impulse up 0.5 dir 0.5 cx 0.5 cy 0.5 rnd_dir 1 no_position}
				{add_view 	"blood_droper-1" 	"blood" "root"}
				{view start "blood"}
				{delay 3 {view pause "blood"}}					
			}
		)
		("cut_part" args "part00" )
		("cut_part" args "part01" )
		("cut_part" args "part02" )
		("cut_part" args "part03" )
		("cut_part" args "part04" )
		("cut_part" args "part05" )
		("cut_part" args "part06" )
		("cut_part" args "part07" )
		("cut_part" args "part08" )
	}
}

{"blood_par"
	{on spawn	
		{impulse up 5 1 dir 2 1}
		{add_view 	"blood_droper-1" 	"blood" "root"}
		{view start "blood"}
		{delay 2 "t"
			{view pause "blood"}
		}
	}
	{on ground_hit 
		{spawn "bloodsparks_small"}
	}
}

{"blood_part"
	{on spawn	
	}
	{on ground_hit 
		{spawn "blood_check"}
		{spawn "bloodsplatter"}
	}
}

{"blood_part2"
	{on spawn
		{add_view 	"blood_droper-1" 	"blood" "root"}
		{view start "blood"}
		{delay 5
			{view pause "blood"}
		}		
	}
	{on ground_hit 
		{spawn "blood_check"}
		{spawn "bloodsplatter"}
	}
}
{"vfx_spark_round"
	{on spawn
		{add_view "fx_trace_bullet_round"		"fx" "fx"}
		{view start "fx"}
	}
	{on ground_hit
		{spawn "hit_sparks_ground"}
		{delete}
	}
	{on contact
		{spawn "hit_sparks_ground"}
		{delete}
	}
}



{"bullet_hit_sparks_burn"
	{on spawn
		{volumes disable bullet blast}
		{add_view 	"trace_burn_flare" 	"fx" "base"}
		{view start "fx"}
		{delay 1.2 0.4
			{delete}
		}
	}
	{on contact
		{spawn "hit_sparks_ground"}
		{delete}
	}
	{on ground_hit 
		{scale from 1 to 0.3 time 0.4}
		{spawn "hit_sparks_ground"}
		;{delete}
	}
}


{"bullet_hit_sparks"
	{on spawn
		{if rand 0.1
			{add_view 	"fx_trace_hit_big" 	"fx_big" "base"}
		}
		{add_view 	"bullet_hit_sparks_fx" 	"fx" "base"}
		{view start "fx"}
		{view start "fx_big"}
		{delay 0.7
			{view stop "fx_big"}
		}
		{delay 1.2 0.4
			{delete}
		}
	}
	{on ground_hit 
		{scale from 1 to 0.3 time 0.4}
		{spawn "hit_sparks_ground"}
		;{delete}
	}
}

{"shoot_hit_sparks"
	{on spawn
		{add_view 	"fx_trace_bullet_tail" 	"fx" "root"}
		{view start "fx"}
		{delay 0.2 0.1
			{delete}
		}
	}
}

{"sand_fx"
	{on spawn
		{add_view 	"sand_fx_set" 	"sand_fx" "fx_fire"}
		{view start "sand_fx"}
	}
	{on contact
		{delete}
	}
	{on ground_hit
		{delete}
	}
}



{"gun_check"
	{on spawn
		{blastwave c4 0.4 r0 1 r1 1 }
		{delete}
	}
}


{"slicer"
	{on spawn	
		{add_view "slicer_tail" "_tail" "root"}
		{view start "_tail"}
		{delay 3 {delete}}
	}
	{on contact
		{if effector "vehicle"
			{spawn "metal_hit_sl"}
			{delete}
		else effector "flesh"
			{spawn "bloodsparks_big"}
			{delete}
		else effector "concrete"
			{spawn "stone_hit_sl"}
			{delete}
		else effector "wood"
			{spawn "hay_hit_small3"}
			{delete}
		else
			{spawn "hay_hit_small3"}
			{delete}		
		}
	}
	{on ground_hit
		{spawn "ex_bul_sm"}
		{delete}
	}
}


{"small_fx"
	{on ground_hit
		{spawn "spheredust_big_hit_steel"}
		{view stop "fx"}
	}
	{on "delete"{hide 3}}
}


{"ps_dummy"
	{on "delete"{hide 3}}
}

{"physics_damping"
;	{friction 1000}
;	{restitution 0.001}
}

(define "throwing_weapon"
	{on contact
		{if effector "human"
			{delay 0
				{constrain_velocity 1}
			}
		}
	}
)

{"knife" ("throwing_weapon")}
{"axe" ("throwing_weapon")}


;{"stone"
;	{on bullet_hit
;		{bullet_detonate}
;	}
;}


{"fx_piece_gasedair"
	{on spawn
		{delay 0
			{add_view "smoke_bats" "fire1" "root"}
			{view start "fire1"}
		}
		{delay 0.5
			{volumes "body" enable contact}
		}
	}
	{on contact
		{call "end"}
	}
	{on ground_hit
		{delay 0.1
			{call "end"}
		}
	}
	{on "end"
		{view stop "fire1"}
		{if not air
			{if not under_water
				{spawn "open_gas_verylarge" dir_velocity}
				{if rand 0.05
					{spawn "open_gas_verylarge"}
				}
				{spawn "open_gas_hit"}
			}
		}
		{delete}
	}
}
{"fx_piece_flame_gas"			;// fx entity that causes burn/heat damage for flamethrowers 
	{on spawn
		{volumes "body" disable contact}
		{gravity 0.1}
		{call "delete_time"}
		{delay 0.1
			{volumes "body" enable contact}
			{call "fire_radius"}
		}
	}
	{on contact
		{volumes disable contact}
		{fire radius 1 time 1 heating 0.3 effector follow}
		{if rand 0.2
			{call_synced "spawn_fire_die"}
		}
		{call "end"}
	}
	
	{on "spawn_fire_die"
		{spawn "fire_die"}
	}
	{on ground_hit
		{call "ground_end"}
	}
	{on "end"
		{delay 0.01
			{delete}
		}
	}
	{on "ground_end"
		{if not under_water
			{if terrain_fx "water"
				else terrain_fx "shallow_water"
				else
				{spawn "fire_flame_thrower" dir_velocity}
				{if rand 0.15
					{call_synced "ground_end_fire"}
				}
			}
		}
		{call "end"}
	}
	{on "ground_end_fire"
		{fire radius 1.2 time 20 heating 0.25}
		{spawn "fire_flame_thrower_ground" offset 0 0 -5}
		{spawn "burned_spot01" random_orientation}
	}
	{on "delete_time" 
		{delay 0.4
			{call "end"}
		}
	}
	{on "fire_radius" 
		{fire radius 1.2 time 1.5 heating 0.75 follow}
	}
}

{"fx_piece_flame"			;// fx entity that causes burn/heat damage for flamethrowers 
	{on spawn
		{volumes "body" disable contact}
		{gravity 1}
		{call "delete_time"}
		{delay 0
			;{add_view "fire_flame_thrower_fly" "fire1" "root"}
			{view start "fire1"}
		}
		{delay 0.1
			{volumes "body" enable contact}
			{call "fire_radius"}
		}
		{delay 0.15 0.05
			{add_view "fire_flame_thrower_fly4" "fire2" "root"}
			{view start "fire2"}
		}
		{delay 0.3 0.05
			{add_view "fire_flame_thrower_fly4_1" "fire3" "root"}
			{view start "fire3"}
			{view stop "fire2"}
		}
	}
	{on contact
		{volumes disable contact}
		{fire radius 1 time 1 heating 0.3 effector follow}
		{if rand 0.2
			{call_synced "spawn_fire_die"}
		}
		{call "end"}
	}
	
	{on "spawn_fire_die"
		{spawn "fire_die"}
	}
	{##on grounded on			;// entity completely stopped moving on the ground and physics is disabled
		{view stop "fire1"}
		{view stop "fire2"}
		{call "ground_end"}
	}
	{on ground_hit
		{view stop "fire1"}
		{view stop "fire2"}
		{call "ground_end"}
	}
	{on "end"
		{view stop "fire1"}
		{view stop "fire2"}
		{view stop "fire3"}
		{delay 0.01
			{delete}
		}
	}
	{on "ground_end"
		{if not under_water
			{if terrain_fx "water"
				else terrain_fx "shallow_water"
				else
				{spawn "fire_flame_thrower" dir_velocity}
				{if rand 0.15
					{call_synced "ground_end_fire"}
				}
			}
		}
		{call "end"}
	}
	{on "ground_end_fire"
		{fire radius 1.2 time 20 heating 0.25}
		{spawn "fire_flame_thrower_ground" offset 0 0 -5}
		{spawn "burned_spot01" random_orientation}
	}
	{on "delete_time"}
	{on "fire_radius"}
}
{"fx_piece_flame 20"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on "delete_time" overload
		{delay 0.7
			{call "end"}
		}
	}
	{on "fire_radius" overload
		{fire radius 1 time 0.7 heating 0.65 follow}
	}
}

{"fx_piece_flame 30"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on "delete_time" overload
		{delay 1.1
			{call "end"}
		}
	}
	{on "fire_radius" overload
		{fire radius 1 time 1.1 heating 0.65 follow}
	}
}
{"fx_piece_flame 40"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on "delete_time" overload
		{delay 1.4
			{call "end"}
		}
	}
	{on "fire_radius" overload
		{fire radius 1 time 1.4 heating 0.65 follow}
	}
}

;// Vehicle Flamethrowers
{"fx_piece_flame 45"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on "delete_time" overload
		{delay 1.2
			{call "end"}
		}
	}
	{on "fire_radius" overload
		{fire radius 1.2 time 1.2 heating 0.75 follow}
	}
}

{"fx_piece_flame 60"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on "delete_time" overload
		{delay 1.5
			{call "end"}
		}
	}
	{on "fire_radius" overload
		{fire radius 1.2 time 1.5 heating 0.75 follow}
	}
}

{"fx_piece_flame 80"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on "delete_time" overload
		{delay 1.8
			{call "end"}
		}
	}
	{on "fire_radius" overload
		{fire radius 1.2 time 1.8 heating 0.75 follow}
	}
}

{"burn_piece"					;// spawned entity that attaches fire damage to entities it contacts (ex. 125mm_ampulomet)
	{on contact
		{volumes disable contact}
		{fire radius 1 time 20 heating 0.25 effector follow}
		{delete}
	}
	{on grounded on			;// entity completely stopped moving on the ground and physics is disabled
		{delete}
	}
	{on ground_hit
		{delete}
	}
}
{"fx_piece_flame_nosound"
	{on spawn
		{gravity 2}
		{delay 0.2
			{blastwave c4 0.2 r0 1.5 r1 1.5}		
			{call "end"}
		}
	}
	{on contact
		{call "end"}
	}
	{on ground_hit
		{call "end"}
	}
	{on "end"
		{fire radius 1.5 time 0.8 heating 0.5}
		{delete}
	}
}

{"fx_piece_flame_helper"
	{on spawn
		{impulse up 1}
	}
	{on contact
		{call "end"}
	}
	{on ground_hit
		{call "end"}
	}
	{on "end"
		{fire radius 1 time 1 heating 0.5}
		{delete}
	}
}

{"fx_piece_flame_nosound_small"
	{on spawn
		{impulse up 1}
		{gravity 2}
		{delay 0.2
			{blastwave c4 0.2 r0 1.5 r1 1.5}		
			{call "end"}
		}
	}
	{on contact
		{call "end"}
		{if effector "v_gas"
			{with_effector
				{call "blast_volume"}
			}
		}
	}
	{on ground_hit
		{call "end"}
	}
	{on "end"
		{fire radius 0.5 time 0.8 heating 0.5}
		{delete}
	}
}

{"fx_piece_flame_end"
	{on spawn
		{add_view "fire_flame_thrower_light" "light" "root"}
		{view start "light"}
		{delay 7
			{delete}
		}
	}
}
{"flamethrower_shell"
	{on spawn
		{delay 0.05
			{fire radius 0.5 time 0.7 heating 1.5 follow}
		}
	}
	{on contact overload
		{if not effector "flamethrower_shell"
			{volumes disable contact}
			{call "end_object"}
		}
	}
	{on "end" overload
		{if not air
			{if not under_water
				{fire radius 3 time 4 heating 0.3}
				{fire radius 1.5 time 0.8 heating 0.5}
				{spawn "fire_flame_thrower" dir_velocity}
				{if rand 0.05
					{spawn "fx_piece_flame_end"}
				}
				{spawn "fire_shellhole2"}
			}
		}
		{delete}
	}
}

{"napalm"
	{on "start"
		{add_view "fire_napalm" "flame" "root"}
		{view start "flame"}
		{fire radius 2 time 1000000 heating 70 follow}
	}
	{on "end"
		{delete}
	}
}

{"inventory_box"
	{on "break"
		{explode_inventory
			{5			"ex_arm_sm"		3	}
			{30			"ex_anti_big"	5	}
			{100		"ex_bomb_big"	10	}
			{1000		"train_die"		15	}
			{10000		"train_die"		20	}
			{100000		"train_die"		25	}
			{1000000	"train_die"		30	}
		}
	}
}
{"flag"
	{on spawn
		{call "start"}
	}
	{on "stop"
		{ani_stop "flattern"}
		{ani_play "stop"}
	}
	{on "start"
		{ani_play "flattern" loop}
	}
}

{"flag captureable"
	{on "capture"
		{if tex_mod "1"
			{ani_play "up" resume callback}
		else
			{ani_play "down" resume callback}
		}
	}
	{on "cancel"
		{set "stop" 1}
		{ani_stop "up"}
		{ani_stop "down"}
		{set "stop" 0}
	}
	{on "enable"
		{volumes "activate" enable contact}
	}
	{on "disable"
		{volumes "activate" disable contact}
	}
	{on animation_end "down"
		{if not "stop"
			{tex_mod "1"}
			{call "capture"}
		}
	}
	{on animation_end "up"
		{if not "stop"
			{tags add "captured"}
		}
	}
}

{"map_point"
	{on "start"
		{ani_play "rotate" loop}
	}
}
{"starshell"
	{on spawn
		{add_view "starshell_light"	"light" "root"}
		{delay 0.4
			{view start "light"}
		}
		{impulse up 40 fx 10 20 fy 10 20}
		{delay 4 1
			{delete}
		}
	}
}
{"water"
	{on spawn
		{ani_play "wave" loop}
		{add_view "wash_big_flow" "wash" "FX_wash"}
		{add_view "wash_big_flow" "wash" "FX_wash1"}
		{add_view "wash_big_flow" "wash" "FX_wash2"}
		{add_view "wash_big_flow" "wash" "FX_wash3"}
		{add_view "wash_big_flow" "wash" "FX_wash4"}
		{add_view "wash_big_flow" "wash" "FX_wash5"}
		{add_view "wash_big_flow" "wash" "FX_wash6"}
		{add_view "wash_big_flow" "wash" "FX_wash7"}
		{add_view "wash_big_flow" "wash" "FX_wash8"}
		{add_view "wash_big_flow" "wash" "FX_wash9"}
		{view start "wash"}
	}
}

{"water_animation_pingpong"
	{on spawn
		;{set "backward" 0}
		{call "animate"}
	}
	{on animation_end "wave"
		{call "animate"}
	}
	{on "animate"
		;{if "backward"
			{ani_play "wave" -1 callback}
			{set "backward" 0}
		;else
			;{ani_play "wave" 1 callback}
			;{set "backward" 1}
		;}
	}
}


{"small_rpg_ammo"
	{on spawn
	}
	{on "unlink"
		{tags remove "link"}
	}
	{on "link"
		{tags add "link"}
	}
	{inflammation_time 2}
	{on "burn_volume"
		{if not "burned"
			{if volume "blasted_ammo_fg"
				{set "burned" 1}
				{burn volume fx "smoke_aero_2_small" time 2 fake even_law}	
				{delay 2 1
					{volumes "ammo_small" disable all}	
					{stuff_detonate}
					{spawn "fraction_spawn" }
					{spawn "metal_hit_zenite_cs"}	
					{spawn "distant_small_expl"}			
					{delete}
				}
			else volume "blasted_ammo_th"
				{set "burned" 1}
				{burn volume fx "smoke_aero_2_small" time 2 fake even_law}	
				{delay 2 1
					{volumes "ammo_small" disable all}	
					{stuff_detonate}
					{start_sound "detonation/phosphorus_start/"}
					{spawn "distant_small_expl"}			
					{delete}
				}
			}
		}
	}
	{on pierce
		{if volume "blasted_ammo_fg"
			{volumes "ammo_small" disable all}	
			{stuff_detonate}
			{blastwave c4 8 r0 5 r1 5}
		else volume "blasted_ammo_th"
			{stuff_detonate}
			{start_sound "detonation/phosphorus_start/"}
			{spawn "distant_small_expl"}			
		}
	}
	{on blast
		{if min_energy 0.5
			{if volume "blasted_ammo_fg"
				{volumes "ammo_small" disable all}	
				{spawn "fraction_spawn" }
				{spawn "metal_hit_zenite_cs"}	
				{spawn "distant_small_expl"}			
				{blastwave c4 6 r0 5 r1 5}
				{delete}
			else volume "blasted_ammo_th"
				{volumes "ammo_small" disable all}	
				{spawn "fraction_thermite" }
				{spawn "fraction_thermite" }
				{spawn "fraction_thermite" }
				{spawn "fraction_thermite" }
				{spawn "fraction_thermite" }
				{spawn "fraction_spawn"}		
				{blastwave c4 3 r0 3 r1 3}	
				{fire radius 1 time 7 heating 1}
				{start_sound "detonation/phosphorus_start/"}
				{spawn "ex_air_norm7"}	
				{spawn "distant_small_expl"}			
				{delete}
			}
		}
	}
}



{"break_action"
	{on "falls"
		{if not tagged "falls"
			{tags add "falls"}
			{impulse dir 5 1 cx 0 0.5 cy 0 0.5}
		}
	}
}

{"radar_loop_sound"
	{on spawn
		{link_sound "sound_link" "vehicle/open_gun/radar/loop/servo_very_slow2"}
	}
}



{"sound_link"
	{on "open"
		{if tagged "open" 
			{stop_sound "sound_link" }
			{tags remove "open"}
		else 
			{play_sound "sound_link" 1}
			{tags add "open"}
		}
	}
	{on "close"
		{stop_sound "sound_link" }
		{tags remove "open"}
	}
}







{"paratrooper"
	{on spawn
		{tags add "paratrooper_air"}
		{view hide "parachute_x"}
	}
	{on "start"
		{ani_play "flight" callback}
	}
	{on animation_end "flight"
		{tags add "paratrooper"}
		{ani_play "landing" callback}
	}
	{on animation_end "landing"
		{view show "parachute_x"}
	}
}








{"paratrooper_attach"
	{on "start"
		{animate_place "attach" "paratruper_flight"}
	}
	{on animation_end "flight"
		{with_linked_entity "attach"
			{unlink}
		}
	}
}

{"parachute_cargo_attach"
	{on "start"
		{animate_place "attach" "paratruper_flight"}
	}
	{on animation_end "landing"
		{with_linked_entity "attach"
			{unlink}
		}
	}
}

{"random_animation"
	{on spawn
		{call "random_animation"}
	}

	(define "random_animation"
		rand 0.1
		{ani_play "animation%0" callback}
	)
	{on "random_animation"
		{if	 ("random_animation" args 0)
		else ("random_animation" args 1)
		else ("random_animation" args 2)
		else ("random_animation" args 3)
		else ("random_animation" args 4)
		else ("random_animation" args 5)
		else ("random_animation" args 6)
		else ("random_animation" args 7)
		else ("random_animation" args 8)
		else rand 0.1
			{call "delay"}
		else
			{call "random_animation"}
		}
	}

	(define "random_animation_end"
		{on animation_end "animation%0"
			{call "random_animation"}
		}
	)
	("random_animation_end" args 0)
	("random_animation_end" args 1)
	("random_animation_end" args 2)
	("random_animation_end" args 3)
	("random_animation_end" args 4)
	("random_animation_end" args 5)
	("random_animation_end" args 6)
	("random_animation_end" args 7)
	("random_animation_end" args 8)

	{on "delay"
		{call "random_animation"}
	}
}

{"random_animation with_delay"
	{on "delay" overload
		{delay 12 4
			{call "random_animation"}
		}
	}
}

{"blast_flattern"
	{on blast
		{if volume "flattern"
			{if min_energy 0.3
				{ani_play "flattern"}
			}
		}
	}
}

{"pointer_attack"
	{on spawn
		{tags add "pointer_attack"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_defend"
	{on spawn
		{tags add "pointer_defend"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_enemy"
	{on spawn
		{tags add "pointer_enemy"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_going"
	{on spawn
		{tags add "pointer_going"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_watchout"
	{on spawn
		{tags add "pointer_watchout"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"pointer_help"
	{on spawn
		{tags add "pointer_help"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"user_guide"
	{on spawn
		{tags add "user_guide"}
		{inactive 0}
		{delay 10
			{hide 5}
		}
	}
}

{"radio_beacon"
	{on spawn
		{add_view "stop_signal" "lamp" "fx_lamp"}
		{view start "lamp"}
	}
}

{"sandstorm"
	{on spawn
		{add_view "desert2_fx" "lamp" "fx_lamp"}
		{view start "super"}
	}
}
{"big_flying_rocket"
	{on spawn
		{link_sound "fly" "weapon/shot/reactive/rocket"}
		{play_sound "fly" 1}
	}
}

{"welding"
	{on spawn
		{add_view "spark_electro02a" "welding" "root"}
		{view start "welding"}
	}
}
{"air_cloud"
	{on spawn
		{add_view "dustrun_snow_big" "air_cloud" "root"}
		{view start "air_cloud"}
	}
}
{"exp_det_dust"
	{on "explode"
		{add_view "ex_det" "detonation" "basis"}
		{view start "detonation"}
	}
}
{"flash_gun_big_entity"
	{on "explode"
		{add_view "flash_gun_big" "detonation" "basis"}
		{view start "detonation"}
	}
}
{"light_plafond_dim_entity"
	{on spawn
		{add_view "light_plafond_dim" "welding" "root"}
		{view start "welding"}
	}
}
{"light_plafond_dim_w_entity"
	{on spawn
		{add_view "light_plafond_dim_w" "welding" "root"}
		{view start "welding"}
	}
}

(define "shellhole_show_with_delay"
	{on spawn
		{view hide "shellhole"}
		{delay %0
			{view show "shellhole"}
		}
	}
)

{"shellhole_dead_moto"
	("shellhole_show_with_delay" args 0.1)
}
{"shellhole_dead_car"
	("shellhole_show_with_delay" args 0.2)
}
{"shellhole_dead_tank"
	("shellhole_show_with_delay" args 0.35)
}

{"flare"
	{on spawn
		{gravity 1.3}
		{tags add "flare"}
		{add_view "signal_rocket" "flare" "root"}
		{view start "flare"}
		{delay 15.5
			{delete}
		}
	}
}
	

{"parachute_signal_fire"
	{on spawn
		{add_view "signal_rocket2" "signal" "fx_signal"}
		{view start "signal"}
		{ani_play "flight" 0.5}
		{delay 3
			{ani_stop "flight"}
			{delay 35
				{ani_play "flight" resume callback}
			}
		}
	}
	{on animation_end "flight"
		{delay 0
			{delete}
		}
	}
}


{"block_detonate"
	{on bullet_hit
		{if effector "bullet"		
			{stuff_detonate}
			{delete}
		}
		{delete}
	}
}


{"tail_rpg7_small"
	{on spawn
		{add_view "rpg7_tail_small_fx" "fly" "root"}
		{delay 1 
			{view start "fly"}
		}
	}
}



{"tail_rocket"
	{on spawn
		{impulse up 0 dir 5 1 forward 12 5 com  fx 2}
		{add_view "smoke_aero_small" "tail" "tail"}
		{view start "tail"}
		{delay 3 1 
			{impulse up 0 forward 5 2 com  fx 3}
			{view stop "tail"}
		}
	}
}




{"s5_rocket"
	{on spawn
		{volumes disable contact }	
		{add_view "rocket_smoke_s5" "tail_fast" "fxfire"}
		{add_view "rocket_smoke_s5_start" "tail_start" "fxfire"}
		{link_sound "fly" "weapon/reactive/move/rpg7/move_rpapa7_proj_flame_cls"}
		{delay 0.1
			{play_sound "fly" 1}
			{call "fly"}
			{view start "tail_fast"}
			{view start "tail_start"}
			{ani_play "fly" +0.23 resume callback }
			{start_sound "weapon/reactive/wrist_rocket"}	
		}
		{delay 0.3
			{volumes enable contact}	
			{view stop "tail_start"}
		}
		{if rand 0.02
			{call "fail"}
		}
		{delay 0.92 0.3;  0,55-0,92 сек.
			{call "_explosion_air_s5"}
		}
	}
	{on "fail"
		{set "blocked" 1}
		{delay 0
			{if rand 0.02
				{ani_play "fail" 0.1}
			else
				{ani_play "fail2" 0.1}
			}
			{start_sound "detonation/blast_phosphorus"}	
			{spawn "ex_air_norm2" "fxfire" x}
			{delay 1 0.5
				{add_view "fail_tail" "fail" "fxfire"}
				{view start "fail"}
				{start_sound "detonation\blast_phosphorus"}	
				{spawn "ex_air_norm2" "fxfire"}
			}
			{delay 1 0.5
				{start_sound "detonation\blast_phosphorus"}	
				{stop_sound "fly" }
				{view stop "tail"}
;				{delay 2 0.5
;				}
			}
		}
	}
	{on "fly"
		{if rand 0.01
			{start_sound "shoot_emitters_ext/rocketlauncher"}	
		else rand 0.1 
			{start_sound "weapon/reactive/rand_move"}	
		}
		{if rand 0.5 
			{spawn "spheredust_small_short2" "fxfire"}
		else rand 0.3 
			{spawn "spheredust_small_short" "fxfire"}
		}
		{delay_effect 2 0.5 "fly"}
	}
	{on "_explosion_air_s5"	
		;{blastwave c4 12 r0 5 r1 5}	
		{spawn "explosion_s5" "blast"}
		{delete}
	}
	{on "_explosion_s5"
		{spawn "explosion_s5" "blast"}
		;{blastwave c4 12 r0 5 r1 5}	
		;{blastwave c4 1.6 r0 12 r1 12}	
		;{fire radius 2 time 0.5 heating 1}
		{delete}
	}
	{on ground_hit
		{view stop "fail"}
		{if not "blocked"
			{call "_explosion_s5"}
		else
			{if volume "detonator"
				{spawn "ex_air_norms" "fxfire"}
				{stop_sound "fly" }
				{view stop "tail_fast"}
				{view stop "tail_start"}
				{delay_ex 0
					{tear "piece_big_steel_rocket" bone from_volume
						{impulse up 0 dir 5 forward 10 com  fx 25 cx 4 2 cy 4 2 rnd_dir 1}					
					}	
				}	
				{delay 0.1
					{delete}
				}
			}
		}
	}
	{on blast_hit
		{if min_energy 1.0
			{call "_explosion_s5"}
		else
			{impulse up 1 1 dir 2 1}
		}
	}
	{on contact
		;{if volume "detonator"
			{call "_explosion_air_s5"}
			{if effector "stuff"
				{with_effector
					{impulse dir 25 10 up 5 dir 7 2 cx 5 3 cy 5 3}
				}
			}
			{if effector "car"
				{with_effector
					{impulse dir -6 com  }
					{if not "exploded"
						{if rand 0.8
							{call "explosion"}
						}
					else
						{impulse up 1 1 dir 2 1}
					}
				}
			}
			{if material "steel"
				{spawn "metal_hit_br_small_semtex" }
			}	
		;}
	}
}
{"s5_rocket failed"
	{on spawn
		{volumes disable bullet contact blast touch}	
;		{gravity 1}
;		{ani_play "start" 0.1}
		{start_sound "detonation\gas_activator"}	
		{add_view "bazooka_tail" "tail_fast" "fxfire"}
		{add_view "muzzle_front_mgun" "tail_start" "fxfire"}
		{view start "tail_fast"}
		{view start "tail_start"}
		{delay 0.1
			{volumes enable bullet contact blast touch}	
		}
		{if rand 0.8
			{call "fail"}
		}
		{delay 0.5
			{view stop "tail_start"}
		}
		{delay 12
			{delete}
		}
		{link_sound "fly" "weapon/reactive/move/rpg7/move_rpapa7_proj_flame_cls"}
		{play_sound "fly" 1}
		{call "fly"}
	}
}

{"piece_big_steel_rocket"
	{on spawn
		{add_view "smoke_aero_small" "tail_fast" "fxfire"}
		{view start "tail_fast"}
		{burn volume "body" fx "smoke_dead_small3" time 5 fake even_law}
		{fire volume "body" radius 0.9 heating 1  time 5 follow}
		{delay 5 2
			{spawn "ex_fg_minimum" "fxfire"}
			{blastwave c4 0.4 r0 12 r1 12}	
			{blastwave c4 16 r0 2 r1 2}	
			{fire radius 2 time 0.5 heating 1}
			{spawn "fx_sled_fire"}
			{spawn "fx_sled_fire"}
			{delete}
		}
	}
}

{"piece_big_steel_rocket2"
	{on spawn
		{add_view "smoke_aero_small" "tail_fast" "fxfire"}
		{view start "tail_fast"}
		{burn volume "body" fx "smoke_dead_small3" time 5 fake even_law}
		{fire volume "body" radius 1 heating 1  time 5 follow}
		{delay 3 1
			{start_sound "detonation/blast_phosphorus"}	
			{spawn "ex_air_big" }
			{blastwave c4 0.4 r0 12 r1 12}	
			{blastwave c4 16 r0 2 r1 2}	
			{fire radius 2 time 0.5 heating 1}
			{delete}
		}
	}
}


{"piece_big_steel_missile"
	{on spawn
		{tex_morph "burned" 1}
		{volumes disable bullet contact blast touch}	
		{delay 1
			{volumes enable bullet contact blast touch}
		}
		{if rand 0.5
			{start_sound "detonation\firework_launch"}	
			{delay 3
				{start_sound "detonation\firework"}	
			}
		}
		{burn volume "body" fx "smoke_dead_small3" time 15 fake even_law}
		{fire volume "body" radius 1 heating 1  time 15 follow}
		{delay 12
			{start_sound "detonation/missile"}
			{spawn "ex_air_big" }
			{call "explosion"}
		}
	}
	{on contact overload
		{with_effector
			{burn fx "thermite_hit3" time 3 }
		}
		{if rand 0.8
			{call "explosion"}
		}
	}
	{on ground_hit
		{if rand 0.5
			{call "explosion"}
		}
	}
	{on "explosion"
		{if not "exploded"
			{set "exploded" 1}
			(define "terrain_fx"
				{if terrain_fx %0 
					{start_sound "expl_emitters/lrg"}	
				}
			)
			("terrain_fx" args "shoot_emit_mtl" 				 )
			("terrain_fx" args "shoot_emit_mtl_int" 				 )
			("terrain_fx" args "shoot_emit_ext_sand" 			 )
			("terrain_fx" args "shoot_emit_ext" 				 )
			("terrain_fx" args "shoot_emit_int" 				 )
			("terrain_fx" args "shoot_emit_int_wood" 			 )
			{spawn "fraction_thermite" }
			{spawn "fraction_thermite" }
			{spawn "fraction_thermite" }
			{spawn "fraction_thermite" }
			{spawn "fraction_thermite" }
			{spawn "fraction_spawn"}		
			{blastwave c4 0.1 r0 9 r1 9}	
			{blastwave c4 6 r0 3 r1 3}	
			{fire radius 0.6 time 7 heating 1}
			{start_sound "detonation/phosphorus_start/"}
			{spawn "ex_air_norm7"}						
			{delete}
		}
	}
}


{"propane_tank_rocket"
	{on spawn
		{link_sound "start_small_rpg" "generation_zero/weapon/micro_missile/loop/mach_wpn_micro_missile_trail_loop_01"}
		{link_sound "open_9m39" "weapon/reactive/9k38/open/"} ;раскрытие
		{link_sound "fly2" "fire/small_stuff/fire_small"}
		{gravity 1}
		{start_sound "detonation\gas_activator"}	
		{add_view "muzzle_front" "tail_fast" "tail"}
		{add_view "rocket_smoke_black" "tail_start" "tail"}
		{add_view "rocket_smoke" "tail" "tail"}
		{add_view "smoke_aero_small" "tail2" "tail"}
		{play_sound "start_small_rpg" 1}
		{play_sound "fly" 1}
		{delay 0.2 0.1		
			{play_sound "open_9m39" }
			{view start "tail_start"}
			{view start "tail"}
			{view start "tail_fast"}
		}
		{volumes disable bullet contact blast touch}	
		{if rand 0.04
			{call "fail"}
		else
			{impulse up 0 dir 25 forward 410 70 com  fx 0}		
		}
		{delay 0.9 
			{view stop "tail_start"}
			{volumes enable bullet contact blast}
		}
		{call "fly"}
		{delay 3 1
			{if not "blocked"
				{ani_play "fall" 1}
			}
			{view stop "tail_fast"}
			{call "fall"}
		}
	}
	{on "fail"
		{set "blocked" 1}
		{delay 0
			{impulse up 0 dir 5 forward 50 10 com  fx 0}
			{start_sound "detonation/blast_phosphorus"}	
			{spawn "ex_air_norm2" "tail"}
			{delay 1 0.5
				{add_view "fail_tail" "fail" "tail"}
				{add_view "exhaust_dark_big" "fail" "tail"}
				{view start "fail"}
				{start_sound "detonation\blast_phosphorus"}	
				{spawn "ex_air_norm2" "tail"}
			}
			{delay 1 0.5
				{add_view "smoke_aero_big2" "fail2" "propane_tank_rocket"}
				{view start "fail2"}
				{start_sound "detonation\blast_phosphorus"}	
				{spawn "ex_air_norm2" }
				;{burn volume "body2" fx "smoke_black_big" time 5 fake even_law}
				{fire volume "body2" radius 0.9 heating 1  time 5 follow}
				{view hide "tail"}
				{stop_sound "fly" }
				{play_sound "fly2" 1}
				{view stop "tail"}
				{delay 6 2
					{impulse up 0 dir 5 forward 25 6 com  fx 0}
					{call "_explosion_air_failed"}
				}
			}
		}
	}
	{on "fall"
		{if altitude 12
			{if rand 0.2
				{start_sound "detonation/blast_phosphorus"}	
				{spawn "ex_air_norm2" }
			}
		}
		{if altitude 25
			{if not tagged "fall"
				{tags add "fall"}
				{start_sound "expl_emitters/bullet"}	
				{delay 1
					{if rand 0.3
						{start_sound "detonation\blast_phosphorus"}	
						{spawn "ex_air_norm2" }
					}
					{view hide "tail"}
					{stop_sound "fly" }
					{play_sound "fly2" 1}
					{view stop "tail"}
				}
				{view start "tail2"}
				{spawn "spheredust_small_short2" "tail"}
			}
		}
		{delay 1
			{call "fall"}
		}
	}
	{on "fly"
		{if rand 0.01
			{start_sound "detonation\blast_phosphorus"}	
			{spawn "ex_air_norm2" }
			{fire volume "body2" radius 0.9 heating 1  time 5 follow}
			{add_view "smoke_aero_big2" "fail2" "propane_tank_rocket"}
			{view start "fail2"}
			{delay 3 1
				{call "_explosion_air"}
			}
		}
		{if rand 0.01
			{start_sound "detonation/expl_emitters/grenade/dist"}	
		}
		{if rand 0.5 
			{spawn "spheredust_small_short2" "tail_long"}
		else rand 0.3 
			{spawn "spheredust_small_short" "tail_long2"}
		}
		{delay 1 0.5
			{call "fly"}
		}
	}
	{on "_explosion_air_failed"
		{stuff_detonate}
		{spawn "open_gas_vl_fx"}
		{spawn "heavy_revebration" }
		{spawn "fx_piece_flame_ground_tail" }
		{spawn "fx_piece_flame_ground_tail" }
		{spawn "fx_piece_flame_ground_tail" }
		{spawn "fx_piece_flame_ground_tail" }
		{spawn "fx_piece_flame_ground_tail" }
		{spawn "fx_piece_flame_ground_tail" }
		{spawn "fx_piece_flame_ground_tail" }
		{spawn "propane_blast_rocket2" "propane_tank_rocket"}
		{blastwave c4 7 r0 5 r1 5}	
		{blastwave c4 1.6 r0 12 r1 12}	
	}
	{on "_explosion_air"
		{stuff_detonate}
		{spawn "ex_propane" }
		{spawn "propane_blast_rocket" }
		{spawn "aero_die_particle" "tail"}
		{spawn "ex_air_norm2" }
		{spawn "open_gas_m_fx"}
		{blastwave c4 7 r0 5 r1 5}	
		{blastwave c4 1.6 r0 12 r1 12}	
	}
	{on "_explosion"
		{spawn "distant_big_expl" offset 0 0 25}
		{spawn "propane_blast_rocket" }
		{spawn "ex_propane"}
		{spawn "metal_hit_br_small_semtex"}
		{spawn "open_gas_vl_fx_fuel"}
		{blastwave c4 16 r0 7 r1 7 position offset 0 0 50}
		{blastwave c4 2 r0 15 r1 15 position offset 0 0 50}
		{fire radius 3 time 0.5 heating 1}
		{stuff_detonate}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
		{spawn "fraction_set" offset 0 0 10}
	}
	{on ground_hit
		{view stop "fail"}
		{if not "blocked"
			{if rand 0.8
				{volumes disable all}
				{call "_explosion"}
			else
				{if not tagged "ground_hit"
					{tags add "ground_hit"}
					{spawn "fx_sled_fire"}
					{spawn "propane_blast" }
					{spawn "ex_lamps" }
					{impulse up 0 dir 2 forward 25 com  fx 0}
					{burn volume "body2" fx "smoke_dead_small3" time 5 fake even_law}
					{fire volume "body2" radius 0.9 heating 1  time 5 follow}
					{delay 4 1
						{call "_explosion_air"}
					}
				}
			}
		}
	}
	{on blast_hit
		{if min_energy 2.0
			{volumes disable all}
			{call "_explosion"}
		else
			{impulse up 1 1 dir 2 1}
		}
	}
	{on bullet_hit
		{if stuff "bullet"
			{if volume "body2"
				{burn volume "body2" fx "smoke_dead_small3" time 5 fake even_law}
				{delay 3 2
					{call "_explosion"}
				}
			else
				{impulse up 0.1 0.1 dir 0.1 0.1}
			}
		else stuff "shell"
			{call "_explosion"}
		}
	}
	{on contact
		{if min_speed 20
			{if volume "body1"
				{volumes disable contact}
				{call "_explosion"}
			}
			{if volume "body2"
				{if rand 0.9
					{volumes disable contact}
					{call "_explosion"}
				else 
					{spawn "spheredust_small_short" }
					{delay 1
						{burn volume "body2" fx "smoke_dead_small3" time 5 fake even_law}
						{fire volume "body2" radius 0.9 heating 1  time 5 follow}
						{delay 3 2
							{call "_explosion"}
						}
					}				
				}				
			else
				{if rand 0.6 
					{spawn "spheredust_small_short2" }
				else rand 0.5 
					{spawn "spheredust_small_short" }
				}
				{impulse up 0.5 0.1 dir 0.1 0.1}
			}
		}	
	}
}





{"epic_fire_ground"
	{on spawn
		{fire radius 0.4 time 6 heating 4 effector}
		{add_view "smoke_camp_blue" "tail" "sprite"}
		{view start "tail"}
		{if rand 0.7
			{scale from 0.9 to 0.9 time 0.1}
		else rand 0.3
			{scale from 0.7 to 0.7 time 0.1}
		else
			{scale from 0.5 to 0.5 time 0.1}
		}
		{delay 6
			{delete}
		}		
	}
}


{"pyro_fire_fuel_puddle_ground"
	{on spawn
		{fire radius 0.4 time 6 heating 4 effector}
		{add_view "smoke_camp_blue" "tail" "sprite"}
		{view start "tail"}
		{if rand 0.7
			{scale from 2 to 0 time 8}
		else rand 0.3
			{scale from 2.5 to 0 time 6}
		else
			{scale from 3 to 0 time 3}
		}
		{delay 8
			{hide 1}
		}		
	}
}

{"pyro_fire_fuel_puddle_volume"
	{on spawn
		{add_view "smoke_camp_blue" "tail" "sprite"}
		{view start "tail"}
		{delay 6
			{hide 3}
		}		
	}
}

{"ex_molot_fire_fraction"
	{on spawn
		{volumes disable contact}
		{delay 0.1
			{volumes enable contact}
		}
		{impulse up 2 1 dir 2 1 cx 4 1 cy 4 1 rnd_dir 3 com}
		{add_view "ex_molot_fire_fly" "tail" "basis"}
		{view start "tail"}
		{delay 6
			{delete}
		}		
	}
	{on ground_hit
		{fire radius 0.2 time 3 heating 4 effector}
		{delete}
	}	
	{on contact
		{if not effector "ex_molot_fire"
			{fire radius 0.2 time 3 heating 4 effector}
			{delete}
		}	
	}	
}

{"ex_molot_fire_fly"
	{on spawn
		{add_view "ex_molot_fire_fly" "tail" "basis"}
		{view start "tail"}
		{delay 0.7
			{delete}
		}		
	}
	{on ground_hit
		{fire radius 0.8 time 3 heating 4 effector}
		{delete}
	}	
	{on contact sync
		{if not effector "ex_molot_fire"
			{fire radius 1 time 3 heating 4 effector}
			{delete}
		}	
	}	
}

{"ex_molot_fire_fraction_inv"
	{on spawn
		{volumes disable contact}
		{delay 0.5
			{volumes enable contact}
		}
		{add_view "ex_molot_fire_fly" "tail" "basis"}
		{view start "tail"}
		{delay 6
			{delete}
		}		
	}
	{on ground_hit
		{fire radius 0.2 time 3 heating 4 effector}
		{delete}
	}	
	{on contact
		{if not effector "ex_molot_fire"
			{fire radius 0.2 time 3 heating 4 effector}
			{delete}
		}	
	}	
}


{"ex_molot_fire_burning"
	{on spawn
	}
	{on animation_event "burning" 
		{if not tagged "start"{tags add "start"} {call "start"}}		
		{spawn "ex_molot_fire_impact_small" "basis" }				
	}
	{on "start"
		{add_view "ex_molot_fire_burning" "start" "basis"}
		{view start "start"}
		{delay 3
			{delete}
		}		
	}
}


{"ex_molot_fire_fraction_small"
	{on spawn
		{volumes disable contact}
		{delay 0.6
			{volumes enable contact}
		}
		{impulse up 0.1 com}
		{add_view "ex_molot_fire_burning" "tail" "basis"}
		{view start "tail"}
		{delay 6
			{delete}
		}		
	}
	{on ground_hit
		{fire radius 0.1 time 2 heating 4 effector}
		{delete}
	}	
	{on contact
		{if not effector "ex_molot_fire"
			{fire radius 0.2 time 3 heating 4 effector}
			{delete}
		}	
	}	
}



{"smokeshell_tank"
	{on spawn
		{impulse up 0 dir 1 forward 20 com  }
		{add_view "tail_smoke" "tail" "smokeshell"}
		{view start "tail"}
		{delay 1.2 0.4		
			{spawn "ex_air_smoke" }			
			{spawn "fraction_smoke" "blast00" x}			
			{spawn "fraction_smoke" "blast01" x}			
			{spawn "fraction_smoke" "blast02" x}			
			{spawn "fraction_smoke" "blast03" x}			
			{delete}			
		}
	}
}
{"smokeshell_particle"
	{on spawn
		{impulse up 0 dir 1 forward 10 4 com  }
		{add_view "tail_smoke" "tail_fast" "body"}
		{add_view "smoke_cover-up_norm_white" "smokescreen" "body"}
		{add_view "smoke_cover-up_big_white" "smokescreen2" "body"}
		{view start "tail_fast"}
		{delay 4
			{view start "smokescreen"}
			{delay 6
				{view start "smokescreen2"}
				{delay 6
					{delete}
				}		
			}		
		}		
	}
	{on ground_hit
		{spawn "smoke_medium"}
	}
}

{"smokeshell_screen"
	{on spawn
		{burn volume "crown" fx "smoke_screen_volume" time 10 fake even_law}
		{delay 10 
			{delete}			
		}
	}
}



{"40x46_ammo"
	{on spawn
		{volumes disable contact}	
		{add_view "start_xm109_tail" 		"start_23mm" "fxfire"}
		{start_sound "weapon/shot/small_arms/m203_close"}				
		{add_view "bullet_tail" "tail_fast" "fxfire"}
		{add_view "helicopter_flare" "tail_start" "fxfire"}
		{view start "start_23mm"}
		{view start "tail_fast"}
		{view start "tail_start"}
		{delay 0
			{volumes enable contact}	
		}
;		{if rand 0.02
;			{impulse up 0 dir 3 forward 20 10 com  fx 0}					
;			{call "fail"}
;		else
			{impulse up 0 dir 0 forward 70 com  fx 0}					
;		}
		{delay 0.2
			{view stop "tail_start"}
		}
		{delay 0.8
			{view stop "start_23mm"}
		}
;		{link_sound "fly" "weapon/reactive/move/rpg7/move_rpapa7_proj_flame_cls"}
;		{play_sound "fly" 1}
;		{call "fly"}
	}
	{on "_explosion_air_m203"	
		{stuff_detonate}
	}
	{on "_explosion_m203"
		{stuff_detonate}
	}
	{on ground_hit
		{call "_explosion_m203"}
	}
	{on blast_hit
		{if min_energy 1.0
			{call "_explosion_m203"}
		else
			{impulse up 1 1 dir 2 1}
		}
	}
	{on contact
		{call "_explosion_air_m203"}
	}
}


{"fire_source"
	{on spawn
		{set "burning" 1}
		{fire radius 1.5 time 99999 heating 0.5 follow}
	}
}

{"fire_napalm_dmg"
	{on spawn
		{spawn "train_die"}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{spawn "fire_napalm_flame"	random_position 200 random_orientation}
		{fire radius 7.5 time 3 heating 7.5}
		{fire radius 15 time 1 heating 0.5}
		{delete}
	}
}


{"start_phosphorus"
	{on spawn	
		{spawn "start_phosphorus_spawn" "fx_blast_00"}
		{spawn "start_phosphorus_spawn" "fx_blast_01"}
		{spawn "start_phosphorus_spawn" "fx_blast_02"}
		{spawn "start_phosphorus_spawn" "fx_blast_03"}
		{spawn "start_phosphorus_spawn" "fx_blast_04"}
		{spawn "start_phosphorus_spawn" "fx_blast_05"}
		{spawn "start_phosphorus_spawn" "fx_blast_06"}
		{spawn "start_phosphorus_spawn" "fx_blast_07"}
		{delete}
	}
}
{"start_phosphorus_spawn"
	{on spawn	
		{delay 1.2 -0.5
			{start_sound "detonation/blast_phosphorus"}
			{spawn "ex_air_norm2" "fx_blast_00" x}
			{spawn "move_phosphorus" "fx_blast_00" x
				{impulse dir -25 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 1.2 -0.5
			{start_sound "detonation/blast_phosphorus"}
			{spawn "ex_air_norm2" "fx_blast_01" x}
			{spawn "move_phosphorus" "fx_blast_01" x
				{impulse dir -25 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 1.2 -0.5
			{start_sound "detonation/blast_phosphorus"}
			{spawn "ex_air_norm2" "fx_blast_02" x}
			{spawn "move_phosphorus" "fx_blast_02" x
				{impulse dir -25 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 1.2 -0.5
			{start_sound "detonation/blast_phosphorus"}
			{spawn "ex_air_norm2" "fx_blast_03" x}
			{spawn "move_phosphorus" "fx_blast_03" x
				{impulse dir -25 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 1.2 -0.5
			{start_sound "detonation/blast_phosphorus"}
			{spawn "ex_air_norm2" "fx_blast_04" x}
			{spawn "move_phosphorus" "fx_blast_04" x
				{impulse dir -25 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 1.2 -0.5
			{start_sound "detonation/blast_phosphorus"}
			{spawn "ex_air_norm2" "fx_blast_05" x}
			{spawn "move_phosphorus" "fx_blast_05" x
				{impulse dir -25 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 1.2 -0.5
			{start_sound "detonation/blast_phosphorus"}
			{spawn "ex_air_norm2" "fx_blast_06" x}
			{spawn "move_phosphorus" "fx_blast_06" x
				{impulse dir -25 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 1.2 -0.5
			{start_sound "detonation/blast_phosphorus"}
			{spawn "ex_air_norm2" "fx_blast_07" x}
			{spawn "move_phosphorus" "fx_blast_07" x
				{impulse dir -25 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 3
			{delete}
		}
	}
}
{"move_phosphorus"
	{on spawn
		{if not under_water
			{if rand 0.5
				{start_sound "detonation/phosphorus_start"}
			}
			{add_view "smoke_air_ph" 	"fire" "root"}
			{add_view "smoke_ground_ph" "set_smoke" "basis"}
			{add_view "smoke_ground_ph2" "set_smoke_2" "basis"}
			{view start "fire"}
		}
		{delay 25
			{if rand 0.3
				{spawn "decal_spotfire_sheet_0"}
			}		
			{if rand 0.3
				{spawn "decal_spotfire_sheet_1"}
			}		
			{if rand 0.3
				{spawn "decal_spotfire_sheet_2"}
			}		
			{if rand 0.3
				{spawn "decal_spotfire_sheet_3"}
			}		
			{delete}
		}
	}
	{on ground_hit
		{fire radius 2 time 25 heating 1}
		{if rand 0.5
			{start_sound "detonation/phosphorus_start"}
		}
		{fall_down}
		{spawn "blast_phosphorus" "basis"}	
		{delay 5
			{view start "set_smoke"}
			{delay 5
				{view start "set_smoke_2"}
			}
		}
	}
	{on contact
		{fire radius 1 time 3 heating 1}
		{if rand 0.5
			{start_sound "detonation/phosphorus_start"}
		}
		{spawn "blast_phosphorus" "basis"}	
		{delay 5
			{view start "set_smoke"}
		}
	}
}

{"c4_ground"
	{on spawn
		{volumes disable contact}
		{delay 1
			{volumes enable contact}
		}	
		;{start_sound ""}	
	}
	{on contact
		{spawn "c4_explosive_blasted"}
		{delete}
	}
	{on ground_hit
		{spawn "c4_explosive_blasted"}
		{delete}
	}
}



{"fire_napalm_flame"
	{on spawn
		{if not under_water
			{if rand 0.7
				{add_view "napalm1" "fire" "root"}
				{view start "fire"}
			else
				{add_view "napalm2" "fire" "root"}
				{view start "fire"}
			}
			{set "burning" 1}
			{fire radius 1.5 time 10 heating 0.2}
		}
		{delay 10
			{delete}
		}
	}
}


{"marker_artilery"
	{on spawn
		{impulse up 0.2 dir 2 forward 25 fz 1 com  }
		{call "add_smoke"}
		{link_sound "smoke" "detonation/grenade_smoke/grenade_smoke"}
		{add_view "smoke_red_small2"		"smoke" "root"}
		{spawn "clutch_sm"}
		{link_sound "air" ""}
		{view start "smoke"}
		{volumes disable touch select}
	}
	{on "activate"
		{delay 10
			{play_sound "smoke" }
			{stop_sound "smoke"}
		}
		{delay 14
			{view stop "smoke3"}
			{start_sound "detonation/mortar_incoming"}
			{delay 1.5
				{hide 1}
				{spawn "start_artilery"}
			}
		}
	}
	{on ground_hit
		{if not tagged "activated"
		;{if not "activated"
			;{set "activated" 1}
			{tags add "activated" }
			{if under_water
				{hide 1}
			else
				{delay 1
					{call "activate"}
				}
			}
		}
	}
	{on contact
		{if not tagged "activated"
		;{if not "activated"
			;{set "activated" 1}
			{tags add "activated" }
			{delay 1
				{call "activate"}
			}
		}
	}
}



{"start_artilery"
	{on spawn	
		{spawn "start_artilery_spawn" "fx_blast_00"}
		{spawn "start_artilery_spawn" "fx_blast_01"}
		{spawn "start_artilery_spawn" "fx_blast_02"}
		{spawn "start_artilery_spawn" "fx_blast_03"}
		{spawn "start_artilery_spawn" "fx_blast_04"}
		{spawn "start_artilery_spawn" "fx_blast_05"}
		{spawn "start_artilery_spawn" "fx_blast_06"}
		{spawn "start_artilery_spawn" "fx_blast_07"}
		{delete}
	}
}
{"start_artilery_spawn"
	{on spawn	
		{delay 15 -6.5
			{if rand 0.5
				{start_sound "detonation/mortar_incoming"}
			}
			{spawn "move_artilery" "fx_blast_00" x
				{impulse dir -15 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 15 -6.5
			{if rand 0.5
				{start_sound "detonation/mortar_incoming"}
			}
			{spawn "move_artilery" "fx_blast_01" x
				{impulse dir -15 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 15 -6.5
			{if rand 0.5
				{start_sound "detonation/mortar_incoming"}
			}
			{spawn "move_artilery" "fx_blast_02" x
				{impulse dir -15 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 15  2.5
			{if rand 0.5
				{start_sound "detonation/mortar_incoming"}
			}
			{spawn "move_artilery" "fx_blast_03" x
				{impulse dir -15 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 15 -9.5
			{if rand 0.5
				{start_sound "detonation/mortar_incoming"}
			}
			{spawn "move_artilery" "fx_blast_04" x
				{impulse dir -15 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 15 -9.5
			{if rand 0.5
				{start_sound "detonation/mortar_incoming"}
			}
			{spawn "move_artilery" "fx_blast_05" x
				{impulse dir -15 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 15 -9.5
			{if rand 0.5
				{start_sound "detonation/mortar_incoming"}
			}
			{spawn "move_artilery" "fx_blast_06" x
				{impulse dir -25 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 15 -9.5
			{if rand 0.5
				{start_sound "detonation/mortar_incoming"}
			}
			{spawn "move_artilery" "fx_blast_07" x
				{impulse dir -25 rnd_dir 9}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 28
			{delete}
		}
	}
}

{"move_artilery"
	{on spawn
		{add_view 		"grenade_tail" 	"fire" "root"}
		{view start "fire"}
		{call "fly"}
		{delay 1
			{add_view 	"152rocket_tail" 	"fire_tail" "root"}
			{view start "fire_tail"}		
		}
	}
	{on "fly"
		{if rand 0.3
			{start_sound "weapon/reactive/rand_move"}
		}
		{delay 0.3
			{call "fly"}
		}
	}
	{on ground_hit
		{call "_explosion"}
	}
	{on contact
		{call "_explosion"}
	}
	{on "_explosion"
		{spawn "distant_big_expl" offset 0 0 25}
		{stuff_detonate}
	}
}



{"damage_x"
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{if volume "fire"
				{call "_burns"}
			}
		}
	}
	{on "_burns"
		{start_sound "fire/small"}
		{fire radius 0.5 time 40 heating 2}
		{burn volume fx "smoke_dead_norm" time 37 fake even_law}
		{delay 8 2 "burn_die1"
			{tex_morph "burn1" 5}
			{call "_burn_crash"}
			{delay 6 "_burn_crash_end"
				{call "_burn_crash_end"}
			}
			{delay 12 3 "burn_die2"
				{call "_burn_crash"}
				{delay 16 2 "burn_die3"
					{tex_morph "burn2" 12}
					{call "_burn_crash"}
				}
			}
		}
	}
	{on "_burn_crash"
		{start_sound "crush/small/wood/"}
		(define "_burn_crash"
			{if rand %1
				{tear "piece_small_wood" bone %0
					{impulse up 0.3 dir 0.3}
				}
			}
		)	
		("_burn_crash" args "part1"			0.4)
		("_burn_crash" args "part2"			0.4)
		("_burn_crash" args "part3"			0.4)
		("_burn_crash" args "part4"			0.4)
		("_burn_crash" args "part5"			0.4)
	}
	{on contact
		{if volume "body"
			{if effector "fraction_small"
				{start_sound "crush/small/wood/"}
				{spawn "wood_hit_bul"}
				{with_effector
					{delete}
				}
				{if rand 0.3
					{call "crush"}
				}
			else effector "concrete"
				{if min_speed 20
					{spawn "hay_hit_small3" }
					{if rand 0.3
						{call "crush"}
					}
				else min_speed 5
					{spawn "hay_hit_small3" }
				}					
			else effector "steel"
				{if min_speed 20
					{start_sound "hit/small/wood_steel/"}
					{start_sound "hit/small/wood_solid/"}
					{spawn "hay_hit_small3" }
					{if rand 0.3
						{call "crush"}
					}
				else min_speed 5
					{spawn "hay_hit_small3" }
				}					
			else effector "hit_small"
				{if min_speed 20
					{spawn "hay_hit_small3" }
					{if rand 0.3
						{call "crush"}
					}
				else min_speed 5
					{spawn "hay_hit_small3" }
				}			
			else effector "car"
				{if min_speed 40
					{start_sound "crush/small/wood/"}
					{spawn "wood_crush_small" }
					{if rand 0.8
						{call "crush"}
					}
				else min_speed 25
					{start_sound "crush/small/wood/"}
					{if rand 0.3
						{call "crush"}
					}
				else 
					{impulse up 0.1 }
				}
			}
		}
		{if volume "part"
			{if min_speed 10
				{tear "piece_small_wood" bone from_volume
					{impulse up 2 1 dir 5 1 cx 9 2 cy 9 2 rnd_dir 4 no_position}
				}
			}		
		}		
	}		
	{on ground_hit
		{if volume "body"
			{if min_speed 25
				{call "crush"}
			}
		}
		{if volume "part"
			{if min_speed 25
				{tear "piece_small_wood" bone from_volume
					{impulse up 0.1}
				}
			}		
		}		
	}		
	{on bullet_hit
		{if volume "body"
			{if stuff "fx_40"
				{spawn "wood_crush_small" }
				{call "crush_big"}
				{bullet_detonate}
			else stuff "shell"
				{call "crush_big"}
				{spawn "wood_crush_small" }
			}
		}
	}
	{on blast_hit
		{if volume "part"
			{if min_energy 5
				{tear "piece_small_wood" bone from_volume
					{impulse up 5 1 dir 5 1 cx 9 2 cy 9 2 rnd_dir 4 no_position}
				}
			else min_energy 2
				{if rand 0.5		
					{tear "piece_small_wood" bone from_volume
						{impulse up 5 1 dir 5 1 cx 9 2 cy 9 2 rnd_dir 4 no_position}
					}
				}
			}
		}
		{if volume "body"
			{if min_energy 5
				{call "crush_big"}
			else min_energy 2
				{call "crush_slow"}
			else min_energy 1
				{call "crush"}
			}
		}
	}
	{on pierce
		{if volume "part"
			{if stuff "bullet hmgun"
				{tear "piece_small_wood" bone from_volume
					{impulse up 7 3 dir 5 1 cx 9 2 cy 9 2 rnd_dir 4 no_position}
				}
			else stuff "bullet ic"
				{if rand 0.8		
					{tear "piece_small_wood" bone from_volume
						{impulse up 5 1 dir 5 1 cx 9 2 cy 9 2 rnd_dir 4 no_position}
					}
				}	
			else stuff "zenite"
				{tear "piece_small_wood" bone from_volume
					{impulse up 5 1 dir 7 1 cx 6 2 cy 9 2 rnd_dir 4 no_position}
				}
			else stuff "bullet ap"
				{if rand 0.8		
					{tear "piece_small_wood" bone from_volume
						{impulse up 3 1 dir 3 1 cx 6 2 cy 6 2 rnd_dir 4 no_position}
					}
				}	
			else stuff "bullet sp"
				{if rand 0.4		
					{tear "piece_small_wood" bone from_volume
						{impulse up 3 1 dir 3 1 cx 6 2 cy 6 2 rnd_dir 4 no_position}
					}
				}	
			else stuff "bullet"
				{if rand 0.5		
					{tear "piece_small_wood" bone from_volume
						{impulse up 3 1 dir 3 1 cx 6 2 cy 6 2 rnd_dir 4 no_position}
					}
				}	
			}	
		}
		{if volume "body"
			{if stuff "bullet hmgun"
				{if rand 0.9		
					{call "crush"}
				}	
				{if "burned"
					{if rand 0.9		
						{call "crush"}
					}	
				}	
			}
			{if stuff "bullet normal ap"
				{if rand 0.8		
					{call "crush"}
				}	
				{if "burned"
					{if rand 0.8		
						{call "crush"}
					}	
				}	
			}
			{if stuff "bullet normal"
				{if rand 0.6		
					{call "crush"}
				}	
				{if "burned"
					{if rand 0.8		
						{call "crush"}
					}	
				}	
			}	
			{if stuff "bullet ic"
				{if rand 0.95		
					{call "crush"}
				}	
				{if "burned"
					{call "crush"}
				}	
			}	
			{if stuff "bullet sp"
				{if rand 0.6		
					{call "crush"}
				}	
				{if "burned"
					{if rand 0.5		
						{call "crush"}
					}	
				}	
			}
		}
	}	
	{on "crush"
		{if not "broken"
			{tags add "crush"}
			{spawn "spheredust_small" }
			{set "broken" 1}
			{delay_ex 0
				{set_skeleton "_x" sync}
			}
		}
	}
	{on "crush_slow"
		{if not "broken"
			{tags add "crush_slow"}
			{spawn "spheredust_small" }
			{set "broken" 1}
			{delay_ex 0
				{set_skeleton "_x" sync}
				(define "cut_part"
					{if rand %1
						{set "broken" 1}
						{tear "piece_small_wood" bone %0
							{impulse up 5 3 dir 3 1 cx 4 2 cy 4 2 rnd_dir 2 no_position}
						}
					}
				)	
				("cut_part" args "part1"	 		0.4)
				("cut_part" args "part2"	 		0.4)
				("cut_part" args "part3"	 		0.4)
				("cut_part" args "part4"	 		0.4)
				("cut_part" args "part5"	 		0.4)
				("cut_part" args "part6"	 		0.4)
			}
		}
	}
	{on "crush_big"
		{if not "broken"
			{tags add "crush_big"}
			{spawn "spheredust_small" }
			{set "broken" 1}
			{delay_ex 0
				{set_skeleton "_x" sync}
				(define "cut_part"
					{if rand %1
						{set "broken" 1}
						{tear "piece_small_wood" bone %0
							{impulse up 8 3 dir 3 1 cx 4 2 cy 4 2 rnd_dir 6 no_position}
						}
					}
				)	
				("cut_part" args "part1"	 		0.9)
				("cut_part" args "part2"	 		0.9)
				("cut_part" args "part3"	 		0.9)
				("cut_part" args "part4"	 		0.9)
				("cut_part" args "part5"	 		0.9)
				("cut_part" args "part6"	 		0.9)
			}
		}
	}
}

{"damage_x_stone"
	{on contact
		{if volume "body"
			{if effector "fraction_small"
				{with_effector
					{delete}
				}
				{if rand 0.3
					{call "crush"}
				}
			else effector "concrete"
				{if min_speed 20
					{if rand 0.3
						{call "crush"}
					}
				else min_speed 5
					{spawn "hay_hit_small3" }
				}					
			else effector "steel"
				{if min_speed 20
					{start_sound "hit/small/stuff"}
					{spawn "hay_hit_small3" }
					{if rand 0.3
						{call "crush"}
					}
				else min_speed 5
					{spawn "hay_hit_small3" }
				}					
			else effector "hit_small"
				{if min_speed 20
					{spawn "hay_hit_small3" }
					{if rand 0.3
						{call "crush"}
					}
				else min_speed 5
					{spawn "hay_hit_small3" }
				}			
			else effector "car"
				{if min_speed 40
					{start_sound "hit/small/stuff"}
					{if rand 0.8
						{call "crush"}
					}
				else min_speed 25
					{if rand 0.3
						{call "crush"}
					}
				else 
					{impulse up 0.1 }
				}
			else effector "vehicle"
				{if min_speed 15
					{start_sound "hit/small/stuff"}
					{if rand 0.3
						{call "crush"}
					}
				else min_speed 5
					{spawn "hay_hit_small3" }
				}					
			}
		}
	}		
	{on ground_hit
		{if volume "body"
			{if min_speed 30
				{call "crush"}
			}
		}
	}		
	{on bullet_hit
		{if volume "body"
			{if stuff "fx_40"
				{call "crush_big"}
				{bullet_detonate}
			else stuff "shell"
				{call "crush_big"}
			}
		}
	}
	{on blast_hit
		{if volume "body"
			{if min_energy 5
				{call "crush_big"}
			else min_energy 2
				{call "crush"}
			}
		}
	}
	{on pierce
		{if volume "body"
			{if stuff "bullet hmgun"
				{call "crush"}
			else stuff "bullet ic"
				{if rand 0.7		
					{call "crush"}
				}	
			else stuff "zenite"
				{call "crush"}
			else stuff "bullet normal ap"
				{if rand 0.5		
					{call "crush"}
				}	
			else stuff "bullet sp"
				{if rand 0.3		
					{call "crush"}
				}	
			else stuff "bullet normal"
				{if rand 0.3		
					{call "crush"}
				}	
			}	
		}
	}	
	{on "crush"
		{if not "broken"
			{start_sound "crush/small/concrete"}
			{spawn "spheredust_small" }
			{set "broken" 1}
			{delay_ex 0
				{set_skeleton "_x" sync}
				(define "cut_part"
					{set "broken" 1}
					{tear "piece_small_concrete" bone %0
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				)	
				("cut_part" args "part1"	 		)
				("cut_part" args "part2"	 		)
				("cut_part" args "part3"	 		)
				("cut_part" args "part4"	 		)
				("cut_part" args "part5"	 		)
				("cut_part" args "part6"	 		)
			}
		}
	}
	{on "crush_big"
		{if not "broken"
			{spawn "spheredust_small" }
			{set "broken" 1}
			{delay_ex 0
				{set_skeleton "_x" sync}
				(define "cut_part"
					{set "broken" 1}
					{tear "piece_small_concrete" bone %0
						{impulse up 4 2 dir 4 2 cx 4 2 cy 4 2 rnd_dir 2 no_position}
					}
				)	
				("cut_part" args "part1"	 		)
				("cut_part" args "part2"	 		)
				("cut_part" args "part3"	 		)
				("cut_part" args "part4"	 		)
				("cut_part" args "part5"	 		)
				("cut_part" args "part6"	 		)
			}
		}
	}
}


{"animated_hit"
	{on contact
		{if volume "body"
			{if effector "fraction_small"
				{with_effector
					{delete}
				}
			}
		else volume "down_hit"
			{if effector "fraction_small"
				{ani_play "down_hit" 1}	
			}
		else volume "right_hit"
			{if effector "fraction_small"
				{ani_play "right_hit" 1}	
			}
		else volume "left_hit"
			{if effector "fraction_small"
				{ani_play "left_hit" 1}	
			}
		else volume "fuse"
			{if effector "fraction_small"
				{spawn "metal_hit_wire2"}
				{burn fx "smoke_aero_small" time 4 fake}				
				{spawn "spheredust_small" }
				{with_effector
					{delete}
				}
			}
		}		
	}		
	{on bullet_hit
		{if stuff "bullet"
			{if volume "down_hit"
				{ani_play "down_hit" 0.3}	
			else volume "right_hit"
				{ani_play "right_hit" 0.7}	
			else volume "left_hit"
				{ani_play "left_hit" 0.7}	
			}		
		}
	}
	{on blast_hit
		{if min_energy 1
			{if volume "down_hit"
				{ani_play "down_hit" 0.3}	
			else volume "right_hit"
				{ani_play "right_hit" 0.7}	
			else volume "left_hit"
				{ani_play "left_hit" 0.7}	
			}		
		}
	}
	{on pierce
		{if not "burned"
			{if volume "fuse"
				{spawn "metal_hit_wire2"}
				{burn fx "smoke_aero_small" time 2 fake}				
				{spawn "spheredust_small" }
				{if rand 0.5 
					{set "burned" 1}
				}
			}
		}		
	}	
}



{"blasted"
	{on spawn
		(define "cut_part"
			{tear "piece_small_steel" bone %0
				{impulse up 7 3 dir 12 2 cx 25 2 cy 25 2 rnd_dir 7 no_position}
				{if rand 0.5 
					{burn fx "smoke_aero_small" time 4 fake}	
				else
					{burn fx "smoke_barrel_small3" time 2 fake}	
				}
			}
		)					
		("cut_part" args "sharp0"	)
		("cut_part" args "sharp1"	)
		("cut_part" args "sharp2"	)
		("cut_part" args "sharp3"	)
		("cut_part" args "sharp4"	)
		("cut_part" args "sharp5"	)
		("cut_part" args "sharp6"	)
	}
}

{"blasted_big"
	{on spawn
		(define "cut_part"
			{tear "piece_small_steel" bone %0
				{impulse up 12 4 dir 30 15 cx 30 15 cy 30 15 rnd_dir 25 no_position}
			}
		)					
		("cut_part" args "sharp0"	)
		("cut_part" args "sharp1"	)
		("cut_part" args "sharp2"	)
		("cut_part" args "sharp3"	)
		("cut_part" args "sharp4"	)
		("cut_part" args "sharp5"	)
		("cut_part" args "sharp6"	)
	}
}
{"st_armor"
	{on spawn
		{ani_play "instal" -1}
	}
	{on animation_event "part1"
		{spawn "spheredust_big_hit_steel" "armor"}
	}
	{on animation_event "part2"
		{spawn "spheredust_big_hit_steel" "armor2"}
	}
}


{"armor_set"
	{on pierce
		{if not volume "not_tear"
			{if volume "armor"
				{if rand 0.1		
					{burn volume fx "rex_emitters_armor" time 7 fake even_law}
					{start_sound "rex_emitters/emitters_light_metalls/"}
				}	
			}	
		}
	}
	{on bullet_hit
		{if volume "armor"
			{if stuff "hmgun"
				{if rand 0.3
					{start_sound "rex_emitters/emitters_light_metalls/"}
				}								
			else stuff "bullet"
				{if rand 0.2
					{burn volume fx "rex_emitters_armor" time 7 fake even_law}
					{start_sound "rex_emitters/emitters_light_metalls/"}
				}	
			}	
		}	
	}	
	{on blast_hit
		{if volume "armor"
			{if min_energy 0.5
				{if rand 0.3 
					{start_sound "rex_emitters/emitters_light_metalls/"}
				}	
			else min_energy 2
				{if rand 0.5
					{start_sound "rex_emitters/emitters_light_metalls/"}
				}	
			else min_energy 4
				{if rand 1
					{start_sound "rex_emitters/emitters_light_metalls/"}
				}	
			}
		}
	}	
}	


{"fireworks_detector"
	{on spawn
		{add_view "laser_sight_add_guided" "laser_detector" "camera"}
	}
	{on "open"
		{if not tagged "open"	
			{spawn "startsmoke_40mm" "start" x}
			{start_sound "weapon/shot/gun/atgm/punch/"}	
			{tags add "open"}
			{view hide	"laser_detector"}
			{tear "fireworks_start" bone "ammo"
				{gravity -3}
				{impulse forward -26 -10 com  }
			}
		}
	}
	{on overlap begin
		{if effector "vehicle"
			{call "open"}
		}
	}

}



{"fireworks_start"
	{on spawn
		{start_sound "detonation/firework_launch/"}	
		{add_view "guided_tail_fx_start" "start" "root"}
		{add_view "guided_tail_fx_fly" "fly" "root"}
		{view start	"start"}
		{delay 0.5 0.7
			{view start	"fly"}
			{view pause	"start"}
		}
		{delay 1 0.5
			{spawn "fireworks_blast" }
			{spawn "firework_00" }
			{spawn "firework_00" }
			{spawn "firework_00" }
			{spawn "firework_00" }
			{spawn "firework_00" }
			{spawn "firework_00" }
			{spawn "firework_00" }
			{spawn "firework_00" }
			{spawn "firework_00" }
			{start_sound "detonation/firework/"}	
			{delete}
		}
	}

}

{"firework_00"
	{on spawn
		{impulse up 2 1 cx 12 2 cy 12 2 rnd_dir 10 5 no_position}
		{add_view "fx_trace_firework" "fly" "root"}
		{add_view "fx_trace_firework2" "fly2" "root"}
		{if rand 0.4		
			{view start	"fly"}
		else
			{view start	"fly2"}
		}
		{delay 0.5 0.7
			{start_sound "detonation/firework/"}	
			{spawn "fireworks_blast_noparticle" }
			{delete}
		}
	}

}




{"jump_cap"
	{on overlap begin
		{if effector "vehicle"
			{with_effector
				{impulse up 0.1}
			}
		}
	}

}

{"small_fire_ground"
	{on ground_hit
		{spawn "small_fire_ground" }
		{delete}
	}
}

{"small_fire_ground_wick"
	{on ground_hit
		{spawn "small_wick_ground" }
		{delete}
	}
}

{"small_fuel_ground"
	{on ground_hit
		{spawn "small_fire_ground2" }
		{delete}
	}
}

{"glass_morph"
	{on spawn
		{call "glass_morph"}
	}
	{on "glass_morph"
		{if rand 0.1
			{tex_morph "1" 2}
		}
		{if rand 0.1
			{tex_morph "2" 2}
		}
		{if rand 0.1
			{tex_morph "3" 2}
		}
		{if rand 0.1
			{tex_morph "4" 2}
		}
		{if rand 0.1
			{tex_morph "5" 2}
		}
		{if rand 0.1
			{tex_morph "6" 2}
		}
		{if rand 0.1
			{tex_morph "7" 2}
		}
		{if rand 0.1
			{tex_morph "8" 2}
		}
		{if rand 0.1
			{tex_morph "9" 2}
		}
		{if rand 0.1
			{tex_morph "10" 2}
		}
		{delay_effect 10 "glass_morph"}
	}
}

{"physics_blasted"
	{on spawn
		{if not tagged "med_blast"
			{ani_play "med_blast" -10}		
		}
	}
	{on blast 
		{if volume "interior"
			(define "door_blast" ;door_lf_open
				{if min_energy 10
					{if tagged "close_%tag" 
						;{start_sound ""}
						{if not tagged "med_blast" 
							{ani_play "med_blast" 8}
							{spawn "rex_rocket_int"}		
							{spawn "emmiters_smoke" "emmiters_front" x}
							{spawn "emmiters_smoke" "emmiters_back" x}
						}
						{tags add "med_blast"}
						{if not tagged "med_blast_%tag" 
							{ani_play "open_door_blast_%tag" 1}
							{tags add "med_blast_%tag"}
							{area enable	"door_%tag_expl"}
							{area disable	"door_%tag_close"}
							{area disable	"door_%tag_open"}
							{volumes "door_%tag_open" disable touch}
						}
						{delay 0
							{if rand 0.9							
								{tear "piece_small_steel" bone "door_%tag_2_locker"
									{burn volume fx "smoke_barrel_small_new" time 8 fake even_law}
									;{spawn "spheredust_small_short_arm" }
									{impulse forward 26 10 com  fx -5 10 cx 12 33}
								}
								{tear "piece_small_steel" bone "door_%tag_1_locker"
									{burn volume fx "smoke_barrel_small_new" time 8 fake even_law}
									;{spawn "spheredust_small_short_arm" }
									{impulse forward 26 10 com  fx -5 10 cx 12 3}
								}
							}
							{if rand 0.7							
								{tear "piece_medium_steel" bone "door_%tag"
									{burn volume fx "smoke_barrel_small_new" time 8 fake even_law}
									{impulse forward 25 10 com  }
								}
							}
							{if rand 0.2							
								{tear "piece_big_steel" bone "side_r"
									{burn volume "side_r" fx "smoke_bats" time 20 fake even_law}
									{impulse forward 25 10 com  }
								}
							}
							{if rand 0.2							
								{tear "piece_big_steel" bone "side_l"
									{burn volume "side_r" fx "smoke_bats" time 20 fake even_law}
									{impulse forward 25 10 com  }
								}
							}
							{if rand 0.4							
								{tear "piece_big_steel" bone "roof"
									{burn volume "roof" fx "smoke_bats" time 20 fake even_law}
									{impulse up 5 forward 6 17 com  fx -5 10 cx 2}
								}
							}
						}
					}
				else min_energy 3
					{if tagged "close_%tag" 
						{if not tagged "small_blast_%tag" 
							;{start_sound ""}
							{spawn "emmiters_smoke" "emmiters_front" x}
							{spawn "emmiters_smoke" "emmiters_back" x}
							{tags add "small_blast_%tag"}
							{area enable	"door_%tag_expl"}
							{area disable	"door_%tag_close"}
							{area disable	"door_%tag_open"}
							{ani_play "open_door_blast_%tag" 1}
							{volumes "door_%tag_open" disable touch}
							{if rand 0.2							
								{tear "piece_medium_steel" bone "door_%tag"
									{burn volume fx "smoke_barrel_small_new" time 8 fake even_law}
									{impulse up 3 dir -3 6 forward 10 20 com  fx -5 10 cx 12 3}
								}
							}
							{if rand 0.5							
								{tear "piece_small_steel" bone "door_%tag_2_handle"
									{burn volume fx "smoke_barrel_small_new" time 8 fake even_law}
									;{spawn "spheredust_small_short_arm" }
									{impulse up 3 dir -3 6 forward 10 20 com  fx -5 10 cx 12 3}
								}
								{tear "piece_small_steel" bone "door_%tag_1_handle"
									{burn volume fx "smoke_barrel_small_new" time 8 fake even_law}
									;{spawn "spheredust_small_short_arm" }
									{impulse up 3 dir -3 6 forward 10 20 com  fx -5 10 cx 12 3}
								}
							}
						}
					}				
				}
			)
			("door_blast" tag(rt) )
			("door_blast" tag(lt) )
			("door_blast" tag(rf) )
			("door_blast" tag(lf) )
		}
	}
}

{"bullet_shellhole"
	{on spawn
		{if rand 0.5
			{tex_mod "rand1"}
		else rand 0.4
			{tex_mod "rand2"}
		else rand 0.35
			{tex_mod "rand3"}
		else rand 0.3
			{tex_mod "rand4"}
		}
	}
}

{"vehicle_skin"
	{on spawn
		{if not "backward"
			{if rand 0.02
				{tex_mod "001"}
			else rand 0.02
				{tex_mod "007"}
			else rand 0.02
				{tex_mod "011"}
			else rand 0.02
				{tex_mod "013"}
			else rand 0.02
				{tex_mod "014"}
			else rand 0.02
				{tex_mod "015"}
			else rand 0.02
				{tex_mod "016"}
			else rand 0.02
				{tex_mod "021"}
			else rand 0.02
				{tex_mod "024"}
			else rand 0.02
				{tex_mod "027"}
			else rand 0.02
				{tex_mod "033"}
			else rand 0.02
				{tex_mod "036"}
			else rand 0.02
				{tex_mod "037"}
			else rand 0.02
				{tex_mod "038"}
			else rand 0.02
				{tex_mod "039"}
			else rand 0.02
				{tex_mod "040"}
			else rand 0.02
				{tex_mod "042"}
			else rand 0.02
				{tex_mod "046"}
			else rand 0.02
				{tex_mod "057"}
			else rand 0.02
				{tex_mod "062"}
			else rand 0.02
				{tex_mod "069"}
			else rand 0.02
				{tex_mod "078"}
			else rand 0.02
				{tex_mod "079"}
			else rand 0.02
				{tex_mod "081"}
			else rand 0.02
				{tex_mod "082"}
			else rand 0.02
				{tex_mod "083"}
			else rand 0.02
				{tex_mod "087"}
			else rand 0.02
				{tex_mod "089"}
			else rand 0.02
				{tex_mod "090"}
			else rand 0.02
				{tex_mod "095"}
			else rand 0.02
				{tex_mod "096"}
			else rand 0.02
				{tex_mod "100"}
			else rand 0.02
				{tex_mod "111"}
			else rand 0.02
				{tex_mod "112"}
			else rand 0.02
				{tex_mod "113"}
			else rand 0.02
				{tex_mod "114"}
			else rand 0.02
				{tex_mod "116"}
			else rand 0.02
				{tex_mod "122"}
			else rand 0.02
				{tex_mod "124"}
			else rand 0.02
				{tex_mod "126"}
			else rand 0.02
				{tex_mod "136"}
			else rand 0.02
				{tex_mod "143"}
			else rand 0.02
				{tex_mod "146"}
			else rand 0.02
				{tex_mod "147"}
			else rand 0.02
				{tex_mod "152"}
			else rand 0.02
				{tex_mod "158"}
			else rand 0.02
				{tex_mod "161"}
			else rand 0.02
				{tex_mod "165"}
			else rand 0.02
				{tex_mod "172"}
			else rand 0.02
				{tex_mod "173"}
			else rand 0.02
				{tex_mod "174"}
			else rand 0.02
				{tex_mod "176"}
			else rand 0.02
				{tex_mod "178"}
			else rand 0.02
				{tex_mod "190"}
			else rand 0.02
				{tex_mod "194"}
			else rand 0.02
				{tex_mod "197"}
			}
			{set "backward" 1}
		}
	}

}


;nazi
{"z_prop"
	{on "volume_hide"
		{bone hide "wall"}
		{bone hide "wall2"}		
	}
}
{"gibz"
	{on spawn 
		{add_view "z_blood-drops" "blood_fx" "fx"}		
		{view start "blood_fx"}		
		{gravity 0.6}
		{delay 15
			{view stop "blood_fx"}
		}	
	}
	{on ground_hit
		{spawn "blood_medium"}
	}
}

{"melee_contact"
	{on spawn
		{impulse up 0.01}		
		{delay 0.1
			{delete}
		}
	}
}

{"shotgun_contact"
	{on spawn
		{Gravity 2} 	
		{impulse dir 0 forward 80 0 rnd_dir 4 3 com  fx 0}	
		{volumes enable contact}
		{delay 0.35 {delete}}			
	}
	{on contact 
		{delete}
	}
	{on ground_hit
		{delete}
	}
}

{"thunder_contact"
	{on spawn
		{Gravity 0} 	
		{impulse dir 0 forward 50 0 rnd_dir 4 3 com  fx 0}	
		{volumes enable contact}
		{delay 0.2 {delete}}			
	}
	{on contact 
		{delay 0.1 {delete}}
	}
}





{"drop"
	{on spawn
		{impulse up 0.1}
		{start_sound "amb_elements/drop/"}	
	}
	{on contact
		(define "contact_fx"
			{if min_speed %2
				{if material %0 			
					{spawn "spheredust_big_short" }
					{start_sound "hit/drop/%1/"}	
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		25 )
		("contact_fx" args "steel" 		metal 			25 )
		("contact_fx" args "wood" 		wood_hollow		25 )
		("contact_fx" args "misc" 		carpet 			25 )
	}
	{on ground_hit
		{if contact_velocity 50
			{spawn "spheredust_big_short" }
		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/drop/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		carpet 			15 )
		("terrain_fx" args "grass" 			grass 			15 )
		("terrain_fx" args "road" 			concrete 		15 )
		("terrain_fx" args "country_road" 	mud 			15 )
		("terrain_fx" args "sand" 			sand 			15 )
		("terrain_fx" args "snow"  			mud 			15 )
		("terrain_fx" args "water" 			water 			15 )
		("terrain_fx" args "bridge" 		wood_solid 		15 )
		("terrain_fx" args "bridge_wood" 	wood_hollow		15 )
		("terrain_fx" args "floor" 			carpet 			15 )
		("terrain_fx" args "rock" 			ground 			15 )
		("terrain_fx" args "metal" 			metal 			15 )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			15 )
		("terrain_fx" args "shoot_emit_mtl_int" 			metal 			15 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			15 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			15 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			15 )
		("terrain_fx" args "shoot_emit_int_wood" 			wood_solid 			15 )
	}
}


{"weapon_u"
	{on spawn
		{delay 1.5
			{if prop "pistol"
				{start_sound "weapon/shell_eject/shell12"}	
				{ani_play "empty" 1 }
			else prop "g36_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/g36_series/"}
			else prop "sig_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/sig_series/"}
			else prop "pp_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/pp_series/"}
			else prop "mp7_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/mp7_series/"}
			else prop "mp5_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/mp5_series/"}
			else prop "ump_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/ump_series/"}
			else prop "aug_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/aug_series/"}
			else prop "ak_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/ak_series/"}
			else prop "galil_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/galil_series/"}
			else prop "m4a1_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/m4a1_series/"}
			else prop "smg_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/smg_series/"}
			else prop "aa12_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/smg_series/"}
			else prop "mg_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/mg_series/"}
			else prop "mg36_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/mg36_series/"}
			else prop "sniper_series"
				{ani_play "armed" 1}
				{start_sound "weapon/armed/snrifle_series/"}
			}
		}
		{delay 4
			{impulse up 0.1}
			(define "cut_part"
				{if rand %1
					{tear "piece_small_steel" bone %0
						{impulse up 0.2 dir 0.2}
						{delay 2
							{hide 3}
						}
					}
				}
			)	
			("cut_part" args "armed"	 		0.8)
			("cut_part" args "magazine"	 		0.8)
			("cut_part" args "barrel"	 		0.8)
			("cut_part" args "trigger"	 		0.8)
			("cut_part" args "stock"	 		0.8)
			("cut_part" args "slide"	 		0.8)
			("cut_part" args "sight"	 		0.8)
			("cut_part" args "scope"	 		0.8)
			("cut_part" args "muzzle"	 		0.8)
			("cut_part" args "part1"	 		0.8)
			("cut_part" args "part2"	 		0.8)
			("cut_part" args "part3"	 		0.8)
			("cut_part" args "part4"	 		0.8)
			("cut_part" args "part5"	 		0.8)
			("cut_part" args "part6"	 		0.8)
			("cut_part" args "part7"	 		0.8)
			("cut_part" args "part8"	 		0.8)
			("cut_part" args "part9"	 		0.8)
			("cut_part" args "part10"	 		0.8)
			("cut_part" args "part11"	 		0.8)
		}
		{delay 6
			{delete}
		}	
	}
	{on ground_hit
		(define "cut_part"
			{if rand %1
				{tear "piece_small_steel" bone %0
					{impulse up 0.2 dir 0.2}
					{delay 1
						{hide 5}
					}
				}
			}
		)	
		("cut_part" args "silencer"	 			0.7)
		("cut_part" args "rail"	 			0.7)
		("cut_part" args "handguard"		0.7)
		("cut_part" args "grip"	 			0.7)
		("cut_part" args "armed"	 		0.5)
		("cut_part" args "scope"	 		0.8)
		("cut_part" args "magazine"	 		0.8)
		("cut_part" args "barrel"	 		0.8)
		("cut_part" args "trigger"	 		0.8)
		("cut_part" args "stock"	 		0.8)
		("cut_part" args "slide"	 		0.8)
		("cut_part" args "sight"	 		0.8)
		("cut_part" args "muzzle"	 		0.8)
		("cut_part" args "part1"	 		0.8)
		("cut_part" args "part2"	 		0.8)
		("cut_part" args "part3"	 		0.8)
		("cut_part" args "part4"	 		0.8)
		("cut_part" args "part5"	 		0.8)
		("cut_part" args "part6"	 		0.8)
		("cut_part" args "part7"	 		0.8)
		("cut_part" args "part8"	 		0.8)
		("cut_part" args "part9"	 		0.8)
		("cut_part" args "part10"	 		0.8)
		("cut_part" args "part11"	 		0.8)
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
{"proj_dummy"		
	{on "link_effects"			
		{delay 0
			{with_linked_entity "missile" 				
				{call "start_5m_fg"}	
			}
		}			
	}		
	{on "start_guidance_seq"			
		{call "launch"}			
		{call "chdir_repeater"}		
	}	     
	{on "check_direction"
		{impulse forward 0.5 up 0.1 com}	                             		
		{gravity 0.1}		
		{delay 0.01 {impulse forward -0.1 com}{gravity 0.01}}		
		{delay 0.02 {impulse up -0.1 com}{gravity 0.01}}		
		{delay 0.03 {impulse forward 0.1 com}{gravity 0.01}}		
		{delay 0.04 {impulse up 0.1 com}{gravity 0.01}}		
		{delay 0.05 {impulse forward 0.1 com}{gravity 0.01}}		
		{delay 0.06 {impulse up -0.1 com}{gravity 0.01}}		
		{delay 0.07 {impulse forward -0.1 com}{gravity 0.01}}		
		{delay 0.08 {impulse up 0.1 com}{gravity 0.01}}		
		{delay 0.09 {impulse up -0.1 com}{gravity 0.01}}		
		{delay 0.10 {impulse up 0.1 com}{gravity 0.01}}		
		{delay 0.11 {impulse up -0.1 com}{gravity 0.01}}		
		{delay 0.12 {impulse up 0.1 com}{gravity 0.01}}		
		{delay 0.13 {impulse up -0.1 com}{gravity 0.01}}		
		{delay 0.14 {impulse up 0.1 com}{gravity 0.01}}		
		{delay 0.15 {impulse up -0.1 com}{gravity 0.01}}					
		{delay 0.05 			
			{call "change_direction"}		
		}			    
	}	     
	{on "turn_off_ik"		
		{ik_enable "stage_hor01" 0}{ik_enable "stage_ver01" 0}		
		{ik_enable "stage_hor02" 0}{ik_enable "stage_ver02" 0}		
		{ik_enable "stage_hor03" 0}{ik_enable "stage_ver03" 0}		
		{ik_enable "stage_hor04" 0}{ik_enable "stage_ver04" 0}		
		{ik_enable "stage_hor05" 0}{ik_enable "stage_ver05" 0}		
		{ik_enable "stage_hor06" 0}{ik_enable "stage_ver06" 0}		
		{ik_enable "stage_hor07" 0}{ik_enable "stage_ver07" 0}		
		{ik_enable "stage_hor08" 0}{ik_enable "stage_ver08" 0}		
		{ik_enable "stage_hor09" 0}{ik_enable "stage_ver09" 0}		
		{ik_enable "stage_hor10" 0}{ik_enable "stage_ver10" 0}		
		{ik_enable "stage_hor11" 0}{ik_enable "stage_ver11" 0}	
		{ik_enable "stage_hor12" 0}{ik_enable "stage_ver12" 0}		
		{ik_enable "stage_hor13" 0}{ik_enable "stage_ver13" 0}		
		{ik_enable "stage_hor14" 0}{ik_enable "stage_ver14" 0}		
		{ik_enable "stage_hor15" 0}{ik_enable "stage_ver15" 0}		
		{ik_enable "stage_hor16" 0}{ik_enable "stage_ver16" 0}	
		{ik_enable "stage_hor17" 0}{ik_enable "stage_ver17" 0}	
		{ik_enable "stage_hor18" 0}{ik_enable "stage_ver18" 0}	
		{ik_enable "stage_hor19" 0}{ik_enable "stage_ver19" 0}		
		{ik_enable "stage_hor20" 0}{ik_enable "stage_ver20" 0}	
		{ik_enable "stage_hor21" 0}{ik_enable "stage_ver21" 0}	
		{ik_enable "stage_hor22" 0}{ik_enable "stage_ver22" 0}		
		{ik_enable "stage_hor23" 0}{ik_enable "stage_ver23" 0}		
		{ik_enable "stage_hor24" 0}{ik_enable "stage_ver24" 0}	
		{ik_enable "stage_hor25" 0}{ik_enable "stage_ver25" 0}	
		{ik_enable "stage_hor26" 0}{ik_enable "stage_ver26" 0}	
		{ik_enable "stage_hor27" 0}{ik_enable "stage_ver27" 0}	
		{ik_enable "stage_hor28" 0}{ik_enable "stage_ver28" 0}	
		{ik_enable "stage_hor29" 0}{ik_enable "stage_ver29" 0}	
		{ik_enable "stage_hor30" 0}{ik_enable "stage_ver30" 0}	
		{ik_enable "stage_hor31" 0}{ik_enable "stage_ver31" 0}	
		{ik_enable "stage_hor32" 0}{ik_enable "stage_ver32" 0}	
		{ik_enable "stage_hor33" 0}{ik_enable "stage_ver33" 0}	
		{ik_enable "stage_hor34" 0}{ik_enable "stage_ver34" 0}		
		{ik_enable "stage_hor35" 0}{ik_enable "stage_ver35" 0}	
		{ik_enable "stage_hor36" 0}{ik_enable "stage_ver36" 0}		
		{ik_enable "stage_hor37" 0}{ik_enable "stage_ver37" 0}	
		{ik_enable "stage_hor38" 0}{ik_enable "stage_ver38" 0}		
		{ik_enable "stage_hor39" 0}{ik_enable "stage_ver39" 0}		
		{ik_enable "stage_hor40" 0}{ik_enable "stage_ver40" 0}	  
	}		  
	{on "change_stage"	     	     	   
		{update_visibility_patch}	        
		{if tagged "stage_01" {tags remove "stage_01"} {tags add "stage_02"} {ik_enable "stage_hor02" 1}{ik_enable "stage_ver02" 1}{ik_enable "stage_hor01" 0}{ik_enable "stage_ver01" 0}{tags add "start"}		
		else tagged "stage_02" {tags remove "stage_02"} {tags add "stage_03"} {ik_enable "stage_hor03" 1}{ik_enable "stage_ver03" 1}{ik_enable "stage_hor02" 0}{ik_enable "stage_ver02" 0}	
		else tagged "stage_03" {tags remove "stage_03"} {tags add "stage_04"} {ik_enable "stage_hor04" 1}{ik_enable "stage_ver04" 1}{ik_enable "stage_hor03" 0}{ik_enable "stage_ver03" 0}	
		else tagged "stage_04" {tags remove "stage_04"} {tags add "stage_05"} {ik_enable "stage_hor05" 1}{ik_enable "stage_ver05" 1}{ik_enable "stage_hor04" 0}{ik_enable "stage_ver04" 0}	
		else tagged "stage_05" {tags remove "stage_05"} {tags add "stage_06"} {ik_enable "stage_hor06" 1}{ik_enable "stage_ver06" 1}{ik_enable "stage_hor05" 0}{ik_enable "stage_ver05" 0}	
		else tagged "stage_06" {tags remove "stage_06"} {tags add "stage_07"} {ik_enable "stage_hor07" 1}{ik_enable "stage_ver07" 1}{ik_enable "stage_hor06" 0}{ik_enable "stage_ver06" 0}	
		else tagged "stage_07" {tags remove "stage_07"} {tags add "stage_08"} {ik_enable "stage_hor08" 1}{ik_enable "stage_ver08" 1}{ik_enable "stage_hor07" 0}{ik_enable "stage_ver07" 0}
		else tagged "stage_08" {tags remove "stage_08"} {tags add "stage_09"} {ik_enable "stage_hor09" 1}{ik_enable "stage_ver09" 1}{ik_enable "stage_hor08" 0}{ik_enable "stage_ver08" 0}	
		else tagged "stage_09" {tags remove "stage_09"} {tags add "stage_10"}  {ik_enable "stage_hor10" 1}{ik_enable "stage_ver10" 1}{ik_enable "stage_hor09" 0}{ik_enable "stage_ver09" 0}	{tags add "50m_fly"}		
		else tagged "stage_10" {tags remove "stage_10"} {tags add "stage_11"} {ik_enable "stage_hor11" 1}{ik_enable "stage_ver11" 1}{ik_enable "stage_hor10" 0}{ik_enable "stage_ver10" 0}		
		else tagged "stage_11" {tags remove "stage_11"} {tags add "stage_12"} {ik_enable "stage_hor12" 1}{ik_enable "stage_ver12" 1}{ik_enable "stage_hor11" 0}{ik_enable "stage_ver11" 0}		
		else tagged "stage_12" {tags remove "stage_12"} {tags add "stage_13"} {ik_enable "stage_hor13" 1}{ik_enable "stage_ver13" 1}{ik_enable "stage_hor12" 0}{ik_enable "stage_ver12" 0}		
		else tagged "stage_13" {tags remove "stage_13"} {tags add "stage_14"} {ik_enable "stage_hor14" 1}{ik_enable "stage_ver14" 1}{ik_enable "stage_hor13" 0}{ik_enable "stage_ver13" 0}		
		else tagged "stage_14" {tags remove "stage_14"} {tags add "stage_15"} {ik_enable "stage_hor15" 1}{ik_enable "stage_ver15" 1}{ik_enable "stage_hor14" 0}{ik_enable "stage_ver14" 0}		
		else tagged "stage_15" {tags remove "stage_15"} {tags add "stage_16"} {ik_enable "stage_hor16" 1}{ik_enable "stage_ver16" 1}{ik_enable "stage_hor15" 0}{ik_enable "stage_ver15" 0}		
		else tagged "stage_16" {tags remove "stage_16"} {tags add "stage_17"} {ik_enable "stage_hor17" 1}{ik_enable "stage_ver17" 1}{ik_enable "stage_hor16" 0}{ik_enable "stage_ver16" 0}		
		else tagged "stage_17" {tags remove "stage_17"} {tags add "stage_18"} {ik_enable "stage_hor18" 1}{ik_enable "stage_ver18" 1}{ik_enable "stage_hor17" 0}{ik_enable "stage_ver17" 0}		
		else tagged "stage_18" {tags remove "stage_18"} {tags add "stage_19"} {ik_enable "stage_hor19" 1}{ik_enable "stage_ver19" 1}{ik_enable "stage_hor18" 0}{ik_enable "stage_ver18" 0}		
		else tagged "stage_19" {tags remove "stage_19"} {tags add "stage_20"} {ik_enable "stage_hor20" 1}{ik_enable "stage_ver20" 1}{ik_enable "stage_hor19" 0}{ik_enable "stage_ver19" 0}{tags add "100m_fly"}		
		else tagged "stage_20" {tags remove "stage_20"} {tags add "stage_21"} {ik_enable "stage_hor21" 1}{ik_enable "stage_ver21" 1}{ik_enable "stage_hor20" 0}{ik_enable "stage_ver20" 0}		
		else tagged "stage_21" {tags remove "stage_21"} {tags add "stage_22"} {ik_enable "stage_hor22" 1}{ik_enable "stage_ver22" 1}{ik_enable "stage_hor21" 0}{ik_enable "stage_ver21" 0}		
		else tagged "stage_22" {tags remove "stage_22"} {tags add "stage_23"} {ik_enable "stage_hor23" 1}{ik_enable "stage_ver23" 1}{ik_enable "stage_hor22" 0}{ik_enable "stage_ver22" 0}		
		else tagged "stage_23" {tags remove "stage_23"} {tags add "stage_24"} {ik_enable "stage_hor24" 1}{ik_enable "stage_ver24" 1}{ik_enable "stage_hor23" 0}{ik_enable "stage_ver23" 0}		
		else tagged "stage_24" {tags remove "stage_24"} {tags add "stage_25"} {ik_enable "stage_hor25" 1}{ik_enable "stage_ver25" 1}{ik_enable "stage_hor24" 0}{ik_enable "stage_ver24" 0}		
		else tagged "stage_25" {tags remove "stage_25"} {tags add "stage_26"} {ik_enable "stage_hor26" 1}{ik_enable "stage_ver26" 1}{ik_enable "stage_hor25" 0}{ik_enable "stage_ver25" 0}		
		else tagged "stage_26" {tags remove "stage_26"} {tags add "stage_27"} {ik_enable "stage_hor27" 1}{ik_enable "stage_ver27" 1}{ik_enable "stage_hor26" 0}{ik_enable "stage_ver26" 0}	
		else tagged "stage_27" {tags remove "stage_27"} {tags add "stage_28"} {ik_enable "stage_hor28" 1}{ik_enable "stage_ver28" 1}{ik_enable "stage_hor27" 0}{ik_enable "stage_ver27" 0}	
		else tagged "stage_28" {tags remove "stage_28"} {tags add "stage_29"} {ik_enable "stage_hor29" 1}{ik_enable "stage_ver29" 1}{ik_enable "stage_hor28" 0}{ik_enable "stage_ver28" 0}	
		else tagged "stage_29" {tags remove "stage_29"} {tags add "stage_30"} {ik_enable "stage_hor30" 1}{ik_enable "stage_ver30" 1}{ik_enable "stage_hor29" 0}{ik_enable "stage_ver29" 0}{tags add "150m_fly"}		
		else tagged "stage_30" {tags remove "stage_30"} {tags add "stage_31"} {ik_enable "stage_hor31" 1}{ik_enable "stage_ver31" 1}{ik_enable "stage_hor30" 0}{ik_enable "stage_ver30" 0}		
		else tagged "stage_31" {tags remove "stage_31"} {tags add "stage_32"} {ik_enable "stage_hor32" 1}{ik_enable "stage_ver32" 1}{ik_enable "stage_hor31" 0}{ik_enable "stage_ver31" 0}	
		else tagged "stage_32" {tags remove "stage_32"} {tags add "stage_33"} {ik_enable "stage_hor33" 1}{ik_enable "stage_ver33" 1}{ik_enable "stage_hor32" 0}{ik_enable "stage_ver32" 0}	
		else tagged "stage_33" {tags remove "stage_33"} {tags add "stage_34"} {ik_enable "stage_hor34" 1}{ik_enable "stage_ver34" 1}{ik_enable "stage_hor33" 0}{ik_enable "stage_ver33" 0}	
		else tagged "stage_34" {tags remove "stage_34"} {tags add "stage_35"} {ik_enable "stage_hor35" 1}{ik_enable "stage_ver35" 1}{ik_enable "stage_hor34" 0}{ik_enable "stage_ver34" 0}	
		else tagged "stage_35" {tags remove "stage_35"} {tags add "stage_36"} {ik_enable "stage_hor36" 1}{ik_enable "stage_ver36" 1}{ik_enable "stage_hor35" 0}{ik_enable "stage_ver35" 0}	
		else tagged "stage_36" {tags remove "stage_36"} {tags add "stage_37"} {ik_enable "stage_hor37" 1}{ik_enable "stage_ver37" 1}{ik_enable "stage_hor36" 0}{ik_enable "stage_ver36" 0}	
		else tagged "stage_37" {tags remove "stage_37"} {tags add "stage_38"} {ik_enable "stage_hor38" 1}{ik_enable "stage_ver38" 1}{ik_enable "stage_hor37" 0}{ik_enable "stage_ver37" 0}	
		else tagged "stage_38" {tags remove "stage_38"} {tags add "stage_39"} {ik_enable "stage_hor39" 1}{ik_enable "stage_ver39" 1}{ik_enable "stage_hor38" 0}{ik_enable "stage_ver38" 0}	
		else tagged "stage_39" {tags remove "stage_39"} {tags add "stage_40"}  {ik_enable "stage_hor40" 1}{ik_enable "stage_ver40" 1}{ik_enable "stage_hor39" 0}{ik_enable "stage_ver39" 0}{tags add "200m_fly"}		
		else tagged "stage_40" {tags remove "stage_40"} {call "detonate"} }		
		{call "check_altitude"}	
		{call "check_range"} 
		; {if not altitude 15		
			; {delay 0.05
				; {call "check_altitude"} 
			; }			
			; {delay 0.1
				; {call "check_altitude"} 
			; }		
		; }	   
	}		
	{on "check_altitude"			
		{with_linked_entity "missile"				
			{if not altitude 0.1					
				{if not tagged "underwater_launch"
					;{spawn "proj_deleter" "root"
					;	{delay 0.2 {delete}}					
					;}
				}				
			else not altitude 10
				{tags remove "underwater_launch"}	
				{view pause "proj_tail10"}			
				{view pause "proj_tail20"}					
				{view start "proj_tail30"}					
				{view pause "proj_tail"}			
			else					
				{tags remove "underwater_launch"}				
				{view pause "proj_tail10"}				
				{view pause "proj_tail20"}					
				{view pause "proj_tail30"}					
				{view start "proj_tail"}				
			}			
		}		
	}	     
	{on "detonate"	      
		{if not "detonate"			
			{set "exploded" 1}			
			{with_linked_entity "missile"				
				{stuff_detonate}		
			}			
			{delete}	      
		}	    
	}	
	{on "destroyed_by_ground"	      
		{if not "detonate"			
			{set "exploded" 1}			
			{with_linked_entity "missile"			
				{delete}		
			}			
			{delete}	       
		}	     
	}		     
	{on contact 		
		{call "detonate"}		
	}		
	{on pierce overload	       
		{if not stuff "noview"				
			{call "detonate"}	          
		}	   
	}	   
	{on bullet_hit overload	
		{if not stuff "noview"				
			{call "detonate"}	  
		}	 	
	}	 	
	(define "speed_fast"		               	
		{on "chdir_repeater" overload			
			{delay (/	0.16	%coeff) {call "check_direction"}}			
			{delay (/	0.32	%coeff) {call "check_direction"}}		
			{delay (/	0.48	%coeff) {call "check_direction"}}		
			{delay (/	0.64	%coeff) {call "check_direction"}}		
			{delay (/	0.8	%coeff) {call "check_direction"}}			
			{delay (/	0.96	%coeff) {call "check_direction"}}		
			{delay (/	1.12	%coeff) {call "check_direction"}}		
			{delay (/	1.28	%coeff) {call "check_direction"}}			
			{delay (/	1.44	%coeff) {call "check_direction"}}			
			{delay (/	1.6	%coeff) {call "check_direction"}}		
			{delay (/	1.76	%coeff) {call "check_direction"}}		
			{delay (/	1.92	%coeff) {call "check_direction"}}		
			{delay (/	2.08	%coeff) {call "check_direction"}}		
			{delay (/	2.24	%coeff) {call "check_direction"}}		
			{delay (/	2.4	%coeff) {call "check_direction"}}			
			{delay (/	2.56	%coeff) {call "check_direction"}}			
			{delay (/	2.72	%coeff) {call "check_direction"}}			
			{delay (/	2.88	%coeff) {call "check_direction"}}		
			{delay (/	3.04	%coeff) {call "check_direction"}}			
			{delay (/	3.2	%coeff) {call "check_direction"}}		
			{delay (/	3.36	%coeff) {call "check_direction"}}		
			{delay (/	3.52	%coeff) {call "check_direction"}}		
			{delay (/	3.68	%coeff) {call "check_direction"}}		
			{delay (/	3.84	%coeff) {call "check_direction"}}		
			{delay (/	4	%coeff) {call "check_direction"}}			
			{delay (/	4.16	%coeff) {call "check_direction"}}		
			{delay (/	4.32	%coeff) {call "check_direction"}}		
			{delay (/	4.48	%coeff) {call "check_direction"}}		
			{delay (/	4.64	%coeff) {call "check_direction"}}		
			{delay (/	4.8	%coeff) {call "check_direction"}}			
			{delay (/	4.96	%coeff) {call "check_direction"}}		
			{delay (/	5.12	%coeff) {call "check_direction"}}		
			{delay (/	5.28	%coeff) {call "check_direction"}}		
			{delay (/	5.44	%coeff) {call "check_direction"}}		
			{delay (/	5.6	%coeff) 	{call "check_direction"}}			
			{delay (/	5.76	%coeff) {call "check_direction"}}		
			{delay (/	5.92	%coeff) {call "check_direction"}}		
			{delay (/	6.08	%coeff) {call "check_direction"}}		
			{delay (/	6.24	%coeff) {call "check_direction"}}		
			{delay (/	6.4	%coeff) 	{call "check_direction"}}			
		}	
		{on "launch" overload 
			{ani_play "center_veryfast" (* 0.75 %coeff)	}	
		}	
	)	
	(define "speed_slow"		               	
		{on "chdir_repeater" overload			
			{delay (/	0.24	%coeff) {call "check_direction"}}			
			{delay (/	0.48	%coeff) {call "check_direction"}}			
			{delay (/	0.72	%coeff) {call "check_direction"}}			
			{delay (/	0.96	%coeff) {call "check_direction"}}			
			{delay (/	1.2	%coeff) {call "check_direction"}}			
			{delay (/	1.44	%coeff) {call "check_direction"}}			
			{delay (/	1.68	%coeff) {call "check_direction"}}			
			{delay (/	1.92	%coeff) {call "check_direction"}}		
			{delay (/	2.16	%coeff) {call "check_direction"}}			
			{delay (/	2.4	%coeff) {call "check_direction"}}			
			{delay (/	2.64	%coeff) {call "check_direction"}}		
			{delay (/	2.88	%coeff) {call "check_direction"}}			
			{delay (/	3.12	%coeff) {call "check_direction"}}			
			{delay (/	3.36	%coeff) {call "check_direction"}}			
			{delay (/	3.6	%coeff) {call "check_direction"}}			
			{delay (/	3.84	%coeff) {call "check_direction"}}			
			{delay (/	4.08	%coeff) {call "check_direction"}}			
			{delay (/	4.32	%coeff) {call "check_direction"}}			
			{delay (/	4.56	%coeff) {call "check_direction"}}		
			{delay (/	4.8	%coeff) {call "check_direction"}}			
			{delay (/	5.04	%coeff) {call "check_direction"}}		
			{delay (/	5.28	%coeff) {call "check_direction"}}		
			{delay (/	5.52	%coeff) {call "check_direction"}}		
			{delay (/	5.76	%coeff) {call "check_direction"}}		
			{delay (/	6	%coeff) {call "check_direction"}}		
			{delay (/	6.24	%coeff) {call "check_direction"}}			
			{delay (/	6.48	%coeff) {call "check_direction"}}		
			{delay (/	6.72	%coeff) {call "check_direction"}}		
			{delay (/	6.96	%coeff) {call "check_direction"}}		
			{delay (/	7.2	%coeff) {call "check_direction"}}			
			{delay (/	7.44	%coeff) {call "check_direction"}}	
			{delay (/	7.68	%coeff) {call "check_direction"}}	
			{delay (/	7.92	%coeff) {call "check_direction"}}		
			{delay (/	8.16	%coeff) {call "check_direction"}}		
			{delay (/	8.4	%coeff) {call "check_direction"}}			
			{delay (/	8.64	%coeff) {call "check_direction"}}	
			{delay (/	8.88	%coeff) {call "check_direction"}}		
			{delay (/	9.12	%coeff) {call "check_direction"}}		
			{delay (/	9.36	%coeff) {call "check_direction"}}		
			{delay (/	9.6	%coeff) {call "check_direction"}}		
		}	
		{on "launch" overload
			{ani_play "center" (* 0.5 %coeff)}
		}	
	)	
	(define "speed_normal"		               		
		{on "chdir_repeater" overload			
			{delay (/	0.213	%coeff) {call "check_direction"}}			{delay (/	0.426	%coeff) {call "check_direction"}}			
			{delay (/	0.639	%coeff) {call "check_direction"}}			{delay (/	0.852	%coeff) {call "check_direction"}}			
			{delay (/	1.065	%coeff) {call "check_direction"}}			{delay (/	1.278	%coeff) {call "check_direction"}}			
			{delay (/	1.491	%coeff) {call "check_direction"}}			{delay (/	1.704	%coeff) {call "check_direction"}}			
			{delay (/	1.917	%coeff) {call "check_direction"}}			{delay (/	2.13	%coeff) {call "check_direction"}}			
			{delay (/	2.343	%coeff) {call "check_direction"}}			{delay (/	2.556	%coeff) {call "check_direction"}}			
			{delay (/	2.769	%coeff) {call "check_direction"}}			{delay (/	2.982	%coeff) {call "check_direction"}}			
			{delay (/	3.195	%coeff) {call "check_direction"}}			{delay (/	3.408	%coeff) {call "check_direction"}}			
			{delay (/	3.621	%coeff) {call "check_direction"}}			{delay (/	3.834	%coeff) {call "check_direction"}}			
			{delay (/	4.047	%coeff) {call "check_direction"}}			{delay (/	4.26	%coeff) {call "check_direction"}}			
			{delay (/	4.473	%coeff) {call "check_direction"}}			{delay (/	4.686	%coeff) {call "check_direction"}}			
			{delay (/	4.899	%coeff) {call "check_direction"}}			{delay (/	5.112	%coeff) {call "check_direction"}}			
			{delay (/	5.325	%coeff) {call "check_direction"}}			{delay (/	5.538	%coeff) {call "check_direction"}}			
			{delay (/	5.751	%coeff) {call "check_direction"}}			{delay (/	5.964	%coeff) {call "check_direction"}}			
			{delay (/	6.177	%coeff) {call "check_direction"}}			{delay (/	6.39	%coeff) {call "check_direction"}}			
			{delay (/	6.603	%coeff) {call "check_direction"}}			{delay (/	6.816	%coeff) {call "check_direction"}}		
			{delay (/	7.029	%coeff) {call "check_direction"}}			{delay (/	7.242	%coeff) {call "check_direction"}}			
			{delay (/	7.455	%coeff) {call "check_direction"}}			{delay (/	7.668	%coeff) {call "check_direction"}}			
			{delay (/	7.881	%coeff) {call "check_direction"}}			{delay (/	8.094	%coeff) {call "check_direction"}}			
			{delay (/	8.307	%coeff) {call "check_direction"}}			{delay (/	8.52	%coeff) {call "check_direction"}}			
		}		
		{on "launch" overload 
			{ani_play "center_fast" (* 0.5625 %coeff)}	
		}	
	)
}				
{"proj_dummy normal"	
	{on spawn	
		{call "turn_off_ik"}		
		{tags add "guided"}			
		{call "check_no_signal"}		
		{volumes "missile" disable contact blast bullet}		   
 		{volumes "target" disable contact blast bullet}		 
 		{volumes disable all}		 
 		{delay 1 			
			{volumes "missile" enable contact}			    
			{volumes "target" enable bullet blast}			    
			{volumes enable all}			    
		}		  
 		{delay 0				
			{call "link_effects"}				
			{impulse forward 2 com}{gravity 0.01}			
			{tags add "stage_01"}
			{ik_enable "stage_hor01" 1}
			{ik_enable "stage_ver01" 1}			               		
			{call "start_guidance_seq"}		  
		}	
	}	
	{on "check_side"
		{if tagged "frends"
			{player 0}
		else
			{player 8}
		}
	}
	(define "try_launch_stage"		      
		tagged "stage_%0"			
		{if not tagged "guided"			       
			{if rand 0.3				
				("turn_to" args %0 left hor)			        
			else rand 0.7				
				("turn_to" args %0 right hor)			        
			}			   
			{if rand 0.3				
				("turn_to" args %0 top ver)			       
			else rand 0.7			
				("turn_to" args %0 bottom ver)			       
			}			
		}		
	)		
	("speed_normal" coeff(0.7))			
	(define "turn_to"		       
		{if not tagged "%2_dir_checked"			
			{ani_play "stage_%2%0_%1" 0.1}		        
		}		
	)			    
	{on "change_direction"		
		{if ("try_launch_stage" args 01)		else ("try_launch_stage" args 02)		else ("try_launch_stage" args 03)	
		else ("try_launch_stage" args 04)		else ("try_launch_stage" args 05)		else ("try_launch_stage" args 06)		
		else ("try_launch_stage" args 07)		else ("try_launch_stage" args 08)		else ("try_launch_stage" args 09)		
		else ("try_launch_stage" args 10)		else ("try_launch_stage" args 11)		else ("try_launch_stage" args 12)	
		else ("try_launch_stage" args 13)		else ("try_launch_stage" args 14)		else ("try_launch_stage" args 15)	
		else ("try_launch_stage" args 16)		else ("try_launch_stage" args 17)		else ("try_launch_stage" args 18)	
		else ("try_launch_stage" args 19)		else ("try_launch_stage" args 20)		else ("try_launch_stage" args 21)		
		else ("try_launch_stage" args 22)		else ("try_launch_stage" args 23)		else ("try_launch_stage" args 24)		
		else ("try_launch_stage" args 25)		else ("try_launch_stage" args 26)		else ("try_launch_stage" args 27)		
		else ("try_launch_stage" args 28)		else ("try_launch_stage" args 29)		else ("try_launch_stage" args 30)		
		else ("try_launch_stage" args 31)		else ("try_launch_stage" args 32)		else ("try_launch_stage" args 33)		
		else ("try_launch_stage" args 34)		else ("try_launch_stage" args 35)		else ("try_launch_stage" args 36)		
		else ("try_launch_stage" args 37)		else ("try_launch_stage" args 38)		else ("try_launch_stage" args 39)		
		else ("try_launch_stage" args 40)		
		}		
		{call "change_stage"}	   
	}
	{on "check_range"
		{if tagged "200m_fly"
			{call "detonate"}			  
		}
	}
}	
{"proj_dummy normal_cluster"	
	{on spawn	
		{call "turn_off_ik"}		
		{tags add "guided"}			
		{call "check_no_signal"}		
		{volumes "missile" disable contact blast bullet}		   
 		{volumes "target" disable contact blast bullet}		 
 		{volumes disable all}		 
 		{delay 1 			
			{volumes "missile" enable contact}			    
			{volumes "target" enable bullet blast}			    
			{volumes enable all}			    
		}		  
 		{delay 0				
			{call "link_effects"}				
			{impulse forward 2 com}{gravity 0.01}			
			{tags add "stage_01"}
			{ik_enable "stage_hor01" 1}
			{ik_enable "stage_ver01" 1}			               		
			{call "start_guidance_seq"}		  
		}	
	}	
	{on "check_side"
		{if tagged "frends"
			{player 0}
		else
			{player 8}
		}
	}
	(define "try_launch_stage"		      
		tagged "stage_%0"			
		{if not tagged "guided"			       
			{if rand 0.3				
				("turn_to" args %0 left hor)			        
			else rand 0.7				
				("turn_to" args %0 right hor)			        
			}			   
			{if rand 0.3				
				("turn_to" args %0 top ver)			       
			else rand 0.7			
				("turn_to" args %0 bottom ver)			       
			}			
		}		
	)		
	("speed_normal" coeff(0.7))			
	(define "turn_to"		       
		{if not tagged "%2_dir_checked"			
			{ani_play "stage_%2%0_%1" 0.1}		        
		}		
	)			    
	{on "change_direction"		
		{if ("try_launch_stage" args 01)		else ("try_launch_stage" args 02)		else ("try_launch_stage" args 03)	
		else ("try_launch_stage" args 04)		else ("try_launch_stage" args 05)		else ("try_launch_stage" args 06)		
		else ("try_launch_stage" args 07)		else ("try_launch_stage" args 08)		else ("try_launch_stage" args 09)		
		else ("try_launch_stage" args 10)		else ("try_launch_stage" args 11)		else ("try_launch_stage" args 12)	
		else ("try_launch_stage" args 13)		else ("try_launch_stage" args 14)		else ("try_launch_stage" args 15)	
		else ("try_launch_stage" args 16)		else ("try_launch_stage" args 17)		else ("try_launch_stage" args 18)	
		else ("try_launch_stage" args 19)		else ("try_launch_stage" args 20)		else ("try_launch_stage" args 21)		
		else ("try_launch_stage" args 22)		else ("try_launch_stage" args 23)		else ("try_launch_stage" args 24)		
		else ("try_launch_stage" args 25)		else ("try_launch_stage" args 26)		else ("try_launch_stage" args 27)		
		else ("try_launch_stage" args 28)		else ("try_launch_stage" args 29)		else ("try_launch_stage" args 30)		
		else ("try_launch_stage" args 31)		else ("try_launch_stage" args 32)		else ("try_launch_stage" args 33)		
		else ("try_launch_stage" args 34)		else ("try_launch_stage" args 35)		else ("try_launch_stage" args 36)		
		else ("try_launch_stage" args 37)		else ("try_launch_stage" args 38)		else ("try_launch_stage" args 39)		
		else ("try_launch_stage" args 40)		
		}		
		{call "change_stage"}	   
	}
	{on "check_range"
		{if tagged "100m_fly"
			{call "detonate"}			  
		}
	}
}	

{"missile_autoguidance_all"		
	{on spawn
		{link_sound "start_small_rpg" "generation_zero/weapon/micro_missile/loop/mach_wpn_micro_missile_trail_loop_01"}
		{add_view "start_xm109_tail" 		"start_xm109" "tail"}
		{add_view "rpg7_tail_fx" 			"fly_pg7v" "tail"}
		{add_view "rpg7_end" 				"end_pg7v" "tail"}
	}
	{on "detonate"		   
		{stuff_detonate}			  
	}		
	{on "underground_detonate"		   
		{if altitude 0			                                    			
			{stuff_detonate}			 
		else   		  			  
			{impulse up 2.0}				
			{delay 0.01 
				{call "underground_detonate"}
			}						
		}		
	}
	{on contact 		
		(define "contact_fx"
			{if material %0 			
				{spawn "%1" }
			}
		)
		("contact_fx" args "concrete" 	stone_hit_br		)
		("contact_fx" args "steel" 		metal_hit_fg_small	)
		("contact_fx" args "wood" 		wood_hit_fg_small	)
		("contact_fx" args "misc" 		ex_air_big2			)
		{call "detonate"}		
	}		
	{on ground_hit			
		{call "detonate"}		
	}		
	{on pierce 		
		{if not stuff "noview"				
			{call "detonate"}		
		}		
	}		
	{on blast			
		{if min_energy 0.3			
			{call "detonate"}			
		}		
	}	
	{on "start_5m_fg"		
		{if not "blocked"
			{play_sound "start_small_rpg" 1}
			{set "blocked" 1}
			{view pause "fly_pg7v"}
			{view pause "end_pg7v"}
			{view start "start_xm109"}
			{view show "start_xm109"}
			{delay 0.1 
				{view start "fly_pg7v"}
				{view show "fly_pg7v"}
				{view stop "start_xm109"}
				{view hide "start_xm109"}
			}
			{delay 0.5
				{view stop "start_xm109"}
				{view hide "start_xm109"}
			}
			{delay 2
				{view stop "fly_pg7v"}
				{view hide "fly_pg7v"}
				{view start "end_pg7v"}
				{view show "end_pg7v"}
			}
		}		
	}	
	{on "start_5m"		
		{if not "blocked"
			{play_sound "start_small_rpg" 1}
			{set "blocked" 1}
			{view pause "fly_pg7v"}
			{view pause "end_pg7v"}
			{view start "start_xm109"}
			{view show "start_xm109"}
			{delay 0.1 
				{view start "fly_pg7v"}
				{view show "fly_pg7v"}
				{view stop "start_xm109"}
				{view hide "start_xm109"}
			}
			{delay 0.15
				{view stop "start_xm109"}
				{view hide "start_xm109"}
			}
			{delay 2
				{view stop "fly_pg7v"}
				{view hide "fly_pg7v"}
				{view start "end_pg7v"}
				{view show "end_pg7v"}
			}
		}		
	}	
}		



; register engine-used props





{"collectable"}
{"nocover"}
{"shoulderbag"}
{"capacity"}
{"obstacle_ignore_height"}
{"trailer"}
{"tractor"}
{"spread_items"}
{"slow_on_crush"}
{"turn_over"}
{"no_plant"}
{"flag_slave"}
{"crater"}

{"vision_cannon_minimum"}
{"vision_cannon_low"}
{"vision_cannon_medium"}
{"vision_cannon_high"}
{"vision_cannon_maximum"}

{"vision_vehicle_minimum"}
{"vision_vehicle_low"}
{"vision_vehicle_medium"}
{"vision_vehicle_high"}
{"vision_vehicle_maximum"}

{"round_sandbag"}
{"round_sandbag2"}
{"round_sandbag3"}
{"sandbag_round"}
{"no_minimap_view"}
{"delete_after_burn"}

{"vision_lev01_air"}

{"vision_lev01_boat"}
{"vision_lev02_boat"}
{"vision_lev03_boat"}
{"vision_lev04_boat"}
{"vision_lev05_boat"}

{"vision_lev00_can"}
{"vision_lev01_can"}
{"vision_lev02_can"}
{"vision_lev03_can"}
{"vision_lev04_can"}
{"vision_lev05_can"}

{"vision_lev01"}
{"vision_lev02"}
{"vision_lev03"}
{"vision_lev04"}
{"vision_lev05"}
{"vision_lev06"}