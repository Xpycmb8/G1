{"dreadnought_base"
	{inflammation_time 40}
	{on spawn
		;{movement_limit fast}
		;{movement_limit normal}
;		{add_view	""			"combat"		"combat_link"}
		; {view hide	"combat"}
		; {view stop	"combat"}
		; {link_sound "combat" 	"generation_zero/characters/skirmisher/armed"}
		{link_sound "engine" 	"generation_zero/characters/dreadnought/engine/machine_other_engine_02"}
		{link_sound "engine_hiss" 	"generation_zero/characters/dreadnought/engine/machine_whine_08_2ch"}
		{link_sound "power_up" 		"generation_zero/characters/dreadnought/power_up/drea_concussion_riser_01"}
		;{start_sound "generation_zero/characters/dreadnought/spawn/"}	
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
		{add_view 	"muzzle_gun30_auto" 		"fx_muzzle00" 	"shooter_mg00"}
		{add_view 	"muzzle_gun30_auto" 		"fx_muzzle01" 	"shooter_mg01"}

		{add_view 	"yellow_ems" 								"ems_global_search" "head_ems_bone"}
		{add_view 	"yellow_light" 								"ems_global" "head_light_small_00_fx"}
		{add_view 	"yellow_light" 								"ems_global" "head_light_small_01_fx"}
		{add_view 	"yellow_light" 								"ems_global" "head_light_small_02_fx"}
		{add_view 	"headlight_led6000k_med" 					"ems_global" "headlight_l"}
		{add_view 	"headlight_led6000k_med" 					"ems_global" "headlight_r"}
		{add_view 	"headlight_led6000k_med" 					"ems_global" "head_light_00_fx"}

		{add_view 	"close_attack_light" 					"close_attack_dread" 	"head_light_00_fx"}
		{add_view 	"close_attack_light" 					"close_attack_dread" 	"head_light_small_00_fx"}
		{add_view 	"close_attack_light" 					"close_attack_dread" 	"head_light_small_01_fx"}
		{add_view 	"close_attack_light" 					"close_attack_dread" 	"head_light_small_02_fx"}

		{add_view 	"heat_stage1_big" 					"stage1" "shooter_mg00"}
		{add_view 	"heat_stage1_big" 					"stage1" "shooter_mg01"}

		{add_view 	"heat_stage2_big" 					"stage2" "shooter_mg00"}
		{add_view 	"heat_stage2_big" 					"stage2" "shooter_mg01"}

		{add_view 	"heat_stage2_fire_big" 					"stage2_fire" "shooter_mg00"}
		{add_view 	"heat_stage2_fire_big" 					"stage2_fire" "shooter_mg01"}

		{add_view 	"start_bgm" 				"fx_muzzle" 	"fx_shoot"}
		
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

		{add_view 	"pneu_tiny" 					"fans1" "backfan_01"}
		{add_view 	"pneu_tiny" 					"fans2" "backfan_02"}
		{add_view 	"pneu_tiny" 					"fans3" "backfan_03"}

		;burn_element
		{add_view 	"burn_element_cpu" 			"cpu_burn" "cpu"}
		{add_view 	"smoke_element_cpu" 		"cpu_smoke" "cpu"}

		{add_view 	"burn_element" 			"burn_missile" "foresight_gun"}
		{add_view 	"burn_element" 			"burn_missile" "foresight_gun"}
				
		{add_view 	"burn_element" 			"smoke_hips_h" "H_drive"}
		{add_view 	"burn_element" 			"smoke_hips_v" "V_drive"}
		
		
		{add_view 	"smoke_barrel_small" 					"fx_fall_l" "LeftCableHipsSM"}
		{add_view 	"smoke_barrel_small" 					"fx_fall_r" "RightCableHipsSM"}

		{add_view 	"drops_oil_small_long" 			"LeftPiston_UpperLegToShoulder" "LeftPiston_UpperLegToShoulder_FrontBaseUpper"}
		{add_view 	"drops_oil_small_long" 			"RightPiston_UpperLegToShoulder" "RightPiston_UpperLegToShoulder_FrontBaseUpper"}

		{add_view 	"burn_element" 					"front_hatch_r_destroy" "front_hatch_r"}
		{add_view 	"burn_element" 					"front_hatch_l_destroy" "front_hatch_l"}

		{add_view 	"smoke_element_cpu" 			"front_hatch_r_break" "front_hatch_r"}
		{add_view 	"smoke_element_cpu" 			"front_hatch_l_break" "front_hatch_l"}

		{add_view 	"burn_element" 					"back_hatch_r_destroy" "back_hatch_r"}
		{add_view 	"burn_element" 					"back_hatch_l_destroy" "back_hatch_l"}

		{add_view 	"smoke_element_cpu" 			"back_hatch_r_break" "back_hatch_r"}
		{add_view 	"smoke_element_cpu" 			"back_hatch_l_break" "back_hatch_l"}

		{add_view 	"burn_element" 			"legplate_right_burn" 	"legplate_right"}
		{add_view 	"burn_element" 			"legplate_left_burn" 	"legplate_left"}

		{add_view 	"burn_element" 			"shoulder_plate_right_burn" 	"shoulder_plate_right"}
		{add_view 	"burn_element" 			"shoulder_plate_left_burn" 		"shoulder_plate_left"}

		{view hide	"close_attack_dread"}
		{view pause	"close_attack_dread"}
		{view hide	"scanline_light"}
		{view pause	"scanline_light"}

		{tags add "hold"}
		{call "ai_talk_signal"}
		{tags add "machine"}
		{tags add "dreadnought_base"}
		{delay 1
			{if tagged "frends"
				{player 0}
			else tagged "rus"
				{player 9}
			else
				{player 8}
			}
		}
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
		("leds_ems_global_small"  vis(visor_led_00)  )
		("leds_ems_global_small"  vis(visor_led_01)  )
		("leds_ems_global_small"  vis(visor_led_02)  )
		("leds_ems_global_small"  vis(body_ems_00) )
		("leds_ems_global_small"  vis(head_light_ems_00) )
		("leds_ems_global_small"  vis(head_light_ems_01) )
		("leds_ems_global_small"  vis(head_light_ems_02) )
	}
	{on "sound_connect"
		{link_sound "stop_gas" "generation_zero/characters/gas_drop/smoke_hiss_end"}
		{link_sound "loop_gas" "generation_zero/characters/gas_drop/smoke_hiss_lp"}
		{link_sound "start_gas" "generation_zero/characters/gas_drop/smoke_hiss_start"}
		{link_sound "concussion_riser" "generation_zero/characters/dreadnought/concussion/drea_concussion_riser"}
		
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
		{add_view 	"yellow_ems_big" 	"ems_global_search" 	"head_light_00_fx"}
		{add_view 	"red_ems_big" 		"ems_global_alarm" 		"head_light_00_fx"}
		{add_view 	"hold_ems_big" 		"ems_global_hold" 		"head_light_00_fx"}
		{view show	"ems_global_hold"}
		{view start	"ems_global_hold"}
		{view hide	"ems_global_alarm"}
		{view pause	"ems_global_alarm"}
		{view hide	"ems_global_search"}
		{view pause	"ems_global_search"}
		{bone show "body_ems_00_hold"}
		{bone hide "body_ems_00_alarm"}
		{bone hide "body_ems_00_search"}
		{bone show	"light_ems"}
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
				{delay 5 {tags remove "search_call"}}
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
	(define "leds_ems_connect"
		("leds_ems"  vis(visor_led_00)	)
		("leds_ems"  vis(visor_led_01)	)
		("leds_ems"  vis(visor_led_02)	)
		("leds_ems"  vis(body_ems_00) )
		("leds_ems"  vis(head_light_ems_00) )
		("leds_ems"  vis(head_light_ems_01) )
		("leds_ems"  vis(head_light_ems_02) )
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
	{on ik begin "h_signal"
		{tags remove "hold"}	
		{tags remove "alarm"}	
		{tags add "search"}
		{if not tagged "search_call_signal"
			{tags add "search_call_signal"}
			{call "ai_talk_signal"}
		}
		{delay 5 {tags remove "search_call_signal"}}
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
		{if component "frontplate" ;dread
			{call "lose_health"}
			{burn volume "fx_frontplate_00" fx "electric_spark_micro_hit" time 7 3 fake}	
			{burn volume "fx_frontplate_01" fx "electric_spark_micro_hit" time 7 3 fake}	
			{burn volume "fx_frontplate_02" fx "electric_spark_micro_hit" time 7 3 fake}	
			{spawn "frontplate_break" "frontplate" x}	
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
		{if component "backfan_01" ;dread
			{call "lose_health"}
			{spawn "break_small_body_robot" "backfan_01"}
			{view hide	"fans1"}
			{view pause	"fans1"}		
		};dread
		{if component "backfan_02"
			{call "lose_health"}
			{spawn "break_small_body_robot" "backfan_02"}
			{view hide	"fans2"}
			{view pause	"fans2"}		
		}
		{if component "backfan_03";dread
			{call "lose_health"}
			{spawn "break_small_body_robot" "backfan_03"}
			{view hide	"fans3"}
			{view pause	"fans3"}					
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
		{if component "battery_r" ;dread
			{call "lose_health"}
			{spawn "electric_spark_break" "battery_r"}
			{call "power_drop"}
			{burn volume "battery_r" fx "component_break_fx" time 5 fake}	
		}
		{if component "battery_l" ;dread
			{call "lose_health"}
			{spawn "electric_spark_break" "battery_l"}
			{call "power_drop"}
			{burn volume "battery_l" fx "component_break_fx" time 5 fake}	
		}
		{if component "cooling_systems" ;not use
			{call "lose_health"}
			{burn volume "cooling_systems" fx "smoke_heat" time 8 fake}
			{delay 20 
				{tags add "break_cooling_systems"}
			}
		}
		{if component "organs_leg_left" ;орган верхней ноги дреда ;
			{call "lose_health"}
			{burn volume "LeftUpLeg_cylplate_01" fx "smoke_heat" time 8 fake}
			{burn volume "LeftUpLeg_cylplate_02" fx "smoke_heat" time 8 fake}		
		}
		{if component "organs_leg_right" ;орган верхней ноги дреда
			{call "lose_health"}
			{burn volume "RightUpLeg_cylplate_02" fx "smoke_heat" time 8 fake}
			{burn volume "RightUpLeg_cylplate_02" fx "smoke_heat" time 8 fake}
		}
		{if component "LeftPiston_UpperLegToShoulder" ;поршни дреда
			{call "lose_health"}
			{view start "LeftPiston_UpperLegToShoulder"}
			{delay 20 5
				{view pause "LeftPiston_UpperLegToShoulder"}
			}
		}
		{if component "RightPiston_UpperLegToShoulder";поршни дреда
			{call "lose_health"}
			{view start "RightPiston_UpperLegToShoulder"}
			{delay 20 5
				{view pause "RightPiston_UpperLegToShoulder"}
			}
		}
		{if component "organs_engine_drive_left" ;dread ; Двигатели впереди в люках
			{call "lose_health"}
			{burn volume "organs_engine_drive_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_engine_drive_left"}
		}
		{if component "organs_engine_drive_right" ;dread ; Двигатели впереди в люках
			{call "lose_health"}
			{burn volume "organs_engine_drive_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_engine_drive_right"}
		}
		{if component "organs_hip_right"     ;dread  ; элемент главной ноги
			{call "lose_health"}
			{burn volume "organs_hip_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_hip_right"}
		}
		{if component "organs_hip_left" ;dread  ; элемент главной ноги
			{call "lose_health"}
			{burn volume "organs_hip_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_hip_left"}
		}
		{if component "hydraulic_knee_right" ;dread ; внутри колена привод
			{call "lose_health"}
			{burn volume "hydraulic_knee_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "hydraulic_knee_right"}
		}
		{if component "hydraulic_knee_left";dread ; внутри колена привод
			{call "lose_health"}
			{burn volume "hydraulic_knee_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "hydraulic_knee_left"}
		}
		{if component "organs_leg_right"     ;dread       ; верхняя нога
			{call "lose_health"}
			{burn volume "organs_leg_right" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_leg_right"}
		}
		{if component "organs_leg_left" ;dread       ; верхняя нога
			{call "lose_health"}
			{burn volume "organs_leg_left" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organs_leg_left"}
		}
		{if component "right_engine" ; hunter_
			{call "lose_health"}
			{burn volume "right_engine" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "right_engine"}
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
		{if component "legplate_right"	;dread; люки на ногах мелкие
			{call "lose_health"}
			{burn volume "legplate_right" fx "electric_spark_break" time 1 fake}
			{spawn "electric_spark_break" "legplate_right"}
			{view start "legplate_right_burn"}
			{movement_limit slow}
			{delay 1
				{if work "fuel"
					{drop_orders}
					{movement_limit fast}
				}
			}
			{delay 12 5
				{view pause "legplate_right_burn"}
			}
		}
		{if component "legplate_left";dread; люки на ногах мелкие
			{call "lose_health"}
			{burn volume "legplate_left" fx "electric_spark_break" time 1 fake}
			{spawn "electric_spark_break" "legplate_left"}
			{view start "legplate_left_burn"}
			{movement_limit slow}
			{delay 1
				{if work "fuel"
					{drop_orders}
					{movement_limit fast}
				}
			}
			{delay 12 5
				{view pause "legplate_left_burn"}
			}		
		}
		{if component "shoulder_plate_right"	;dread	; Двигатели впереди в люках
			{if not able "exploded"			
				{if not tagged "move"
					{if not tagged "replace_position"
						{if rand 0.5
							{ani_play "hit_reel_45ccw" 0.5}
						else rand 0.3
							{ani_play "hit_reel_135ccw" 0.5}
						}					
					}
				}
			}
			{call "lose_health"}
			{spawn "electric_spark_break" "shoulder_plate_right"}
			{view start "shoulder_plate_right_burn"}
			{movement_limit slow}
			{delay 3
				{if work "fuel"
					{drop_orders}				
					{movement_limit fast}
				}
			}
			{delay 7
				{view pause "shoulder_plate_right_burn"}
			}		
		}
		{if component "shoulder_plate_left";dread	; Двигатели впереди в люках
			{call "lose_health"}
			{spawn "electric_spark_break" "shoulder_plate_left"}
			{view start "shoulder_plate_left_burn"}
			{movement_limit slow}
			{if not able "exploded"			
				{if not tagged "move"
					{if not tagged "replace_position"
						{if rand 0.3
							{ani_play "hit_reel_45cw" 0.5}
						else rand 0.3
							{ani_play "hit_reel_135cw" 0.5}
						}					
					}
				}
			}
			{delay 3
				{if work "fuel"
					{drop_orders}				
					{movement_limit fast}
				}
			}
			{delay 7
				{view pause "shoulder_plate_left_burn"}
			}	
		}			
		(define "mesh_break_armor" ;armor all
			{if component "%component" 
				{burn volume "%component" fx "smoke_preheat" time 2 1 fake}	
			}
		)
		;all armor
		("mesh_break_armor" component(front_armor)  				)
		("mesh_break_armor" component(down_armor)  				)
		("mesh_break_armor" component(kneepad_r)  			   )
		("mesh_break_armor" component(kneepad_l)  			   )
		("mesh_break_armor" component(head_top)  				   )
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
		(define "mesh_break_cylplate" ;dread harv
			{if component "%component" 
				{spawn "break_small_body_robot" "%component"}
				{burn volume "%component" fx "smoke_preheat" time 2 1 fake}	
			}
		)
		("mesh_break_cylplate" component(RightUpLeg_cylplate_01))
		("mesh_break_cylplate" component(RightUpLeg_cylplate_02))
		("mesh_break_cylplate" component(RightUpLeg1_cylplate_01))
		("mesh_break_cylplate" component(RightUpLeg1_cylplate_02))
		("mesh_break_cylplate" component(RightFoot_cylplate_01))
		("mesh_break_cylplate" component(RightFoot_cylplate_02))
		("mesh_break_cylplate" component(LeftUpLeg_cylplate_01))
		("mesh_break_cylplate" component(LeftUpLeg_cylplate_02))
		("mesh_break_cylplate" component(LeftUpLeg1_cylplate_01))
		("mesh_break_cylplate" component(LeftUpLeg1_cylplate_02))
		("mesh_break_cylplate" component(LeftFoot_cylplate_01))
		("mesh_break_cylplate" component(LeftFoot_cylplate_02))
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
		{if component "area_missile"
			{weapon_work "gun" 0}
			{tags add "destroy_missile"}
			{spawn "brake_component" "area_missile" x}	
			{spawn "fireworks_blast_noparticle" "area_missile"}
		else component "missile"
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
	{on pierce sync;dread
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
				{if component "%component"
					{if stuff "%stuff"
						{if not work "%component"
							{if rand %stuff_destroy
								{components "%component" destroy}
							}
						else
							{if rand %stuff_break
								{components "%component" break}
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
		("mesh_break" component(cpu)  				 				stuff_destroy(0.3)    )
		("mesh_break" component(engine)  			 				stuff_destroy(0.2)    )


		("mesh_break" component(LeftPiston_UpperLegToShoulder)		stuff_destroy(0.3)    ) ;LeftPiston_UpperLegToShoulder_FrontBaseUpper
		("mesh_break" component(RightPiston_UpperLegToShoulder)		stuff_destroy(0.3)    ) ;rightPiston_UpperLegToShoulder_FrontBaseUpper


			
		("mesh_break" component(gasdrop_l)  						 stuff_destroy(0.3)    )
		("mesh_break" component(gasdrop_r)  						 stuff_destroy(0.3)    )
		("mesh_break" component(Concussion_Pulse_r)  				 stuff_destroy(0.2)    )
		("mesh_break" component(Concussion_Pulse_l)  				 stuff_destroy(0.2)    )
		("mesh_break" component(backlegs_mount)  					 stuff_destroy(0.2)    )
		("mesh_break" component(frontlegs_mount)  					 stuff_destroy(0.2)    )
		("mesh_break" component(front_core_panel)  					 stuff_destroy(0.2)    )
		("mesh_break" component(structure_plate_right)  			 stuff_destroy(0.2)    )
		("mesh_break" component(structure_plate_left)  				 stuff_destroy(0.2)    )
		("mesh_break" component(back_hatch_l)  						 stuff_destroy(0.2)    )
		("mesh_break" component(back_hatch_r)  						 stuff_destroy(0.2)    )
		("mesh_break" component(front_hatch_l)  					 stuff_destroy(0.2)    )
		("mesh_break" component(front_hatch_r)  					 stuff_destroy(0.2)    )
		("mesh_break" component(drill_hatch_r)  					 stuff_destroy(0.2)    )
		("mesh_break" component(drill_hatch_l)  					 stuff_destroy(0.2)    )
		("mesh_break" component(pestcontainer)  					 stuff_destroy(0.2)    )
		("mesh_break" component(engine_move)  						 stuff_destroy(0.2)    )
		("mesh_break" component(backfan_01)  						 stuff_destroy(0.2)    )
		("mesh_break" component(backfan_02)  						 stuff_destroy(0.2)    )
		("mesh_break" component(backfan_03)  						 stuff_destroy(0.2)    )
		("mesh_break" component(sideplate_left)  					 stuff_destroy(0.2)    )
		("mesh_break" component(sideplate_right)  					 stuff_destroy(0.2)    )
		("mesh_break" component(head_sideplate_front_r)  			 stuff_destroy(0.2)    )
		("mesh_break" component(head_sideplate_front_l)  			 stuff_destroy(0.2)    )
		("mesh_break" component(head_sideplate_back_r)  			 stuff_destroy(0.2)    )
		("mesh_break" component(head_sideplate_back_l)  			 stuff_destroy(0.2)    )
		
		("mesh_break" component(legplate_right)  			 		stuff_destroy(0.2)    )
		("mesh_break" component(legplate_left)  			 		stuff_destroy(0.2)    )

		("mesh_break" component(shoulder_plate_left)  			 	stuff_destroy(0.2)    )
		("mesh_break" component(shoulder_plate_right)  			 	stuff_destroy(0.2)    )



		("mesh_break" component(leftUpLeg_cylplate_01)  			stuff_destroy(0.2)    )
		("mesh_break" component(leftUpLeg_cylplate_02)  			stuff_destroy(0.2)    )
		("mesh_break" component(leftUpLeg1_cylplate_01)  			stuff_destroy(0.2)    )
		("mesh_break" component(leftUpLeg1_cylplate_02)  			stuff_destroy(0.2)    )
		("mesh_break" component(leftFoot_cylplate_01)  			 	stuff_destroy(0.2)    )
		("mesh_break" component(leftFoot_cylplate_02)  			 	stuff_destroy(0.2)    )
		("mesh_break" component(rightUpLeg_cylplate_01)  			stuff_destroy(0.2)    )
		("mesh_break" component(rightUpLeg_cylplate_02)  			stuff_destroy(0.2)    )
		("mesh_break" component(rightUpLeg1_cylplate_01)  			stuff_destroy(0.2)    )
		("mesh_break" component(rightUpLeg1_cylplate_02)  			stuff_destroy(0.2)    )
		("mesh_break" component(rightFoot_cylplate_01)  			stuff_destroy(0.2)    )
		("mesh_break" component(rightFoot_cylplate_02)  			stuff_destroy(0.2)    )

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
	{on bullet_hit
		{physics_work 0} ;test
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
	{on blast ;dread
		{if stuff "attack_melee_l_stamp"
			{call "attack_melee_l_stamp"}
		}
		{if stuff "attack_melee_r_stamp"
			{call "attack_melee_r_stamp"}
		}
		{if stuff "attack_melee_l_stamp_bwd"
			{call "attack_melee_l_stamp_bwd"}
		}
		{if stuff "attack_melee_r_stamp_bwd"
			{call "attack_melee_r_stamp_bwd"}
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
		("orientation" vol(front_left_hit)  	ani_play(hit_stumble_45ccw)   rand(0.5)  min_energy(2) )
		("orientation" vol(front_right_hit)  	ani_play(hit_stumble_45cw)    rand(0.5)  min_energy(2) )
		("orientation" vol(back_left_hit)  		ani_play(hit_stumble_135cw)   rand(0.5)  min_energy(2) )
		("orientation" vol(back_right_hit)  	ani_play(hit_stumble_135ccw)  rand(0.5)  min_energy(2) )
	}
	(include "burn_volume.inc")
	{on "fx_component_mover" ;organs_leg_left LeftUpLeg_cylplate_01 LeftUpLeg_cylplate_02
		{if not work "organs_leg_right"
			{if rand 0.1
				{spawn "electric_spark_break" "organs_leg_right"}
				{call "drop_speed"}
			}
			{if rand 0.5
				{spawn "component_break_fx" "rightUpLeg_cylplate_01"}
			}			
			{if rand 0.5
				{spawn "component_break_fx" "rightUpLeg_cylplate_02"}
			}			
		}
		{if not work "organs_leg_left"
			{if rand 0.1
				{spawn "electric_spark_break" "organs_leg_left"}
				{call "drop_speed"}
			}
			{if rand 0.5
				{spawn "component_break_fx" "LeftUpLeg_cylplate_01"}
			}			
			{if rand 0.5
				{spawn "component_break_fx" "LeftUpLeg_cylplate_02"}
			}			
		}
	}	
	{on "power_up" ; dread
		{if not able "exploded"
			{if work "backfan_01"
				{view show	"fans1"}
				{view start	"fans1"}		
			}
			{if work "backfan_02"
				{view show	"fans2"}
				{view start	"fans2"}		
			}
			{if work "backfan_03"
				{view show	"fans3"}
				{view start	"fans3"}					
			}
			{view show	"ems_global"}
			{view start	"ems_global"}		
			{view show	"ems"}
			{view start	"ems"}		
			{tags add "hold"}
			{call "ai_talk_signal"}
			{call "led_loop"}
		}
	}
	{on "led_loop"
		{if work "main_body"
			{if tagged "hold"
				{bone show "visor_led_00_hold"}
				{delay 0.5 "led_loop"
					{bone show "visor_led_01_hold"}
					{delay 0.5 "led_loop"
						{bone show "visor_led_02_hold"}
						{delay 1 "led_loop"
							{bone hide "visor_led_00_hold"}
							{bone hide "visor_led_01_hold"}
							{bone hide "visor_led_02_hold"}
						}
					}
				}
			else tagged "search"
				{bone show "visor_led_00_search"}
				{delay 0.5 "led_loop"
					{bone show "visor_led_01_search"}
					{delay 0.5 "led_loop"
						{bone show "visor_led_02_search"}
						{delay 1 "led_loop"
							{bone hide "visor_led_00_search"}
							{bone hide "visor_led_01_search"}
							{bone hide "visor_led_02_search"}
						}
					}
				}
			else tagged "alarm"
				{bone show "visor_led_00_alarm"}
				{delay 0.5 "led_loop"
					{bone show "visor_led_01_alarm"}
					{delay 0.5 "led_loop"
						{bone show "visor_led_02_alarm"}
						{delay 1 "led_loop"
							{bone hide "visor_led_00_alarm"}
							{bone hide "visor_led_01_alarm"}
							{bone hide "visor_led_02_alarm"}
						}
					}
				}
			else tagged "off"
				{bone hide "visor_led_00_bone"}
				{bone hide "visor_led_01_bone"}
				{bone hide "visor_led_02_bone"}
			}
		}
		{delay_effect 0.5 "led_loop"}
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
					{view hide	"fans1"}
					{view pause	"fans1"}		
					{view hide	"fans2"}
					{view pause	"fans2"}		
					{view hide	"fans3"}
					{view pause	"fans3"}					
					{view hide	"ems_global"}
					{view pause	"ems_global"}
					{call "stop_idle"}
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
					{view hide	"fans1"}
					{view pause	"fans1"}		
					{view hide	"fans2"}
					{view pause	"fans2"}		
					{view hide	"fans3"}
					{view pause	"fans3"}					
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
		{kill_delay "drop_speed_move"}
		{movement_limit slow}
		{delay 2 "drop_speed_move"
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
	{on animation_event "runstart_f" ;dread hunter skir
		{if tagged "move"
			{call "move_update_f"}
		else
			{ani_play "runstop_f" 1}
		}
	}	
	
	{on move on ;dread
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
	{on "move_update_walk"  ;dread цикл ходки 
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

	{on turn on ; dread		
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
	{on animation_event "update_turn_left_movement"; обновление пооврота убрано;dread harv
		{call "update_turn_left_movement"}
	}
	{on animation_event "update_turn_right_movement"; обновление пооврота убрано;dread harv
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
			{delay 0.1
				{tags remove "step_l_045_exit"}	
			}
			{tags remove "left"}	
			{tags remove "step_l_045"}	
		}
	}
	{on "update_turn_left_movement" 
		{if tagged "Turn_Left"
			;{if not tagged "step_l_045"
			;	{tags add "step_l_045"}	
				{delay 0.1
					{if not tagged "step_r_045"
						;{if not tagged "walk"
							{ani_play "step_l_045"}	
						;}
					}
				}
			;}
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
			{delay 0.1
				;{movement_limit fast}		
				{tags remove "step_r_045_exit"}	
			}
			{tags remove "right"}	
			{tags remove "step_r_045"}	
		}
	}
	{on "update_turn_right_movement" 
		{if tagged "Turn_right"
			;{if not tagged "step_r_045"
			;	{tags add "step_r_045"}	
				{delay 0.1
					{if not tagged "step_l_045"
						;{if not tagged "walk"
							{ani_play "step_r_045"}	
						;}
					}
				}
			;}
		}
	}
	{on turn off ; dread
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
		(define "turn_off"	
			{if tagged "%turn_off"
				{tags add "%turn_off_exit" }
				{tags remove "%turn_off"}	
			}
		)
		("turn_off" turn_off(step_r_090) turn_off_exit(step_r_090_exit) )	
		("turn_off" turn_off(step_r_045) turn_off_exit(step_r_045_exit) )	
		("turn_off" turn_off(step_l_090) turn_off_exit(step_l_090_exit) )	
		("turn_off" turn_off(step_l_045) turn_off_exit(step_l_045_exit) )	
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
	{on animation_event "runloop_f" 
		{if not tagged "jump"
			{if velocity 20	 ;если прибежал
				{call "move_update_run"}
				;{ani_stop "run_swing_to_walk" }
			else velocity 12	
				{ani_play "run_swing_to_walk" }
			}
		}
	}
	{on "move_update_run" 
		(define "move_update_run"
			{if velocity %speed	
				{if tagged "run"
					{ani_play "runloop_f" (* %speed 0.06) }
				}
				;{tags add "%speed"}	;check sum
				;{tags add "%ani"}	;check sum
			}
		)		
		("move_update_run" speed(35) 	)
		("move_update_run" speed(32) 	)
		("move_update_run" speed(30) 	)
		("move_update_run" speed(28) 	)
		("move_update_run" speed(26) 	)
		("move_update_run" speed(24) 	)
		("move_update_run" speed(22) 	)
		("move_update_run" speed(20)	)
		("move_update_run" speed(19)  	)
	}	
	{on "explosion_dread" 
		{if not able "exploded"			
			{set "exploded" 1}		
			{able "exploded" 1}
			{stop_sound "engine" }
			{stop_sound "engine_hiss" }
			;{bone hide ""}
			;{mtl_enable_skin 0}
			{tags add "off"}
			{tags add "dead"}
			{call "stop_all"}
			{call "tear_parts"}
			{if tagged "move"
				{if rand 0.5
					{ani_play "death_l_fwd"}
				else
					{ani_play "death_r_fwd"}
				}
			else
				{if rand 0.2
					{ani_play "death_l_bwd"}
				else rand 0.2
					{ani_play "death_l_bwd" 0.5}
				else rand 0.2
					{ani_play "death_r_bwd" 0.5}
				else
					{ani_play "death_r_bwd"}
				}
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
			{spawn "destroy_med_robot" "neck"}
			{spawn "burn_flare" "head_sm"}
		}
	}
	{on "tear_parts_explode"
		(define "blast_dreadnought"
			{if rand %1
				{tear "piece_small_steel" bone %0
					{impulse up 4 3 dir 12 5 cx 3 2 cy 3 2 no_position}
				}
			}
		)
		("blast_dreadnought" args "fuel" 				0.4)
		("blast_dreadnought" args "RightHandIndex1" 	0.9)
		("blast_dreadnought" args "RightHand" 			0.5)
		("blast_dreadnought" args "RightForeArm" 		0.6)
		("blast_dreadnought" args "RightArm" 			0.6)
		("blast_dreadnought" args "RightUpLeg" 		0.6)
		("blast_dreadnought" args "RightLeg" 			0.7)
		("blast_dreadnought" args "RightFoot" 			0.7)
		("blast_dreadnought" args "RightToeBase" 		0.7)		
		("blast_dreadnought" args "leftHandIndex1" 	0.8)
		("blast_dreadnought" args "leftHand" 			0.7)
		("blast_dreadnought" args "leftForeArm" 		0.7)
		("blast_dreadnought" args "leftArm" 			0.6)
		("blast_dreadnought" args "leftUpLeg" 			0.6)
		("blast_dreadnought" args "leftLeg" 			0.8)
		("blast_dreadnought" args "leftFoot" 			0.8)
		("blast_dreadnought" args "leftToeBase" 		0.7)
		("blast_dreadnought" args "armour_knee_right" 	0.8)
		("blast_dreadnought" args "armour_knee_left" 	0.8)			
		("blast_dreadnought" args "armour_shoulder_right" 		0.8)
		("blast_dreadnought" args "armour_shoulder_left" 		0.8)
		("blast_dreadnought" args "armour_head" 				0.8)
		("blast_dreadnought" args "front_armor" 				0.8)			
		("blast_dreadnought" args "neck" 						0.8)
		("blast_dreadnought" args "scanner" 					0.8)		
		("blast_dreadnought" args "head" 						0.8)	
		("blast_dreadnought" args "magazine" 			1)	
		("blast_dreadnought" args "mgun" 				1)	
		("blast_dreadnought" args "weaponattach" 			1)	
	}
	{on "random_component_break_l"
		{if rand 0.5	
			{tear "piece_small_misc" bone "visor_body"
				{spawn "component_break_fx" "visor_body"}
				{bone hide "light_ems"}
				{bone hide "body_ems_00_alarm"}
				{view hide "ems_global"}				
				{impulse dir 2 1 	cx 0.4 	cy 0.4 no_position}	
			}
		else rand 0.4
			{tear "piece_medium_steel" bone "armour_head"
				{spawn "component_break_fx" "armour_head"}
				{impulse dir 2 1 	cx 0.4 	cy 0.4 no_position}	
			}			
		else rand 0.3
			{tear "piece_medium_steel" bone "shoulder_plate_left"
				{spawn "component_break_fx" "shoulder_plate_left"}
				{impulse dir 2 1 	cx 0.4 	cy 0.4 no_position}	
			}
		else
			{tear "piece_medium_steel" bone "kneepad_l"
				{spawn "component_break_fx" "kneepad_l"}
				{impulse dir 2 1 	cx 0.4 	cy 0.4 no_position}	
			}
		}	
	}
	{on "random_component_break_r"
		{if rand 0.5	
			{tear "piece_small_misc" bone "visor_body"
				{spawn "component_break_fx" "visor_body"}
				{bone hide "light_ems"}
				{bone hide "body_ems_00_alarm"}
				{view hide "ems_global"}				
				{impulse dir 2 1 	cx 0.4 	cy 0.4 no_position}	
			}
		else rand 0.4
			{tear "piece_medium_steel" bone "armour_head"
				{spawn "component_break_fx" "armour_head"}
				{impulse dir 2 1 	cx 0.4 	cy 0.4 no_position}	
			}			
		else rand 0.3
			{tear "piece_medium_steel" bone "shoulder_plate_right"
				;{spawn "component_break_fx" "shoulder_plate_right"}
				{impulse dir 2 1 	cx 0.4 	cy 0.4 no_position}	
			}
		else
			{tear "piece_medium_steel" bone "kneepad_r"
				;{spawn "component_break_fx" "kneepad_r"}
				{impulse dir 2 1 	cx 0.4 	cy 0.4 no_position}	
			}
		}	
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
		{if not tagged "damage_mgun"
			{weapon_work "mgun" 1}
		else
			{weapon_work "mgun" 0}
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
	{on "weapon_disable"
		{kill_delay "main_gun"}
		{weapon_work "gun" 0}
		{tags remove "weapon_enable"}
	}	
	{on "weapon_enable"
		{delay 1 "main_gun"
			{if work "missile"
				{tags add "weapon_enable"}
				{weapon_work "gun" 1}
			}
		}
	}
	{on "weapon_gas_disable"
		{kill_delay "gas_gun"}
		{weapon_work "attack_gas" 0}
		{tags remove "weapon_gas_enable"}
	}
	{on "weapon_gas_enable"
		{delay 1 "gas_gun"
			{tags add "weapon_gas_enable"}
			{weapon_work "attack_gas" 1}
		}
	}
	{on "weapon_melee_disable"
		{with_linked_entity "attack_melee_r_stamp"
			{call "close"}
		}
		{with_linked_entity "attack_melee_l_stamp"
			{call "close"}
		}
		{with_linked_entity "attack_melee_r_bwd_stamp"
			{call "close"}
		}
		{with_linked_entity "attack_melee_l_bwd_stamp"
			{call "close"}
		}
	}
	{on "weapon_melee_enable" ;with link -close
		{with_linked_entity "attack_melee_r_stamp"
			{call "open"}
		}
		{with_linked_entity "attack_melee_l_stamp"
			{call "open"}
		}
		{with_linked_entity "attack_melee_r_bwd_stamp"
			{call "open"}
		}
		{with_linked_entity "attack_melee_l_bwd_stamp"
			{call "open"}
		}
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
	{on "drop_pest"
		{start_sound "generation_zero/characters/pest/reinforcement_pod"}
		{ani_play "drop_pest"}
		{call "drop_speed_move"}
		{delay 1
			{if tagged "egg05"
				{tags remove "egg05"}
				{tags add "egg06"}
				{bone hide "egg06"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_06" x {impulse forward 2 1}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_06" x {impulse forward 2 1} {call "unlink"}}
				}
			}
			{if tagged "egg04"
				{tags remove "egg04"}
				{tags add "egg05"}
				{bone hide "egg05"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_05" x {impulse forward 2 1}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_05" x {impulse forward 2 1} {call "unlink"}}
				}
			}
			{if tagged "egg03"
				{tags remove "egg03"}
				{tags add "egg04"}
				{bone hide "egg04"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_04" x {impulse forward 2 1}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_04" x {impulse forward 2 1} {call "unlink"}}
				}
			}
			{if tagged "egg02"
				{tags remove "egg02"}
				{tags add "egg03"}
				{bone hide "egg03"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_03" x {impulse forward 2 1}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_03" x {impulse forward 2 1} {call "unlink"}}
				}
			}
			{if tagged "egg01"
				{tags remove "egg01"}
				{tags add "egg02"}
				{bone hide "egg02"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_02" x {impulse forward 2 1}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_02" x {impulse forward 2 1} {call "unlink"}}
				}
			}
			{if tagged "egg00"
				{tags remove "egg00"}
				{tags add "egg01"}
				{bone hide "egg01"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_01" x {impulse forward 2 1}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_01" x {impulse forward 2 1} {call "unlink"}}
				}
			}
			{if not tagged "egg00"
				{tags add "egg00"}
				{bone hide "egg00"}
				{if tagged "frends"
					{spawn "pest_egg_bomb" "egg_00" x {impulse forward 2 1}{tags add "frends"}{call "unlink"}}
				else
					{spawn "pest_egg_01" "egg_00" x {impulse forward 2 1} {call "unlink"}}
				}
			}
		}			
		{delay 4
			{ani_play "drop_pest" -1}
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
	{on "reload"  ;dread
		{if tagged "fire_mgun"
			{if work "mgun"
				{tags add "mgun_r"}
				{weapon_work "mgun" 0}
				;{ani_play "%anim" }	
				{delay 12
					{if work "mgun"
						;{ani_play "%anim" -1 }
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
				{delay 20
					{if work "gun"
						{delay 0.5
							{tags remove "gun_r"}
							{weapon_work "gun" 1}
						}
					}
				}
			}		
		else tagged "fire_missile"
			{if work "missile"
				{tags add "gun_r"}
				{tags add "load_mortar"}
				{weapon_work "gun" 0}
				{delay 1
					{ani_play "reload" 0.5}
				}
				{delay 11
					{if work "missile"
						{delay 0.5
							{spawn "wpn_prepare_mortar" "RightWeaponRotate"}
							{tags remove "gun_r"}
							{if not tagged "damage_gun"
								{weapon_work "gun" 1}
							}
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
		else tagged "fire_mgun_melee"
			{if work "mgun_melee"
				{tags add "mgun_melee_r"}
				{weapon_work "attack_melee_charge" 0}
				{delay 8
					{if work "mgun_melee"
						{tags remove "mgun_melee_r"}
						{weapon_work "attack_melee_charge" 1}
					}
				}
			}
		else tagged "attack_concussion"
			{if work "attack_concussion"
				{tags add "attack_concussion_r"}
				{weapon_work "attack_concussion" 0}
				{delay 8
					{if work "attack_concussion"
						{tags remove "attack_concussion_r"}
						{weapon_work "attack_concussion" 1}
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
	{on "move_hit" 
		{if not "blocked"
			{if rand 0.5
				{ani_play "hit_reel_45ccw" resume}
			else rand 0.5
				{ani_play "hit_reel_45cw" resume}
			}
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
	{on fire "attack_gas" 
		{tags add "fire_gasdrop"}
		{call "weapon_melee_disable"}
		{tags remove "hold"}	
		{tags remove "search"}	
		{tags add "alarm"}
		{if not tagged "alarm_call_signal"
			{tags add "alarm_call_signal"}
			{call "ai_talk_signal"}
		}
		{delay 4 {tags remove "alarm_call_signal"}}
		{delay 10
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
	{on fire "attack_pestdrop"  ;dread
		{tags add "fire_pestcontainer_drop"}
		{call "drop_pest"}
		{delay 0.3
			{tags remove "fire_pestcontainer_drop"}
		}	
	}		
	{on fire "attack_concussion"
		{tags remove "hold"}	
		{tags remove "search"}	
		{tags add "alarm"}
		{if not tagged "alarm_call_signal"
			{tags add "alarm_call_signal"}
			{call "ai_talk_signal"}
		}
		{delay 4 {tags remove "alarm_call_signal"}}
		{weapon_work "attack_gas" 0}
		{delay 5
			{weapon_work "attack_gas" 1}
		}
		{tags add "attack_concussion"}
		{delay 0.5
			{tags remove "attack_concussion"}
		}
		{ani_play "attack_concussion" 1}		
		;{blastwave c4 1 r0 10 r1 10}	; concussion	
	}		
	{on "attack_melee_r_stamp" 
		{call "weapon_melee_disable"}
		{call "fire_script_begin"}
		{delay 5
			{call "weapon_melee_enable"}
		}
		{delay 0.1
			{ani_play "attack_melee_r_stamp" 1 }		
		}
	}		
	{on "attack_melee_l_stamp" 
		{call "weapon_melee_disable"}
		{call "fire_script_begin"}
		{delay 5
			{call "weapon_melee_enable"}
		}
		{delay 0.1
			{ani_play "attack_melee_l_stamp" 1 }		
		}
	}		
	{on "attack_melee_r_stamp_bwd" 
		{call "weapon_melee_disable"}
		{call "fire_script_begin"}
		{delay 5
			{call "weapon_melee_enable"}
		}
		{delay 0.1
			{ani_play "attack_melee_r_stamp_bwd" 1 }		
		}
	}		
	{on "attack_melee_l_stamp_bwd" 
		{call "weapon_melee_disable"}
		{call "fire_script_begin"}
		{delay 5
			{call "weapon_melee_enable"}
		}
		{delay 0.1
			{ani_play "attack_melee_l_stamp_bwd" 1 }		
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
	;evs
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
	
	{on animation_event "reload_small_dr"
		{spawn "reload_small" "bullet_bone"}
	}	
	{on animation_event "melee_l_stamp"
			{start_sound "generation_zero/characters/harvest/attack_legs/stomp"}
			{spawn "harvest_melee" "LeftToeBase_fx"}
			{burn volume "LeftToeBase" fx "dust_med_dreadnought" time 0.5 fake even_law}
			{spawn "dust_med_dreadnought_front" "LeftToeBase_fx"}
			{spawn "explosion_flash_melee" "LeftToeBase_fx" x}
			{spawn "distant_small_grass_set" "LeftToeBase_fx" x}
			{spawn "footstep_dread" "LeftToeBase_fx" x}
	}
	{on animation_event "heat_20"		;dread
		{burn volume "barrel_heat_r" fx "smoke_heat_barrel" time 5 fake even_law}
		{burn volume "barrel_heat_l" fx "smoke_heat_barrel" time 5 fake even_law}
	}
	{on animation_event "heat_50"	;dread	
		{view start "stage1"}
		{view show "stage1"}
		{delay 4 
			{view hide	"stage1"}
			{view pause	"stage1"}
		}
	}
	{on animation_event "heat_80"		;dread
		{view start "stage2"}
		{view show "stage2"}
		{delay 0.5
			{ani_play "random_weapon_cooling" 0.4 }		;event
		}
		
		{delay 4 
			{view hide	"stage2"}
			{view pause	"stage2"}
		}
	}
	{on animation_event "heat_99";dread
		{view start "stage2_fire"}
		{view show "stage2_fire"}
		{delay 4 
			{view hide	"stage2_fire"}
			{view pause	"stage2_fire"}
		}
		{weapon_work "mgun" 0}
		{delay 6 4
			{if work "mgun"
				{weapon_work "mgun" 1}
			}
		}		
	}
	{on animation_event "hatch_mg_open"	;dread
		{ani_play "heat_mg" -0.6 resume callback}
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
		{burn volume "backfan_01" fx "smoke_heat" time 5 fake even_law}					
		{burn volume "backfan_02" fx "smoke_heat" time 5 fake even_law}					
		{burn volume "backfan_03" fx "smoke_heat" time 5 fake even_law}					
		{burn volume "cpu" fx "fx_fire_engine_gen" time 2 fake even_law}					
		{burn volume "body_organ" fx "smoke_heat" time 5 fake even_law}					
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
	{on animation_event "melee_r_stamp"
			{start_sound "generation_zero/characters/harvest/attack_legs/stomp"}
			{spawn "harvest_melee" "rightToeBase_fx"}
			{burn volume "rightToeBase" fx "dust_med_dreadnought" time 0.5 fake even_law}
			{spawn "dust_med_dreadnought_front" "rightToeBase_fx"}
			{spawn "explosion_flash_melee" "rightToeBase_fx" x}
			{spawn "distant_small_grass_set" "rightToeBase_fx" x}
			{spawn "footstep_dread" "RightToeBase_fx" x}
	}
	{on animation_event "play_idle" 
		{tags remove "search"}	
		{tags remove "alarm"}	
		{tags add "hold"}
		{call "ai_talk_signal"}
		{tags add "play_idle"}
	}
	{on animation_event "leave_idle" 
		{tags remove "play_idle"}
	}
	{on animation_event "explosion_dread" 
		{call "explosion_dread"}
	}
	{on animation_event "hatch_small_open" ;dread
		{start_sound "generation_zero/characters/small_mech/servo"}			
	}
	{on animation_event "hatch_small_drop" ;dread
		{start_sound "generation_zero/characters/small_mech/drop"}			
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
	{on animation_event "foot_dreadnought_r"
		{spawn "footstep_dread" "RightToeBase_sm" x}
		{burn volume "RightToe1" fx "dust_med_dreadnought" time 2.5 fake even_law}
		{burn volume "RightToe1" fx "dust_med_dreadnought" time 2.5 fake even_law}
		{burn volume "RightToe3" fx "dust_med_dreadnought" time 2.5 fake even_law}
		{spawn "dust_med_dreadnought_front" "RightToeBase_fx"}
		{spawn "explosion_flash_foot" "RightToeBase_fx" x}
		{spawn "distant_small_grass_set" "RightToeBase_fx" x}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/dreadnought/move/%0/"}	
				{start_sound "generation_zero/characters/dreadnought/move/far/%0/"}	
			
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "foot_dreadnought_l"
		{spawn "footstep_dread" "LeftToeBase_sm" x}
		{burn volume "LeftToe1" fx "dust_med_dreadnought" time 2.5 fake even_law}
		{burn volume "LeftToe1" fx "dust_med_dreadnought" time 2.5 fake even_law}
		{burn volume "LeftToe3" fx "dust_med_dreadnought" time 2.5 fake even_law}
		{spawn "dust_med_dreadnought_front" "LeftToeBase_fx" x}
		{spawn "explosion_flash_foot" "LeftToeBase_fx"}
		{spawn "distant_small_grass_set" "LeftToeBase_fx" x}
		(define "terrain_fx_check"
			{if tagged "%0"
				{start_sound "generation_zero/characters/dreadnought/move/%0/"}	
				{start_sound "generation_zero/characters/dreadnought/move/far/%0/"}	
			
			}
		)
		("terrain_fx_check" args ground )
		("terrain_fx_check" args wood 	)
		("terrain_fx_check" args metal 	)
		("terrain_fx_check" args grass 	)
		("terrain_fx_check" args gravel	)
	}
	{on animation_event "restart_clunk_dread"
		{if rand 0.1
			{spawn "electric_spark_hit" "RightCableUpperLegUp_00_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "RightCableUpperLegUp_01_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "RightCableUpperLegUp_02_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "RightCableUpperLegUp_03_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftCableUpperLegUp_00_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftCableUpperLegUp_01_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftCableUpperLegUp_02_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftCableUpperLegUp_03_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "RightCableHips_00_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "RightCableHips_01_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftCableHips_00_clunk"}
		else rand 0.1
			{spawn "electric_spark_hit" "LeftCableHips_01_clunk"}
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
	{on animation_event "block_all_dread_call" ;dread
		{movement_limit slow}
		{weapon_work "mgun" 0}
		{weapon_work "attack_gas" 0}
		{weapon_work "attack_melee_charge" 0}
		{weapon_work "gun" 0}		
	}
	{on animation_event "unblock_all_dread_call" ;dread
		{if work "fuel"
			{chassis_work 1}
		}
		{if work "mgun"
			{weapon_work "mgun" 1}
		}
		{if work "attack_gas"
			{weapon_work "attack_gas" 1};gasdrop
		}
		;{if work "attack_melee_charge"
			{weapon_work "attack_melee_charge" 1} ;mgun_melee
		;}
		{if work "gun"
			{weapon_work "gun" 1}
		}
	}
	;----------------------------------------------------------------death dread
	{on animation_event "death_start_dread"
	}	
	{on animation_event "death_dread_01"
		{if rand 0.5
			{spawn "break_small_body_robot" "RightCableUpperLegUp_01_clunk"}
		else rand 0.3
			{spawn "break_small_body_robot" "RightCableUpperLegUp_02_clunk"}
		else
			{spawn "break_small_body_robot" "RightCableUpperLegUp_03_clunk"}
		}	
	}
	{on animation_event "death_dread_02"
		{if rand 0.5
			{spawn "break_small_body_robot" "RightToeBase"}
		else rand 0.3
			{spawn "break_small_body_robot" "RightCableUpperLegDownSM"}
		else
			{spawn "break_small_body_robot" "RightToe4"}
		}	
	}
	{on animation_event "death_dread_03"
		{if rand 0.5
			{spawn "break_small_body_robot" "LeftCableHips_00_clunk"}
		else rand 0.3
			{spawn "break_small_body_robot" "LeftCableHips_01_clunk"}
		else
			{spawn "break_small_body_robot" "LeftCableHipsSM1"}
		}	
	}
	{on animation_event "death_l_bwd_dread_04"
		{spawn "hit_fall" "RightCableUpperLegUpSM1"}
		{if rand 0.5
			{spawn "break_small_body_robot" "RightCableUpperLegUpSM1"}
		else rand 0.3
			{spawn "break_small_body_robot" "LeftCableHips_01_clunk"}
		else
			{spawn "break_small_body_robot" "LeftCableHipsSM1"}
		}	
	}
	{on animation_event "death_r_bwd_dread_04"
		{spawn "hit_fall" "LeftCableUpperLegUpSM1"}
		{if rand 0.5
			{spawn "break_small_body_robot" "LeftCableUpperLegUpSM1"}
		else rand 0.3
			{spawn "break_small_body_robot" "RightCableUpperLegUpSM1"}
		else
			{spawn "break_small_body_robot" "RightCableHipsSM1"}
		}	
	}
	{on animation_event "start_fall_dread"
		{burn volume "hips" fx "burn_element" time 6 fake even_law}
		{start_sound "generation_zero/characters/explosion/robot_death_downer_tank/far/"}	
		{start_sound "generation_zero/characters/explosion/robot_death_downer_tank/close/"}	
	}
	{on animation_event "fx_fall_r"
		{view start "fx_fall_r"}
		{view show "fx_fall_r"}
		{delay 3
			{view hide "fx_fall_r"}
			{view stop "fx_fall_r"}
		}
	}
	{on animation_event "fx_fall_l"
		{view start "fx_fall_l"}
		{view show "fx_fall_l"}
		{delay 3
			{view hide "fx_fall_l"}
			{view stop "fx_fall_l"}
		}
	}
	{on animation_event "fx_fall_hit_l"
		{call "random_component_break_l"}
	}
	{on animation_event "fx_fall_hit_r"
		{call "random_component_break_r"}
	}
	;-----------------------------------------------------------------------------------------------------------------------------------
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
	}
	{on animation_event "close_attack_leave";dread harv
		{view hide "close_attack_dread"}
		{view stop "close_attack_dread"}	
	}
}


{"cannon_152mm" 
	{on ik begin "RightWeaponRotate_ik"
		{if rand 0.2
			{spawn "wpn_alarm_missiles" "RightWeaponRotate"}
			;{start_sound "generation_zero/characters/wpn_alarm/wpn_alarm_mortar/bb/tank_wpn_alarm_mortar_verb"}	
			;{start_sound "generation_zero/characters/wpn_alarm/wpn_alarm_mortar/dir/tank_wpn_alarm_mortar_dir"}	
		}		
		{tags remove "hold"}	
		{tags remove "search"}	
		{tags add "alarm"}
		{if not tagged "alarm_call_signal"
			{tags add "alarm_call_signal"}
			{if not tagged "move"
				{chassis_work 0}
				{delay 1.5
					{if work "fuel"
						{chassis_work 1}
					}
				}
			}
			{call "ai_talk_signal"}
		}
		{delay 4 {tags remove "alarm_call_signal"}}
	}
	{on fire "mgun" 
		{call "drop_speed_move"}
		{kill_delay "heat"}
		{if not tagged "heat"				
			{tags add "heat"}
			{ani_play "heat_mg" +0.1 resume callback}
		}
		{delay 3 "heat"
			{if broken "fan" 3
				{ani_play "heat_mg" -0.01 resume callback}
			else broken "fan" 2
				{ani_play "heat_mg" -0.03 resume callback}
			else broken "fan" 1
				{ani_play "heat_mg" -0.04 resume callback}
			else
				{ani_play "heat_mg" -0.05 resume callback}
			}
		}
		{ani_play "recoil_gun"}
		{tags add "fire_mgun"}
		{delay 0.3
			{tags remove "fire_mgun"}
		}	
		{link_sound "loop_fire" "weapon/shot/loop/25mm/plr/25mm_loop"}
		{link_sound "stop_fire" "weapon/shot/loop/25mm/plr/25mm_stop"}
		{if not tagged "firing"				
			{play_sound "loop_fire" 1}
			{tags add "firing"}
		}
		{tags add "fast_fire"}
		(define "fire_barrel"
			name "%0"
				{spawn "fx_shoot_hit_sparks" "fx_muzzle%0" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "fx_muzzle%0" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "fx_muzzle%0" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "fx_muzzle%0" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
				{view start "fx_muzzle%0"}
				{view start "maingun_smoke"}
				{delay 0.015 "fire"
					{spawn "shell20_casing" "fx_eject_%0" x scale 0.5
						{impulse up 1.5 0.5 dir -7 cz 0.5 0.1 com}
						{delay 5
							{hide 3}
						}
					}
					{view hide	"fx_muzzle%0"}
					{tags remove "fast_fire"}
					{view pause "fx_muzzle%0"}
				}
		)
		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
		{delay 2 1 "fire"
			{view hide	"maingun_smoke"}
			{view pause	"maingun_smoke"}
		}
		{if tagged "firing"			
			{delay 0.1
				{tags remove "firing"}
				{if not tagged "firing"				
					{delay 0.5 "heat"
						{tags remove "heat"}
						{ani_stop "heat_mg"}
					}
					{stop_sound "loop_fire" }
					{play_sound "stop_fire" }
				}
			}
		}
		{if tagged "shoot_emitters_ext"
			{start_sound "shoot_emitters_ext/zenite/"}
		}		
		{if tagged "shoot_emitters_int"
			{start_sound "shoot_emitters_int/zenite/"}
		}		
		{if tagged "shoot_emitters_mtl"
			{start_sound "shoot_emitters_ext/zenite/"}
		}		
		{if not tagged "alarm_call_signal"
			{tags add "alarm_call_signal"}
			{call "ai_talk_signal"}
		}
		{delay 4 {tags remove "alarm_call_signal"}}
	}
	{on fire "gun" 
		{if tagged "damage_gun"
			{burn volume "Guided_Missile" fx "smoke_heat" time 4 fake}
			{delay 0.5
				{if rand 0.1
					{spawn "electric_spark_hit" "Guided_Missile"}
				else rand 0.1
					{spawn "electric_spark_hit" "rocket"}
				}			
			}			
			{delay 16
				{if not tagged "destroy_gun_main"
					{weapon_work "gun" 1}
					{if rand 0.7
						{spawn "electric_spark_hit" "Guided_Missile"}
						{start_sound "generation_zero/characters/dreadnought/search_to_combat/drea_c4_voc_search_to_combat_01"}	
						{start_sound "generation_zero/characters/dreadnought/search_to_combat_bb/drea_c4_voc_search_to_combat_01_bb"}	
					}
					{delay 0.8
						{if rand 0.5
							{spawn "electric_spark_hit" "Guided_Missile"}
						else rand 0.4
							{spawn "electric_spark_hit" "rocket"}
						}			
					}			
				}			
			}
		}
		{tags remove "load_mortar"}
		{tags add "fire_missile"}
		{delay 0.3
			{tags remove "fire_missile"}
		}	
		{spawn "fx_shoot_hit_sparks" "foresight_gun" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_gun" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight_gun" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{view show 	"fx_muzzle"}
		{spawn "shoot_gun_dread" "foresight_gun"}
		{delay 1 "fire"
			{view hide	"fx_muzzle"}
			{view pause "fx_muzzle"}
		}
	}
}
{"dreadnought_mg"
	{on fire "gun" 
		{tags add "fire_gun"}
		{delay 0.3
			{tags remove "fire_gun"}
		}	
		{spawn "distant_small_gun" "Foresight_rocket" }
		(define "fire_barrel"
			name "%0"
				{spawn "rpg_shot" "shooter_a%0_fx" x}			
		)
		{if   
			("fire_barrel" args 00)
		else 
			("fire_barrel" args 01)
		else
			("fire_barrel" args 02)
		else 
			("fire_barrel" args 03)
		else 
			("fire_barrel" args 04)
		else 
			("fire_barrel" args 05)
		else 
			("fire_barrel" args 06)
		else 
			("fire_barrel" args 07)
		else 
			("fire_barrel" args 08)
		else 
			("fire_barrel" args 09)
		}
	}
	{on fire "mgun" 
		{tags remove "hold"}	
		{tags remove "search"}	
		{tags add "alarm"}
		{if not tagged "alarm_call_signal"
			{tags add "alarm_call_signal"}
			{call "ai_talk_signal"}
		}
		{delay 4 {tags remove "alarm_call_signal"}}
		{kill_delay "heat"}
		{if not tagged "heat"				
			{tags add "heat"}
			{ani_play "heat_mg" +0.1 resume callback}
		}
		{delay 3 "heat"
			{if broken "fan" 3
				{ani_play "heat_mg" -0.01 resume callback}
			else broken "fan" 2
				{ani_play "heat_mg" -0.03 resume callback}
			else broken "fan" 1
				{ani_play "heat_mg" -0.04 resume callback}
			else
				{ani_play "heat_mg" -0.05 resume callback}
			}
		}
		{ani_play "recoil_gun"}
		{tags add "fire_mgun"}
		{delay 0.3
			{tags remove "fire_mgun"}
		}	
		{link_sound "loop_fire" "weapon/shot/loop/25mm/plr/25mm_loop"}
		{link_sound "stop_fire" "weapon/shot/loop/25mm/plr/25mm_stop"}
		{if not tagged "firing"				
			{play_sound "loop_fire" 1}
			{tags add "firing"}
		}
		{tags add "fast_fire"}
		(define "fire_barrel"
			name "%0"
				{spawn "fx_shoot_hit_sparks" "fx_muzzle%0" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "fx_muzzle%0" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "fx_muzzle%0" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "fx_muzzle%0" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
				{view start "fx_muzzle%0"}
				{view start "maingun_smoke"}
				{delay 0.015 "fire"
					{spawn "shell20_casing" "fx_eject_%0" x scale 0.5
						{impulse up 1.5 0.5 dir -7 cz 0.5 0.1 com}
						{delay 5
							{hide 3}
						}
					}
					{view hide	"fx_muzzle%0"}
					{tags remove "fast_fire"}
					{view pause "fx_muzzle%0"}
				}
		)
		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
		{delay 2 1 "fire"
			{view hide	"maingun_smoke"}
			{view pause	"maingun_smoke"}
		}
		{if tagged "firing"			
			{delay 0.1
				{tags remove "firing"}
				{if not tagged "firing"				
					{delay 0.5 "heat"
						{tags remove "heat"}
						{ani_stop "heat_mg"}
					}
					{stop_sound "loop_fire" }
					{play_sound "stop_fire" }
				}
			}
		}
		{if tagged "shoot_emitters_ext"
			{start_sound "shoot_emitters_ext/zenite/"}
		}		
		{if tagged "shoot_emitters_int"
			{start_sound "shoot_emitters_int/zenite/"}
		}		
		{if tagged "shoot_emitters_mtl"
			{start_sound "shoot_emitters_ext/zenite/"}
		}		
	}
}