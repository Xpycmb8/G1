{"harvester_base"
	{inflammation_time 40}
	{on spawn
		{link_sound "engine" 	"generation_zero/characters/dreadnought/engine/machine_other_engine_02"}
		{link_sound "engine_hiss" 	"generation_zero/characters/dreadnought/engine/machine_whine_08_2ch"}
		{link_sound "power_up" 		"generation_zero/characters/dreadnought/power_up/drea_concussion_riser_01"}
		{delay 0.1
			{if not "exploded"
				{if not "engine_started"
					{set "engine_started" 1}
					{if tagged "frends"
						{player 0}
					else
						{player 8}
					}
					{if not tagged "started"
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
		{add_view 	"scanline_light" 						"scanline_light" "scanlines_fx"}
		{add_view 	"scanline_burn" 						"scanline_light" "scanlines2_fx_bone"}
		{add_view 	"scanline_burn" 						"scanline_light" "scanlines_fx_bone"}
		{add_view 	"close_attack_light" 					"close_attack_harvest" "visor_body_bone"}
		{add_view 	"yellow_ems" 								"ems_global_search" "head_ems_bone"}
		{add_view 	"yellow_light" 								"ems_global" "head_light_small_00_fx"}
		{add_view 	"yellow_light" 								"ems_global" "head_light_small_01_fx"}
		{add_view 	"yellow_light" 								"ems_global" "head_light_small_02_fx"}
		{add_view 	"headlight_led6000k_med" 					"ems_global" "headlight_l"}
		{add_view 	"headlight_led6000k_med" 					"ems_global" "headlight_r"}
		{add_view 	"headlight_led6000k_med" 					"ems_global" "head_light_00_fx"}
		
		{add_view 	"smoke_gas_drop_drop" 		"gas_drop_l" 	"gasdrop_socket_l_00"}
		{add_view 	"smoke_gas_drop_drop" 		"gas_drop_l" 	"gasdrop_socket_l_01"}
		{add_view 	"smoke_gas_drop_drop" 		"gas_drop_l" 	"gasdrop_socket_l_02"}
		{add_view 	"smoke_gas_drop_drop" 		"gas_drop_l" 	"gasdrop_socket_l_03"}
		{add_view 	"smoke_gas_drop_drop" 		"gas_drop_l" 	"gasdrop_socket_l_04"}
		
		
		{add_view 	"smoke_gas_drop_drop" 		"gas_drop_r" 	"gasdrop_socket_r_00"}
		{add_view 	"smoke_gas_drop_drop" 		"gas_drop_r" 	"gasdrop_socket_r_01"}
		{add_view 	"smoke_gas_drop_drop" 		"gas_drop_r" 	"gasdrop_socket_r_02"}
		{add_view 	"smoke_gas_drop_drop" 		"gas_drop_r" 	"gasdrop_socket_r_03"}
		{add_view 	"smoke_gas_drop_drop" 		"gas_drop_r" 	"gasdrop_socket_r_04"}

		{add_view 	"smoke_drop_hv" 		"smoke_drop_l" 	"gasdrop_socket_l_00"}
		{add_view 	"smoke_drop_hv" 		"smoke_drop_l" 	"gasdrop_socket_l_01"}
		{add_view 	"smoke_drop_hv" 		"smoke_drop_l" 	"gasdrop_socket_l_02"}
		{add_view 	"smoke_drop_hv" 		"smoke_drop_l" 	"gasdrop_socket_l_03"}
		{add_view 	"smoke_drop_hv" 		"smoke_drop_l" 	"gasdrop_socket_l_04"}
		
		
		{add_view 	"smoke_drop_hv" 		"smoke_drop_r" 	"gasdrop_socket_r_00"}
		{add_view 	"smoke_drop_hv" 		"smoke_drop_r" 	"gasdrop_socket_r_01"}
		{add_view 	"smoke_drop_hv" 		"smoke_drop_r" 	"gasdrop_socket_r_02"}
		{add_view 	"smoke_drop_hv" 		"smoke_drop_r" 	"gasdrop_socket_r_03"}
		{add_view 	"smoke_drop_hv" 		"smoke_drop_r" 	"gasdrop_socket_r_04"}

		{add_view 	"rpg_shot_small" 										"fx_muzzle_rpg_l" "fx_shoot_missilelauncher_l"} ;harvest
		{add_view 	"rpg_shot_small" 										"fx_muzzle_rpg_r" "fx_shoot_missilelauncher_r"} ;harvest
		{add_view 	"laser_sight_add_guided_rocket" 						"laser_point_l" "fx_laser_point_missilelauncher_l"} ;harvest
		{add_view 	"laser_sight_guided_rocket" 							"laser_point_l" "fx_laser_point_missilelauncher_l"} ;harvest

		{add_view 	"laser_sight_add_guided_rocket" 						"laser_point_r" "fx_laser_point_missilelauncher_r"} ;harvest
		{add_view 	"laser_sight_guided_rocket" 							"laser_point_r" "fx_laser_point_missilelauncher_r"} ;harvest

		{add_view 	"rpg_shot_small" 				"missile_r_08"  		"shooter_r_fx_08"}
		{add_view 	"rpg_shot_small" 				"missile_r_07"  		"shooter_r_fx_07"}
		{add_view 	"rpg_shot_small" 				"missile_r_06"  		"shooter_r_fx_06"}
		{add_view 	"rpg_shot_small" 				"missile_r_05"  		"shooter_r_fx_05"}
		{add_view 	"rpg_shot_small" 				"missile_r_04"  		"shooter_r_fx_04"}
		{add_view 	"rpg_shot_small" 				"missile_r_03"  		"shooter_r_fx_03"}
		{add_view 	"rpg_shot_small" 				"missile_r_02"  		"shooter_r_fx_02"}
		{add_view 	"rpg_shot_small" 				"missile_r_01"  		"shooter_r_fx_01"}
		{add_view 	"rpg_shot_small" 				"missile_r_00"  		"shooter_r_fx_00"}
		{add_view 	"rpg_shot_small" 				"missile_l_08"  		"shooter_l_fx_08"}
		{add_view 	"rpg_shot_small" 				"missile_l_07"  		"shooter_l_fx_07"}
		{add_view 	"rpg_shot_small" 				"missile_l_06"  		"shooter_l_fx_06"}
		{add_view 	"rpg_shot_small" 				"missile_l_05"  		"shooter_l_fx_05"}
		{add_view 	"rpg_shot_small" 				"missile_l_04"  		"shooter_l_fx_04"}
		{add_view 	"rpg_shot_small" 				"missile_l_03"  		"shooter_l_fx_03"}
		{add_view 	"rpg_shot_small" 				"missile_l_02"  		"shooter_l_fx_02"}
		{add_view 	"rpg_shot_small" 				"missile_l_01"  		"shooter_l_fx_01"}
		{add_view 	"rpg_shot_small" 				"missile_l_00"  		"shooter_l_fx_00"}

		;burn_element
		{add_view 	"burn_element_cpu" 			"cpu_burn" "cpu"}
		{add_view 	"smoke_element_cpu" 		"cpu_smoke" "cpu"}

		{add_view 	"burn_element" 			"burn_missile" "foresight_gun"}
		{add_view 	"burn_element" 			"burn_missile" "foresight_gun"}
		
		{add_view 	"burn_element" 			"burn_missile_r" "Foresight_rocket_r"}
		{add_view 	"burn_element" 			"burn_missile_l" "Foresight_rocket_l"}
		{add_view 	"smoke_heat" 			"smoke_missile_r" "Foresight_rocket_r"}
		{add_view 	"smoke_heat" 			"smoke_missile_l" "Foresight_rocket_l"}
		
		{add_view 	"burn_element" 			"smoke_hips_h" "H_drive"}
		{add_view 	"burn_element" 			"smoke_hips_v" "V_drive"}
		
		
		{add_view 	"smoke_barrel_small" 					"fx_fall_l" "LeftCableHipsSM"}
		{add_view 	"smoke_barrel_small" 					"fx_fall_r" "RightCableHipsSM"}

		{add_view 	"burn_element" 					"front_hatch_r_destroy" "front_hatch_r"}
		{add_view 	"burn_element" 					"front_hatch_l_destroy" "front_hatch_l"}

		{add_view 	"smoke_element_cpu" 			"front_hatch_r_break" "front_hatch_r"}
		{add_view 	"smoke_element_cpu" 			"front_hatch_l_break" "front_hatch_l"}

		{add_view 	"burn_element" 					"back_hatch_r_destroy" "back_hatch_r"}
		{add_view 	"burn_element" 					"back_hatch_l_destroy" "back_hatch_l"}

		{add_view 	"smoke_element_cpu" 			"back_hatch_r_break" "back_hatch_r"}
		{add_view 	"smoke_element_cpu" 			"back_hatch_l_break" "back_hatch_l"}

		{view hide	"close_attack_harvest"}
		{view pause	"close_attack_harvest"}
		{view hide	"scanline_light"}
		{view pause	"scanline_light"}

		{delay 1
			{if tagged "frends"
				{player 0}
			else tagged "rus"
				{player 9}
			else
				{player 8}
			}
		}
		{tags add "hold"}
		{tags add "machine"}
		{tags add "harvester_base"}
		{call "led_ems_connect"}
		{call "led_light_connect"}
		{call "radio_connect"}
		{call "sound_connect"}
		{call "fire_connect"}
		
		
		{set "engine_started" 0}
		{set "stop" 1}
		{delay 15 5 "idle_enter"
			{tags add "idle_enter"}
			{call "idle-enter"}
		}		
	}
	{on "fire_connect"
		(define "burn_fx_component_cylplate" ;dread harv
			{add_view 	"burn_component_break_small" "%component_burn" 	"%component"}
			{view hide	"%component_burn"}
			{view pause	"%component_burn"}
		)
		("burn_fx_component_cylplate" component(RightUpLeg_cylplate_01))
		("burn_fx_component_cylplate" component(RightUpLeg_cylplate_02))
		("burn_fx_component_cylplate" component(rightUpLeg_cylplate_03))
		("burn_fx_component_cylplate" component(RightUpLeg1_cylplate_01))
		("burn_fx_component_cylplate" component(RightUpLeg1_cylplate_02))
		("burn_fx_component_cylplate" component(RightFoot_cylplate_01))
		("burn_fx_component_cylplate" component(RightFoot_cylplate_02))
		("burn_fx_component_cylplate" component(rightArm_cylplate_01))
		("burn_fx_component_cylplate" component(rightArm_cylplate_02))
		("burn_fx_component_cylplate" component(rightArm_cylplate_03))
		("burn_fx_component_cylplate" component(rightArm_cylplate_04))
		("burn_fx_component_cylplate" component(rightShoulder_cylplate_01))
		("burn_fx_component_cylplate" component(leftUpLeg_cylplate_01))
		("burn_fx_component_cylplate" component(leftUpLeg_cylplate_02))
		("burn_fx_component_cylplate" component(leftUpLeg_cylplate_03))
		("burn_fx_component_cylplate" component(leftUpLeg1_cylplate_01))
		("burn_fx_component_cylplate" component(leftUpLeg1_cylplate_02))
		("burn_fx_component_cylplate" component(leftFoot_cylplate_01))
		("burn_fx_component_cylplate" component(leftFoot_cylplate_02))
		("burn_fx_component_cylplate" component(leftArm_cylplate_01))
		("burn_fx_component_cylplate" component(leftArm_cylplate_02))
		("burn_fx_component_cylplate" component(leftArm_cylplate_03))
		("burn_fx_component_cylplate" component(leftArm_cylplate_04))
		("burn_fx_component_cylplate" component(leftShoulder_cylplate_01))
		(define "burn_fx_component"
			{add_view 	"burn_component_break_small" "%comp_burn" 	"%comp"}
			{view hide	"%comp_burn"}
			{view pause	"%comp_burn"}
		)
		("burn_fx_component"  comp(leg_regulator_large_right)				 	)
		("burn_fx_component"  comp(leg_regulator_large_left) 			    	)
		("burn_fx_component"  comp(cooling_systems)								)
		("burn_fx_component"  comp(battery_l) 									)
		("burn_fx_component"  comp(battery_r)  									)
		("burn_fx_component"  comp(battery) 									)
		("burn_fx_component"  comp(leg_motor_left)  							)
		("burn_fx_component"  comp(leg_motor_right)  							)
	}
	{on "led_ems_connect"
		(define "leds_ems_global_small"
			{add_view 	"yellow_ems_small" 	"ems_global_search" 	"%vis_search"}
			{add_view 	"red_ems_small" 	"ems_global_alarm" 		"%vis_alarm"}
			{add_view 	"hold_ems_small" 	"ems_global_hold" 		"%vis_hold"}
			{bone show "%vis_hold"}
			{bone hide "%vis_alarm"}
			{bone hide "%vis_search"}
			{view show	"ems_global_hold"}
			{view start	"ems_global_hold"}
			{view hide	"ems_global_alarm"}
			{view pause	"ems_global_alarm"}
			{view hide	"ems_global_search"}
			{view pause	"ems_global_search"}
		)
		("leds_ems_global_small"  vis(body_ems_00)  )
		("leds_ems_global_small"  vis(head_light_ems_00) )
		("leds_ems_global_small"  vis(visor_body) )
	}
	{on "sound_connect"
		{link_sound "stop_gas" "generation_zero/characters/gas_drop/smoke_hiss_end"}
		{link_sound "loop_gas" "generation_zero/characters/gas_drop/smoke_hiss_lp"}
		{link_sound "start_gas" "generation_zero/characters/gas_drop/smoke_hiss_start"}
		{link_sound "concussion_riser" "generation_zero/characters/dreadnought/concussion/drea_concussion_riser"}
		
		{link_sound "scan-var1" "generation_zero/characters/skirmisher/scan/scan_loop_02"}
		{link_sound "scan-var2" "generation_zero/characters/skirmisher/scan/scan_loop_02"}
		{link_sound "scan-var3" "generation_zero/characters/skirmisher/scan/scan_loop_02"}
		
		{link_sound "power_down_bb" "generation_zero/characters/restart_clunk/power/bb/emp_01_shutdown_bb"}
		{link_sound "power_down" "generation_zero/characters/restart_clunk/power/dir/emp_01_shutdown_dir"}
	
		{link_sound "power_up_bb" "generation_zero/characters/restart_clunk/power/bb/emp_01_startup_bb"}
		{link_sound "power_up" "generation_zero/characters/restart_clunk/power/dir/emp_01_startup_dir"}
	}
	{on "led_light_connect"
		(define "leds_ems_global"
			{add_view 	"yellow_ems_big" 	"ems_global_search" 	"%vis_search"}
			{add_view 	"red_ems_big" 		"ems_global_alarm" 		"%vis_alarm"}
			{add_view 	"hold_ems_big" 		"ems_global_hold" 		"%vis_hold"}
			{view show	"ems_global_hold"}
			{view start	"ems_global_hold"}
			{view hide	"ems_global_alarm"}
			{view pause	"ems_global_alarm"}
			{view hide	"ems_global_search"}
			{view pause	"ems_global_search"}
		)
		("leds_ems_global"  vis(body_ems_00) )
		
	}
	{on "ai_talk_signal" 
		{delay 0.2
			{if tagged "alarm"
				{tags remove "search"}
				{tags remove "hold"}
				{if not tagged "alarm_call"
					{tags add "alarm_call"}
					{if rand 0.5
						{spawn "dread_combat_ver2" "head"}
					else 
						{spawn "dread_combat_ver1" "head"}
					}
				}
				{delay 5 {tags remove "alarm_call"}}
				;{burn volume "visor_ems" fx "red_burn" fake}
				{call "show_alarm"}
			else tagged "search"
				{tags remove "alarm"}
				{tags remove "hold"}
				{if not tagged "search_call"
					{tags add "search_call"}
					{if rand 0.3
						{spawn "dread_search_ver7" "head"}
					else rand 0.3
						{spawn "dread_search_ver6" "head"}
					else rand 0.3
						{spawn "dread_search_ver5" "head"}
					else rand 0.3
						{spawn "dread_search_ver4" "head"}
					else rand 0.3
						{spawn "dread_search_ver3" "head"}
					else rand 0.3
						{spawn "dread_search_ver2" "head"}
					else 
						{spawn "dread_search_ver1" "head"}
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
		("leds_ems"  vis(body_ems_00)	)
		("leds_ems"  vis(head_light_ems_00)	)
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
		)
		("leds_ems_connect")
	}	
	{on "check_work_gun"
		{if not tagged "damage_missile_r"
			{weapon_work "gun_r" 1}
		else
			{weapon_work "gun_r" 0}
		}
		{if not tagged "damage_missile_l"
			{weapon_work "gun_l" 1}
		else
			{weapon_work "gun_l" 0}
		}
		{if not tagged "damage_missile"
			{weapon_work "gun" 1}
		else
			{weapon_work "gun" 0}
		}
		{if not tagged "damage_pestcontainer"
			{weapon_work "attack_pestdrop" 1}
		else
			{weapon_work "attack_pestdrop" 0}
		}
	}
	{on "firing_block"
		{kill_delay "limit"}
		{movement_limit slow}
		{delay 3 "limit"
			{if work "fuel"
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
	{on fire "alarm_signal"   
		;{signal shot 5000}
		{tags add "mgun_alarm_base"}
		{tags add "call_allies"}
		{if rand 0.1
			{if not tagged "turn"
				{if not tagged "move"
					{if rand 0.5
						{ani_play "hit_reel_135cw" 1}
					else
						{ani_play "hit_reel_135ccw" 1}
					}
				}
			}
		}
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
	{on "power_up" ; harvest
		{if not able "exploded"
			{view show	"ems_global"}
			{view start	"ems_global"}		
			{view show	"ems"}
			{view start	"ems"}		
			{tags add "hold"}
			{tags remove "alarm"}	
			{tags remove "search"}
			{if not tagged "search_call_signal"
				{tags add "search_call_signal"}
				{call "ai_talk_signal"}
			}
			{delay 2 {tags remove "search_call_signal"}}
		}
	}
	
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
	{on "power_drop_permanent"
		;{kill_delay "power_drop"}
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
			{tags add "power_drop"}
			{tags remove "hold"}	
			{tags remove "alarm"}	
			{tags remove "search"}
			{tags add "off"}
			{call "ai_talk_signal"}
			{tags add "wire_burn"}
			{call "sparks_loop"}
			{burn volume "cpu" fx "smoke_preheat" time 5 fake even_law}	
			{ani_play "power_down"}
			{call "gun_block"}
			{delay 15
				{tags remove "wire_burn"}				
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


	{on move on ;
		{kill_delay "move_stop"}
		{call "stop_idle"}
		{tags add "move"}	
		{set "blocked" 1}
		{if not tagged "turn"
			{tags remove "Turn_Left"}	
			{tags remove "Turn_Right"}	
			{tags add "move_forward"}
			{call "walkstart_f"}
			;{ani_play "walkstart_f"  }
		}
		{call "weapon_disable"}
		{call "weapon_gas_disable"}
		{call "weapon_melee_disable"}
	}
	{on "walkstart_f"
		{if not tagged "walkstart_f"		
			{tags add "walkstart_f"}
			{ani_play "walkstart_f"  }
		}	
	}	
	{on animation_event "walkstart_f_start" ;еэг в начале хода
		{tags add "walkstart_f"}
		{tags add "walk"}
	}
	{on animation_event "walkstart_f_end" ;выход из аним старта
		{tags remove "walkstart_f"}
		{if not tagged "turn"
			{if tagged "move"
				{call "move_update_walk"}
			}
		}	
	}
	{on "walkstop_f"; вызов стопа после старта
		{if not tagged "Turn_Left"		
			{if not tagged "Turn_right"		
				{if not tagged "turn"		
					{if not tagged "walkstop_f"		
						{tags add "walkstop_f"}
						;{ani_stop "walkloop_f"  }
						;{ani_play "walkstop_f"  }
					}	
				}	
			}	
		}	
	}	
	{on move off ; all
		{call "walkstop_f"}
		{call "stop_idle"}
		{tags remove "move_forward"}	
		{tags remove "move"}	
		{tags remove "turn"}
		{tags remove "walk"}
		{delay 1
			{call "weapon_enable"}
			{call "weapon_gas_enable"}
			{call "weapon_melee_enable"}
		}
		{set "blocked" 0}
	}
	{on "move_update_walk"  ; цикл ходки 
		{if tagged "move"		
			{if not tagged "walkstop_f"		
				{ani_play "walkloop_f" }
			}
		}	
	}	
	{on animation_event "walkloop_f_start" 
		{tags add "walk"}
		{tags add "walkloop_f"}
	}
	{on animation_event "walkloop_f_exit" 
		{if tagged "walkstop_f"		
			{tags remove "walkloop_f"}
			{ani_play "walkstop_f"  }
		else
			{call "move_update_walk"}		
		}
	}
	{on animation_event "walkstop_f_start"
		;{chassis_work 0}
		{tags add "walk"}
	}
	{on animation_event "walkstop_f_exit" 
		;{if work "fuel" {chassis_work 1}}		
		{call "weapon_enable"}
		{tags remove "walk"}
		{tags remove "walkstop_f"}
	}
	{on turn on ; 		
		{call "weapon_melee_disable"}
		{call "weapon_disable"}
		{set "blocked" 1}
		{kill_delay "move_stop"}
		{call "stop_idle"}
		{tags add "turn"}
		{if Turn_Left
			{tags add "Turn_Left"}	
			{call "update_turn_left_movement"}
		else Turn_Right
			{tags add "Turn_Right"}	
			{call "update_turn_right_movement"}
		}
	}
	{on "update_turn_left_movement" 
		{if tagged "curl_stand"
			{ani_play "curl_step_l_045"}
		else
			{ani_play "step_l_045"}
		}
	}
	{on animation_event "update_turn_left_movement"; обновление пооврота убрано; harv
		{call "update_turn_left_movement"}
	}
	{on animation_event "update_turn_right_movement"; обновление пооврота убрано; harv
		{call "update_turn_right_movement"}
	}
	{on animation_event "step_l_045_start"
		{tags add "left"}	
		{tags add "step_l_045"}	
		; {if not tagged "move"		
			; {movement_limit slow}		
		; }
	}
	{on animation_event "step_l_045_exit"
		{if tagged "Turn_Left"
			{call "update_turn_left_movement"}
		else
			{ani_stop "step_l_045"}	
			{tags remove "left"}	
			{tags remove "step_l_045"}	
		}
	}
	{on animation_event "step_r_045_start"
		{tags add "step_r_045"}	
		{tags add "right"}	
		;{movement_limit slow}		
	}
	{on animation_event "step_r_045_exit"
		{if tagged "Turn_Right"
			{call "update_turn_right_movement"}
		else
			{ani_stop "step_r_045"}	
			{tags remove "right"}	
			{tags remove "step_r_045"}	
		}
	}
	{on "update_turn_right_movement" 
		{if tagged "curl_stand"
			{ani_play "curl_step_r_045"}
		else
			{ani_play "step_r_045"}
		}
	}
	{on turn off ; 
		{set "blocked" 0}
		{kill_delay "long_turn"}
		{delay 0.5 "move_stop"
			{tags remove "turn"}
			{tags remove "long_turn"}
		}
		{tags remove "Turn_Left"}	
		{tags remove "Turn_Right"}	
		{call "weapon_enable"}
		{call "weapon_gas_enable"}
		{call "weapon_melee_enable"}
		{tags remove "step_r_090"}	
		{tags remove "step_r_045"}	
		{tags remove "step_l_090"}	
		{tags remove "step_l_045"}	
	}


	{on animation_event "curl_step_l_045_start"
		{movement_limit slow}
		{tags add "left"}	
		{tags add "step_l_045"}	
	}
	{on animation_event "curl_step_l_045_exit"
		{if work "fuel" {movement_limit fast}}
		{if tagged "Turn_Left"
			{call "update_turn_left_movement"}
		else
			{tags remove "left"}	
			{tags remove "step_l_045"}
		}
	}
	{on animation_event "curl_step_r_045_start"
		{movement_limit slow}
		{tags add "right"}	
		{tags add "step_r_045"}	
	}
	{on animation_event "curl_step_r_045_exit"
		{if work "fuel" {movement_limit fast}}
		{if tagged "Turn_Right"
			{call "update_turn_right_movement"}
		else
			{tags remove "right"}	
			{tags remove "step_r_045"}
		}
	}
	{on accelerate on
		{tags add "accelerate_on"}
		{if tagged "turn"
			{tags remove "turn"}
			(define "turn_off"	
				{if tagged "%turn_off"
					{tags remove "%turn_off"}	
				}
			)
			("turn_off" turn_off(step_r_090) )	
			("turn_off" turn_off(step_r_045) )	
			("turn_off" turn_off(step_l_090) )	
			("turn_off" turn_off(step_l_045) )	
			{tags remove "Turn_Left"}	
			{tags remove "Turn_Right"}	
			{tags add "move_forward"}
			{ani_play "walkloop_f" }
		}
	}
	{on accelerate off
		{tags remove "accelerate_on"}
	}
	{on engine on
	}
	{on engine off
	}
	{on break ; all
		{call "check_work_organ"}
		{if component "missile_r" ;harv
			{view start "smoke_missile_r"}
			{delay 10 5
				{view pause "smoke_missile_r"}
			}
			{burn volume "missile_r" fx "smoke_heat" time 7 3 fake}	
			{tags add "damage_missile_r"}
			{spawn "break_small_body_robot" "Missile_r"}				
		}
		{if component "missile_l" ;harv
			{view start "smoke_missile_l"}
			{delay 10 5
				{view pause "smoke_missile_l"}
			}
			{burn volume "missile_l" fx "smoke_heat" time 7 3 fake}	
			{tags add "damage_missile_l"}
			{spawn "break_small_body_robot" "Missile_l"}				
		}
		{if component "pestcontainer" ;dread harv hunter
			{tags add "damage_pestcontainer"}
			{weapon_work "attack_pestdrop" 0}
		}
		{if component "lower_arm" ;all tag leg
			{burn volume fx "electric_spark_hit_pierce" time 0.8 fake}			
			{burn volume fx "smoke_destroy" time 0.3 fake}			
		}
		{if component "upper_arm";all tag leg
			{burn volume fx "smoke_destroy" time 0.3 fake}			
			{burn volume fx "electric_spark_hit_pierce" time 0.8 fake}			
		}
		{if component "gasdrop_r" ;dread harv
			{kill_delay "drop_r_loop"}		
			{with_linked_entity "gas_sound_r"
				{call "close"}
			}			
			{with_linked_entity "gasdrop_r"
				{call "empty_fast"}
			}			
		}
		{if component "gasdrop_l";dread harv
			{kill_delay "drop_l_loop"}		
			{with_linked_entity "gas_sound_l"
				{call "close"}
			}			
			{with_linked_entity "gasdrop_l"
				{call "empty_fast"}
			}			
		}
		{if component "fuel" ;all
			{call "lose_health"}
			{start_sound "detonation/fireextinguisher/FX_Explosion_FireExtinguisherVapor_02"}	
			;{burn volume "fuel" fx "smoke_gas_trit_burn" time 7 fake}	
			{stop_sound "engine" }
			{delay 8
				{movement_limit normal}
			}
			{delay 13
				{call "drop_speed"}
			}	
			{delay 15
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
		{if component "cooling_systems" ;not use
			{call "lose_health"}
			{burn volume "cooling_systems" fx "smoke_heat" time 8 fake}
			{delay 20 
				{tags add "break_cooling_systems"}
			}
		}
		{if component "leg_regulator_large_right" ;harv
			{call "lose_health"}
			{burn volume "leg_regulator_large_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "leg_regulator_large_right"}
		}
		{if component "leg_regulator_large_left";harv
			{call "lose_health"}
			{burn volume "leg_regulator_large_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "leg_regulator_large_left"}	
		}
		{if component "leg_motor_left";harv
			{call "lose_health"}
			{burn volume "leg_motor_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "leg_motor_left"}
		}
		{if component "leg_motor_right";harv
			{call "lose_health"}
			{burn volume "leg_motor_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "leg_motor_right"}			
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
			{bone cut "head_light_00_fx"}
			{bone hide	"body_ems_00_hold"}
			{bone hide	"body_ems_00_alarm"}
			{bone hide	"body_ems_00_search"}
			{bone hide	"visor_body_hold"}
			{bone hide	"visor_body_search"}
			{bone hide	"visor_body_alarm"}			
			{spawn "glass_hit5" "visor_body"}
			{spawn "electric_spark_break" "visor_body"}
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
		("mesh_break_armor" component(front_plate_r)			)
		("mesh_break_armor" component(front_plate_l)			)
		("mesh_break_armor" component(knee_plate_r)				)
		("mesh_break_armor" component(knee_plate_l)				)
		("mesh_break_armor" component(armour_head_upper)		)
		("mesh_break_armor" component(armour_head)				)
		(define "mesh_break" ;
			{if component "%component" 
				{burn volume "%component" fx "electric_spark_micro_hit" time 2 1 fake}	
				{burn volume "%component" fx "smoke_preheat" time 4 3 fake}	
			}
		)
		("mesh_break" component(main_body)			)
		("mesh_break" component(Drill)			)
		("mesh_break" component(Drillmount)			)
		("mesh_break" component(backlegs_mount)		)
		("mesh_break" component(frontlegs_mount)	)
		;all leg
		("mesh_break" component(RightHand)			)
		("mesh_break" component(RightForeArm)		)
		("mesh_break" component(RightArm)			)
		("mesh_break" component(RightShoulder)		)
		("mesh_break" component(RightUpLeg)			)
		("mesh_break" component(RightLeg)			)
		("mesh_break" component(RightFoot)			)
		("mesh_break" component(RightToe)  			)
		("mesh_break" component(leftHand)			)
		("mesh_break" component(leftForeArm)		)
		("mesh_break" component(leftArm)			)
		("mesh_break" component(leftShoulder)		)
		("mesh_break" component(leftUpLeg)			)
		("mesh_break" component(leftLeg)			)
		("mesh_break" component(leftFoot)			)
		("mesh_break" component(leftToe)  			)
		
		(define "mesh_break_cylplate" ;dread harv
			{if component "%component" 
				{spawn "break_small_body_robot" "%component"}
				{view start "%component_burn"}
				{delay 10 5
					{view stop "%component_burn"}
				}
			}
		)
		("mesh_break_cylplate" component(RightUpLeg_cylplate_01))
		("mesh_break_cylplate" component(RightUpLeg_cylplate_02))
		("mesh_break_cylplate" component(rightUpLeg_cylplate_03))
		("mesh_break_cylplate" component(RightUpLeg1_cylplate_01))
		("mesh_break_cylplate" component(RightUpLeg1_cylplate_02))
		("mesh_break_cylplate" component(RightFoot_cylplate_01))
		("mesh_break_cylplate" component(RightFoot_cylplate_02))
		("mesh_break_cylplate" component(rightArm_cylplate_01))
		("mesh_break_cylplate" component(rightArm_cylplate_02))
		("mesh_break_cylplate" component(rightArm_cylplate_03))
		("mesh_break_cylplate" component(rightArm_cylplate_04))
		("mesh_break_cylplate" component(rightShoulder_cylplate_01))
		("mesh_break_cylplate" component(leftUpLeg_cylplate_01))
		("mesh_break_cylplate" component(leftUpLeg_cylplate_02))
		("mesh_break_cylplate" component(leftUpLeg_cylplate_03))
		("mesh_break_cylplate" component(leftUpLeg1_cylplate_01))
		("mesh_break_cylplate" component(leftUpLeg1_cylplate_02))
		("mesh_break_cylplate" component(leftFoot_cylplate_01))
		("mesh_break_cylplate" component(leftFoot_cylplate_02))
		("mesh_break_cylplate" component(leftArm_cylplate_01))
		("mesh_break_cylplate" component(leftArm_cylplate_02))
		("mesh_break_cylplate" component(leftArm_cylplate_03))
		("mesh_break_cylplate" component(leftArm_cylplate_04))
		("mesh_break_cylplate" component(leftShoulder_cylplate_01))

	}
	{on destroy ; all
		; {if component "main_body"
			; {bone hide	"orange_ems"}
			; {bone hide	"red_ems"}
		; }
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
		("mesh_break_armor" component(front_plate_r)			)
		("mesh_break_armor" component(front_plate_l)			)
		("mesh_break_armor" component(knee_plate_r)				)
		("mesh_break_armor" component(knee_plate_l)				)
		("mesh_break_armor" component(armour_head_upper)		)
		("mesh_break_armor" component(armour_head)				)
		{if component "missile_r"
			{view start "burn_missile_r"}
			{weapon_work "gun_r" 0}
			{tags add "destroy_missile_r"}
			{spawn "brake_component" "Missile_r" x}	
			{spawn "fireworks_blast_noparticle" "Missile_r"}
		else component "missile_l"
			{view start "burn_missile_l"}
			{weapon_work "gun_l" 0}
			{tags add "destroy_missile_l"}
			{spawn "brake_component" "Missile_l" x}	
			{spawn "fireworks_blast_noparticle" "Missile_l"}
		else component "battery_r"
			{call "lose_health"}
			{view hide "ems_global"}
			{view stop "ems_global"}
			{spawn "destroy_component" "battery_r" } ;destroy_component
			{spawn "electric_spark_break" "battery_r"}
			{call "power_drop_permanent"}
			{burn volume "battery_r" fx "component_break_fx" time 5 fake}	
		else component "battery_l"
			{call "lose_health"}
			{view hide "ems_global"}
			{view stop "ems_global"}
			{spawn "destroy_component" "battery_l" } ;destroy_component
			{spawn "electric_spark_break" "battery_l"}
			{call "power_drop_permanent"}
			{burn volume "battery_l" fx "component_break_fx" time 5 fake}	
		else component "cooling_systems"
			{call "lose_health"}
			{burn volume "cooling_systems" fx "smoke_heat" time 8 fake}
			{delay 20 
				{tags add "break_cooling_systems"}
			}
		else component "leg_regulator_large_right"
			{call "lose_health"}
			{spawn "destroy_component" "leg_regulator_large_right" } ;destroy_component
			{view start "leg_regulator_large_right_burn"}
			{delay 40 
				{tags add "leg_regulator_large_right_burn"}
				{view pause "leg_regulator_large_right_burn"}
			}
			{spawn "electric_spark_break" "leg_regulator_large_right"}
		else component "leg_regulator_large_left"
			{call "lose_health"}
			{spawn "destroy_component" "leg_regulator_large_left" } ;destroy_component
			{view start "leg_regulator_large_left_burn"}
			{delay 40 
				{tags add "leg_regulator_large_left_burn"}
				{view pause "leg_regulator_large_left_burn"}
			}
			{spawn "electric_spark_break" "leg_regulator_large_left"}	
		else component "organs_leg_motor_left"
			{call "lose_health"}
			{view start "organs_leg_motor_left_burn"}
			{delay 25 
				{tags add "organs_leg_motor_left_burn"}
				{view pause "organs_leg_motor_left_burn"}
			}
			{spawn "destroy_component" "organs_leg_motor_left" } ;destroy_component
			{spawn "electric_spark_break" "organs_leg_motor_left"}
		else component "organs_leg_motor_right"
			{call "lose_health"}
			{view start "organs_leg_motor_right_burn"}
			{delay 25 
				{tags add "organs_leg_motor_right_burn"}
				{view pause "organs_leg_motor_right_burn"}
			}
			{spawn "destroy_component" "organs_leg_motor_right" } ;destroy_component
			{spawn "electric_spark_break" "organs_leg_motor_right"}
		else component "organs_engine_drive_left"
			{call "lose_health"}
			{view start "organs_engine_drive_left_burn"}
			{delay 25 
				{tags add "organs_engine_drive_left_burn"}
				{view pause "organs_engine_drive_left_burn"}
			}
			{spawn "destroy_component" "organs_engine_drive_left" } ;destroy_component
			{spawn "electric_spark_break" "organs_engine_drive_left"}
		else component "organs_engine_drive_right"
			{call "lose_health"}
			{burn volume "organs_engine_drive_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_engine_drive_right"}
		else component "organs_hip_right"
			{call "lose_health"}
			{burn volume "organs_hip_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_hip_right"}
		else component "organs_hip_left"
			{call "lose_health"}
			{burn volume "organs_hip_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_hip_left"}
		else component "hydraulic_knee_right"
			{call "lose_health"}
			{burn volume "hydraulic_knee_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "hydraulic_knee_right"}
		else component "hydraulic_knee_left"
			{call "lose_health"}
			{burn volume "hydraulic_knee_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "hydraulic_knee_left"}
		else component "organs_leg_right"
			{call "lose_health"}
			{burn volume "organs_leg_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_leg_right"}
		else component "organs_leg_left"
			{call "lose_health"}
			{burn volume "organs_leg_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_leg_left"}
		else component "right_engine"
			{call "lose_health"}
			{burn volume "right_engine" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "right_engine"}
		else component "left_engine"
			{call "lose_health"}
			{burn volume "left_engine" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "left_engine"}
		else component "right_engine2"
			{call "lose_health"}
			{burn volume "right_engine2" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "right_engine2"}
		else component "left_engine2"
			{call "lose_health"}
			{burn volume "left_engine2" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "left_engine2"}
		else component "body_organ"
			{call "lose_health"}
			{burn volume "body_organ" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "body_organ"}
			{call "power_drop"}
		else component "head_organ"
			{call "lose_health"}
			{if prop "defence_tower_base"
				{call "destroy_turret"}
			}
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
		else component "visor_body"
			{bone cut "visor_body_support_bone"}
			{spawn "electric_spark_break" "visor_body"}
		else component "visor_head"
			{tags add "destroy_visor"}
			{bone cut "visor_head_support_bone"}
			{spawn "glass_hit_lamp" "scanner"}					
		else component "cpu" 
			{call "lose_health"}
			{tags add "destroy_cpu"}
			{tags add "broken_cpu"}
			{call "power_drop"}
			{movement_limit slow}	
			{burn volume "cpu" fx "component_break_fx" time 2 fake}	
			{spawn "electric_spark_hit_pierce" }
			{view start "cpu_burn"}
			{call "electric_spark_small"}
			{delay 30 15
				{view pause "cpu_burn"}
			}
		}
	}
	{on pierce ;harvest
		{vehicle_health_damage_pierce}
		(define "health"
			{if volume "main_organ"
				{if stuff "%stuff"
					{ani_play "health" %health resume}
					{kill_delay "health"}
					{delay 0.1 "health"
						{ani_stop "health"}
					}
				}
			}
		)		
		("health" stuff(shell fg) 			health(+0.4) 	)
		("health" stuff(shell ap) 			health(+0.4) 	)			
		("health" stuff(shell) 				health(+0.7)		)
		("health" stuff(rocketlauncher) 	health(+0.6)		)
		("health" stuff(zenite cs) 			health(+0.3)		)
		("health" stuff(zenite fg) 			health(+0.2)		)
		("health" stuff(zenite) 			health(+0.2)		)
		("health" stuff(bullet big ap) 		health(+0.2)	)
		("health" stuff(bullet big fg) 		health(+0.1)		)
		("health" stuff(bullet big) 		health(+0.1)		)
		("health" stuff(bullet normal ap) 	health(+0.1)		)
		("health" stuff(bullet normal fg) 	health(+0.1)		)
		("health" stuff(bullet normal) 		health(+0.1)		)
		("health" stuff(bullet small) 		health(+0.1)		)	
		(define "mesh_break"
			(define "stuff_pierce"
				{if volume "%component"
					{if stuff "%stuff"
						{if not work "%component"
							{if rand %stuff_break
								{components "%component" break}
							}
						else
							{if rand %stuff_destroy
								{components "%component" destroy}
							}
						}
					}
				}
			)		
			("stuff_pierce" stuff(shell fg) 			stuff_break(0.5) 	)
			("stuff_pierce" stuff(shell ap) 			stuff_break(0.6) 		)			
			("stuff_pierce" stuff(shell) 				stuff_break(0.7)		)
			("stuff_pierce" stuff(rocketlauncher) 		stuff_break(0.8)		)
			("stuff_pierce" stuff(zenite cs) 			stuff_break(0.4)		)
			("stuff_pierce" stuff(zenite fg) 			stuff_break(0.3)		)
			("stuff_pierce" stuff(zenite) 				stuff_break(0.4)		)
			("stuff_pierce" stuff(bullet big ap) 		stuff_break(0.25)		)
			("stuff_pierce" stuff(bullet big fg) 		stuff_break(0.15)		)
			("stuff_pierce" stuff(bullet big) 			stuff_break(0.2)		)
			("stuff_pierce" stuff(bullet normal ap) 	stuff_break(0.2)	)
			("stuff_pierce" stuff(bullet normal fg) 	stuff_break(0.1)		)
			("stuff_pierce" stuff(bullet normal) 		stuff_break(0.1)		)
			("stuff_pierce" stuff(bullet small) 		stuff_break(0.1)		)
		)		
		("mesh_break" component(hips)  				 				stuff_destroy(0.2)    )
		("mesh_break" component(main_body)  				 		stuff_destroy(0.2)    )
		("mesh_break" component(head)  				 				stuff_destroy(0.2)    )
		("mesh_break" component(cpu)  				 				stuff_destroy(0.5)    )
		("mesh_break" component(engine)  			 				stuff_destroy(0.3)    )
			
		("mesh_break" component(back_cooling_prot_plate)			stuff_destroy(0.3)    ) ;задняя часть крышка
		("mesh_break" component(shoulder_plating_left)				stuff_destroy(0.3)    ) ;повреждаемые боковые части на ноге
		("mesh_break" component(shoulder_plating_right)				stuff_destroy(0.3)    ) ;повреждаемые боковые части на ноге
		("mesh_break" component(gasdrop_l)  						 stuff_destroy(0.3)    )
		("mesh_break" component(gasdrop_r)  						 stuff_destroy(0.3)    )
		("mesh_break" component(Concussion_Pulse_r)  				 stuff_destroy(0.2)    )
		("mesh_break" component(Concussion_Pulse_l)  				 stuff_destroy(0.2)    )
		("mesh_break" component(Drillmount)  						 stuff_destroy(0.2)    )
		("mesh_break" component(backlegs_mount)  					 stuff_destroy(0.2)    )
		("mesh_break" component(frontlegs_mount)  					 stuff_destroy(0.2)    )
		("mesh_break" component(front_core_panel)  					 stuff_destroy(0.2)    )
		("mesh_break" component(structure_plate_right)  			 stuff_destroy(0.2)    )
		("mesh_break" component(structure_plate_left)  				 stuff_destroy(0.2)    )
		("mesh_break" component(front_hatch_l)  					 stuff_destroy(0.2)    )
		("mesh_break" component(front_hatch_r)  					 stuff_destroy(0.2)    )
		("mesh_break" component(drill_hatch_r)  					 stuff_destroy(0.2)    )
		("mesh_break" component(drill_hatch_l)  					 stuff_destroy(0.2)    )
		("mesh_break" component(Drill)  							 stuff_destroy(0.2)    )
		("mesh_break" component(pestcontainer)  					 stuff_destroy(0.2)    )
		("mesh_break" component(sideplate_left)  					 stuff_destroy(0.2)    )
		("mesh_break" component(sideplate_right)  					 stuff_destroy(0.2)    )
	
		;harvest
		("mesh_break" component(front_plate_r)  			 		stuff_destroy(0.2))
		("mesh_break" component(front_plate_l)  			 		stuff_destroy(0.2))
		("mesh_break" component(knee_plate_r)  			 			stuff_destroy(0.2))
		("mesh_break" component(knee_plate_l)  			 			stuff_destroy(0.2))
		("mesh_break" component(armour_head)  			 			stuff_destroy(0.2))
		("mesh_break" component(armour_head_upper)  				stuff_destroy(0.2))


		("mesh_break" component(armor)  		 					stuff_destroy(0.1))

;------------------
		
		;all leg

		("mesh_break" component(RightHand)  	 					stuff_destroy(0.3))
		("mesh_break" component(RightForeArm)  			 			stuff_destroy(0.3))
		("mesh_break" component(RightArm)  			 				stuff_destroy(0.3))
		("mesh_break" component(RightShoulder)  		 			stuff_destroy(0.3))
		("mesh_break" component(RightUpLeg)  			 			stuff_destroy(0.3))
		("mesh_break" component(RightLeg)  		 					stuff_destroy(0.3))
		("mesh_break" component(RightFoot)  			 			stuff_destroy(0.3))
		("mesh_break" component(RightToe)  		 					stuff_destroy(0.3))
		("mesh_break" component(leftHand)  	 						stuff_destroy(0.3))
		("mesh_break" component(leftForeArm)  			 			stuff_destroy(0.3))
		("mesh_break" component(leftArm)  			 				stuff_destroy(0.3))
		("mesh_break" component(leftShoulder)  		 				stuff_destroy(0.3))
		("mesh_break" component(leftUpLeg)  			 			stuff_destroy(0.3))
		("mesh_break" component(leftLeg)  		 					stuff_destroy(0.3))
		("mesh_break" component(leftFoot)  			 				stuff_destroy(0.3))
		("mesh_break" component(leftToe)  		 					stuff_destroy(0.3))
	(include "pierce_all.inc")
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
							{if not tagged "curl_stand"
								{if not tagged "replace_position"
									{ani_play "%ani_play" %speed }
								}					
							}
						}
					}
				}
			}
		}
	)
	{on blast ;harvest
		{if stuff "rocketlauncher"
			{if rand 0.5
				{call "rpg_detect"}
			}
		}
		{if stuff "attack_concussion"
			{call "attack_concussion"}
		}
		{if stuff "attack_l_bwd_hv"
			{call "attack_l_bwd"}
		}
		{if stuff "attack_r_bwd_hv"
			{call "attack_r_bwd"}
		}
		{if stuff "attack_l_hv"
			{call "attack_l"}
		}
		{if stuff "attack_r_hv"
			{call "attack_r"}
		}
		(include "blast_all.inc")
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
		("health" energy(20) 				health(+0.7))
		("health" energy(15) 				health(+0.6))
		("health" energy(10) 				health(+0.45))
		("health" energy(7) 				health(+0.3))
		("health" energy(5) 				health(+0.2))
		("health" energy(3) 				health(+0.1))
		("health" energy(1) 				health(+0.03))
		("orientation" vol(front_left_hit)  	ani_play(hit_reel_45ccw)   rand(0.3)  min_energy(2) )
		("orientation" vol(front_right_hit)  	ani_play(hit_reel_45cw)    rand(0.3)  min_energy(2) )
		("orientation" vol(back_left_hit)  		ani_play(hit_reel_135cw)   rand(0.3)  min_energy(2) )
		("orientation" vol(back_right_hit)  	ani_play(hit_reel_135ccw)  rand(0.3)  min_energy(2) )
	}
	(include "burn_volume.inc")
	{on "weapon_gas_off"
		{kill_delay "main_gun"}
		{if work "main_body"
			{chassis_work 1}
		}
		{if work "gasdrop"
			{weapon_work "attack_gas" 0}
			{tags remove "weapon_active_gas"}
			;{ani_play "wpn_combat_to_idle"  }					
		}
	}
	{on "weapon_gas_on"
		{if work "main_body"
			{kill_delay "gas_gun" }		
			{delay 0.5 "gas_gun"
				{if work "gasdrop"
					{tags add "weapon_active_gas"}
					{delay 0.5 "gas_gun"
						{call "drop_speed"}
						{delay 0.8 "gas_gun"
							{weapon_work "weapon_active_gas" 1}
						}
					}
				}
			}
		}
	}
	{on "weapon_melee_disable"
		{with_linked_entity "attack_l_bwd_hv"
			{call "close"}
		}
		{with_linked_entity "attack_r_bwd_hv"
			{call "close"}
		}
		{with_linked_entity "attack_l_hv"
			{call "close"}
		}
		{with_linked_entity "attack_r_hv"
			{call "close"}
		}
		{with_linked_entity "attack_concussion"
			{call "close"}
		}
	}
	{on "weapon_melee_enable" ;with link -close
		{with_linked_entity "attack_l_bwd_hv"
			{call "open"}
		}
		{with_linked_entity "attack_r_bwd_hv"
			{call "open"}
		}
		{with_linked_entity "attack_l_hv"
			{call "open"}
		}
		{with_linked_entity "attack_r_hv"
			{call "open"}
		}
		{with_linked_entity "attack_concussion"
			{call "open"}
		}
	}
	{on fire "attack_pestdrop" 
		{call "fire_script_begin"}
		{call "weapon_melee_disable"}
		{tags add "fire_pestcontainer_drop"}
		;{tags add "curl_stand"}		
		{delay 0.3
			{tags remove "fire_pestcontainer_drop"}
		}	
		{delay 0.9
			{start_sound "generation_zero/characters/harvest/curl/"}	
			{start_sound "generation_zero/characters/harvest/curl_bb/"}	
		}
		{delay 2 1
			;{call "weapon_melee_enable"}
			{ani_play "idle_to_curl" 0.6}	
		}
		{delay 8 "curl"
			{spawn "skirmisher_egg" "spawn_front" 		{call "unlink_harvest"}}
			{spawn "skirmisher_egg" "spawn_left"		{call "unlink_harvest"}}
			{spawn "skirmisher_egg" "spawn_right"		{call "unlink_harvest"}}		
		}			
		{delay 30 
			{ani_play "curl_to_idle" 0.8}	
			{call "fire_script_end"}
			{call "weapon_melee_enable"}
		}
	}		
	{on "attack_l"
		{call "weapon_melee_disable"}
		{ani_play "attack_l" 1}		
		{tags add "attack_l"}
		{delay 0.5
			{tags remove "attack_l"}
		}
		{delay 2
			{call "weapon_melee_enable"}
		}
	}		
	{on "attack_r"
		{call "weapon_melee_disable"}
		{ani_play "attack_r" 1}		
		{tags add "attack_r"}
		{delay 0.5
			{tags remove "attack_r"}
		}
		{delay 2
			{call "weapon_melee_enable"}
		}
	}		
	{on "attack_l_bwd"
		{call "weapon_melee_disable"}
		{ani_play "attack_l_bwd" 1}		
		{tags add "attack_l_bwd"}
		{delay 0.5
			{tags remove "attack_l_bwd"}
		}
		{delay 2
			{call "weapon_melee_enable"}
		}
	}		
	{on "attack_r_bwd"
		{call "weapon_melee_disable"}
		{ani_play "attack_r_bwd" 1}		
		{tags add "attack_r_bwd"}
		{delay 0.5
			{tags remove "attack_r_bwd"}
		}
		{delay 2
			{call "weapon_melee_enable"}
		}
	}		
	{on fire "attack_gas"
		{tags add "fire_gasdrop"}
		{call "weapon_melee_disable"}
		{movement_limit slow}
		{call "drop_speed"}
		{chassis_work 0}
		{delay 8
			{if work "fuel"
				{chassis_work 1}
				{movement_limit fast}
			}
			{call "weapon_melee_enable"}
		}
		{delay 0.3
			{tags remove "fire_gasdrop"}
		}	
		{if work "gasdrop_l"
			{call "check_gasdrop_anim"}
			{weapon_work "attack_gas" 0}
			{delay 0.5
				{call "drop_l_loop"}
				{ani_play "gas_fuel" -0.5 resume callback}
				{view start "gas_drop_l"}
				{with_linked_entity "gasdrop_l"
					{call "empty"}
				}			
				{with_linked_entity "gas_sound_l" ;; if broken, kill_sound
					{call "open"}
				}
			}				
			{delay 8 ;gas_timer
				{view pause "gas_drop_l"}
			}
		}
		{if work "gasdrop_r"
			{call "check_gasdrop_anim"}
			{weapon_work "attack_gas" 0}
			{delay 0.5
				{call "drop_r_loop"}
				{view start "gas_drop_r"}
				{delay 0.5
					{ani_play "gas_fuel" -0.5 resume callback}
				}
				{with_linked_entity "gas_sound_r"
					{call "open"}
				}			
				{with_linked_entity "gasdrop_r"
					{call "empty"}
				}			
				{delay 8 ;gas_timer
					{view pause "gas_drop_r"}
				}
			}
		}
	}
	{on fire "gun_l"
		{tags add "fire_gun_l"}
		{if tagged "damage_missile_l"
			{if rand 0.1
				{call "jammed_left_gun"}
			}
			{if rand 0.001
				{call "break_l_gun"}
			}
		}
		(define "fire_barrel"
			name "%0"
				;{spawn "rpg_shot" "shooter_a%0fx" x}			
				{view start "missile_l_%0"}
				{view show 	"missile_l_%0"}
				{delay 2 "fire"
					{view hide	"missile_l_%0"}
					{view pause "missile_l_%0"}
				}
		)		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		  else ("fire_barrel" args 06)
		  else ("fire_barrel" args 07)
		  else ("fire_barrel" args 08)
		  else ("fire_barrel" args 09)
		}
		{delay 0.5
			{tags remove "fire_gun_l"}
		}	
	}
	{on fire "gun_r"
		{tags add "fire_gun_r"}
		{if tagged "damage_missile_r"
			{if rand 0.1
				{call "jammed_right_gun"}
			}
			{if rand 0.001
				{call "break_r_gun"}
			}
		}
		(define "fire_barrel"
			name "%0"
				;{spawn "rpg_shot" "shooter_a%0fx" x}			
				{view start "missile_r_%0"}
				{view show 	"missile_r_%0"}
				{delay 2 "fire"
					{view hide	"missile_r_%0"}
					{view pause "missile_r_%0"}
				}
		)		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		  else ("fire_barrel" args 06)
		  else ("fire_barrel" args 07)
		  else ("fire_barrel" args 08)
		  else ("fire_barrel" args 09)
		}
		{delay 0.5
			{tags remove "fire_gun_r"}
		}	
	}
	{on "jammed_left_gun" 
		{spawn "break_small_body_robot" "Missile_l"}				
		{weapon_work "gun_l" 0}
		{burn volume "Missile_l" fx "smoke_destroy" time 6 fake even_law}		
		{delay 4 2
			{spawn "break_small_body_robot" "Missile_l"}	
			{if not tagged "destroy_missile_l"			
				{weapon_work "gun_l" 1}
			}	
		}	
		;{ani_play "" }	
	}
	{on "break_l_gun" 
		{spawn "break_small_body_robot" "Missile_l"}				
		{components "Missile_l" destroy}		
	}
	{on "jammed_right_gun" 
		{spawn "break_small_body_robot" "Missile_r"}				
		{weapon_work "gun_r" 0}
		{burn volume "Missile_r" fx "smoke_destroy" time 6 fake even_law}		
		{delay 4 2
			{spawn "break_small_body_robot" "Missile_r"}	
			{if not tagged "destroy_missile_r"			
				{weapon_work "gun_r" 1}
			}	
		}	
		;{ani_play "" }	
	}
	{on "break_r_gun" 
		{spawn "break_small_body_robot" "Missile_r"}				
		{components "Missile_r" destroy}		
	}
	
	{on "reload"  ;harvest
		{if tagged "fire_gun_r"
			{if work "gun_r"
				{tags add "gun_r"}
				{weapon_work "gun_r" 0}
				{delay 11
					{if work "gun_r"
						{delay 0.5
							{tags remove "gun_r"}
							{weapon_work "gun_r" 1}
						}
					}
				}
			}		
		else tagged "fire_gun_l"
			{if work "gun_l"
				{tags add "gun_l"}
				{weapon_work "gun_l" 0}
				{delay 11
					{if work "gun_l"
						{delay 0.5
							{tags remove "gun_l"}
							{weapon_work "gun_l" 1}
						}
					}
				}
			}		
		else tagged "fire_pestcontainer_drop"
			{if work "pestcontainer_drop"
				{tags add "pestcontainer_drop_r"}
				{weapon_work "attack_pestdrop" 0}	
				{delay 60
					{if work "pestcontainer_drop"
						{call "drop_pest_reload"}
						{tags remove "pestcontainer_drop_r"}
						{weapon_work "attack_pestdrop" 1}
					}
				}
			}		
		else tagged "fire_gasdrop"
			{if work "gasdrop"
				{tags add "gasdrop_r"}
				{weapon_work "attack_gas" 0}
				{delay 20
					{if work "gasdrop"
						{tags remove "gasdrop_r"}
						{weapon_work "attack_gas" 1}
					}
				}
			}
		}
	}
	
	{on "rpg_detect"
		{if not tagged "move"
			{if not tagged "rpg_detect"
				{tags add "rpg_detect"}
				{call "fire_script_begin"}
				{call "weapon_melee_disable"}
				{delay 1
					{spawn "curl_move" "basis"}
				}
				{delay 2
					{ani_play "idle_to_curl" 1}	
					{call "fire_script_end"}
					{drop_orders}
					{movement_limit slow}
				}
				{delay 4
					{if rand 0.8
						{if work "gasdrop_l"
							{spawn "wpn_prepare_mortar" "gasdrop_l"}
							{delay 0.5
								{call "drop_l_loop_smoke"}
								{view start "smoke_drop_l"}
								{with_linked_entity "gas_sound_l" ;; if broken, kill_sound
									{call "open"}
								}
							}				
							{delay 8 ;gas_timer
								{kill_delay "drop_l_loop_smoke"}		
								{view pause "smoke_drop_l"}
							}
						}
						{if work "gasdrop_r"
							{spawn "wpn_prepare_mortar" "gasdrop_r"}
							{delay 0.5
								{call "drop_r_loop_smoke"}
								{view start "smoke_drop_r"}
								{with_linked_entity "gas_sound_r" ;; if broken, kill_sound
									{call "open"}
								}
							}				
							{delay 8 ;gas_timer
								{kill_delay "drop_r_loop_smoke"}		
								{view pause "smoke_drop_r"}
							}
						}
					}
				}
				{delay 25 
					{ani_play "curl_to_idle" 1}	
					{drop_orders}
					{movement_limit fast}
					{call "weapon_melee_enable"}
				}
				{delay 35 
					{tags remove "rpg_detect"}
				}
			}		
		}		
	}
	{on "attack_concussion"
		{call "weapon_melee_disable"}
		{tags add "attack_concussion"}
		{delay 0.5
			{tags remove "attack_concussion"}
		}
		{if tagged "curl_stand"
			{ani_play "curl_attack_concussion" 1}
		else
			{ani_play "attack_concussion" 1}
		}
		{delay 10
			{call "weapon_melee_enable"}
		}
	}

	{on "drop_pest"
		{call "drop_count"}
		; {delay 0.1
			; (define "drop"
				; {if bone "egg%0" visible
					; {tags add "filled_%0"}
				; else
					; {tags remove "filled_%0"}
					; ;{bone hide "egg%0"}
					; {spawn "pest_egg_01" "egg_%0" x {call "unlink"}}
				; }
			; )
			; ("drop" args 00)
			; ("drop" args 01)
			; ("drop" args 02)
			; ("drop" args 03)
			; ("drop" args 04)
			; ("drop" args 05)
			; ("drop" args 06)
		; }			
	}		
	{on "drop_count"
		{if tagged "egg05"
			{tags add "egg06"}
			{bone hide "egg06"}
			{spawn "pest_egg_01" "egg_06" x {call "unlink"}}
		}
		{if tagged "egg04"
			{tags add "egg05"}
			{bone hide "egg05"}
			{spawn "pest_egg_01" "egg_05" x {call "unlink"}}
		}
		{if tagged "egg03"
			{tags add "egg04"}
			{bone hide "egg04"}
			{spawn "pest_egg_01" "egg_04" x {call "unlink"}}
		}
		{if tagged "egg02"
			{tags add "egg03"}
			{bone hide "egg03"}
			{spawn "pest_egg_01" "egg_03" x {call "unlink"}}
		}
		{if tagged "egg01"
			{tags add "egg02"}
			{bone hide "egg02"}
			{spawn "pest_egg_01" "egg_02" x {call "unlink"}}
		}
		{if tagged "egg00"
			{tags add "egg01"}
			{bone hide "egg01"}
			{spawn "pest_egg_01" "egg_01" x {call "unlink"}}
		}
		{if not tagged "egg00"
			{tags add "egg00"}
			{bone hide "egg00"}
			{spawn "pest_egg_01" "egg_00" x {call "unlink"}}
		}
	}
	{on "drop_pest_reload"
		(define "drop"
			{tags remove "egg%0"}
			{bone show "egg%0"}
		)
		("drop" args 00)
		("drop" args 01)
		("drop" args 02)
		("drop" args 03)
		("drop" args 04)
		("drop" args 05)
		("drop" args 06)
	}			
	{on "check_gasdrop_anim"
		{ani_play "attack_gas" 0.5}
		{delay 6 ;gas_timer
			{kill_delay "drop_l_loop"}		
			{kill_delay "drop_r_loop"}		
		}
	}
	{on "drop_l_loop"
		{if work "gasdrop_l"
			{spawn "open_gas_scale" "gasdrop_socket_l_00" x {impulse forward 12 6}  }
			{spawn "open_gas_scale" "gasdrop_socket_l_01" x {impulse forward 12 6}  }
			{spawn "open_gas_scale" "gasdrop_socket_l_02" x {impulse forward 12 6}  }
			{spawn "open_gas_scale" "gasdrop_socket_l_03" x {impulse forward 12 6}  }
			{spawn "open_gas_scale" "gasdrop_socket_l_04" x {impulse forward 12 6}  }
		}
		{delay_effect 1 "drop_l_loop"}
	}
	{on "drop_r_loop"
		{if work "gasdrop_r"
			{spawn "open_gas_scale" "gasdrop_socket_r_00" x {impulse forward 12 6}  }
			{spawn "open_gas_scale" "gasdrop_socket_r_01" x {impulse forward 12 6}  }
			{spawn "open_gas_scale" "gasdrop_socket_r_02" x {impulse forward 12 6}  }
			{spawn "open_gas_scale" "gasdrop_socket_r_03" x {impulse forward 12 6}  }
			{spawn "open_gas_scale" "gasdrop_socket_r_04" x {impulse forward 12 6}  }
		}
		{delay_effect 1 "drop_r_loop"}
	}

	{on "drop_l_loop_smoke"
		{if work "gasdrop_l"
			{spawn "open_smoke_scale" "gasdrop_socket_l_00" x {impulse forward 12 6}  }
			{spawn "open_smoke_scale" "gasdrop_socket_l_01" x {impulse forward 12 6}  }
			{spawn "open_smoke_scale" "gasdrop_socket_l_02" x {impulse forward 12 6}  }
			{spawn "open_smoke_scale" "gasdrop_socket_l_03" x {impulse forward 12 6}  }
			{spawn "open_smoke_scale" "gasdrop_socket_l_04" x {impulse forward 12 6}  }
		}
		{delay_effect 1 "drop_l_loop_smoke"}
	}
	{on "drop_r_loop_smoke"
		{if work "gasdrop_r"
			{spawn "open_smoke_scale" "gasdrop_socket_r_00" x {impulse forward 12 6}  }
			{spawn "open_smoke_scale" "gasdrop_socket_r_01" x {impulse forward 12 6}  }
			{spawn "open_smoke_scale" "gasdrop_socket_r_02" x {impulse forward 12 6}  }
			{spawn "open_smoke_scale" "gasdrop_socket_r_03" x {impulse forward 12 6}  }
			{spawn "open_smoke_scale" "gasdrop_socket_r_04" x {impulse forward 12 6}  }
		}
		{delay_effect 1 "drop_r_loop_smoke"}
	}


	; {on animation_end "gas_fuel"
		; {with_linked_entity "gas_sound"
			; {call "open"}
		; }	
		; {delay 0.5
			; {weapon_work "attack_gas" 0}
		; }	
	; }
	{on "explosion_harv" 
		{if not able "exploded"			
			{view start "front_hatch_r_destroy"}
			{view show "front_hatch_r_destroy"}
			{view start "front_hatch_l_destroy"}
			{view show "front_hatch_l_destroy"}			
			{set "exploded" 1}		
			{able "exploded" 1}
			{stop_sound "engine" }
			{stop_sound "engine_hiss" }
			;{bone hide ""}
			;{mtl_enable_skin 0}
			{tags add "off"}
			{tags add "dead"}
			{call "stop_all"}
			;{call "tear_parts"}
			{if rand 0.5
				{ani_play "death_l_fwd"}
			else
				{ani_play "death_r_fwd"}
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
			{able select 0}
			{able repaired 0}
			{clear_inventory}
			{with_linked_entity "attack_l_bwd_hv"
				{delete}
			}			
			{with_linked_entity "attack_r_bwd_hv"
				{delete}
			}			
			{with_linked_entity "attack_l_hv"
				{delete}
			}			
			{with_linked_entity "attack_l_hv"
				{delete}
			}			
			{with_linked_entity "attack_concussion"
				{delete}
			}			
			{call "tear_parts_explode"}
		}
	}
	{on "tear_parts_explode"
		(define "blast_harvest"
			{if rand %1
				{tear "piece_small_steel" bone %0
					{impulse up 4 3 dir 12 5 cx 3 2 cy 3 2 no_position}
				}
			}
		)
		("blast_harvest" args "front_plate_r" 				0.4)
		("blast_harvest" args "front_plate_l" 				0.4)
		("blast_harvest" args "knee_plate_r" 				0.4)
		("blast_harvest" args "knee_plate_l" 				0.6)
		("blast_harvest" args "Concussion_Pulse_l" 			0.2)
		("blast_harvest" args "Concussion_Pulse_r" 			0.2)
		("blast_harvest" args "visor_body" 			0.4)
		("blast_harvest" args "container" 			0.4)
		("blast_harvest" args "Missile_l" 			0.2)
		("blast_harvest" args "Missile_r" 			0.2)
	}
	{on "move_hit" 
		{if not "blocked"
			{if rand 0.5
				{ani_play "hit_reel_45ccw" resume}
			else rand 0.5
				{ani_play "hit_reel_45cw" resume}
			}
		}
	}
	{on "fire_script_begin"
		{auto_operatable 0}
		{drop_orders}
		{movement_limit slow}
		{delay 1
			{chassis_work 0}
		}
	}
	{on "fire_script_end"
		{if not able "exploded"
			{if work "fuel"
				{auto_operatable 1}
				{chassis_work 1}
				{drop_orders}
				{movement_limit fast}
			}
		}
	}
	;evs
	{on animation_event "curl_start"
		{tags add "curl_stand"}		
	}
	{on animation_event "curl_end"
		{tags remove "curl_stand"}		
	}
	{on animation_event "fire_script_begin"
		{auto_operatable 0}
		{drop_orders}
		{movement_limit slow}
		{delay 1
			{chassis_work 0}
		}
	}
	{on animation_event "fire_script_end"
		{if not able "exploded"
			{if work "fuel"
				{auto_operatable 1}
				{chassis_work 1}
				{drop_orders}
				{movement_limit fast}
			}
		}
	}
	{on animation_event "drop_speed_event_start" ;harv
		{movement_limit slow}
		
	}
	{on animation_event "drop_speed_event_exit";harv
		{if work "fuel"
			{movement_limit fast}
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
	{on animation_event "explosion_harv" 
		{call "explosion_harv"}
	}
	{on animation_event "block_hit"
		{chassis_work 0}
		{auto_operatable 0}
		{able select 0}
	}
	{on animation_event "unblock_hit"
		{delay 1 
			{if not able "exploded" 
				{auto_operatable 1}
				{able select 1}
				{if work "fuel"
					{chassis_work 1}
				}
				{if tagged "frends"
					{delay 0.1
						{player 0}
					}
				else tagged "rus"
					{delay 0.1
						{player 9}
					}
				else
					{delay 0.1
						{player 8}
					}
				}
			}
		}
	}
	{on animation_event "replace_position_start" ;skir scout harv
		{tags add "replace_position"}		
		{movement_limit slow}
		{auto_operatable 0}
		{able select 0}
	}
	{on animation_event "replace_position_end"
		{tags remove "replace_position"}
		{if work "fuel"
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
	;harvest_foot
	{on animation_event "foot_harvest_fr"
		;{spawn "footstep_hooffront" "footstep_hooffront_r" x terrain_texmod}
		{if rand 0.5
			{spawn "dust_med_harvest" "RightHand_fx" x}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/harvest/move/%0/"}				
				{start_sound "generation_zero/characters/harvest/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_harvest_fl"
		;{spawn "footstep_hooffront" "footstep_hooffront_r" x terrain_texmod}
		{if rand 0.5
			{spawn "dust_med_harvest" "RightHand_fx" x}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/harvest/move/%0/"}				
				{start_sound "generation_zero/characters/harvest/move/far/%0/"}				
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "play_idle" ;skir scout harv
		{tags add "play_idle"}
		{tags add "hold"}	
		{tags remove "alarm"}	
		{tags remove "search"}
		{if not tagged "search_call_signal"
			{tags add "search_call_signal"}
			{call "ai_talk_signal"}
		}
		{delay 2 {tags remove "search_call_signal"}}
	}
	{on animation_event "leave_idle" ;skir scout harv
		{tags remove "play_idle"}
	}
	{on animation_event "foot_harvest_melee_l"
		{start_sound "generation_zero/characters/harvest/attack_legs/stomp"}
		{spawn "harvest_melee" "RightHand_fx"}
		{burn volume "Righthand" fx "dust_med_dreadnought" time 0.5 fake even_law}
		{spawn "dust_med_dreadnought_front" "RightHand_fx"}
		{spawn "explosion_flash_melee" "RightHand_fx" x}
		{spawn "distant_small_grass_set" "RightHand_fx" x}
	}	
	{on animation_event "foot_harvest_melee_r"
		{start_sound "generation_zero/characters/harvest/attack_legs/stomp"}
		{spawn "harvest_melee" "LeftHand_fx"}
		{burn volume "lefthand" fx "dust_med_dreadnought" time 0.5 fake even_law}
		{spawn "dust_med_dreadnought_front" "leftHand_fx"}
		{spawn "explosion_flash_melee" "leftHand_fx" x}
		{spawn "distant_small_grass_set" "leftHand_fx" x}
	}	
	;----------------------------------------------------------------death harv
	{on animation_event "death_harv_01"
		{if rand 0.5
			{spawn "break_small_body_robot" "pneu_short_01"}
		else rand 0.3
			{spawn "break_small_body_robot" "pneu_short_07"}
		else
			{spawn "break_small_body_robot" "pneu_short_05"}
		}	
	}	
	{on animation_event "death_harv_02"
		{spawn "hit_fall" "LeftIndex"}
	}	
	{on animation_event "death_harv_03"
		{spawn "hit_fall" "RightForeArm"}
	}	
	{on animation_event "death_harv_04"
		{start_sound "generation_zero/characters/harvest/joint_damage"}	
		;{start_sound "generation_zero/characters/explosion/robot_death_downer_tank/close/"}	
	}	
	{on animation_event "restart_clunk_harvester"
		{if rand 0.1
			{spawn "electric_spark_hit" "LeftCableUpperArmTopSM"}
		else rand 0.1
			{spawn "electric_spark_hit" "RightCableLegSM"}
		else rand 0.1
			{spawn "electric_spark_hit" "RightCableLegSM1"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftCableLegSM1"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftCableLegSM"}
		else rand 0.1
			{spawn "electric_spark_hit" "Neck"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftForeArm"}
		else rand 0.1
			{spawn "electric_spark_hit" "RightForeArm"}
		else rand 0.1
			{spawn "electric_spark_hit" "CableDrillSM"}
		else rand 0.1
			{spawn "electric_spark_hit" "RightArm"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftArm"}
		else rand 0.1
			{spawn "electric_spark_hit" "RightShoulder"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftShoulder"}
		}
		{if rand 0.4
			{start_sound "generation_zero/characters/restart_clunk/large/"}			
		}
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
	{on animation_event "joint_big" ;hunter harv dread
		{call "fx_component_mover"}
		{if tagged "run"
			{start_sound "generation_zero/characters/dreadnought/joint/run"}			
		else
			{start_sound "generation_zero/characters/dreadnought/joint/walk"}			
		}	
	}
	{on animation_event "concussion_riser" ;dread harv
		{play_sound "concussion_riser"}
	}
	{on animation_event "attack_concussion";dread harv
		{start_sound "generation_zero/characters/dreadnought/concussion/blast"}	
		{spawn "damage_concussion_fx" "basis"}		
		{spawn "damage_concussion" "concussion"}		
	}
	{on animation_event "close_attack_enter";dread harv
		{view start "close_attack_dread"}
		{view show "close_attack_dread"}	
		{view start "close_attack_harvest"}
		{view show "close_attack_harvest"}	
	}
	{on animation_event "close_attack_leave";dread harv
		{view hide "close_attack_dread"}
		{view stop "close_attack_dread"}	
		{view hide "close_attack_harvest"}
		{view stop "close_attack_harvest"}	
	}
	{on animation_event "20heal" ;all
		{burn volume "cpu" fx "smoke_heat" time 5 fake}	
		{burn volume "back_hatch_r" fx "smoke_heat" time 5 fake}	
		{burn volume "back_hatch_l" fx "smoke_heat" time 5 fake}		
		{if rand 0.3
			{spawn "component_break_fx" "shoulder_plate_right"}
		}			
		{if rand 0.3
			{spawn "component_break_fx" "shoulder_plate_left"}
		}			
	}
	{on animation_event "40heal"  ;all	
		{burn volume "cpu" fx "smoke_heat" time 7 fake}	
		{burn volume "bridge" fx "smoke_heat" time 7 fake}	
	}
	{on animation_event "70heal"  ;all
		{if rand 0.3
			{spawn "component_break_fx" "RightCableHips_00_clunk"}
		}			
		{if rand 0.3
			{spawn "component_break_fx" "RightCableHips_01_clunk"}
		}			
		{if rand 0.3
			{spawn "component_break_fx" "LeftCableHips_00_clunk"}
		}			
		{if rand 0.3
			{spawn "component_break_fx" "LeftCableHips_01_clunk"}
		}			
		{burn volume "cpu" fx "fx_fire_engine_gen" time 2 fake even_law}					
		{burn volume "body_organ" fx "smoke_heat" time 5 fake even_law}					
	}
	{on "overheat_cooling_systems"
		(define "hiss"
			{if rand 0.05
				{spawn "pneu_short" "%0" x}
			
			}
		)
		("hiss" args 00)
		("hiss" args 01)
		("hiss" args 02)
		("hiss" args 03)
		("hiss" args 04)
		("hiss" args 05)
		("hiss" args 06)
		("hiss" args 07)
		("hiss" args 08)
		("hiss" args 09)
		{if not work "cooling_systems"
			{burn volume "cooling_systems" fx "smoke_heat" time 20 fake}
			{play_sound "heater" 1}	
			{delay 10 
				{movement_limit normal}			
			}
		}	
	}	
}