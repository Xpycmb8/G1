{"defence_tower_base" ;weapon_attach_tower
	{on spawn
		;----------
		{link_sound "turret_rotate" 		"vehicle/turret/turret_lr"						}
		{link_sound "turret_end" 			"vehicle/whotel/turret_end/stop"			}
		{link_sound "turret_start" 			"vehicle/whotel/turret_start/start"			}
		{link_sound "gun_rotate" 			"vehicle/whotel/gun/ik_loop"				}
		{view start "ems_global"}
		{link_sound "loop_fire" "weapon/shot/loop/25mm/plr/25mm_loop"}
		{link_sound "stop_fire" "weapon/shot/loop/25mm/plr/25mm_stop"}
		{delay 0.1
			{if not "engine_started"
				{set "engine_started" 1}
				{if not tagged "started"
					{if tagged "frends"
						{player 0}
					else
						{player 8}
					}
					{start_sound "generation_zero/characters/skirmisher/spawn/"}	
					{tags add "started"}
				}
			else
				{if tagged "frends"
					{player 0}
				else
					{player 8}
				}
			}
		}
	}
	{on pierce sync;tower?
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
		("mesh_break" component(head)  				 				stuff_destroy(0.2)    )
		("mesh_break" component(magazine)  				 			stuff_destroy(0.2)    )
		("mesh_break" component(mgun)  				 				stuff_destroy(0.2)    )
		("mesh_break" component(cpu)  				 				stuff_destroy(0.3)    )
		("mesh_break" component(battery)  				 			stuff_destroy(0.3)    )
		("mesh_break" component(cpu)  				 				stuff_destroy(0.3)    )
		("mesh_break" component(head_organ)  				 		stuff_destroy(0.3)    )
		("mesh_break" component(joint)  				 			stuff_destroy(0.3)    )
		("mesh_break" component(visor)  				 			stuff_destroy(0.3)    )

	
;------------------		
		(include "pierce_all.inc")
	}
	{on blast ;dread
		(include "blast_all.inc")
	}
	(include "burn_volume.inc")
	{on fire "alarm_signal"   
		{tags add "mgun_alarm_base"}
		{tags add "call_allies"}
		{delay 5
			{tags remove "mgun_alarm_base"}
			{tags remove "call_allies"}
		}
		{if not tagged "alarm"
			{tags add "alarm"}
			{if rand 0.5
				{start_sound "generation_zero/characters/fnix_turret/combat/fnix_turret_alarm_target_acquired_dir_01"}	
				{start_sound "generation_zero/characters/fnix_turret/combat_bb/fnix_turret_alarm_target_acquired_bb_01"}	
			else rand 0.3
				{start_sound "generation_zero/characters/fnix_turret/combat/fnix_turret_alarm_target_acquired_dir_02"}	
				{start_sound "generation_zero/characters/fnix_turret/combat_bb/fnix_turret_alarm_target_acquired_bb_03"}	
			else 
				{start_sound "generation_zero/characters/fnix_turret/combat/fnix_turret_alarm_target_acquired_dir_03"}	
				{start_sound "generation_zero/characters/fnix_turret/combat_bb/fnix_turret_alarm_target_acquired_bb_03"}	
			}
			{delay 0.1 {call "leds_update"}}
		}
		{delay 1 {tags remove "alarm"}}
	}
	{on "combat_call"
		{if not tagged "search"
			{tags add "search"}
			{if rand 0.4
				{start_sound "generation_zero/characters/fnix_turret/search_to_combat/fnix_turret_alarm_target_lost_dir_01"}	
				{start_sound "generation_zero/characters/fnix_turret/search_to_combat_bb/fnix_turret_alarm_target_lost_bb_01"}	
			else 
				{start_sound "generation_zero/characters/fnix_turret/search_to_combat/fnix_turret_alarm_target_lost_dir_02"}	
				{start_sound "generation_zero/characters/fnix_turret/search_to_combat_bb/fnix_turret_alarm_target_lost_bb_02"}	
			}
			{delay 0.1 {call "leds_update"}}
		}
		{delay 2 {tags remove "search"}}
	}
	{on ik begin "h_dr_signal" overload
		{call "combat_call"}
	}
	{on ik begin "v_dr_signal" overload
	}
	{on ik begin "H_drive"
		{if not work "joint"
			{if rand 0.5
				{ik_enable "H_drive" 0}
				{spawn "break_small_body_robot" "h_drive"}
			}
			{delay 1
				{ik_enable "H_drive" 1}
			}
		}
		{ik_enable "V_drive" 0}
		{play_sound "turret_start"}
		{play_sound "turret_rotate" 1}
	}
	{on ik end "H_drive"
		{ik_enable "V_drive" 1}
		{stop_sound "turret_start"}
		{stop_sound "turret_rotate"}
		{play_sound "turret_end"}
	}

	{on ik begin "V_drive"
		{play_sound "gun_rotate"}
	}
	{on ik end "V_drive"
		{if work "head_arm"
			{ik_enable "H_drive" 1}
		}
		{stop_sound "gun_rotate"}
	}
	{on destroy ; all
		{if component "head_organ"			
			{if not able "exploded"	
				{able "exploded" 1}
				{call "destroy_turret"}
			}
		}
		{if component "head_arm"
			{ik_enable "H_drive" 0}
		}
	}
	{on break ; all
		{if component "head_arm"
			{ik_enable "H_drive" 0}
			{spawn "break_small_body_robot" "h_drive"}
			{delay 5
				{ik_enable "H_drive" 1}
			}
			{spawn "break_small_body_robot" "h_drive"}
		}
		{if component "head_organ"
			{spawn "break_small_body_robot" "head"}
			{if rand 0.3
				{if not able "exploded"	
					{able "exploded" 1}
					{call "destroy_turret"}
				}
			}
		}
	}	
	{on "destroy_turret"
		{start_sound "generation_zero/characters/explosion/robot_death_downer_medbot/close"}
		{start_sound "generation_zero/characters/explosion/robot_death_downer_medbot/far"}
		{spawn "break_small_body_robot" "head"}
		{spawn "break_small_body_robot" "h_drive"}
		{view start "smoke_hips_h"}
		{delay 3 1
			{view start "smoke_hips_v"}
		}
		{delay 25
			{view stop "smoke_hips_h"}
			{delay 4 2
				{view stop "smoke_hips_v"}
			}
		}		
		{weapon_work "alarm_signal" 0}
		{weapon_work "mgun" 0}
		{auto_operatable 0}
		{ani_play "destroy"}
		{burn volume "cpu" fx "burn_element_cpu" time 12 fake even_law}		
	}
	{on fire "impact_fire" 
		{ani_play "impact"}
		{start_sound "generation_zero/characters/dreadnought/pneumatics"}
		{delay 3
			{ani_play "impact" -0.4}
		}
		{delay 0.5
			{spawn "damage_impact" "blastl"}
			{spawn "defence_tower_impact" "blastr"}
			
			{spawn "damage_impact" "blastl"}
			{spawn "defence_tower_impact" "blastl"}
		}
	
	}
}

{"defence_tower_mgun" ;weapon_attach_tower
	{on spawn
		;shotgun
		{add_view 	"muzzle_gun30_auto" 		"fx_muzzle00" 	"shooter00"}
		{add_view 	"muzzle_gun30_auto" 		"fx_muzzle01" 	"shooter01"}
		;----------
		{link_sound "loop_fire" "weapon/shot/loop/25mm/plr/25mm_loop"}
		{link_sound "stop_fire" "weapon/shot/loop/25mm/plr/25mm_stop"}
	}
	
	{on fire "mgun" 
		{tags add "fire_mgun"}
		{delay 0.3
			{tags remove "fire_mgun"}
		}	
		{if not tagged "firing"				
			{play_sound "loop_fire" 1}
			{tags add "firing"}
		}
		{tags add "fast_fire"}
		(define "fire_barrel"
			name "%0"
				{ani_play "recoil%0" 1.5 }
				{spawn "fx_shoot_hit_sparks" "shooter%0" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "shooter%0" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
				{view start "fx_muzzle%0"}
				{delay 0.015 "fire"
					{view hide	"fx_muzzle%0"}
					{tags remove "fast_fire"}
					{view pause "fx_muzzle%0"}
				}
		)
		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
		{if tagged "firing"			
			{delay 0.1
				{tags remove "firing"}
				{if not tagged "firing"				
					{stop_sound "loop_fire" }
					{play_sound "stop_fire" }
				}
			}
		}
	}
	{on animation_event "clear_casing_20mm_00"
		{tear "shell_drop_small" bone "shell_drop_00" copy 
			{impulse cx -0.1 0.1 com  }
		}
	}
	{on animation_event "clear_casing_20mm_01"
		{tear "shell_drop_small" bone "shell_drop_01" copy 
			{impulse cx -0.1 0.1 com  }
		}
	}
}
{"defence_tower_rocket" ;weapon_attach_tower
	{on spawn
		{add_view 	"start_bgm" 		"fx_muzzle" 	"fx_shoot"}
	}
	
	{on fire "mgun" 
		{tags add "fire_rocket"}
		{delay 1
			{tags remove "fire_rocket"}
		}	
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{view show 	"fx_muzzle"}
		{delay 1 "fire"
			{view hide	"fx_muzzle"}
			{view pause "fx_muzzle"}
		}
	}
}
{"autonomous_turret"
	{on spawn
		;{if work""
			{ik_enable "h_drive_slow" 0}
		;}
		{link_sound "engine" 	"generation_zero/characters/skirmisher/engine/runner_class4_engine"}
		{link_sound "handle_ik_start"			"vehicle/turret/small2_start"}
		{link_sound "handle_ik_move"			"vehicle/turret/small2_loop"}
		{link_sound "handle_ik_end"				"vehicle/turret/small2_end"}
		{add_view 	"heat_stage1" 		"stage1" "fx_main"}
		{add_view 	"heat_stage2" 		"stage2" "fx_main"}
		{add_view 	"muzzle_single" 				"fx_muzzle_heat" "fx_main"}
		{call "led_ems_connect"}
		{auto_operatable 0}
		{tags remove "open_attack"}
		{ani_stop "energy"}					
		{ani_wind "power_down" end}
	}
	{on "led_ems_connect"
		(define "leds_ems_global"
			{add_view 	"laser_sight_add_guided_rocket" 						"laser_point" "fx_laser_point"}
			{add_view 	"laser_sight_guided_rocket" 							"laser_point" "fx_laser_point"}
			{add_view 	"laser_sight_guided_rocket" 							"laser_point" "sight_sniper_bone"}
			{add_view 	"yellow_ems_small" 	"ems_global_search" 	"%vis_search"}
			{add_view 	"red_ems_small" 	"ems_global_alarm" 		"%vis_alarm"}
			{add_view 	"hold_ems_small" 	"ems_global_hold" 		"%vis_hold"}
			{view show	"ems_global_hold"}
			{view start	"ems_global_hold"}
			{view hide	"ems_global_alarm"}
			{view pause	"ems_global_alarm"}
			{view hide	"ems_global_search"}
			{view pause	"ems_global_search"}
			{view hide	"laser_point"}
			{view pause	"laser_point"}
		)
		("leds_ems_global"  vis(head_ems) )
	
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
						{tags remove "hold"}	
						{tags remove "search"}	
						{tags remove "alarm"}	
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
			("leds_ems"  vis(head_ems) )
		}
	}
	{on animation_event "power_down_leave" overload
		;{auto_operatable 1}
		{if not able "exploded" 
			{able select 1}
		}
	}
	{on animation_event "power_down_start" overload
		{ani_stop "walkloop_fwd"}
		{ani_stop "walkloop_f"}
		;{auto_operatable 0}
		{drop_orders}
	}
	{on animation_event "0_energy"
		{volumes "attach_battery" enable touch}
		{auto_operatable 0}
		{tags remove "open_attack"}
		{bone hide "leds"}
		{delay 0.5
			{ani_play "power_down" }			
		}
		{delay 1	
			{bone hide "battery"}
			{tear "piece_medium_steel" bone "magazine" copy 
				{impulse up 0 com}
			}		
		}
	}
	{on animation_event "20_energy"
		{ik_enable "h_drive_slow" 1}
		{ik_enable "h_drive" 0}
	}
	{on ik begin "h_drive"
		{play_sound "handle_ik_start" }
		{ani_play "ik_h" loop resume }			
		{delay 0.5 "gun_ik_vertical"
			{play_sound "handle_ik_move" 1}
		}
	}
	{on ik end "h_drive"
		{kill_delay "gun_ik_vertical"}
		{ani_stop "ik_h"}			
		{stop_sound "handle_ik_start" }
		{stop_sound "handle_ik_move" }
		{play_sound "handle_ik_end" }
	}
	{on "open_attack"
		{start_sound "vehicle/light/"}
		{if not tagged "open_attack"
			;{auto_operatable 1}
			{tags add "open_attack"}
			{ani_play "energy" +0.01 resume}			
			{delay 0.1
				{ani_play "power_up" }			
			}
		else
			{delay 0.2
				{ani_play "power_down" }			
			}
			{tags add "off"}
			;{auto_operatable 0}
			{tags remove "open_attack"}
			{ani_stop "energy"}					
		}
	}
	{on "attach_battery"	
		{volumes "attach_battery" disable touch}
		{ani_play "energy"-1}			
		{bone show "battery"}
		{bone show "leds"}
	}	
	
	(define "energy"
		{on animation_event "%event"
			{tags add "%tagged_energy"}
			;{if tagged "%tagged_energy"	
				
			;}
		}
	)
	;                      
	;("energy" event(0)  tagged_energy(0_energy) )
	("energy" event(5)  tagged_energy(5_energy) )
	("energy" event(10) tagged_energy(10_energy) )
	("energy" event(15) tagged_energy(15_energy) )
;	("energy" event(20) tagged_energy(20_energy) )
	("energy" event(25) tagged_energy(25_energy) )
	("energy" event(30) tagged_energy(30_energy) )
	("energy" event(35) tagged_energy(35_energy) )
	("energy" event(40) tagged_energy(40_energy) )
	("energy" event(45) tagged_energy(45_energy) )
	("energy" event(50) tagged_energy(50_energy) )
	("energy" event(55) tagged_energy(55_energy) )
	("energy" event(60) tagged_energy(60_energy) )
	("energy" event(65) tagged_energy(65_energy) )
	("energy" event(70) tagged_energy(70_energy) )
	("energy" event(75) tagged_energy(75_energy) )
	("energy" event(80) tagged_energy(80_energy) )
	("energy" event(85) tagged_energy(85_energy) )
	("energy" event(90) tagged_energy(90_energy) )
	("energy" event(95) tagged_energy(95_energy) )
	("energy" event(100) tagged_energy(100_energy) )
	{on fire "mgun" 
		{kill_delay "heat50"}
		{if not tagged "heat50"				
			{tex_morph "_heat1" 7}
			{tags add "heat50"}
			{ani_play "energy" +0.01 resume}			
			{ani_play "stage1" +0.7 resume callback}
			{ani_play "stage2" +0.3 resume callback}
		}
		{delay 2 "heat50"
			{ani_play "stage1" -0.5 resume }
			{ani_play "stage2" -0.2 resume }
			{tex_morph "_heat0" 6}
			{tags remove "heat50"}
		}
		{if tagged "stage1"
			{if rand 0.7
				{view start "fx_muzzle_heat"}
			}
			{delay 0.03 "fire"
				{view hide	"fx_muzzle_heat"}
				{view pause	"fx_muzzle_heat"}
			}
			{if rand 0.06
				{spawn "spark_small_gun_heat" "foresight3" x}
			}
		}
		{if tagged "stage2"
			{if rand 0.7
				{view start "fx_muzzle_heat_full"}
			}
			{delay 0.04 "fire"
				{view hide	"fx_muzzle_heat_full"}
				{view pause	"fx_muzzle_heat_full"}
			}
			{if rand 0.1
				{spawn "spark_small_gun_heat" "foresight3" x}
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
		}
		{view start "fx_main"}
		{delay 0.03 "fire"
			{view hide	"fx_main"}
			{view pause	"fx_main"}
		}
		{tags add "firing"}
		{start_sound "weapon/shoot_loud/far/ar"}	
		{start_sound "weapon/shoot_loud/close/ar"}	
		{delay 3 "firing"
			{tags remove "firing"}
		}
		{ani_play "recoil" }		
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresigh3t" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "foresight3" }
		{if not tagged "fire_move"				
			{tags add "fire_move"}
			{ani_play "wpn_move" -0.1 resume}				
		}
		{delay 0.1 "fire_hold"
			{ani_play "wpn_move" +0.1 resume}				
		}
		{tags add "alarm"}
		{tags remove "hold"}
		{tags remove "search"}
		{call "leds_update"}
	}
	{on animation_end "stage1"
		{view start "stage1"}
		{delay 2 1 
			{view hide	"stage1"}
			{view pause	"stage1"}
		}
		{burn volume "smg" fx "smoke_heat_barrel" time 3 fake even_law}
		{burn volume "recoil" fx "smoke_heat_barrel" time 7 fake even_law}
		{tags add "stage1"}
	}
	{on animation_end "stage2"
		{tags add "heat_full"}		
		{view start "stage2"}
		{delay 5 
			{tags remove "heat_full"}		
			{view hide	"stage2"}
			{view pause	"stage2"}
		}
		{if tagged "fire_hold"				
			{start_sound "weapon/heat/"}
		}
		{burn volume "recoil"	 fx "smoke_heat_barrel" time 12 fake even_law}
		{burn volume "smg"	 fx "smoke_heat_barrel" time 8 fake even_law}
		{tags add "stage2"}
	}
	{on fire "alarm_signal"   
		;{signal shot 5000}
		{tags add "mgun_alarm_base"}
		{delay 5
			{tags remove "mgun_alarm_base"}
		}
		{tags remove "hold"}	
		{tags remove "search"}	
		{tags add "alarm"}
		{call "leds_update"}
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
		{delay 1 {tags remove "combat_call"}}
	}
	{on ik begin "v_dr_signal"
		{tags remove "hold"}	
		{tags remove "alarm"}	
		{tags add "search"}
		{call "leds_update"}
		{if not tagged "search_call"
			{tags add "search_call"}
			{if rand 0.2
				{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_18_clr"}	
				{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_18_bb"}	
			else rand 0.2
				{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_19_clr"}	
				{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_19_bb"}	
			else rand 0.2
				{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_20_clr"}	
				{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_20_bb"}	
			else rand 0.2
				{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_21_clr"}	
				{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_21_bb"}	
			else 
				{start_sound "generation_zero/characters/skirmisher/search_c4/skir_combat_search_2ch"}	
				{start_sound "generation_zero/characters/skirmisher/search_bb/skir_combat_search_bb"}			
			}
		}
		{delay 2 {tags remove "search_call"}}
	}
}
{"autonomous_turret_heavy"
	{on spawn
		{add_view 	"laser_sight_add_guided_rocket" 						"laser_point_l" "fx_laser_point_missilelauncher_l"} ;harvest
		{add_view 	"laser_sight_guided_rocket" 							"laser_point_l" "fx_laser_point_missilelauncher_l"} ;harvest
		{link_sound "engine" 	"generation_zero/characters/skirmisher/engine/runner_class4_engine"}
		{link_sound "handle_ik_start"			"vehicle/turret/small2_start"}
		{link_sound "handle_ik_move"			"vehicle/turret/small2_loop"}
		{link_sound "handle_ik_end"				"vehicle/turret/small2_end"}
		{link_sound "spin"				"weapon/gatling/Minigun_Shredder_FireSpin"}
		{link_sound "spin_down"				"weapon/gatling/Minigun_FireSpin_Down"}
		{link_sound "armed"				"weapon/turret/Beep_Arm_01"}	
		{add_view 	"muzzle_front_hmgun" 		"fx_muzzle" 			"foresight3"}
		{add_view 	"muzzle_front_shotgun" 		"fx_muzzle_heat" 		"foresight3"}
		{add_view 	"muzzle_gun30_auto" 		"fx_muzzle_heat_full" 	"foresight3"}
		{add_view 	"heat_stage1" 			"stage1" 			"foresight3"}
		{add_view 	"heat_stage2" 			"stage2" 			"foresight3"}
		{add_view 	"fx_trace_hit_big" 		"barrel_damage" 			"barrel_fx"}	
		{add_view 	"batt_fire" 			"barrel_damage2" 			"barrel_fx"}	
		{call "led_ems_connect"}
		{auto_operatable 0}
		{tags remove "open_attack"}
		{ani_stop "energy"}					
		{ani_wind "power_down" end}
		{weapon_work "mgun" 0}
		{ik_enable "h_drive_slow" 0}
;		{link_sound "power_up" 		"generation_zero/characters/dreadnought/power_up/drea_concussion_riser_01"}
	}
	{on "led_ems_connect"
		(define "leds_ems_global"
			{add_view 	"laser_sight_add_guided_rocket" 						"laser_point" "fx_laser"}
			{add_view 	"red_ems_big" 							"laser_point" "fx_laser"}
			{add_view 	"yellow_ems_small" 	"ems_global_search" 	"%vis_search"}
			{add_view 	"red_ems_small" 	"ems_global_alarm" 		"%vis_alarm"}
			{add_view 	"hold_ems_small" 	"ems_global_hold" 		"%vis_hold"}
			{view show	"ems_global_hold"}
			{view start	"ems_global_hold"}
			{view hide	"ems_global_alarm"}
			{view pause	"ems_global_alarm"}
			{view hide	"ems_global_search"}
			{view pause	"ems_global_search"}
			{view hide	"laser_point"}
			{view pause	"laser_point"}
		)
		("leds_ems_global"  vis(head_ems) )
	
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
						{tags remove "hold"}	
						{tags remove "search"}	
						{tags remove "alarm"}	
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
			("leds_ems"  vis(head_ems) )
		}
	}
	{on "open_attack"
		{start_sound "vehicle/light/"}
		{if not tagged "open_attack"
			;{auto_operatable 1}
			{tags add "open_attack"}
			{ani_play "energy" +0.01 resume}			
			{delay 0.1
				{ani_play "power_up" }			
			}
		else
			{delay 0.2
				{ani_play "power_down" }			
			}
			{tags add "off"}
			;{auto_operatable 0}
			{tags remove "open_attack"}
			{ani_stop "energy"}					
		}
	}
	{on "attach_battery"	
		{volumes "attach_battery" disable touch}
		{ani_play "energy"-1}			
		{bone show "battery"}
		{bone show "leds"}
	}	
	
	{on fire "alarm_signal"   
		;{signal shot 5000}
		{tags add "mgun_alarm_base"}
		{delay 5
			{tags remove "mgun_alarm_base"}
		}
		{tags remove "hold"}	
		{tags remove "search"}	
		{tags add "alarm"}
		{call "leds_update"}
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
		{delay 1 {tags remove "combat_call"}}
	}
	{on fire "slope_move" 
		{tags add "mgun_rotate"}
		{tags add "mgun_rotate_check"}
		{tags add "spin"}
		{delay 0.1 
			{tags remove "mgun_rotate"}
		}
		{if min_mass 101
			{tags add "ammo_full"}
			{tags remove "ammo_empty"}
			{if not tagged "armed_spin"				
				{delay 0.5
					{play_sound "armed"}
				}
				{tags add "armed_spin"}
				{play_sound "spin" 1}
				{ani_play "wpn_rotate" loop}
			}			
			{delay 2
				{weapon_work "mgun" 1}
			}			
			{delay 7.5
				{if tagged "mgun_rotate_check"				
					{if tagged "spin"				
						{tags remove "spin"}
						{tags remove "armed_spin"}
						{stop_sound "spin"}
						{play_sound "spin_down"}
						{ani_stop "wpn_rotate" }				
						{ani_play "wpn_stop" }	
					}
				}
			}
			{start_sound "generation_zero/characters/wpn_alarm/wpn_alarm_mgun/bb"}	
			{start_sound "generation_zero/characters/wpn_alarm/wpn_alarm_mgun/dir"}	
		else min_mass 99
			{tags remove "ammo_full"}
			{tags add "ammo_empty"}
			{start_sound "generation_zero/characters/wpn_alarm/wpn_alarm_missiles/bb"}	
			{start_sound "generation_zero/characters/wpn_alarm/wpn_alarm_missiles/dir"}	
		}
		{view start "laser_point"}
		{view show "laser_point"}
		{delay 3
			{view hide	"laser_point"}
			{view pause	"laser_point"}
		}
		{ik_enable "h_drive" 0}
		{ik_enable "h_drive_slow" 1}
	}
	{on fire "mgun"
		{tags remove "mgun_rotate_check"}
		{tags add "firing"}
		{weapon_work "mgun_rotate" 0}
		{kill_delay "rotate"}
		{kill_delay "heat50"}
		{if not tagged "heat50"				
			{tags add "heat50"}
			{ani_play "energy" +0.03 resume}			
			{ani_play "stage1" +0.7 resume callback}
			{ani_play "stage2" +0.3 resume callback}
		}
		{delay 2 "heat50"
			{ani_play "stage1" -0.5 resume }
			{ani_play "stage2" -0.2 resume }
			{tags remove "heat50"}
		}
		{view start "fx_muzzle"}
		{view show "fx_muzzle"}
		{if not tagged "fire_move"				
			{ani_play "wpn_fire" loop}				
			{tags add "fire_move"}
		}
		{delay 0.1 
			{ani_play "wpn_rotate" loop}				
			{ani_stop "wpn_fire" }				
			{tags remove "fire_move"}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
		{delay 3 "firing"
			{if not tagged "fire_move"				
				{if tagged "spin"				
					{ani_stop "wpn_rotate" }				
					{stop_sound "spin"}
					{play_sound "spin_down"}
					{tags remove "armed_spin"}
					{ani_play "wpn_stop" }	
					{ik_enable "h_drive_slow" 0}
					{ik_enable "v_drive_slow" 0}
					{ik_enable "h_drive" 1}
					{ik_enable "v_drive" 1}
					{weapon_work "mgun" 0}
					{weapon_work "mgun_rotate" 1}
					{tags remove "spin"}
					{tags remove "firing"}
				}
			}
		}
		{tags add "alarm"}
		{tags remove "hold"}
		{tags remove "search"}
		{call "leds_update"}
		{if tagged "stage1"
			{if rand 0.3
				{view start "fx_muzzle_heat"}
				{view show "fx_muzzle_heat"}
			}
			{delay 0.01 "fire"
				{view hide	"fx_muzzle_heat"}
				{view pause	"fx_muzzle_heat"}
			}
		}
		{if tagged "stage2"
			{if rand 0.3
				{view start "fx_muzzle_heat_full"}
				{view show "fx_muzzle_heat_full"}
			}
			{delay 0.01 "fire"
				{view hide	"fx_muzzle_heat_full"}
				{view pause	"fx_muzzle_heat_full"}
			}
		}
		{if tagged "damage_barrel"
			{call "jamm_barrel"}
		}
	}
	{on "reload"
		{weapon_work "mgun" 0}
		{weapon_work "mgun_rotate" 0}
		;{if tagged "mgun_rotate"
		;}
		{if tagged "fire_move"
			{if tagged "spin"				
				{tags remove "spin"}
				{stop_sound "spin"}
				{play_sound "spin_down"}
				{delay 0.2 
					{tags remove "armed_spin"}
					{ani_stop "wpn_rotate" }				
					{ani_stop "wpn_fire" }
				}
				{ani_play "wpn_stop" }	
			}
		}
		{delay 7
			{weapon_work "mgun_rotate" 1}
		}
	}
	{on "jamm_barrel"
		{if rand 0.2
			{view start "barrel_damage"}
			{view show "barrel_damage"}
			{delay 0.5
				{if tagged "fire_move"
					{view start "barrel_damage2"}
					{view show "barrel_damage2"}		
					{view hide "barrel_damage"}
					{view pause "barrel_damage"}		
					{delay 0.2
						{if tagged "fire_move"
							{view hide "barrel_damage2"}
							{view pause "barrel_damage2"}		
							{start_sound "generation_zero/weapon/gau/jamm"}	
							;{spawn "car_destroy_engine_small" "j_barrels"}						
							{weapon_work "mgun" 0}
						}
					}
				}
			}
			{delay 1.1	
				{ani_stop "wpn_rotate" }				
				{ani_stop "wpn_fire" }
				{view hide "barrel_damage"}
				{view pause "barrel_damage"}		
				{view hide "barrel_damage2"}
				{view pause "barrel_damage2"}		
				;{if work "mgun"
					{weapon_work "mgun" 0}
				;}
			}
		}
	}		
;	{on animation_end "wpn_rotate"
;	}		
;	{on animation_end "wpn_fire"
;	}		
	{on animation_event "fire_loop_gau"
		{start_sound "generation_zero/weapon/gau/far"}	
		{start_sound "generation_zero/weapon/gau/close"}	
		{start_sound "generation_zero/weapon/gau/bass"}	
		{tear "shell_drop_762_57" bone "shell_drop" copy 
			{impulse forward 6 3 cx -1.5 1.5 com}
		}
	}		
	{on animation_event "power_down_leave" overload
		{auto_operatable 1}
		{tags add "frends"}
		{if not able "exploded" 
			{able select 1}
		}
	}
	{on animation_event "power_down_start" overload
		;{auto_operatable 0}
		{drop_orders}
	}
	{on animation_event "0_energy"
		{volumes "attach_battery" enable touch}
		{tags remove "open_attack"}
		{bone hide "leds"}
		{delay 0.5
			{ani_play "power_down" }			
		}
		{delay 1	
			{start_sound "generation_zero/characters/wpn_alarm/wpn_alarm_missiles/bb"}	
			{start_sound "generation_zero/characters/wpn_alarm/wpn_alarm_missiles/dir"}	
			{view hide	"laser_point"}
			{view pause	"laser_point"}
			{bone hide "battery"}
			;{tear "piece_medium_steel" bone "magazine" copy 
			;	{impulse up 0 com}
			;}		
		}
	}
	{on animation_event "20_energy"
		{ik_enable "h_drive_slow" 1}
		{ik_enable "h_drive" 0}
	}
	{on animation_end "stage1"
		{view start "stage1"}
		{delay 2 1 
			{view hide	"stage1"}
			{view pause	"stage1"}
		}
		{burn volume "smg" fx "smoke_heat_barrel" time 3 fake even_law}
		{burn volume "recoil" fx "smoke_heat_barrel" time 7 fake even_law}
		{tags add "stage1"}
	}
	{on animation_end "stage2"
		{tags add "heat_full"}		
		{view start "stage2"}
		{delay 5 
			{tags remove "heat_full"}		
			{view hide	"stage2"}
			{view pause	"stage2"}
		}
		{if tagged "fire_hold"				
			{start_sound "weapon/heat/"}
		}
		{burn volume "recoil"	 fx "smoke_heat_barrel" time 12 fake even_law}
		{burn volume "smg"	 fx "smoke_heat_barrel" time 8 fake even_law}
		{tags add "stage2"}
	}
	{on ik begin "v_dr_signal"
		{tags remove "hold"}	
		{tags remove "alarm"}	
		{tags add "search"}
		{call "leds_update"}
		{if not tagged "search_call"
			{tags add "search_call"}
			{if rand 0.2
				{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_18_clr"}	
				{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_18_bb"}	
			else rand 0.2
				{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_19_clr"}	
				{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_19_bb"}	
			else rand 0.2
				{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_20_clr"}	
				{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_20_bb"}	
			else rand 0.2
				{start_sound "generation_zero/characters/skirmisher/search_c4/skir_c4_to_search_21_clr"}	
				{start_sound "generation_zero/characters/skirmisher/search_c4_bb/skir_c4_to_search_21_bb"}	
			else 
				{start_sound "generation_zero/characters/skirmisher/search_c4/skir_combat_search_2ch"}	
				{start_sound "generation_zero/characters/skirmisher/search_bb/skir_combat_search_bb"}			
			}
		}
		{delay 2 {tags remove "search_call"}}
	}
	{on pierce sync
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
		("mesh_break" component(engine)			stuff_destroy(0.2)    )
		("mesh_break" component(visor)			stuff_destroy(0.2)    )
		("mesh_break" component(magazine)		stuff_destroy(0.2)    )
		("mesh_break" component(barrel)			stuff_destroy(0.2)    )
		("mesh_break" component(turret)			stuff_destroy(0.2)    )
		("mesh_break" component(joint)			stuff_destroy(0.2)    )
		("mesh_break" component(battery)		stuff_destroy(0.2)    )
		("mesh_break" component(cpu)			stuff_destroy(0.2)    )
		{if stuff "atgm_launcher"
			{call "break"}
		}
		{if stuff "shell_big"
			{call "break"}
		}
		{if stuff "rocketlauncher"
			{call "break"}
		}
	}	
	{on break ;turret xm
		{if component "barrel"			
			{tags add "damage_barrel"}
			{spawn "metal_pierce_bul" "barrel_fx"}	
		}
	}
}
