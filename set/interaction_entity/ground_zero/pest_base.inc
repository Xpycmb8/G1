{"pest_base"
	{inflammation_time 5}
	{on spawn
		{add_view	"micro_combat_shock"			"combat"		"combat_link"}
		{view hide	"combat"}
		{view stop	"combat"}
		{add_view 	"smoke_gas_tail" 				"move_pest_class_d" "tail4"}
		{add_view 	"smoke_gas_tail_close" 			"close_combat_class_d" "tail4"}		
		{add_view 	"burn_element_cpu" 				"explosion_fx" "body"}
		{delay 1
			{if tagged "frends"
				{player 0}
			else tagged "rus"
				{player 9}
			else
				{player 8}
			}
		}
		{if not tagged "spawned"		
			{ani_play "power_up"  }	
			{start_sound "generation_zero/characters/pest/spawn/"}	
		}
		{tags add "hold"}
		{tags add "machine"}
		{tags add "pest_base"}
		{call "link_sound"}			
		{set "engine_started" 0}
		{set "stop" 1}
		{delay 15 5 "idle_enter"
			{tags add "idle_enter"}
			{call "idle-enter"}
		}		
	}
	{on "led_light_connect"
		(define "leds_ems_global"
			{add_view 	"yellow_ems_small" 	"ems_global_search" 	"%vis_search"}
			{add_view 	"red_ems_small" 	"ems_global_alarm" 		"%vis_alarm"}
			{add_view 	"hold_ems_small" 	"ems_global_hold" 		"%vis_hold"}
			{view show	"ems_global_hold"}
			{view start	"ems_global_hold"}
			{view hide	"ems_global_alarm"}
			{view pause	"ems_global_alarm"}
			{view hide	"ems_global_search"}
			{view pause	"ems_global_search"}
			{bone show	"light_ems"}
		)
		("leds_ems_global"  vis(visor_body_bone) )
		
	}
	{on "selfdestruct"
		{if not tagged "selfdestruct"
			{tags add "selfdestruct"}
			{delay 360
				{start_sound "generation_zero/characters/pest/selfdestruct/"}	
				{delay 1
					{spawn "electric_spark_hit" "sparks_link"}			
				}		
				{delay 2
					{call "_explosion_pest"}			
				}		
			}
		}	
	}	
	{on "upside_down"
		{if work "body"
			{delay 0.5
				{spawn "spheredust_small"}			
				{pillar_up}
			}
			
		}
	}
	{on "power_up" ; all
		{if not able "exploded"
			{view show	"ems_global"}
			{view start	"ems_global"}		
			{view show	"ems"}
			{view start	"ems"}		
			{tags add "hold"}
			{call "leds_update"}
		}
	}
	{on "power_drop_permanent"
		{if not able "exploded"
			{delay 0.2 
				{if not tagged "power_drop"
					{delay 1.5 
						{burn volume "visor_ems" fx "yellow_burn" time 0.1 fake}
						{drop_orders}
						{reset_manual_control}
						{auto_operatable 0}
						{able select minimap 0}
						{able repaired 0}
					}
					{view hide	"ems_global"}
					{view pause	"ems_global"}
					{call "stop_idle"}
					{tags add "power_drop_permanent"}
					{tags add "power_drop"}
					{tags add "off"}
					{tags remove "hold"}
					{tags remove "alarm"}
					{tags remove "search"}
					{call "leds_update"}
					{call "sparks_loop"}
					{burn volume "cpu" fx "smoke_preheat" time 5 fake even_law}	
					{ani_play "power_down"}
					{call "gun_block"}
				}
			}
		}
	}

	{on pierce ; pest
		{call "stop_idle"}
		{if volume "main_body"
			{if work "main_body"
				{if rand 0.5
					{call "_explosion_pest"}
				}
			else
				{call "_explosion_pest"}
			}
		}		
		(define "mesh_break"
			(define "stuff_pierce"
				{if volume "%component"
					{if stuff "%stuff"
						{if work "%component"
							{components "%component" break}
						else rand %stuff_destroy
							{components "%component" destroy}
						}
					}
				}
			)		
			("stuff_pierce" stuff(shell) 				stuff_break(1)		)
			("stuff_pierce" stuff(rocketlauncher) 		stuff_break(1)		)
			("stuff_pierce" stuff(zenite) 				stuff_break(1)		)
			("stuff_pierce" stuff(bullet big) 			stuff_break(1)		)
			("stuff_pierce" stuff(bullet normal ap) 	stuff_break(1)		)
			("stuff_pierce" stuff(bullet normal) 		stuff_break(0.9)	)
			("stuff_pierce" stuff(bullet small) 		stuff_break(0.8)	)
		)		
		;all armor
		("mesh_break" component(front_armor)  			 			stuff_destroy(0.5))
;------------------
		;all leg
		("mesh_break" component(RightToeBase)  	 						stuff_destroy(0.7))
		("mesh_break" component(RightFoot)  			 				stuff_destroy(0.7))
		("mesh_break" component(RightLeg)  			 					stuff_destroy(0.7))
		("mesh_break" component(RightUpLeg)  		 					stuff_destroy(0.7))
		("mesh_break" component(RightShoulder)  			 			stuff_destroy(0.7))
		("mesh_break" component(RightForeArm)  		 					stuff_destroy(0.7))
		("mesh_break" component(RightHand)  			 				stuff_destroy(0.7))
		("mesh_break" component(LeftToeBase)  		 					stuff_destroy(0.7))
		("mesh_break" component(LeftFoot)  		 						stuff_destroy(0.7))
		("mesh_break" component(LeftLeg)  		 						stuff_destroy(0.7))
		("mesh_break" component(LeftUpLeg)  	 						stuff_destroy(0.7))
		("mesh_break" component(LeftShoulder)  		 					stuff_destroy(0.7))
		("mesh_break" component(LeftForeArm)   							stuff_destroy(0.7))
		("mesh_break" component(LeftHand)  	 							stuff_destroy(0.7))
	}
	{on blast ; pest
		{if stuff "orientation_melee_front"
			{call "jump_front"}
		}
		{if volume "main_body"
			{if min_energy 3
				{call "_explosion_pest"}
			else min_energy 1
				{if rand 0.3
					{call "_explosion_pest"}
				}
			}
		}		
	}
	(include "burn_volume.inc")
	{on "_explosion_pest" 
		{if not able "exploded"			
			{set "exploded" 1}
			{able "exploded" 1}
			{able select 0}
			{able repaired 0}
			{auto_operatable 0}
			{view pause "move_pest_class_d"}
			{view pause "close_combat_class_d"}
			{bone hide "ems"}
			{start_sound "generation_zero/characters/pest/explode/"}			
			{stop_sound "engine" }
			{tags add "dead"}
			{ani_stop "idle_loop"}
			{clear_inventory}
			{spawn "burn_flare" "body"}
			{spawn "ex_air_smoke" "body"}
			{burn volume "main_body" fx "burn_element_cpu" time 4 fake}
			{mtl_enable_skin 0}
			{components "main_body" destroy}
			{if tagged "move"
				{impulse forward 1 cx 2 1 cy 2 1 no_position}		
			else
				{impulse up 0.5 cx 3 2 cy 3 2 rnd_dir 2 no_position}		
			}
			(define "cut_part"
				{if rand 0.4
					{tear "piece_small_steel_forward" bone %0
						{impulse up 0.5 dir 1 0.5 cx 1 0.5 cy 1 0.5 rnd_dir 1 0.5 no_position}
					}
				}
			)
			("cut_part" args "RightUpLeg_bone")
			("cut_part" args "RightLeg_bone")
			("cut_part" args "RightFoot_bone")
			("cut_part" args "RightShoulder_bone")
			("cut_part" args "RightArm_bone")
			("cut_part" args "RightForeArm_bone")
			("cut_part" args "leftUpLeg_bone")
			("cut_part" args "leftLeg_bone")
			("cut_part" args "leftFoot_bone")
			("cut_part" args "leftShoulder_bone")
			("cut_part" args "leftArm_bone")
			("cut_part" args "leftForeArm_bone")
			("cut_part" args "front_armor")
			("cut_part" args "tail_back")
			{with_linked_entity "link_bomb"
				{stuff_detonate}
			}				
			{delay_ex 0.1
				{set_skeleton "_x"}
				{impulse up 0.1 }		
			}
			;{delay 10 {view hide "explosion_fx"}}
		}
	}
	{on "power_drop" 
		{if not able "exploded"
			{if not tagged "power_drop"
				{call "stop_idle"}
				{tags add "power_drop"}
				{tags add "off"}
				{burn volume "main_body" fx "smoke_preheat" time 2 fake even_law}	
				{ani_play "power_down"}
				{call "gun_block"}
				{delay 4 2 "power_drop"
					{if not able "exploded"
						{tags remove "power_drop"}
						{ani_play "power_up"}
					}
				}
			}
		}	
	}
	{on "electric_spark_small"
		{tags add "electric_spark_loop"}
		{call "electric_spark_small_loop"}
		{delay 20 "electric_spark_loop"
			{tags remove "electric_spark_loop"}
		}
	}
	{on "electric_spark_small_loop" 
		{if tagged "electric_spark_loop"
			{start_sound "generation_zero/electric_spark"}			
		else
			{kill_delay "electric_spark_small_loop"}		
		}
		{delay_effect 0.4 "electric_spark_small_loop"}		
	}
	{on "sparks_loop" 
		{if tagged "wire_burn"
			{delay 0.5
				{if rand 0.3
					{start_sound "generation_zero/electric_spark/"}	
					{burn volume "head_organ" fx "electric_spark_hit" time 0.1 fake}		
				}
			}
			{delay 1
				{if rand 0.5
					{start_sound "generation_zero/electric_spark/"}	
					{burn volume "body_organ" fx "electric_spark_hit" time 0.1 fake}		
				}
			}
			{burn volume "back_engine_organ" fx "electric_spark_hit" time 0.1 fake}		
		else
			{kill_delay "sparks_loop"}		
		}
		{delay_effect 3 0.5 "sparks_loop"}		
	}
	{on "sparks_loop_cpu" 
		{if tagged "broken_cpu"
			{if not able "exploded"
				{if rand 0.05
					{call "power_drop"}
				}
				{if rand 0.3
					{start_sound "generation_zero/electric_spark/"}	
					{burn volume "cpu" fx "electric_spark_hit" time 0.1 fake}		
				}
			}
		else
			{kill_delay "sparks_loop_cpu"}		
		}
		{delay_effect 3 0.5 "sparks_loop_cpu"}		
	}
	(define "terrain_fx"
		{on terrain_fx %0 enter
			{tags add %1}
		}
		{on terrain_fx %0 leave
			{if "blocked"			
				{tags remove %1}
			}
		}
	)
	("terrain_fx" args "shoot_emit_ext_sand" 		"ground" )
	("terrain_fx" args "shoot_emit_int_wood" 		"wood")
	("terrain_fx" args "shoot_emit_ext" 			"ground")
	("terrain_fx" args "shoot_emit_int" 			"wood" )
	("terrain_fx" args "shoot_emit_mtl"  			"metal" )
	("terrain_fx" args "shoot_emit_mtl_int"  		"metal" )
	("terrain_fx" args "floor"   					"wood")
	("terrain_fx" args "volume"  					"ground")
	("terrain_fx" args "snow"  						"ground")
	("terrain_fx" args "land"  						"ground")
	("terrain_fx" args "metal" 						"metal" )
	("terrain_fx" args "ground"  					"ground")
	("terrain_fx" args "bridge"   					"ground")
	("terrain_fx" args "bridge_wood" 				"wood" )
	("terrain_fx" args "road"  						"gravel")
	("terrain_fx" args "country_road"  				"ground" )
	("terrain_fx" args "rock"  						"ground" )
	("terrain_fx" args "sand"  						"ground" )
	("terrain_fx" args "grass"  					"grass")
	
	(define "speed"
		{on animation_event "%tagged_speed"
			{if tagged "%tagged_speed"	
				{ani_stop "speed_full" }
			}
		}
	)
	;                      
	("speed" tagged_speed(0_speed) )
	("speed" tagged_speed(1_speed) )
	("speed" tagged_speed(2_speed) )
	("speed" tagged_speed(3_speed) )
	("speed" tagged_speed(4_speed) )
	("speed" tagged_speed(5_speed) )
	("speed" tagged_speed(6_speed) )
	("speed" tagged_speed(7_speed) )
	("speed" tagged_speed(8_speed) )
	("speed" tagged_speed(9_speed) )
	{on move on ; pest
		{call "selfdestruct"}
		{ani_stop "idle_loop"}
		{tags add "move"}	
		{set "blocked" 1}
		{if not tagged "turn"
			{if Move_Forward
				{view start "move_pest_class_d"}
				{view show "move_pest_class_d"}
				{tags add "move_forward"}
				{ani_play "runstart_f"  }				
				{ani_stop "runstart_b" }	
;			else Move_Backward
;				{tags add "move_backward"}	
;				{ani_play "runstart_b" -0.5 }	
;				{ani_stop "runstart_f" }	
			}
		}
		; {if broken "" 
		; }
		; {play_sound "" }
		; {tags add ""}
		; {if velocity 30
			; {play_sound "" }
		; else velocity 0
			; {play_sound "" }
		; }	
	}
	{on move off ; all
		{call "stop_idle"}
		{delay 0.5
			{if not tagged "move"
				{if not tagged "turn"
					{call "stop_all_ani"}
				}
			}
		}
		{tags remove "move_forward"}	
		{tags remove "move"}	
		{tags remove "turn"}
		{tags remove "run"}
		{tags remove "walk"}
		{set "blocked" 0}
		{delay 0.5
			{view pause "move_pest_class_d"}
		}
	}
	{on "move_update_f" 
		(define "move_update"
			{if velocity %speed				
				{ani_play "runloop_fwd" (* %speed 0.5) }
				;{tags add "%speed"}	;check sum
				;{tags add "%ani"}	;check sum
			}
		)		
		("move_update" speed(8)		)
		("move_update" speed(7) 	)
		("move_update" speed(6) 	)
		("move_update" speed(5) 	)
		("move_update" speed(4) 	)
		("move_update" speed(3) 	)
		("move_update" speed(2)  	)
		("move_update" speed(1)  	)
	}	
	{on "move_update_b" 
		(define "move_update"
			{if velocity %speed				
				{ani_play "runloop_brd" (* %reverse 0.1) }
				;{tags add "%reverse"}	;check sum
				;{tags add "%ani"}	;check sum
			}
		)		
		("move_update" speed(1) 	ani(0.03) reverse(-1))
		("move_update" speed(2) 	ani(0.04) reverse(-2))
		("move_update" speed(3) 	ani(0.06) reverse(-3))
		("move_update" speed(4) 	ani(0.08) reverse(-4))
		("move_update" speed(5) 	ani(0.09) reverse(-5))
		("move_update" speed(6) 	ani(0.1)  reverse(-6))
		("move_update" speed(7) 	ani(0.11) reverse(-7))
		("move_update" speed(8) 	ani(0.12) reverse(-8))
	}	
	{on turn on ; all
		{set "blocked" 1}
		{kill_delay "move_stop"}
		{call "stop_idle"}
		{tags add "turn"}
		{ani_stop "idle_loop"}
		{if turn_left
			{tags add "turn_left"}	
			{call "update_turn_left"}
		else turn_right
			{tags add "turn_right"}	
			{call "update_turn_right"}
		}
	}
	{on "update_turn_right"
		{if tagged "long_turn"
			{tags add "step_r_090"}	
			{ani_play "step_r_090" 1 resume loop}	
		else
			{tags add "step_r_045"}	
			{ani_play "step_r_045" 0.4 resume loop}	
		}
	}
	{on "update_turn_left"
		{if tagged "long_turn"
			{tags add "step_l_090"}	
			{ani_play "step_l_090" 1 resume loop}	
		else
			{tags add "step_l_045"}	
			{ani_play "step_l_045" 0.4 resume loop}	
		}
	}
	{on turn off ; add remove tags left right
		{delay 0.5 "move_stop"
			{call "weapon_on"}
		}
		{tags remove "turn"}		
		{tags remove "long_turn"}
		{tags remove "turn_left"}
		{tags remove "turn_right"}
		{kill_delay "long_turn"}
		{kill_delay "update_turn_left"}
		{kill_delay "update_turn_right"}
		(define "turn_off"	
			{if tagged "%turn_off"
				{ani_stop "%turn_off" }
				{tags remove "%turn_off"}	
			}
		)
		("turn_off" turn_off(step_r_090)  )	
		("turn_off" turn_off(step_r_045)  )	
		("turn_off" turn_off(step_l_090)  )	
		("turn_off" turn_off(step_l_045)  )	
	}
	{on accelerate on
		{tags add "accelerate_on"}
	}
	{on accelerate off
		{tags remove "accelerate_on"}
	}
	{on engine on
	}
	{on engine off
	}
	{on "stop_all_ani"
		{ani_stop "runloop_fwd"}
		{ani_stop "runstart_f"}
		{ani_stop "step_r_090"}
		{ani_stop "step_r_045"}
		{ani_stop "step_l_090"}
		{ani_stop "step_l_045"}
		{ani_stop "runstop_f"}
	}
	{on "drop_speed"
		{movement_limit slow}
		{delay 0.2 
			{if not able "exploded"
				{movement_limit fast}
			}
		}
	}
	
	; {on "jump_front"
		; {impulse up 0.1 }				
		; {tags remove "move"}
		; {tags remove "move_forward"}
; ;		{call "drop_speed"}
		; {call "stop_all_ani"}
		; {call "stop_idle"}
		; {tags remove "idle_enter"}		
		; {ani_play "attack_melee_jump_close" 1 }
	; }
	
	{on fire "mgun" ;pest
		;{call "drop_speed"}
		{impulse up 0.1 }				
		{tags remove "move"}
		{tags remove "move_forward"}
		{call "stop_all_ani"}
		{call "stop_idle"}
		;{chassis_work 0}
		{tags remove "idle_enter"}		
		{ani_play "attack_melee_jump_close" 1 }
	}
	{on "leave_unit"
		{tags add "leave"}
		{delay 3 1
			{call "_explosion_pest"}
		}
	}
	{on ground_hit overload
		{if able "exploded"
			{if velocity 2
				{if volume "limbs_micro"		
					{spawn "spheredust_big_hit_steel"}
					{tear "piece_small_steel" bone from_volume
						{impulse dir 2 1 	cx 0.4 	cy 0.4 no_position}	
					}
				}
			}
		}				
		{if tagged "blast_hit"
			{if velocity 10
				{if rand 0.5				
					{if volume "limbs_micro"
						{chassis_work 0}
						{spawn "spheredust_big_hit_steel"}
						{tear "piece_small_steel" bone from_volume
							{impulse dir 7 1 	cx 2 1 	cy 2 1 no_position}	
						}				
					}				
				}
			}
		}
		{if min_speed 20			
			{start_sound "hit/generic/metal_weight/15"}
			{spawn "dust_jump"}
		else min_speed 8			
			{start_sound "hit/generic/metal_weight/5"}
			{spawn "dust_jump"}
		}
	}
	{on animation_event "runstart_f"
		{if tagged "move"
			{call "move_update_f"}
		else
			{ani_play "runstop_f" 1}
		}
	}	
	{on animation_event "runstart_b"
		{if tagged "move"
			{call "move_update_b"}
		else
			{ani_play "runstop_b" 1}
		}
	}	
	{on animation_event "runloop_f_small"
		{if velocity 4	
			{call "move_update_f"}
		else velocity 0
			{ani_play "runstop_f" }
		}
	}
	{on animation_event "power_down_start" ;all
		; {weapon_work "gun" 0}
		; {weapon_work "mgun" 0}
		; {weapon_work "alarm_signal" 0}	
		; {weapon_work "attack_melee_charge" 0}
		; {weapon_work "attack_melee_charge_close" 0}
		; {weapon_work "head_joint" 0}
		; {weapon_work "mgun_pestcontainer" 0}
		; {weapon_work "attack_gas" 0}
		{auto_operatable 0}
		{drop_orders}
		{able select 0}
		{play_sound "power_down" }
		{play_sound "power_down_bb" }
		{stop_sound "engine" }
		{call "power_drop"}
		{ani_stop "engine_on"}	
	}
	{on animation_event "power_down_check";all
		{chassis_work 0}
		{auto_operatable 0}
		{able select 0}
	}
	{on animation_event "power_down_start_spawn";all
		{chassis_work 0}
		{auto_operatable 0}
		{drop_orders}
		{able select 0}
		{stop_sound "engine" }
		;{call "power_drop"}
	}	
	{on animation_event "restart_clunk";all
		{if able "exploded"
			{ani_stop "power_down"}
		}
		{if rand 0.1
			{spawn "electric_spark_hit" "back_engine_organ"}
		}
		{if rand 0.3
			{spawn "electric_spark_hit" "Spine1"}
		}
		{if rand 0.4
			{start_sound "generation_zero/characters/restart_clunk/med/"}			
		}
	}
	{on animation_event "power_up_load";all
		{play_sound "power_up"}
		{play_sound "power_up_bb"}
	}
	{on animation_event "power_down_leave";all
		{bone show	"orange_ems"}
		{bone show	"red_ems"}
		{if work "fuel"
			{chassis_work 1}
			{play_sound "engine" 1 loop}
			{play_sound "engine_hiss" 1 loop}
			{play_sound "engine_add" 1 loop}
			{ani_play "engine_on" loop}	
		}
		; (define "work"
			; {if work "%mgun"
				; {weapon_work "%mgun" 1}
			; }
		; )
		; ("work"  work(gun))
		; ("work"  work(mgun))
		; ("work"  work(mgun1))
		; ("work"  work(mgun2))
		; ("work"  work(mgun3))
		; ("work"  work(alarm_signal))
		; ("work"  work(gasdrop))
		; ("work"  work(mgun_melee))
		; ("work"  work(mgun_pestcontainer))
		{if not able "exploded" 
			{auto_operatable 1}
			{able select 1}
			{call "power_up"}
		}
	}
	{on animation_event "tail_fx_start" ;pest
		{view start "smoke_gas_tail_close"}
		{view show "smoke_gas_tail_close"}
	}
	{on animation_event "tail_fx_end"
		{view hide "smoke_gas_tail_close"}
		{view stop "smoke_gas_tail_close"}
	}
	{on animation_event "restart_micro"
		{if rand 0.1
			{spawn "electric_spark_hit" "body"}
		}
		{if rand 0.7
			{start_sound "generation_zero/electric_spark/"}			
		}
	}
	{on animation_event "block_class_d" 
		{chassis_work 0}
		{weapon_work "attack_melee_charge_close" 0} ;class_d
	}
	{on animation_event "close_combat_leave"
		{chassis_work 1}
		{weapon_work "attack_melee_charge_close" 1} ;class_d
	}
	{on animation_event "foot_micro" ;pest
		{if rand 0.1
			{spawn "dust_micro_pest" "rightHand_bone"}
		else rand 0.15
			{spawn "dust_micro_pest" "leftHand_bone"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/pest/move/%0/"}	
			
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "combat_micro_armed_enter"
		{tags add "combat"}
	}
	{on animation_event "combat_micro_armed_leave"
		{tags remove "combat"}
	}
	{on animation_event "jump_micro"
		{start_sound "generation_zero/characters/pest/jump/"}	
		{delay 0.3
			{if rand 0.5
				{start_sound "generation_zero/characters/pest/combat/"}	
			}
		}
	}
}
{"pest_classic"
	{on "link_sound"
		{link_sound "combat" 	"generation_zero/characters/pest/armed"} ;animation_event "combat_micro_armed_enter"
		{link_sound "engine" 	"generation_zero/characters/pest/engine/pest_engine_02_2ch"}
	}	
	{on "pest_combat_talk"
		{start_sound "generation_zero/characters/pest/combat/"}	
	}
	{on fire "alarm_signal"   
		{start_sound "generation_zero/characters/pest/combat"}				
	}
	{on contact ; pest
		{if tagged "fly"
			{if effector "small_stuff"
				{with_effector
					{impulse dir 2 1}
				}
			}
			(define "contact_fx"
				{if min_speed 5
					{if material %0 			
						{spawn %2  }
						{start_sound "hit/drop/%1/"}	
					}
				}
			)
			("contact_fx" args "concrete" 	concrete "stone_hit_bul_small")
			("contact_fx" args "steel" 		metal   "metal_pierce_bul_big" )
			("contact_fx" args "wood" 		wood_hollow "wood_hit_bul" )
			("contact_fx" args "misc" 		carpet "plastic_hit_bul")		
			{if not effector "human"
				{if not effector "small_stuff"
					{ani_stop "attack_melee_jump_close"}
					(define "disable_contact_0")
					{bone hide "sparks_link"}
					{ani_stop "micro_combat" }
					{view hide "combat"}
					{view pause "combat"}
					{stop_sound "combat" }
					{tags remove "combat"}
					{delay 3
						{weapon_work "mgun" 1}		
					}
				}
				;{impulse up 1.1}			
				;{impulse forward -1 }
				{if rand 0.3 
					{spawn "spheredust_small_short2" }
				else rand 0.1 
					{spawn "spheredust_small_short" }
				}
			}
			;{start_sound "generation_zero/char_machine_small/deploy_pest_egg"}
		}
		{if tagged "combat"
			{if effector "human"
				{with_effector
					{call "critical_health"}
					{if rand 0.3 
						{throw_on_ground}
						;{knockdown 2 0.5}
					}
					{talk "hit"}
					{tags add "bleeding_small_e"}
					{delay 1.4
						{tags remove "bleeding_small_e"}
					}
					{call "bleeding_small_e"}
					(define "electra_hit"
						{if volume "%volume"
							{burn volume "%volume" fx "electra_hit" time %time fake even_law}
						}
					)
					("electra_hit" volume(body) time(1.5))
					("electra_hit" volume(head) time(1.5))
					("electra_hit" volume(foot1r) time(2.5))
					("electra_hit" volume(foot2r) time(2.5))
					("electra_hit" volume(foot1l) time(2.5))
					("electra_hit" volume(foot2l) time(2.5))
					("electra_hit" volume(hand1r) time(2.5))
					("electra_hit" volume(hand2r) time(2.5))
					("electra_hit" volume(hand1l) time(2.5))
					("electra_hit" volume(hand2l) time(2.5))
				}
			}
		}
	}
}
{"pest_class_d"
	{on "link_sound"
		{link_sound "combat" 	"generation_zero/characters/pest_class_d/armed"}
		{link_sound "engine" 	"generation_zero/characters/pest/engine/pest_engine_02_2ch"}
	}	
	{on "pest_combat_talk"
		{start_sound "generation_zero/characters/pest_class_d/combat/"}	
	}
	{on fire "alarm_signal"   
		{start_sound "generation_zero/characters/pest/combat"}				
	}
	{on move on ; pest_class_d
		{weapon_work "attack_melee_charge_close" 0}		
	}
	{on move off ; pest_class_d
		{weapon_work "attack_melee_charge_close" 1}		
	}
	{on fire "attack_melee_charge_close" ;pest_class_d
		{start_sound "generation_zero/characters/pest_class_d/combat/"}	
		{tags remove "move"}
		{tags remove "move_forward"}
		{call "stop_all_ani"}
		{call "stop_idle"}
		{physics_work 0}
		{chassis_work 0}
		{tags remove "idle_enter"}		
		{ani_play "attack_melee_close" 1 callback}
	}
	{on animation_end "attack_melee_close"
		{physics_work 1}
		{chassis_work 1}
	}
	{on animation_event "jump_micro" overload
		{burn volume "fx_tail" fx "smoke_gas_tail" time 3 fake even_law}
		{impulse forward 1 }				
		{spawn "dust_jump" "basis"}
		{start_sound "generation_zero/characters/pest/jump/"}	
	}
	{on animation_event "combat_micro_armed_enter"
		{bone show "sparks_link"}
		{view show "combat"}
		{view start "combat"}
		{ani_play "micro_combat" 2 loop }
		{play_sound "combat" 1}
	}
	{on animation_event "combat_micro_armed_leave"
		{bone hide "sparks_link"}
		{ani_stop "micro_combat" }
		{view hide "combat"}
		{view pause "combat"}
		{stop_sound "combat" }
		{tags remove "combat"}
	}
	{on animation_event "combat_micro" overload
		{if rand 0.5
			{start_sound "generation_zero/characters/pest_class_d/combat/"}	
		}
	}
}
{"pest_bomb"
	{on "link_sound"
		{link_sound "combat" 	"generation_zero/characters/pest/armed"}
		{link_sound "engine" 	"generation_zero/characters/pest/engine/pest_engine_02_2ch"}
	}	
	{on "pest_combat_talk"
		{start_sound "generation_zero/characters/pest_c4/combat/"}	
	}
	{on fire "alarm_signal"   
		{start_sound "generation_zero/characters/pest_c4/alert"}				
	}
	{on animation_event "combat_micro" overload
		{if rand 0.5
			{start_sound "generation_zero/characters/pest_c4/combat/"}	
		}
	}
	{on contact ; pest_bomb
		{if tagged "combat"
			{with_linked_entity "link_bomb"
				{stuff_detonate}
			}				
		}
		{if tagged "fly"
			(define "contact_fx"
				{if min_speed 5
					{if material %0 			
						{spawn %2  }
						{start_sound "hit/drop/%1/"}	
					}
				}
			)
			("contact_fx" args "concrete" 	concrete "stone_hit_bul_small")
			("contact_fx" args "steel" 		metal   "metal_pierce_bul_big" )
			("contact_fx" args "wood" 		wood_hollow "wood_hit_bul" )
			("contact_fx" args "misc" 		carpet "plastic_hit_bul")		
			{if not effector "human"
				{ani_stop "attack_melee_jump_close"}
				(define "disable_contact_0")
				{bone hide "sparks_link"}
				{ani_stop "micro_combat" }
				{view hide "combat"}
				{view pause "combat"}
				{stop_sound "combat" }
				{tags remove "combat"}
				{delay 3
					{weapon_work "mgun" 1}		
				}
				;{impulse up 1.1}			
				;{impulse forward -1 }
				{if rand 0.3 
					{spawn "spheredust_small_short2" }
				else rand 0.1 
					{spawn "spheredust_small_short" }
				}
			}
			;{start_sound "generation_zero/char_machine_small/deploy_pest_egg"}
		}
	}
}
{"pest_bomb_link"
	{inflammation_time 0.3}
	{on contact
		{if effector "fraction_small"
			{stuff_detonate}
		}
	}
	{on pierce ; _bomb
		{stuff_detonate}
	}
	{on blast ; _bomb
		{if min_energy 2
			{stuff_detonate}
		}
	}
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{call "_burn"}
		}
	}
	{on "_burn"
		{start_sound "fire/small"}
		{burn volume fx "smoke_dead_norm" time 2 fake even_law}
		{delay 0.4
			{stuff_detonate}
		}
	}
}



