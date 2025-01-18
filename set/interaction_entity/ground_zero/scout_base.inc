{"scout_base"
	{inflammation_time 9}
	{on spawn
		{if prop "prototype"
			{add_view	"scout_jetengine_prototype"			"jetengine_r"		"right_jetengine_fx"}
			{add_view	"scout_jetengine_prototype"			"jetengine_l"		"left_jetengine_fx"}
		else
			{add_view	"scout_jetengine"			"jetengine_r"		"right_jetengine_fx"}
			{add_view	"scout_jetengine"			"jetengine_l"		"left_jetengine_fx"}
		}
		{add_view	"scout_jetengine_damage"	"jetengine_damage_r"		"right_jetengine_fx"}
		{add_view	"scout_jetengine_damage"	"jetengine_damage_l"		"left_jetengine_fx"}
		{add_view 	"scanline_light" 						"scanline_light" "scanlines_fx"}
		{add_view 	"scanline_burn" 						"scanline_light" "scanlines2_fx_bone"}
		{add_view 	"scanline_burn" 						"scanline_light" "scanlines_fx_bone"}
		{add_view	"dust_landed_scout"			"land_ground"		"basis"}

		;burn_element
		{add_view 	"burn_element_cpu" 			"cpu_burn" "cpu"}
		{add_view 	"smoke_element_cpu" 		"cpu_smoke" "cpu"}
		
		{add_view 	"burn_element" 			"smoke_hips_h" "H_drive"}
		{add_view 	"burn_element" 			"smoke_hips_v" "V_drive"}
		
		{link_sound "engine_dir" 	"generation_zero/characters/scout/rotor/far/scout_rotor"}
		{link_sound "engine_close" 	"generation_zero/characters/scout/rotor/close/scout_rotor"}
		{link_sound "radio_var1" 	"generation_zero/characters/scout/radio/radio_comms_loop_001"}
		{link_sound "radio_var2" 	"generation_zero/characters/scout/radio/radio_comms_loop_002"}
		{link_sound "radio_var3" 	"generation_zero/characters/scout/radio/radio_comms_loop_003"}
		{link_sound "radio_var4" 	"generation_zero/characters/scout/radio/radio_comms_loop_tone_023"}

		{add_view	"burn_component_break_small"	"destroy_fx"		"hips"}
		{view hide	"scanline_light"}
		{view pause	"scanline_light"}
		{view pause "destroy_fx"}
		{view hide "jetengine_r"}
		{view pause "jetengine_r"}
		{view hide "jetengine_l"}
		{view pause "jetengine_l"}
		{view pause "jetengine_damage_r"}
		{view pause "jetengine_damage_l"}
		{view hide "jetengine_damage_r"}
		{view hide "jetengine_damage_l"}		
		{ani_play "power_up_spawn" resume }	
		;{start_sound "generation_zero/characters/pest/spawn/"}	
		{bone hide "visor_all"}
		{tags add "hold"}
		{tags add "machine"}
		{tags add "scout_base"}
		{set "engine_started" 0}
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
		{call "leds_update"}
		{call "led_ems_connect"}
		{call "led_light_connect"}
		{call "radio_connect"}
		{call "sound_connect"}
		{call "fire_connect"}
		{set "stop" 1}
		{delay 120 "idle_enter"
			{tags add "idle_enter"}
			{call "idle-enter"}
		}		
		{ik_enable "head_ik_h_damage" 0}
		{ik_enable "head_ik_v_damage" 0}
	}
	{on "radio_connect"
		{if not able "exploded"	
			{delay 5
				{if rand 0.2
					{play_sound "radio_var1" 1}
				else rand 0.2
					{play_sound "radio_var2" 1}
				else rand 0.2
					{play_sound "radio_var3" 1}
				else
					{play_sound "radio_var4" 1}
				}
			}
		}
	}
	{on "leds_update" 
		{kill_delay "hold_led"}		
		{delay 0.1
			(define "leds_ems"
				{if not tagged "die_battery"
					{if tagged "hold"
						{burn volume "visor_ems" fx "hold_burn" fake}
						{view start	"ems_global_hold"}
						{view show	"ems_global_hold"}
						{view hide	"ems_global_alarm"}
						{view pause	"ems_global_alarm"}
						{view hide	"ems_global_search"}
						{view pause	"ems_global_search"}
						{bone show "%vis_hold"}
						{bone hide "%vis_alarm"}
						{bone hide "%vis_search"}
					else tagged "search"
						{burn volume "visor_ems" fx "yellow_burn" fake}
						{view hide	"ems_global_alarm"}
						{view pause	"ems_global_alarm"}
						{view start	"ems_global_search"}
						{view show	"ems_global_search"}
						{view hide	"ems_global_hold"}
						{view pause	"ems_global_hold"}
						{bone hide "%vis_hold"}
						{bone hide "%vis_alarm"}
						{bone show "%vis_search"}
					else tagged "alarm"
						{burn volume "visor_ems" fx "red_burn" fake}
						{view start	"ems_global_alarm"}
						{view show	"ems_global_alarm"}
						{view hide	"ems_global_search"}
						{view pause	"ems_global_search"}
						{view hide	"ems_global_hold"}
						{view pause	"ems_global_hold"}
						{bone hide "%vis_hold"}
						{bone show "%vis_alarm"}
						{bone hide "%vis_search"}
					else tagged "off"
						{view hide	"ems_global_alarm"}
						{view pause	"ems_global_alarm"}
						{view hide	"ems_global_search"}
						{view pause	"ems_global_search"}
						{view hide	"ems_global_hold"}
						{view pause	"ems_global_hold"}
						{bone hide "%vis_hold"}
						{bone hide "%vis_alarm"}
						{bone hide "%vis_search"}
					}
					{delay 3
						{tags remove "off"}	
						{tags remove "hold"}	
						{tags remove "search"}	
						{tags remove "alarm"}	
					}
					{if tagged "alarm"
						{delay 12 "hold_led"
							{if not able "exploded"
								{tags add "search"}	
								{tags remove "alarm"}	
								{view hide	"ems_global_alarm"}
								{view pause	"ems_global_alarm"}
								{view start	"ems_global_search"}
								{view show	"ems_global_search"}
								{view hide	"ems_global_hold"}
								{view pause	"ems_global_hold"}
								{bone hide "%vis_alarm"}
								{bone show "%vis_search"}
							}
						}
						{delay 20 "hold_led"
							{if not able "exploded"
								{tags add "hold"}	
								{tags remove "search"}	
								{view start	"ems_global_hold"}
								{view show	"ems_global_hold"}
								{view hide	"ems_global_alarm"}
								{view pause	"ems_global_alarm"}
								{view hide	"ems_global_search"}
								{view pause	"ems_global_search"}
								{bone show "%vis_hold"}
								{bone hide "%vis_alarm"}
								{bone hide "%vis_search"}
							}
						}
					}
				}
			)
			("leds_ems"  vis(head_ems_00)  )
			("leds_ems"  vis(head_ems_01)  )
			("leds_ems"  vis(head_ems_02) )
			("leds_ems"  vis(head_ems_03) )
			("leds_ems"  vis(visor_led_01) )
			("leds_ems"  vis(visor_led_02) )
			("leds_ems"  vis(visor_led_03) )
			("leds_ems"  vis(head_light_ems_00) )
			("leds_ems"  vis(head_light_ems_01) )
			("leds_ems"  vis(head_light_ems_02) )
		}
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
			{bone hide	"light_ems"}
		)
		("leds_ems"  vis(head_ems_00)  )
		("leds_ems"  vis(head_ems_01)  )
		("leds_ems"  vis(head_ems_02) )
		("leds_ems"  vis(head_ems_03) )
		("leds_ems"  vis(head_ems_04) )
		("leds_ems"  vis(head_ems_05) )
		("leds_ems"  vis(head_ems_06) )
		("leds_ems"  vis(visor_led_01) )
		("leds_ems"  vis(visor_led_02) )
		("leds_ems"  vis(visor_led_03) )
		("leds_ems"  vis(head_light_ems_00) )
		("leds_ems"  vis(head_light_ems_01) )
		("leds_ems"  vis(head_light_ems_02) )
	}	
	{on ik begin "h_dr_signal"
		{call "slope_weapon_warning"}
		{tags add "search"}
		{tags remove "alarm"}
		{tags remove "hold"}
		{call "leds_update"}
		{if not tagged "combat_call"
			{tags add "combat_call"}
			{start_sound "generation_zero/characters/scout/ping/close/scout_sonar_ping_dir-LR"}	
			{start_sound "generation_zero/characters/scout/ping/far/scout_sonar_ping_bb"}	
		}
		{delay 2 {tags remove "combat_call"}}
	}
	{on ik begin "v_dr_signal"
		{call "slope_weapon_warning"}
		{tags add "search"}
		{tags remove "alarm"}
		{tags remove "hold"}
		{call "leds_update"}
		{if not tagged "combat_call"
			{tags add "combat_call"}
			{start_sound "generation_zero/characters/scout/ping/close/scout_sonar_ping_dir-LR"}	
			{start_sound "generation_zero/characters/scout/ping/far/scout_sonar_ping_bb"}	
		}
		{delay 2 {tags remove "combat_call"}}
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
		{if tagged "idle_enter"
			{if not tagged "power_drop"
				{if not able "exploded"
					{if rand 0.3 
						{call "land_idle"}
					else rand 0.2
						{call "scan_wide_loop"}
					}
				}
			}
		}
		{delay_effect 360 "idle-enter" }
	}	
	{on animation_end "hover_power_down"
		{start_sound "hit/generic/metal_weight/15/"}
		{ani_play "hover_power_down_ground" 0.3}
	}
	{on "power_drop" 
		;{kill_delay "power_drop"}
		{if not able "exploded"
			{delay 0.2 
				{if not tagged "power_drop"
					{view hide	"ems_global"}
					{view pause	"ems_global"}
					{view hide	"ems"}
					{view pause	"ems"}
					{call "stop_idle"}
					{ani_stop "hover" }
					{if not tagged "landed"
						{tags add "landed"}
						{ani_play "hover_power_down" 0.5 callback}
					}
					{view start "land_ground"}
					{tags add "power_drop"}
					{tags add "off"}
					{tags remove "hold"}
					{tags remove "alarm"}
					{tags remove "search"}
					{call "leds_update"}
					{burn volume "cpu" fx "smoke_preheat" time 5 fake even_law}	
					{start_sound "generation_zero/characters/explosion/robot_death_downer_medbot/close/"}
					{start_sound "generation_zero/characters/explosion/robot_death_downer_medbot/far/"}
					{delay 1.5
						{delay 0.5
							{burn volume "right_jetengine" fx "smoke_heat" time 2 fake even_law}	
							{burn volume "left_jetengine" fx "smoke_heat" time 2 fake even_law}	
							{delay 1
								{start_sound "generation_zero/characters/scout/rotor/end/emp_tick_shutdown_01"}
								{ani_stop "engine_work" 	}
								{ani_stop "engine_start" 	}
								{ani_play "engine_stop" 	}
								{stop_sound "radio_var1" }
								{stop_sound "radio_var2" }
								{stop_sound "radio_var3" }
								{stop_sound "radio_var4" }
								{stop_sound "engine_close" }
								{stop_sound "engine_dir" }
								{view pause "land_ground"}
								{with_linked_entity "right_jetengine"
									{call "close"}
								}
								{with_linked_entity "left_jetengine"
									{call "close"}
								}
								{view stop	"jetengine_r"}
								{view hide	"jetengine_r"}		
								{view stop	"jetengine_l"}
								{view hide	"jetengine_l"}
								{view stop	"jetengine_damage_r"}
								{view hide	"jetengine_damage_r"}		
								{view stop	"jetengine_damage_l"}
								{view hide	"jetengine_damage_l"}
							}
						}
					}
					{delay 12 6 "power_drop"
						{if not able "exploded"
							{ani_play "idle_to_lure" }							
							{tags remove "power_drop"}
							{call "take_off"}
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
	{on "scan_wide_loop"
		{if tagged "idle_enter"		
			{ani_stop "hover" }
			{ani_play "scan_wide_loop" callback}
			{delay 7 3
				;{ani_stop "scan_wide_loop" }
				{tags remove "idle_enter"}
			}			
		}
	}
	{on animation_end "scan_wide_loop"
		{if not tagged "idle_enter"		
			{if not able "exploded"				
				{ani_play "hover" loop}
			}			
		}	
	}	
	{on "land_idle"
		;{if not tagged "landed_idle"
			{if not tagged "mgun_alarm_hold"
				{if not able "exploded"
					{if not tagged "move"
						{tags add "landed_idle"}
						{delay 1
							{tags remove "flying"}
							{call "land_idle_ems"}
							{movement_limit slow}
							{ani_play "landing" 0.6}
							{view start "land_ground"}
						}
						{delay 5 "idle_land"
							{ani_play "idle_ground_loop" +1 resume loop}
						}
						{delay 15 "idle_land"
							{ani_stop "idle_ground_loop" }
							{ani_play "idle_ground_loop" -1 resume }
						}
						{delay 30 "idle_land"
							{if not able "exploded"
								{ani_play "engine_start" callback}
								{delay 2 "idle_land"
									{kill_delay "land_idle_ems"}
									{call "take_off"}
								}
							}
						}			
					}
				}
			}
		;}	
	}
	{on "land_idle_ems" 
		{bone hide "orange_ems"}
		{delay 0.5
			{bone show "orange_ems"}
		}
		{delay_effect 1 "land_idle_ems" }
	}	
	
	
	
	{on fire "alarm_signal"   
		{kill_delay "land_idle_ems"}
		{call "take_off"}
		{kill_delay "hold"}
		{signal shot 5000}
		{tags add "mgun_alarm_horn"}
		{tags add "mgun_alarm_hold"}
		{tags add "call_allies"}
		{delay 360 "hold"
			{tags remove "mgun_alarm_hold"}
		}
		{delay 5
			{tags remove "mgun_alarm_horn"}
			{tags remove "call_allies"}
		}
		{bone hide "visor_all"}
		{tags add "alarm"}
		{tags remove "hold"}
		{tags remove "search"}
		{call "leds_update"}
		{start_sound "generation_zero/characters/scout/horn/close/scout_detect_alarm_horn_01_dir"}	
		{start_sound "generation_zero/characters/scout/horn/far/scout_detect_alarm_horn_01_verb"}	
	}
	{on fire "head_joint" ;head_joint
		{tags add "head_joint"}
		{delay 1
			{tags remove "head_joint"}
		}
	}
	{on fire "slope_move"  ;slope
		{call "slope_weapon_warning"}
		{tags add "slope"}
		{delay 1
			{tags remove "slope"}
		}
	}
	{on "reload" overload ;scout
		{if tagged "mgun_alarm"
			{if work "mgun_alarm"
				{weapon_work "alarm_signal" 0}
				{delay 4
					{if work "mgun"
						{tags remove "mgun_alarm"}
						{weapon_work "alarm_signal" 1}
					}
				}
			}
		else tagged "slope"
			{if work "slope"
				{tags add "slope"}
				{weapon_work "slope_move" 0}
				{delay 1
					{if work "slope"
						{tags remove "slope"}
						{weapon_work "slope_move" 1}
					}
				}
			}
		else tagged "head_joint"
			{if work "head_joint"
				{tags add "head_joint"}
				;{weapon_work "head_joint" 0}
				{delay 1
					{if work "head_joint"
						{tags remove "head_joint"}
						;{weapon_work "head_joint" 1}
					}
				}
			}
		}
	}
	{on "power_up" ; scout
		{if not able "exploded"
			;{burn volume "" fx "yellow_burn" fake}
			;{view show	"ems_global"}
			;{view start	"ems_global"}		
			{view show	"ems"}
			{view start	"ems"}
			{tags add "hold"}
			{call "leds_update"}
			{play_sound "engine_close" 1}
			{play_sound "engine_dir" 1}
			{call "take_off_load"}
			{call "ping_scout"}
			{call "talk_scout"}
			{ani_play "engine_start" callback}
		}
	}
	{on "power_drop_permanent"
		;{kill_delay "power_drop"}
		{if not able "exploded"
			{delay 0.2 
				{if not tagged "power_drop"
					{delay 1.5 
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
					{call "leds_update"}
					{call "sparks_loop"}
					{burn volume "cpu" fx "smoke_preheat" time 5 fake even_law}	
					{ani_play "power_down"}
					{call "gun_block"}
					{delay 5
						{tags remove "wire_burn"}				
					}
				}
			}
		}
	}
	{on animation_end "engine_start"
		{if not able "exploded"
			{ani_play "engine_work" loop}
		}
	}	
	{on "take_off_load" 
		{if not tagged "break_jetengine"
			{movement_limit fast}
			{ani_play "take_off"  }			
			{delay 0.1
				{tags remove "landed"}
				{view pause "land_ground"}
				{tags remove "landed_idle"}
				{if not tagged "break_jetengine_r"
					{spawn "scout_jetengine_start" "right_jetengine_fx" x}
					{view show	"jetengine_r"}
					{view start	"jetengine_r"}		
					{with_linked_entity "right_jetengine"
						{call "open"}
					}
				}
				{if not tagged "break_jetengine_l"
					{spawn "scout_jetengine_start" "left_jetengine_fx" x}
					{view show	"jetengine_l"}
					{view start	"jetengine_l"}		
					{with_linked_entity "left_jetengine"
						{call "open"}
					}
				}
			}
		}
	}
	{on "take_off" 
		{if not tagged "flying"
			{if not tagged "break_jetengine"
				{movement_limit fast}
				{ani_play "take_off"  }			
				{delay 0.1
					{tags remove "landed"}
					{view pause "land_ground"}
					{tags remove "landed_idle"}
					{if not tagged "break_jetengine_r"
						{spawn "scout_jetengine_start" "right_jetengine_fx" x}
						{view show	"jetengine_r"}
						{view start	"jetengine_r"}		
						{with_linked_entity "right_jetengine"
							{call "open"}
						}
					}
					{if not tagged "break_jetengine_l"
						{spawn "scout_jetengine_start" "left_jetengine_fx" x}
						{view show	"jetengine_l"}
						{view start	"jetengine_l"}		
						{with_linked_entity "left_jetengine"
							{call "open"}
						}
					}
				}
			}
		}
	}
	{on animation_event "take_off_land" ; отрыв от земли
	
	}
	{on animation_event "hover" ; конец взлёта
		{if not tagged "break_jetengine"
			{ani_play "hover" +1 resume loop }
			{tags add "flying"}
		}
	}
	{on "land_ground"
		{delay 0.3
			{tags remove "flying"}
			{if not tagged "landed_idle"
				{if not able "exploded"		
					{if tagged "break_jetengine_l"
						{if tagged "break_jetengine_r"
							{chassis_work 0}
							{if rand 0.5
								{spawn "electric_spark_hit_pierce" "left_jetengine_fx" }
							else rand 0.3
								{spawn "electric_spark_hit_pierce" "right_jetengine_fx" }
							}
							{tags add "landed"}
							{ani_stop "hover" }
							{ani_stop "engine_work" 	}
							{ani_stop "engine_start" 	}
							{ani_play "engine_stop" 	}
							{ani_play "hover_power_down" 0.5}
							{view start "land_ground"}
							{delay 1.5
								{ani_play "hover_power_down_ground" 0.3}
								{delay 0.5
									{start_sound "hit/generic/metal_weight/15/"}
									{burn volume "right_jetengine" fx "smoke_heat" time 2 fake even_law}	
									{burn volume "left_jetengine" fx "smoke_heat" time 2 fake even_law}	
									{delay 1
										{ani_stop "engine_work" 	}
										{stop_sound "radio_var1" }
										{stop_sound "radio_var2" }
										{stop_sound "radio_var3" }
										{stop_sound "radio_var4" }
										{start_sound "generation_zero/characters/explosion/robot_death_downer_medbot/close/"}
										{start_sound "generation_zero/characters/explosion/robot_death_downer_medbot/far/"}
										{stop_sound "engine_close" }
										{stop_sound "engine_dir" }
										{with_linked_entity "right_jetengine"
											{call "close"}
										}
										{with_linked_entity "left_jetengine"
											{call "close"}
										}
										{view stop	"jetengine_r"}
										{view hide	"jetengine_r"}		
										{view stop	"jetengine_l"}
										{view hide	"jetengine_l"}
										{view stop	"jetengine_damage_r"}
										{view hide	"jetengine_damage_r"}		
										{view stop	"jetengine_damage_l"}
										{view hide	"jetengine_damage_l"}
										{if work "horn"
											{if rand 0.5 ; horn
												{tags add "alarm"}
												{tags remove "hold"}
												{tags remove "search"}
												{call "leds_update"}
												{start_sound "generation_zero/characters/scout/horn/close/scout_detect_alarm_horn_01_dir"}	
												{start_sound "generation_zero/characters/scout/horn/far/scout_detect_alarm_horn_01_verb"}	
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	{on animation_event "slope_left_start" 
		{tags add "slope"}
		{tags add "slope_left"}
		{ani_stop "hover" }
		;{chassis_work 0}
		{if rand 0.2
			{spawn "scout_jetengine_start" "left_jetengine_fx" x}
		else rand 0.2
			{spawn "scout_jetengine_start" "left_jetengine_fx" x}
		}
	}
	{on animation_event "slope_left_end" 
		{tags remove "slope"}
		{if not tagged "break_jetengine"
			{ani_play "hover" loop }
		}
		;{chassis_work 1}
		{delay 0.5 
			{tags remove "slope_left"}
		}
	}
	{on animation_event "slope_right_start" 
		{tags add "slope"}
		{tags add "slope_right"}
		{ani_stop "hover" }
		;{chassis_work 0}
		{if rand 0.2
			{spawn "scout_jetengine_start" "right_jetengine_fx" x}
		else rand 0.2
			{spawn "scout_jetengine_start" "left_jetengine_fx" x}
		}
	}
	{on animation_event "slope_right_end" 
		{tags remove "slope"}
		{if not tagged "break_jetengine"
			{ani_play "hover" loop }
		}
		;{chassis_work 1}
		{delay 0.5 
			{tags remove "slope_right"}
		}
	}
	{on animation_event "slope_right_reward_start" 
		{tags add "slope"}
		{tags add "slope_left"}
		{ani_stop "hover" }
		;{chassis_work 0}
		{if rand 0.2
			{spawn "scout_jetengine_start" "right_jetengine_fx" x}
		else rand 0.2
			{spawn "scout_jetengine_start" "left_jetengine_fx" x}
		}
	}
	{on animation_event "slope_right_reward_end" 
		{tags remove "slope"}
		{if not tagged "break_jetengine"
			{ani_play "hover" loop }
		}
		;{chassis_work 1}
		{delay 0.5 
			{tags remove "slope_left"}
		}
	}
	{on "slope_weapon_warning"
		{if not able "exploded"		
			{call "stop_idle"}
			 {if not tagged "alarm"
				 {if tagged "alarm"
					{if tagged "flying"
						{if not tagged "break_jetengine_l"
							{if not tagged "break_jetengine_r"
								{if not tagged "slope"
									{if rand 0.5
										{if not tagged "slope_left"
											{ani_play "slope_left" 2}
											{ani_stop "slope_right" }
										}
									else
										{if not tagged "slope_right"
											{ani_play "slope_right" 2}
											{ani_stop "slope_left" }
										}
									}
								}
							}
						}		
					}		
				}		
			}
		}		
	}
	; {on "lose_health"
		; {ani_play "health" +3 resume}
		; {kill_delay "health"}
		; {delay 0.2 "health"
			; {ani_stop "health"}
		; }
	; }
	{on break ; all
		{if component "main_body"
			{call "break_body"}
		else component "arm_tear" ;all tag leg
			{burn volume fx "electric_spark_hit_pierce" time 0.8 fake}			
			{burn volume fx "smoke_destroy" time 0.3 fake}			
		else component "fuel" ;all
			{call "lose_health"}
			{start_sound "detonation/fireextinguisher/FX_Explosion_FireExtinguisherVapor_02"}	
			;{burn volume "fuel" fx "smoke_gas_trit_burn" time 7 fake}	
			{stop_sound "engine" }
			{delay 8
				{movement_limit normal}
			}
			{delay 14.5
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
		else component "jetengine_l" ;scout
			{if not able "exploded"		
				{if not tagged "landed_idle"
					{call "land_ground"} ;hover_power_down
					{if rand 0.5
						{ani_play "hit_stumble_45ccw" resume}
					else
						{ani_play "hit_stumble_45cw" resume}
					}
				}
			}
			{spawn "electric_spark_hit_pierce" "leftPropeller_sm" }
			{movement_limit slow}
			{tags add "break_jetengine"}
			{tags add "break_jetengine_l"}
			{spawn "scout_jetengine_break" "leftPropeller_sm"}	;искры поломки
			{spawn "trace_linear_big" "leftPropeller_sm" x}		;искры поломки			
			(define "break"
				{if rand 0.7
					{tear "piece_small_micro" bone %0
						{impulse forward 2 0.5 cx 4 1 cy 4 1 }
					}
				}
			)
			("break" args "left_jetengine_armor_1")
			("break" args "left_jetengine_armor_2")
			("break" args "left_jetengine_armor_3")
			("break" args "left_jetengine_armor_4")
			("break" args "left_jetengine_armor_5")
			("break" args "left_jetengine_armor_6")
		else component "jetengine_r" ;scout
			{if not able "exploded"		
				{if not tagged "landed_idle"
					{call "land_ground"} ;hover_power_down
					{if rand 0.5
						{ani_play "hit_stumble_45ccw" resume}
					else
						{ani_play "hit_stumble_45cw" resume}
					}
				}
			}
			{movement_limit slow}
			{tags add "break_jetengine"}
			{tags add "break_jetengine_r"}
			{spawn "electric_spark_hit_pierce" "RightPropeller_sm" }
			{spawn "scout_jetengine_break" "RightPropeller_sm"}	;искры поломки
			{spawn "trace_linear_big" "RightPropeller_sm" x}		;искры поломки			
			(define "jetengine_r"
				{if rand 0.5
					{tear "piece_small_micro" bone %0
						{impulse forward 2 0.5 cx 4 1 cy 4 1 }
					}
				}
			)
			("break" args "right_jetengine_armor_1")
			("break" args "right_jetengine_armor_2")
			("break" args "right_jetengine_armor_3")
			("break" args "right_jetengine_armor_4")
			("break" args "right_jetengine_armor_5")
			("break" args "right_jetengine_armor_6")
		else component "head" ;all
			{call "lose_health"}
			{start_sound "generation_zero/electric_spark/"}	
			{burn volume "head_organ" fx "electric_spark_hit" time 0.4 fake}	
			{if rand 0.5
				{call "power_drop"}
			}
		else component "main_body" ;all
			{burn volume "body_organ" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "body_organ"}
			{if rand 0.5
				{call "power_drop"}
			}
			{call "lose_health"}
			{start_sound "generation_zero/electric_spark/"}	
			{burn volume "body_organ" fx "electric_spark_hit" time 0.4 fake}	
		else component "head_organ"
			{call "lose_health"}
			{burn volume "head_organ" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "head_organ"}
			{call "power_drop"}
		else component "neck"
			{call "lose_health"}
			{spawn "electric_spark_break" "neck"}
		else component "neck1"
			{call "lose_health"}
			{spawn "electric_spark_break" "neck1"}
		else component "horn"
			{burn volume "horn" fx "smoke_heat" time 25 fake}			
			{call "lose_health"}
			{spawn "electric_spark_break" "horn"}
		else component "engine"
			{call "lose_health"}
			{spawn "electric_spark_break" "propeller"}
		else component "organ_neck"
			{call "lose_health"}
			{spawn "electric_spark_break" "neck"}
		else component "back_engine_organ"
			{call "lose_health"}
			{spawn "electric_spark_break" "organ_motor"}
		else component "organ_cannister"
			{movement_limit slow}
			{call "lose_health"}
			{spawn "electric_spark_break" "fuel"}
		}
	}
	{on destroy ; all
		{if component "main_body"
			{ani_stop "engine_work"}
			{bone hide	"orange_ems"}
			{bone hide	"red_ems"}
		}
		{if component "jetengine_r"
			{call "lose_health"}
			{burn volume "right_jetengine" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "right_jetengine"}
		else component "jetengine_l"
			{call "lose_health"}
			{burn volume "left_jetengine" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "left_jetengine"}
		else component "fuel"
			{call "lose_health"}
			{spawn "break_small_body_robot" "fuel"}	;break fx
			{if rand 0.2
				{fire volume "fuel" radius 0.1 heating 0.5  time 5 follow}
			}
			{burn volume "fuel" fx "smoke_heat" time 10 fake}
			{burn volume "fuel" fx "burn_component_break_small" time 3 fake}
		else component "head_organ"
			{call "lose_health"}
			{burn volume "head_organ" fx "smoke_heat" time 60 fake}
			{spawn "electric_spark_break" "head_organ"}
			{call "power_drop"}
		else component "neck"
			{call "lose_health"}
			{spawn "electric_spark_break" "neck"}
		else component "neck1"
			{call "lose_health"}
			{spawn "electric_spark_break" "neck1"}
		else component "horn"
			{stop_sound "radio_var1" }
			{stop_sound "radio_var2" }
			{stop_sound "radio_var3" }
			{stop_sound "radio_var4" }
			{kill_delay "ping_scout"}
			{call "lose_health"}
			{spawn "electric_spark_break" "horn"}
			{weapon_work "alarm_signal" 0}
			(define "break_horn"
				{tear "piece_small_steel" bone %0
					{impulse forward 2 1 cx 1 0.5 cy 1 0.5 rnd_dir 1 0.5 no_position}
				}
			)
			("break_horn" args "horn_part1" )
			("break_horn" args "horn_part2" )
			("break_horn" args "horn_part3" )
			("break_horn" args "horn_part4" )
		else component "engine"
			{call "lose_health"}
			{spawn "electric_spark_break" "propeller"}
		else component "organ_neck"
			{call "lose_health"}
			{spawn "electric_spark_break" "neck"}
		else component "back_engine_organ"
			{call "lose_health"}
			{spawn "electric_spark_break" "organ_motor"}
		else component "organ_cannister"
			{call "lose_health"}
			{spawn "electric_spark_break" "fuel"}
		}
	}
	{on blast ;scout
		(include "blast_all.inc")
		("orientation" vol(front_left_hit)  	ani_play(hit_stumble_45ccw)   rand(0.8)  min_energy(0.5) )
		("orientation" vol(front_right_hit)  	ani_play(hit_stumble_45cw)    rand(0.8)  min_energy(0.5) )
		("orientation" vol(back_left_hit)  		ani_play(hit_stumble_135cw)   rand(0.8)  min_energy(0.5) )
		("orientation" vol(back_right_hit)  	ani_play(hit_stumble_135ccw)  rand(0.8)  min_energy(0.5) )
		{if min_energy 4
			{if not tagged "flying"
				{call "explosion_scout_ground"}
			else
				{call "explosion_scout"}
			}
		else min_energy 2
			{if stuff "rocketlauncher"
				{if rand 0.4
					{if not tagged "flying"
						{call "explosion_scout_ground"}
					else
						{call "explosion_scout"}
					}
				}
			}
			{if volume "head_organ" 
				{spawn "electric_spark_hit_pierce" "head_organ"}
				{if rand 0.8
					{burn volume "head_organ" fx "smoke_heat" time 5 1 fake even_law}
					{call "power_drop"}
				}
			else volume "head_arm" 
				{spawn "electric_spark_hit_pierce" "Head_ik_h_damage"}
				{if rand 0.5
					{components "head_arm" break}
				}			
			else volume "jetengine_l" 
				{components "jetengine_l" break}			
			else volume "jetengine_r" 
				{components "jetengine_r" break}			
			else volume "horn" 
				{components "horn" break}			
			else volume "body" 
				{components "body" break}			
			else volume "engine" 
				{components "engine" break}			
			else volume "fuel" 
				{components "fuel" break}			
			}		
		}
	}
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
	{on bullet_hit
		{delay 0.5 {call "take_off"}}
		
		{kill_delay "idle_land"}
		{if tagged "move"
			{call "drop_speed"}
		}		
		{if tagged "idle_enter"
			{tags remove "idle_enter"}
			{call "stop_idle"}
		}
		{if not tagged "landed"
			("orientation_hit" vol(armorplate_front_left)  		ani_play(hit_stumble_45ccw)	 	speed(0.5)  rand(0.8)  )
			("orientation_hit" vol(armorplate_front_right)  	ani_play(hit_stumble_135ccw)   	speed(0.5)  rand(0.8)  )
			("orientation_hit" vol(armorplate_back_left)  		ani_play(hit_stumble_45cw)  	speed(0.5)  rand(0.8)  )
			("orientation_hit" vol(armorplate_back_right)  		ani_play(hit_stumble_135cw) 	speed(0.5)  rand(0.8)  )
		}
	}
	{on pierce ;scout_pierce
		{signal shot 2500}
		{call "stop_idle"}
		(define "hit_system_organ"		
			{if volume "organ"
				{if stuff %0
					{if rand %1
						{if not tagged "flying"
							{call "explosion_scout_ground"}
						else
							{call "explosion_scout"}
						}
					}
				}
			}
		)	
;								tags (0) 		rand (1)	 
		("hit_system_organ" args "rocketlauncher"		1 		)
		("hit_system_organ" args "shell"				1 		)
		("hit_system_organ" args "zenite cs"			0.6  		)
		("hit_system_organ" args "zenite"				0.6  		)
		("hit_system_organ" args "sniper"				0.6  		)
		("hit_system_organ" args "bullet big ap"		0.2  		)
		("hit_system_organ" args "bullet big"			0.1  		)
		("hit_system_organ" args "bullet normal ap"		0.05  		)
		("hit_system_organ" args "bullet normal"		0.02 		)
		("hit_system_organ" args "bullet small"			0.01  		)
		("hit_system_organ" args "bullet"				0.01  		)
		{if volume "main_body"
			{if rand 0.1
				{if not tagged "flying"
					{call "explosion_scout_ground"}
				else
					{call "explosion_scout"}
				}
			}
		}
	(include "pierce_all.inc")
	}
	(include "burn_volume.inc")
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
	
	; (define "speed"
		; {on animation_event "%tagged_speed"
			; {if tagged "%tagged_speed"	
				; {ani_stop "speed_full" }
			; }
		; }
	; )
	; ;                      
	; ("speed" tagged_speed(0_speed) )
	; ("speed" tagged_speed(1_speed) )
	; ("speed" tagged_speed(2_speed) )
	; ("speed" tagged_speed(3_speed) )
	; ("speed" tagged_speed(4_speed) )
	; ("speed" tagged_speed(5_speed) )
	; ("speed" tagged_speed(6_speed) )
	; ("speed" tagged_speed(7_speed) )
	; ("speed" tagged_speed(8_speed) )
	; ("speed" tagged_speed(9_speed) )
	{on move on ;scout
		{kill_delay "move_stop"}
		{call "stop_idle"}
		{tags add "move"}	
		{set "blocked" 1}
		{if not tagged "turn"
			{if Move_Forward
				{tags add "move_forward"}
			}
		}
	}
	{on "ping_scout"
		{if not able "exploded"	
			{if rand 0.5
				{start_sound "generation_zero/characters/scout/ping/close/scout_sonar_ping_dir-LR"}
				{start_sound "generation_zero/characters/scout/ping/far/scout_sonar_ping_bb"}
				{spawn "ping_scout" "horn"}
			}
		}
		{delay_effect 4 2 "ping_scout"}	
	}
	{on "talk_scout"
		{if not able "exploded"	
			{if tagged "move_forward"
				{if rand 0.2
					{start_sound "generation_zero/characters/scout/talk/close/scout_talk_2ch_01-LR"}
					{start_sound "generation_zero/characters/scout/talk/far/scout_talk_bb_01"}
				else rand 0.2
					{start_sound "generation_zero/characters/scout/talk/close/scout_talk_2ch_02-LR"}
					{start_sound "generation_zero/characters/scout/talk/far/scout_talk_bb_02"}
				else rand 0.2
					{start_sound "generation_zero/characters/scout/talk/close/scout_talk_2ch_03-LR"}
					{start_sound "generation_zero/characters/scout/talk/far/scout_talk_bb_03"}
				else rand 0.2
					{start_sound "generation_zero/characters/scout/talk/close/scout_talk_2ch_04-LR"}
					{start_sound "generation_zero/characters/scout/talk/far/scout_talk_bb_04"}
				else
					{start_sound "generation_zero/characters/scout/talk/close/scout_talk_2ch_05-LR"}
					{start_sound "generation_zero/characters/scout/talk/far/scout_talk_bb_05"}
				}
			}
		}
		{delay_effect 14 8 "talk_scout"}	
	}


	{on "break_body" 
		{delay 5 2
			{if not tagged "break_jetengine_l"
				{if not tagged "break_jetengine_r"
					{call "land_ground"} ;hover_power_down
				}
			}
		}
		{spawn "break_small_body_robot" "body"}
		{burn volume "body" fx "smoke_heat" time 5 fake even_law}					
		{movement_limit slow}
		(define "blast_scout"
			{if rand %1
				{tear "piece_small_steel" bone %0
					{impulse forward 2 1 cx 1 0.5 cy 1 0.5 rnd_dir 1 0.5 no_position}
				}
			}
		)
		("blast_scout" args "armorplate_front_right" 		0.7)
		("blast_scout" args "armorplate_front_left" 		0.7)
		("blast_scout" args "armorplate_back_right" 		0.7)
		("blast_scout" args "armorplate_back_left" 			0.7)
		("blast_scout" args "right_armplate" 		0.7)
		("blast_scout" args "left_armplate" 		0.7)
		;("blast_scout" args "horn_part1" 		0.6)
		;("blast_scout" args "horn_part2" 		0.6)
		;("blast_scout" args "horn_part3" 		0.6)
		;("blast_scout" args "horn_part4" 		0.6)
	}


	{on "explosion_scout" 
		{if not able "exploded"		
			{delay_ex 0.1
				{set_skeleton "_x" sync}
				{impulse up 0.1}
			}
			{start_sound "generation_zero/characters/explosion/robot_death_downer_medbot/close"}
			{start_sound "generation_zero/characters/explosion/robot_death_downer_medbot/far"}
			{tags remove "alarm"}
			{tags remove "hold"}
			{tags remove "search"}
			{tags add "off"}
			{tags add "dead"}
			{able "exploded" 1}
			{ani_stop "hover"}
			{spawn "break_small_body_robot" "body"}
			{if not tagged "landed"
				{ani_play "death_01"}
			}			
			{stop_sound "engine" }
			{burn volume "body" fx "smoke_heat" time 5 fake even_law}					
			{kill_delay "idle"}
			{kill_delay "ping_scout"}
			{kill_delay "talk_scout"}
			{drop_orders}
			{components destroy}
			{reset_manual_control}
			{auto_operatable 0}
			{able select 0}
			{able repaired 0}
			{call "leds_update"}
			{call "stop_all"}
			{mtl_enable_skin 0}
			{bone hide "wire"}
			{bone hide "wire_body"}
			{bone hide "RightLeg_wire"}
			{bone hide "LeftLeg_wire"}
			{bone hide "CentralLeg_wire"}
			{view pause "land_ground"}
			(define "blast_scout"
				{if rand %1
					{tear "piece_small_steel" bone %0
						{impulse up 0.5 dir 1 0.5 cx 1 0.5 cy 1 0.5 rnd_dir 1 0.5 no_position}
					}
				}
			)
			("blast_scout" args "armorplate_front_right" 		0.7)
			("blast_scout" args "armorplate_front_left" 		0.7)
			("blast_scout" args "armorplate_back_right" 		0.7)
			("blast_scout" args "armorplate_back_left" 			0.7)
			("blast_scout" args "right_armplate" 		0.7)
			("blast_scout" args "left_armplate" 		0.7)
		}
	}
	{on "explosion_scout_ground" 
		{if not "crush"	
			{delay_ex 0.1
				{set_skeleton "_x" sync}
				{impulse up 0.2 cx 2 1 cy 2 1 rnd_dir 0.5 no_position}		
			}
			{able "exploded" 1}
			{set "crush" 1}
			{start_sound "generation_zero/characters/explosion/damage_startcrsh_medium"}
			{ani_stop "death_01"}
			{ani_stop "engine_work"}
			{spawn "break_small_body_robot" "body"}
			{mtl_enable_skin 0}
			{components destroy}
			{reset_manual_control}
			{auto_operatable 0}
			{able select 0}
			{able repaired 0}
			{bone hide "wire"}
			{bone hide "wire_body"}
			{bone hide "RightLeg_wire"}
			{bone hide "LeftLeg_wire"}
			{bone hide "CentralLeg_wire"}
			{stop_sound "engine_close" }
			{stop_sound "engine_dir" }
			{view pause "land_ground"}
			{with_linked_entity "right_jetengine"
				{call "close"}
			}
			{with_linked_entity "left_jetengine"
				{call "close"}
			}
			{view stop	"jetengine_r"}
			{view hide	"jetengine_r"}		
			{view stop	"jetengine_l"}
			{view hide	"jetengine_l"}
			(define "blast_scout"
				{if rand %1
					{tear "piece_small_steel" bone %0
						{impulse up 0.5 dir 1 0.5 cx 1 0.5 cy 1 0.5 rnd_dir 1 0.5 no_position}
					}
				}
			)
			("blast_scout" args "armorplate_front_right" 		0.7)
			("blast_scout" args "armorplate_front_left" 		0.7)
			("blast_scout" args "armorplate_back_right" 		0.7)
			("blast_scout" args "armorplate_back_left" 			0.7)
			("blast_scout" args "right_armplate" 		0.7)
			("blast_scout" args "left_armplate" 		0.7)
			("blast_scout" args "right_jetengine" 		0.4)
			("blast_scout" args "left_jetengine" 		0.4)
			("blast_scout" args "Propeller" 		0.4)
			("blast_scout" args "LeftUpperLeg" 		0.2)
			("blast_scout" args "leftLeg" 			0.4)
			("blast_scout" args "leftFoot" 			0.7)
			("blast_scout" args "leftToeBase" 		0.9)
			("blast_scout" args "rightUpperLeg" 		0.2)
			("blast_scout" args "rightLeg" 			0.4)
			("blast_scout" args "rightFoot" 			0.7)
			("blast_scout" args "rightToeBase" 		0.9)
			("blast_scout" args "centralUpperLeg" 		0.2)
			("blast_scout" args "centralLeg" 			0.4)
			("blast_scout" args "centralFoot" 			0.7)
			("blast_scout" args "centralToeBase" 		0.9)			
			("blast_scout" args "horn_part1" 		0.6)
			("blast_scout" args "horn_part2" 		0.6)
			("blast_scout" args "horn_part3" 		0.6)
			("blast_scout" args "horn_part4" 		0.6)
			("blast_scout" args "horn" 		0.3)
		}
	}
	{on ground_hit
		{if able "exploded"		
			{if not tagged "landed_blast"
				{start_sound "generation_zero/characters/explosion/damage_startcrsh_medium"}
				{tags add "landed_blast"}
				{ani_stop "death_01"}
				{ani_stop "engine_work"}
				{spawn "break_small_body_robot" "body"}
				{mtl_enable_skin 0}
				{components destroy}
				{reset_manual_control}
				{auto_operatable 0}
				{able select 0}
				{able repaired 0}
				{bone hide "wire"}
				{bone hide "wire_body"}
				{bone hide "RightLeg_wire"}
				{bone hide "LeftLeg_wire"}
				{bone hide "CentralLeg_wire"}
				{stop_sound "engine_close" }
				{stop_sound "engine_dir" }
				{with_linked_entity "right_jetengine"
					{call "close"}
				}
				{with_linked_entity "left_jetengine"
					{call "close"}
				}
				{view stop	"jetengine_r"}
				{view hide	"jetengine_r"}		
				{view stop	"jetengine_l"}
				{view hide	"jetengine_l"}
				{view start "destroy_fx"}
				{delay 120 60
					{view hide "destroy_fx"}
				}
				(define "blast_scout"
					{if rand %1
						{tear "piece_small_steel" bone %0
							{impulse up 0.5 dir 1 0.5 cx 1 0.5 cy 1 0.5 rnd_dir 1 0.5 no_position}
						}
					}
				)
				("blast_scout" args "armorplate_front_right" 		0.7)
				("blast_scout" args "armorplate_front_left" 		0.7)
				("blast_scout" args "armorplate_back_right" 		0.7)
				("blast_scout" args "armorplate_back_left" 			0.7)
				("blast_scout" args "right_armplate" 		0.7)
				("blast_scout" args "left_armplate" 		0.7)
				("blast_scout" args "right_jetengine" 		0.4)
				("blast_scout" args "left_jetengine" 		0.4)
				("blast_scout" args "Propeller" 		0.4)
				("blast_scout" args "LeftUpperLeg" 		0.2)
				("blast_scout" args "leftLeg" 			0.4)
				("blast_scout" args "leftFoot" 			0.7)
				("blast_scout" args "leftToeBase" 		0.9)
				("blast_scout" args "rightUpperLeg" 		0.2)
				("blast_scout" args "rightLeg" 			0.4)
				("blast_scout" args "rightFoot" 			0.7)
				("blast_scout" args "rightToeBase" 		0.9)
				("blast_scout" args "centralUpperLeg" 		0.2)
				("blast_scout" args "centralLeg" 			0.4)
				("blast_scout" args "centralFoot" 			0.7)
				("blast_scout" args "centralToeBase" 		0.9)			
				("blast_scout" args "horn_part1" 		0.6)
				("blast_scout" args "horn_part2" 		0.6)
				("blast_scout" args "horn_part3" 		0.6)
				("blast_scout" args "horn_part4" 		0.6)
				("blast_scout" args "horn" 		0.3)
				
				
			}
		}
	}


	{on "velocity_update"
		{if velocity 8
			{if not tagged "8_speed"
				{tags add "8_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "8_speed" 	+1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 7
			{if not tagged "7_speed"
				{tags add "7_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "8_speed" 	-1)
				;("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 6
			{if not tagged "6_speed"
				{tags add "6_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				;("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 5
			{if not tagged "5_speed"
				{tags add "5_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				;("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 4
			{if not tagged "4_speed"
				{tags add "4_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				;("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 3
			{if not tagged "3_speed"
				{tags add "3_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				("speed" args "4_speed" 	-1)
				;("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 3
			{if not tagged "3_speed"
				{tags add "3_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				("speed" args "4_speed" 	-1)
				;("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 2
			{if not tagged "2_speed"
				{tags add "2_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				("speed" args "4_speed" 	-1)
				("speed" args "3_speed" 	-1)
				;("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 1
			{if not tagged "1_speed"
				{tags add "1_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				("speed" args "4_speed" 	-1)
				("speed" args "3_speed" 	-1)
				("speed" args "2_speed" 	-1)
				;("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 0
			{if not tagged "0_speed"
				{tags add "0_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				("speed" args "4_speed" 	-1)
				("speed" args "3_speed" 	-1)
				("speed" args "2_speed" 	-1)
				("speed" args "1_speed" 	-1)
				;("speed" args "0_speed" 	+1)
			}
		}
	}
	{on "move_update_scout" ;not use
		{if not tagged "turn"
			(define "move_update"
				{if velocity %speed				
					{if tagged "move_forward"
						{ani_play "move_forward_%degre" +0.1 resume}
					}
				else
					{ani_play "move_forward_10" -1 resume}
				}
			)		
			("move_update" speed(8)	 degre(80)	)
			("move_update" speed(7)	 degre(70) 	)
			("move_update" speed(6)	 degre(60) 	)
			("move_update" speed(5)	 degre(50) 	)
			("move_update" speed(4)	 degre(40) 	)
			("move_update" speed(3)	 degre(30) 	)
			("move_update" speed(2)	 degre(20)  	)
			("move_update" speed(1)	 degre(10)  	)
		}	
	}	
	{on brake on
		{if velocity 2
			{ani_play "move_forward" -1 resume }
		else
			{ani_play "move_forward" -0.5 resume }
		}	
	}			
	{on move off ; scout
		;{ani_play "move_end" 0.2 resume }
		{call "stop_idle"}
		{delay 0.5
			{if not tagged "move"
				{if not tagged "turn"
					{call "stop_all_ani"}
				}
			}
		}
		;{call "idle_start"}
		;{kill_delay "move_stop"}
		{tags remove "move_forward"}	
		{tags remove "move_backward"}	
		{tags remove "move"}	
		{tags remove "turn"}
		{tags remove "run"}
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
	{on turn on overload
		{set "blocked" 1}
		{kill_delay "move_stop"}
		{call "stop_idle"}
		{tags add "turn"}
		{if Turn_Left
			{tags add "Turn_Left"}	
			{ani_play "turn_left" +1 resume }
		else Turn_Right
			{tags add "Turn_Right"}	
			{ani_play "turn_right" +1 resume }
		}
	}
	{on turn off overload ; scout
		{tags remove "turn"}
		(define "turn_off"	
			{if tagged "%turn_off"
				{ani_play "%turn_off" -2 resume }
				{tags remove "%turn_off"}	
			}
		)
		("turn_off" turn_off(turn_left)  )	
		("turn_off" turn_off(turn_right)  )	
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
	{on animation_event "20heal" ;all
		{burn volume "cpu" fx "smoke_heat" time 5 fake}	
	}
	{on animation_event "40heal"  ;all	
		{burn volume "cpu" fx "smoke_heat" time 7 fake}	
	}
	{on animation_event "70heal"  ;all
		{burn volume "cpu" fx "fx_fire_engine_gen" time 2 fake even_law}					
	}
	{on animation_event "move_update" ;scout. drone c4
		{if not able "exploded"
			{call "velocity_update"}	
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
	{on animation_event "grounded"
		{spawn "dust_land" "basis"}
	}
	{on animation_event "walk_limit"
		{tags add "walk_limit"}
	}
	{on animation_event "walk_limit_end"
		{tags remove "walk_limit"}
	}
	{on animation_event "landed"
		{if velocity 5
			{tags add "move"}
			{call "move_update_f"}
		}
		{delay  1
			{chassis_work 1}
			{weapon_work "mgun" 1}
		}
	}
	{on animation_event "block_hover"
		{ani_stop "hover"  }				
	}
	{on animation_event "hover_off"
		{if tagged "landed_idle" ;найти тихий звук 
			{ani_play "engine_work" 0.3 loop }	
		else
			{stop_sound "engine_close" }
			{stop_sound "engine_dir" }
			{ani_stop "engine_work"  }						
			{ani_play "engine_stop"  }						
		}
		{with_linked_entity "right_jetengine"
			{call "close"}
		}
		{with_linked_entity "left_jetengine"
			{call "close"}
		}
		{view stop	"jetengine_r"}
		{view hide	"jetengine_r"}		
		{view stop	"jetengine_l"}
		{view hide	"jetengine_l"}
	}
	{on animation_event "unblock_hover"
		{if not tagged "idle_script"
			{if work "main_body"
				{if not tagged "break_jetengine"
					{ani_play "hover" loop }		
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
	{on animation_event "joint_small"
		{start_sound "generation_zero/characters/scout/joint/"}			
	}
	{on animation_event "play_idle" ;skir scout harv
		{tags add "play_idle"}
		{tags add "hold"}
		{call "leds_update"}
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
}
