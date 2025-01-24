{"skirmisher_base"
	{inflammation_time 2}
	{on spawn
		{add_view 	"scanline_light" 						"scanline_light" "scanlines_fx"}
		{add_view 	"scanline_burn" 						"scanline_light" "scanlines2_fx_bone"}
		{add_view 	"scanline_burn" 						"scanline_light" "scanlines_fx_bone"}
		{add_view 	"yellow_ems" 							"ems_global_search" "head_ems_bone"}
		{add_view 	"headlight_car_led" 					"ems_global" "head_light_00_fx"}

		{add_view 	"flash_gun_silencer_small" 		"fx_main" 			"foresight"}
		{add_view 	"smoke_sil_small" 				"fx_fire_hot" 		"foresight"}

		;burn_element
		{add_view 	"burn_element_cpu" 			"cpu_burn" "cpu"}
		{add_view 	"smoke_element_cpu" 		"cpu_smoke" "cpu"}

		
		{add_view 	"burn_element" 			"smoke_hips_h" "H_drive"}
		{add_view 	"burn_element" 			"smoke_hips_v" "V_drive"}
		
		{view hide	"fx_main_sniper"}
		{view pause	"fx_main_sniper"}
		{view hide	"fx_main_mgun"}
		{view pause	"fx_main_mgun"}
		{view hide	"fx_fire_hot_mgun"}
		{view pause	"fx_fire_hot_mgun"}

		{view hide	"fx_main"}
		{view pause	"fx_main"}
		{view hide	"fx_fire_hot"}
		{view pause	"fx_fire_hot"}

		{view hide	"laser_point"}
		{view pause	"laser_point"}
		{view hide	"scanline_light"}
		{view pause	"scanline_light"}

		{tags add "skirmisher_base"}
		{link_sound "engine" 	"generation_zero/characters/skirmisher/engine/runner_class4_engine"}
		{delay 0.1
			{if not able "exploded"
				{if not "engine_started"
					{set "engine_started" 1}
					{if tagged "frends"
						{player 0}
					else
						{player 8}
					}
					{if not tagged "started"
						{start_sound "generation_zero/characters/skirmisher/spawn/"}	
						{tags add "started"}
						{ani_play "power_up_spawn" resume }	
					}
				else
					{ani_wind "power_up_spawn" end}
					{if tagged "frends"
						{player 0}
					else
						{player 8}
					}
				}
			}
		}
		{tags add "hold"}
		{tags add "machine"}
		{call "led_ems_connect"}
		{call "led_light_connect"}
		{call "radio_connect"}
		{call "sound_connect"}
		{set "stop" 1}
		{delay 15 5 "idle_enter"
			{tags add "idle_enter"}
			{call "idle-enter"}
		}		
		{ik_enable "head_ik_h_damage" 0}
		{ik_enable "head_ik_v_damage" 0}
		{weapon_work "attack_melee_charge" 0}
	}

	{on "sound_connect"
		{link_sound "scan-var1" "generation_zero/characters/skirmisher/scan/scan_loop_02"}
		{link_sound "scan-var2" "generation_zero/characters/skirmisher/scan/scan_loop_02"}
		{link_sound "scan-var3" "generation_zero/characters/skirmisher/scan/scan_loop_02"}
		
		{link_sound "heater"						"weapon/heat/" 	}	
		
		{link_sound "power_down_bb" "generation_zero/characters/restart_clunk/power/bb/emp_01_shutdown_bb"}
		{link_sound "power_down" "generation_zero/characters/restart_clunk/power/dir/emp_01_shutdown_dir"}
	
		{link_sound "power_up_bb" "generation_zero/characters/restart_clunk/power/bb/emp_01_startup_bb"}
		{link_sound "power_up" "generation_zero/characters/restart_clunk/power/dir/emp_01_startup_dir"}
	}
	{on "led_ems_connect"
		(define "leds_ems_global_small"
			{add_view 	"yellow_ems_small" 	"ems_global_search" 	"%vis_search"}
			{add_view 	"red_ems_small" 	"ems_global_alarm" 		"%vis_alarm"}
			{add_view 	"hold_ems_small" 	"ems_global_hold" 		"%vis_hold"}
			{bone show "%vis_hold"}
			{view show	"ems_global_hold"}
			{view start	"ems_global_hold"}
			{view hide	"ems_global_alarm"}
			{view pause	"ems_global_alarm"}
			{view hide	"ems_global_search"}
			{view pause	"ems_global_search"}
		)
		("leds_ems_global_small"  vis(RightUpLeg_ems) )
		("leds_ems_global_small"  vis(LeftUpLeg_ems)  )
		("leds_ems_global_small"  vis(head_ems_00)  )
		("leds_ems_global_small"  vis(head_ems_01)  )
		("leds_ems_global_small"  vis(head_ems_02) )
		("leds_ems_global_small"  vis(head_ems_03) )
	}
	{on "led_light_connect"
		{add_view 	"yellow_ems_med" 	"ems_global_search" 	"visor_head_bone"}
		{add_view 	"red_ems_med" 		"ems_global_alarm" 		"visor_head_bone"}
		{add_view 	"hold_ems_med" 		"ems_global_hold" 		"visor_head_bone"}
		{view show	"ems_global_hold"}
		{view start	"ems_global_hold"}
		{view hide	"ems_global_alarm"}
		{view pause	"ems_global_alarm"}
		{view hide	"ems_global_search"}
		{view pause	"ems_global_search"}
	}
	
	
	{on "ai_talk_signal" 
		{delay 0.2
			{if tagged "alarm"
				{tags remove "search"}
				{tags remove "hold"}
				{if not tagged "alarm_call"
					{tags add "alarm_call"}
					{if rand 0.4
						{start_sound "generation_zero/characters/skirmisher/combat/skir_combat_call_2ch"}	
						{start_sound "generation_zero/characters/skirmisher/combat_bb/skir_combat_call_bb"}			
					else rand 0.3
						{start_sound "generation_zero/characters/skirmisher/combat/skir_confirmation_01_2ch"}	
						{start_sound "generation_zero/characters/skirmisher/combat_bb/skir_confirmation_01_bb"}			
					else 
						{start_sound "generation_zero/characters/skirmisher/combat/skir_confirmation_02_2ch"}	
						{start_sound "generation_zero/characters/skirmisher/combat_bb/skir_confirmation_02_bb"}			
					}
				}
				{delay 2 {tags remove "alarm_call"}}
				;{burn volume "visor_ems" fx "red_burn" fake}
				{call "show_alarm"}
			else tagged "search"
				{tags remove "alarm"}
				{tags remove "hold"}
				{if not tagged "search_call"
					{tags add "search_call"}
					{if rand 0.4
						{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_18_clr"}	
						{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_18_bb"}	
					else rand 0.3
						{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_19_clr"}	
						{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_19_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_20_clr"}	
						{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_20_bb"}	
					else rand 0.1
						{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_21_clr"}	
						{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_21_bb"}	
					else 
						{start_sound "generation_zero/characters/skirmisher/search_c4/skir_combat_search_2ch"}	
						{start_sound "generation_zero/characters/skirmisher/search_bb/skir_combat_search_bb"}			
					}
				}
				{delay 2 {tags remove "search_call"}}
				;{burn volume "visor_ems" fx "yellow_burn" fake}
				{call "show_search"}
			else tagged "off"
				{tags remove "search"}
				{tags remove "hold"}
				{tags remove "alarm"}
				{call "show_off"}
			else tagged "hold"
				{call "show_hold"}
			}
			{delay 10 
				{if tagged "alarm"
					{if not able "exploded"
						{tags add "search"}	
						{tags remove "alarm"}	
						{call "show_search"}
					}
				}
				{delay 15 
					{if not able "exploded"
						{tags add "hold"}	
						{tags remove "search"}	
						{call "show_hold"}
					}
				}
			}
		}
	}
	{on ik begin "h_signal"
		{tags remove "hold"}	
		{tags remove "alarm"}	
		{tags add "search"}
		{if not tagged "search_call_signal"
			{tags add "search_call_signal"}
			{call "ai_talk_signal"}
		}
		{delay 2 {tags remove "search_call_signal"}}
	}
	(define "leds_ems_connect"
		("leds_ems"  vis(RightUpLeg_ems)	)
		("leds_ems"  vis(LeftUpLeg_ems) 	)
		("leds_ems"  vis(head_ems_00) 		)
		("leds_ems"  vis(head_ems_01) 		)
		("leds_ems"  vis(head_ems_02) 		)
		("leds_ems"  vis(head_ems_03)	 	)
	)
	{on "show_off" 
		{view hide	"ems_global_hold"}
		{view pause	"ems_global_hold"}
		{view hide	"ems_global_alarm"}
		{view pause	"ems_global_alarm"}
		{view hide	"ems_global_search"}
		{view pause	"ems_global_search"}
		(define "leds_ems"
			{bone hide "%vis_hold"}
			{bone hide "%vis_alarm"}
			{bone hide "%vis_search"}
		)
		("leds_ems_connect")
	}
	{on "show_hold" 
		{view start	"ems_global_hold"}
		{view show	"ems_global_hold"}
		{view hide	"ems_global_alarm"}
		{view pause	"ems_global_alarm"}
		{view hide	"ems_global_search"}
		{view pause	"ems_global_search"}
		(define "leds_ems"
			{bone show "%vis_hold"}
			{bone hide "%vis_alarm"}
			{bone hide "%vis_search"}
		)
		("leds_ems_connect")
	}
	{on "show_search" 
		{view hide	"ems_global_alarm"}
		{view pause	"ems_global_alarm"}
		{view start	"ems_global_search"}
		{view show	"ems_global_search"}
		{view hide	"ems_global_hold"}
		{view pause	"ems_global_hold"}
		(define "leds_ems"
			{bone hide "%vis_hold"}
			{bone hide "%vis_alarm"}
			{bone show "%vis_search"}
		)
		("leds_ems_connect")
	}
	{on "show_alarm" 
		{view start	"ems_global_alarm"}
		{view show	"ems_global_alarm"}
		{view hide	"ems_global_search"}
		{view pause	"ems_global_search"}
		{view hide	"ems_global_hold"}
		{view pause	"ems_global_hold"}
		(define "leds_ems"
			{bone hide "%vis_hold"}
			{bone show "%vis_alarm"}
			{bone hide "%vis_search"}
		)
		("leds_ems_connect")
	}
	{on "stop_all" 
		{ani_stop "power_up"}
		{ani_stop "power_drop"}
		{view hide	"ems_global_alarm"}
		{view pause	"ems_global_alarm"}
		{view hide	"ems_global_search"}
		{view pause	"ems_global_search"}
		{view hide	"ems_global_hold"}
		{view pause	"ems_global_hold"}
		(define "leds_ems"
			{bone hide "%vis_hold"}
			{bone hide "%vis_alarm"}
			{bone hide "%vis_search"}
			{bone hide	"light_ems"}
		)
		("leds_ems_connect")
	}	
	{on "check_work_gun"
		{if not tagged "damage_missile"
			{weapon_work "gun" 1}
		else
			{weapon_work "gun" 0}
		}
		{if not tagged "damage_mgun"
			{weapon_work "mgun" 1}
		else
			{weapon_work "mgun" 0}
		}
		{if not tagged "damage_sniper"
			{weapon_work "gun" 1}
		else
			{weapon_work "gun" 0}
		}
	}
	{on "firing_block"
		{kill_delay "limit"}
		{movement_limit slow}
		{delay 3 "limit"
			{if work "fuel"
				{drop_orders}
				{movement_limit fast}
			}
		}
	}
	{on "lose_health"
		{ani_play "health" +3 resume}
		{kill_delay "health"}
		{delay 0.2 "health"
			{ani_stop "health"}
		}
	}
	{on "power_up" ; all
		{if not able "exploded"
			{tags add "hold"}
			{call "ai_talk_signal"}
		}
	}
	{on "power_drop_permanent"
		;{kill_delay "power_drop"}
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
					{tags add "wire_burn"}
					{tags remove "hold"}
					{tags remove "alarm"}
					{tags remove "search"}
					{call "ai_talk_signal"}
					{call "sparks_loop"}
					{burn volume "cpu" fx "smoke_preheat" time 5 fake even_law}	
					{ani_play "power_down"}
					{call "gun_block"}
					{delay 15
						{tags remove "wire_burn"}				
					}
				}
			}
		}
	}
	{on "power_drop"
		;{kill_delay "power_drop"}
		{if not able "exploded"
			{delay 0.2 
				{if not tagged "power_drop"
					{delay 1.5 
						{burn volume "visor_ems" fx "yellow_burn" time 0.1 fake}
					}
					{view hide	"ems_global"}
					{view pause	"ems_global"}
					{view hide	"ems"}
					{view pause	"ems"}
					{view hide	"cooling_engine_l"}
					{view pause	"cooling_engine_r"}		
					{view hide	"cooling_engine_l_overheat"}
					{view pause	"cooling_engine_r_overheat"}		
					{call "stop_idle"}
					{tags add "power_drop"}
					{tags add "off"}
					{tags remove "hold"}
					{tags remove "alarm"}
					{tags remove "search"}
					{call "ai_talk_signal"}
					{burn volume "cpu" fx "smoke_preheat" time 5 fake even_law}	
					{ani_play "power_down"}
					{call "gun_block"}
					{delay 12 6 "power_drop"
						{if not able "exploded"
							{tags remove "power_drop"}
							{ani_play "power_up"}
							{delay 4
								{if prop "skirmisher_rocket"
									{ani_play "wpn_idle_to_combat" 0.5}
								}
							}
						}
					}
				}
			}	
		}	
	}	
	{on "drop_speed"
		{drop_orders}
		;{auto_operatable 0}
		{delay 0.5 
			{if not able "exploded"
				;{auto_operatable 1}
			}
		}
	}
	{on "drop_speed_move"
		{movement_limit slow}
		{delay 3 
			{if not able "exploded"
				{if work "fuel"
					{drop_orders}
					{movement_limit fast}
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
		{delay_effect 0.2 "electric_spark_small_loop"}		
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
	{on animation_event "runstart_f" ;dread hunter skir
		{if tagged "move"
			{call "move_update_f"}
		else
			{ani_play "runstop_f" 1}
		}
	}	
	{on move on ;skir
		{weapon_work "attack_melee_charge_close" 0} ;close
		{weapon_work "gun" 0}
		{weapon_work "sniper_on" 0}
		{kill_delay "move_stop"}
		{call "stop_idle"}
		{tags add "move"}	
		{set "blocked" 1}
		{if not tagged "turn"
			{if Move_Forward
				{tags add "move_forward"}
				{if velocity 11
					{ani_play "runstart_f" 0.5 }
				else velocity 0
					{ani_play "walkstart_f"  }
					;{movement_limit normal}
					{delay 10 "gear_speed"
						{if work "fuel"
							{tags add "fast_move"}
							;{movement_limit fast}
						}
					}
				}	
			}
		}
		{call "weapon_off"}
		{call "weapon_gas_off"}
		{call "weapon_melee_off"}
		{if broken "upper_arm" 2
			{tags add "engine_leg_broken"}
		}
	}
	{on move off ; all
		{weapon_work "attack_melee_charge_close" 1}
		{if work "sniper"
			{weapon_work "gun" 1}
		}
		{call "stop_idle"}
		{delay 0.5
			{if not tagged "move"
				{if not tagged "turn"
					{call "stop_all_ani"}
				}
			}
		}
		{tags remove "move_forward"}	
		{tags remove "move_backward"}	
		{tags remove "move"}	
		{tags remove "turn"}
		{tags remove "run"}
		{tags remove "walk"}
		{delay 0.5 "move_stop"
			{call "weapon_on"}
		}
		{delay 1 "move_stop"
			{call "weapon_melee_on"}
		}
		{set "blocked" 0}
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
	{on animation_event "update_turn_left" ;hunter skir
		{call "update_turn_left"}
	}
	{on animation_event "update_turn_right";hunter skir
		{call "update_turn_right"}
	}
	{on turn off overload ; add remove tags left right
		{delay 0.5 "move_stop"
			{call "weapon_on"}
		}
		{tags remove "turn_left"}
		{tags remove "turn_right"}
		{tags remove "turn"}
		{tags remove "long_turn"}
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
	{on brake on 
		{if tagged "fast_move"
			{tags remove "fast_move"}
		}
		; {if velocity 10
			; {play_sound ""  }
		; else
			; {play_sound ""  }
		; }
		; {call ""}
		; {tags remove ""}
		; }
	}	
	{on engine on
	}
	{on engine off
	}
	{on "explosion_skir_big" 
		{if not able "exploded"	
			{kill_delay "electric_spark_small_loop_health"}
			{mtl_enable_skin 0}
			{able "exploded" 1}
			{able select 0}
			{able repaired 0}
			{set "exploded" 1}
			{tags remove "electric_spark_loop"}
			{tags remove "started"}
			{kill_delay "sparks_loop_cpu"}		
			{kill_delay "electric_spark_small_loop"}		
			{kill_delay "sparks_loop"}		
			{stop_sound "engine" }
			{bone hide "legs_wire"}
			{bone hide "body_wire"}
			{tags add "off"}
			{tags add "dead"}
			{call "stop_all"}
			{if tagged "move"
				{impulse forward 2.5 cx 3 2 cy 3 2 rnd_dir 2 no_position}		
			else
				{impulse up 0.5 cx 3 2 cy 3 2 rnd_dir 2 no_position}		
			}
			{burn volume "cpu" fx "fx_fire_engine_gen" time 2 fake even_law}					
			{burn volume "body_organ" fx "smoke_heat" time 5 fake even_law}					
			{kill_delay "idle"}
			{drop_orders}
			{delay 0.5
				{components destroy}
			}
			{reset_manual_control}
			{auto_operatable 0}
			{delay_ex 0.1
				{set_skeleton "_x" sync}
				{call "tear_parts_explode"}
			}
			{clear_inventory}
			{spawn "destroy_med_robot" "hips"}
			{spawn "burn_flare" "head"}
		}
	}	
	{on "explosion_skir" 
		{if not able "exploded"			
			{mtl_enable_skin 0}
			{set "exploded" 1}		
			{able "exploded" 1}
			{tags remove "electric_spark_loop"}
			{tags remove "started"}
			{kill_delay "sparks_loop_cpu"}		
			{kill_delay "electric_spark_small_loop"}		
			{kill_delay "sparks_loop"}		
			{burn volume "cpu" fx "fx_fire_engine_gen" time 2 fake even_law}					
			{burn volume "body_organ" fx "smoke_heat" time 5 fake even_law}					
			{kill_delay "idle"}
			{stop_sound "engine" }
			{bone hide "legs_wire"}
			{bone hide "body_wire"}
			{tags add "off"}
			{tags add "dead"}
			{call "stop_all"}
			{delay_ex 0.1
				{set_skeleton "_x" sync}
				{call "tear_parts"}
			}
			{if tagged "move"
				{impulse forward 2.5 cx 3 2 cy 3 2 rnd_dir 2 no_position}		
			else
				{impulse up 0.5 cx 3 2 cy 3 2 rnd_dir 2 no_position}		
			}
			; {delay 0.5
				; {components destroy}
			; }
			{auto_operatable 0}
			{able select 0}
			{able repaired 0}
			{clear_inventory}
			{spawn "destroy_med_robot" "hips"}
			{spawn "burn_flare" "head"}
		}
	}
	{on "tear_parts_explode"
		{spawn "car_destroy_engine" }
		(define "blast_skir"
			{if rand %1
				{tear "piece_small_steel" bone %0
					{mtl_enable_skin 0}
					{impulse up 4 3 dir 12 5 cx 3 2 cy 3 2 no_position}
				}
			}
		)
		("blast_skir" args "fuel" 				0.4)
		("blast_skir" args "RightHandIndex1" 	0.9)
		("blast_skir" args "RightHand" 			0.5)
		("blast_skir" args "RightForeArm" 		0.6)
		("blast_skir" args "RightArm" 			0.6)
		("blast_skir" args "RightUpLeg" 		0.6)
		("blast_skir" args "RightLeg" 			0.7)
		("blast_skir" args "RightFoot" 			0.7)
		("blast_skir" args "RightToeBase" 		0.7)		
		("blast_skir" args "leftHandIndex1" 	0.8)
		("blast_skir" args "leftHand" 			0.7)
		("blast_skir" args "leftForeArm" 		0.7)
		("blast_skir" args "leftArm" 			0.6)
		("blast_skir" args "leftUpLeg" 			0.6)
		("blast_skir" args "leftLeg" 			0.8)
		("blast_skir" args "leftFoot" 			0.8)
		("blast_skir" args "leftToeBase" 		0.7)
		("blast_skir" args "armour_knee_right" 	0.8)
		("blast_skir" args "armour_knee_left" 	0.8)			
		("blast_skir" args "armour_shoulder_right" 		0.8)
		("blast_skir" args "armour_shoulder_left" 		0.8)
		("blast_skir" args "armour_head" 				0.8)
		("blast_skir" args "front_armor" 				0.8)			
		("blast_skir" args "neck" 						0.8)
		("blast_skir" args "scanner" 					0.8)		
		("blast_skir" args "head" 						0.8)	
		("blast_skir" args "magazine" 			1)	
		("blast_skir" args "mgun" 				1)	
		("blast_skir" args "weaponattach" 			1)	
	}
	{on "tear_parts"
		(define "blast_skir"
			{if rand %1
				{tear "piece_small_steel" bone %0
					{mtl_enable_skin 0}
					{impulse up 0.5 dir 1 0.5 cx 1 0.5 cy 1 0.5 rnd_dir 1 0.5 no_position}
				}
			}
		)
		("blast_skir" args "fuel" 				0.9)
		("blast_skir" args "RightHandIndex1" 	0.8)
		("blast_skir" args "RightHand" 		0.6)
		("blast_skir" args "RightForeArm" 	0.5)
		("blast_skir" args "RightArm" 		0.3)
		("blast_skir" args "RightUpLeg" 		0.3)
		("blast_skir" args "RightLeg" 		0.5)
		("blast_skir" args "RightFoot" 		0.5)
		("blast_skir" args "RightToeBase" 	0.7)		
		("blast_skir" args "leftHandIndex1" 	0.8)
		("blast_skir" args "leftHand" 		0.6)
		("blast_skir" args "leftForeArm" 		0.5)
		("blast_skir" args "leftArm" 			0.3)
		("blast_skir" args "leftUpLeg" 		0.3)
		("blast_skir" args "leftLeg" 			0.5)
		("blast_skir" args "leftFoot" 		0.5)
		("blast_skir" args "leftToeBase" 		0.7)
		("blast_skir" args "armour_knee_right" 0.5)
		("blast_skir" args "armour_knee_left" 0.5)			
		("blast_skir" args "armour_shoulder_right" 0.5)
		("blast_skir" args "armour_shoulder_left" 0.5)
		("blast_skir" args "armour_head" 		0.8)
		("blast_skir" args "front_armor" 		0.5)			
		("blast_skir" args "neck" 			0.3)
		("blast_skir" args "scanner" 			0.8)		
		("blast_skir" args "head" 			0.4)	
		("blast_skir" args "magazine" 			1)	
		("blast_skir" args "mgun" 				1)	
		("blast_skir" args "weaponattach" 			1)	
	}

	{on "fx_component_mover" ; skir
		(define "fx_component"
			{if not work "%component"
				{if rand %rand
					;{add_view 	"component_break_fx" "break_fx" "%component"}
					;{view start "break_fx"}
					;{delay 1 0.5
					;	{view pause "break_fx"}
					;}
					{spawn "component_break_fx" "%component"}
				}
			}
		)		
		("fx_component" rand(0.2) component(leftarm)   )
		("fx_component" rand(0.2) component(leftfoot)   )
		("fx_component" rand(0.2) component(leftforearm)   )
		("fx_component" rand(0.2) component(lefthand)   )
		("fx_component" rand(0.2) component(lefthandtoe)   )
		("fx_component" rand(0.2) component(leftleg)   )
		("fx_component" rand(0.2) component(lefttoebase)   )
		("fx_component" rand(0.2) component(leftupleg)   )
		("fx_component" rand(0.2) component(leftUpLeg_knee)   )
		("fx_component" rand(0.2) component(rightarm)   )
		("fx_component" rand(0.2) component(rightfoot)   )
		("fx_component" rand(0.2) component(rightforearm)   )
		("fx_component" rand(0.2) component(righthand)   )
		("fx_component" rand(0.2) component(righthandtoe)   )
		("fx_component" rand(0.2) component(rightleg)   )
		("fx_component" rand(0.2) component(righttoebase)   )
		("fx_component" rand(0.2) component(rightupleg)   )
		("fx_component" rand(0.2) component(rightUpLeg_knee)   )
	}
	{on "move_update_walk" ; skir 
		(define "move_update"
			{if velocity %speed
				{ani_play "walkloop_fwd" (* %speed 0.9) }
				;{tags add "%speed"}	;check sum
				;{tags add "%ani"}	;check sum
			}
		)		
		;("move_update" speed(19)  	)
		;("move_update" speed(18)  	)
		;("move_update" speed(17)  	)
		;("move_update" speed(16)  	)
		;("move_update" speed(15)  	)
		;("move_update" speed(14)  	)
		;("move_update" speed(13)  	)
		;("move_update" speed(12)  	)
		;("move_update" speed(11)  	)
		("move_update" speed(10)  	)
		("move_update" speed(9)  	)
		("move_update" speed(8)		)
		("move_update" speed(7) 	)
		("move_update" speed(6) 	)
		("move_update" speed(5) 	)
		("move_update" speed(4) 	)
		("move_update" speed(3) 	)
		("move_update" speed(2)  	)
		("move_update" speed(1)  	)
	}	
	{on "move_update_run" 
		(define "move_update_run"
			{if velocity %speed	
				{if tagged "run"
					{ani_play "runloop_fwd" (* %speed 0.06) }
					; {if tagged "fast_move"
						; {if rand 0.1
							; {ani_play "attack_melee_charge_01"}
						; }
					; }
				}
				;{tags add "%speed"}	;check sum
				;{tags add "%ani"}	;check sum
			}
		)		
		("move_update_run" speed(45) 	)
		("move_update_run" speed(43) 	)
		("move_update_run" speed(41) 	)
		("move_update_run" speed(39) 	)
		("move_update_run" speed(37) 	)
		("move_update_run" speed(35) 	)
		("move_update_run" speed(32) 	)
		("move_update_run" speed(30) 	)
		("move_update_run" speed(28) 	)
		("move_update_run" speed(26) 	)
		("move_update_run" speed(24) 	)
		("move_update_run" speed(22) 	)
		("move_update_run" speed(20)	)
		("move_update_run" speed(19)  	)
		("move_update_run" speed(18)  	)
		("move_update_run" speed(17)  	)
		("move_update_run" speed(16)  	)
		("move_update_run" speed(15)  	)
		("move_update_run" speed(14)  	)
		("move_update_run" speed(13)  	)
		("move_update_run" speed(12)  	)
		("move_update_run" speed(11)  	)
	}	
	{on "update_turn_right"
		{if tagged "long_turn"
			{tags add "step_r_090"}	
			{ani_play "step_r_090" 1 resume loop}	
		else
			{tags add "step_r_045"}	
			{ani_play "step_r_045" 0.6 resume loop}	
		}
	}
	{on "update_turn_left"
		{if tagged "long_turn"
			{tags add "step_l_090"}	
			{ani_play "step_l_090" 1 resume loop}	
		else
			{tags add "step_l_045"}	
			{ani_play "step_l_045" 0.6 resume loop}	
		}
	}
	{on "jump_allow"
		{weapon_work "attack_melee_charge" 1}
	}
	{on "jump_reject"
		{weapon_work "attack_melee_charge" 0}
	}
		
	{on "weapon_off" ; all
		{kill_delay "main_gun"}
		{if work "fuel"
			{chassis_work 1}
		}
		{if tagged "weapon_active"
			{if not tagged "destroy_mgun"
				{weapon_work "mgun" 0}
				{tags remove "weapon_active"}
				{ani_play "wpn_combat_to_idle"  }					
			}
		}
	}
	{on "weapon_on" ; all
		{if not tagged "weapon_active"
			{kill_delay "main_gun" }		
			{if not tagged "destroy_mgun"
				{tags add "weapon_active"}
				;{movement_limit slow}
				{if work "mgun"
					{ani_play "wpn_idle_to_combat" 0.5}		
				else
					{ani_play "wpn_idle_to_combat" 0.2}	
				}					
				{if work "shotgun"
					{ani_play "wpn_idle_to_combat" 0.5}		
				else
					{ani_play "wpn_idle_to_combat" 0.2}	
				}					
				{delay 0.5 "main_gun"
					{if work "gun"
						{weapon_work "gun" 1}
					}
					{if work "mgun"
						{weapon_work "mgun" 1}
					}
					{if work "shotgun"
						{weapon_work "mgun" 1}
					}
					{delay 2 "main_gun"
						{if not tagged "destroy_mgun"
							{if tagged "damage_mgun" {if rand 0.5 {call "jammed_gun_skir"}}}
							;{if work "fuel"
							;	{movement_limit fast}
							;}
						}
					}
				}
			}
		}
	}
	
	
	{on "jammed_gun_skir" ; skir	
		{kill_delay "jammed_gun" }		
		{weapon_work "mgun" 0}
		{if not tagged "destroy_mgun"
			{ani_play "wpn_combat_to_idle" 0.8}
			{burn volume "mgun" fx "smoke_heat" time 0.8 fake even_law}
			{start_sound "generation_zero/hits/electricity_explo_small/"}		
			{delay 0.2 "jammed_gun"
				{ani_play "wpn_idle_to_combat" 0.8}
				{start_sound "generation_zero/hits/electricity_explo_small/"}		
				{delay 0.2 "jammed_gun"
					{ani_play "wpn_combat_to_idle" 0.8}
					{start_sound "generation_zero/hits/electricity_explo_small/"}		
					{delay 0.2 
						{if not tagged "destroy_mgun"
							{weapon_work "mgun" 1}
						}
						{ani_play "wpn_idle_to_combat" 0.8}
						{start_sound "generation_zero/hits/electricity_explo_small/"}		
					}
				}
			}
		}
	}
;idle--------------------skir
	{on "stop_idle"
		{view stop "scanline_light"}		
		{view hide "scanline_light"}		
		{ani_stop "scan" }	
		{bone hide "scanlines_2"}
		{bone hide "scanlines"}
		{stop_sound "scan-var1" }
		{stop_sound "scan-var2" }
		{stop_sound "scan-var3" }
		{kill_delay "idle"}
		{call "idle_exit"}	
		{ani_stop "idle_loop"}
		{ani_stop "idle_loop_var_01"}
		{ani_stop "idle_loop_var_02"}
		{ani_stop "idle_loop_var_03"}
		{ani_stop "scan_wide_loop" }
		
	}
	{on "idle-enter"
		{if not "exploded"
			{if tagged "idle_enter"
				{delay 40 20 "idle"
					{call "idle_try"}
				}
			}
		}
	}
	{on "idle_try"
		{if able "select"
			{delay 0.2 "idle"
				{if not tagged "play_idle"
					{if rand 0.3
						{ani_play "idle_loop_var_01" }
					else rand 0.3
						{ani_play "idle_loop_var_02" }
					else rand 0.3
						{ani_play "idle_loop_var_03" }
					else rand 0.2
						{ani_play "idle_loop_var_04_left" }
					else rand 0.2
						{ani_play "idle_loop_var_04_right" }						
					else
						{delay 40 20 "idle"
							{call "idle_try"}
						}
					}
				}
			}
		}
	}
	{on "idle_exit"
		{if tagged "play_idle_right"
			{ani_play "idle_loop_var_04_right" -2 resume}
		}
		{if tagged "play_idle_left"
			{ani_play "idle_loop_var_04_left" -2 resume}
		}
	}
	{on contact ; skir
		{if effector "tank"
			{if min_speed 10
				(define "mesh_break" ;
					{if volume "%component"
						{if not work "%component"
							{if rand %rand
								{components "%component" destroy}
							}
						}
						{if rand %rand
							{components "%component" break}
						}
					}
				)
				("mesh_break" component(hips)  				rand(0.3)    )
				("mesh_break" component(gasdrop_l)  							rand(0.3) d_rand(0.3)    )
				("mesh_break" component(gasdrop_r)  							rand(0.3) d_rand(0.3)    )
				("mesh_break" component(Concussion_Pulse_r)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(Concussion_Pulse_l)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(Drillmount)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(backlegs_mount)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(frontlegs_mount)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_core_panel)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(structure_plate_right)  				rand(0.3) d_rand(0.5)    )
				("mesh_break" component(structure_plate_left)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(back_hatch_l)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(back_hatch_r)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_hatch_l)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_hatch_r)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(drill_hatch_r)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(drill_hatch_l)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(Drill)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(pestcontainer)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(engine_move)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(backfan_01)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(backfan_02)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(backfan_03)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(sideplate_left)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(sideplate_right)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(head_sideplate_front_r)  				rand(0.3) d_rand(0.5)    )
				("mesh_break" component(head_sideplate_front_l)  				rand(0.3) d_rand(0.5)    )
				("mesh_break" component(head_sideplate_back_r)  				rand(0.3) d_rand(0.5)    )
				("mesh_break" component(head_sideplate_back_l)  				rand(0.3) d_rand(0.5)    )
				;all armor
				("mesh_break" component(front_armor)  				rand(0.3)    )
				("mesh_break" component(down_armor)  				rand(0.3)    )
				("mesh_break" component(armour_head)  				rand(0.5)    )
				("mesh_break" component(armour_knee_left)  			rand(0.5)    )
				("mesh_break" component(armour_knee_right)  		rand(0.5)    )
				("mesh_break" component(armour_shoulder_left)  		rand(0.5)    )
				("mesh_break" component(armour_shoulder_right)  	rand(0.5)    )
				("mesh_break" component(kneepad_r)  			rand(0.5)    )
				("mesh_break" component(kneepad_l)  			rand(0.5)    )
				("mesh_break" component(head_top)  				rand(0.5)    )
				("mesh_break" component(back_armor)  			rand(0.5)    )
				("mesh_break" component(upper_armor_raid)  		rand(0.3)    )
				("mesh_break" component(front_armor_raid)  		rand(0.2)    )
				("mesh_break" component(armor_head_wire)  		rand(0.5)    )
				("mesh_break" component(knee_plate_l)  			rand(0.3))
				("mesh_break" component(knee_plate_r)  			rand(0.3) )
				("mesh_break" component(front_plate_r)  			rand(0.3))
				("mesh_break" component(front_plate_l)  			rand(0.3))
				;all leg
				("mesh_break" component(leftupleg_knee)  		rand(0.3)    )
				("mesh_break" component(leftarm)  				rand(0.3)    )
				("mesh_break" component(leftfoot)  				rand(0.3)    )
				("mesh_break" component(leftforearm)  			rand(0.3)    )
				("mesh_break" component(lefthand)  				rand(0.3)    )
				("mesh_break" component(lefthandtoe)  			rand(0.3)    )
				("mesh_break" component(leftleg)  				rand(0.3)    )
				("mesh_break" component(lefttoebase)  			rand(0.3)    )
				("mesh_break" component(leftupleg)  			rand(0.3)    )
				("mesh_break" component(leftShoulder)  			rand(0.3)    )
				("mesh_break" component(leftUpLeg_spring)  		rand(0.3)    )
				("mesh_break" component(leftUpLeg1)  			rand(0.3)    )
				("mesh_break" component(leftArmorPlate_Knee)  	rand(0.3)    )
				("mesh_break" component(leftToe1)  				rand(0.3)    )
				("mesh_break" component(leftToe2)  				rand(0.3)    )
				("mesh_break" component(leftToe3)  				rand(0.3)    )
				("mesh_break" component(leftToe4)  				rand(0.3)    )
				("mesh_break" component(rightupleg_knee)  		rand(0.3)    )
				("mesh_break" component(rightarm)  				rand(0.3)    )
				("mesh_break" component(rightfoot)  			rand(0.3)    )
				("mesh_break" component(rightforearm)  			rand(0.3)    )
				("mesh_break" component(righthand)  			rand(0.3)    )
				("mesh_break" component(righthandtoe)  			rand(0.3)    )
				("mesh_break" component(rightleg)  				rand(0.3)    )
				("mesh_break" component(righttoebase)  			rand(0.3)    )
				("mesh_break" component(rightupleg)  			rand(0.3)    )
				("mesh_break" component(rightShoulder)  		rand(0.3)    )
				("mesh_break" component(rightUpLeg_spring)  	rand(0.3)    )
				("mesh_break" component(rightUpLeg1)  			rand(0.3)    )
				("mesh_break" component(rightArmorPlate_Knee)  	rand(0.3)    )
				("mesh_break" component(rightToe1)  			rand(0.3)    )
				("mesh_break" component(rightToe2)  			rand(0.3)    )
				("mesh_break" component(rightToe3)  			rand(0.3)    )
				("mesh_break" component(rightToe4)  			rand(0.3)    )
				(define "arm" ;
					{if volume "arm_tear"
						{if volume "%component"
							{if rand %rand
								{chassis_work 0}
								{tear "piece_small_steel_forward" bone "%component"
									{impulse dir 1 0.5 	cx 1 0.5 cy 1 0.5 no_position}
								}				
							}
						}
					}
				)
				("arm" component(RightToeBase)  		rand(0.5)    )
				("arm" component(RightFoot)  			rand(0.5)    )
				("arm" component(RightLeg)  			rand(0.5)    )
				("arm" component(rightupperleg)  		rand(0.5)    )
				("arm" component(leftToeBase)  			rand(0.5)    )
				("arm" component(leftFoot)  			rand(0.5)    )
				("arm" component(leftLeg)  				rand(0.5)    )
				("arm" component(leftupperleg)  		rand(0.5)    )
				("arm" component(centralToeBase)  		rand(0.5)    )
				("arm" component(centralFoot)  			rand(0.5)    )
				("arm" component(centralLeg)  			rand(0.5)    )
				("arm" component(centralupperleg)  		rand(0.5)    )	
				(define "organ_break" ;
					{if volume "%component"
						{if not work "%component"
							{if rand %rand_destroy
								{components "%component" destroy}
							}
						}
						{if rand %rand
							{components "%component" break}
						}
					}
				)
				("organ_break" component(neck) 				 		rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(head_arm) 				 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(head_joint) 			 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(battery) 				 	rand(0.3) rand_destroy(0.2)  )
				("organ_break" component(battery_r) 			 	rand(0.3) rand_destroy(0.2)  )
				("organ_break" component(battery_l) 				rand(0.3) rand_destroy(0.2)  )
				("organ_break" component(cooling_systems) 			rand(0.3) rand_destroy(0.2)  )
				("organ_break" component(leg_regulator_large_right) rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(leg_regulator_large_left) 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(organs_leg_motor_left) 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(organs_leg_motor_right) 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(organs_engine_drive_left) 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(organs_engine_drive_right) rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(organs_hip_right)  		rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(organs_hip_left)  		rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(hydraulic_knee_right)  	rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(hydraulic_knee_left)  		rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(organs_leg_right)  		rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(organs_leg_left)  		rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(right_engine)  			rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(left_engine)  				rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(body_organ)  				rand(0.1) rand_destroy(0.1)  )
				("organ_break" component(head_organ)  				rand(0.2) rand_destroy(0.2)  )
				("organ_break" component(head_wire)  				rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(visor_head)  				rand(0.3) rand_destroy(0.3)  )
				("organ_break" component(visor_body) 				rand(0.3) rand_destroy(0.3)  )
			}
		}
		{if not effector "obstacle"
			(define "contact_fx"
				{if min_speed 10
					{if material %0 			
						;{spawn %2 }
						{start_sound "hit/generic/%1/5"}
					}
				}
			)
			("contact_fx" args "concrete" 	body  		)
			("contact_fx" args "steel" 		metal_weight   	)
			("contact_fx" args "wood" 		wood  	)
			("contact_fx" args "misc" 		plastic  		)		
			{if rand 0.3 
				{spawn "spheredust_small_short2" }
			else rand 0.1 
				{spawn "spheredust_small_short" }
			}
		}
		{if tagged "combat"
			{if effector "human"
				{with_effector
					{talk "hit"}
					{tags add "bleeding_small_e"}
					{delay 4
						{tags remove "bleeding_small_e"}
					}
					{call "bleeding_small_e"}
					(define "electra_hit"
						{if volume "%volume"
							{burn volume "%volume" fx "electra_hit" time %time fake even_law}
						}
					)
					("electra_hit" volume(body) time(3))
					("electra_hit" volume(head) time(3))
					("electra_hit" volume(foot1r) time(5))
					("electra_hit" volume(foot2r) time(5))
					("electra_hit" volume(foot1l) time(5))
					("electra_hit" volume(foot2l) time(5))
					("electra_hit" volume(hand1r) time(5))
					("electra_hit" volume(hand2r) time(5))
					("electra_hit" volume(hand1l) time(5))
					("electra_hit" volume(hand2l) time(5))
				}
			}
			{if effector "nazi_zombie"
				{with_effector
					(define "electra_hit"
						{if volume "%volume"
							{burn volume "%volume" fx "electra_hit" time %time fake even_law}
						}
					)
					("electra_hit" volume(j_spinelower)	 time(3))
					("electra_hit" volume(j_spine4) 	 time(3))
					("electra_hit" volume(j_head) 		 time(5))
					("electra_hit" volume(j_elbow_le) 	 time(5))
					("electra_hit" volume(j_knee_le) 	 time(5))
					("electra_hit" volume(j_hip_le) 	 time(5))
					("electra_hit" volume(j_shoulder_le) time(5))
					("electra_hit" volume(j_shoulder_ri) time(5))
					("electra_hit" volume(j_knee_ri) 	 time(5))
					("electra_hit" volume(j_hip_ri)  	 time(5))
					{call "death"}
				}
			}
		}
	}
	{on ground_hit 
		{if "exploded"
			;{if rand 0.5
				{tear "piece_small_steel" bone from_volume
					{impulse dir 2 1}
				}
			;}
		}
	}
	{on break ; all
		{call "check_work_organ"}
		{if component "mgun"			
			{tags add "damage_mgun"}
			{if rand 0.5 {call "jammed_gun_skir"}}
			;{weapon_work "mgun" 0}
			{spawn "ex_air_norm" "mgun"}	
			{burn volume "mgun" fx "electric_spark_micro_hit" time 0.4 fake}	
		}
		{if component "shotgun"
			{spawn "break_small_body_robot" "fx_shotgun_break"}	
			{spawn "break_small_body_robot" "recoil"}	
			{tags add "damage_shotgun"}
			{delay 0.5
				{burn volume "fx_burn_shotgun" fx "electric_spark_micro_hit" time 1.4 fake}	
			}
		}
		{if component "sniper"
			{tags add "damage_sniper"}
			{delay 0.1
				{burn volume "wire_sniper" fx "electric_spark_micro_hit" time 1.4 fake}	
			}			
		}
		{if component "rocket"
			{burn volume "rocket00_fx" fx "smoke_heat" time 7 3 fake}	
			{burn volume "rocket01_fx" fx "smoke_heat" time 7 3 fake}	
			{tags add "damage_rocket"}
			{spawn "break_small_body_robot" "rocket"}				
		}
		{if component "missile"
			{view start "smoke_missile"}
			{delay 10 5
				{view pause "smoke_missile"}
			}
			{burn volume "Guided_Missile" fx "smoke_heat" time 7 3 fake}	
			{tags add "damage_missile"}
			{spawn "break_small_body_robot" "rocket"}				
		}
		{if component "lower_arm" ;all tag leg
			{burn volume fx "electric_spark_hit_pierce" time 0.8 fake}			
			{burn volume fx "smoke_destroy" time 0.3 fake}			
		}
		{if component "upper_arm";all tag leg
			{burn volume fx "smoke_destroy" time 0.3 fake}			
			{burn volume fx "electric_spark_hit_pierce" time 0.8 fake}			
		}
		{if component "fuel" ;all
			{call "lose_health"}
			{start_sound "detonation/fireextinguisher/FX_Explosion_FireExtinguisherVapor_02"}	
			;{burn volume "fuel" fx "smoke_gas_trit_burn" time 7 fake}	
			{stop_sound "engine" }
			{delay 8
				{drop_orders}
				{movement_limit normal}
			}
			{delay 13
				{call "drop_speed"}
			}	
			{delay 15
				{drop_orders}
				{movement_limit slow}
			}
			;{spawn "tritium_blast" "fuel"}			
			{spawn "open_tritium" "fuel"}			
			{spawn "open_tritium" "fuel"}			
			{spawn "open_tritium" "fuel"}			
			{spawn "open_tritium" "fuel"}			
			{spawn "open_tritium" "fuel"}			
			{spawn "open_tritium" "fuel"}			
		}
		{if component "head" ;all
			{call "lose_health"}
			{start_sound "generation_zero/electric_spark/"}	
			{burn volume "head_organ" fx "electric_spark_hit" time 0.4 fake}	
		}
		{if component "main_body" ;all
			{call "lose_health"}
			{start_sound "generation_zero/electric_spark/"}	
			{burn volume "body_organ" fx "electric_spark_hit" time 0.4 fake}	
		}
		{if component "back_engine_organ" ;dread harv skir
			{call "lose_health"}
			{spawn "car_destroy_engine_small" "back_engine_organ"}			
			{call "drop_speed"}			
			{start_sound "generation_zero/electric_spark/"}	
			{burn volume "back_engine_organ" fx "electric_spark_hit" time 0.1 fake}	
			{ani_play "break_engine"}
			{delay 2 1
				{start_sound "generation_zero/electric_spark/"}	
			}
		}
		{if component "cpu" ;all
			{call "lose_health"}
			{tags add "broken_cpu"}
			{call "power_drop"}
			{drop_orders}
			{movement_limit slow}	
			{ani_play "break_engine"}
			{burn volume "cpu" fx "component_break_fx" time 2 fake}	
			{burn volume "cpu" fx "smoke_heat" time 7 fake}	
			{fire volume "cpu" radius 0.1 heating 0.4  time 5 follow}
			{spawn "electric_spark_hit_pierce" }
			{view start "cpu_smoke"}
			{delay 20 5
				{view pause "cpu_smoke"}
			}
			{delay 5 2
				{start_sound "generation_zero/electric_spark/"}
				{call "sparks_loop_cpu"}
			}
		}
		{if component "scanner" ;all
			{spawn "electric_spark_hit_pierce" "scanner"}
			{bone cut "visor_ems"}
			{bone cut "visor_head_bone"}
			{burn volume "scanner" fx "smoke_heat" time 2 1 fake}	
		}
		{if component "head_arm" ;all
			{view start "smoke_hips_h"}
			{start_sound "generation_zero/electric_spark/"}
			{ik_enable "Head_ik_h" 0}
			{ik_enable "Head_ik_v" 0}
			{ik_enable "head_ik_v_damage" 1}
			{ik_enable "head_ik_h_damage" 1}
		}
		{if component "head_joint" ;all
			{start_sound "generation_zero/electric_spark/"}
			{ik_enable "Head_ik_h" 0}
			{ik_enable "Head_ik_v" 0}
			{ik_enable "head_ik_v_damage" 1}
			{ik_enable "head_ik_h_damage" 1}
		}
		{if component "body_organ" ;all
			{call "lose_health"}
			{burn volume "body_organ" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "body_organ"}
			{call "power_drop"}
		}
		{if component "head_organ";all
			{call "lose_health"}
			{burn volume "head_organ" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "head_organ"}
			{call "power_drop"}
		}
		{if component "head_wire";all
			{call "power_drop"}
			{burn volume fx "electric_spark_break" time 2 fake}
		}
		{if component "visor_body";all
			{bone cut "visor_body_bone"}
			{bone hide	"light_ems"}
			{spawn "electric_spark_break" "visor_body_bone"}
		}
		{if component "visor_head";all
			{bone cut "visor_head_bone"}
			{spawn "glass_hit_lamp" "visor_head_bone"}					
		}
		(define "mesh_break_armor" ;armor all
			{if component "%component" 
				{burn volume "%component" fx "smoke_preheat" time 2 1 fake}	
			}
		)
		;all armor
		("mesh_break_armor" component(front_armor)  				)
		("mesh_break_armor" component(down_armor)  				)
		("mesh_break_armor" component(armour_head)  				)
		("mesh_break_armor" component(armour_head_upper)  			 )
		("mesh_break_armor" component(armour_knee_left)  			)
		("mesh_break_armor" component(armour_knee_right)  		 )
		("mesh_break_armor" component(armour_shoulder_left)  		   )
		("mesh_break_armor" component(armour_shoulder_right)  	    )
		("mesh_break_armor" component(kneepad_r)  			   )
		("mesh_break_armor" component(kneepad_l)  			   )
		("mesh_break_armor" component(head_top)  				   )
		("mesh_break_armor" component(back_armor)  			  )
		("mesh_break_armor" component(upper_armor_raid)  		  )
		("mesh_break_armor" component(front_armor_raid)  		   )
		("mesh_break_armor" component(armor_head_wire)  		  )
		(define "mesh_break" ;
			{if component "%component" 
				{burn volume "%component" fx "electric_spark_micro_hit" time 2 1 fake}	
				{burn volume "%component" fx "smoke_preheat" time 4 3 fake}	
			}
		)
		("mesh_break" component(hips)  				)
		;all leg
		("mesh_break" component(leftupleg_knee)  		)
		("mesh_break" component(leftarm)  				)
		("mesh_break" component(leftfoot)  				)
		("mesh_break" component(leftforearm)  			)
		("mesh_break" component(lefthand)  				)
		("mesh_break" component(lefthandtoe)  			)
		("mesh_break" component(leftleg)  				)
		("mesh_break" component(lefttoebase)  			)
		("mesh_break" component(leftupleg)  			)
		("mesh_break" component(leftShoulder)  			)
		("mesh_break" component(leftUpLeg_spring)  		)
		("mesh_break" component(leftUpLeg1)  			)
		("mesh_break" component(leftArmorPlate_Knee)  	)
		("mesh_break" component(leftToe1)  				)
		("mesh_break" component(leftToe2)  				)
		("mesh_break" component(leftToe3)  				)
		("mesh_break" component(leftToe4)  				)
		("mesh_break" component(rightupleg_knee)  		)
		("mesh_break" component(rightarm)  				)
		("mesh_break" component(rightfoot)  			)
		("mesh_break" component(rightforearm)  			)
		("mesh_break" component(righthand)  			)
		("mesh_break" component(righthandtoe)  			)
		("mesh_break" component(rightleg)  				)
		("mesh_break" component(righttoebase)  			)
		("mesh_break" component(rightupleg)  			)
		("mesh_break" component(rightShoulder)  		)
		("mesh_break" component(rightUpLeg_spring)  	)
		("mesh_break" component(rightUpLeg1)  			)
		("mesh_break" component(rightArmorPlate_Knee)  	)
		("mesh_break" component(rightToe1)  			)
		("mesh_break" component(rightToe2)  			)
		("mesh_break" component(rightToe3)  			)
		("mesh_break" component(rightToe4)  		    )
	}
	{on destroy ; all
		{if component "main_body"
			{bone hide	"orange_ems"}
			{bone hide	"red_ems"}
		}
		(define "mesh_break_armor" ;armor
			{if component "%component" 
				{tear "piece_small_steel_forward" bone "%component"
					{spawn "electric_spark_hit_pierce" }
					;(define "disable_contact_blast_0")
					;{impulse forward 2 1 dir 5 2}
				}
			}
		)
		;all armor
		("mesh_break_armor" component(front_armor)  			)
		("mesh_break_armor" component(down_armor)  				)
		("mesh_break_armor" component(armour_head)  			)
		("mesh_break_armor" component(armour_head_upper)  		)
		("mesh_break_armor" component(armour_knee_left)  		)
		("mesh_break_armor" component(armour_knee_right)  		)
		("mesh_break_armor" component(armour_shoulder_left)  	)
		("mesh_break_armor" component(armour_shoulder_right)  	)
		("mesh_break_armor" component(kneepad_r)  				)
		("mesh_break_armor" component(kneepad_l)  				)
		("mesh_break_armor" component(head_top)  				)
		("mesh_break_armor" component(back_armor)  				)
		("mesh_break_armor" component(upper_armor_raid)  		)
		("mesh_break_armor" component(front_armor_raid)  		)
		("mesh_break_armor" component(armor_head_wire)  		)
		{if component "missile"
			{if tagged "load_mortar"			
				{spawn "metal_hit_fg_auto" "rocket" x}	
			}
			{view start "burn_missile"}
			{delay 3
				{view stop "burn_missile"}
			}
			{weapon_work "gun" 0}
			{bone hide "rocket"}
			{tags add "destroy_missile"}
			{spawn "brake_component" "rocket" x}	
			{spawn "fireworks_blast_noparticle" "rocket"}
		else component "shotgun"
			{weapon_work "mgun" 0}
			{spawn "break_small_body_robot" "stock_shotgun"}	;break fx
			{tags add "broken_shotgun"}
			{view hide "shell_drop"}
			{view hide "shell_view"}
			(define "mesh_break" 
				{tear "piece_small_steel_forward" bone "%component"
					{spawn "electric_spark_hit_pierce" }
				}
			)
			("mesh_break" component(recoil)  						)
			("mesh_break" component(magazine_shotgun)  				)
			("mesh_break" component(barrel_shotgun)  				)
			("mesh_break" component(rail_shotgun)  					)
		else component "sniper"
			{weapon_work "gun" 0}
			{spawn "break_small_body_robot" "sniper"}	;break fx
			{tags add "broken_sniper"}
			{bone hide "visor_led_01_alarm"}
			{bone hide "visor_led_01_search"}
			{bone hide "visor_led_01_hold"}
			{bone hide "shell_drop_sniper"}	
			{bone hide "sight_ems"}			
			(define "mesh_break" 
				{tear "piece_small_steel_forward" bone "%component"
					{spawn "electric_spark_hit_pierce" }
				}
			)
			("mesh_break" component(magazine_sniper)	)
			("mesh_break" component(barrel_sniper)		)
			("mesh_break" component(visor_sniper)		)
			{delay 0.01
				{tear "piece_small_steel" bone "sniper"
					{spawn "electric_spark_hit_pierce" }
				}
			}
		else component "rocket"
			{weapon_work "gun" 0}
			{spawn "break_small_body_robot" "rocket"}	;break fx
			{tags add "broken_rocket"}
			{bone hide "rocket_00"}
			{bone hide "rocket_01"}
			{bone hide "rocket_02"}
			{bone hide "rocket_03"}		
			{delay 0.01
				{tear "piece_small_steel" bone "rocket"
					{spawn "electric_spark_hit_pierce" }
				}
			}
		else component "mgun"
			{weapon_work "mgun" 0}
			{tags add "destroy_mgun"}
			{spawn "ex_air_norm" "mgun"}
			{tear "piece_small_steel" bone "ammo"
				{impulse dir 1}
			}
			{delay 2 1 {ani_play "wpn_combat_to_idle" }}
		else component "battery"
			{call "lose_health"}
			{tags add "die_battery"}
			{view hide "ems_global"}
			{view stop "ems_global"}
			{spawn "electric_spark_break" "battery"}
			{call "power_drop_permanent"}
			{burn volume "battery" fx "component_break_fx" time 5 fake}	
		else component "organs_leg_motor_left"
			{call "lose_health"}
			{view start "organs_leg_motor_left_burn"}
			{delay 25 
				{tags add "organs_leg_motor_left_burn"}
				{view pause "organs_leg_motor_left_burn"}
			}
			{spawn "destroy_component" "organs_leg_motor_left" } ;destroy_component
			{spawn "electric_spark_break" "organs_leg_motor_left"}
		else component "organs_hip_right"
			{call "lose_health"}
			{burn volume "organs_hip_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_hip_right"}
		else component "organs_hip_left"
			{call "lose_health"}
			{burn volume "organs_hip_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_hip_left"}
		else component "organs_leg_right"
			{call "lose_health"}
			{burn volume "organs_leg_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_leg_right"}
		else component "organs_leg_left"
			{call "lose_health"}
			{burn volume "organs_leg_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_leg_left"}
		else component "body_organ"
			{call "lose_health"}
			{burn volume "body_organ" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "body_organ"}
			{call "power_drop"}
		else component "head_organ"
			{call "lose_health"}
			{burn volume "head_organ" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "head_organ"}
			{call "power_drop"}
		else component "head_wire"
			{call "power_drop"}
			{burn volume fx "electric_spark_break" time 2 fake}
		else component "fuel"
			{call "lose_health"}
			{spawn "break_small_body_robot" "fuel"}	;break fx
			{if rand 0.2
				{fire volume "fuel" radius 0.1 heating 0.5  time 5 follow}
			}
			{burn volume "fuel" fx "smoke_heat" time 10 fake}
			{burn volume "fuel" fx "burn_component_break_small" time 3 fake}
		else component "visor_head"
			{tags add "destroy_visor"}
			{bone cut "visor_head_support_bone"}
			{spawn "glass_hit_lamp" "scanner"}					
		else component "cpu" 
			{call "lose_health"}
			{tags add "destroy_cpu"}
			{tags add "broken_cpu"}
			{call "power_drop"}
			{drop_orders}
			{movement_limit slow}	
			{burn volume "cpu" fx "component_break_fx" time 2 fake}	
			{spawn "electric_spark_hit_pierce" }
			{view start "cpu_burn"}
			{call "electric_spark_small"}
			{delay 30 15
				{view pause "cpu_burn"}
			}
		}
		(define "glass_damaged" ;
			{if component "%component" 
				{bone cut "%component_fx"}
				{bone hide "%component_damage"}
				{spawn "electric_spark_micro_hit" "%component"}	
				{spawn "glass_hit_lamp" "%component"}			
			}
		)
		("glass_damaged" component(head_light_00) )
		("glass_damaged" component(head_light_small_00) )
		("glass_damaged" component(head_light_small_01) )
		("glass_damaged" component(head_light_small_02) )
		("glass_damaged" component(head_light_small_03) )
		("glass_damaged" component(head_light_small_04) )
		("glass_damaged" component(head_light_small_05) )
	}
	{on bullet_hit
		{if tagged "move"
			{call "drop_speed"}
		}		
		{if tagged "idle_enter"
			{tags remove "idle_enter"}
			{call "stop_idle"}
		}
	}
	(define "orientation" ;
		{delay 0.1
			{if not able "exploded"
				{if not stuff "damage_concussion"
					{if min_energy %min_energy
						{if rand %rand
							{if volume "%vol"
								{if not tagged "power_drop"
									{if not tagged "move"
										{if not tagged "replace_position"
											{ani_play "%ani_play"}
										}					
									}
								}
							}
						}
					}
				}
			}
		}
	)
	(define "orientation_hit" ;
		{delay 0.1
			{if not able "exploded"
				{if rand %rand
					{if volume "%vol"
						{if not tagged "power_drop"
							;{if not tagged "move"
								{if not tagged "replace_position"
									{ani_play "%ani_play" %speed }
								}					
							;}
						}
					}
				}
			}
		}
	)
	{on blast ;skir
		(include "blast_all.inc")
		("orientation" vol(front_left_hit)  	ani_play(hit_stumble_45ccw)   rand(0.5)  min_energy(0.5) )
		("orientation" vol(front_right_hit)  	ani_play(hit_stumble_45cw)    rand(0.5)  min_energy(0.5) )
		("orientation" vol(back_left_hit)  		ani_play(hit_stumble_135cw)   rand(0.5)  min_energy(0.5) )
		("orientation" vol(back_right_hit)  	ani_play(hit_stumble_135ccw)  rand(0.5)  min_energy(0.5) )
		{kill_delay "drop"}
		(define "health"
			{if volume "main_organ"
				{if min_energy %energy
					{ani_play "health" %health resume}
					{kill_delay "health"}
					{delay 0.1 "health"
						{ani_stop "health"}
					}
				}
			}
		)		
		("health" energy(20) 				health(+1))
		("health" energy(15) 				health(+0.75))
		("health" energy(10) 				health(+0.6))
		("health" energy(7) 				health(+0.45))
		("health" energy(5) 				health(+0.3))
		("health" energy(3) 				health(+0.2))
		("health" energy(1) 				health(+0.1))
		{if min_energy 7
			{if rand 0.4
				{call "explosion_skir_big"}
			}
		else min_energy 2
			{if volume "main_body"
				{if stuff "rocketlauncher"
					{if rand 0.2
						{if not able "exploded"	
							{spawn "destroy_component" "body_organ"}
							{burn volume "head_organ" fx "burn_component_break_small" time 2 1 fake even_law}
							{burn volume "body_organ" fx "burn_component_break_small" time 2 1 fake even_law}
							{call "explosion_skir"}
						}
					}
				}
			}
		}
	}
	{on pierce ;skir
		(define "health"
			{if volume "main_organ"
				{if stuff "%stuff"
					{ani_play "health" %health resume}
					{kill_delay "health"}
					{delay 0.15 "health"
						{ani_stop "health"}
					}
				}
			}
		)		
		("health" stuff(shell fg) 			health(+0.5) 	)
		("health" stuff(shell ap) 			health(+0.7) 	)			
		("health" stuff(shell) 				health(+1)		)
		("health" stuff(rocketlauncher) 	health(+1)		)
		("health" stuff(zenite cs) 			health(+0.6)		)
		("health" stuff(zenite fg) 			health(+0.3)		)
		("health" stuff(zenite) 			health(+0.4)		)
		("health" stuff(bullet big ap) 		health(+0.45)	)
		("health" stuff(bullet big fg) 		health(+0.2)		)
		("health" stuff(bullet big) 		health(+0.4)		)
		("health" stuff(bullet normal ap) 	health(+0.3)		)
		("health" stuff(bullet normal fg) 	health(+0.2)		)
		("health" stuff(bullet normal) 		health(+0.2)		)
		("health" stuff(bullet small) 		health(+0.1)		)	
		(define "hit_system"
			{if stuff "atgm"
				{call "explosion_skir_big"}
				{impulse dir 5 3 }
			}
			{if stuff %0
				{if volume "organ"
					{if not able "exploded"	
						{spawn "destroy_component" "body_organ"}
						{call "explosion_skir"}
					}
				}
				{if volume "main_body"
					{if rand 0.7
						{call "explosion_skir"}
					else rand 0.2
						{call "explosion_skir_big"}
						{impulse dir 5 3 }				
					}
				}
			}
		)	
		("hit_system" args "rocketlauncher"		)
		("hit_system" args "shell"				)
		(define "hit_system_limbs"		
			{if able "exploded"
				{if volume "limbs"
					{if stuff %0
						{if rand %1
							{tear "piece_small_steel" bone from_volume
								{impulse up 0.5 dir 3 0.5 cx 1 0.5 cy 1 0.5}
							}
						}
					}
				}
			}
		)	
;								tags (0) 		rand (1)	 
		("hit_system_limbs" args "shell"				0.7  		)
		("hit_system_limbs" args "shell_minimum"		0.7  		)
		("hit_system_limbs" args "zenite cs"			0.5  		)
		("hit_system_limbs" args "zenite"				0.3  		)
		("hit_system_limbs" args "bullet big ap"		0.2  		)
		("hit_system_limbs" args "bullet big"			0.1  		)
		("hit_system_limbs" args "bullet normal ap"		0.1  		)
		("hit_system_limbs" args "bullet normal"		0.05 		)
		("hit_system_limbs" args "bullet small"			0.01  		)
		("hit_system_limbs" args "bullet"				0.01  		)
		(define "hit_system_organ"		
			{if volume "organ"
				{if stuff %0
					{if rand %1
						{call "explosion_skir"}
					}
				}
			}
		)	
;								tags (0) 		rand (1)	 
		("hit_system_organ" args "rocketlauncher"		1  		)
		("hit_system_organ" args "shell_minimum"		1  		)
		("hit_system_organ" args "shell"				1  		)
		("hit_system_organ" args "zenite cs"			0.2  		)
		("hit_system_organ" args "zenite"				0.1  		)
		("hit_system_organ" args "sniper"				0.1  		)
		("hit_system_organ" args "bullet big ap"		0.04  		)
		("hit_system_organ" args "bullet big"			0.02  		)
		("hit_system_organ" args "bullet normal ap"		0.025  		)
		("hit_system_organ" args "bullet normal"		0.02 		)
		("hit_system_organ" args "bullet small"			0.01  		)
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
			("stuff_pierce" stuff(shell fg) 			stuff_break(0.8) 	)
			("stuff_pierce" stuff(shell ap) 			stuff_break(1) 		)			
			("stuff_pierce" stuff(shell) 				stuff_break(1)		)
			("stuff_pierce" stuff(rocketlauncher) 		stuff_break(1)		)
			("stuff_pierce" stuff(zenite cs) 			stuff_break(0.7)		)
			("stuff_pierce" stuff(zenite fg) 			stuff_break(0.6)		)
			("stuff_pierce" stuff(zenite) 				stuff_break(0.5)		)
			("stuff_pierce" stuff(bullet big ap) 		stuff_break(0.5)		)
			("stuff_pierce" stuff(bullet big fg) 		stuff_break(0.5)		)
			("stuff_pierce" stuff(bullet big) 			stuff_break(0.4)		)
			("stuff_pierce" stuff(bullet normal ap) 	stuff_break(0.4)	)
			("stuff_pierce" stuff(bullet normal fg) 	stuff_break(0.3)		)
			("stuff_pierce" stuff(bullet normal) 		stuff_break(0.4)		)
			("stuff_pierce" stuff(bullet small) 		stuff_break(0.3)		)
		)		
		("mesh_break" component(hips)  				 				stuff_destroy(0.2)    )
		("mesh_break" component(main_body)  				 		stuff_destroy(0.2)    )
		("mesh_break" component(head)  				 				stuff_destroy(0.2)    )
		("mesh_break" component(cpu)  				 				stuff_destroy(0.5)    )
		("mesh_break" component(engine)  			 				stuff_destroy(0.3)    )
			
		("mesh_break" component(backlegs_mount)  					 stuff_destroy(0.5)    )
		("mesh_break" component(frontlegs_mount)  					 stuff_destroy(0.5)    )
		("mesh_break" component(front_core_panel)  					 stuff_destroy(0.5)    )
		;all armor
		("mesh_break" component(front_armor)  			 			stuff_destroy(0.2))
		("mesh_break" component(down_armor)  			 			stuff_destroy(0.2))
		("mesh_break" component(armour_head)  			 			stuff_destroy(0.2))
		("mesh_break" component(armour_head_upper)  	 			stuff_destroy(0.2))
		("mesh_break" component(armour_knee_left)  		 			stuff_destroy(0.2))
		("mesh_break" component(armour_knee_right)  	 			stuff_destroy(0.2))
		("mesh_break" component(armour_shoulder_left)  	 			stuff_destroy(0.2))
		("mesh_break" component(armour_shoulder_right)   			stuff_destroy(0.2))
		("mesh_break" component(kneepad_r)  			 			stuff_destroy(0.2))
		("mesh_break" component(kneepad_l)  						stuff_destroy(0.2))
		("mesh_break" component(head_top)  				 			stuff_destroy(0.2))
		("mesh_break" component(back_armor)  			 			stuff_destroy(0.2))
		("mesh_break" component(upper_armor_raid)  		 			stuff_destroy(0.2))
		("mesh_break" component(front_armor_raid)  		 			stuff_destroy(0.2))
		("mesh_break" component(armor_head_wire)  		 			stuff_destroy(0.2))
	

;------------------
		
		;all leg
		("mesh_break" component(leftupleg_knee)  	 				stuff_destroy(0.3))
		("mesh_break" component(leftarm)  			 				stuff_destroy(0.3))
		("mesh_break" component(leftfoot)  			 				stuff_destroy(0.3))
		("mesh_break" component(leftforearm)  		 				stuff_destroy(0.3))
		("mesh_break" component(lefthand)  			 				stuff_destroy(0.3))
		("mesh_break" component(lefthandtoe)  		 				stuff_destroy(0.3))
		("mesh_break" component(leftleg)  			 				stuff_destroy(0.3))
		("mesh_break" component(lefttoebase)  		 				stuff_destroy(0.3))
		("mesh_break" component(leftupleg)  		 				stuff_destroy(0.3))
		("mesh_break" component(leftShoulder)  		 				stuff_destroy(0.3))
		("mesh_break" component(leftUpLeg_spring)  	 				stuff_destroy(0.3))
		("mesh_break" component(leftUpLeg1)  		 				stuff_destroy(0.3))
		("mesh_break" component(leftArmorPlate_Knee)   				stuff_destroy(0.3))
		("mesh_break" component(leftToe1)  			 				stuff_destroy(0.3))
		("mesh_break" component(leftToe2)  			 				stuff_destroy(0.3))
		("mesh_break" component(leftToe3)  			 				stuff_destroy(0.3))
		("mesh_break" component(leftToe4)  			 				stuff_destroy(0.3))
		("mesh_break" component(rightupleg_knee)  	 				stuff_destroy(0.3))
		("mesh_break" component(rightarm)  			 				stuff_destroy(0.3))
		("mesh_break" component(rightfoot)  		 				stuff_destroy(0.3))
		("mesh_break" component(rightforearm)  		 				stuff_destroy(0.3))
		("mesh_break" component(righthand)  		 				stuff_destroy(0.3))
		("mesh_break" component(righthandtoe)  		 				stuff_destroy(0.3))
		("mesh_break" component(rightleg)  			 				stuff_destroy(0.3))
		("mesh_break" component(righttoebase)  		 				stuff_destroy(0.3))
		("mesh_break" component(rightupleg)  		 				stuff_destroy(0.3))
		("mesh_break" component(rightShoulder)  	 				stuff_destroy(0.3))
		("mesh_break" component(rightUpLeg_spring)   				stuff_destroy(0.3))
		("mesh_break" component(rightUpLeg1)  		 				stuff_destroy(0.3))
		("mesh_break" component(rightArmorPlate_Knee)   			stuff_destroy(0.3))
		("mesh_break" component(rightToe1)  		 				stuff_destroy(0.3))
		("mesh_break" component(rightToe2)  		 				stuff_destroy(0.3))
		("mesh_break" component(rightToe3)  		 				stuff_destroy(0.3))
		("mesh_break" component(rightToe4)  		 				stuff_destroy(0.3))	
	(include "pierce_all.inc")
	}
	(include "burn_volume.inc")
	{on "head_arm_damage"
		{if rand 0.5
			{if rand 0.2
				{spawn "electric_spark_hit_pierce" "Head_ik_h_damage"}
			}
			{delay 0.5
				{spawn "electric_spark_hit_pierce" "Head_ik_h_damage"}
				{ik_enable "Head_ik_h_damage" 0}
			}
			{delay 1.2 2
				{ik_enable "Head_ik_h_damage" 1}
				{spawn "electric_spark_hit_pierce" "Head_ik_h_damage"}
			}
		}
	}	
	{on fire "alarm_signal"   ;skir base
		;{signal shot 5000}
		{tags add "mgun_alarm_base"}
		{tags add "call_allies"}
		{delay 5
			{tags remove "mgun_alarm_base"}
			{tags remove "call_allies"}
		}
		{if tagged "search"
			{tags remove "search"}
			{tags add "alarm"}
		else tagged "hold"
			{tags remove "hold"}
			{tags add "search"}
		}
		{call "ai_talk_signal"}
		{delay 1 {tags remove "combat_call"}}
	}
	{on fire "attack_melee_charge" ;mgun_melee
		{start_sound "generation_zero/characters/skirmisher/jump"}
		{spawn "spheredust_norm" "basis" }		
		{tags add "jump"}
		{ani_stop "runloop_f" }
		{ani_play "attack_melee_charge_01" 1 }
		{delay 0.5
			{weapon_work "attack_melee_charge" 0}
		}
	}
	{on fire "attack_melee_charge_close" ;mgun_melee_close
		{weapon_work "mgun" 0}
		{delay 2
			{if work "mgun"
				{weapon_work "mgun" 1}
			}
		}
		{tags add "mgun_melee_close"}
		{delay 0.5
			{tags remove "mgun_melee_close"}
		}
		{ani_play "attack_melee_close" 0.8}		
	}
	{on "electric_spark_small_loop_health" 	
		{if tagged "electric_spark_small_loop_health"
			{if rand 0.2
				{spawn "break_small_body_robot" "engine_hatch"}
				{if rand 0.1
					{fire volume "cpu" radius 0.1 heating 1  time 3 follow}					
				}
			else rand 0.2
				{spawn "break_small_body_robot" "body_organ"}
			else rand 0.2
				{spawn "break_small_body_robot" "head_organ"}
			else rand 0.2
				{spawn "component_break_fx" "engine_hatch"}
			else rand 0.2
				{spawn "component_break_fx" "body_organ"}
			else rand 0.2
				{spawn "component_break_fx" "head_organ"}
			else rand 0.2
				{spawn "component_break_fx" "head_arm"}
			}	
		}	
		{delay_effect 4 1 "electric_spark_small_loop_health"}		
	}	
;evs	
	{on animation_event "bullet_drop_view" ;hunter lynx skir skir_shotg_w 
		{view show "shell"}	
		{view show "shell_drop"}	
		{view show "shell_drop_sniper"}	
	}
	{on animation_event "open_bolt_charge" 
		{spawn "open_bolt_charge" "recoil_bone" } ;link sound with bone fix
	}		
	{on animation_event "close_bolt_charge"
		{spawn "close_bolt_charge" "recoil_bone" } ;link sound with bone fix
	}		
	{on animation_event "open_bolt_lmg" ;skir
		{spawn "open_bolt_lmg" "recoil_bone" } ;link sound with bone fix
		;{start_sound "weapon/bolt_move/med/lmg"}	
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
	{on animation_event "20heal" ;all
		{tags add "20heal"}
		{burn volume "cpu" fx "smoke_heat" time 5 fake}	
	}
	{on animation_event "40heal"  ;all	
		{tags add "40heal"}
		{burn volume "cpu" fx "smoke_heat" time 7 fake}	
		{burn volume "bridge" fx "smoke_heat" time 7 fake}	
	}
	{on animation_event "70heal"  ;all
		{call "electric_spark_small_loop_health"}
		{tags add "electric_spark_small_loop_health"}
		{tags add "70heal"}
		{burn volume "cpu" fx "fx_fire_engine_gen" time 2 fake even_law}					
		{burn volume "body_organ" fx "smoke_heat" time 5 fake even_law}					
	}
	{on animation_event "explosion_skir" 
		{call "explosion_skir"}
	}
	{on animation_event "run_pass_to_walk"
		{ani_stop "walkloop_fwd" }
		{tags add "run"}
		{call "move_update_run"}
		{call "jump_allow"}
	}
	{on animation_event "run_swing_to_walk"
		{call "jump_reject"}
		{tags remove "run"}
		{call "move_update_walk"}
	}
	{on animation_event "runloop_f" 
		{if not tagged "jump"
			{if velocity 14	 ;если прибежал
				{call "move_update_run"}
				;{ani_stop "run_swing_to_walk" }
			else velocity 10	
				{ani_play "run_swing_to_walk" }
			}
		}
	}
	{on animation_event "walkstart_f" ; all
		{if not tagged "turn"
			{if tagged "move"
				{call "move_update_f"}
				{call "move_update_walk"}
			else
				{ani_play "walkstop_f" 1}
			}
		}	
	}	
	{on animation_event "walkloop_f" ;skir
		{if not tagged "jump"
			{if velocity 14	;начало бега
				{ani_stop "walkloop_fwd"}
				{ani_play "run_pass_to_walk" }
			else velocity 8	
				{call "move_update_walk"}
				{ani_stop "run_pass_to_walk" }
			else not tagged "move"
				{ani_play "walkstop_f" }
			else 	
				{call "move_update_walk"}
			}
		}
	}	
	{on animation_event "search_idle"
		{tags add "search"}
		{call "ai_talk_signal"}
		{start_sound "generation_zero/characters/skirmisher/search_idle/"}				
	}
	{on animation_event "replace_position_start"
		{tags add "replace_position"}		
		{drop_orders}
		{movement_limit slow}
		{auto_operatable 0}
		{able select 0}
	}
	{on animation_event "replace_position_end"
		{tags remove "replace_position"}
		{if work "fuel"
			{drop_orders}
			{movement_limit fast}
		}
		{if not able "exploded" 
			{auto_operatable 1}
			{able select 1}
			{if tagged "frends"
				{delay 0.1
					{player 0}
				}
			else
				{delay 0.1
					{player 8}
				}
			}
		}
	}
	;-------------------------------------------------------------------
	{on animation_event "foot_skirmisher_r_front"
		{spawn "footstep_hooffront" "footstep_hooffront_r" x terrain_texmod}
		{if rand 0.5
			{spawn "dust_med_skirmisher" "footstep_hooffront_r"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}				
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_skirmisher_r_back"
		{spawn "footstep_hoofback" "footstep_hoofback_r" x terrain_texmod}
		{if rand 0.5
			{spawn "dust_med_skirmisher" "footstep_hoofback_r"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}	
			
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	;-------------------------------------------------------------------

	{on animation_event "foot_skirmisher_l_front"
		{spawn "footstep_hooffront" "footstep_hooffront_l" x terrain_texmod}
		{if rand 0.5
			{spawn "dust_med_skirmisher" "footstep_hooffront_l"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_skirmisher_l_back"
		{spawn "footstep_hoofback" "footstep_hoofback_l" x terrain_texmod}
		{if rand 0.5
			{spawn "dust_med_skirmisher" "footstep_hoofback_l"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	;-------------------------------------------------------------------
	{on animation_event "foot_skirmisher_lf_run_frontdust"
		{spawn "footstep_hooffront" "footstep_hooffront_l" x terrain_texmod}
		{burn volume "leftHandToe" fx "rex_emitters_armor" time 1 fake even_law}
		{spawn "dust_med_skirmisher_land" "footstep_hooffront_l" x}
		{start_sound "generation_zero/characters/skirmisher/move/run/"}	
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_skirmisher_lf_run"
		{spawn "footstep_hooffront" "footstep_hooffront_l" x terrain_texmod}
		{burn volume "leftHandToe" fx "rex_emitters_armor" time 1 fake even_law}
		{spawn "dust_med_skirmisher_run" "footstep_hooffront_l"}
		{start_sound "generation_zero/characters/skirmisher/move/run/"}	
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_skirmisher_lf"
		{spawn "footstep_hooffront" "footstep_hooffront_l" x terrain_texmod}
		{if rand 0.5
			{spawn "dust_med_skirmisher" "footstep_hooffront_l"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	;-------------------------------------------------------------------

	{on animation_event "foot_skirmisher_rf_run_frontdust"
		{spawn "footstep_hooffront" "footstep_hooffront_r" x terrain_texmod}
		{burn volume "RightHandToe" fx "rex_emitters_armor" time 1 fake even_law}
		{spawn "dust_med_skirmisher_land" "footstep_hooffront_r" x}
		{start_sound "generation_zero/characters/skirmisher/move/run/"}	
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_skirmisher_rf_run"
		{spawn "footstep_hooffront" "footstep_hooffront_r" x terrain_texmod}
		{burn volume "RightHandToe" fx "rex_emitters_armor" time 1 fake even_law}
		{spawn "dust_med_skirmisher_run" "footstep_hooffront_r"}
		{start_sound "generation_zero/characters/skirmisher/move/run/"}	
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_skirmisher_rf"
		{spawn "footstep_hooffront" "footstep_hooffront_r" x terrain_texmod}
		{if rand 0.5
			{spawn "dust_med_skirmisher" "footstep_hooffront_r"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	;-------------------------------------------------------------------
	{on animation_event "foot_skirmisher_rb_run"
		{spawn "footstep_hoofback" "footstep_hoofback_r" x terrain_texmod}
		{burn volume "LeftHandToe" fx "rex_emitters_armor" time 1 fake even_law}
		{spawn "dust_med_skirmisher_run" "footstep_hoofback_r"}
		{start_sound "generation_zero/characters/skirmisher/move/run/"}	
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_skirmisher_rb"
		{spawn "footstep_hoofback" "footstep_hoofback_r" x terrain_texmod}
		{if rand 0.3
			{spawn "dust_med_skirmisher" "footstep_hoofback_r"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
				{start_sound "generation_zero/characters/skirmisher/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	;-------------------------------------------------------------------
	{on animation_event "foot_skirmisher_l"
		{if rand 0.3
			{spawn "dust_med_skirmisher" "footstep_hooffront_l"}
		else rand 0.4
			{spawn "dust_med_skirmisher" "footstep_hoofback_l"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/skirmisher/move/%0/"}	
			
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "joint_med_in"
		{call "fx_component_mover"}
		{if tagged "run"
			{start_sound "generation_zero/characters/skirmisher/joint/run/in/"}			
		else
			{start_sound "generation_zero/characters/skirmisher/joint/walk/in/"}			
		}	
	}
	{on animation_event "joint_med_out"
		{call "fx_component_mover"}
		{if tagged "run"
			{start_sound "generation_zero/characters/skirmisher/joint/run/out/"}			
		else
			{start_sound "generation_zero/characters/skirmisher/joint/walk/out/"}			
		}	
	}
	{on animation_event "play_idle_right" ;skir
		{if not tagged "play_idle_right"
			{tags add "play_idle_right"}
		else
			{tags remove "play_idle_right"}
		}
	}
	{on animation_event "play_idle_left" ;skir
		{if not tagged "play_idle_left"
			{tags add "play_idle_left"}
		else
			{tags remove "play_idle_left"}
		}
	}
	{on animation_event "play_idle" ;skir scout harv
		{tags add "play_idle"}
		{tags add "hold"}
		{call "ai_talk_signal"}
	}
	{on animation_event "leave_idle" ;skir scout harv
		{tags remove "play_idle"}
	}
	{on animation_event "scanlines_start" ;skir scout 
		{view start "scanline_light"}		
		{view show "scanline_light"}		
		{ani_play "scan" 1 loop}	
		{bone show "scanlines_2"}
		{bone show "scanlines"}
		{if rand 0.3
			{play_sound "scan-var1" 1 loop}
		else rand 0.3
			{play_sound "scan-var2" 1 loop}
		else 
			{play_sound "scan-var3" 1 loop}
		}
	}
	{on animation_event "scanlines_stop"  ;skir scout
		{view stop "scanline_light"}		
		{view hide "scanline_light"}		
		{ani_stop "scan" }	
		{bone hide "scanlines_2"}
		{bone hide "scanlines"}
		{stop_sound "scan-var1" }
		{stop_sound "scan-var2" }
		{stop_sound "scan-var3" }
	}
	{on animation_event "scanlines_open"  ;skir scout
		{bone show "scanlines_2"}
		{bone show "scanlines"}
	}
	{on animation_event "scanlines_hide"  ;skir scout
		{bone hide "scanlines_2"}
		{bone hide "scanlines"}
	}
	;-----------------------------------------------------------------------------------------------------------------------------------
	{on animation_event "idle_enter" ;skir  harv dread hunter
		{tags add "idle_enter"}
		{delay 5 "idle_enter"
			{call "idle-enter"}
		}
	}
	{on animation_event "idle_exit";skir  harv dread hunter
		{tags remove "idle_enter"}
		{ani_stop "idle_loop"}
		{kill_delay "idle_enter"}
	}
	;-------------------------------------------------------------------
	{on animation_event "jump_close" ;skir
		{start_sound "generation_zero/characters/skirmisher/jump/"}			
		{if rand 0.2
			{spawn "electric_spark_hit" "Spine1"}		
		}
		{delay 0.5
			{if rand 0.3
				{start_sound "generation_zero/characters/skirmisher/combat/skir_combat_call_2ch"}	
				{start_sound "generation_zero/characters/skirmisher/combat_bb/skir_combat_call_bb"}			
			}
		}
	}
	{on animation_event "wpn_idle_to_combat" ;skir
		{start_sound "generation_zero/characters/skirmisher/wpn_set/on/"}
	}
	{on animation_event "wpn_combat_to_idle" ;skir
		{start_sound "generation_zero/characters/skirmisher/wpn_set/off/"}	
	}
	{on animation_event "idle_rand_s" ;skir
		{if rand 0.3
			{start_sound "generation_zero/characters/skirmisher/idle/"}				
		}
	}
	{on animation_event "landed_close";skir
		;{pillar_up}
		{impulse up 0.1}
		{tags remove "jump"}
	}
}

{"skirmisher_mg"
	{on "sound_connect"
		{link_sound "mid"		"weapon/shot/small_arms/acr_sup"}		
		{link_sound "close"		"weapon/shot/small_arms/acr_sup_close"}	
		{link_sound "far"		"weapon/shoot_loud/far/ar_sup"}	
	}
	{on fire "mgun" ; skir
		{play_sound "mid"}
		{play_sound "close"}
		{play_sound "far"}
		{tags add "fire_mgun"}
		{tags add "firing"}
		{tags add "firing_smg"}
		{delay 0.2 
			{tags remove "fire_mgun"}
		}
		{if tagged "damage_mgun" {if rand 0.1 {call "jammed_gun_skir"}}}
		{if tagged "broken_cpu"
			{if rand 0.15
				{burn volume "cpu" fx "smoke_heat" time 2 1 fake even_law}
				{burn volume "electric_spark_hit" fx "smoke_heat" time 0.5 fake even_law}
				{start_sound "/generation_zero/hits/electricity_explo_small/"}
				{delay 0.5 0.2
					{call "weapon_off"}
				}
				{delay 1
					{call "weapon_on"}
				}
			}
		;else
		}
		{view start "fx_main"}
		{delay 0.03
			{view show	"fx_fire_hot"}
			{view start	"fx_fire_hot"}
			{view hide	"fx_main"}
			{view pause	"fx_main"}
		}
		{delay 1.4 0.7
			{view hide	"fx_fire_hot"}
			{view pause	"fx_fire_hot"}
		}
		{delay 3
			{tags remove "firing"}
			{tags remove "firing_smg"}
		}
		{ani_play "wpn_recoil" }		
		{spawn "trace_linear" "foresight" x }
		{spawn "trace_linear" "foresight" x }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "foresight" }
		{tags remove "hold"}
		{tags remove "search"}
		{if not tagged "alarm"
			{tags add "alarm"}
			{call "ai_talk_signal"}
		}			
		{call "stop_idle"}
		{tags remove "idle_enter"}
	}
	{on "reload" overload ;skirmisher_smg
		{if tagged "fire_mgun"
			{if work "mgun"
				{tags add "mgun_r"}
				{weapon_work "mgun" 0}
				{delay 0.1
					{if work "mgun"
						{delay 1
							{ani_play "wpn_reload" 0.5}	
							{tags remove "mgun_r"}
							;{if not tagged "move"
								{weapon_work "mgun" 1}
							;}
						}
					}
				}
			}
		}
	}
	{on animation_event "belt_drop";skir
		{view show "belt_drop"}	
		{tear "belt_drop" bone "belt_drop" copy 
			{impulse forward 2 1 cx -1 1 com}
		}
	}
}

{"skirmisher_sniper"
	{on spawn
		{if work "gun"
			{tags add "sniper_off"}
			;{weapon_work "gun" 0}
		}
	}
	; {on fire "sniper_on" 
		; {tags add "firing_sniper_on"}
		; ;{if work "gun_sniper"
			; {view show	"laser_point_sniper"}
			; {view start	"laser_point_sniper"}
			; {tags add "sniper_on"}
			; {weapon_work "gun" 1}
		; ;}
		; {start_sound "generation_zero/characters/skirmisher/combat/skir_confirmation_02_2ch"}	
		; {start_sound "generation_zero/characters/skirmisher/combat_bb/skir_confirmation_02_bb"}	
		; {ani_play "open_fire" +1 resume }			
		; {if not tagged "move"	
			; {chassis_work 0}
		; }
		; {delay 5
			; {if work "fuel"
				; {chassis_work 1}
			; }
			; {tags remove "firing_sniper_on"}
			; {tags remove "sniper_on"}
			; ;{weapon_work "gun" 0}
			; {view hide	"laser_point_sniper"}
			; {view pause	"laser_point_sniper"}
		; }
	; }
	{on fire "gun"
		{ani_play "recoil" }		
		{spawn "trace_linear" "foresight" x }
		{spawn "trace_linear" "foresight" x }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "foresight" }
		{tags add "firing_sniper"}
		{if tagged "damage_sniper" {if rand 0.1 {call "jammed_gun_skir"}}}
		{if tagged "broken_cpu"
			{if rand 0.15
				{burn volume "cpu" fx "smoke_heat" time 2 1 fake even_law}
				{burn volume "electric_spark_hit" fx "smoke_heat" time 0.5 fake even_law}
				{start_sound "/generation_zero/hits/electricity_explo_small/"}
				{delay 0.5 0.2
					{call "weapon_off"}
				}
				{delay 1
					{call "weapon_on"}
				}
			}
		;else
		}
		;{weapon_work "sniper_on" 1}
		{view start "fx_main"}
		{delay 0.03 "fire"
			{view show	"fx_fire_hot"}
			{view start	"fx_fire_hot"}
			{view hide	"fx_main"}
			{view pause	"fx_main"}
		}
		{delay 1.4 0.7 "fire_hot"
			{tags remove "firing_sniper"}
			{view hide	"fx_fire_hot"}
			{view pause	"fx_fire_hot"}
		}
		{tags add "firing"}
		{start_sound "weapon/shoot_loud/far/sniper_sup"}	
		{start_sound "weapon/shoot_loud/close/sniper_sup"}	
		{delay 3 "firing"
			{ani_play "open_fire" -1 }			
			{if work "fuel"
				{chassis_work 1}
			}
			{tags remove "firing"}
		}
		{tags add "alarm"}
		{tags remove "hold"}
		{tags remove "search"}
		{call "ai_talk_signal"}
		;{call "stop_all_ani"}
		{call "stop_idle"}
		{tags remove "idle_enter"}
	}
	{on "reload" overload ;skirmisher_sniper
		{if tagged "firing_sniper"
			{if work "gun"
				{tags add "sniper_r"}
				{weapon_work "gun" 0}
				{delay 0.5
					{if work "gun"
						{ani_play "charge" }	
						{delay 1
							{tags remove "sniper_r"}
							{if not tagged "move"
								{weapon_work "gun" 1}
							}
						}
					}
				}
			}
		}
	}
	{on animation_event "clear_casing_sniper" ;skir sniper
		{spawn "shell_eject_shell12" "j_recoil" }	;link sound with bone fix
		{tear "shell_drop_12_55" bone "shell_drop" copy ;slicer_tail
			{impulse forward 0.6 cx -0.1 0.1 com  }
		}
		{delay 0
			{view hide "shell_drop"}	
		}
	}
	{on animation_event "bolt_forward";skir sniper
		{spawn "raise_first_bolt_forward" "j_recoil" }	;link sound with bone fix
	}		
	{on animation_event "bolt_close";skir sniper
		{spawn "raise_first_boltclose_01" "j_recoil" }	;link sound with bone fix
	}		
}



{"skirmisher_shotgun"
	{on fire "mgun" overload ; skir_shotgin
		{with_effector
			{tags remove "first_load"}
			{call "fire"}
		}
		; {if tagged "break_weapon"
			; {if rand 0.05
				; {call "destroy_weapon"}
			; }
			; {if rand 0.2
				; {spawn "clear_weapon" "recoil" }	
			; }
		; else tagged "destroy_weapon"
			; {call "destroy_weapon"}
		; }
		{ani_play "wpn_recoil" }		
		{spawn "distant_small" "RightWeaponBase" }
		{tags add "firing"}
		{tags add "firing_shotgun"}
		{tags add "alarm"}
		{tags remove "hold"}
		{tags remove "search"}
		{call "stop_idle"}
		{tags remove "idle_enter"}
		{if tagged "damage_mgun" {if rand 0.1 {call "jammed_gun_skir"}}}
		{if tagged "broken_cpu"
			{if rand 0.15
				{burn volume "cpu" fx "smoke_heat" time 2 1 fake even_law}
				{burn volume "electric_spark_hit" fx "smoke_heat" time 0.5 fake even_law}
				{start_sound "/generation_zero/hits/electricity_explo_small/"}
				{delay 0.5 0.2
					{call "weapon_off"}
				}
				{delay 1
					{call "weapon_on"}
				}
			}
		;else
		}
		{delay 2 "firing"
			{tags remove "firing"}
			{tags remove "firing_shotgun"}
		}
	}
	{on "reload" overload ;skirmisher_shotgun
		{if tagged "firing_shotgun"
			{if work "shotgun"
				{with_effector
					{call "reload"}
				}
				{tags add "mgun_r"}
				{weapon_work "mgun" 0}
				{delay 0.1
					{if work "shotgun"
						{delay 1
							{tags remove "mgun_r"}
							{if not tagged "move"
								{weapon_work "mgun" 1}
							}
						}
					}
				}
			}
		}
	}
	{on animation_event "bullet_drop_view" ;hunter lynx skir skir_shotg_w 
		{view show "shell_drop"}	
	}
	{on animation_event "open_bolt_heavy"
		{spawn "open_bolt_heavy" "j_recoil_sniper" } ;link sound with bone fix
		{spawn "open_bolt_heavy" "recoil_bone" } ;link sound with bone fix		
		;{start_sound "weapon/bolt_move/heavy/"}	
	}		
	{on animation_event "clear_casing_12x55_fast" ;hunter skir shotgun
		{spawn "shell_eject_shell12" "recoil" }	;link sound with bone fix
		;{start_sound "weapon/shell_eject/shell12"}	
		{tear "shell_drop_12_55" bone "shell_drop" copy ;slicer_tail
			{impulse forward 5 cx -0.2 0.2 com  }
		}
		{delay 0
			{view hide "shell_drop"}	
		}
	}
}

{"skirmisher_mortar"
	{on fire "mgun" overload ; skir_mortar
		{with_effector
			{tags remove "first_load"}
			{call "fire"}
		}
		{tags add "firing"}
		{tags add "firing_mortar"}
		{tags add "alarm"}
		{tags remove "hold"}
		{tags remove "search"}
		{call "stop_idle"}
		{tags remove "idle_enter"}
		{if tagged "damage_mgun" {if rand 0.1 {call "jammed_gun_skir"}}}
		{if tagged "broken_cpu"
			{if rand 0.15
				{burn volume "cpu" fx "smoke_heat" time 2 1 fake even_law}
				{burn volume "electric_spark_hit" fx "smoke_heat" time 0.5 fake even_law}
				{start_sound "/generation_zero/hits/electricity_explo_small/"}
				{delay 0.5 0.2
					{call "weapon_off"}
				}
				{delay 1
					{call "weapon_on"}
				}
			}
		;else
		}
		{delay 2 "firing"
			{tags remove "firing"}
			{tags remove "firing_mortar"}
		}
	}
	{on "reload" overload ;skirmisher_shotgun
		{if tagged "firing_mortar"
			{if work "mortar"
				{with_effector
					{call "reload"}
				}
				{tags add "mortar_r"}
				{weapon_work "mgun" 0}
				{delay 0.1
					{if work "mortar"
						{delay 1
							{tags remove "mortar_r"}
							{if not tagged "move"
								{weapon_work "mgun" 1}
							}
						}
					}
				}
			}
		}
	}
}


{"skirmisher_ags"
	{on fire "mgun" overload ; skir
		{with_effector
			{tags remove "first_load"}
			{call "fire"}
		}
		{ani_play "wpn_recoil" }		
		{tags add "firing"}
		{tags add "firing_ags"}
		{tags add "alarm"}
		{tags remove "hold"}
		{tags remove "search"}
		{call "stop_idle"}
		{tags remove "idle_enter"}
		{start_sound "weapon/shoot_loud/far/shotgun"}	
		{if tagged "damage_mgun" {if rand 0.1 {call "jammed_gun_skir"}}}
		{if tagged "broken_cpu"
			{if rand 0.15
				{burn volume "cpu" fx "smoke_heat" time 2 1 fake even_law}
				{burn volume "electric_spark_hit" fx "smoke_heat" time 0.5 fake even_law}
				{start_sound "/generation_zero/hits/electricity_explo_small/"}
				{delay 0.5 0.2
					{call "weapon_off"}
				}
				{delay 1
					{call "weapon_on"}
				}
			}
		;else
		}
		{delay 2 "firing"
			{chassis_work 1}			
			{tags remove "firing"}
			{tags remove "firing_ags"}
		}
	}
	{on "reload" overload ;skirmisher_shotgun
		{if tagged "firing_ags"
			;{if work "shotgun"
				{with_effector
					{call "reload"}
				}
				{tags add "mgun_r"}
				{weapon_work "mgun" 0}
				{delay 0.1
					{if work "ags"
						{delay 1
							{tags remove "mgun_r"}
							{if not tagged "move"
								{weapon_work "mgun" 1}
							}
						}
					}
				}
			;}
		}
	}
}

{"skirmisher_rocket"
	{on spawn
		{if work "mgun"
			{tags add "load_mortar"}
		}
	}
	{on "weapon_warning"
		{if not tagged "drive_hor"
			{tags add "drive_hor"}
			{start_sound "generation_zero/characters/mech_lr_pneu/start/"}	
		}
		{kill_delay "laser_point"}
		{delay 1  "laser_point"
			{tags remove "drive_hor"}
		}
		{drop_orders}
		{movement_limit slow}
		; {delay 0.1
			; {drop_orders}
		; }		
		{delay 2
			{call "weapon_on"}
		}							
		{if tagged "load_mortar"
			{tags add "alarm"}
			{call "ai_talk_signal"}
			{if not tagged "combat_call"
				{tags add "combat_call"}
				{if rand 0.3
					{start_sound "generation_zero/characters/skirmisher/combat/skir_confirmation_01_2ch"}	
					{start_sound "generation_zero/characters/skirmisher/combat_bb/skir_confirmation_01_bb"}	
				else rand 0.2
					{start_sound "generation_zero/characters/skirmisher/combat/skir_confirmation_02_2ch"}	
					{start_sound "generation_zero/characters/skirmisher/combat_bb/skir_confirmation_02_bb"}	
				else 
					{start_sound "generation_zero/characters/skirmisher/combat/skir_combat_call_2ch"}	
					{start_sound "generation_zero/characters/skirmisher/combat_bb/skir_combat_call_bb"}			
				}
			}
			{delay 2 {tags remove "combat_call"}}
			{bone show "shoot_alarm_ems"}
			{bone hide "shoot_search_ems"}
			{bone hide "shoot_hold_ems"}
			{bone show "laser_point"}
			{view start "laser_point"}
			{view show "laser_point"}
			{delay 2 "laser_point"
				{bone hide "shoot_alarm_ems"}
				{bone show "shoot_search_ems"}
				{bone hide "laser_point"}
				{view hide	"laser_point"}
				{view pause	"laser_point"}
			}
			{delay 3.5 "laser_point"
				{bone show "shoot_hold_ems"}
				{bone hide "shoot_search_ems"}			
			}
		}		
	}
	{on "rpg_weapon_warning" 
		{if not able "exploded"		
			{if not tagged "deploy_smoke"
				{tags add "deploy_smoke"}
				{start_sound "generation_zero/characters/skirmisher/combat/skir_confirmation_01_2ch"}	
				{start_sound "generation_zero/characters/skirmisher/combat_bb/skir_confirmation_01_bb"}	
				{start_sound "detonation/firework/"}	
				{spawn "smoke_screen_blast_sm" "body_organ"}
				{delay 90
					{tags remove "deploy_smoke"}
				}
			}
		}
	}
	{on fire "mgun" overload ; rocket
		{tags add "fire_rocketlauncher"}
		{if tagged "frends"
			{with_effector
				{tags add "frends"}
				{tags remove "first_load"}
				{call "fire"}
			}
		else
			{with_effector
				{tags remove "first_load"}
				{call "fire"}
			}
		}
		{if tagged "damage_mgun" {if rand 0.1 {call "jammed_gun_skir"}}}
		{if tagged "broken_cpu"
			{if rand 0.15
				{burn volume "cpu" fx "smoke_heat" time 2 1 fake even_law}
				{burn volume "electric_spark_hit" fx "smoke_heat" time 0.5 fake even_law}
				{start_sound "/generation_zero/hits/electricity_explo_small/"}
				{delay 0.5 0.2
					{call "weapon_off"}
				}
				{delay 1
					{call "weapon_on"}
				}
			}
		;else
		}
		;{spawn "rpg_shot_small" "fxshot" x}
		{tags add "firing"}
		{delay 2 "firing"
			{tags remove "firing"}
		}
		;{ani_play "wpn_recoil" }		
		{tags add "alarm"}
		{tags remove "hold"}
		{tags remove "search"}
		;{call "stop_all_ani"}
		{call "stop_idle"}
		;{chassis_work 0}
		{tags remove "idle_enter"}
	}
	{on "reload" ;skirmisher_rocket
		{if tagged "fire_rocketlauncher"
			{if work "mgun"
				{tags remove "fire_rocketlauncher"}
				{tags add "load_mortar"}
				{with_effector
					{call "reload"}
				}
				{tags add "mgun_r"}
				{weapon_work "mgun" 0}
				{delay 0.1
					{if work "mgun"
						{delay 1
							{tags remove "mgun_r"}
							{if not tagged "move"
								{weapon_work "mgun" 1}
							}
						}
					}
				}
			}
		}
	}
	{on "weapon_off" overload; skir_rocket
		{kill_delay "main_gun"}
		{if work "fuel"
			{chassis_work 1}
			{drop_orders}
			{movement_limit fast}
		}
		{if tagged "weapon_active"
			{if work "mgun"
				{weapon_work "mgun" 0}
				{tags remove "weapon_active"}
				{ani_play "wpn_combat_to_idle" 0.5 }					
			}
		}
	}
	{on "weapon_on" overload ; skir_rocket
		{if not tagged "weapon_active"
			{kill_delay "main_gun" }		
			{if not tagged "destroy_mgun"
				{tags add "weapon_active"}
				{chassis_work 0}
				{ani_play "wpn_idle_to_combat" 0.5}					
				{delay 0.3 "main_gun"
					{if work "mgun"
						{weapon_work "mgun" 1}
					}
					{delay 8 "main_gun"
						{if not tagged "destroy_mgun"
							{if tagged "damage_mgun" {if rand 0.5 {call "jammed_gun_skir"}}}
							{if work "fuel"
								{drop_orders}
								{movement_limit fast}
								{chassis_work 1}
							}
						}
					}
				}
			}
		}
	}
}


