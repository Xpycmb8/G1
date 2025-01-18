{"animal"
	{on blast
		{health_damage_blast
			{effects "" "" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}
	{on blow opponent sync
		{health_damage_blow
			{effects "hit" "hit" "die" "die" "explosion" "explosion" "explosion"}
		}
		{call "damage"}
	}
	{on bullet_hit
		{call "pierce_damage"}
	}
	{on "pierce_damage"
		{health_damage_pierce
			{effects "" "" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}
	{on contact sync 
		{if effector "vehicle"
			{if effector_velocity 0.1
				{spawn "fx_piece_blood_fx" }	
				{spawn "fx_piece_blood_fx" }	
				{spawn "fx_piece_blood_fx" }	
				{spawn "fx_piece_blood_fx" }	
				{start_sound "hit/small/human/"}
				{health_damage_crush "die" "explosion"}
			}
		else effector "pest_base"
			{if contact_velocity 3
				{burn volume fx "electra_hit" time 5 fake even_law}
				{spawn "fx_piece_blood_fx" }	
				{health_damage_count 25 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "knife_armed"
			{spawn "fx_piece_blood_fx" }	
			{spawn "fx_piece_blood_fx" }	
			{start_sound "hit/small/human/"}
			{health_damage_count 110 {effects "" "hit" "damage" "die" "die"}}
		else effector "knife"
			{if contact_velocity 5
				{health_damage_count 110 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "axe"
			{if contact_velocity 5
				{health_damage_count 180 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "big part"
			{if contact_velocity 3
				{health_damage_count 60 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "fraction"
			{if contact_velocity 3
				{health_damage_count 90 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "medium part"
			{if contact_velocity 6
				{health_damage_count 40 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "small part"
			{if contact_velocity 10
				{health_damage_count 20 {effects "" "hit" "damage" "die" "die"}}
			}
		}
	}
	{on "die"
		{volumes disable contact}
		{die}
		{delay 3
			{volumes enable contact}
			{update_visibility_patch}
		}
	}
	{on "explosion"
		;{delete}
	}
	{on "idle"
		{if name "enter"
			{call "idle_try"}
		else name "exit"
			{ani_stop "passive"}
			{ani_stop "eat"}
			{kill_delay "idle_try"}
			{kill_delay "idle_noanm"}
		}
	}
	{on "idle_try"
		{delay 0.2 0.1 "idle_try"
			{if rand 0.4
				{ani_play "eat" callback}
			else rand 0.4
				{ani_play "passive" callback}
			else
				{delay 5 3 "idle_noanm"
					{call "idle_try"}
				}
			}
		}
	}
	{on animation_end "passive"
		{call "idle_try"}
	}
	{on animation_end "eat"
		{call "idle_try"}
	}
}

{"chicken"
	{on "damage"
		{spawn "pero_hit_small"}
		{start_sound "animal/chicken/cluck"}
	}
	{on "die"
		{call "explosion"}
	}
	{on "explosion"
		{start_sound "animal/chicken/die"}
		{spawn "pero_hit"}
		{spawn "blood_small"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/chicken/cluck"}
		}
	}
	{on ground_hit sync
		{call "feather"}
	}
	{on contact sync
		{if velocity 4
			{call "feather"}
		}
	}
	{on "feather"
		{if not tagged "feather"
			{tags add "feather" }
			{spawn "pero_hit_small"}
			{start_sound "animal/chicken/cluck"}
			{delay 0.2
				{tags remove "feather" }
			}
		}
	}
}

(define "imp"
	{spawn %0 %1
		{impulse	up 1 0.5 dir 8 4
					cx 0 12 cy 0 12
					fx 0 60 fy 0 60 fz 80 40
		}
	}
)

{"dog"
	{on spawn
		{add_view	"drops_water_small3"	"on_water"	"leg1"}
		{add_view	"drops_water_small3"	"on_water"	"leg2"}
		{add_view	"drops_water_small3"	"on_water"	"leg3"}
		{add_view	"drops_water_small3"	"on_water"	"leg4"}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
		{if not dead
			{start_sound "animal/dog/aw"}
		}
	}
	{on "die"
		{start_sound "animal/dog/die"}
		{spawn "blood_small"}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "hand1"	"basis")}
		{if rand 0.7	("imp" args "hand2"	"basis")}
		{if not dead
			{start_sound "animal/dog/die"}
		}
		{spawn "blood"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/dog/aw"}
		}
	}

	(define "terrain_fx_dog"
		{on terrain_fx %0 enter
			{view start "on_%1"}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx_dog" args "shallow_water" 	water)
	("terrain_fx_dog" args "puddle"			water)
}

{"rabbit"
	{on "damage"
		{spawn "bloodsparks_small"}
	}
	{on "die"
		{spawn "rabbit_hit"}
		{spawn "blood_small"}
		{delete}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{spawn "rabbit_hit"}
		{spawn "blood"}
;		{spawn "blood_small"}
		{delete}
	}
}

{"crab"
	{on bullet_hit
		{spawn "blood"}
		{call "pierce_damage"}
		{delete}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
	}
	{on "die"
		{spawn "rabbit_hit"}
		{spawn "blood_small"}
		{delete}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{spawn "rabbit_hit"}
		{spawn "blood"}
;		{spawn "blood_small"}
		{delete}
	}
}

{"cow"
	{on "pierce_damage" overload
		{health_damage_pierce
			{effects "" "" "damage" "die" "explosion"}
		}
	}
	{on "damage"
		{spawn "bloodsparks_small"}
		{if not dead
			{start_sound "animal/cow/moo"}
		}
	}
	{on "die"
		{start_sound "animal/cow/moo"}
		{spawn "blood_small"}
	}
	{on "explosion"
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "head"	"basis")}
		{if rand 0.7	("imp" args "hand1"	"basis")}
		{if rand 0.7	("imp" args "hand2"	"basis")}
		{if not dead
			{start_sound "animal/cow/moo"}
		}
		{spawn "blood"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/cow/moo"}
		}
	}
}

{"donkey"
	(define "terrain_fx_water"
		{on terrain_fx %0 enter
			{tags add "water_enter"}
		}
		{on terrain_fx %0 leave
			{tags remove "water_enter"}
		}
	)
	("terrain_fx_water" args "water"			water)
	("terrain_fx_water" args "puddle"			puddle)
	("terrain_fx_water" args "shallow_water"	puddle)
	("terrain_fx_water" args "mud"				mud)
	{on movement_mode_changed
		(define "terrain_fx_check"
			{if terrain_fx %0 
				{tags add %0}
			else
				{tags remove %0}
			}
		)
		("terrain_fx_check" args "shoot_emit_ext_sand" )
		("terrain_fx_check" args "shoot_emit_int_wood" )
		("terrain_fx_check" args "shoot_emit_ext" )
		("terrain_fx_check" args "shoot_emit_int" )
		("terrain_fx_check" args "shoot_emit_mtl" )
		("terrain_fx_check" args "shoot_emit_mtl_int" )
		("terrain_fx_check" args "floor" )
		("terrain_fx_check" args "volume" )
		("terrain_fx_check" args "snow" )
		("terrain_fx_check" args "land" )
		("terrain_fx_check" args "metal" )
		("terrain_fx_check" args "ground" )
		("terrain_fx_check" args "bridge" )
		("terrain_fx_check" args "bridge_wood" )
		("terrain_fx_check" args "road" )
		("terrain_fx_check" args "country_road" )
		("terrain_fx_check" args "rock" )
		("terrain_fx_check" args "sand" )
		("terrain_fx_check" args "grass" )
		("terrain_fx_check" args "water" )
		("terrain_fx_check" args "shallow_water" )
	}
	(define "foot"	
		{on animation_event %0
			{call "step"}
			{if tagged "water"
				{spawn "drops_puddle_animal" %0}
			else tagged "shallow_water"
				{spawn "drops_puddle_animal" %0}
			else
				{if rand 0.5
					{spawn "human_steps_dust" %0}
				}
			}
		}
	)
	("foot" args "donkey_r_toe_front_bone")
	("foot" args "donkey_l_toe_front_bone")
	("foot" args "donkey_r_toe_back_bone")
	("foot" args "donkey_l_toe_back_bone")
	{on "step"	
		(define "terrain_fx_animal"
			{if tagged %0 
				{start_sound "animal/donkey/walk/%1/"}	
			}
		)
		("terrain_fx_animal" args "ground" 						ground 		 	)
		("terrain_fx_animal" args "grass" 							ground 		 	)
		("terrain_fx_animal" args "road" 							stone 	 		)
		("terrain_fx_animal" args "country_road" 					stone 		 	)
		("terrain_fx_animal" args "sand" 							ground 		 	)
		("terrain_fx_animal" args "snow"  							ground 		 	)
		("terrain_fx_animal" args "water" 							water 		 	)
		("terrain_fx_animal" args "shallow_water" 					water 		 	)
		("terrain_fx_animal" args "bridge" 						wood 		   	)
		("terrain_fx_animal" args "bridge_wood" 					wood	   		)
		("terrain_fx_animal" args "floor" 							stone 		   	)
		("terrain_fx_animal" args "rock" 							stone 		   	)
		("terrain_fx_animal" args "metal" 							ground 		   	)
		("terrain_fx_animal" args "shoot_emit_mtl" 				ground 		 	)
		("terrain_fx_animal" args "shoot_emit_mtl_int" 			ground 		 	)
		("terrain_fx_animal" args "shoot_emit_ext_sand" 			ground 		 	)
		("terrain_fx_animal" args "shoot_emit_ext" 				ground 		 	)
		("terrain_fx_animal" args "shoot_emit_int" 				ground 		 	)	
	}
}




{"tuskano"
	{on spawn
		{volumes "touch" disable contact touch select}
		{volumes "touch_human" disable contact touch select}
		{link_sound "scared"		"" 	}
		{link_sound "idle"			"" 	}
	}
	{on move on
		{tags add "walk"}
		{if tagged "pierce_full"
			{movement_limit slow}
			{ani_play "stand_walk_fwd_1" loop}
		else tagged "pierce"
			{movement_limit normal}
			{ani_play "stand_walk_fwd_dmg_0" loop}
		else 
			{ani_play "walk" loop }	
		}
		
	}
	{on turn on
		{ani_play "stand_turn_left_0" loop}
		{tags add "turn"}
	}
	{on turn off
		{ani_stop "stand_turn_left_0" }
		{tags remove "turn"}
	}
	{on move off
		{ani_stop "stand_walk_fwd_1" }
		{delay 0.5 {tags remove "walk"}}
		{ani_stop "walk" }
		{ani_stop "stand_walk_fwd_dmg_0" }
	}
	{on "idle"
		{set "idle" 1}
		{if not "blocked"
			{if rand 0.5
				{ani_play "passive" 0.5 callback}
			 else
				{ani_play "passive2" 0.5 callback}
			}
		}
	}
	{on "safe-idle"
		{if "idle"
			{call "idle"}
		}
	}
	{on "start-idle"
		{set "idle" 1}
		{delay_effect 1 "safe-idle"}
	}
	{on animation_end "idle1"
		{delay_effect 7 1.5 "safe-idle"}
	}
	{on animation_end "idle2"
		{delay_effect 7 1.5 "safe-idle"}
	}
	{on animation_end "idle3"
		{delay_effect 7 1.5 "safe-idle"}
	}
	{on animation_end "idle4"
		{delay_effect 7 1.5 "safe-idle"}
	}
	{on "stop_idle"
		{set "idle" 0}
		{ani_stop "idle1"}
		{ani_stop "idle2"}
		{ani_stop "idle3"}
		{ani_stop "idle4"}
	}

	{on blast
		{health_damage_blast
			{effects "" "" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}
	{on blow opponent sync
		{health_damage_blow
			{effects "hit" "hit" "die" "die" "explosion" "explosion" "explosion"}
		}
		{call "damage"}
	}
	{on bullet_hit
		{call "pierce_damage"}
		{kill_flags reset}
		{signal hit 15} ; generate hit signal
		{if stuff "bullet"
			{if rand 0.3
				{tags add "pierce_full"}
			else rand 0.5
				{tags add "pierce"}
			}
			{if volume "head" 
				{ani_play "hit_head" 1}
				;{if tagged "hit_bullet_head"	
				{if not tagged "scared"	
					;{ani_play "" }
					{if not tagged "walk"	
						;{ani_play "" }
						{if not tagged "pierce_full"	
							{if not tagged "hit_bullet_head"	
								{tags add "hit_bullet_head"}
								{ani_play "hit_head" 1}
							}
						}
					}
				}
				{delay 1.3 "hit_bullet_head"
					{tags remove "hit_bullet_head"}
				}
			else volume "body_up" 
				{if not tagged "scared"	
					{if not tagged "walk"	
						{if not tagged "pierce_full"	
							{if not tagged "hit_bullet"	
								{tags add "hit_bullet"}
								{ani_play "hit" 0.8}
							}
						}
					}
				}
				{delay 1.3 "hit_bullet"
					{tags remove "hit_bullet"}
				}
			else volume "body_down" 
				{if not tagged "scared"	
					{if not tagged "walk"	
						{if not tagged "pierce_full"	
							{if not tagged "hit_bullet"	
								{tags add "hit_bullet"}
								{ani_play "hit" 0.8}
							}
						}
					}
				}
				{delay 1.3 "hit_bullet"
					{tags remove "hit_bullet"}
				}
			else volume "tail" 
			else volume "foot_r1" 
				{if not tagged "scared"	
					{if not tagged "walk"	
						{if not tagged "pierce_full"	
							{if not tagged "hit_bullet"	
								{tags add "hit_bullet"}
								{ani_play "hit" 0.8}
							}
						}
					}
				}
				{delay 1.3 "hit_bullet"
					{tags remove "hit_bullet"}
				}
				{movement_limit slow}
			else volume "foot_r2" 
				{if not tagged "scared"	
					{if not tagged "walk"	
						{if not tagged "pierce_full"	
							{if not tagged "hit_bullet"	
								{tags add "hit_bullet"}
								{ani_play "hit" 0.8}
							}
						}
					}
				}
				{delay 1.3 "hit_bullet"
					{tags remove "hit_bullet"}
				}
				{movement_limit slow}
			else volume "foot_r3" 
				{if not tagged "scared"	
					{if not tagged "walk"	
						{if not tagged "pierce_full"	
							{if not tagged "hit_bullet"	
								{tags add "hit_bullet"}
								{ani_play "hit" 0.8}
							}
						}
					}
				}
				{delay 1.3 "hit_bullet"
					{tags remove "hit_bullet"}
				}
				{movement_limit slow}
			else volume "foot_l1" 
				{if not tagged "scared"	
					{if not tagged "walk"	
						{if not tagged "pierce_full"	
							{if not tagged "hit_bullet"	
								{tags add "hit_bullet"}
								{ani_play "hit" 0.8}
							}
						}
					}
				}
				{delay 1.3 "hit_bullet"
					{tags remove "hit_bullet"}
				}
				{movement_limit slow}
			else volume "foot_l2" 
				{if not tagged "scared"	
					{if not tagged "walk"	
						{if not tagged "pierce_full"	
							{if not tagged "hit_bullet"	
								{tags add "hit_bullet"}
								{ani_play "hit" 0.8}
							}
						}
					}
				}
				{delay 1.3 "hit_bullet"
					{tags remove "hit_bullet"}
				}
				{movement_limit slow}
			else volume "foot_l3" 
				{if not tagged "scared"	
					{if not tagged "walk"	
						{if not tagged "pierce_full"	
							{if not tagged "hit_bullet"	
								{tags add "hit_bullet"}
								{ani_play "hit" 0.8}
							}
						}
					}
				}
				{delay 1.3 "hit_bullet"
					{tags remove "hit_bullet"}
				}
				{movement_limit slow}
			}
		}
		{delay 1.3 "hit_bullet"
			{tags remove "hit_bullet"}
		}
	}
	{on "pierce_damage"
		;{chassis_work 0}
		{play_sound "scared"}
		{delay 1
			;{chassis_work 1}
		}
		{health_damage_pierce
			{effects "hit" "hit" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}
	{on overlap begin
		;{if not tagged "walk"
			{if not tagged "scared"
				{if rand 0.7
					{if effector "human"
						{chassis_work 0}
						{volumes "touch" disable contact touch select}
						{tags add "scared"}
						{play_sound "scared"}
						{ani_play "stand_scared_start" 0.9}
						{delay 1
							{ani_play "stand_scared_loop" loop}
						}
						{ani_stop "idle1"}
						{ani_stop "idle2"}
						{ani_stop "idle3"}
						{kill_delay "idle_try"}
						{kill_delay "idle_noanm"}			
						{delay 5 "vol"
							{volumes "touch" enable contact touch select}
							{delay 6
								{tags remove "all"}
								{ani_stop "stand_scared_loop" }	
								{ani_play "stand_scared_end" 0.5}
								{delay 1.7
									{if rand 0.4					
										{play_sound "scared"}
										{ani_play "idle1" 1}
									else rand 0.4
										{ani_play "idle2" 1}
									else rand 0.4
										{ani_play "idle3" 1}
									else
										{ani_play "idle4" 1}
									}
								}
								{delay 9 "scared"
									{chassis_work 1}
									{tags remove "scared"}			
								}
							}	
						}	
					}
				else effector "trace"
					{tags add "human"}
					{play_sound "scared"}
					{ani_play "stand_scared_start" 1}
					{delay 1
						{ani_play "stand_scared_loop" loop}
					}
					{ani_stop "idle1"}
					{ani_stop "idle2"}
					{ani_stop "idle3"}
					{ani_stop "idle4"}
					{kill_delay "idle_try"}
					{kill_delay "idle_noanm"}
				}		
			}		
		;}		
	}
;	{on overlap end
;		{if effector "human"
;			{tags remove "human"}
;			{ani_stop "stand_scared_loop" }	
;			{ani_play "stand_scared_end" 1}
;			{ani_stop "idle1"}
;			{ani_stop "idle2"}
;			{ani_stop "idle3"}
;			{kill_delay "idle_try"}
;			{kill_delay "idle_noanm"}	
;		else		
;			{delay 3
;				{tags remove "all"}
;				{ani_stop "stand_scared_loop" }	
;				{ani_play "stand_scared_end" 1}
;			}	
;		}	
;	}
	{on animation_end "hit"
		{ani_play "idle1"}
	}

	{on contact sync 
		{if not tagged "scared"
			{if rand 0.7
				{if effector "human"
					{chassis_work 0}
					{volumes "touch" disable contact touch select}
					{tags add "scared"}
					{play_sound "scared"}
					{ani_play "stand_scared_start" 0.9}
					{delay 1
						{ani_play "stand_scared_loop" loop}
					}
					{ani_stop "idle1"}
					{ani_stop "idle2"}
					{ani_stop "idle3"}
					{kill_delay "idle_try"}
					{kill_delay "idle_noanm"}			
					{delay 5 "vol"
						{volumes "touch" enable contact touch select}
						{delay 6
							{tags remove "all"}
							{ani_stop "stand_scared_loop" }	
							{ani_play "stand_scared_end" 0.5}
							{delay 1.7
								{if rand 0.4					
									{play_sound "scared"}
									{ani_play "idle1" 1}
								else rand 0.4
									{ani_play "idle2" 1}
								else rand 0.4
									{ani_play "idle3" 1}
								else
									{ani_play "idle4" 1}
								}
							}
							{delay 9 "scared"
								{chassis_work 1}
								{tags remove "scared"}			
							}
						}	
					}	
				}
			}
		}
		{if effector "tuskano"
			{if not tagged "attack"
				{if rand 0.7
					{with_effector
						{health_damage_crush "die" "explosion"}
					}
					{chassis_work 0}
					{volumes "touch" disable contact touch select}
					{tags add "attack"}
					{play_sound "scared"}
					{ani_play "stand_atack_1" 0.9}
					{ani_stop "idle1"}
					{ani_stop "idle2"}
					{ani_stop "idle3"}
					{kill_delay "idle_try"}
					{kill_delay "idle_noanm"}			
					{delay 2 "vol"
						{volumes "touch" enable contact touch select}
						{chassis_work 1}
						{tags remove "scared"}			
					}
				}
			}
		}
		{if effector "vehicle"
			{if effector_velocity 0.1
				{health_damage_crush "die" "explosion"}
			}
		else effector "knife"
			{if contact_velocity 5
				{health_damage_count 110 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "axe"
			{if contact_velocity 5
				{health_damage_count 180 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "big part"
			{if contact_velocity 3
				{health_damage_count 60 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "fraction"
			{if contact_velocity 3
				{health_damage_count 90 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "medium part"
			{if contact_velocity 6
				{health_damage_count 40 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "small part"
			{if contact_velocity 10
				{health_damage_count 20 {effects "" "hit" "damage" "die" "die"}}
			}
		}
	}
	{on "die"
		{volumes disable contact}
;		{ani_play "die" callback}
		{die}
		{delay 3
			{volumes enable contact}
			{update_visibility_patch}
		}
	}
	{on "explosion"
		;{delete}
	}
	
	(define "play_move_sound"
		{if terrain_fx "road"
			{start_sound "human/move/%0/road_%1"}
		else terrain_fx "country_road"
			{start_sound "human/move/%0/road_%1"}
		else terrain_fx "ice"
			{start_sound "human/move/%0/snow_%1"}
		else terrain_fx "snow"
			{start_sound "human/move/%0/snow_%1"}
		else terrain_fx "sand"
			{start_sound "human/move/%0/sand_%1"}
		else terrain_fx "grass"
			{start_sound "human/move/%0/grass_%1"}
		else
			{start_sound "human/move/%0/ground_%1"}
		}
	)

	{on "stop_move_sounds"
		{stop_sound "swim"}
		{tags remove "fast_move_mode"}
		;{set "fast_move_mode" 0}
		{tags remove "fast"}
		{tags remove "normal"}
		{tags remove "walk"}
		{tags remove "slow"}
	}
	{on movement_mode_changed
		{call "stop_move_sounds"}
		{if name "fast"
			{if swimming
				{play_sound "swim" 1}
			else not lying
				("play_move_sound" args fast start)
				{tags add "fast"}
				{tags add "fast_move_mode"}
			}
		else name "normal"
			{tags add "normal"}		
		else name "normal"
			{tags add "normal"}		
		else name "slow"
			{tags add "slow"}		
		}
	}
	
;	{on animation_end ""
;		{call ""}
;	}
}








{"animal_demorale"}