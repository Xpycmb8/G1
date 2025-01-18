{"hunter_base"
	{inflammation_time 20}
	{on spawn
		{link_sound "engine" 	"generation_zero/characters/hunter/engine/machine_other_engine_03"}
		;{link_sound "engine_hiss" 	"generation_zero/characters/dreadnought/engine/machine_whine_08_2ch"}
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
		{add_view 	"muzzle_front_shorted" 					"fx_muzzle_buck" 	"foresight_main"}
		{add_view 	"muzzle_front_shorted" 					"fx_muzzle_slug" 	"foresight_main"}
		{add_view 	"muzzle_front_hmgun" 					"fx_muzzle_dragon" 	"foresight_main"}
		{add_view 	"heat_stage1_fire" 						"stage1_fire" 		"foresight_main"}
		{add_view 	"heat_stage1" 							"stage1" 			"foresight_main"}
		{add_view 	"scanline_light" 						"scanline_light" "scanlines_fx"}
		{add_view 	"scanline_burn" 						"scanline_light" "scanlines2_fx_bone"}
		{add_view 	"scanline_burn" 						"scanline_light" "scanlines_fx_bone"}
		{add_view 	"yellow_ems" 							"ems_global_search" "head_ems_bone"}
		{add_view 	"yellow_light" 							"ems_global" "head_light_small_00_fx"}
		{add_view 	"yellow_light" 							"ems_global" "head_light_small_01_fx"}
		{add_view 	"yellow_light" 							"ems_global" "head_light_small_02_fx"}
		{add_view 	"headlight_led6000k_med" 				"ems_global" "headlight_l"}
		{add_view 	"headlight_led6000k_med" 				"ems_global" "headlight_r"}
		{add_view 	"headlight_led6000k_med" 				"ems_global" "head_light_00_fx"}
		{add_view 	"light_skir_main" 						"ems_global" "head_light_00_fx"}

		{add_view 	"muzzle_front_hmgun" 			"fx_muzzle_mgun" 			"foresight_main"}
		{add_view 	"muzzle_front_shotgun" 			"fx_main_mgun" 				"foresight_main"} ; hunter rifle
		{add_view 	"smoke_sil_small" 				"fx_fire_hot_mgun" 			"foresight_main"}; hunter rifle
		{add_view 	"muzzle_sniper" 				"fx_main_sniper" 			"foresight_sniper"}; hunter sniper
		{add_view 	"muzzle_single_heavy" 			"fx_main_sniper" 			"fx_point_sniper_00"}; hunter sniper
		{add_view 	"muzzle_single_heavy" 			"fx_main_sniper" 			"fx_point_sniper_01"}; hunter sniper

		{add_view 	"melee_fx" 						"blade_melee" "blade_overlap_03"}

		{add_view 	"cooling_engine" 				"cooling_engine_r" 		"back_hatch_r"}
		{add_view 	"cooling_engine" 				"cooling_engine_l" 		"back_hatch_l"}
		{add_view 	"cooling_engine_overheat" 		"cooling_engine_r_overheat" 		"back_hatch_r"}
		{add_view 	"cooling_engine_overheat" 		"cooling_engine_l_overheat" 		"back_hatch_l"}


		{add_view 	"close_attack_light" 	"melee_warning" "head_light_small_00_fx"}



		;burn_element
		{add_view 	"burn_element_cpu" 			"cpu_burn" "cpu"}
		{add_view 	"smoke_element_cpu" 		"cpu_smoke" "cpu"}

		{add_view 	"burn_element" 			"burn_missile" "foresight_gun"}
		{add_view 	"burn_element" 			"burn_missile" "foresight_gun"}
				
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


		{view hide	"scanline_light"}
		{view pause	"scanline_light"}

		{view hide	"fx_main_sniper"}
		{view pause	"fx_main_sniper"}
		{view hide	"fx_main_mgun"}
		{view pause	"fx_main_mgun"}
		{view hide	"fx_fire_hot_mgun"}
		{view pause	"fx_fire_hot_mgun"}

		{view hide	"melee_warning"}
		{view pause	"melee_warning"}

		{view hide	"cooling_engine_r"}
		{view hide	"cooling_engine_l"}
		{view hide	"cooling_engine_r_overheat"}
		{view hide	"cooling_engine_l_overheat"}
		{view pause	"cooling_engine_r"}
		{view pause	"cooling_engine_l"}
		{view pause	"cooling_engine_r_overheat"}
		{view pause	"cooling_engine_l_overheat"}

		{view hide	"fx_muzzle_dragon"}
		{view pause	"fx_muzzle_dragon"}
		{view hide	"fx_muzzle_buck"}
		{view pause	"fx_muzzle_buck"}
		{view hide	"fx_muzzle_slug"}
		{view pause	"fx_muzzle_slug"}
		{view hide	"fx_muzzle_mgun"}
		{view pause	"fx_muzzle_mgun"}
		{set "engine_started" 0}
		{set "stop" 1}
		{delay 15 5 "idle_enter"
			{tags add "idle_enter"}
			{call "idle-enter"}
		}		
		{ik_enable "head_ik_h_damage" 0}
		{ik_enable "head_ik_v_damage" 0}
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
		{tags add "hunter_base"}
		{tags add "egg_deploy1"}
		{call "ai_talk_signal"}
		{call "led_ems_connect"}
		{call "led_light_connect"}
		{call "radio_connect"}
		{call "sound_connect"}
		{call "fire_connect"}
	}
	{on "fire_connect"
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
			{add_view 	"yellow_ems_small" 	"ems_global_search" 	"%vis"}
			{add_view 	"red_ems_small" 	"ems_global_alarm" 		"%vis"}
			{add_view 	"hold_ems_small" 	"ems_global_hold" 		"%vis"}
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
		("leds_ems_global_small"  vis(head_ems_00)  )
		("leds_ems_global_small"  vis(head_ems_01)  )
		("leds_ems_global_small"  vis(head_ems_02) )
		("leds_ems_global_small"  vis(visor_led_01) )
		("leds_ems_global_small"  vis(visor_led_02) )
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
	{on "led_light_connect"
		{add_view 	"yellow_ems_big" 	"ems_global_search" 	"head_light_small_00_fx"}
		{add_view 	"red_ems_big" 		"ems_global_alarm" 		"head_light_small_00_fx"}
		{add_view 	"hold_ems_big" 		"ems_global_hold" 		"head_light_small_00_fx"}
		{view show	"ems_global_hold"}
		{view start	"ems_global_hold"}
		{view hide	"ems_global_alarm"}
		{view pause	"ems_global_alarm"}
		{view hide	"ems_global_search"}
		{view pause	"ems_global_search"}
		)
	}
	{on "ai_talk_signal" 
		{delay 0.2
			{if tagged "alarm"
				{tags remove "search"}
				{tags remove "hold"}
				{if not tagged "alarm_call"
					{tags add "alarm_call"}
					{if rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/81_01_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/81_01_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/81_02_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/81_02_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/81_03_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/81_03_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/81_04_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/81_04_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/82_01_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/82_01_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/82_02_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/82_02_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/82_03_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/82_03_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/82_04_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/82_04_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/82_05_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/82_05_dmono_bb"}	
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
					{if rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/80_01_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/80_01_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/80_02_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/80_02_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/80_03_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/80_03_dmono_bb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter/combat/80_04_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/80_04_dmono_bb"}	
					else 
						{start_sound "generation_zero/characters/hunter/combat/80_05_dmono_2ch"}	
						{start_sound "generation_zero/characters/hunter/combat_bb/80_05_dmono_bb"}	
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
		("leds_ems"  vis(head_ems_00)	)
		("leds_ems"  vis(head_ems_01)	)
		("leds_ems"  vis(head_ems_02)	)
		("leds_ems"  vis(visor_led_01) )
		("leds_ems"  vis(visor_led_02) )
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
			{view show	"ems_global"}
			{view start	"ems_global"}		
			{view show	"ems"}
			{view start	"ems"}		
			{tags add "hold"}
			{tags remove "search"}	
			{tags remove "alarm"}	
			{call "ai_talk_signal"}
			{call "fx_component_start"}
		}
	}
	{on "fx_component_start" 
		{if work "back_hatch_l"
			{view show	"cooling_engine_l"}
			{view start	"cooling_engine_l"}		
		}	
		{if work "back_hatch_r"
			{view show	"cooling_engine_r"}
			{view start	"cooling_engine_r"}		
		}
		{if work "canister_left_01"
			{view show "canister_left_01_fx"}
			{view start "canister_left_01_fx"}
		}	
		{if work "canister_left_02"
			{view show "canister_left_02_fx"}
			{view start "canister_left_02_fx"}
		}	
		{if work "canister_right_01"
			{view show "canister_right_01_fx"}
			{view start "canister_right_01_fx"}
		}	
		{if work "canister_right_02"
			{view show "canister_right_02_fx"}
			{view start "canister_right_02_fx"}
		}	
	}
	{on "fx_component_stop"
		{view hide	"cooling_engine_l"}
		{view pause	"cooling_engine_l"}		
		{view hide	"cooling_engine_r"}
		{view pause	"cooling_engine_r"}		
		{view hide "canister_left_01_fx"}
		{view pause "canister_left_01_fx"}
		{view hide "canister_left_02_fx"}
		{view pause "canister_left_02_fx"}
		{view hide "canister_right_01_fx"}
		{view pause "canister_right_01_fx"}
		{view hide "canister_right_02_fx"}
		{view pause "canister_right_02_fx"}
		{view hide	"cooling_engine_l_overheat"}
		{view pause	"cooling_engine_r_overheat"}		
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
					{call "fx_component_stop"}
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
					{call "fx_component_stop"}
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
		{movement_limit slow}
		{delay 0.2 
			{if not able "exploded"
				{if work "fuel"
					{drop_orders}
					{movement_limit fast}
				}
			}
		}
	}
	{on "drop_speed_move"
		{drop_orders}
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
	{on "drop_speed_fire"
		{auto_operatable 0}
		{movement_limit slow}
		{delay 0.5
			{chassis_work 0}
		}
		{delay 6
			{if not able "exploded"
				{if work "fuel"
					{auto_operatable 1}
					{chassis_work 1}
					{drop_orders}
					{movement_limit fast}
				}
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
	{on contact ; 
		{if effector "tank"
			{if min_speed 10
				(define "mesh_break" ;
					{if volume "%component"
						{if rand %rand
							{components "%component" break}
						}
					}
				)
				("mesh_break" component(back_hatch_l)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(back_hatch_r)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_hatch_l)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_hatch_r)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(drill_hatch_r)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(drill_hatch_l)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(pestcontainer)  						rand(0.3) d_rand(0.5)    )
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
		{if component "pestcontainer" ;dread harv hunter
			{tags add "damage_pestcontainer"}
			{weapon_work "attack_pestdrop" 0}
			{if bone "egg00" visible
				{tear "piece_small_steel" bone "egg00"
					{burn volume fx "electric_spark_hit" time 2 fake}		
					{impulse forward 2 0.5 cx 4 1 cy 4 1 }
				}
			}
			{if bone "egg01" visible
				{tear "piece_small_steel" bone "egg01"
					{burn volume fx "electric_spark_hit" time 2 fake}		
					{impulse forward 2 0.5 cx 4 1 cy 4 1 }
				}
			}
			{if bone "egg02" visible
				{tear "piece_small_steel" bone "egg02"
					{burn volume fx "electric_spark_hit" time 2 fake}		
					{impulse forward 2 0.5 cx 4 1 cy 4 1 }
				}
			}
			{tear "piece_small_steel" bone "pestcontainer_hatch_front"
				{impulse forward 2 0.5 cx 4 1 cy 4 1 }
			}
			{tear "piece_small_steel" bone "pestcontainer_hatch_bot"
				{impulse forward 2 0.5 cx 4 1 cy 4 1 }
			}
			{spawn "break_small_body_robot" "hatch_botttom_bone"}				
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
		{if component "fuel_rods_l" ;hunter class d
			{spawn "break_small_body_robot" "fuel_rods_l"}	;break fx
			{tags add "break_flamethrower"}
			{spawn "open_tritium" "fuel_rods_l"}			
			{spawn "open_tritium" "fuel_rods_l"}			
		}
		{if component "fuel_rods_r" ;hunter class d
			{spawn "break_small_body_robot" "fuel_rods_r"}	;break fx
			{tags add "break_flamethrower"}
			{spawn "open_tritium" "fuel_rods_r"}			
			{spawn "open_tritium" "fuel_rods_r"}			
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
		{if component "right_engine" ; hunter_
			{call "lose_health"}
			{burn volume "right_engine" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "right_engine"}
		}
		{if component "left_engine"; hunter_
			{call "lose_health"}
			{burn volume "left_engine" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "left_engine"}
		}
		{if component "right_engine2"; hunter_
			{call "lose_health"}
			{burn volume "right_engine2" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "right_engine2"}
		}
		{if component "left_engine2"; hunter_
			{call "lose_health"}
			{burn volume "left_engine2" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "left_engine2"}
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
			{bone cut "head_light_small_00_fx"}		
			{spawn "electric_spark_break" "visor_body_bone"}
		}
		{if component "visor_head";all
			{bone cut "visor_head_bone"}
			{spawn "glass_hit_lamp" "visor_head_bone"}					
		}
		{if component "canister_right_01";can gas
			{spawn "destroy_ballon" "canister_right_01"}
			{view hide "canister_right_01_fx"}
			{view pause "canister_right_01_fx"}			
		}
		{if component "canister_right_02";can gas
			{spawn "destroy_ballon" "canister_right_02"}
			{view hide "canister_right_02_fx"}
			{view pause "canister_right_02_fx"}			
		}
		{if component "canister_left_01";can gas
			{spawn "destroy_ballon" "canister_left_01"}
			{view hide "canister_left_01_fx"}
			{view pause "canister_left_01_fx"}			
		}
		{if component "canister_left_02";can gas
			{spawn "destroy_ballon" "canister_left_02"}
			{view hide "canister_left_02_fx"}
			{view pause "canister_left_02_fx"}			
		}
		{if component "front_hatch_r" ;крышка охотника спереди х2
			{burn volume "front_hatch_r" fx "electric_spark_micro_hit" time 5 2 fake}	
			{start_sound "generation_zero/electric_spark/"}	
			{view start "front_hatch_r_break"}
			{delay 7 3
				{view pause "front_hatch_r_break"}
			}	
		}
		{if component "front_hatch_l" ;крышка охотника спереди х2
			{burn volume "front_hatch_l" fx "electric_spark_micro_hit" time 5 2 fake}	
			{start_sound "generation_zero/electric_spark/"}	
			{view start "front_hatch_l_break"}
			{delay 7 3
				{view pause "front_hatch_l_break"}
			}	
		}
		{if component "back_hatch_r" ;крышка охотника сзади х2
			{burn volume "back_hatch_r" fx "electric_spark_micro_hit" time 5 2 fake}	
			{start_sound "generation_zero/electric_spark/"}	
			{view stop "cooling_engine_r"}
			{view start "back_hatch_r_break"}
			{delay 7 3
				{view pause "back_hatch_r_break"}
			}	
		}
		{if component "back_hatch_l" ;крышка охотника сзади х2
			{burn volume "back_hatch_l" fx "electric_spark_micro_hit" time 5 2 fake}	
			{start_sound "generation_zero/electric_spark/"}	
			{view stop "cooling_engine_l"}
			{view start "back_hatch_l_break"}
			{delay 7 3
				{view pause "back_hatch_l_break"}
			}	
		}
		{if component "armor_right_engine_wire" ;сетка охотника
			{spawn "break_wire" "armor_right_engine_wire"}			
		}
		{if component "armor_left_engine_wire" ;сетка охотника
			{spawn "break_wire" "armor_left_engine_wire"}			
		}
		{if component "armor_cpu_wire" ;сетка охотника
			{spawn "break_wire" "armor_cpu_wire"}			
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
		("mesh_break_armor" component(armour_prot_left)  			) ;hunter
		("mesh_break_armor" component(armour_prot_right)  			) ;hunter
		("mesh_break_armor" component(head_sideplate_back_r)  		) ;hunter
		("mesh_break_armor" component(head_sideplate_back_l)  		) ;hunter
		("mesh_break_armor" component(head_sideplate_front_r)  		) ;hunter
		("mesh_break_armor" component(head_sideplate_front_l)  		) ;hunter
		("mesh_break_armor" component(cyl_prot_plate_right)  		) ;hunter
		("mesh_break_armor" component(cyl_prot_plate_left)  		) ;hunter
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
		else component "fuel_rods_l" ;hunter class d
		else component "fuel_rods_r" ;hunter class d	
		else component "flamethrower" ;hunter class d
			{weapon_work "mgun" 0}
			{spawn "break_small_body_robot" "fuel_rods_l"}	;break fx
			{tags add "broken_flamethrower"}
			{delay 0.1
				{tear "piece_small_steel" bone "flamethrower"
					{spawn "electric_spark_hit_pierce" }
				}
			}
		else component "rocket_cluster" ;hunter class d
			{weapon_work "alarm_signal_fire" 0}
			{spawn "break_small_body_robot" "rocket"}	;break fx
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
		else component "front_hatch_r" ;крышка охотника спереди х2
			{start_sound "generation_zero/electric_spark/"}	
			{view start "front_hatch_r_destroy"}
			{if rand 0.2
				{fire volume "front_hatch_r" radius 0.1 heating 0.2  time 5 follow}
			}
			{delay 7 3
				{view pause "front_hatch_r_destroy"}
			}	
		else component "front_hatch_l" ;крышка охотника спереди х2
			{start_sound "generation_zero/electric_spark/"}	
			{view start "front_hatch_l_destroy"}
			{if rand 0.2
				{fire volume "front_hatch_l" radius 0.1 heating 0.2  time 5 follow}
			}
			{delay 7 3
				{view pause "front_hatch_l_destroy"}
			}	
		else component "back_hatch_r" ;крышка охотника сзфди х2
			{start_sound "generation_zero/electric_spark/"}	
			{view start "back_hatch_r_destroy"}
			{delay 7 3
				{view pause "back_hatch_r_destroy"}
			}	
		else component "back_hatch_l" ;крышка охотника сзфди х2
			{start_sound "generation_zero/electric_spark/"}	
			{view start "back_hatch_l_destroy"}
			{delay 7 3
				{view pause "back_hatch_l_destroy"}
			}	
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
	{on blast ;hunter
		{if stuff "orientation_melee_back"
			{call "attack_melee_swipe_bwd_armed"}
		}
		{if stuff "orientation_melee_front"
			{call "attack_melee_swipe_fwd_armed"}
		}
		{if stuff "orientation_melee_stab"
			{call "attack_melee_swipe_stab_armed"}
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
		("health" energy(20) 				health(+3))
		("health" energy(15) 				health(+1.75))
		("health" energy(10) 				health(+1))
		("health" energy(7) 				health(+0.55))
		("health" energy(5) 				health(+0.45))
		("health" energy(3) 				health(+0.4))
		("health" energy(1) 				health(+0.2))
		("orientation" vol(front_left_hit)  	ani_play(hit_stumble_45ccw)   rand(0.5)  min_energy(0.5) )
		("orientation" vol(front_right_hit)  	ani_play(hit_stumble_45cw)    rand(0.5)  min_energy(0.5) )
		("orientation" vol(back_left_hit)  		ani_play(hit_stumble_135cw)   rand(0.5)  min_energy(0.5) )
		("orientation" vol(back_right_hit)  	ani_play(hit_stumble_135ccw)  rand(0.5)  min_energy(0.5) )
	}
	;{on animation_event "5heal" 
	;}
	{on pierce sync;hunter
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
			("stuff_pierce" stuff(shell fg) 			stuff_break(0.5) 	)
			("stuff_pierce" stuff(shell ap) 			stuff_break(0.7) 		)			
			("stuff_pierce" stuff(shell) 				stuff_break(1)		)
			("stuff_pierce" stuff(rocketlauncher) 		stuff_break(1)		)
			("stuff_pierce" stuff(zenite cs) 			stuff_break(0.6)		)
			("stuff_pierce" stuff(zenite fg) 			stuff_break(0.3)		)
			("stuff_pierce" stuff(zenite) 				stuff_break(0.4)		)
			("stuff_pierce" stuff(bullet big ap) 		stuff_break(0.45)		)
			("stuff_pierce" stuff(bullet big fg) 		stuff_break(0.2)		)
			("stuff_pierce" stuff(bullet big) 			stuff_break(0.4)		)
			("stuff_pierce" stuff(bullet normal ap) 	stuff_break(0.3)	)
			("stuff_pierce" stuff(bullet normal fg) 	stuff_break(0.2)		)
			("stuff_pierce" stuff(bullet normal) 		stuff_break(0.2)		)
			("stuff_pierce" stuff(bullet small) 		stuff_break(0.1)		)
		)		
		("mesh_break" component(hips)  				 				stuff_destroy(0.2)    )
		("mesh_break" component(main_body)  				 		stuff_destroy(0.2)    )
		("mesh_break" component(head)  				 				stuff_destroy(0.2)    )
		("mesh_break" component(cpu)  				 				stuff_destroy(0.3)    )
		("mesh_break" component(engine)  			 				stuff_destroy(0.3)    )
		
		("mesh_break" component(front_core_panel)  					 stuff_destroy(0.35)    )
		("mesh_break" component(structure_plate_right)  			 stuff_destroy(0.35)    )
		("mesh_break" component(structure_plate_left)  				 stuff_destroy(0.35)    )
		("mesh_break" component(back_hatch_l)  						 stuff_destroy(0.35)    )
		("mesh_break" component(back_hatch_r)  						 stuff_destroy(0.35)    )
		("mesh_break" component(front_hatch_l)  					 stuff_destroy(0.35)    )
		("mesh_break" component(front_hatch_r)  					 stuff_destroy(0.35)    )
		("mesh_break" component(pestcontainer)  					 stuff_destroy(0.35)    )
		("mesh_break" component(engine_move)  						 stuff_destroy(0.35)    )
		("mesh_break" component(left_engine)  						 stuff_destroy(0.35)    )
		("mesh_break" component(left_engine2)  						 stuff_destroy(0.35)    )
		("mesh_break" component(right_engine)  						 stuff_destroy(0.35)    )
		("mesh_break" component(right_engine2)  					 stuff_destroy(0.35)    )
		("mesh_break" component(sideplate_left)  					 stuff_destroy(0.35)    )
		("mesh_break" component(sideplate_right)  					 stuff_destroy(0.35)    )
		("mesh_break" component(head_sideplate_front_r)  			 stuff_destroy(0.35)    )
		("mesh_break" component(head_sideplate_front_l)  			 stuff_destroy(0.35)    )
		("mesh_break" component(head_sideplate_back_r)  			 stuff_destroy(0.35)    )
		("mesh_break" component(head_sideplate_back_l)  			 stuff_destroy(0.35)    )
		
		("mesh_break" component(legplate_right)  			 		stuff_destroy(0.35)    )
		("mesh_break" component(legplate_left)  			 		stuff_destroy(0.35)    )

		("mesh_break" component(shoulder_plate_left)  			 	stuff_destroy(0.35)    )
		("mesh_break" component(shoulder_plate_right)  			 	stuff_destroy(0.35)    )

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

		;hunter
		("mesh_break" component(armour_prot_right)  		 		stuff_destroy(0.2))
		("mesh_break" component(armour_prot_left)  		 			stuff_destroy(0.2))
		("mesh_break" component(cyl_prot_plate_left)  		 		stuff_destroy(0.2))
		("mesh_break" component(cyl_prot_plate_right)  		 		stuff_destroy(0.2))
		
		("mesh_break" component(head_sideplate_front_l)  	 		stuff_destroy(0.2))
		("mesh_break" component(head_sideplate_front_r)  	 		stuff_destroy(0.2))
		("mesh_break" component(head_sideplate_back_l)  	 		stuff_destroy(0.2))
		("mesh_break" component(head_sideplate_back_r)  	 		stuff_destroy(0.2))
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
		{delay 5 "idle"
			{if not "exploded"
				{if not tagged "play_idle"
					{if rand 0.3
						{ani_play "idle_loop_var_01" }
					else rand 0.3
						{ani_play "idle_loop_var_02" }
					else rand 0.3
						{ani_play "idle_loop_var_03" }
					else
						{delay 40 20 "idle"
							{call "idle_try"}
						}
					}
				}
			}
		}
	}
	{on "drop_pest_reload"
		{tags add "egg_deploy1"}
		{tags remove "egg_deploy2"}
		{tags remove "egg_deploy3"}
		{tags remove "egg_deploy4"}
		(define "drop"
			{tags remove "egg%0"}
			{bone show "egg%0"}
		)
		("drop" args 00)
		("drop" args 01)
		("drop" args 02)
		("drop" args 03)
	}			
	{on "drop_pest"
		{start_sound "generation_zero/characters/pest/reinforcement_pod"}
		{ani_play "drop_pest"}
		{call "drop_speed_move"}
		{delay 1
			{if tagged "egg_deploy1"
				{tags add "egg_deploy2"}
				{tags remove "egg_deploy1"}
				{bone hide "egg00"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_00" x {impulse forward 0.5 0.5}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_00" x {impulse forward 0.5 0.5} {call "unlink"}}
				}
			else tagged "egg_deploy2"
				{bone hide "egg01"}
				{tags remove "egg_deploy2"}
				{tags add "egg_deploy3"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_01" x {impulse forward 0.5 0.5}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_01" x {impulse forward 0.5 0.5} {call "unlink"}}
				}
			else tagged "egg_deploy3"
				{bone hide "egg02"}
				{tags remove "egg_deploy3"}
				{tags add "egg_deploy4"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_02" x {impulse forward 0.5 0.5}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_02" x {impulse forward 0.5 0.5} {call "unlink"}}
				}
			else tagged "egg_deploy4"
				{bone hide "egg03"}
				{tags remove "egg_deploy4"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_03" x {impulse forward 0.5 0.5}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_03" x {impulse forward 0.5 0.5} {call "unlink"}}
				}
			}				
		}			
		{delay 4
			{ani_play "drop_pest" -1}
		}
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
	{on animation_event "runstart_f" ;dread hunter skir
		{if tagged "move"
			{call "move_update_f"}
		else
			{ani_play "runstop_f" 1}
		}
	}	
	{on move on 
		{kill_delay "move_stop"}
		{tags add "walk"}
		{call "stop_idle"}
		{set "blocked" 1}
		{if not tagged "turn"
			{tags add "move_forward"}
			{tags add "move"}
			{call "walkstart_f"}
			{call "weapon_melee_off"}
			{call "weapon_off"}
		}
	}
	{on "walkstart_f"
		{if not tagged "walkstart_f"		
			{tags add "walkstart_f"}
			{delay 0
				{if tagged "move"
					{ani_play "walkstart_f"  }
				}				
			}
		}	
	}	
	{on turn on ; all
		{call "weapon_melee_off"}
		{call "weapon_off"}
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
	{on turn off ; add remove tags left right
		{delay 0.5 "move_stop"
			{call "weapon_on"}
			{call "weapon_melee_on"}
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
		{tags remove "move_backward"}	
		{tags remove "move"}	
		{tags remove "turn"}
		{tags remove "run"}
		{tags remove "walk"}
		{delay 1 "move_stop"
			{call "weapon_on"}
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
;	{on animation_event "walkstop_f_start" 
;		{tags add "walkstop_f"}
;	}
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
	{on animation_event "walkloop_f" ; цикл ходьбы
		{if not tagged "jump"
			{call "move_update_walk_hunter"}
		}
	}
	{on "move_update_walk_hunter"  
		(define "move_update_hunter"
			{if tagged "move"		
				{if not tagged "walkstop_f"		
					{if velocity %speed
						{ani_play "walkloop_fwd" (* %speed 1) }
					}
				}
			else ;выполнение остановки если дали тэг
				{call "walkstop_f_hunter"}				
			}
		)		
		("move_update_hunter" speed(19)  	)
		("move_update_hunter" speed(18)  	)
		("move_update_hunter" speed(17)  	)
		("move_update_hunter" speed(16)  	)
		("move_update_hunter" speed(15)  	)
		("move_update_hunter" speed(14)  	)
		("move_update_hunter" speed(13)  	)
		("move_update_hunter" speed(12)  	)
		("move_update_hunter" speed(11)  	)
		("move_update_hunter" speed(10)  	)
		("move_update_hunter" speed(9)  	)
		("move_update_hunter" speed(8)		)
		("move_update_hunter" speed(7) 	)
		("move_update_hunter" speed(6) 	)
		("move_update_hunter" speed(5) 	)
		("move_update_hunter" speed(4) 	)
		("move_update_hunter" speed(3) 	)
		("move_update_hunter" speed(2)  	)
		("move_update_hunter" speed(1)  	)
	}	
	{on animation_event "walkstart_hf_end" 
		{tags remove "walkstart_f"}
		{if not tagged "turn"
			{if tagged "move"
				{call "move_update_walk_hunter"}
			else
				{call "walkstop_f_hunter"} ;если не пошёл
			}
		}	
	}
	{on animation_event "walkstop_f_exit" 
		{tags remove "walkstop_f"}
	}
	{on "walkstop_f_hunter"; вызов стопа после старта
		{if not tagged "turn"		
			{if not tagged "walkstop_f"		
				{tags add "walkstop_f"}
				{ani_stop "walkstart_f"  }
				{ani_stop "walkloop_f"  }
				{ani_play "walkstop_f"  }
			}	
		}	
	}	
	{on "weapon_melee_on"
		{if work "body"
			{with_linked_entity "link_melee"
				{call "open"}
			}
		}
	}
	{on "weapon_melee_off"
		{if work "body"
			{with_linked_entity "link_melee"
				{call "close"}
			}
		}
	}
	{on "weapon_on"
		{if work "mgun"
			{weapon_work "mgun" 1}
		}
		{if work "gun"
			{weapon_work "gun" 1}
		}		
	}
	{on "weapon_off"
		{weapon_work "gun" 0}
		{weapon_work "mgun" 0}
	}
	{on "reload"  ;hunter
		{if tagged "fire_mgun"
			{if work "mgun"
				{tags add "mgun_r"}
				{weapon_work "mgun" 0}
				{delay 12
					{if work "mgun"
						{delay 0.5
							{tags remove "mgun_r"}
							{weapon_work "mgun" 1}
						}
					}
				}
			}
		else tagged "fire_gun"
			{if work "gun"
				{tags add "gun_r"}
				{weapon_work "gun" 0}
				{delay 0.6			
					{ani_play "reload_rocket"  }
				}					
				{delay 3.4
					{if work "gun"
						{delay 0.5
							{tags remove "gun_r"}
							{weapon_work "gun" 1}
						}
					}
				}
			}		
		else tagged "fire_pestcontainer_drop"
			{if work "pestcontainer_drop"
				{tags add "pestcontainer_drop_r"}
				{delay 340
					{call "drop_pest_reload"}
					{if work "pestcontainer_drop"
						{tags remove "pestcontainer_drop_r"}
					}
				}
			}		
		}
	}
	{on "attack_melee_swipe_stab_armed"
		{if not tagged "attack_melee_stab_armed"
			{tags add "attack_melee_stab_armed"}	
			{tags remove "hold"}	
			{tags add "alarm"}	
			{tags remove "search"}
			{call "ai_talk_signal"}
			{ani_play "attack_melee_stab" 1}
			{if rand 0.4
				{start_sound "generation_zero/characters/hunter/target/50_01_dmono_2ch"}	
				{start_sound "generation_zero/characters/hunter/target/50_01_dmono_bb"}	
			else 
				{start_sound "generation_zero/characters/hunter/target/50_02_dmono_2ch"}	
				{start_sound "generation_zero/characters/hunter/target/50_01_dmono_bb"}	
			}
			{delay 60
				{tags remove "attack_melee_stab_armed"}
			}	
		}	
	}
	{on "attack_melee_swipe_bwd_armed"
		{if not tagged "attack_melee_swipe_bwd_armed"
			{tags add "attack_melee_swipe_bwd_armed"}	
			{tags remove "hold"}	
			{tags add "alarm"}	
			{tags remove "search"}
			{call "ai_talk_signal"}
			{ani_play "attack_melee_swipe_bwd" 1}
			{if rand 0.4
				{start_sound "generation_zero/characters/hunter/target/50_01_dmono_2ch"}	
				{start_sound "generation_zero/characters/hunter/target/50_01_dmono_bb"}	
			else 
				{start_sound "generation_zero/characters/hunter/target/50_02_dmono_2ch"}	
				{start_sound "generation_zero/characters/hunter/target/50_01_dmono_bb"}	
			}
			{delay 8
				{tags remove "attack_melee_swipe_bwd_armed"}
			}	
		}	
	}
	{on "attack_melee_swipe_fwd_armed"
		{if not tagged "attack_melee_swipe_fwd_armed"
			{tags add "attack_melee_swipe_fwd_armed"}	
			{tags remove "hold"}	
			{tags add "alarm"}	
			{tags remove "search"}
			{call "ai_talk_signal"}
			{ani_play "attack_melee_swipe_fwd" 1}
			{if rand 0.4
				{start_sound "generation_zero/characters/hunter/target/50_01_dmono_2ch"}	
				{start_sound "generation_zero/characters/hunter/target/50_01_dmono_bb"}	
			else 
				{start_sound "generation_zero/characters/hunter/target/50_02_dmono_2ch"}	
				{start_sound "generation_zero/characters/hunter/target/50_01_dmono_bb"}	
			}
			{delay 8
				{tags remove "attack_melee_swipe_fwd_armed"}
			}	
		}	
	}
	{on animation_event "explosion_hunter" 
		{tags add "explosion_hunter"}
		{call "explosion_hunter"}
	}
	{on fire "alarm_signal"   ;hunter base
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
	;-------evs
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
	{on animation_event "scanlines_open"  ;skir scout hunter
		{bone show "scanlines_2"}
		{bone show "scanlines"}
	}
	{on animation_event "scanlines_hide"  ;skir scout
		{bone hide "scanlines_2"}
		{bone hide "scanlines"}
	}
	{on animation_event "bullet_drop_view" ;hunter lynx skir skir_shotg_w 
		{view show "shell"}	
		{view show "shell_drop"}	
		{view show "shell_drop_masterkey"}	
		{view show "shell_drop_sniper"}	
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
	{on animation_event "clear_casing_12x55_sniper" ;hunter
		{spawn "shell_eject_shell12" "j_recoil_sniper" }	;link sound with bone fix
		;{spawn "fx_eject_smoke2" "shell_drop" }		
		;{start_sound "weapon/shell_eject/shell12"}	
		{tear "shell_drop_12_55" bone "shell_drop_sniper" copy ;slicer_tail
			{impulse forward 5 cx -0.2 0.2 com  }
		}
		{delay 0
			{view hide "shell_drop_sniper"}	
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
		{burn volume "front_hatch_r" fx "smoke_heat" time 5 fake even_law}					
		{burn volume "front_hatch_l" fx "smoke_heat" time 5 fake even_law}					
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
		{components "front_hatch_r" break}
		{components "front_hatch_l" break}
		{components "back_hatch_l" break}
		{components "back_hatch_r" break}
	}
	;----------------------------------------------------------------death hunter
	{on animation_event "death_r_bwd_hunter_01"
		{spawn "hit_fall" "pestcontainer_arm"}
		{if rand 0.3
			{spawn "break_small_body_robot" "neck1"}
		else rand 0.3
			{spawn "break_small_body_robot" "cpu"}
		else rand 0.3
			{spawn "break_small_body_robot" "front_hatch_r"}
		else
			{spawn "break_small_body_robot" "front_hatch_l"}
		}	
	}
	{on animation_event "death_r_bwd_hunter_01front"
		{spawn "hit_fall" "neck"}
		{if rand 0.3
			{spawn "break_small_body_robot" "neck1"}
		else rand 0.3
			{spawn "break_small_body_robot" "cpu"}
		else rand 0.3
			{spawn "break_small_body_robot" "front_hatch_r"}
		else
			{spawn "break_small_body_robot" "front_hatch_l"}
		}	
	}
	{on animation_event "death_r_bwd_hunter_02"
		{if rand 0.3
			{tear "piece_big_steel" bone "turret_link_ik_v3"
				{burn volume fx "smoke_bats" time 1 fake even_law}					
			}
		else rand 0.2
			{tear "piece_medium_steel" bone "head_sideplate_front_l"
			}
		else rand 0.2
			{tear "piece_medium_steel" bone "head_sideplate_front_r"
			}
		else rand 0.2
			{tear "piece_medium_steel" bone "head_sideplate_back_l"
			}
		else rand 0.2
			{tear "piece_medium_steel" bone "head_sideplate_back_r"
			}
		}	
	}
	{on animation_event "death_r_bwd_hunter_03"
		{if rand 0.3
			{spawn "break_small_body_robot" "LeftCableLegSM1"}
		else rand 0.3
			{spawn "break_small_body_robot" "RightCableLegSM"}
		else rand 0.3
			{spawn "break_small_body_robot" "leftCableLegSM"}
		else rand 0.3
			{spawn "break_small_body_robot" "CableHeadSM"}
		else rand 0.3
			{spawn "break_small_body_robot" "leftCableArmSM"}
		else rand 0.3
			{spawn "break_small_body_robot" "RightCableArmSM"}
		}	
	}
	;----------------------------------------------------------------	
	{on animation_event "hunter_melee_stab_start_c4"
		{if rand 0.3
			{start_sound "generation_zero/characters/hunter_c4/melee_attack/hunt_c4_melee_attack_clr_25"}	
			{start_sound "generation_zero/characters/hunter_c4/melee_attack/hunt_c4_melee_attack_bb_25"}	
		else rand 0.3
			{start_sound "generation_zero/characters/hunter_c4/melee_attack/hunt_c4_melee_attack_clr_26"}	
			{start_sound "generation_zero/characters/hunter_c4/melee_attack/hunt_c4_melee_attack_bb_26"}	
		else rand 0.3
			{start_sound "generation_zero/characters/hunter_c4/melee_attack/hunt_c4_melee_attack_clr_27"}	
			{start_sound "generation_zero/characters/hunter_c4/melee_attack/hunt_c4_melee_attack_bb_27"}	
		else 
			{start_sound "generation_zero/characters/hunter_c4/melee_attack/hunt_c4_melee_attack_clr_28"}	
			{start_sound "generation_zero/characters/hunter_c4/melee_attack/hunt_c4_melee_attack_bb_28"}	
		}
		{tags remove "hold"}	
		{tags add "alarm"}	
		{tags remove "search"}
		{call "ai_talk_signal"}
	}
	{on animation_event "hunter_melee_stab_start"
		{if rand 0.3
			{start_sound "generation_zero/characters/hunter/melee_attack/hunter_voc_meleeattack_01_dir"}	
			{start_sound "generation_zero/characters/hunter/melee_attack/hunter_voc_meleeattack_01_bb"}	
		else rand 0.3
			{start_sound "generation_zero/characters/hunter/melee_attack/hunter_voc_meleeattack_02_dir"}	
			{start_sound "generation_zero/characters/hunter/melee_attack/hunter_voc_meleeattack_02_bb"}	
		else rand 0.3
			{start_sound "generation_zero/characters/hunter/melee_attack/hunter_voc_meleeattack_03_dir"}	
			{start_sound "generation_zero/characters/hunter/melee_attack/hunter_voc_meleeattack_03_bb"}	
		else 
			{start_sound "generation_zero/characters/hunter/melee_attack/hunter_voc_meleeattack_04_dir"}	
			{start_sound "generation_zero/characters/hunter/melee_attack/hunter_voc_meleeattack_04_bb"}	
		}
		{tags remove "hold"}	
		{tags add "alarm"}	
		{tags remove "search"}
		{call "ai_talk_signal"}
	}
	{on animation_event "landed" ;'
		{start_sound "generation_zero/characters/hunter/melee_stab_ground/"}
		{if tagged "grass"			
			{spawn "bullet_shellhole_big_grass" "blade_overlap_02"}
		else tagged "ground"	
			{spawn "bullet_shellhole_big_ground" "blade_overlap_02"}
		else tagged "gravel"	
			{spawn "bullet_shellhole_big_road" "blade_overlap_02"}
		}
		{spawn "dust_jump_hunter" "RightFinger"}
		{spawn "damage_blade" "blade_overlap_03" }	
		{spawn "damage_blade" "blade_overlap_02" }	
		{spawn "damage_blade" "blade_overlap_01" }	
		{spawn "damage_blade" "rightfinger" }	
		{spawn "damage_blade" "blade_overlap_01" }	
	}
	{on animation_event "melee_warning"
		{view start "melee_warning"}
		{view show "melee_warning"}
		{delay 1
			{view hide "melee_warning"}
			{view pause "melee_warning"}
		}
	}
	{on animation_event "hunter_jump"
		{start_sound "generation_zero/characters/hunter/melee_leap"}	
		{spawn "dust_jump_hunter" "basis"}
	}
	{on animation_event "hunter_run_start"
		{tags add "run"}
	}
	{on animation_event "hunter_run_exit"
		{tags remove "run"}
	}
	{on animation_event "joint_med_in"
		{call "fx_component_mover"}
		{if tagged "run"
			{start_sound "generation_zero/characters/skirmisher/joint/run/in/"}			
		else
			{start_sound "generation_zero/characters/hunter/joint/walk/in/"}			
		}	
	}
	{on animation_event "joint_med_out"
		{call "fx_component_mover"}
		{if tagged "run"
			{start_sound "generation_zero/characters/skirmisher/joint/run/out/"}			
		else
			{start_sound "generation_zero/characters/hunter/joint/walk/out/"}			
		}	
	}
	{on animation_event "foot_hunter_l"
		{spawn "footstep_hunter" "footstep_hoof_l" x terrain_texmod}
		{if rand 0.3
			{spawn "dust_med_skirmisher" "footstep_hoof_l"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/hunter/move/%0/"}	
			
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_hunter_r"
		{spawn "footstep_hunter" "footstep_hoof_r" x terrain_texmod}
		{if rand 0.3
			{spawn "dust_med_skirmisher" "footstep_hoof_r"}
		}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/hunter/move/%0/"}	
			
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_hunter_l_run"
		{spawn "footstep_hunter" "footstep_hoof_l" x terrain_texmod}
		{spawn "dust_med_hunter_run" "footstep_hoof_l"}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/hunter/move/%0/"}	
			
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_hunter_r_run"
		{spawn "footstep_hunter" "footstep_hoof_r" x terrain_texmod}
		{spawn "dust_med_hunter_run" "footstep_hoof_r"}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/hunter/move/%0/"}	
			
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "block_all_hunter" ;hunter
		{chassis_work 0}
		{weapon_work "mgun" 0}
		{weapon_work "head_joint" 0} ;head_joint
		{weapon_work "attack_melee_swipe_fwd" 0}
		{weapon_work "attack_melee_swipe_bwd" 0}
		{weapon_work "attack_melee_charge" 0}
		{weapon_work "gun" 0}
	
	}
	{on animation_event "block_all_hunter_melee" ;hunter
		{chassis_work 0}
		{auto_operatable 0}
		{drop_orders}
		{able select 0}
	}
	{on animation_event "unblock_all_hunter_melee" ;hunter
		{if work "fuel"
			{chassis_work 1}
		}
		{auto_operatable 1}
		{able select 1}
	}
	{on animation_event "unblock_all_hunter";hunter
		{if work "fuel"
			{chassis_work 1}
		}
		{if work "mgun"
			{weapon_work "mgun" 1}
		}
		{if work "head_joint"
			{weapon_work "head_joint" 1};head_joint
		}
		;{if work "attack_melee_swipe_fwd"
		{weapon_work "attack_melee_swipe_fwd" 1};mgun_melee_front
		;}
		;{if work "attack_melee_swipe_bwd"
		{weapon_work "attack_melee_swipe_bwd" 1} ;mgun_melee_back
		;}
		{if work "gun"
			{weapon_work "gun" 1}
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
 
	{on animation_event "retract_blade"
		{tags add "blade_on"}
		{spawn "blade_pull_fx" "blade_fx" x}
		{start_sound "generation_zero/characters/hunter/melee_retract_blade/"}	
	}
	{on animation_event "melee_blade_pull"
		{start_sound "generation_zero/characters/hunter/melee_blade_pull/"}	
	}
	{on animation_event "melee_extend_blade"
		{tags remove "blade_on"}
		{start_sound "generation_zero/characters/hunter/melee_extend_blade/"}	
	}
	{on animation_event "melee_stab_swing" ;добавить пыль н земле
		{view start "blade_melee"}
		{delay 0.2
			{view pause "blade_melee"}
		}
		{start_sound "generation_zero/characters/hunter/melee_stab_swing/"}	
	}
	{on animation_event "blade_damage" 	
		;{spawn "damage_blade" "link_melee" }	
		{spawn "damage_blade" "blade_overlap_03" }	
		{spawn "damage_blade" "blade_overlap_00" }	
		{spawn "damage_blade" "blade_overlap_01" }	
	}
	{on animation_event "blade_damage_big" 	
		{spawn "damage_blade" "link_melee" }	
		{spawn "damage_shock_micro" "link_melee" }	
	}
	{on "tear_parts_explode_hunter"
		(define "blast_hunter"
			{if rand %1
				{tear "piece_small_steel" bone %0
					{impulse up 2 1 dir 12 5 cx 3 2 cy 3 2 no_position}
				}
			}
		)
		("blast_hunter" args "head_sideplate_front_r" 				0.3)
		("blast_hunter" args "head_sideplate_back_r" 				0.3)	
		("blast_hunter" args "head_sideplate_back_l" 				0.3)	
		("blast_hunter" args "head_sideplate_front_l" 				0.3)	
		("blast_hunter" args "armour_head_upper" 			0.1)	
		("blast_hunter" args "armour_head_lower" 			0.1)	
		("blast_hunter" args "armour_prot_left" 			0.2)	
		("blast_hunter" args "armour_prot_right" 			0.2)	
		("blast_hunter" args "cyl_prot_plate_left" 			0.2)	
		("blast_hunter" args "cyl_prot_plate_right" 		0.3)	
		("blast_hunter" args "visor_body" 					0.3)	
	}
	
	{on "explosion_hunter" 
		{if not able "exploded"			
			{set "exploded" 1}		
			{able "exploded" 1}
			{stop_sound "engine" }
			;{bone hide ""}
			;{mtl_enable_skin 0}
			{tags add "off"}
			{tags add "dead"}
			{call "stop_all"}
			{call "tear_parts_explode_hunter"}
			{if tagged "move"
				{if rand 0.5
					{ani_play "death_l_fwd"}
				else
					{ani_play "death_r_fwd"}
				}
			else
				{if rand 0.5
					{ani_play "death_l_bwd"}
				else
					{ani_play "death_r_bwd"}
				}
			}
			{burn volume "cpu" fx "fx_fire_engine_gen" time 2 fake even_law}					
			{burn volume "organs_engine_drive_left" fx "smoke_heat" time 5 fake even_law}	
			{burn volume "organs_engine_drive_right" fx "smoke_heat" time 5 fake even_law}	
			;{burn volume "front_hatch_r" fx "smoke_heat" time 5 fake even_law}	
			;{burn volume "front_hatch_l" fx "smoke_heat" time 5 fake even_law}	
			{view start "front_hatch_r_destroy"}
			{view show "front_hatch_r_destroy"}
			{view start "front_hatch_l_destroy"}
			{view show "front_hatch_l_destroy"}			
			{kill_delay "idle"}
			{drop_orders}
			{delay 0.5
				{components destroy}
			}
			{reset_manual_control}
			{auto_operatable 0}
			{able select 0}
			{able repaired 0}
			{with_linked_entity "link_front"
				{delete}
			}			
			{clear_inventory}
			{spawn "destroy_med_robot" "hips"}
			{spawn "burn_flare" "head"}
		}
	}
	; {on fire "attack_melee_swipe_fwd"   ;hunter melee_front
		; {tags remove "hold"}	
		; {tags add "alarm"}	
		; {tags remove "search"}
		; {call "ai_talk_signal"}
		; {tags add "fire_mgun_melee_front"}
		; {ani_play "attack_melee_swipe_fwd" 1}
		; {if rand 0.4
			; {start_sound "generation_zero/characters/hunter/target/50_01_dmono_2ch"}	
			; {start_sound "generation_zero/characters/hunter/target/50_01_dmono_bb"}	
		; else 
			; {start_sound "generation_zero/characters/hunter/target/50_02_dmono_2ch"}	
			; {start_sound "generation_zero/characters/hunter/target/50_01_dmono_bb"}	
		; }
		; {delay 0.3
			; {tags remove "fire_mgun_melee_front"}
		; }	
	; }
	; {on fire "attack_melee_swipe_bwd" ;hunter melee_back
		; {tags remove "hold"}	
		; {tags add "alarm"}	
		; {tags remove "search"}
		; {call "ai_talk_signal"}
		; {tags add "fire_mgun_melee_back"}
		; {ani_play "attack_melee_swipe_bwd" 1}
		; {if rand 0.4
			; {start_sound "generation_zero/characters/hunter/target/50_01_dmono_2ch"}	
			; {start_sound "generation_zero/characters/hunter/target/50_01_dmono_bb"}	
		; else 
			; {start_sound "generation_zero/characters/hunter/target/50_02_dmono_2ch"}	
			; {start_sound "generation_zero/characters/hunter/target/50_01_dmono_bb"}	
		; }
		; {delay 0.3
			; {tags remove "fire_mgun_melee_back"}
		; }	
	; }
	{on fire "attack_pestdrop"  ;hunter
		{tags add "fire_pestcontainer_drop"}
		{call "drop_pest"}
		{delay 0.3
			{tags remove "fire_pestcontainer_drop"}
		}	
	}		
}
{"hunter_shotgun_sniper"
	{on fire "mgun" overload  ;hunter
		{tags remove "hold"}	
		{tags add "alarm"}	
		{tags remove "search"}
		{call "weapon_melee_off"}
		{call "ai_talk_signal"}
		{call "firing_block"}
		{tags add "fire_mgun"}
		{delay 0.3
			{tags remove "fire_mgun"}
		}	
		{if tagged "damage_main_mgun" {if rand 0.1 {call "jammed_mgun"}}}
		{tags add "firing"}
		{start_sound "weapon/shoot_loud/far/shotgun"}	
		{start_sound "weapon/shoot_loud/close/shotgun"}	
		{delay 3 "firing"
			{tags remove "firing"}
		}
		{ani_play "recoil_shotgun" }		
		{spawn "distant_small" "foresight_main" }
		{tags remove "idle_enter"}
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{tags add "buck"}
		{tags remove "slug"}
		{view start "fx_muzzle_buck"}
		{view show "fx_muzzle_buck"}
		{delay 0.1 "fire"
			{view start "smoke"}
			{view start "smoke_recoil"}
			{view hide	"fx_muzzle_buck"}
			{view pause	"fx_muzzle_buck"}
		}
	}		
	{on fire "gun"   
		{tags remove "hold"}	
		{tags add "alarm"}	
		{tags remove "search"}
		{call "weapon_melee_off"}
		{call "ai_talk_signal"}
		{call "firing_block"}
		{ani_play "recoil_sniper"}
		{tags add "fire_gun"}
		{delay 0.3
			{tags remove "fire_gun"}
		}	
		{if tagged "damage_main_gun" {if rand 0.1 {call "jammed_mgun"}}}
		{view start "fx_main_sniper"}
		{view show "fx_main_sniper"}
		{delay 0.1 "fire"
			{view show	"fx_fire_hot_sniper"}
			{view start	"fx_fire_hot_sniper"}
			{view hide	"fx_main_sniper"}
			{view pause	"fx_main_sniper"}
		}
		{delay 1.4 0.7 "fire_hot"
			{view hide	"fx_fire_hot_sniper"}
			{view pause	"fx_fire_hot_sniper"}
		}
		{start_sound "weapon/shoot_loud/far/sniper"}	
		{start_sound "weapon/shoot_loud/close/sniper"}	
		{ani_play "recoil_sniper" }		
		{spawn "trace_linear" "foresight_sniper" x }
		{spawn "trace_linear" "foresight_sniper" x }
		{spawn "fx_shoot_hit_sparks" "foresight_sniper" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_sniper" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_sniper" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_sniper" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_sniper" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_sniper" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_sniper" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_sniper" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "foresight_sniper" }
		{tags remove "idle_enter"}
	}
}
{"hunter_smg_rocket"
	{on fire "gun" ;hunter
		{call "weapon_melee_off"}
		{tags remove "hold"}	
		{tags add "alarm"}	
		{tags remove "search"}
		{call "ai_talk_signal"}
		{call "firing_block"}
		{tags add "fire_gun"}
		{delay 0.3
			{tags remove "fire_gun"}
		}	
		{if tagged "damage_main_gun" {if rand 0.1 {call "jammed_mgun"}}}
		{tags remove "idle_enter"}
		(define "fire_barrel"
			name "%0"
				{spawn "shell_5m_fg_loader_auto" "shooter_%0" x {call "check_side"}}		
				{spawn "rpg_shot_small" "shooter_%0fx" x}			
		)
		{if   
			("fire_barrel" args 00)
		else 
			("fire_barrel" args 01)
		else
			("fire_barrel" args 02)
		else 
			("fire_barrel" args 03)
		}
	}
	{on fire "mgun" ;hunter
		{call "weapon_melee_off"}
		{tags remove "hold"}	
		{tags add "alarm"}	
		{tags remove "search"}
		{call "ai_talk_signal"}
		{call "firing_block"}
		{tags add "fire_mgun"}
		{delay 0.3
			{tags remove "fire_mgun"}
		}	
		{if tagged "damage_main_mgun" {if rand 0.1 {call "jammed_mgun"}}}
		{tags add "firing"}
		{start_sound "weapon/shoot_loud/far/shotgun"}	
		{start_sound "weapon/shoot_loud/close/shotgun"}	
		{delay 3 "firing"
			{tags remove "firing"}
		}
		{ani_play "recoil_mgun" }		
		{spawn "distant_small" "foresight_main" }
		{tags remove "idle_enter"}
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{tags add "buck"}
		{tags remove "slug"}
		{view start "fx_muzzle_mgun"}
		{view show "fx_muzzle_mgun"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle_mgun"}
			{view pause	"fx_muzzle_mgun"}
		}
		{tear "shell_drop_small" bone "shell_drop" copy 
			{impulse cx -0.1 com  }
		}
	}		
}
{"hunter_class_d"
	{on spawn
		{add_view "fly_tow_turn" "prestart_rocket00"	"shooter_fx00"}	
		{add_view "fly_tow_turn" "prestart_rocket01"	"shooter_fx01"}	
		{add_view "fly_tow_turn" "prestart_rocket02"	"shooter_fx02"}	
		{add_view "fly_tow_turn" "prestart_rocket03"	"shooter_fx03"}	
		{add_view "fly_tow_turn" "prestart_rocket04"	"shooter_fx04"}	
		{add_view "fly_tow_turn" "prestart_rocket05"	"shooter_fx05"}	
		{add_view "fly_tow_turn" "prestart_rocket06"	"shooter_fx06"}	
		{add_view "fly_tow_turn" "prestart_rocket07"	"shooter_fx07"}	
		{add_view "fly_tow_turn" "prestart_rocket08"	"shooter_fx08"}	
		{add_view "fly_tow_turn" "prestart_rocket09"	"shooter_fx09"}	
		{add_view "fly_tow_turn" "prestart_rocket10"	"shooter_fx10"}	
		{add_view "flamer_fire_gas"			"flame"	"foresight_main"}	
		{add_view "flammer_barrel_classd"	"flame_fx"	"flame_fx"}		
		{link_sound "start"	"weapon/shot/flame/handheld/flamer_start"}
		{link_sound "loop"	"weapon/shot/flame/handheld/flamer_loop"}
		{link_sound "end"	"weapon/shot/flame/handheld/flamer_stop"}	
		{add_view "exhaust_class_d_canister"	"canister_left_02_fx"	"canister_left_02_fx"}		
		{add_view "exhaust_class_d_canister"	"canister_left_01_fx"	"canister_left_01_fx"}		
		{add_view "exhaust_class_d_canister"	"canister_right_02_fx"	"canister_right_02_fx"}		
		{add_view "exhaust_class_d_canister"	"canister_right_01_fx"	"canister_right_01_fx"}				
		{view hide "canister_fx"}
		{view pause "canister_fx"}
		{view hide "prestart_rocket00"}
		{view pause "prestart_rocket00"}
		{view hide "prestart_rocket01"}
		{view pause "prestart_rocket01"}
		{view hide "prestart_rocket02"}
		{view pause "prestart_rocket02"}
		{view hide "prestart_rocket03"}
		{view pause "prestart_rocket03"}
		{view hide "prestart_rocket04"}
		{view pause "prestart_rocket04"}
		{view hide "prestart_rocket05"}
		{view pause "prestart_rocket05"}
		{view hide "prestart_rocket06"}
		{view pause "prestart_rocket06"}
		{view hide "prestart_rocket07"}
		{view pause "prestart_rocket07"}
		{view hide "prestart_rocket08"}
		{view pause "prestart_rocket08"}
		{view hide "prestart_rocket09"}
		{view pause "prestart_rocket09"}
		{view hide "prestart_rocket10"}
		{view pause "prestart_rocket10"}
		{view hide "flame"}
		{view pause "flame"}
		{view start "flame_fx"}
		{view show "flame_fx"}
	}
	{on "ai_talk_signal" overload
		{delay 0.2
			{if tagged "alarm"
				{tags remove "search"}
				{tags remove "hold"}
				{if not tagged "alarm_call"
					{tags add "alarm_call"}
					{if rand 0.2
						{start_sound "generation_zero/characters/hunter_c4/combat/hunt_c4_search_to_combat_clr_01"}	
						{start_sound "generation_zero/characters/hunter_c4/combat_bb/hunt_c4_search_to_combat_bb_01"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter_c4/combat/hunt_c4_search_to_combat_clr_02"}	
						{start_sound "generation_zero/characters/hunter_c4/combat_bb/hunt_c4_search_to_combat_bb_02"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter_c4/combat/hunt_c4_search_to_combat_clr_03"}	
						{start_sound "generation_zero/characters/hunter_c4/combat_bb/hunt_c4_search_to_combat_bb_03"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter_c4/combat/hunt_c4_search_to_combat_clr_04"}	
						{start_sound "generation_zero/characters/hunter_c4/combat_bb/hunt_c4_search_to_combat_bb_04"}	
					else
						{start_sound "generation_zero/characters/hunter_c4/combat/hunt_c4_search_to_combat_clr_05"}	
						{start_sound "generation_zero/characters/hunter_c4/combat_bb/hunt_c4_search_to_combat_bb_05"}	
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
					{if rand 0.2
						{start_sound "generation_zero/characters/hunter_c4/search/hunt_c4_combat_to_search_clr_16"}	
						{start_sound "generation_zero/characters/hunter_c4/search_bb/hunt_c4_combat_to_search_bb_16"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter_c4/search/hunt_c4_combat_to_search_clr_18"}	
						{start_sound "generation_zero/characters/hunter_c4/search_bb/hunt_c4_combat_to_search_bb_18"}	
					else rand 0.2
						{start_sound "generation_zero/characters/hunter_c4/search/hunt_c4_combat_to_search_clr_19"}	
						{start_sound "generation_zero/characters/hunter_c4/search_bb/hunt_c4_combat_to_search_bb_19"}	
					else 
						{start_sound "generation_zero/characters/hunter_c4/search/hunt_c4_combat_to_search_clr_20"}	
						{start_sound "generation_zero/characters/hunter_c4/search_bb/hunt_c4_combat_to_search_bb_20"}	
					}
				}
				{delay 2 {tags remove "search_call"}}
				;{burn volume "visor_ems" fx "yellow_burn" fake}
				{call "show_search"}
			else tagged "off"
				{tags remove "search"}
				{tags remove "hold"}
				{tags remove "alarm"}
				{view hide	"ems_global_alarm"}
				{view pause	"ems_global_alarm"}
				{view hide	"ems_global_search"}
				{view pause	"ems_global_search"}
				{view hide	"ems_global_hold"}
				{view pause	"ems_global_hold"}
				{call "show_hold"}
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
	{on fire "alarm_signal_fire"   
		{signal shot 5000}
		{tags add "alarm_signal_fire"}
		{call "fire_script_begin"}
		{tags remove "hold"}	
		{tags add "alarm"}	
		{tags remove "search"}
		{if not tagged "combat_call"
			{tags add "combat_call"}
			{spawn "wpn_alarm_clustermine" "v_drive_carrier_mount"}
		}
		{delay 1
			{ani_play "open_attack" 0.4}
			{spawn "small_mech_servo" "v_drive_carrier"}
			{ik_enable "v_drive_carrier_mount" 0}
			{ik_enable "v_drive_carrier" 0}
			{ik_enable "h_drive_carrier" 0}
		}
		{delay 2
			{tags remove "combat_call"}
			{if work "rocket"
				{call "gun_fire" }
			}
		}
		{delay 5
			{tags remove "alarm_signal_fire"}
		}
		{delay 12
			{ani_play "close_attack" 0.3}
			{spawn "small_mech_servo" "v_drive_carrier"}
			{ik_enable "v_drive_carrier_mount" 1}
			{ik_enable "v_drive_carrier" 1}
			{ik_enable "h_drive_carrier" 1}
			{call "fire_script_end"}
		}
	}
	{on "gun_fire" ;hunter		
		{call "weapon_melee_off"}
		{tags remove "hold"}	
		{tags add "alarm"}	
		{tags remove "search"}
		{call "ai_talk_signal"}
		{call "firing_block"}
		{tags add "fire_gun"}
		{delay 3
			{tags remove "fire_gun"}
		}	
		{tags remove "idle_enter"}
		{delay 0.5
			{view start "prestart_rocket00"}
			{delay 0.11
				{view pause "prestart_rocket00"}
				{spawn "shell_5m_fg_loader_cluster" "shooter00" x {call "check_side"}}		
				{spawn "rpg_shot_small" "shooter_fx00" x}{ani_play "recoil_rocket" 1}
				{bone hide "rocket00"}
				{delay 0.2
					{view start "prestart_rocket01"}
					{delay 0.11
						{view pause "prestart_rocket01"}
						{spawn "shell_5m_fg_loader_cluster" "shooter01" x {call "check_side"}}		
						{spawn "rpg_shot_small" "shooter_fx01" x}{ani_play "recoil_rocket" 1}
						{bone hide "rocket01"}
						{delay 0.2
							{view start "prestart_rocket02"}
							{delay 0.11
								{view pause "prestart_rocket02"}
								{spawn "shell_5m_fg_loader_cluster" "shooter02" x {call "check_side"}}		
								{spawn "rpg_shot_small" "shooter_fx02" x}{ani_play "recoil_rocket" 1}
								{bone hide "rocket02"}
								{delay 0.2
									{view start "prestart_rocket03"}
									{delay 0.11
										{view pause "prestart_rocket03"}
										{spawn "shell_5m_fg_loader_cluster" "shooter03" x {call "check_side"}}		
										{spawn "rpg_shot_small" "shooter_fx03" x}{ani_play "recoil_rocket" 1}
										{bone hide "rocket03"}
										{delay 0.2
											{view start "prestart_rocket04"}
											{delay 0.11
												{view pause "prestart_rocket04"}
												{spawn "shell_5m_fg_loader_cluster" "shooter04" x {call "check_side"}}		
												{spawn "rpg_shot_small" "shooter_fx04" x}{ani_play "recoil_rocket" 1}
												{bone hide "rocket04"}
												{delay 0.2
													{view start "prestart_rocket05"}
													{delay 0.11
														{view pause "prestart_rocket05"}
														{spawn "shell_5m_fg_loader_cluster" "shooter05" x {call "check_side"}}		
														{spawn "rpg_shot_small" "shooter_fx05" x}{ani_play "recoil_rocket" 1}
														{bone hide "rocket05"}
														{delay 0.2
															{view start "prestart_rocket06"}
															{delay 0.11
																{view pause "prestart_rocket06"}
																{spawn "shell_5m_fg_loader_cluster" "shooter06" x {call "check_side"}}		
																{spawn "rpg_shot_small" "shooter_fx06" x} {ani_play "recoil_rocket" 1}
																{bone hide "rocket06"}
																{delay 0.2
																	{view start "prestart_rocket07"}
																	{delay 0.11
																		{view pause "prestart_rocket07"}
																		{spawn "shell_5m_fg_loader_cluster" "shooter07" x {call "check_side"}}		
																		{spawn "rpg_shot_small" "shooter_fx07" x} {ani_play "recoil_rocket" 1}
																		{bone hide "rocket07"}
																		{delay 0.2
																			{view start "prestart_rocket08"}
																			{delay 0.11
																				{view pause "prestart_rocket08"}
																				{spawn "shell_5m_fg_loader_cluster" "shooter08" x {call "check_side"}}		
																				{spawn "rpg_shot_small" "shooter_fx08" x} {ani_play "recoil_rocket" 1}
																				{bone hide "rocket08"}
																				{delay 0.2
																					{view start "prestart_rocket09"}
																					{delay 0.11
																						{view pause "prestart_rocket09"}
																						{spawn "shell_5m_fg_loader_cluster" "shooter09" x {call "check_side"}}		
																						{spawn "rpg_shot_small" "shooter_fx09" x} {ani_play "recoil_rocket" 1}
																						{bone hide "rocket09"}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	{on fire "mgun"   ;hunter
		{spawn "ex_molot_fire_flamer" "foresight_main" x
			{impulse forward 15 rnd_dir 0.01 com}
			{gravity 0}
			{linear_damping 0}
		}
		{view start "flame"}
		{kill_delay "fire"}
		{if not tagged "fire_flame"
			{tags add "fire_flame"}
			{chassis_work 0}
			{play_sound "start"}
			{delay 0.1 "loop"
				{play_sound "loop" 1}
			}
		}
		{delay 0.2 "fire"
			{view pause "flame"}
			{tags remove "fire_flame"}
			{play_sound "end"}
			{kill_delay "loop"}
			{stop_sound "loop"}
			{delay 2 "fire"
				{if work "fuel"
					{chassis_work 1}
				}
			}
		}
	}
}

