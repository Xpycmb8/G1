{"lynx_base"
	{inflammation_time 2}
	{on spawn
		{tags add "rus"}
		{delay 0.1
			{if not "exploded"
				{if not "engine_started"
					{set "engine_started" 1}
					{if tagged "frends"
						{player 0}
					else
						{player 9}
					}
					{if not tagged "started"
						{start_sound "generation_zero/characters/lynx/engine/starter/"}	
						{tags add "started"}
						{ani_play "power_up_spawn" resume }	
					}
				else
					{ani_wind "power_up_spawn" end}
					{if tagged "frends"
						{player 0}
					else
						{player 9}
					}
				}
			}
		}
		{tags add "lynx_base"}
		{tags add "hold"}
		{tags add "machine"}
		{call "ai_talk_signal"}
;		{call "led_ems_connect"}
		{call "led_light_connect"}
;		{call "radio_connect"}
		{call "sound_connect"}
		{call "fire_connect"}
;		{call "add_fx_component"}
		

		{add_view 	"scanline_light" 						"scanline_light" "scanlines_fx"}
		{add_view 	"scanline_burn" 						"scanline_light" "scanlines2_fx_bone"}
		{add_view 	"scanline_burn" 						"scanline_light" "scanlines_fx_bone"}
		{add_view 	"cooling_engine_small" 		"cooling_engine_r" 		"RightEngine"}
		{add_view 	"cooling_engine_small" 		"cooling_engine_l" 		"LeftEngine"}
		
		{add_view 	"burn_element" 		"left_engine_burn" 			"LeftEngine"}
		{add_view 	"burn_element" 		"right_engine_burn" 		"RightEngine"}
		
		{add_view 	"burn_element" 		"hydraulic_burn" 		"hydraulic"}

		{add_view 	"burn_component_break_tiny" 			"explosion_fx" "Head"} 
		{add_view 	"burn_component_break_tiny" 			"explosion_fx" "burn_fx"}
		
		
		{add_view 	"brake_fx" 		"brake_on" 			"brake_l_fx"}
		{add_view 	"brake_fx" 		"brake_on" 			"brake_r_fx"}

		{add_view 	"muzzle_single" 				"fx_muzzle_heat" 		"fx_main"} ;mg
		{add_view 	"muzzle_single_heavy" 			"fx_muzzle_heat_full" 	"fx_main"};mg
		{add_view 	"heat_stage1" 					"stage1" 				"fx_main"};mg_not use
		{add_view 	"heat_stage2_small" 			"stage2" 				"fx_main"};mg_not use
		{add_view 	"smoke_sil" 					"fx_fire_hot" 			"fx_main"};mg

		{add_view 	"muzzle_gun30_auto" 			"fx_muzzle_ags" 	"fx_main"};ags

		{add_view 	"blade_pull_loop_fx" 					"blade_fx" 			"blade_fx"};mg

		{view hide	"scanline_light"}
		{view pause	"scanline_light"}
		{view hide	"brake_on"}
		{view pause	"brake_on"}
		{view hide	"left_engine_burn"}
		{view pause	"left_engine_burn"}
		{view hide	"right_engine_burn"}
		{view pause	"right_engine_burn"}
		{set "engine_started" 0}
		{set "stop" 1}
		{delay 15 5 "idle_enter"
			{tags add "idle_enter"}
			{call "idle-enter"}
		}		
		{volumes "sawblade" disable contact contact_ground overlap blast bullet}		   
 	}
	{on "sound_connect" 
		{link_sound "power_down_bb" "generation_zero/characters/lynx/engine/shutdown/bb/machine_soviet_emp_lynx_shutdown_bb"}
		{link_sound "power_down" "generation_zero/characters/lynx/engine/shutdown/dir/machine_soviet_emp_lynx_shutdown_dir-lr-lr"}

		{link_sound "power_up_bb" "generation_zero/characters/lynx/engine/start/bb/machine_soviet_emp_lynx_start_bb"}
		{link_sound "power_up" "generation_zero/characters/lynx/engine/start/dir/machine_soviet_emp_lynx_start_dir-lr"}

		{link_sound "engine_add" 		"generation_zero/characters/lynx/engine/loop/turbine/soviet_lynx_engine_howl_01"}
		{link_sound "engine" 			"generation_zero/characters/lynx/engine/loop/soviet_lynx_engine_loop_H02_02"}

		{link_sound "ground" 			"generation_zero/characters/lynx/move/ground/lynx_ball_roll_dirt_slow"}
		{link_sound "grass" 			"generation_zero/characters/lynx/move/grass/lynx_ball_roll_grass_slow"}
		{link_sound "tarmac" 			"generation_zero/characters/lynx/move/tarmac/lynx_ball_roll_tarmac_slow"}
		{link_sound "saw_start_run" 	"generation_zero/characters/lynx/saw/saw_start_run/lynx_melee_saw_start_run_loop_02"}
		{link_sound "saw_loop" 			"generation_zero/characters/lynx/saw/lynx_melee_saw_hit_loop_01"}
		{link_sound "mid_mg"			"weapon/shot/small_arms/sg552"}		
		{link_sound "close_mg"			"weapon/shot/small_arms/sg552_close"}	
		{link_sound "far_mg"			"weapon/shoot_loud/far/lmg"}	
	}
	{on "led_ems_connect";not use
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
		("leds_ems_global_small"  vis(head_ems_00)  )
	}
	{on "led_light_connect" 
		(define "leds_ems_global"
			{add_view 	"yellow_ems_med" 	"ems_global_search" 	"%vis_search"}
			{add_view 	"red_ems_med" 		"ems_global_alarm" 		"%vis_alarm"}
			{add_view 	"hold_ems_med" 		"ems_global_hold" 		"%vis_hold"}
			{view show	"ems_global_hold"}
			{view start	"ems_global_hold"}
			{view hide	"ems_global_alarm"}
			{view pause	"ems_global_alarm"}
			{view hide	"ems_global_search"}
			{view pause	"ems_global_search"}
		)
		("leds_ems_global"  vis(head_ems_00) )
	}
	{on "ai_talk_signal" 
		{delay 0.2
			{if tagged "alarm"
				{tags remove "search"}
				{tags remove "hold"}
				{if not tagged "alarm_call"
					{tags add "alarm_call"}
					{if rand 0.4
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_01_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_01_verb"}	
					else rand 0.3
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_02_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_02_verb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_03_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_03_verb"}	
					else rand 0.1
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_04_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_04_verb"}	
					else rand 0.1
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_06_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_06_verb"}	
					else 
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_05_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_05_verb"}	
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
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_01_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_01_verb"}	
					else rand 0.3
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_02_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_02_verb"}	
					else rand 0.2
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_03_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_03_verb"}	
					else rand 0.1
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_04_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_04_verb"}	
					else rand 0.1
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_06_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_06_verb"}	
					else 
						{start_sound "generation_zero/characters/lynx/combat/lynx_voc_alert_05_dir"}	
						{start_sound "generation_zero/characters/lynx/combat_bb/lynx_voc_alert_05_verb"}	
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
	(define "leds_ems_connect"
		("leds_ems"  vis(head_ems_00) 		)
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
		(define "leds_ems"
			{view hide	"ems_global_alarm"}
			{view pause	"ems_global_alarm"}
			{view hide	"ems_global_search"}
			{view pause	"ems_global_search"}
			{view hide	"ems_global_hold"}
			{view pause	"ems_global_hold"}
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
					{tags remove "search"}	
					{tags remove "alarm"}	
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
					{tags remove "search"}	
					{tags remove "alarm"}	
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
	{on brake on 
		{if tagged "fast_move"
			{tags remove "fast_move"}
		}
		{if velocity 15
			{ani_play "brake_on" 0.2 }
		else 
			{ani_play "brake_on" 0.4 }
		}
	}	
	{on animation_event "brake_fx_lynx_start" 
		{view show	"brake_on"}
		{view start	"brake_on"}
	}
	{on animation_event "brake_fx_lynx_stop" 
		{view hide	"brake_on"}
		{view pause	"brake_on"}
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
	{on move on ;lynx
		{weapon_work "attack_melee_charge_close" 0}
		{call "stop_idle"}
		{tags add "move"}	
		{set "blocked" 1}
		{if not tagged "turn"
			{if Move_Forward
				{tags add "move_forward"}
				{tags remove "move_backward"}
				; {if velocity 10
					; {ani_play "runstart_f" 0.5 }
				; else velocity 0
					; {ani_play "walkstart_f"  }
				; }
			else
				{tags remove "move_forward"}
				{tags add "move_backward"}
			}
		}
		(define "terrain_fx_sound"	
			{if tagged "%terrain"
				{play_sound "%terrain" 1}
			}
		)
		("terrain_fx_sound" terrain(ground)		sound(ground)	)	
		("terrain_fx_sound" terrain(wood)  		sound(ground)		)	
		("terrain_fx_sound" terrain(metal)  	sound(ground)		)	
		("terrain_fx_sound" terrain(gravel) 	sound(tarmac)			)	
		("terrain_fx_sound" terrain(grass)  	sound(grass)	)	
		; {if broken "" 
		; }
		; {play_sound "" }
		; {tags add ""}
		; {if velocity 30
			; {play_sound "" }
		; else velocity 0
			; {play_sound "" }
		; }	
		{call "weapon_off"}
		; {if broken "upper_arm" 2
			; {tags add "engine_leg_broken"}
		; }
	}
	{on move off ;lynx
		{tags remove "move_forward"}	
		{tags remove "move_backward"}	
		{tags remove "move"}	
		{tags remove "turn"}
		{tags remove "run"}
		{tags remove "walk"}
		{set "blocked" 0}
		{stop_sound "ground" }
		{stop_sound "tarmac" }
		{stop_sound "grass" }
	}
	{on turn on ; lynx
		(define "terrain_fx_sound"	
			{if tagged "%terrain"
				{play_sound "%terrain" 1}
			}
		)
		("terrain_fx_sound" terrain(ground)		sound(ground)	)	
		("terrain_fx_sound" terrain(wood)  		sound(ground)		)	
		("terrain_fx_sound" terrain(metal)  	sound(ground)		)	
		("terrain_fx_sound" terrain(gravel) 	sound(tarmac)			)	
		("terrain_fx_sound" terrain(grass)  	sound(grass)	)	
		{set "blocked" 1}
		{call "stop_idle"}
		{tags add "turn"}
		{if turn_left
			{ani_play "turn_left" 0.15 loop resume }
			{tags add "turn_left"}	
		else turn_right
			{ani_play "turn_left" -0.15 loop resume }
			{tags add "turn_right"}	
		}
	}

	{on turn off ; lynx 
		{stop_sound "ground" }
		{stop_sound "tarmac" }
		{stop_sound "grass" }
		{ani_stop "turn_left" }
		{set "blocked" 0}
		{delay 1 "move_stop"
			{call "weapon_on"}
		}
		{tags remove "turn"}
		(define "turn_off"	
			{if tagged "%turn_off"
				{tags remove "%turn_off"}	
			}
		)
		("turn_off" turn_off(turn_right)  )	
		("turn_off" turn_off(turn_left)  )	
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
	{on "fx_component_mover" 
		(define "fx_component"
			{if not work "%component"
				{if rand %rand
					{spawn "component_break_fx" "%component"}
				}
			}
		)		
		("fx_component" rand(0.2) component(leftarm)   )
	}
	{on "move_update_speed" ; lynx
		(define "move_update"
			{if velocity %speed
				{ani_play "moveloop_fwd" (* %speed 1) }
				;{tags add "%speed"}	;check sum
				;{tags add "%ani"}	;check sum
			}
		)		
		("move_update" speed(19)  	)
		("move_update" speed(18)  	)
		("move_update" speed(17)  	)
		("move_update" speed(16)  	)
		("move_update" speed(15)  	)
		("move_update" speed(14)  	)
		("move_update" speed(13)  	)
		("move_update" speed(12)  	)
		("move_update" speed(11)  	)
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
;idle--------------------lynx
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
	{on contact ; lynx
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
				("mesh_break" component(sidearmor_03_rus_l)  					rand(0.3)    d_rand(0.3) )
				("mesh_break" component(sidearmor_02_rus_l)  					rand(0.3)   d_rand(0.3)  )
				("mesh_break" component(sidearmor_01_rus_l)  					rand(0.3)   d_rand(0.3)  )
				("mesh_break" component(sideplate_left)  						rand(0.3) d_rand(0.3)    )
				("mesh_break" component(kneepad_l)  							rand(0.3) d_rand(0.3)    )
				("mesh_break" component(left_engine)  							rand(0.3) d_rand(0.3)    )
				("mesh_break" component(sidearmor_03_rus_r)  					rand(0.3)   d_rand(0.3)  )
				("mesh_break" component(sidearmor_02_rus_r)  					rand(0.3)   d_rand(0.3)  )
				("mesh_break" component(sidearmor_01_rus_r)  					rand(0.3)   d_rand(0.3)  )
				("mesh_break" component(sideplate_right)  						rand(0.3) d_rand(0.3)    )
				("mesh_break" component(kneepad_r)  							rand(0.3) d_rand(0.3)    )
				("mesh_break" component(right_engine)  							rand(0.3) d_rand(0.3)    )
				("mesh_break" component(front_hatch)  							rand(0.3) d_rand(0.3)    )
;				("mesh_break" component(trackLeft)  							rand(0.3) d_rand(0.3)    )
;				("mesh_break" component(trackright)  							rand(0.3) d_rand(0.3)    )
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
				("organ_break" component(head) 				 		rand(0.5) rand_destroy(0.5)  )
				("organ_break" component(fuel)  					rand(0.3) rand_destroy(0.3)  )
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
		{if volume "sawblade"
			{tags add "sawblade_contact"}
			{if tagged "saw_attack"
				{delay 9
					{if tagged "sawblade_contact"
						{if not able "exploded"
							{ani_stop "saw_attack_loop" }	
							{ani_stop "saw_attack_move" }	
							{ani_play "saw_attack_stop" -0.5}		
							{ani_play "saw_attack_backup" 0.5}
							{kill_delay "check_ground"}		
							{tags remove "check_ground"}
							{tags remove "saw_attack"}
							{drop_orders}
							{if not able "exploded"
								{auto_operatable 1}
							}
							{view pause "blade_fx"}
							{ani_stop "rotate_saw" }	
							{start_sound "generation_zero/characters/lynx/saw/stop"}			
							{ani_play "close_saw" }	
							{volumes "sawblade" disable contact contact_ground overlap blast bullet}		   
						}
					}
				}
				{if effector "human"
					{tags add "human_contact"}
					{delay 3
						{tags remove "human_contact"}
					}
					{with_effector
						{talk "hit"}
						{tags add "bleeding_small_body_random"}
						{delay 8
							{tags remove "bleeding_small_body_random"}
						}
						{call "bleeding_small_body_random"}
					}
				}
				{if effector "physics"
					{call "backup_saw_restore"}
					{with_effector
						{impulse up 2}
					}
				else effector "wood fence"
					{call "backup_saw_restore"}
					{with_effector
						{call "break"}
					}
				else not tagged "human_contact"
					{call "backup_saw_end"}
				}
			}			
		}	
	}
	{on "backup_saw_restore"
		{if not tagged "backup"
			{tags add "backup"}
			{spawn "blade_contact" "sawblade_rot"}
			{spawn "damage_shock_micro" "sawblade_rot"}
			{kill_delay "saw_attack"}		
			{ani_stop "saw_attack_loop"   }	
			{ani_stop "saw_attack_move" }			
			{ani_play "saw_attack_contact" }
			{delay 1
				{tags remove "backup"}
				{ani_play "saw_attack_loop" -0.6  }	
				{ani_play "saw_attack_move" -0.6 }			
				{delay 1.5
					;{kill_delay "check_ground"}		
					{ani_play "saw_attack_loop" 1 loop }	
					{ani_play "saw_attack_move" 1 loop }			
						; {ani_stop "saw_attack_loop" }	
						; {ani_stop "saw_attack_move" }	
						; {ani_play "saw_attack_backup" 0.7 callback}
						; {stop_sound "saw_start_run"  }
						; {view pause "blade_fx"}
						; {ani_stop "rotate_saw" }	
						; {start_sound "generation_zero/characters/lynx/saw/stop"}			
						; {ani_play "close_saw" 0.5}	
						; ;{ani_wind "saw_attack" end}	
						; {volumes "sawblade" disable contact contact_ground overlap blast bullet}		   
						; {delay 2 {tags remove "backup"} {tags remove "sawblade_contact"}}
					; }					
				}
			}	
		}
	}	
	{on "backup_saw_end"
		{if not tagged "backup"
			{tags add "backup"}
			{spawn "blade_contact" "sawblade_rot"}
			{spawn "damage_shock_micro" "sawblade_rot"}
			{kill_delay "check_ground"}		
			{kill_delay "saw_attack"}		
			{ani_stop "saw_attack_loop" }	
			{ani_stop "saw_attack_move" }	
			{ani_play "saw_attack_contact" }
			{delay 1 
				{ani_stop "saw_attack_loop" }	
				{ani_stop "saw_attack_move" }	
				{ani_play "saw_attack_backup" 0.5 }
				{stop_sound "saw_start_run"  }
				{view pause "blade_fx"}
				{ani_stop "rotate_saw" }	
				{start_sound "generation_zero/characters/lynx/saw/stop"}			
				{ani_play "close_saw" 0.5}	
				;{ani_wind "saw_attack" end}	
				{volumes "sawblade" disable contact contact_ground overlap blast bullet}		   
				{delay 2 {tags remove "backup"} {tags remove "sawblade_contact"}}
			}					
		}
	}	
	{on ground_hit 
		{kill_delay "ground_contact"}
		{if "exploded"
			{if volume "armor_crushed"	
				{if rand 0.5
					{tear "piece_small_steel" bone from_volume
						{impulse dir 2 1}
					}
				}
			}
		; else
			; ;{if volume "ground_contact"	
				; {delay 2 "ground_contact"
					; {if not tagged "restore"
						; {tags add "restore"}
						; {chassis_work 0}
						; {spawn "spheredust_small"}			
						; {ani_play "jump" }			
						; ;{impulse up 0.001}
						; {delay 1 
							; {if work "fuel"
								; {chassis_work 1}
							; }
							; {tags remove "restore"}
							; ;{pillar_up}			
						; }
				; }
			; }
		}
	}
	{on animation_event "jump_pillar"
		{start_sound "generation_zero/characters/phy_robot_med/"}		
		{spawn "spheredust_small" "railing_r"}	
		{spawn "spheredust_small" "railing_l"}	
		{spawn "spheredust_small" "basis"}	
	}
	{on animation_event "pillar_up"
		{start_sound "generation_zero/characters/phy_robot_med/"}		
		{spawn "spheredust_small"}			
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
	{on blast ;lynx
		{if stuff "orientation_melee_front"
			{call "saw_front"}
		}
		(include "blast_all.inc")
		; ("orientation" vol(front_left_hit)  	ani_play(hit_stumble_45ccw)   rand(0.5)  min_energy(0.5) )
		; ("orientation" vol(front_right_hit)  	ani_play(hit_stumble_45cw)    rand(0.5)  min_energy(0.5) )
		; ("orientation" vol(back_left_hit)  		ani_play(hit_stumble_135cw)   rand(0.5)  min_energy(0.5) )
		; ("orientation" vol(back_right_hit)  	ani_play(hit_stumble_135ccw)  rand(0.5)  min_energy(0.5) )
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
		{if min_energy 8
			{if rand 0.3
				{call "explosion_lynx_big"}
			}
		else min_energy 4
			{if volume "main_body"
				{if stuff "rocketlauncher"
					{if rand 0.2
						{if not able "exploded"	
							{spawn "destroy_component" "body_organ"}
							{burn volume "head_organ" fx "burn_component_break_small" time 2 1 fake even_law}
							{burn volume "body_organ" fx "burn_component_break_small" time 2 1 fake even_law}
							{call "explosion_lynx"}
						}
					}
				}
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
		{if component "missile"
			{view start "smoke_missile"}
			{delay 10 5
				{view pause "smoke_missile"}
			}
			{burn volume "Guided_Missile" fx "smoke_heat" time 7 3 fake}	
			{tags add "damage_missile"}
			{spawn "break_small_body_robot" "rocket"}				
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
			;{burn volume "body_organ" fx "electric_spark_hit" time 0.4 fake}	
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
		{if component "head_organ";all
			{call "lose_health"}
			{burn volume "head_organ" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "head_organ"}
			{call "power_drop"}
		}
		{if component "hydraulic" 
			{call "lose_health"}
			{start_sound "generation_zero/electric_spark/"}	
			{view start "hydraulic_burn"}
			{delay 8 3
				{start_sound "generation_zero/electric_spark/"}
				{view stop "hydraulic_burn"}
			}
		}
		{if component "left_engine" 
			{call "lose_health"}
			{start_sound "generation_zero/electric_spark/"}	
			{view start "left_engine_burn"}
			{delay 8 3
				{start_sound "generation_zero/electric_spark/"}
				{view stop "left_engine_burn"}
			}
		}
		{if component "right_engine" 
			{call "lose_health"}
			{start_sound "generation_zero/electric_spark/"}	
			{view start "right_engine_burn"}
			{delay 8 3
				{start_sound "generation_zero/electric_spark/"}
				{view stop "right_engine_burn"}
			}
		}
		(define "mesh_break_armor" ;armor all
			{if component "%component" 
				{burn volume "%component" fx "smoke_preheat" time 2 1 fake}	
			}
		)
		;all armor
		("mesh_break_armor" component(kneepad_r)  				)
		("mesh_break_armor" component(kneepad_l)  				)
		("mesh_break_armor" component(sideplate_left)  				)
		("mesh_break_armor" component(sideplate_right)  				)
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
		("mesh_break_armor" component(kneepad_r)  				)
		("mesh_break_armor" component(kneepad_l)  				)
		("mesh_break_armor" component(sideplate_left)  				)
		("mesh_break_armor" component(sideplate_right)  				)
		{if component "main_body"
			{bone hide	"orange_ems"}
			{bone hide	"red_ems"}
		}
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
		else component "mgun"
			{weapon_work "mgun" 0}
			{tags add "destroy_mgun"}
			{spawn "ex_air_norm" "mgun"}
			{tear "piece_small_steel" bone "ammo"
				{impulse dir 1}
			}
			{delay 2 1 {ani_play "wpn_combat_to_idle" }}
		else component "right_engine"
			{call "lose_health"}
			{burn volume "right_engine" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "right_engine"}
		else component "left_engine"
			{call "lose_health"}
			{burn volume "left_engine" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "left_engine"}
		else component "head_organ"
			{call "lose_health"}
			{burn volume "head_organ" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "organ_head"}
			{call "power_drop"}
		else component "hydraulic" 
			{call "lose_health"}
			{burn volume "hydraulic" fx "smoke_heat" time 10 fake}
			{spawn "electric_spark_break" "hydraulic"}
		else component "fuel"
			{call "lose_health"}
			{spawn "break_small_body_robot" "fuel"}	;break fx
			{if rand 0.2
				{fire volume "fuel" radius 0.1 heating 0.5  time 5 follow}
			}
			{burn volume "fuel" fx "smoke_heat" time 10 fake}
			{burn volume "fuel" fx "burn_component_break_small" time 3 fake}
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
	{on pierce ;Lynx
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
				{call "explosion_lynx_big"}
				{impulse dir 5 3 }
			}
			{if stuff %0
				{if volume "organ"
					{if not able "exploded"	
						{spawn "destroy_component" "body_organ"}
						{call "explosion_lynx"}
					}
				}
				{if volume "main_body"
					{if rand 0.7
						{call "explosion_lynx"}
					else rand 0.2
						{call "explosion_lynx_big"}
						{impulse dir 5 3 }				
					}
				}
			}
		)	
		("hit_system" args "rocketlauncher"		)
		("hit_system" args "shell"				)
		(define "hit_system_organ"		
			{if volume "organ"
				{if stuff %0
					{if rand %1
						{call "explosion_lynx"}
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
				{if volume "%volume"
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
		("mesh_break" volume(wheell2) 		component(trackLeft)  				 			stuff_destroy(0.2)    )
		("mesh_break" volume(wheelr2) 		component(trackRight)  				 			stuff_destroy(0.2)    )
		("mesh_break" volume(main_body) 	component(main_body)  				 			stuff_destroy(0.1)    )
		("mesh_break" volume(head) 			component(head)  				 				stuff_destroy(0.2)    )
		("mesh_break" volume(cpu) 			component(cpu)  				 				stuff_destroy(0.5)    )
		("mesh_break" volume(fuel) 			component(fuel)  			 					stuff_destroy(0.3)    )
			
		("mesh_break" volume(kneepad_r) 	component(kneepad_r)  					 stuff_destroy(0.3)    )
		("mesh_break" volume(kneepad_l) 	component(kneepad_l)  					 stuff_destroy(0.3)    )
		("mesh_break" volume(front_hatch) 	component(front_hatch)  					 stuff_destroy(0.3)    )
		;all armor
	
		("mesh_break" volume(sideplate_left) 	component(sideplate_left)  					 stuff_destroy(0.3)    )
		("mesh_break" volume(sideplate_right) 	component(sideplate_right)  					 stuff_destroy(0.3)    )
		("mesh_break" volume(railing_b_armor) 	component(railing_b_armor)  				stuff_destroy(0.3)    )

;------------------
	(include "pierce_all.inc")
	}
	{on "explosion_lynx_big" 
		{if not able "exploded"	
			{with_linked_entity "link_front"
				{delete}
			}			
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
			{stop_sound "engine_add" }
			{stop_sound "engine" }
			{stop_sound "ground" }
			{stop_sound "grass" }
			{stop_sound "tarmac" }
			{stop_sound "saw_start_run" }
			{stop_sound "saw_loop" }
			{bone hide "head_ems_00_alarm"}
			{bone hide "head_ems_00_search"}
			{bone hide "head_ems_00_hold"}
			{tags add "off"}
			{tags add "dead"}
			{call "stop_all"}
			{if tagged "move"
				{impulse forward 1.5 cx 2 1 cy 2 1 no_position}		
			else
				{impulse up 0.5 cx 3 2 cy 3 2 rnd_dir 2 no_position}		
			}
			{burn volume "cpu" fx "fx_fire_engine_gen" time 2 fake even_law}					
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
			{view start "explosion_fx"}
			{view show "explosion_fx"}
			{delay 15
				{view hide "explosion_fx"}
			}
		}
	}	
	{on "explosion_lynx" 
		{if not able "exploded"	
			{with_linked_entity "link_front"
				{delete}
			}			
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
			{stop_sound "engine_add" }
			{stop_sound "engine" }
			{stop_sound "ground" }
			{stop_sound "grass" }
			{stop_sound "tarmac" }
			{stop_sound "saw_start_run" }
			{stop_sound "saw_loop" }
			{bone hide "head_ems_00_alarm"}
			{bone hide "head_ems_00_search"}
			{bone hide "head_ems_00_hold"}
			{tags add "off"}
			{tags add "dead"}
			{call "stop_all"}
			{if tagged "move"
				{impulse forward 1.5 cx 2 1 cy 2 1 no_position}		
			else
				{impulse up 0.1 cx 0.5 0.2 cy 0.5 0.2 rnd_dir 0.5 no_position}		
			}
			{burn volume "cpu" fx "fx_fire_engine_gen" time 2 fake even_law}					
			{kill_delay "idle"}
			{drop_orders}
			;{delay 0.5
			;	{components destroy}
			;}
			{reset_manual_control}
			{auto_operatable 0}
			{delay_ex 0.1
				{set_skeleton "_x" sync}
				{call "tear_parts"}
			}
			{clear_inventory}
			{spawn "destroy_med_robot" "hips"}
			{spawn "burn_flare" "head"}
			{view start "explosion_fx"}
			{view show "explosion_fx"}
			{delay 15
				{view hide "explosion_fx"}
			}
		}
	}	
	{on "tear_parts_explode"
		{spawn "car_destroy_engine" }
		(define "blasted"
			{if rand %1
				{tear "piece_small_steel" bone %0
					{mtl_enable_skin 0}
					{impulse up 4 3 dir 12 5 cx 3 2 cy 3 2 no_position}
				}
			}
		)
		("blasted" args "fuel" 				0.4)
		("blasted" args "Head" 				0.4)
		("blasted" args "front_hatch" 		0.4)
		("blasted" args "railing_r" 		0.4)
		("blasted" args "railing_l" 		0.4)
		("blasted" args "brake_r" 			0.4)
		("blasted" args "brake_l" 				0.4)
		("blasted" args "wheelr2" 				0.7)
		("blasted" args "wheell2" 				0.7)
		("blasted" args "kneepad_r" 			0.4)
		("blasted" args "kneepad_l" 			0.4)
		("blasted" args "sideplate_right" 		0.4)
		("blasted" args "sideplate_left" 		0.4)
		("blasted" args "mgun" 					0.4)
		("blasted" args "railing_b_armor" 		0.4)
		
	}
	{on "tear_parts"
		(define "blasted"
			{if rand %1
				{tear "piece_small_steel" bone %0
					{mtl_enable_skin 0}
					{impulse up 0.5 dir 1 0.5 cx 1 0.5 cy 1 0.5 rnd_dir 1 0.5 no_position}
				}
			}
		)
		("blasted" args "fuel" 				0.2)
		("blasted" args "Head" 				0.2)
		("blasted" args "front_hatch" 		0.2)
		("blasted" args "railing_r" 		0.3)
		("blasted" args "railing_l" 		0.3)
		("blasted" args "brake_r" 			0.4)
		("blasted" args "brake_l" 				0.4)
		("blasted" args "wheelr2" 				0.3)
		("blasted" args "wheell2" 				0.3)
		("blasted" args "kneepad_r" 			0.5)
		("blasted" args "kneepad_l" 			0.5)
		("blasted" args "sideplate_right" 		0.5)
		("blasted" args "sideplate_left" 		0.5)
		("blasted" args "mgun" 					0.6)
		("blasted" args "railing_b_armor" 		0.1)
	}
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
	{on ik begin "head_ik_h"
		{tags add "hold"}
		{tags remove "search"}	
		{tags remove "alarm"}	
		{call "ai_talk_signal"}
	}
	{on fire "alarm_signal"   ;lynx base
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
	}
	; {on fire "mgun_melee" overload
		; {start_sound "generation_zero/characters/skirmisher/jump"}
		; {spawn "spheredust_norm" "basis" }		
		; {tags add "jump"}
		; {ani_stop "runloop_f" }
		; {ani_play "attack_melee_charge_01" 1 }
		; {delay 0.5
			; {weapon_work "attack_melee_charge 0}
		; }
	; }
	{on "check_ground"
		{if tagged "check_ground"
			{impulse up -0.1}
		else
			{kill_delay "check_ground"}		
		}
		{delay_effect 0.2 "check_ground"}		
	}
	{on fire "saw_signal" ; lynx
		{call "saw_front"}
	}
	{on "saw_front"
		{with_linked_entity "link_front"
			{call "close"}
		}			
		{auto_operatable 0}
		{drop_orders}
		;{impulse up 0.1}
		{tags add "saw_attack"}
		{delay 0.1
			{ani_play "saw_attack_start" callback}	;{5 "saw_attack_start"}
			{tags add "check_ground"}
			{call "check_ground"}
		}
		
	}	
	{on animation_event "saw_attack_start" 
		{ani_play "open_saw" callback}	
	}
	{on animation_end "saw_attack_start"
		{ani_play "saw_attack_loop" +1 resume loop }	
		{ani_play "saw_attack_move" +1 resume loop}			
		{delay 8 "saw_attack" ;time attack
			{if not tagged "sawblade_contact"
				{if not able "exploded"
					{ani_stop "saw_attack_loop" }	
					{ani_stop "saw_attack_move" }	
					{ani_play "saw_attack_stop" -0.5}		
					{ani_play "saw_attack_backup" 0.5}
					{kill_delay "check_ground"}		
					{tags remove "check_ground"}
					{tags remove "saw_attack"}
					{drop_orders}
					{if not able "exploded"
						{auto_operatable 1}
					}
					{view pause "blade_fx"}
					{ani_stop "rotate_saw" }	
					{start_sound "generation_zero/characters/lynx/saw/stop"}			
					{stop_sound "saw_start_run"  } 
					{ani_play "close_saw" }	
					{volumes "sawblade" disable contact contact_ground overlap blast bullet}		   
				}
			}
		}
	}
	; {on animation_end "saw_attack_loop"
		; {ani_play "saw_attack_stop"}		
	; }
	; {on animation_end "saw_attack_backup"
		; {if not tagged "sawblade_contact"
		; }			
	; }
	{on animation_event "open_saw" 
		{start_sound "generation_zero/characters/lynx/saw/saw_deploy"}			
	}
	{on animation_end "open_saw"
		{volumes "sawblade" enable contact contact_ground overlap blast bullet}		   
		{ani_play "rotate_saw" loop}	
		{play_sound "saw_start_run"  1} ;6sec
		{view start "blade_fx"}
;		{delay 6 "saw_attack"
	}
	; {on animation_end "rotate_saw"
	; }
	


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
		(define "work"
			{if work "%set"
				{weapon_work "%set" 1}
			}
		)
		("work"  set(gun))
		("work"  set(mgun))
		{if not able "exploded" 
			{auto_operatable 1}
			{able select 1}
			{call "power_up"}
		}
	}
	{on animation_event "20heal" ;all
		{burn volume "cpu" fx "smoke_heat" time 5 fake}	
	}
	{on animation_event "40heal"  ;all	
		{burn volume "cpu" fx "smoke_heat" time 7 fake}	
	}
	{on animation_event "70heal"  ;all
		{burn volume "cpu" fx "fx_fire_engine_gen" time 2 fake even_law}					
	}
	{on animation_event "explosion_lynx" 
		{call "explosion_lynx"}
	}
	{on animation_event "clear_casing_762"
		{tear "shell_drop_762_57" bone "shell_drop" copy 
			{impulse forward 6 3 cx -1.5 1.5 com}
		}
		{delay 0
			{view hide "shell_drop"}	
		}
	}		
	{on animation_event "bullet_drop_view" ;hunter lynx skir skir_shotg_w 
		{view show "shell_drop"}	
	}
	{on animation_event "search_idle"
		{tags add "hold"}
		{tags remove "search"}	
		{tags remove "alarm"}	
		{call "ai_talk_signal"}
	}
	{on animation_event "idle_rand" 
		; {if rand 0.3
			; {start_sound "generation_zero/characters/skirmisher/idle/"}				
		; }
	}
}


{"lynx_mg"
	{on fire "mgun"  ; lynx
		{call "drop_speed"}
		{play_sound "mid_mg"}
		{play_sound "close_mg"}
		{play_sound "far_mg"}
		{if tagged "damage_mgun" {if rand 0.1 {call "jammed_gun"}}}
		{view start "fx_muzzle_heat"}
		{view show "fx_muzzle_heat"}
		{delay 0.1 "fire"
			{view show	"fx_fire_hot"}
			{view start	"fx_fire_hot"}
			{view hide	"fx_muzzle_heat"}
			{view pause	"fx_muzzle_heat"}
		}
		{delay 1 0.5 "fire_hot"
			{view hide	"fx_fire_hot"}
			{view pause	"fx_fire_hot"}
		}
		{tags add "firing"}
		{tags add "firing_smg"}
		{delay 3 "firing"
			{tags remove "firing"}
			{tags remove "firing_smg"}
		}
		{ani_play "recoil_mgun" }		
		{spawn "trace_linear" "fx_main" x }
		{spawn "trace_linear" "fx_main" x }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "fx_main" }
		; {if not tagged "fire_move"				
			; {tags add "fire_move"}
			; {ani_play "wpn_recoil" -0.1 resume}				
		; }
		; {delay 0.1 "fire_hold"
			; {ani_play "wpn_recoil" +0.1 resume}				
		; }
		{tags add "alarm"}
		{tags remove "hold"}
		{tags remove "search"}
		;{call "stop_all_ani"}
		{call "ai_talk_signal"}
		{call "stop_idle"}
		;{chassis_work 0}
		{tags remove "idle_enter"}
	}
	{on "reload" overload 
		{if tagged "firing_smg"
			{if work "mgun"
				{tags add "mgun_r"}
				{delay 1
					{ani_play "wpn_reload" 0.5}	
					{tags remove "mgun_r"}
				}
			}
		}
	}
}
{"lynx_ags"
	{on fire "mgun"  ; lynx
		{call "drop_speed"}
		{view start "fx_muzzle_ags"}
		{view show "fx_muzzle_ags"}
		{delay 0.1 "fire"
			{view show	"fx_smoke"}
			{view start	"fx_smoke"}
			{view hide	"fx_muzzle_ags"}
			{view pause	"fx_muzzle_ags"}
		}
		{delay 2 0.5 "fire_hot"
			{view hide	"fx_smoke"}
			{view pause	"fx_smoke"}
		}
		{tags add "firing"}
		{tags add "firing_ags"}
		{delay 3 "firing"
			{tags remove "firing"}
			{tags remove "firing_ags"}
		}
		{ani_play "recoil" }		
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "fx_main" }
		{spawn "shoot_gun_ags_lynx" "fx_main" }	
		{tags add "alarm"}
		{tags remove "hold"}
		{tags remove "search"}
		{call "ai_talk_signal"}
		{call "stop_idle"}
		{tags remove "idle_enter"}
	}
	{on "reload" overload 
		{if tagged "firing_ags"
			{if work "mgun"
				{tags add "mgun_r"}
				{delay 1
					;{ani_play "wpn_reload" 0.5}	
					{tags remove "mgun_r"}
				}
			}
		}
	}
}

